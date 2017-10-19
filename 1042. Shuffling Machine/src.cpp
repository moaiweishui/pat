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

vector<string> shufflingMachine(vector<string> status, vector<int>& order)
{
    vector<string> res(54, "");

    for (int i = 0; i < 54; i++)
    {
        res[order[i] - 1] = status[i];
    }

    return res;
}

int main()
{
 
    int N;
    cin >> N;

    vector<int> order;
    int buf;

    for (int i = 0; i < 54; i++)
    {
        cin >> buf;
        order.push_back(buf);
    }

    vector<string> status;
    string s;
    for (int i = 0; i < 54; i++)
    {
        if (i < 13)
        {
            stringstream ss;
            ss << i + 1;
            ss >> s;
            status.push_back("S" + s);
        }
        else if (i < 26)
        {
            stringstream ss;
            ss << (i - 12);
            ss >> s;
            status.push_back("H" + s);
        }
        else if (i < 39)
        {
            stringstream ss;
            ss << (i - 25);
            ss >> s;
            status.push_back("C" + s);
        }
        else if (i < 52)
        {
            stringstream ss;
            ss << (i - 38);
            ss >> s;
            status.push_back("D" + s);
        }
        else
        {
            stringstream ss;
            ss << (i - 51);
            ss >> s;
            status.push_back("J" + s);
        }
    }

    int cnt = 0;

    while (cnt != N)
    {
        status = shufflingMachine(status, order);
        cnt++;
    }

    for (int i = 0; i < 54; i++)
    {
        cout << status[i];
        if (i != 53)
            cout << ' ';
        else
            cout << endl;
    }

    return 0;
}
