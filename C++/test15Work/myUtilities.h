#pragma once
#include <stdexcept>
#include <memory>
#include <iostream>
#include <ios>
#include <limits>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <regex>

using namespace std;


template<typename ... Args>
inline string string_format(const string &format, Args ... args) {
    size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; // Extra space for '\0'
    if (size <= 0) { throw runtime_error("Ошибка в процессе форматирования!"); }
    unique_ptr<char[]> buf(new char[size]);
    snprintf(buf.get(), size, format.c_str(), args ...);
    return string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
}

inline string trim_str(string &str) {
    str.erase(str.find_last_not_of(" \n\r\t") + 1);
    return str;
}

inline int getIntFromInput() {
    string str;
    int num;

    getline(cin, str);

    while (!regex_match(trim_str(str), regex(R"(^(\+|-)?\d+$)"))) {
        cout << "Неверный формат целочисленного значения! Введите снова!\n";
        getline(cin, str);
    }

    num = stoi(str);

    return num;
}

inline float getFloatFromInput() {
    string str;
    float num;

    getline(cin, str);

    while (!regex_match(trim_str(str), regex(R"(^[-+]?\d*\.?\d*$)"))) {
        cout << "Неверный формат вещественного значения! Введите снова!\n";
        getline(cin, str);
    }

    num = stof(str);

    return num;
}

inline double getDoubleFromInput() {
    string str;
    double num;

    getline(cin, str);

    while (!regex_match(trim_str(str), regex(R"(^[-+]?\d*\.?\d*$)"))) {
        cout << "Неверный формат вещественного значения! Введите снова!\n";
        getline(cin, str);
    }

    num = stof(str);

    return num;
}

inline int getInt(const string &title, int minValue, int maxValue) {
    int value;

    if (!title.empty()) {
        cout << title << endl;
    }

    value = getIntFromInput();

    while (value < minValue || value > maxValue) {
        cout << "Значение должно быть от " << minValue << " до " << maxValue << "!" << endl;
        value = getIntFromInput();
    }

    return value;
}

inline int getInt(const string &title, const vector<int> &codes, const string &outOfRangeMsg) {
    int value;

    if (!title.empty()) {
        cout << title << endl;
    }

    value = getIntFromInput();

    while (find(codes.begin(), codes.end(), value) == codes.end()) {
        if (!outOfRangeMsg.empty()) {
            cout << outOfRangeMsg << endl;
        }

        cout << "\nЗначение должно быть в пределах допустимого набора:\n";
        const vector<int>::const_iterator &iterator = codes.begin();
        for (int el : codes) {
            cout << el << " ";
        }
        cout << "\n\n";

        value = getIntFromInput();
    }

    return value;
}

inline string getString(const string &title) {
    string value;

    if (!title.empty()) {
        cout << title << endl;
    }

    getline(cin, value);
    trim_str(value);

    while (value.empty()) {
        cout << "Значение должно содержать минимум 1 символ!" << endl;
        getline(cin, value);
    }

    return value;
}

inline string getString(const string &title, const string &regex_mask, const string &regexMismatchMsg) {
    string value;

    if (!title.empty()) {
        cout << title << endl;
    }

    getline(cin, value);
    bool valid = !value.empty() && regex_match(trim_str(value), regex(regex_mask));

    while (!valid) {
        if (value.empty()) {
            cout << "Значение должно содержать минимум 1 символ!" << endl;
        }
        if (!regex_match(value.c_str(), regex(regex_mask))) {
            cout << regexMismatchMsg << endl;
        }
        getline(cin, value);
        valid = !value.empty() && regex_match(trim_str(value), regex(regex_mask));
    }

    return value;
}

