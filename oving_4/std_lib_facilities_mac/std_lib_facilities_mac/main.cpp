#include "std_lib_facilities.h"
#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"

int main(){
    //Oppgave 1a) v0 = 5
    //Oppgave 1e) Pass by reference virker som den bedre losningen her siden vi da vil spare oss for koding siden vi ikke trenger aa endre verdien paa value1 manuelt om vi velger aa ta i bruk funksjonen senere
    
    std::cout << "Velg hva som skal gjores: \n 1) testCallByValue() \n 2) testCallByReference() \n 3) testSwapNumbers() \n 4) testVectorSorting() \n 5) testString() \n 6) playMastermind()" << endl;
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
            break;
        case 5:
            testString();
            break;
        case 6:
            playMastermind();
            break;
        case 7:
            cout << readInputToString(8, 1, 6);
            break;
    }
    
    return 0;
}
