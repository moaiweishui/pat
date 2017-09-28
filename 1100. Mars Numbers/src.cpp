#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <sstream>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

string mar2earth(string input)
{
    unordered_map<string, int> low_map;
    low_map["tret"] = 0;
    low_map["jan"] = 1;
    low_map["feb"] = 2;
    low_map["mar"] = 3;
    low_map["apr"] = 4;
    low_map["may"] = 5;
    low_map["jun"] = 6;
    low_map["jly"] = 7;
    low_map["aug"] = 8;
    low_map["sep"] = 9;
    low_map["oct"] = 10;
    low_map["nov"] = 11;
    low_map["dec"] = 12;

    unordered_map<string, int> high_map;
    high_map["tam"] = 1;
    high_map["hel"] = 2;
    high_map["maa"] = 3;
    high_map["huh"] = 4;
    high_map["tou"] = 5;
    high_map["kes"] = 6;
    high_map["hei"] = 7;
    high_map["elo"] = 8;
    high_map["syy"] = 9;
    high_map["lok"] = 10;
    high_map["mer"] = 11;
    high_map["jou"] = 12;

    auto findit = find(input.begin(), input.end(), ' ');
    if (findit == input.end())
    {
        auto it = high_map.find(input);
        if (it != high_map.end())
        {
            int val = (*it).second * 13;
            stringstream ss;
            string res;
            ss << val;
            ss >> res;
            return res;
        }
        else
        {
            int val = low_map[input];
            stringstream ss;
            string res;
            ss << val;
            ss >> res;
            return res;
        }
    }
    else
    {
        int pos = findit - input.begin();
        int val1 = high_map[input.substr(0, pos)];
        int val2 = low_map[input.substr(pos + 1, input.length() - pos - 1)];
        int val =  val2 + 13 * val1;
        stringstream ss;
        string res;
        ss << val;
        ss >> res;
        return res;
    }

}

string earth2mar(string input)
{
    unordered_map<int, string> low_map;
    low_map[0] = "tret";
    low_map[1] = "jan";
    low_map[2] = "feb";
    low_map[3] = "mar";
    low_map[4] = "apr";
    low_map[5] = "may";
    low_map[6] = "jun";
    low_map[7] = "jly";
    low_map[8] = "aug";
    low_map[9] = "sep";
    low_map[10] = "oct";
    low_map[11] = "nov";
    low_map[12] = "dec";

    unordered_map<int, string> high_map;
    high_map[1] = "tam";
    high_map[2] = "hel";
    high_map[3] = "maa";
    high_map[4] = "huh";
    high_map[5] = "tou";
    high_map[6] = "kes";
    high_map[7] = "hei";
    high_map[8] = "elo";
    high_map[9] = "syy";
    high_map[10] = "lok";
    high_map[11] = "mer";
    high_map[12] = "jou";

    stringstream ss;
    int num;
    ss << input;  
    ss >> num;

    if (num >= 13)
    {
        int low_num = num % 13;
        int high_num = num / 13;
        if (low_num == 0)
            return high_map[high_num];
        else
            return high_map[high_num] + ' ' + low_map[low_num];
    }
    else
    {
        return low_map[num];
    }
}

int main()
{
    int num;
    cin >> num;

    vector<string> vec;
    

    int cnt = 0;

    cin.get(); //get first '\n'

    while (cnt != num)
    {
        char c = cin.get();
        string s = "";
        while (c != '\n')
        {
            s += c;
            c = cin.get();
        }
        vec.push_back(s);
        cnt++;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i][0] >= '0' && vec[i][0] <= '9')
        {
            cout << earth2mar(vec[i]) << endl;
        }
        else
        {
            cout << mar2earth(vec[i])<<endl;
        }
    }


    return 0;
}
