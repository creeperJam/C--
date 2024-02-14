#include <boost/multiprecision/cpp_int.hpp>
 #include <boost/multiprecision/cpp_dec_float.hpp> 
// #include <json.hpp>
#include <cstdint>
#include <string.h>
#include <iostream>
#include <bitset>
#include <limits>
#include <cmath>

using namespace std;
using BI = boost::multiprecision::cpp_int;
using BF = boost::multiprecision::cpp_dec_float_50;
namespace mp = boost::multiprecision;

int *IEEE754(long double f);
int *toIEEE754(float_t f);
long double fromIEEE754(int *binary);
std::string stampa(int b[], int n);
// void print(BI i);

int main(int argc, char const *argv[])
{
    BF num;
    // std::cout << "num: " << num << std::endl;

    // BI u = mp::pow(mp::cpp_int(2), 1020);
    // BI foo = 18446744073709551516; // 1267650600228229401496703205376
    // std::cout << "foo: ";
    // std::cin >> u;

    // std::cout << "foo: " << u << std::endl;

    std::cout << "Inserire un numero: ";

    std::cin >> num;

    std::cout << "Numero: " << num << std::endl;

    int *binary = toIEEE754(num);

    std::cout.precision(30);
    std::cout << "La rappresentazione binaria del numero " << num << " è: " << stampa(binary, 32) << std::endl;
    std::cout << "Questo corrisponde a: " << fromIEEE754(binary) << std::endl;

    return 0;
}

std::string stampa(int binary[], int n)
{
    std::string s = "";
    for (int i = 0; i < n - 1; i++)
    {
        s += std::to_string(binary[i]) + ", ";
    }
    s += std::to_string(binary[n - 1]);
    return s;
}

int *toIEEE754(BF f)
{
    int *binary = new int[32]{0};

    binary[0] = f < 0 ? 1 : 0;

    // __int128_t wholePart = (__int128_t)floor((f < 0 ? -f : f));
    BI wholePart = (int64_t)floor((f < 0 ? -f : f));
    // int64_t test = 9223372036854775807; // Uguale a long long unsigned int
    std::cout << wholePart << " --- Incredibile" << std::endl;

    // boost::multiprecision::floor(f);

    // boost::multiprecision::int256_t wholePart = boost::multiprecision::floor(f < 0 ? -f : f);
    long double decimalPart = (f < 0 ? -f : f) - wholePart;

    // std::cout << "Test: " << wholePart << std::endl;

    // stringstream ss = "";

    std::string mantissa = "";

    int *exponent = new int[8]{0}; // In forma polarizzata
    int exponentDec = 0;
    int indexExp = 0;

    // Mantissa -- Parte intera

    while (wholePart != 0)
    {
        mantissa = std::to_string(wholePart % 2) + mantissa;
        wholePart /= 2;
        // std::cout << "Mantissa: " << mantissa << std::endl;
        // std::cout << "Parte intera: " << wholePart << std::endl;
    }

    mantissa = mantissa.substr(1, mantissa.length());
    exponentDec = mantissa.length() + 127;
    // std::cout << "Esponente: " << exponentDec-127 << std::endl;

    // Mantissa -- Parte decimale

    while (decimalPart != 0 && mantissa.length() < 23)
    {
        decimalPart *= 2;
        if (decimalPart >= 1)
        {
            mantissa.append("1");
            decimalPart -= 1;
        }
        else
        {
            mantissa.append("0");
        }
    }

    // std::cout << "Mantissa: " << mantissa << std::endl;

    while (exponentDec != 0 && indexExp < 8)
    {
        exponent[indexExp++] = exponentDec % 2;
        exponentDec /= 2;
    }

    exponentDec = indexExp - 1;

    for (int i = 0; i < indexExp / 2; i++)
    {
        int scambio = exponent[i];
        exponent[i] = exponent[indexExp - 1 - i];
        exponent[indexExp - 1 - i] = scambio;
    }

    for (int i = 1; i < 9; i++)
    {
        binary[i] = exponent[i - 1];
    }
    for (int i = 9; i < (mantissa.length() < 23 ? mantissa.length() + 9 : 32); i++)
    {
        binary[i] = mantissa[i - 9] - '0';
        // std::cout << binary[i] << std::endl;
    }

    return binary;
}

long double fromIEEE754(int *binary)
{
    long double number = 0;
    int exponent = 0;

    for (int i = 1; i < 9; i++)
    {
        exponent += binary[9 - i] * pow(2, i - 1);
    }
    exponent -= 127;

    int mantissa[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 1; i < 24; i++)
    {
        mantissa[i] = binary[i + 8];
    }

    stampa(binary, 32);

    for (int i = 0; i < 24; i++)
    {
        // std::cout << pow(2.0, exponent--) * (double)mantissa[i] << std::endl;
        number += pow(2.0, exponent--) * (double)mantissa[i];
    }

    number = binary[0] == 1 ? 0 - number : number;

    return number;
}

// NON SO COME

int *IEEE754(float f)
{
    // Create a union of float and 32-bit integer
    union
    {
        float input; // assumes sizeof(float) is 4 bytes
        int output;
    } data;

    data.input = f;

    // Convert the 32-bit integer to a bitset
    std::bitset<32> bits(data.output);

    // Allocate memory for the array
    int *binary = new int[32];

    // Fill the array with the binary representation
    for (int i = 0; i < 32; ++i)
    {
        binary[i] = bits[31 - i];
    }

    return binary;
}
