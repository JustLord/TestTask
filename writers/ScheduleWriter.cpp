//
// Created by nikita on 11/30/19.
//

#include "ScheduleWriter.h"

void ScheduleWriter::write(const std::string &fileName, const std::vector<Schedule> &schedules) {
    file.open(fileName, std::ios::out);

    for (unsigned i = 0; i < schedules.size(); i++) {
        if (i && schedules[i - 1].company != schedules[i].company)
            file << std::endl;

        writeLine(schedules[i]);
    }

    file.close();
}

void ScheduleWriter::writeLine(const Schedule &schedule) {
    file << schedule.company->name << " " << schedule.departureTime.toString() << " "
         << schedule.arrivalTime.normalised().toString() << std::endl;
}
