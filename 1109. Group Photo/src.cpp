#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <set>
#include <functional>
#include <math.h>

using namespace std;

struct person{
    string name;
    int height;
    person(string name, int height) :name(name), height(height){}
};

bool cmp(person* a, person* b)
{
    if (a->height < b->height)
        return true;
    else if (a->height > b->height)
        return false;
    else
        return a->name > b->name;
}

void arrange_person(vector<vector<person*>>& photo, vector<person*>& peoples, 
    int row, int row_size, int start, int end)
{
    int mid = floor(1.0 * (end - start + 1) / 2 + 1) - 1;

    int left = 0;
    int right = row_size - 1;

    int p = mid;
    int cnt = 0;

    while (cnt < row_size)
    {
        if (cnt % 2 == 0)
            p += cnt;
        else
            p -= cnt;
        photo[row][p] = peoples[end - cnt];
        cnt++;
    }

    return;
}

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    string name_buf;
    int height_buf;

    vector<person*> peoples;

    for (int i = 0; i < n; i++)
    {
        cin >> name_buf;
        cin >> height_buf;

        person* new_person = new person(name_buf, height_buf);
        peoples.push_back(new_person);
    }

    sort(peoples.begin(), peoples.end(), cmp);

    double row_size = floor(1.0 * n / k);
    int cnt = 0;

    vector<vector<person*>> photo;

    for (int i = 0; i < k; i++)
    {
        if (i != k - 1)
        {
            vector<person*> _v(row_size);
            photo.push_back(_v);
        }
        else
        {
            vector<person*> _v(n - row_size*(k - 1));
            photo.push_back(_v);
        }
    }

    for (int i = 0; i < k; i++)
    {
        if (i != k - 1)
            arrange_person(photo, peoples, i, row_size, row_size * i, row_size*i + row_size - 1);
        else
            arrange_person(photo, peoples, i, n - row_size*(k - 1), row_size * i, n - 1);
    }

    for (int i = k - 1; i >= 0; i--)
    { 
        for (int j = 0; j < photo[i].size(); j++)
        {
            cout << photo[i][j]->name;
            if (j != photo[i].size() - 1)
                cout << ' ';
            else
                cout << endl;
        }
    }

    return 0;
}
