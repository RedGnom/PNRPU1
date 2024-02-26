#include <iostream>
using namespace std;
int board[8][8] = { 0 };
int k = 0;
// Функция для вывода результата
void print() {
    cout << "Ход номер " << ++k << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
// Заполнение поля и установка ферзя
void setQueen(int i, int j) {
    for (int k = 0; k < 8; k++) {
        // Строки и столбцы
        ++board[k][j];
        ++board[i][k];
        int diag;
        // Заполнение главной диагонали
        diag = j - i + k;
        if (diag >= 0 && diag < 8) {
            ++board[k][diag];
        }
        // Побочная диагональ
        diag = j + i - k;
        if (diag >= 0 && diag < 8) {
            ++board[k][diag];
        }
    }
    board[i][j] = -1; // Метка отличающая ферзя от остальных клеток
    print();
}
// Удаление ферзя с доски, действия аналогичный установке, но со знаком минус
void resetQueen(int i, int j) {
    for (int k = 0; k < 8; k++) {
        --board[k][j];
        --board[i][k];
        int diag;
        diag = j - i + k;
        if (diag >= 0 && diag < 8) {
            --board[k][diag];
        }
        diag = j + i - k;
        if (diag >= 0 && diag < 8) {
            --board[k][diag];
        }
    }
    board[i][j] = 0; // Обозначение свободной клетки
    print();
}

bool tryQueen(int i) {
    bool result = false;
    for (int j = 0; j < 8; ++j) {
        if (board[i][j] == 0) { // Если находиться свободное место, то устанавливем ферзя
            setQueen(i, j);
            if (i == 7) {
                result = true; // Если дошли до конца, то завершаем функцию
            }
            else {
                // В противном случае удаляем ферзя
                if (!(result = tryQueen(i + 1))) {
                    resetQueen(i, j);
                }
            }
        }
        if (result) {
            break;
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    // Вызываем функцию с 1 строки
    tryQueen(0);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            // Заменяем ферзей на q, а остальные цифры на *
            if (board[i][j] == -1) {
                cout << "Q ";
            }
            else {
                cout << "* ";
            }
        }
        cout << endl;
    }
    return 0;
}