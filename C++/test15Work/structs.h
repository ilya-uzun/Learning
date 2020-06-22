#pragma once
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include "constants.h"

#define FIO_MAX_LENGTH 60
#define ADDRESS_MAX_LENGTH 100

using namespace std;

/**
 * Структура "Набор меню"
 * Содержит текстовое представление доступных пунктов меню
 * и коды соответсвующих операций
 */
struct MenuSet {
    string msg;
    vector<int> codes;
};
