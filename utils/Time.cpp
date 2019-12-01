//
// Created by nikita on 11/30/19.
//

#include "Time.h"

bool Time::isHour(char format) {
    return format == 'h' || format == 'H';;
}

bool Time::isMinute(char format) {
    return format == 'm' || format == 'M';
}

bool Time::isSecond(char format) {
    return format == 's' || format == 'S';
}

Time Time::fromString(const std::string &format, const std::string &str) {
    auto getDigit = [](char c){ return (int) c - '0'; };

    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    auto formatIterator = format.begin();
    auto iterator = str.begin();

    while (formatIterator != format.end()) {
        if (isHour(*formatIterator)) {
            hours = *iterator++;
            formatIterator++;

            while (isHour(*formatIterator)) {
                hours =  hours * 10 + getDigit(*iterator++);
                formatIterator++;
            }

            continue;
        } else if (isMinute(*formatIterator)) {
            minutes = *iterator++;
            formatIterator++;

            while (isMinute(*formatIterator)) {
                minutes = minutes * 10 + getDigit(*iterator++);
                formatIterator++;
            }

            continue;
        } else if (isSecond(*formatIterator)) {
            seconds = *iterator++;
            formatIterator++;

            while (isSecond(*formatIterator)) {
                seconds = seconds * 10 + getDigit(*iterator++);
                formatIterator++;
            }

            continue;
        } else {
            formatIterator++;
            iterator++;
        }
    }

    return Time(hours * 60*60 + minutes * 60 + seconds);
}

std::string Time::toString() const {
    char buff[10];
    sprintf(buff, "%02d:%02d", _time / (60 * 60), _time % (60 * 60));
    return buff;
}

Time &Time::normalise() {
    _time %= 24 * 60 * 60;
    return *this;
}

Time Time::normalised() const {
    Time time = *this;
    time.normalise();
    return time;
}

Time &Time::extend() {
    _time += 24 * 60 * 60;
    return *this;
}
