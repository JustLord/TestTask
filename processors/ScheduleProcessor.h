//
// Created by nikita on 11/30/19.
//
#pragma once

#include <vector>
#include "../entities/Schedule.h"

class ScheduleProcessor {
public:
    std::vector<Schedule> process(std::vector<Schedule> schedules);
};
