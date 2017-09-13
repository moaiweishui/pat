#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define UP 4

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
        return 0;

    int r, c;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            c = i;
    }
    r = n / c;

    vector<vector<int>> matrix(r, vector<int>(c, -1));
    int num;
    int status = RIGHT;
    int x, y;
    int tmp;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        num = nums[i];
        switch (status){
        case RIGHT:
            if (i == 0)
            {
                x = 0;
                y = 0;
            }
            else
            {
                if (y + 1 >= c || matrix[x][y + 1] != -1)
                {
                    x++;
                    status = DOWN;
                }
                else
                {
                    y++;
                }
            }
            break;
        case DOWN:
            if (x + 1 >= r || matrix[x + 1][y] != -1)
            {
                y--;
                status = LEFT;
            }
            else
            {
                x++;
            }
            break;
        case LEFT:
            if (y - 1 < 0 || matrix[x][y - 1] != -1)
            {
                x--;
                status = UP;
            }
            else
            {
                y--;
            }
            break;
        case UP:
            if (x - 1 < 0 || matrix[x - 1][y] != -1)
            {
                y++;
                status = RIGHT;
            }
            else
            {
                x--;
            }
            break;
        default:
            break;
        }
        matrix[x][y] = num;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << matrix[i][j];
            if (j != c - 1)
                cout << ' ';
        }
        cout << endl;
    }

    return 0;
}
