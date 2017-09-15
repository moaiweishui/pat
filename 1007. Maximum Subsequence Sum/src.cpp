#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    int buf;
    int flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        if (buf >= 0)
            flag = true;
        nums.push_back(buf);
    }

    if (n == 1)
    {
        int res = nums[0] >= 0 ? nums[0] : 0;
        cout << res << ' ' << nums[0] << ' ' << nums[0] << endl;
        return 0;
    }
        

    if (!flag)
    {
        cout << 0 << ' ';
        cout << nums[0] << ' ' << nums[n - 1] << endl;
        return 0;
    }

    vector<int> maxSum(n, 0);
    vector<pair<int, int>> position(n, make_pair(0, 0));
    
    maxSum[0] = nums[0];

    int max = 0x80000000;
    int start, end;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > maxSum[i - 1] + nums[i])
        {
            maxSum[i] = nums[i];
            position[i] = make_pair(i, i);
        }
        else
        {
            maxSum[i] = maxSum[i - 1] + nums[i];
            position[i] = make_pair(position[i - 1].first, i);
        }

        if (maxSum[i] > max)
        {
            max = maxSum[i];
            start = position[i].first;
            end = position[i].second;
        }

    }

    cout << max << ' ' << nums[start] << ' ' << nums[end] << endl;

    return 0;
}
