#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <float.h>
using namespace std;

struct SupplyNode{
    int id;
    double price;
    vector<int> downstream;
    SupplyNode(int id) : id(id), price(DBL_MAX) {}
};

int main()
{
    int n;
    double ori_price, r;

    cin >> n;
    cin >> ori_price;
    cin >> r;

    SupplyNode* new_node;
    
    vector<SupplyNode*> supply_vec;

    for (int i = 0; i < n; i++)
    {
        new_node = new SupplyNode(i);
        vector<int> tmp_v;
        new_node->downstream = tmp_v;
        supply_vec.push_back(new_node);
    }

    int buf_num, buf;

    for (int i = 0; i < n; i++)
    {
        cin >> buf_num;
        for (int j = 0; j < buf_num; j++)
        {
            cin >> buf;
            supply_vec[i]->downstream.push_back(buf);
        }
    }

    supply_vec[0]->price = ori_price;

    queue<SupplyNode*> q;
    q.push(supply_vec[0]);

    double price;

    bool flag = false;

    double res;
    int cnt = 0;

    while (!q.empty())
    {
        SupplyNode* node = q.front();

        if (!flag && node->downstream.size() == 0)
        {
            res = node->price;
            cnt = 1;
            flag = true;
        }
        else if (flag && node->downstream.size() == 0 && node->price == res)
        {
            cnt++;
        }
        

        q.pop();
        price = node->price * (1 + r / 100);
        for (int i = 0; i < node->downstream.size(); i++)
        {
            if (price < supply_vec[node->downstream[i]]->price)
                supply_vec[node->downstream[i]]->price = price;
            q.push(supply_vec[node->downstream[i]]);
        }
    }

    printf("%.4lf %d", res, cnt);

    return 0;
}
