#include <iostream>
#include <math.h>
#include <vector>

std::vector<int> fattorizzazione(int n);

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

std::vector<int> fattorizzazione(int n) {
    std::vector<int> fattori(2, 0);

    long long unsigned int k = floor(sqrt(n)) + 1;

    while (sqrt(k*k - n) != floor(sqrt(k*k - n)) && k <= n) k += 1;

    // std::cout << fattori.size() << std::endl;
    fattori[0] = k + sqrt(k*k - n);
    fattori[1] = k - sqrt(k*k - n);

    

    if (fattori[0] == 1 || fattori[1] == 1) return fattori;
    else {
        std::vector<int> fat1 = fattorizzazione(fattori[0]);
        std::vector<int> fat2 = fattorizzazione(fattori[1]);

        fattori.resize(fattori.size() + fat1.size() + fat2.size(), 0);

        for (int i = 0; i < fattori.size(); i++) {
            std::cout << (fattori[i] + ", ");
        }
    }

    return fattori;
}

std::vector<int> primeFactorsChecker(int n) {

}
