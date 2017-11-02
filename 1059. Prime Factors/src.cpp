#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <string>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<long long> getPrimeFactors(long long num)
{
    vector<long long> res;
    int p = 2;
    long long x = num;
    while (p != x)
    {
        if (x % p == 0)
        {
            res.push_back(p);
            x = x / p;
        }
        else
            p++;
    }
    res.push_back(p);
    return res;
}

int main() {

    long long N;
    cin >> N;
    
    if (N <= 3)
    {
        printf("%lld=%lld\n", N, N);
        return 0;
    }

    vector<long long> factors = getPrimeFactors(N);

    vector<vector<long long>> vec;
    vector<long long> tmp;
    long long last;
    for (int i = 0; i < factors.size(); i++)
    {
        if (i == 0)
        {
            tmp.push_back(factors[i]);
            last = factors[i];
        }
        else
        {
            if (factors[i] == last)
                tmp.push_back(factors[i]);
            else
            {
                vec.push_back(tmp);
                tmp.clear();
                tmp.push_back(factors[i]);
                last = factors[i];
            }
        }
    }
    if (!tmp.empty())
        vec.push_back(tmp);

    printf("%lld", N);
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == 0)
            printf("=");
        else
            printf("*");
        if (vec[i].size() == 1)
            printf("%lld", vec[i][0]);
        else
            printf("%lld^%d", vec[i][0], vec[i].size());
    }
    printf("\n");
    return 0;
}
