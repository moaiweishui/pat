#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> vec;

    int buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        vec.push_back(buf);
    }

    sort(vec.begin(), vec.end());

    vector<int> minMile(n, -1);

    int res;

    for (int i = n; i > 0; i--)
    {
        if (i < vec[n - i])
        {
            res = i;
            break;
        }
    }

    cout << res << endl;

    return 0;
}
