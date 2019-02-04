#include "std_lib_facilities.h"
#include <iostream>
#include "cannonball.h"
#include "utilities.hpp"

class cannonBall {
public:
    double initVelocityY, initVelocity, time, initPosition;
/*public:
    void set_values(double, double, double);*/
};

/*void cannonBall::set_values(double x, double y, double z) {
    cin >> x;
    initVelocityY = x;
    cin >> y;
    time = y;
    cin >> z;
    initPosition = z;
}*/

void testDeviation(double compareOperand, double toOperand, double maxError, string name);
void playTargetPractice();

int main(){
    /*cannonBall ball;
    ball.set_values(0, 0, 0);*/
    
    cannonBall ball;
    std::cout << "Skriv inn velY: ";
    std::cin >> ball.initVelocityY;
    std::cout << "Skriv inn vel: ";
    std::cin >> ball.initVelocity;
    std::cout << "Skriv inn tid: ";
    std::cin >> ball.time;
    std::cout << "Skriv inn pos: ";
    std::cin >> ball.initPosition;
    
    
    
    std::cout << acclY() << endl;
    std::cout << speedY(ball.initVelocityY, ball.time) << endl;
    std::cout << posX(ball.initPosition, ball.initVelocity, ball.time) << endl;
    std::cout << posY(ball.initPosition, ball.initVelocity, ball.time) << endl;
    printTime(ball.time);
    std::cout << flightTime(ball.initVelocityY) << endl;
    
    /*double maxError = 0.0001;
    testDeviation(posX(ball.initPosition, ball.initVelocity, ball.time), 250.0, maxError, to_string(posX(ball.initPosition, ball.initVelocity, ball.time)));    //bruker midlertidig verdi på 250.0 som toOperand da dette var den som ble nevnt i fasit, bruk setprecision(posX(), 1)
    */
    double theta {0};
    double absVelocity {0};
    double velocityX {0};
    double velocityY {0};
    getUserInput(theta, absVelocity);
    getVelocityVector(theta, absVelocity, velocityX, velocityY);
    cout << getDistanceTraveled(velocityX, velocityY) << endl;;
    double distanceToTarget;
    std::cout << "Skriv inn avstand til mål: " << endl;
    std::cin >> distanceToTarget;
    cout << targetPractice(distanceToTarget, velocityX, velocityY) << endl;
    
    std::cout << "Skriv inn nedre grense: ";
    int lowerLimit;
    std::cin >> lowerLimit;
    std::cout << "Skriv inn øvre grense: ";
    int upperLimit;
    std::cin >> upperLimit;
    srand(static_cast<unsigned int>(time(nullptr)));
    std::cout << randomWithLimits(lowerLimit, upperLimit) << endl;
    
    playTargetPractice();
    return 0;
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    double difference {abs(compareOperand-toOperand)};
    if (difference < maxError) {
        std::cout << "Absoluttverdien av differansen er " << difference << " og feilmarginen er " << maxError << " som betyr at avviket er inenfor gyldighetsområdet." << endl;
    }
    else {
        std::cout << "Absoluttverdien av differansen er " << difference << " og feilmarginen er " << maxError << " som betyr at avviket ikke er inenfor gyldighetsområdet." << endl;
    }
}

void playTargetPractice() {
    int lowerLimit {100};
    int upperLimit {1000};
    int target {randomWithLimits(lowerLimit, upperLimit)};
    
    double theta {0};
    double absVelocity {0};
    double velocityX {0};
    double velocityY {0};
    for (int i = 0; i < 10; ++i) {
        getUserInput(theta, absVelocity);
        getVelocityVector(theta, absVelocity, velocityX, velocityY);
        double travelDistance {getDistanceTraveled(velocityX, velocityY)};
        double ballHit {abs(travelDistance-target)};
        
        if (ballHit <= 5) {
            std::cout << "Du traff målet og var " << ballHit << "meter unna.";
            std::cout << "Ballen var " << flightTime(velocityY) << "sekunder i lufta." << endl;
            break;
        }
        else {
            std::cout << "Du bommet :(" << endl;
            std::cout << "Målet er " << target << "meter unna." << endl;
            std::cout << "Ballen var " << flightTime(velocityY) << "sekunder i lufta." << endl;
        }
    }
    
    std::cout << "Du traff desverre ikke målet på noen av forsøkene.";
}
