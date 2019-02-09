//
//  utilities.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 31/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "utilities.hpp"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; ++i) {
        startValue += increment;
    }
}

void swapNumbers(int& value1, int& value2) {
    int temp = value2;
    value2 = value1;
    value1 = temp;
}

void sortVector(vector<int>& liste) {
    for(int i = 1; i<liste.size(); ++i) {
        int j = i;
        while((j > 0) and (liste[j-1] > liste[j])) {
            swapNumbers(liste[j], liste[j-1]);
            j -= 1;
        }
    }
}

//Sjekker om listen er odde eller partall og returnerer enten gjennomsnittet av de to midterste eller det midterste tallet
double medianOfVector(vector<int> liste) {
    if (liste.size() % 2 == 0) {
        return ((liste[ceil(liste.size()/2)] + liste[floor(liste.size()/2)])/2);
    }
    else {
        return (liste[floor(liste.size()/2)]);
    }
}

string randomizeString(int length, int lowerBound, int upperBound) {
    string streng = "";
    for (int i = 0; i < length; ++i) {
        srand(static_cast<unsigned int>(time(nullptr)+i));
        int increaseBy = ((rand() % upperBound + lowerBound));
        char letter = 'A' + increaseBy-1;
        streng += letter;
    }
    return streng;
}


string reatInputToString(int length, int lowerBound, int upperBound) {
    string streng = "";
    std::cout << "Skriv inn en streng paa lengde: " << length << endl;
    string temp;
    std::cin >> temp;
    for (int i = 0; i < temp.size(); ++i) {
        char c = temp[i];   //usikker paa om det er noedvendig aa opprette dette som et char objekt
        if (!isalpha(temp[i])) {
            break;
        }
        if (toupper(c) < lowerBound or toupper(c) > upperBound) {
            break;
        }
        while (streng.size() < length) {
            streng += c;
        }
    }
    if (!streng.empty() and (streng.size() == length)) {
        return streng;
    }
    else {
        std::cout << "Du skrev inn en ugyldig streng.";
        return 0;
    }
}


int countChar(string streng, char kar) {
    int count {0};
    for (int i = 0; i < streng.size(); ++i) {
        if (streng[i] == kar) {
            count += 1;
        }
    }
    return count;
}

