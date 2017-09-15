#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sumMoney(vector<int>& coins, int i, int j)
{
    return coins[i] + coins[j];
}

int main()
{
    int n;
    cin >> n;
    int bill;
    cin >> bill;

    vector<int> coins;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        coins.push_back(tmp);
    }

    if (n == 1)
    {
        cout << "No Solution" << endl;
        return 0;
    }

    sort(coins.begin(), coins.end());

    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        tmp = coins[l] + coins[r];
        if (tmp == bill)
        {
            cout << coins[l];
            cout << ' ';
            cout << coins[r] << endl;
            break;
        }
        else if (tmp < bill)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    if (l >= r)
        cout << "No Solution" << endl;
    
    return 0;
}
