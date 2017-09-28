#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int string2int(string s)
{
    stringstream ss;
    ss << s;
    int res;
    ss >> res;
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<string> nums;
    string buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        nums.push_back(buf);
    }

    string as, bs;
    int a, b, z;

    for (int i = 0; i < n; i++)
    {
        int len = nums[i].length();
        
        as = nums[i].substr(0, len / 2);
        bs = nums[i].substr(len / 2, len / 2);

        a = string2int(as);
        b = string2int(bs);
        z = string2int(nums[i]);

        int x = a*b;

        if (x == 0)
            cout << "No" << endl;
        else
        {
            if (z%x == 0)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
