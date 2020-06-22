#pragma once
/**
 * Файл с глобальными константами и переменными
 */


/**
 * Перечисление с пунктами меню
 */
enum MenuAction {
    MENU_PRINT = 1,
    MENU_SEARCH = 2,
    MENU_EDIT = 3,
    MENU_REMOVE = 4,
    MENU_TEST_COLL = 5,
    MENU_EXIT = 6
};

/**
 * Состоянии базы данных относительно кол-ва записей
 */
enum EntriesState {
    EMPTY = 1,
    FULL = 2,
    HAS_ENTRIES = 3
};

#define MIN_ENTRIES_NUMBER 1
#define MAX_ENTRIES_NUMBER 100
#define MIN_INT numeric_limits<int>::min()
#define MAX_INT numeric_limits<int>::max()

