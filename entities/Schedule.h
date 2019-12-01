//
// Created by nikita on 11/30/19.
//
#pragma once

#include "../utils/Time.h"
#include "Company.h"

class Schedule {
public:
    Schedule() : company(nullptr) {};
    Schedule(const Time &arrivalTime, const Time &departureTime, const Company *company)
            : arrivalTime(arrivalTime), departureTime(departureTime), company(company) {}

public:
    Time arrivalTime;
    Time departureTime;
    const Company *company;
};
