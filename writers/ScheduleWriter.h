//
// Created by nikita on 11/30/19.
//

#ifndef TEST2_SCHEDULEWRITER_H
#define TEST2_SCHEDULEWRITER_H


#include <vector>
#include <fstream>
#include "../entities/Schedule.h"

class ScheduleWriter {
public:
    void write(const std::string& fileName, const std::vector<Schedule>& schedules);
private:
    void writeLine(const Schedule& schedule);

private:
    std::ofstream file;
};


#endif //TEST2_SCHEDULEWRITER_H
