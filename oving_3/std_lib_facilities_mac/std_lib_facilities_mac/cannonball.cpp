//
//  cannonball.cpp
//  std_lib_facilities_mac
//
//  Created by Jon H on 28/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#include "cannonball.h"

double acclY() {
    return (-9.81);
}

double speedY(double initVelocityY, double time) {
    return (initVelocityY + (acclY() * time));
}

double posX(double initPosition, double initVelocity, double time) {
    return (initPosition + (initVelocity*time));
}

double posY(double initPosition, double initVelocity, double time) {
    return (initPosition + (initVelocity*time)+((acclY()*(std::pow(time, 2)))/2));
}

void printTime(double time) {
    int timer = time;   //antar dette er tilstrekkelig nok antagelse
    int hours {(timer / 3600)};
    int remaining {(timer % 3600)};
    int minutes {(remaining / 60)};
    int seconds {(remaining % 60)};
    std::cout << /*setprecision(2) << fixed <<*/ hours << ":" << minutes << ":" << seconds << endl;
}

double flightTime(double initVelocityY) {
    return abs((-2 * initVelocityY)/acclY());
}


//Ber brukeren om to tall, en vinkel og en fart.
//Formålet er å endre verdien på argumentene.
//theta og absVelocity er referanser til objektene funksjonen kalles med.
void getUserInput(double& theta, double& absVelocity) {
    std::cout << "Skriv inn vinkelen: ";
    std::cin >> theta;
    std::cout << "Skriv inn farten: ";
    std::cin >> absVelocity;
}

//Konverterer fra grader til radianer
double degToRad(double deg);    //brukes denne til noe i det hele tatt?

//Returnerer henholdsvis farten i x-, og y-retnin, gitt en vinkel theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) {
    return (absVelocity * cos(theta));
}
double getVelocityY(double theta, double absVelocity) {
    return (absVelocity * sin(theta));
}

//Dekomponerer farten gitt av absVelocity, i x- og y- komponentene gitt vinkelen theta.
//Komponentene oppdateres gjennom referansen.
//"Vector" i funksjonsnavnet er vektor-begrepet i geometri.
void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY) {
    velocityX = getVelocityX(theta, absVelocity);
    velocityY = getVelocityY(theta, absVelocity);
}

//Beregner hvor langt kulen har bevegd seg i x-retning når posisjonen i y-retningen er 0
double getDistanceTraveled(double velocityX, double velocityY) {
    double time = flightTime(velocityY);
    return (posX(0, velocityX, time));
}

//Beregner avviket i meter mellom verdien der kula lander når startfarten er en gitt verdi
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    return (abs(distanceToTarget - getDistanceTraveled(velocityX, velocityY)));
}
