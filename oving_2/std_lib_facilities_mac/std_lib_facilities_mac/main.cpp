#include "std_lib_facilities.h"

void inputAndPrintInteger() {
    cout << "Skriv inn et heltall: \n";
    int n {0};
    cin >> n;
    cout << "Du skrev: " << n << "\n";
}

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

bool isOdd(int c) {
    return ((c % 2) == 0);
}

void printHumanReadableTime(int n) {
    int hours {n / 3600};
    int remainder {n % 3600};
    int minutes {remainder / 60};
    int seconds {remainder % 60};
    string total {""};
    if (hours > 0 and ((minutes > 0) or (seconds > 0))) {
        total += to_string(hours) + "timer, ";
    }
    else {
        total += to_string(hours) + "timer.";
    }
    if (minutes > 0 and seconds > 0) {
        total += to_string(minutes) + "minutter og";
    }
    else if (minutes > 0) {
        total += to_string(minutes) + "minutter.";
    }
    if (seconds > 0) {
        total += to_string(seconds) + "sekunder.";
    }
    cout << total << "\n";
}

void inputIntegersUsingLoopAndPrintSum() {  //FIKS!!!, MÅ REGNE SAMMEN NÅR 0 TRYKKES
    cout << "Legg sammen tall ved å skrive inn et heltall, avslutt ved å skrive inn '0'";
    int n {0};
    int i {0};
    do {
        cin >> i;
        n += i;
    }
    while (i!= 0);
    cout << "Summen er: " << n << "\n";
}

double inputDouble () {
    cout << "Skriv inn et flyttall: ";
    double n {0};
    cin >> n;
    return n;
}

void nokToEur() {
    cout << "Skriv inn beløpet i nok som skal konverteres: ";
    double nok {0};
    cin >> nok;
    cout << nok << "kr blir " << setprecision(2) << fixed << (nok / 9.75) << "euro.\n";
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
        for (int j = 1; j <= gange; j++){
            cout << (i*(j)) << setw(bredde);
        }
        cout << "\n";
    }
}

double discriminant(double a, double b, double c) {
    /*double a {0};
    double b {0};
    double c {0};*/
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

void calculateSeries(vector<int>& aarligInnbetaling){
    double totaltLaan {10000};
    double antallAvdrag {10};
    double rente {3};
    double gjenstaendeLaan {totaltLaan};
    for (int i = 0; i < antallAvdrag; ++i){
        int serie = ((totaltLaan/ antallAvdrag) + ((rente/100) * (gjenstaendeLaan)));
        aarligInnbetaling.push_back(serie);
        gjenstaendeLaan -= (totaltLaan/antallAvdrag);
    }
}

void calculateAnnuity(vector<int>& annuitetsLaan) {
    double totaltLaan{10000};
    double rente{3};
    double antallAvdrag{10};
    for (int i = 0; i < antallAvdrag; ++i) {
        int annuitet = (totaltLaan * ((rente/100.0)/(1-pow((1+(rente/100.0)), (-antallAvdrag)))));
        annuitetsLaan.push_back(annuitet);
    }
}

void innbetalingTilTabell(vector<int> aarligInnbetaling, vector<int> annuitetsLaan){
    int totalAnnuitet{0};
    int totalSerie{0};
    cout << setw(5) << "År" << setw(15) << setw(15) << "Annuitet" << setw(15) << "Serie" << setw(15) << "Differanse\n";
    for(int i = 0; i < aarligInnbetaling.size(); ++i){
        cout << setw(5) << i+1 << setw(15) << annuitetsLaan[i] << setw(15) << aarligInnbetaling[i] << setw(15) << (aarligInnbetaling[i]-annuitetsLaan[i]) << "\n";
        totalAnnuitet += annuitetsLaan[i];
        totalSerie += aarligInnbetaling[i];
    }
    cout << setw(5) << "Total" << setw(15) << totalAnnuitet << setw(15) << totalSerie << "\n";
}

int main(){
    cout << "Oppgave 1a)\n";
    inputAndPrintInteger();
    
    cout << "Oppgave 1b)\n";
    int heltall {inputInteger()};
    cout << "Du skrev: " << heltall << "\n";
    
    /*cout << "Oppgave 1c)\n";
    inputIntegersAndPrintSum();*/
    
    //Oppgave 1d)
    
     /*Jeg valgte å bruke inputInteger fordi denne returnerer et tall istedenfor å bare printe den.
     Vi vil i denne oppgaven opprette to variabler med heltall som objekter slik vi til slutt kan legge de sammen.
     Om vi hadde brukt den første funksjonen ville ikke denne returnert noen objekter som vi faktisk kunne
     bruke til variablene vår.*/
    
    
    cout << "Oppgave 1e)\n";
    for (int c = 0; c < 16; c++) {
        cout << setw(3) << isOdd(c);
    }
    cout << "\n";
    
    cout << "Oppgave 1f)\n";
    cout << "Skriv inn sekunder\n";
    int sekunder {0};
    cin >> sekunder;
    printHumanReadableTime(sekunder);
    
    /*cout << "Oppgave 2a)\n";
    inputIntegersUsingLoopAndPrintSum();*/
    
    //Oppgave 2b)
    
     /*Både while og for løkker egner seg her, men om man tenker for oppgaver som f.eks. en kalkulator vil en while
     løkke egne seg mye bedre. En for løkke er dermed den beste om man skal legge sammen score for en fast
     gitt totalmengde antall.*/
    
    
    cout << "Oppgave 2c)\n";
    inputDouble();
    
    /*cout << "Oppgave 2d)\n";
    nokToEur();*/
    
    //Oppgave 2e)
    
     /*inputDouble er bedre enn inputInteger fordi selv om man sender et heltall i norske kroner
     er der ønskelig å få et desimaltall tilbake siden man ikke kan garantere at konverteringen ikke blir
     et flyttall.*/
    
    //cout << "Oppgave 3a)\n";
    int number {0};
    do {
        cout << "Velg funksjon:\n" << "0) Avslutt\n" << "1) Summer to tall\n" << "2) Summer flere tall\n" << "3) Konverter NOK til EURO.\n" << "4) Skriv ut gangetabell\n" << "5) Løs rotligning\n" << "Angi valg (0-5): ";
        cin >> number;
        switch (number) {
            case 1:
                inputIntegersAndPrintSum();
                break;
            case 2:
                inputIntegersUsingLoopAndPrintSum();
                break;
            case 3:
                nokToEur();
                break;
            case 4:
                gangetabell();  //kom tilbake til denne
                break;
            case 5:
                solvedQuadraticEquation();
                break;
        }
    } while (number != 0);
    //cout << "Oppgave 4a)\n";
    //discriminant(double a, double b, double c);
    
    //cout << "Oppgave 4b)\n";
    //printRealRoots(double a, double b, double c);
    
    //cout << "Oppgave 4c)\n";
    //solvedQuadraticEquation();
    
    //cout << "TEST OPPGAVE 4E!";
    
    //cout << "Oppgave 5a)\n";
    vector<int> aarligInnbetaling(0);
    //calculateSeries();
    //bruk while løkker og .push_back() for å legge inn nedbetalingen
    
    //cout << "Oppgave 5b)\n";
    vector<int> annuitetsLaan(0);
    //calculateAnnuity();
    
    //cout << "Oppgave 5c)\n";
    //innbetalingTilTabell(); - lag denne
     
    calculateSeries(aarligInnbetaling);
    calculateAnnuity(annuitetsLaan);
    innbetalingTilTabell(aarligInnbetaling, annuitetsLaan);

    return 0;
}
