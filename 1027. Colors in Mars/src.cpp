#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

pair<char, char> dec2radix13(int n)
{
    pair<char, char> res;
    int high = n / 13;
    int low = n % 13;

    if (high >= 10)
        res.first = high - 10 + 'A';
    else
        res.first = high + '0';

    if (low >= 10)
        res.second = low - 10 + 'A';
    else
        res.second = low + '0';

    return res;
}

int main()
{
    ios::sync_with_stdio(false);

    int r_dec, g_dec, b_dec;
    cin >> r_dec >> g_dec >> b_dec;

    pair<char, char> r_13, g_13, b_13;
    r_13 = dec2radix13(r_dec);
    g_13 = dec2radix13(g_dec);
    b_13 = dec2radix13(b_dec);

    cout << '#' << r_13.first << r_13.second;
    cout << g_13.first << g_13.second;
    cout << b_13.first << b_13.second << endl;

    return 0;
}
