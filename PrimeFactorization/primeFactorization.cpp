#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> fattorizzazione(int n);
void printVector(std::vector<int> vector);

int main(int argc, char const *argv[])
{
    long long unsigned int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    std::vector<int> fattori = fattorizzazione(number);

    std::cout << "La fattorizzazione del numero " << number << " in numeri primi è: " << fattori[0] << " * " << fattori[1] << std::endl;

    std::cin.clear();                                                   // reset any error flags
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    std::cin.get();                                                     // get one more char from the user

    return 0;
}

std::vector<int> fattorizzazione(int n)
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

    // printVector(fattori);

    if (fattori[0] == 1 || fattori[1] == 1)
        return fattori;
    else
    {
        std::vector<int> fat1 = fattorizzazione(fattori[0]);
        std::vector<int> fat2 = fattorizzazione(fattori[1]);
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

        std::cout << "Dimensione finale: " << size << std::endl;

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

        printVector(fattori);
    }

    return fattori;
}

// std::vector<int> primeFactorsChecker(int n)
// {
// }

void printVector(std::vector<int> vector)
{
    std::cout << "[";

    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << (vector[i]);
        if (i != vector.size() - 1)
            std::cout << ", ";
    }

    std::cout << "]" << std::endl;
}
