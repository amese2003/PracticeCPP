#include "pch.h"

template <typename T> int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

int GetMax(int a, int b)
{
    int c = a - b;

    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);

    int use_sign_of_a = sa ^ sb;

    int use_sign_of_c = ~(sa ^ sb);


    int k = use_sign_of_a * sa + use_sign_of_c * sc;
    int q = ~(k);

    return a * k + b * q;
}

int Test1()
{
    int a = 30;
    int b = 20;
    int c = GetMax(a, b);
    cout << c << endl;
}
