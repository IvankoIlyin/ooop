#include<vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include"Matrix.h"
#include"Rationalnumber.h"

using namespace std;

int main()
{
    Matrix NewMatrix;
    Matrix CopyMatrix;
    Matrix E;
    NewMatrix.generateMatrix(2, 1, 5, 1, 5);
    cout << "Matrix:" << endl;
    cout << endl;
    CopyMatrix = NewMatrix;
    NewMatrix.printMatrix();
    NewMatrix.inversionGaus();
    cout << "Inverse Matrix" << endl;
    cout << endl;
    NewMatrix.printMatrix();
    Rationalnumber D = NewMatrix.Determinant();
    cout << "deter=" << D.m << "/" << D.n << endl;
    cout << endl;
    /*vector<vector<Rationalnumber>> NewMatrix;
    vector<vector<Rationalnumber>> InversMatrix;
    vector<vector<Rationalnumber>> E;
    NewMatrix = generateMatrix(2,1,5,1,5);
    cout << "Matrix:" << endl;
    cout << endl;
    printMatrix(NewMatrix);
    cout << endl;
    cout << "Inverse Matrix" << endl;
    cout << endl;
    InversMatrix = inversionGaus(NewMatrix);
    printMatrix(InversMatrix);
    cout << endl;
    cout << "E=InversMatrix*Matrix=" << endl;
    cout << endl;
    E = multipMatrix(NewMatrix, InversMatrix);
    printMatrix(E);
    cout << endl;
    Rationalnumber D = Determinant(InversMatrix, InversMatrix.size());
    cout << "deter=" << D.m << "/" << D.n << endl;
    cout << endl;
    Rationalnumber norma;
    norma = NormaFroben(InversMatrix);
    cout << "Norma Frobeniusa = " << norma.m/norma.n << endl;
    */
}

