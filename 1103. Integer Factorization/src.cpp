#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <functional>

using namespace std;

int mypow(int a, int b)
{
    int res = 1;
    while (b)
    {
        res *= a;
        b--;
    }
    return res;
}

void traceback(vector<vector<int>>& res, vector<int>& mem, vector<int>& candidates, vector<int>& sum_res, 
    int target, int& size, int seq_sum, int sum, int p, int last)
{
    if (mem.size() == size)
    {
        if (sum == target)
        {
            sum_res.push_back(seq_sum);
            res.push_back(mem);
        }
        return;
    }

    for (int i = last; i < candidates.size(); i++)
    {
        int tmp = mypow(candidates[i], p);
        if (tmp + sum <= target)
        {
            mem.push_back(candidates[i]);
            traceback(res, mem, candidates, sum_res, target, size, candidates[i] + seq_sum, tmp + sum, p, i);
            mem.pop_back();
        }
    }
}

int main()
{
    int num, k, p;

    cin >> num;
    cin >> k;
    cin >> p;

    int maxx = floor(pow(num, 1.0 / p));

    vector<int> candidates;

    for (int i = 0; i < maxx; i++)
    {
        candidates.push_back(maxx - i);
    }

    vector<vector<int>> res;
    vector<int> sum_res;
    vector<int> mem;

    traceback(res, mem, candidates, sum_res, num, k, 0, 0, p, 0);

    if (res.size() == 0)
        cout << "Impossible" << endl;
    else
    {
        int max = 0;
        int pos = -1;

        for (int i = 0; i < res.size(); i++)
        {
            if (sum_res[i] > max)
            {
                max = sum_res[i];
                pos = i;
            }
        }

        cout << num << " = " << res[pos][0] << '^' << p;

        for (int i = 1; i < k; i++)
            cout << " + " << res[pos][i] << '^' << p;
        cout << endl;
    }

    return 0;
}
