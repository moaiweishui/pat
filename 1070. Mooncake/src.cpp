#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <functional>
#include <sstream>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct MoonCake{
    double price;
    double amount;
    double unit_price;
    MoonCake(double amount) : price(0), amount(amount), unit_price(0){}
};

bool cmp(MoonCake* a, MoonCake* b)
{
    return a->unit_price > b->unit_price;
}

int main()
{
    int N, D;
    cin >> N >> D;
    vector<MoonCake*> vec;
    MoonCake* new_mooncake = NULL;
    double amount;
    for (int i = 0; i < N; i++)
    {
        cin >> amount;
        new_mooncake = new MoonCake(amount);
        vec.push_back(new_mooncake);
    }
    double price;
    for (int i = 0; i < N; i++)
    {
        cin >> price;
        vec[i]->price = price;
        vec[i]->unit_price = price / vec[i]->amount;
    }

    sort(vec.begin(), vec.end(), cmp);

    double remain = D;
    int p = 0;
    double profit = 0;
    while (remain)
    {
        if (vec[p]->amount >= remain)
        {
            profit += vec[p]->unit_price * remain;
            remain = 0;
        }
        else
        {
            profit += vec[p]->unit_price * vec[p]->amount;
            remain -= vec[p]->amount;
        }
        p++;
        if (p == vec.size())
            break;
    }

    printf("%.2lf\n", profit);

    return 0;
}
