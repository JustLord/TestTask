//
// Created by nikita on 11/30/19.
//
#pragma once

#include "../utils/Time.h"
#include "Company.h"

class Schedule {
public:
    Schedule() = default;
    Schedule(const Time &arrivalTime, const Time &departureTime, const Company *company) : arrivalTime(arrivalTime),
                                                                                           departureTime(departureTime),
                                                                                           company(company) {}
//    static Schedule fromString(const std::string &str) {
//        std::vector<std::string> strs;
//        for (auto s : spliter(str))
//            strs.emplace_back(s);
//
//        Schedule schedule;
//        schedule.company = getCompany(strs[0]);
//        schedule.arrivalTime = Time::fromString(strs[1]);
//        schedule.departureTime = Time::fromString(strs[2]);
//
//        return schedule;
//    }
//
//    [[nodiscard]] std::string toString() const {
//        std::stringstream stream;
//        stream << getCompanyName(company) << ' ' << arrivalTime.toString() << ' '
//               << departureTime.normalised().toString();
//
//        return stream.str();
//    }

public:
    Time arrivalTime;
    Time departureTime;
    const Company *company;
};
