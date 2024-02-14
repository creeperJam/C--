#include <iostream>
#include <math.h>
#include <vector>

struct powers
{
    int num;
    int power;
};

std::vector<int> primeFactors(int n);
std::string printIntegerVector(std::vector<int> vector);
std::string printPowersVector(std::vector<powers> vector);
std::vector<int> vectorSort(std::vector<int> vector);
std::vector<powers> commonFactorsGrouper(std::vector<int> vector);

int main(int argc, char const *argv[])
{
    long long unsigned int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::vector<int> fattori = vectorSort(primeFactors(number));
    std::cout << "The prime factors of the number " << number << " are: " << printIntegerVector(fattori) << std::endl;
    std::vector<powers> commonFactors = commonFactorsGrouper(fattori);

    std::cout << "Grouped into the form n^k, [n, k], they become:" << printPowersVector(commonFactors) << std::endl;

    std::cin.clear();                                                   // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    std::cin.get();                                                     // get one more char from the user

    return 0;
}

std::vector<powers> commonFactorsGrouper(std::vector<int> primeFactors)
{
    int lastValue = primeFactors[0];
    int index = 0;
    int size = 1;
    for (int i = 1; i < primeFactors.size(); i++)
    {
        if (primeFactors[i] != lastValue)
        {
            size++;
            lastValue = primeFactors[i];
        }
    }

    std::vector<powers> commonFactors(size);

    commonFactors[0] = powers{primeFactors[0], 1};
    lastValue = primeFactors[0];
    for (int i = 1; i < primeFactors.size(); i++)
    {
        if (primeFactors[i] == lastValue)
        {
            commonFactors[index] = powers{lastValue, commonFactors[index].power + 1};
        }
        else
        {
            index++;
            commonFactors[index] = powers{primeFactors[i], 1};
        }
    }

    return commonFactors;
}

std::vector<int> vectorSort(std::vector<int> vector)
{
    // bool sorted = true;

    for (int i = 0; i < vector.size() - 1; i++)
    {
        for (int j = i + 1; j < vector.size(); j++)
        {
            if (vector[j] < vector[i])
            {
                int app = vector[i];
                vector[i] = vector[j];
                vector[j] = app;
            }
        }

        // if (sorted) break;
    }

    return vector;
}

std::vector<int> primeFactors(int n)
{
    if (n < 0)
        return std::vector<int>(2, 0);
    // if (n <= 3) return std::vector<int> {n, 1};

    std::vector<int> fattori(2, 0);

    if (sqrt(n) == floor(sqrt(n)))
    {
        fattori[0] = fattori[1] = sqrt(n);
    }
    else if (n % 2 == 1)
    {
        long long unsigned int k = floor(sqrt(n)) + 1;

        while (sqrt(k * k - n) != floor(sqrt(k * k - n)) && k <= n)
            k += 1;

        // std::cout << fattori.size() << std::endl;
        fattori[0] = k + sqrt(k * k - n);
        fattori[1] = k - sqrt(k * k - n);
    }
    else
    {
        fattori[0] = 2;
        fattori[1] = n / 2;
    }

    // printIntegerVector(fattori);

    if (fattori[0] == 1 || fattori[1] == 1)
        return fattori;
    else
    {
        std::vector<int> fat1 = primeFactors(fattori[0]);
        std::vector<int> fat2 = primeFactors(fattori[1]);
        int size = 0;
        int index = 0;

        for (int i = 0; i < fat1.size(); i++)
        {
            if (fat1[i] != 1)
                size++;
        }

        for (int i = 0; i < fat2.size(); i++)
        {
            if (fat2[i] != 1)
                size++;
        }

        fattori.clear();
        fattori.resize(size, 0);

        for (int i = 0; i < fat1.size(); i++)
        {
            if (fat1[i] != 1)
                fattori[index++] = fat1[i];
        }

        for (int i = 0; i < fat2.size(); i++)
        {
            if (fat2[i] != 1)
                fattori[index++] = fat2[i];
        }
    }

    return fattori;
}

std::string printIntegerVector(std::vector<int> vector)
{
    std::string s = "[";

    for (int i = 0; i < vector.size(); i++)
    {
        s += std::to_string(vector[i]);
        if (i != vector.size() - 1)
            s += ", ";
    }

    s += "]";

    return s;
}

std::string printPowersVector(std::vector<powers> vector)
{
    std::string s = "[";

    for (int i = 0; i < vector.size(); i++)
    {
        powers app = vector[i];

        s += "[" + std::to_string(app.num) + ", " + std::to_string(app.power) + "]";
        if (i != vector.size() - 1)
            s += ", ";
    }

    s += "]";

    return s;
}
