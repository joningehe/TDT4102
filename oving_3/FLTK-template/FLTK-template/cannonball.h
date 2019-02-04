//
//  cannonball.h
//  std_lib_facilities_mac
//
//  Created by Jon H on 28/01/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//
#pragma once
#include "std_lib_facilities.h"
#ifndef cannonball_h
#define cannonball_h

double acclY();
double speedY(double initVelocityY, double time);
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);
void printTime(double time);
double flightTime(double initVelocityY);

void getUserInput(double& theta, double& absVelocity);
double degToRad(double deg);
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
void getVelocityVector(double theta, double absVelocity, double& velocityX, double& velocityY);

double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);


#endif /* cannonball_h */
