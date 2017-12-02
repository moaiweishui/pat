#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <string>
#include <string.h>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
   
    vector<int> couples(100000, -1);
    int N, M;
    cin >> N;
    int id1, id2;
    for (int i = 0; i < N; i++){
        scanf("%d %d", &id1, &id2);
        couples[id1] = id2;
        couples[id2] = id1;
    }

    cin >> M;
    int id;
    vector<bool> party(100000, false);
    set<int> single_set;
    int single = 0;
    for (int i = 0; i < M; i++){
        scanf("%d", &id);
        party[id] = true;
        if (couples[id] == -1){      
            single_set.insert(id);
        }
        else{
            if (party[couples[id]] == true){
                single_set.erase(couples[id]);
            }
            else{
                single_set.insert(id);
            }
        }
    }

    cout << single_set.size() << endl;
    for (auto it = single_set.begin(); it != single_set.end(); it++){
        if (it == single_set.begin())
            printf("%05d", *it);
        else
            printf(" %05d", *it);
    }
    cout << endl;
    return 0;
}
