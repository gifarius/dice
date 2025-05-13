#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void printDice(int value) {
    switch (value) {
    case 1:
        cout << " ---------" << endl;
        cout << "|         |" << endl;
        cout << "|    *    |" << endl;
        cout << "|         |" << endl;
        cout << " ---------" << endl;
        break;
    case 2:
        cout << " ---------" << endl;
        cout << "|         |" << endl;
        cout << "|  *   *  |" << endl;
        cout << "|         |" << endl;
        cout << " ---------" << endl;
        break;
    case 3:
        cout << " ---------" << endl;
        cout << "|    *    |" << endl;
        cout << "|         |" << endl;
        cout << "|  *   *  |" << endl;
        cout << " ---------" << endl;
        break;
    case 4:
        cout << " ---------" << endl;
        cout << "| *     * |" << endl;
        cout << "|         |" << endl;
        cout << "| *     * |" << endl;
        cout << " ---------" << endl;
        break;
    case 5:
        cout << " ---------" << endl;
        cout << "| *     * |" << endl;
        cout << "|    *    |" << endl;
        cout << "| *     * |" << endl;
        cout << " ---------" << endl;
        break;
    case 6:
        cout << " ---------" << endl;
        cout << "| *     * |" << endl;
        cout << "| *     * |" << endl;
        cout << "| *     * |" << endl;
        cout << " ---------" << endl;
        break;
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    int theme = 9;
    srand(time(0));  

    while (true) {
        int choice;

        clearScreen(); 

        int bot = rand() % 6 + 1;
        int user = rand() % 6 + 1;

        cout << "\033[3" << theme << "m===================\n\tБот\n===================\033[0m" << endl;
        printDice(bot);

        cout << "\033[3" << theme << "m===================\n\tИгрок\n===================\033[0m" << endl;
        printDice(user);

        cout << "1. Продолжать\n2. Редактировать тему\n3. Выход\n# > ";
        cin >> choice;

        if (choice == 1) {
            continue;
        }
        else if (choice == 2) {
            while (true) {
                int tmp;
                cout << "Пожалуйста, выберите цвет:\n";
                cout << "1 - Красный\n2 - Зеленый\n3 - Желтый\n4 - Синий\n5 - Пурпурный\n6 - Голубой\n7 - Белый\n";
                cout << "# > ";
                cin >> tmp;
                if (tmp >= 1 && tmp <= 7) {
                    theme = tmp;
                    break;
                }
                else {
                    clearScreen();
                    cout << "Цвет не найден.Попробуйте еще раз." << endl;
                }
            }
            clearScreen();
        }
        else if (choice == 3) {
            break;
        }
        else {
            cout << "Ошибка! Неверный выбор." << endl;
        }
    }

    return 0;
}
