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
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    long long num = N;

    long long cnt = 0;

    int e = 1;

    long long a, b;

    while (num)
    {
        a = num / 10;
        b = num % 10;

        cnt += a * e;
        if (b == 1)
        {
            if (e == 1)
                cnt += 1;
            else
                cnt += N % e + 1;
        }
        else if (b > 1)
            cnt += e;

        num = num / 10;
        e = e * 10;
    }
    cout << cnt << endl;
    return 0;
}
