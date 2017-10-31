/******************* Solution 1 ********************/
#define _CRT_SECURE_NO_DEPRECATE
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
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int N;
    long long p;
    cin >> N >> p;

    vector<long long> nums;
    long long buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &buf);
        nums.push_back(buf);
    }

    sort(nums.begin(), nums.end());

    vector<int> rowCache1(N, 1);
    vector<int> rowCache2(N, 1);

    int max_len = -1;

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
        {
            for (int j = i; j < N; j++)
            {
                if (j == 0)
                    rowCache1[j] = 1;
                else if (nums[j] <= nums[i] * p)
                    rowCache1[j] = j - i + 1;
                else
                    rowCache1[j] = rowCache1[j - 1];

                if (rowCache1[j] > max_len)
                    max_len = rowCache1[j];
            }           
        }
        else
        {
            if (i != 1)
            {
                rowCache1.assign(rowCache2.begin(), rowCache2.end());
            }

            for (int j = i; j < N; j++)
            {
                if (i == j)
                    rowCache2[j] = 1;
                else if (nums[j] <= nums[i] * p)
                    rowCache2[j] = j - i + 1;
                else
                    rowCache2[j] = max(rowCache1[j], rowCache2[j - 1]);

                if (rowCache2[j] > max_len)
                    max_len = rowCache2[j];
            }
        }

    }

    cout << max_len << endl;

    return 0;
}

/******************* Solution 2 ********************/
#define _CRT_SECURE_NO_DEPRECATE
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
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int binarySearch(vector<long long>& nums, int left, int right, long long target)
{
    if (left == right)
        return left;
    int p = left;
    int q = right;
    int mid;
    while (q - p > 10)
    {
        mid = (p + q) / 2;
        if (nums[mid] <= target)
            p = mid;
        else
            q = mid;
    }
    int i;
    for (i = p; i <= q; i++)
    {
        if (nums[i] > target)
            break;
    }

    return i - 1;
}

int main() {
    int N;
    long long p;
    cin >> N >> p;

    vector<long long> nums;
    long long buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &buf);
        nums.push_back(buf);
    }

    sort(nums.begin(), nums.end());

    vector<int> len(N, 0);

    int _len;
    int max_len = -1;
    for (int i = 0; i < N; i++)
    {
        _len = binarySearch(nums, i, N - 1, nums[i] * p) - i + 1;
        if (_len > max_len)
            max_len = _len;
    }

    cout << max_len;

    return 0;
}
