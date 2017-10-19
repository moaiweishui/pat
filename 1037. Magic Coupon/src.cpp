#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool cmp(long long a, long long b)
{
    return abs(a) > abs(b);
}

int main()
{
    int NC, NP;

    vector<long long> C_pos;
    vector<long long> C_neg;
    
    vector<long long> P_pos;
    vector<long long> P_neg;

    long long buf;

    cin >> NC;
    for (int i = 0; i < NC; i++)
    {
        scanf("%lld", &buf);
        if (buf > 0)
            C_pos.push_back(buf);
        else if (buf < 0)
            C_neg.push_back(buf);
    }

    cin >> NP;
    for (int i = 0; i < NP; i++)
    {
        scanf("%lld", &buf);
        if (buf > 0)
            P_pos.push_back(buf);
        else if (buf < 0)
            P_neg.push_back(buf);
    }

    sort(C_pos.begin(), C_pos.end(), cmp);
    sort(C_neg.begin(), C_neg.end(), cmp);
    sort(P_pos.begin(), P_pos.end(), cmp);
    sort(P_neg.begin(), P_neg.end(), cmp);

    int len_pos = C_pos.size() < P_pos.size() ? C_pos.size() : P_pos.size();
    int len_neg = C_neg.size() < P_neg.size() ? C_neg.size() : P_neg.size();

    int sum = 0;

    for (int i = 0; i < len_pos; i++)
        sum += C_pos[i] * P_pos[i];

    for (int i = 0; i < len_neg; i++)
        sum += C_neg[i] * P_neg[i];

    cout << sum << endl;

    return 0;
}
