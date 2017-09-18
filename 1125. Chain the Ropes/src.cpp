#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> nums;
    double buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        nums.push_back(buf);
    }

    sort(nums.begin(), nums.end());

    double len = nums[0];
    for (int i = 1; i < n; i++)
    {
        len = (len + nums[i]) / 2;
    }

    cout << int(len) << endl;

    return 0;
}
