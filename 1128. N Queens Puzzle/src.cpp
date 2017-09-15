#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

bool isValid(int n, vector<int>& arrange)
{
    set<int> arrange_set(arrange.begin(), arrange.end());
    if (arrange_set.size() < n)
        return false;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(i - j) == abs(arrange[i] - arrange[j]))
                return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> sequences;

    int tmp;
    int buf;

    vector<int> buf_vec;

    for (int i = 0; i < n; i++)
    {
        buf_vec.clear();
        cin >> tmp;
        for (int j = 0; j < tmp; j++)
        {
            cin >> buf;
            buf_vec.push_back(buf);
        }
        sequences.push_back(buf_vec);
    }

    for (int i = 0; i < n; i++)
    {
        if (isValid(sequences[i].size(), sequences[i]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return 0;
}
