#include "std_lib_facilities.h"

int inputInteger() {
    cout << "Skriv inn et heltall: \n";
    int n {0};
    cin >> n;
    return n;
}

void inputIntegersAndPrintSum() {
    int tall1 {0};
    tall1 = inputInteger();
    int tall2 {0};
    tall2 = inputInteger();
    cout << "Summen av tallene er: " << tall1+tall2 << "\n";
}

void inputIntegersUsingLoopAndPrintSum() {  //FIKS!!!, MÅ REGNE SAMMEN NÅR 0 TRYKKES
    cout << "Legg sammen tall ved å skrive inn et heltall, avslutt ved å skrive inn '0'";
    int n {0};
    int i {0};
    do {
        cin >> i;
        n += i;
    }
    while (n != 0);
    cout << "Summen er: " << n << "\n";
}

void nokToEur() {
    cout << "Skriv inn beløpet i nok som skal konverteres: ";
    double nok {0};
    cin >> nok;
    cout << nok << "kr blir " << setprecision(3) << (nok / 9.75) << "euro.\n";
}

void gangetabell() {
    cout << "Til hvilket tall vil du at gangetabellen skal gå?\n";
    int gange {0};
    cin >> gange;
    cout << "\nBredde (chr) på vinduet skal være: ";
    int bredde {0};
    cin >> bredde;
    /*cout << "\nHøyde (chr) på vinduet skal være: "; //skal denne gjøres noe mer med?
     int hoyde {0};
     cin >> hoyde;*/
    setw(bredde);
    for (int i = 1; i < gange+1; i++) {
        for (int j = 1; j <= i; j++){
            cout << (i*j) << setw(bredde);
        }
        cout << "\n";
    }
}

double discriminant(double a, double b, double c) {
    return (pow(b, 2) - (4*a*c));
}

void printRealRoots(double a, double b, double c) {
    double disc = discriminant(a, b, c);
    if (disc > 0) {
        cout << (((-b)+(sqrt(disc)))/(2*a)) << "\n";
        cout << (((-b)-(sqrt(disc)))/(2*a)) << "\n";
        
    }
    else if (disc == 0) {
        cout << ((-b)/(2*a)) << "\n";
    }
    else {
        cout << "Ingen løsning siden det blir negativt under brøkstreken";
    }
}

void solvedQuadraticEquation() {
    cout << "Skriv inn verdier for a, b og c\n";
    cout << "a: ";
    double a {0};
    cin >> a;
    cout << "b: ";
    double b {0};
    cin >> b;
    cout << "c: ";
    double c {0};
    cin >> c;
    printRealRoots(a, b, c);
}

void calculateSeries(vector<int> aarligInnbetaling){
    double totaltLaan {10000};
    double antallAvdrag {10};
    double rente {3};
    double gjenstaendeLaan {totaltLaan};
    while (gjenstaendeLaan >= 0){
        int serie = ((totaltLaan/ antallAvdrag) + ((rente/100) * (gjenstaendeLaan)));
        gjenstaendeLaan -= serie;
        aarligInnbetaling.push_back(serie);
        cout << serie << gjenstaendeLaan;
    }
}

void calculateAnnuity(vector<int> annuitetsLaan) {
    double totaltLaan{10000};
    double rente{3};
    double antallAvdrag{10};
    while (totaltLaan >= 0) {
        int annuitet = (totaltLaan * ((rente/100)/(1-(pow((1+(rente/100)), (-antallAvdrag))))));
        totaltLaan -= annuitet;
        annuitetsLaan.push_back(annuitet);
        cout << annuitet;
    }
}

void innbetalingTilTabell(vector<int> aarligInnbetaling, vector<int> annuitetsLaan){
    int totalAnnuitet{0};
    int totalSerie{0};
    cout << setw(5) << "År" << "Annuitet" << "Serie" << "Differanse\n";
    for(int i = 0; i < aarligInnbetaling.size(); ++i){
        cout << setw(5) << i+1 << annuitetsLaan[i] << aarligInnbetaling[i] << (aarligInnbetaling[i]-annuitetsLaan[i]) << "\n";
        totalAnnuitet += annuitetsLaan[i];
        totalSerie += aarligInnbetaling[i];
    }
    cout << setw(5) << "Total" << totalAnnuitet << totalSerie << "\n";
}

int main(){
    int number {0};
    do {
        cout << "Velg funksjon:\n" << "0) Avslutt\n" << "1) Summer to tall\n" << "2) Summer flere tall\n" << "3) Konverter NOK til EURO.\n" << "4) Skriv ut gangetabell\n" << "5) Løs rotligning\n" << "Angi valg (0-5): ";
        cin >> number;
        switch (number) {
            case 1:
                inputIntegersAndPrintSum();
            case 2:
                inputIntegersUsingLoopAndPrintSum();
            case 3:
                nokToEur();
            case 4:
                gangetabell();
            case 5:
                solvedQuadraticEquation();
        }
    } while (number != 0);
    
    vector<int> aarligInnbetaling(0);
    vector<int> annuitetsLaan(0);

    calculateSeries(aarligInnbetaling);
    calculateAnnuity(annuitetsLaan);
    innbetalingTilTabell(aarligInnbetaling, annuitetsLaan);
    
    return 0;
}

