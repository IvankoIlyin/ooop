#include<vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include"Rationalnumber.h"
using namespace std;

void printMatrix(vector<vector<Rationalnumber>> Matrix) {
    int n = Matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            Matrix[i][j].print();
            if (j == n - 1) { cout << endl; }
        }
    }
}


vector<vector<Rationalnumber>> generateMatrix(int n, int begM, int endM, int begN, int endN) {
    vector<vector<Rationalnumber>> E;
    for (int i = 0; i < n; i++) {
        vector<Rationalnumber> row;
        for (int j = 0; j < n; j++) {
            Rationalnumber a;
            row.push_back(a.generate(begM, endM,  begN,  endN));
        }
        E.push_back(row);
    }
    return E;
}

vector<vector<Rationalnumber>> inversionGaus(vector<vector<Rationalnumber>> A) {

    int n = A.size();

    vector<vector<Rationalnumber>> E;
    Rationalnumber temp;

    for (int i = 0; i < n; i++) {
        vector<Rationalnumber> row;
        for (int j = 0; j < n; j++) {
            Rationalnumber r;
            row.push_back(r);
        }
        E.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {

            E[i][j].m = 0; E[i][j].n = 1;

            if (i == j)
                E[i][j].m = 1; E[i][j].n = 1;
        }
    }



    for (int k = 0; k < n; k++) {
        temp = A[k][k];

        for (int j = 0; j < n; j++) {
            A[k][j].division(temp);
            E[k][j].division(temp);
            A[k][j].reduct();
            E[k][j].reduct();


        }

        for (int i = k + 1; i < n; i++) {
            temp = A[i][k];

            for (int j = 0; j < n; j++) {
                Rationalnumber A1, E1;
                A1 = A[k][j];
                E1 = E[k][j];
                A1.multip(temp);
                E1.multip(temp);
                A[i][j].subtract(A1);
                E[i][j].subtract(E1);
                A[i][j].reduct();
                E[i][j].reduct();

            }
        }
    }

    for (int k = n - 1; k > 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            temp = A[i][k];

            for (int j = 0; j < n; j++) {
                Rationalnumber A1, E1;
                A1 = A[k][j];
                E1 = E[k][j];
                A1.multip(temp);
                E1.multip(temp);
                A[i][j].subtract(A1);
                E[i][j].subtract(E1);
                A[i][j].reduct();
                E[i][j].reduct();


            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = E[i][j];
        }
    }

    return A;
}

vector<vector<Rationalnumber>> multipMatrix(vector<vector<Rationalnumber>> A, vector<vector<Rationalnumber>> B) {
    int n = A.size();
    vector<vector<Rationalnumber>> C;
    for (int i = 0; i < n; i++) {
        vector<Rationalnumber> row;
        for (int j = 0; j < n; j++) {
            Rationalnumber r;
            row.push_back(r);
        }
        C.push_back(row);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j].m = 0;
            C[i][j].n = 1;
            for (int k = 0; k < n; k++) {
                C[i][j].sum(A[i][k].multip(B[k][j]));

            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j].reduct();
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (C[i][j].m == C[i][j].n) {
                C[i][j].m = 1; C[i][j].n = 1;
            }
            if (C[i][j].m == 0) {
                C[i][j].m = 0; C[i][j].n = 1;
            }
        }
    }

    return C;
}


void minorMatrix(vector<vector<Rationalnumber>> A, vector<vector<Rationalnumber>> P, int i, int j, int n)
{
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki < n - 1; ki++) {
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj < n - 1; kj++) {
            if (kj == j) dj = 1;
            P[ki][kj] = A[ki + di][kj + dj];
        }
    }
}

Rationalnumber Determinant(vector<vector<Rationalnumber>> A, int n) {
    vector<vector<Rationalnumber>> P;
    for (int i = 0; i < n; i++) {
        vector<Rationalnumber> row;
        for (int j = 0; j < n; j++) {
            Rationalnumber r;
            row.push_back(r);
        }
        P.push_back(row);
    }
    int i, j, m;
    Rationalnumber d, k;
    j = 0;
    k.m = 1; k.n = 1;
    d.m = 0; d.n = 1;
    m = n - 1;
    if (n < 1) { cout << "determinant is not exist" << endl; }
    if (n == 1) { d = A[0][0]; return d; }
    if (n == 2) {
        Rationalnumber A1, A2;
        A1 = A[0][0]; A1.multip(A[1][1]);
        A2 = A[1][0]; A2.multip(A[0][1]);
        d = A1.subtract(A2);
        return d;
    }
    if (n > 2) {
        for (i = 0; i < n; i++) {
            minorMatrix(A, P, i, 0, n);
            Rationalnumber k1 = k;
            k1.multip(A[i][0]);
            k1.multip(Determinant(P, m));
            d.sum(k1);
            k.m = k.m * -1;
            k.n = k.n * -1;
        }
    }
    return d;

}
