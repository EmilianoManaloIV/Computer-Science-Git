/* 
 * File:   main.cpp
 * Author: Emiliano Manalo
 * Created on September 10, 2023 9:30 PM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */
#include <iostream>
#include <cstring>
using namespace std;

const int COLMAX = 80;

int read(char array[][COLMAX], int &rowDet);
void sort(char array[][COLMAX], int rowDet, int colDet, const char replace[], const char with[]);
void print(const char array[][COLMAX], int rowDet, int colDet);
int custom_strcmp(const char a[], const char b[], const char replace[], const char with[]);

int main(int argc, char** argv) {
    const int ROW = 30;
    char array[ROW][COLMAX];
    int colIn, colDet, rowIn, rowDet;
    char replace[COLMAX], with[COLMAX];

    cout << "Modify the sort order by swapping these characters." << endl;
    cin >> replace;
    cout << "With the following characters" << endl;
    cin >> with;
    cout << "Read in a 2 dimensional array of characters and sort by Row" << endl;
    cout << "Input the number of rows <= 20" << endl;
    cin >> rowIn;
    cout << "Input the maximum number of columns <=20" << endl;
    cin >> colIn;

    rowDet = rowIn;
    cout << "Now input the array." << endl;
    colDet = read(array, rowDet);

    sort(array, rowIn, colIn, replace, with);
    cout << "The Sorted Array" << endl;
    print(array, rowIn, colIn);

    return 0;
}

int read(char array[][COLMAX], int &rowDet) {
    int colDet = 0;
    cin.ignore(); // Ignore the newline character from previous input

    for (int i = 0; i < rowDet; i++) {
        cin.getline(array[i], COLMAX);
        int len = strlen(array[i]);
        if (len > colDet) {
            colDet = len;
        }
    }

    return colDet;
}

void sort(char array[][COLMAX], int rowDet, int colDet, const char replace[], const char with[]) {
    for (int i = 0; i < rowDet - 1; i++) {
        for (int j = 0; j < rowDet - i - 1; j++) {
            if (custom_strcmp(array[j], array[j + 1], replace, with) > 0) {
                char temp[COLMAX];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j + 1]);
                strcpy(array[j + 1], temp);
            }
        }
    }
}

void print(const char array[][COLMAX], int rowDet, int colDet) {
    for (int i = 0; i < rowDet; i++) {
        cout << array[i] << endl;
    }
}

int custom_strcmp(const char a[], const char b[], const char replace[], const char with[]) {
    int i = 0;
    while (a[i] && b[i]) {
        char charA = a[i];
        char charB = b[i];
        for (int j = 0; replace[j]; j++) {
            if (a[i] == replace[j]) {
                charA = with[j];
            }
            if (b[i] == replace[j]) {
                charB = with[j];
            }
        }
        if (charA < charB) return -1;
        if (charA > charB) return 1;
        i++;
    }
    return 0;
}
