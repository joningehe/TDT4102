#include "std_lib_facilities.h"

int maxOfTwo(int a, int b) {
    if (a > b) {
        return "A is greater than B";
    }
    else {
        return "B is greater than or equal to A";
    }
}

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    for (int i = 0; i < n+1; i++;) {
        cout << i << ", " << b << "\n";
        int temp = b;
        b += a;
        a  = temp;
    }
    cout << "----\n";
    return b;
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 0; i < n+1; i++) {
        totalsum += i * i;
        cout << i * i << "\n";
    }
    cout << totalSum << "\n";
    return totalSum;
}

void triangleNumbersBelow(int n) {  //må bruke void da denne funksjonen ikke skal returnere noe
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":" << string sep="" << "\n";   //kunne brukt char16_t istedenfor void?
    while (acc < n) {
        cout << acc << "\n";
        acc += num;
        num += 1;
    }
    cout << "\n";   //usikker på om det var slik de mente det
}

bool isPrime(int n){
    for (int j = 2; j < n+1; j++;){
        if (n % j == 0) {
            return false;   //er det egentlig nødvendig å avslutte med semikolon når man returnerer?
        }
    }
    return true;
}

void naivePrimeNumberSearch(int n){
    for (number = 2; number < n+1; number++;) {
        if (isPrime(number)) {
            cout << number << " is a prime\n";
        }
    }
}

int findGreatestDivisor(int n){
    for (int divisor = n-1; divisor > 0; divisor-=1;){
        if ( n % divisor == 0) {
            return divisor
        }
    }
}

int main(){

    cout << "Oppgave a)\n";
    cout << maxOfTwo(int a = 5, int b = 5) << "\n";  //sjekker om a er større enn b

    cout << "Oppgave c)\n";
    int n = 0;
    cout << "Skriv inn verdi for n = ";
    cin >> n;
    cout << "\n" << fibonacci(n) << "\n";   //sender n til funksjonen fibonacci for å finne rekken

    cout << "oppgave d)\n";
    cout << "Skriv inn verdi for n = ";
    cin << n;
    cout << "\n" << squareNumberSum(n) << "\n"; //finner den kvadrerte summen

    cout << "Oppgave e)\n";
    cout << "Skriv inn verdi for n = ";
    cin << n;
    cout << "\n" << triangleNumbersBelow(n) << "\n"; //finner trekanttall eller noe slikt

    cout << "Oppgave f)\n";
    cout << "Skriv inn verdi for n = ";
    cin << n;
    cout << "\n" << isPrime(n) << "\n";

    cout << "Oppgave g)\n";
    cout << "Skriv inn verdi for n = ";
    cin << n;
    cout << "\n" << naivePrimeNumberSearch(n) << "\n";

    cout << "oppgave h\n";
    cout << "Skriv inn verdi for n = ";
    cin >> n;
    cout << "\n" << findGreatestDivisor(n) << "\n";

}