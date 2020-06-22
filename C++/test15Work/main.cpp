#include "Dialog.h"

using namespace std;

/**
 * Главная функция
 * @return
 */
int main() {
    Dialog dialog;
    dialog.execute();  //Запуск диалога с пользователем

    cout << endl << "Нажмите [Enter] для завершения программы!";
    cin.ignore();
    cin.get();

    return 0;
}
