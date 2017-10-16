#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string.h>
#include <string>
#include <iomanip>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

long int getMid(vector<long>& vec1, vector<long>& vec2, int pos)
{
    int p = 0;
    int q = 0;
    int cnt = 0;
    
    while (p < vec1.size() && q < vec2.size())
    {
        if (vec1[p] <= vec2[q])
        {          
            if (cnt == pos)
                return vec1[p];
            else
            {
                p++;
                cnt++;
            }
        }
        else
        {
            if (cnt == pos)
                return vec2[q];
            else
            {
                q++;
                cnt++;
            } 
        }       
    }

    if (p == vec1.size())
        return vec2[q + pos - cnt];
    else if (q == vec2.size())
        return vec1[p + pos - cnt];

}

int main()
{

    vector<long> vec1;
    vector<long> vec2;
    
    int M, N;

    scanf("%d", &M);
    long buf;
    for (int i = 0; i < M; i++)
    {
        scanf("%ld", &buf);
        vec1.push_back(buf);
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%ld", &buf);
        vec2.push_back(buf);
    }

    int mid = (M + N - 1) / 2;
    long res = getMid(vec1, vec2, mid);

    printf("%ld\n", res);

    return 0;
}
