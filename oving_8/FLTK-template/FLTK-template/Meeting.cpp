
//
//  Meeting.cpp
//  FLTK-template
//
//  Created by Jon H on 05/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#include "std_lib_facilities.h"
#include "Meeting.hpp"
std::ostream &operator<<(std::ostream &os, const Campus& c){
    switch(c){
        case Campus::Gjøvik:
            return std::cout << "Gjøvik";
        case Campus::Trondheim:
            return std::cout << "Trondhiem";
        case Campus::Ålesund:
            return std::cout << "Ålesund";
    }
    return std::cout << "Error";
}

int Meeting::getDay() const{
    return day;
}

int Meeting::getStartTime() const{
    return startTime;
}

int Meeting::getEndTime() const{
    return endTime;
}

Campus Meeting::getLocation() const{
    return location;
}

std::string Meeting::getSubject() const{
    return subject;
}

Person Meeting::getLeader() const{
    return *leader;
}

void Meeting::addParticipant(const Person *participant){
    participants.insert(participant);
}

set<const Meeting*> Meeting::meetings;

vector<std::string> Meeting::getParticipantList() const{
    vector<std::string> pList;
    for(auto part : participants) {
        pList.emplace_back(part->getName());
    }
    return pList;
}

std::ostream &operator<<(std::ostream &os, const Meeting& m){
    os << m.getSubject() << "\n" << m.getLocation() << "\n" << m.getStartTime() << "\n" << m.getEndTime() << "\n" << m.getLeader() << "\n" << "List of participants:\n";
    for (auto it : m.getParticipantList()) {
        os << it << ", ";
    }
    return os;
}

/*vector<const Person*> Meeting::findPotentialCoDriving() const{    //ikke ferdig
    vector<const Person*> matches;
    for(auto it : meetings){
            if(it->getLocation() == location){
                if((it->getEndTime() - it->getStartTime()) <= 3600){
                    matches.emplace_back(it);
            }
        }
    }
    return matches;
}
*/
