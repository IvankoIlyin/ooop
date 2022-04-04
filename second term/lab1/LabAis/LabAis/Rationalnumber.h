#include <stdio.h>
#include <stdlib.h>
using namespace std;
#ifndef Rational_H
#define Rational_H
class Rationalnumber {
public:
    long long m; //RatMum=m/n
    long long n;
    void print() {
        cout << m << "/" << n << " ";
    }
    double randd(double b, double e)
    {
        return b + (rand() % static_cast<unsigned int>((e - b) * 1000)) / 1000;
    }

    Rationalnumber generate(int begM, int endM, int begN, int endN) {
        Rationalnumber a;
        a.m = randd(begM, endM);
        a.n = randd(begN, endN);
        return a;
    }

    void reduct() {
        bool flag = true;
        int i = 2;
        while (flag) {
            while (m % i == 0 && n % i == 0) {
                m = m / i;
                n = n / i;
            }
            i++;
            if (i == 7) { flag = false; }
        }

    }

    Rationalnumber division(Rationalnumber b) {
        Rationalnumber c;
        c.m = m * b.n;
        c.n = n * b.m;
        m = c.m;
        n = c.n;
        return c;
    }

    Rationalnumber multip(Rationalnumber b) {
        Rationalnumber c;
        c.m = m * b.m;
        c.n = n * b.n;
        m = c.m;
        n = c.n;
        return c;
    }

    Rationalnumber subtract(Rationalnumber b) {
        Rationalnumber c;
        c.m = (m * b.n) - (n * b.m);
        c.n = n * b.n;
        m = c.m;
        n = c.n;
        return c;
    }

    Rationalnumber sum(Rationalnumber b) {
        Rationalnumber c;
        c.m = (m * b.n) + (n * b.m);
        c.n = n * b.n;
        m = c.m;
        n = c.n;
        return c;
    }


};
#endif // !Rational_H




