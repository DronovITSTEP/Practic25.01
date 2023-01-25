#include <iostream>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

// создание 2-массива
int** CreateArray(int &row, int& col) {
    Sleep(1000);
    //row = 4, col = 6;
    srand(time(0));
    int** arr = new int* [row];

    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = rand() % 5;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return arr;
}

void Show(int** arr, int &row, int &col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < _msize(arr[0])/sizeof(int); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
/*
Написать программу, которая удаляет из
двухмерного массива, заполненного случайными числами
строки, содержащие нулевые элементы.
*/
int** DeleteZero(int** arr, int &row, int &col) {
    int zero_count = 0;
    int** new_arr = new int* [row];

    //для поиска 0 и создания нового массива
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] == 0) zero_count++;
        }
        new_arr[i] = new int[col - zero_count];
        zero_count = 0;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0, k = 0; j < col; j++) {
            if (arr[i][j] != 0) new_arr[i][k++] = arr[i][j];
        }
    }
    return new_arr;
}

/*
Задание 2. Написать программу, которая поэлементно
суммирует два динамических двумерных массива, заполненных 
случайными числами и сохраняет результат
в третьем массиве.
*/
int** SumArray(int** arr1, int** arr2, int& row, int& col) {
    int** arr3 = new int* [row];
    for (int i = 0; i < row; i++) {
        arr3[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return arr3;
}
/*
Задание 3. Напишите функцию умножения матриц. 
Матрица представляет собой таблицу чисел. Произведением
матрицы A размером M×N (M строк, N столбцов) на
матрицу B размером N×K является матрица C размером
M×K такая, что
arr3[i][j]= arr1[i][1]*arr2[1][j] + arr1[i][2]*arr2[2][j] + … + aiNbNj, для
1 <= i <= M и 1 <= j <= K, где
■ axy — элемент, находящийся на пересечении строки
x и столбца y матрицы A;
■ bxy — элемент, находящийся на пересечении строки
x и столбца y матрицы B;
■ cxy — элемент, находящийся на пересечении строки
x и столбца y матрицы C.
*/

int** MultArray(int** arr1, int** arr2, int M, int N, int K) {
    int** arr3 = new int* [M];
    for (int i = 0; i < M; i++) {
        arr3[i] = new int[K] {};
        for (int j = 0; j < K; j++) {  
            for (int k = 0; k < N; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return arr3;
}

int main()
{
    int row, col;
    int M = 3, N = 2, K = 3;
    //Show(DeleteZero(CreateArray(row, col), row, col), row, col);
    //Show(SumArray(CreateArray(row, col), CreateArray(row, col),row, col),row, col);
    Show(MultArray(CreateArray(M, N), CreateArray(N ,K), M, N, K), M, K);
}
