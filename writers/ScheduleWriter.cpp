//
// Created by nikita on 11/30/19.
//

#include "ScheduleWriter.h"

void ScheduleWriter::write(const std::string &fileName, const std::vector<Schedule> &schedules) {
    file.open(fileName, std::ios::out);

    for (auto &schedule : schedules)
        writeLine(schedule);

    file.close();
}

void ScheduleWriter::writeLine(const Schedule &schedule) {
    file << schedule.company->name;
    file << " ";
    file << schedule.departureTime.toString();
    file << " ";
    file << schedule.arrivalTime.normalised().toString();
    file << std::endl;
}
