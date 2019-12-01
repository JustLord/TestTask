//
// Created by nikita on 11/30/19.
//

#include <iostream>
#include <algorithm>
#include "ScheduleWriter.h"

void ScheduleWriter::write(const std::string &fileName, std::vector<Schedule> schedules) {
    sortResult(schedules);
    writeToFile(fileName, schedules);
}

void ScheduleWriter::writeLine(const Schedule &schedule) {
    file << schedule.company->name << " " << schedule.departureTime.toString() << " "
         << schedule.arrivalTime.normalised().toString() << std::endl;
}

void ScheduleWriter::sortResult(std::vector<Schedule> &schedules) const {
    std::sort(schedules.begin(), schedules.end(), ResultCmp());
}

void ScheduleWriter::writeToFile(const std::string& fileName, const std::vector<Schedule>& schedules) {
    file.open(fileName, std::ios::out);

    if (file.is_open()) {
        for (unsigned i = 0; i < schedules.size(); i++) {
            if (i && schedules[i - 1].company != schedules[i].company)
                file << std::endl;

            writeLine(schedules[i]);
        }

        file.close();

        std::cout << "Result saved on output.txt" << std::endl;
    } else {
        std::cout << "Error while saving result" << std::endl;
    }
}

bool ScheduleWriter::ResultCmp::operator()(const Schedule &a, const Schedule &b) {
    if (a.company->priority != b.company->priority)
        return a.company->priority > b.company->priority;
    return a.departureTime < b.departureTime;
}