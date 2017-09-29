#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
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

void getFactors(int num, vector<int>& factors)
{
    int x = 2;
    int n = num;
    while (x < (n+1) / 2)
    {
        if (n % x == 0)
        {
            factors.push_back(x);
            n = n / x;
        }
        else
        {
            x++;
        }
    }
    if (n != num)
        factors.push_back(n);
}

void display(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << '*';
        else
            cout << endl;
    }
}

int main()
{
    int num;
    cin >> num;

    vector<int> factors;

    getFactors(num, factors);

    
    
    if (factors.size() == 0)
    {
        cout << 1 << endl;
        cout << num << endl;
    }
    else
    {
        vector<int> res;
        
        int max_len = 0;

        int n = factors.size();

        int first = factors[0];
        int last = factors[factors.size() - 1];

        vector<int> mem;

        for (int i = first; i <= last; i++)
        {
            int product = 1;
            for (int j = 0; j < n; j++)
            {
                mem.push_back(i + j);
                product *= i + j;
                if (product > num || num % product != 0)
                {
                    break;
                }
                else if (num % product == 0)
                {
                    if (mem.size() > max_len)
                    {
                        res.assign(mem.begin(), mem.end());
                        max_len = res.size();
                    }
                }
            }
            mem.clear();
        }

        cout << res.size() << endl;
        display(res);

    }


    return 0;
}
