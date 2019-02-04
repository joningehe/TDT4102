#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "tests.hpp"

int main(){
    //Oppgave 1a) v0 = 5
    //Oppgave 1e) Kombinasjon da man ikke kan endre paa to verdier gjennom referanse uten aa opprette en 3 verdi basert paa det vi har laert, kan bruke std::swap(a, b), men antar dette ikke var ment aa gjoerest
    
    std::cout << "Velg hva som skal gjores: " << endl;
    int n {0};
    std::cin >> n;
    switch(n){
        case 0:
            break;
        case 1:
            testCallByValue();
            break;
        case 2:
            testCallByReference();
            break;
        case 3:
            testSwapNumbers();
            break;
        case 4:
            testVectorSorting();
    }
    
    return 0;
}
