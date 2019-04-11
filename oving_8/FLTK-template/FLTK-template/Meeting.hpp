
//
//  Meeting.hpp
//  FLTK-template
//
//  Created by Jon H on 05/03/2019.
//  Copyright © 2019 Daniel Solberg. All rights reserved.
//
#pragma once
#ifndef Meeting_hpp
#define Meeting_hpp
#include "std_lib_facilities.h"
#include <stdio.h>
#include "Person.hpp"

enum class Campus{
    Gjøvik, Trondheim, Ålesund
};

std::ostream &operator<<(std::ostream &os, const Campus& c);

class Meeting {
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const Person* leader;
    set<const Person*> participants;
    static set<const Meeting*> meetings;
public:
    Meeting(const Meeting&) = delete;
    Meeting& operator=(const Meeting&) = delete;
    
    Meeting(int day, int startTime, int endTime, Campus location, std::string subject, const Person *leader) :
    day(day),
    startTime(startTime),
    endTime(endTime),
    location(location),
    subject(subject),
    leader(leader)
    {
        addParticipant(leader);
        meetings.insert(this);
    }
    ~Meeting(){meetings.erase(this);}
    
    int getDay() const;
    int getStartTime() const;
    int getEndTime() const;
    Campus getLocation() const;
    std::string getSubject() const;
    Person getLeader() const;
    void addParticipant(const Person *participant);
    vector<std::string> getParticipantList() const;
    
    //vector<const Person*> findPotentialCoDriving() const;
};

std::ostream &operator<<(std::ostream &os, const Meeting &m);




#endif /* Meeting_hpp */
