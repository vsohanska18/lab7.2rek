//програма, яка міняє місцями максимальний і мінімальний елементи кожного парного рядка матриці
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Change(int** M, const int rows, const int cols, int i, int j, int &minIndex, int &maxIndex, int &min, int &max);
void Print(int** M, const int rows, const int cols, int i, int j);

#ifndef UNIT_TEST
int main(){
    const int rows = 5, cols = 4, low = -34, high = 34;
    int minIndex, maxIndex, min, max;
    srand((unsigned)time(NULL));
    int** M = new int*[rows];
    for(int i = 0; i < rows; i++){
        M[i] = new int [cols];
    }
    for(int i =0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            M[i][j] = low + rand() % (high - low + 1);
        }
    }
    cout << "Початкова матриця:" << endl;
    Print(M, rows, cols, 0, 0);
    
    Change(M, rows, cols, 0, 0, minIndex, maxIndex, min, max);
    cout<<"Матриця після перестановки:"<<endl;
    Print(M, rows, cols, 0, 0);

    for(int i = 0; i < rows; i++){
        delete[] M[i];
    }
    delete[] M;
    return 0;
}
#endif
void Change(int** M, const int rows, const int cols, int i, int j, int &minIndex, int &maxIndex, int &min, int &max){
    if(i == rows)
        return;
    if(j == 0 && i % 2 == 1){
        min = M[i][0];
        max = M[i][0];
        minIndex = 0;
        maxIndex = 0;
    }
    if(j == cols){
        if(i % 2 == 1){
            int temp = M[i][minIndex];
            M[i][minIndex] = M[i][maxIndex];
            M[i][maxIndex] = temp;
        }
        Change(M, rows, cols, i + 1, 0, minIndex, maxIndex, min, max);
        return;
    }
    if(i % 2 == 1){
        if(M[i][j] > max){
            max = M[i][j];
            maxIndex = j;
        }
        if(M[i][j] < min){
            min = M[i][j];
            minIndex = j;
        }
    }
    Change(M, rows, cols, i, j + 1, minIndex, maxIndex, min, max);
}
void Print(int** M, const int rows, const int cols, int i, int j){
    if(i == rows)
        return;
    if(j == cols){
        cout << endl;
        Print(M, rows, cols, i + 1, 0);
        return;
    } 
    cout << setw(4) << M[i][j];
    Print(M, rows, cols, i, j + 1);
}