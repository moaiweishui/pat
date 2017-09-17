#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int buf;

    vector<int> nums;

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        nums.push_back(buf);
    }

    sort(nums.begin(), nums.end());

    int minus, pos;

    if (n % 2 == 0)
    {
        minus = 0;
        pos = n / 2;
    }
    else
    {
        minus = 1;
        pos = n / 2;
    }

    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < pos; i++)
        sum1 += nums[i];

    for (int i = pos; i < n; i++)
        sum2 += nums[i];

    cout << minus << ' ' << abs(sum1 - sum2) << endl;

    return 0;
}
