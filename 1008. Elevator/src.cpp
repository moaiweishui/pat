#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int buf;
    int res = 0;

    int last = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        if (buf > last)
            res += (buf - last) * 6;
        else if (buf < last)
            res += (last - buf) * 4;
        last = buf;

        res += 5;       
    }
    cout << res << endl;
    return 0;
}
