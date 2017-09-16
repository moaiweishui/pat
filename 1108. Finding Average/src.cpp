#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

bool isNumber(string s)
{
    int len = s.size();

    int start = 0;

    if (s[0] == '-')
        start = 1;
    int dot = 0;
    for (int i = start; i < len; i++)
    {
        if (s[i] == '.')
        {
            if (i == start)
                return false;
            else if (len - i - 1 >= 3)
                return false;
            else
            {
                dot++;
            }
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            ;;
        }
        else
        {
            return false;
        }
    }

    if (dot > 1)
        return false;
    else
        return true;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        return 0;

    string buf;
    //vector<float> valid_nums;
    vector<string> nums;
    float x;

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        nums.push_back(buf);
    }

    float sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (isNumber(nums[i]))
        {
            stringstream ssbuf;
            ssbuf << nums[i];
            ssbuf >> x;
            if (x <= 1000 && x >= -1000)
            {
                sum += x;
                cnt++;
            }
            else
                cout << "ERROR: " << nums[i] << " is not a legal number" << endl;
        }
        else
            cout << "ERROR: " << nums[i] << " is not a legal number" << endl;
    }
    
    if (cnt == 0)
        cout << "The average of 0 numbers is Undefined" << endl;
    else if(cnt == 1)
    {
      cout << "The average of 1 number is " << setiosflags(ios::fixed) << setprecision(2) << sum << endl;
    }
    else
    {
        float avg = sum / cnt;
        cout << "The average of " << cnt << " numbers is " << setiosflags(ios::fixed) << setprecision(2) << avg << endl;
    }

    return 0;
}
