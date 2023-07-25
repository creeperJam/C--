#include <iostream>
#include <string>
#include <math.h>

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
void inserimentoFunzione(std::string &funz) {
    
}

double calcoloFunz(std::string funz, double c) {
    double ris = 0;
    for (int i = 0; i < funz.length(); i++) {
        if (funz[i] == 'x') {
            ris = c;
        }
        else if (funz[i] == '^') {
            ris = pow(ris, funz[i+1]);
        }
        else if (funz[i] == '*') {
            ris *= funz[i+1];
        }
        else if (funz[i] == '/') {
            ris /= funz[i+1];
        }
    }

    return ris;
}

void integrazione(std::string funz, int a, int b, int n, double &superficie) {
    double ampiezza = abs((b - a)) / n, c;
    int x = a;

    for (int i = 1; i < n; i++) {
        x += ampiezza;
        c = x + (ampiezza/2);
        // calcoloFunz(funz, c);
        superficie += c*c*ampiezza;
        std::cout << "Superfice: " << superficie << std::endl;
    }
}

int main() {
    double a, b, superficie = 0; // Estremi
    int n; // Numero iterazioni
    std::string funz;
    std::cout << "Inserire la funzione (* per le moltiplicazioni, ^ per le potenze, / per le divisioni e x (minuscola) per le incognite): ";
    inserimentoFunzione(funz);

    std::cout << "Inserire l'estremo inferiore dell'intervallo: ";
    std::cin >> a;
    std::cout << "Inserire l'estremo superiore dell'intervallo: ";
    std::cin >> b;
    std::cout << "Inserire il numero di intervalli: ";
    std::cin >> n;

    integrazione(funz, a, b, n, superficie); // Calcolo integrale di f(x)=x^2

    std::cout << "La superficie dell'area è: " << superficie << std::endl;

    return 0;
}