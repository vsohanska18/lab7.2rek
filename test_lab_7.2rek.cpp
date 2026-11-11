#include <gtest/gtest.h>
#include "lab_7.2rek.cpp"
// Створення матриці
int** makeMatrix() {
    int** M = new int*[5];
    for (int i = 0; i < 5; i++) {
        M[i] = new int[4];
    }
    return M;
}
// Видалення матриці
void deleteMatrix(int** M) {
    for (int i = 0; i < 5; i++) {
        delete[] M[i];
    }
    delete[] M;
}
// Тест 1. Перевірка перестановки мінімуму та максимуму
TEST(Lab72Rek, ChangeMinMax) {
    int** M = makeMatrix();
    int values[5][4] = {
        {4, 1, 9, 2},
        {8, -3, 5, 1},
        {-7, 6, 0, 3},
        {2, 10, -5, 4},
        {3, 3, 3, 3}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = values[i][j];
        }
    }
    int minIndex = 0, maxIndex = 0;
    int min = 0, max = 0;
    Change(M, 5, 4, 0, 0, minIndex, maxIndex, min, max);
    int expected[5][4] = {
        {4, 1, 9, 2},
        {-3, 8, 5, 1},
        {-7, 6, 0, 3},
        {2, -5, 10, 4},
        {3, 3, 3, 3}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(M[i][j], expected[i][j]);
        }
    }
    deleteMatrix(M);
}
// Тест 2. Перевірка незмінності непарних рядків
TEST(Lab72Rek, OddRowsUnchanged) {
    int** M = makeMatrix();
    int values[5][4] = {
        {5, 2, 8, 1},
        {7, -4, 3, 9},
        {6, 2, 1, 4},
        {10, -5, 3, 8},
        {9, 2, 7, 1}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = values[i][j];
        }
    }
    int minIndex = 0, maxIndex = 0;
    int min = 0, max = 0;
    Change(M, 5, 4, 0, 0, minIndex, maxIndex, min, max);
    // Перевіряємо перший, третій і п'ятий рядки
    for (int i = 0; i < 5; i += 2) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(M[i][j], values[i][j]);
        }
    }
    deleteMatrix(M);
}
// Тест 3. Перевірка роботи з від'ємними числами
TEST(Lab72Rek, NegativeNumbers) {
    int** M = makeMatrix();
    int values[5][4] = {
        {1, 2, 3, 4},
        {-8, -2, -15, -5},
        {5, 6, 7, 8},
        {-3, -10, -1, -6},
        {9, 8, 7, 6}
    };
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = values[i][j];
        }
    }
    int minIndex = 0, maxIndex = 0;
    int min = 0, max = 0;
    Change(M, 5, 4, 0, 0, minIndex, maxIndex, min, max);
    // Перевірка другого рядка
    EXPECT_EQ(M[1][1], -15);
    EXPECT_EQ(M[1][2], -2);
    // Перевірка четвертого рядка
    EXPECT_EQ(M[3][1], -1);
    EXPECT_EQ(M[3][2], -10);
    deleteMatrix(M);
}
// Тест 4. Перевірка однакових елементів
TEST(Lab72Rek, EqualElements) {
    int** M = makeMatrix();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            M[i][j] = 5;
        }
    }
    int minIndex = 0, maxIndex = 0;
    int min = 0, max = 0;
    Change(M, 5, 4, 0, 0, minIndex, maxIndex, min, max);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(M[i][j], 5);
        }
    }
    deleteMatrix(M);
}