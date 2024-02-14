#include <iostream>
#include <limits>
#include <string>
#include <math.h>
#include <algorithm> 
#include <cctype>
#include <locale>

// TODO: Aggiungere la funzione che permette di calcolare la funzione inserita, tenendo conto di:
// - parentesi
// - moltiplicazioni
// - divisioni
// - potenze
// - incognite (che verranno sostituite con il valore di c)
// - funzioni trigonometriche (seno, coseno, tangente, arcoseno, arcocoseno, arcotangente)
// - funzioni esponenziali (logaritmo naturale, logaritmo in base 10, logaritmo in base x, esponenziale, radice quadrata, radice cubica)
// - GLI SPAZI, se presenti nella stringa, devono essere eliminati

// Possibile soluzione: uso di un menu di inserimento della funzione, in cui l'utente può scegliere cosa inserire (frazioni, funzioni trigonometriche, ecc.)
// e in base a ciò inserire la funzione in un formato che possa essere letto dal programma
bool contains(char arr[], char c)
{
    int n = sizeof(arr);
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << std::endl;
        if (arr[i] == c)
            return true;
    }
    return false;
}

void inserimentoFunzione(std::string &funz)
{
    // std::string app = funz.substr(0, 1);
    // std::cout << "Carattere 0: " + app;
    // char values[] = {'+', '-', '*', '/', '^', '(', ')'};
    char correctionsOpen[] = {'[', '{'};
    char correctionsClosed[] = {']', '}'};

    for (int i = 0; i < funz.length(); i++)
    {
        // std::cout << "Carattere " << i << ": " + app;
        if (contains(correctionsOpen, funz[i]))
        {
            funz[i] = '(';
        }
        if (contains(correctionsClosed, funz[i]))
        {
            funz[i] = ')';
        }
    }

    // if (contains(values, c)) funz += c + ' ';
    // else if (contains(correctionsOpen, c)) funz += "( ";
    // else if (contains(correctionsClosed, c)) funz += ") ";
}

double calcoloFunz(std::string funz, double c)
{
    double ris = 0;
    for (int i = 0; i < funz.length(); i++)
    {
        if (funz[i] == 'x')
        {
            ris = c;
        }
        else if (funz[i] == '^')
        {
            ris = pow(ris, funz[i++]);
        }
        else if (funz[i] == '*')
        {
            ris *= funz[i + 1];
        }
        else if (funz[i] == '/')
        {
            ris /= funz[i + 1];
        }
    }

    return ris;
}

void integrazione(std::string funz, int a, int b, int n, double &superficie)
{
    double ampiezza = abs((b - a)) / n, c;
    int x = a;

    for (int i = 1; i < n; i++)
    {
        x += ampiezza;
        c = x + (ampiezza / 2);
        // calcoloFunz(funz, c);
        superficie += c * c * ampiezza;
        std::cout << "Superfice: " << superficie << std::endl;
    }
}

float radiciQuadrate(int n)
{
    float radice = 0;
    for (int i = 0; i < n; i++)
    {
        // std::cout << "Tentativo con numero " << i << std::endl;
        if (i * i > n)
        {
            radice = i - 1;
            break;
        }
    }

    radice += (n - radice * radice) / (2 * radice);
    return radice;
}

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    rtrim(s);
    ltrim(s);
}

int main()
{
    double a, b, superficie = 0; // Estremi
    int n;                       // Numero iterazioni
    std::string funz;
    std::cout << "Inserire la funzione (* per le moltiplicazioni, ^ per le potenze, / per le divisioni, x (minuscola) per le incognite): ";
    
    getline(std::cin, funz);
    
    trim(funz);
    // for (int i = 0; i < 10; i++)
    // {
    std::cout << "La funzione inserita è: " << funz << std::endl;

    inserimentoFunzione(funz);
    
    // }
    std::cout << "La funzione inserita è: " << funz << std::endl;

    // std::cout << "Inserire l'estremo inferiore dell'intervallo: ";
    // std::cin >> a;
    // std::cout << "Inserire l'estremo superiore dell'intervallo: ";
    // std::cin >> b;
    // std::cout << "Inserire il numero di intervalli: ";
    // std::cin >> n;

    // integrazione(funz, a, b, n, superficie); // Calcolo integrale di f(x)=x^2

    // std::cout << "La superficie dell'area è: " << superficie << std::endl;

    // int n;

    // std::cout << "Inserire il numero intero di cui calcolare la radice quadrata: ";
    // std::cin >> n;
    // std::cout << "La radice quadrata di " << n << " è circa " << radiciQuadrate(n) << std::endl;

    // std::cin.clear();                                                   // reset any error flags
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore any characters in the input buffer until we find an enter character
    // std::cin.get();                                                     // get one more char from the user
    return 0;
}
