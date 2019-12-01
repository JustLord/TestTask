//
// Created by nikita on 11/30/19.
//

#ifndef TEST2_SCHEDULEPROCESSOR_H
#define TEST2_SCHEDULEPROCESSOR_H


#include <vector>
#include "../entities/Schedule.h"

class ScheduleProcessor {
public:
    std::vector<Schedule> process(std::vector<Schedule> schedules);
};


#endif //TEST2_SCHEDULEPROCESSOR_H
