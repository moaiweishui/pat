#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> coins;
    int buf;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &buf);
        coins.push_back(buf);
    }
    sort(coins.begin(), coins.end(), cmp);
    coins.insert(coins.begin(), -1);

    vector<vector<int>> mem(10001, vector<int>(101, 0));
    vector<vector<bool>> index(10001, vector<bool>(101, false));

    int tmp1, tmp2;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (i == 1)
            {
                if (j >= coins[1])
                {
                    mem[i][j] = coins[1];
                    index[i][j] = true;
                }
                else
                    mem[i][j] = 0;
            }
            else
            {
                if (coins[i] > j)
                {
                    mem[i][j] = mem[i - 1][j];
                }
                else
                {
                    tmp1 = mem[i - 1][j];
                    tmp2 = mem[i - 1][j - coins[i]] + coins[i];
                    if (tmp2 >= tmp1)
                    {
                        mem[i][j] = tmp2;
                        index[i][j] = true;
                    }
                    else
                        mem[i][j] = tmp1;
                }
                
            }
        }
    }

    if (mem[N][M] == M)
    {
        int remain = M;
        vector<int> res;
        
        int r = N;

        while (remain)
        {
            if (index[r][remain] == false)
                r--;
            else
            {
                res.push_back(coins[r]);
                remain = remain - coins[r];
                r--;
            }
        }

        for (int i = 0; i < res.size(); i++)
        {
            if (i == 0)
                printf("%d", res[i]);
            else
                printf(" %d", res[i]);
        }
        printf("\n");
    }
    else
        printf("No Solution\n");

    return 0;
}
