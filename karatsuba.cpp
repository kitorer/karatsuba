#include <iostream>
#include <chrono>
#include <fstream>
#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <algorithm>

using namespace std;

double karatsuba(double x, double y){
    if (x < 10 || y < 10)
        return x * y;
    int n = max(to_string(x).length(), to_string(y).length());
    n = (n / 2) + (n % 2);
    double a = x / pow(10, n);
    double b = x - (a * pow(10, n));
    double c = y / pow(10, n);
    double d = y - (c * pow(10, n));
    double ac = karatsuba(a, c);
    double bd = karatsuba(b, d);
    double abcd = karatsuba(a + b, c + d);
    return ac * pow(10, 2 * n) + (abcd - ac - bd) * pow(10, n) + bd;
}


int main()
{
    printf("%lf", karatsuba(1234, 5678));
}