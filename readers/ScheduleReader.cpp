//
// Created by nikita on 11/30/19.
//

#include <iostream>
#include "ScheduleReader.h"

std::optional<std::vector<Schedule>> ScheduleReader::Read(const std::string &fileName) {
    std::vector<Schedule> schedules;

    _fileStream.open(fileName, std::ios::in);

    if (_fileStream.is_open()) {
        while (!_fileStream.eof()) {
            auto schedule = ReadLine();

            if(schedule.company)
                schedules.push_back(schedule);
        }

        _fileStream.close();
    } else {
        std::cout << "Error while open stream file" << std::endl;
        return {};
    }

    return schedules;
}

Schedule ScheduleReader::ReadLine() {
    Schedule schedule;

    std::string buffer;

    _fileStream >> buffer;
    auto companyIterator = _nameToCompanyMap.find(buffer);
    schedule.company = companyIterator != _nameToCompanyMap.end() ? &companyIterator->second : nullptr;

    _fileStream >> buffer;
    schedule.departureTime = Time::fromString("hh:mm", buffer);

    _fileStream >> buffer;
    schedule.arrivalTime = Time::fromString("hh:mm", buffer);

    if (schedule.departureTime > schedule.arrivalTime)
        schedule.arrivalTime.extend();

    return schedule;
}

ScheduleReader::ScheduleReader(const std::map<std::string, Company> &nameToCompanyMap) : _nameToCompanyMap(
        nameToCompanyMap) {}
