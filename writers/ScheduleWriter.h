//
// Created by nikita on 11/30/19.
//

#pragma once

#include <vector>
#include <fstream>
#include "../entities/Schedule.h"

class ScheduleWriter {
public:
    void write(const std::string& fileName, std::vector<Schedule> schedules);
private:
    void writeToFile(const std::string& fileName, const std::vector<Schedule>& schedules);
    void sortResult(std::vector<Schedule>& schedules) const;
    void writeLine(const Schedule& schedule);

private:
    std::ofstream file;
    struct ResultCmp{
        bool operator()(const Schedule& a, const Schedule& b);
    };
};