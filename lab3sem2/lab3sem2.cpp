#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


int** getMat(string fname) {
    int** A = 0;
    A = new int* [4];
    ifstream f(fname);
    for (int i = 0; i < 4; i++) {
        A[i] = new int[4];
        for (int j = 0; j < 4; j++) {
            f >> A[i][j];
        }
    }
    return A;
}

void printMat(int** A) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

void addMat(int** A, int** B) {
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] + B[i][j] << " ";
        }
        cout << "\n";
    }
}

void mulMat(int** A, int** B) {
    int i, j, k;
    int res[4][4];
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            res[i][j] = 0;
            for (k = 0; k < 4; k++) {
                res[i][j] += A[i][k] * B[k][j];
            }
            
        }
    }
    // Print
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}


int main()
{
    
    /*
    // CREATE MATRIX
    ofstream f("matrix1.txt");
    int A[4][4] = { {1, 0, 1, 4}, {0, 4, 2, 0}, {0, 4, 0, 1}, {5, 3, 0, 0} };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            f << A[i][j] << " ";
        }
        f << "\n";
    }
    */
    
    
    
    
    // READ from file
    int** A = getMat("matrix.txt");
    int** B = getMat("matrix1.txt");

    // Print Mat
    cout << "Mat1:" << endl;
    printMat(A);
    cout << "\n";

    cout << "Mat2:" << endl;
    printMat(B);
    cout << "\n";

    // SUM Mat
    cout << "SUM:" << endl;
    addMat(A, B);
    cout << "\n";

    // MUL Mat
    cout << "Mul:" << endl;
    mulMat(A, B);
    cout << "\n";
    
    

    return 0;
}


