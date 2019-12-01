//
// Created by nikita on 11/30/19.
//
#pragma once

#include <vector>
#include "../entities/Schedule.h"

class ScheduleProcessor {
public:
    std::vector<Schedule> process(std::vector<Schedule> schedules);

private:
    void sortResult(std::vector<Schedule> &schedules) const;

private:
    struct ResultCmp{
        bool operator()(const Schedule& a, const Schedule& b);
    };
};
