/********************************* Solution 1 ***********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int M, N;
    cin >> M >> N;

    int color;

    map<int, int> hmap;

    int max = -1;
    int dominant_color;
    for (int i = 0; i < M * N; i++)
    {
        scanf("%d", &color);
        hmap[color]++;

        if (hmap[color] > max)
        {
            max = hmap[color];
            dominant_color = color;
        }
           
    }

    cout << dominant_color << endl;

    return 0;
}

/********************************* Solution 2 ***********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int M, N;
    cin >> M >> N;

    int color;

    int max = -1;
    int dominant_color;
    int cnt = 0;

    for (int i = 0; i < M * N; i++)
    {
        scanf("%d", &color);
        
        if (cnt == 0)
        {
            dominant_color = color;
            cnt = 1;
        }
        else
        {
            if (color == dominant_color)
                cnt++;
            else
                cnt--;
        }
    }

    cout << dominant_color << endl;

    return 0;
}
