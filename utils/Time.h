//
// Created by nikita on 11/30/19.
//

#pragma once

#include <string>

class Time {
public:
    explicit Time(int time = 0) : _time{time} {}
    static Time fromString(const std::string &format, const std::string &str);
    [[nodiscard]]std::string toString() const;
    Time &normalise();
    [[nodiscard]] Time normalised() const;
    Time &extend();

    friend bool operator!=(const Time &a, const Time &b);
    friend bool operator==(const Time &a, const Time &b);
    friend bool operator<(const Time &a, const Time &b);
    friend bool operator>(const Time &a, const Time &b);
    bool operator<=(const Time &a) { return _time <= a._time; }
    bool operator>=(const Time &a) { return _time >= a._time; }

private:
    static bool isHour(char format);
    static bool isMinute(char format);
    static bool isSecond(char format);

private:
    int _time;
};

inline bool operator!=(const Time &a, const Time &b) { return a._time != b._time; }
inline bool operator==(const Time &a, const Time &b) { return a._time == b._time; }
inline bool operator<(const Time &a, const Time &b) { return a._time < b._time; }
inline bool operator>(const Time &a, const Time &b) { return a._time > b._time; }