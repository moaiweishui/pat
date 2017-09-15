#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int sumDigits(int num)
{
    int res = 0;

    while (num)
    {
        res += num % 10;
        num = num / 10;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    set<int> nums;

    int buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        nums.insert(sumDigits(buf));
    }

    vector<int> vec(nums.begin(), nums.end());

    sort(vec.begin(), vec.end());

    int size = vec.size();
    cout << size << endl;

    for (int i = 0; i < size; i++)
    {
        if (i < size - 1)
            cout << vec[i] << ' ';
        else
            cout << vec[i] << endl;
    }

    return 0;
}
