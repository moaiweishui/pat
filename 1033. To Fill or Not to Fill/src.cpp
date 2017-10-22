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
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct GasStation{
    double dist;
    double price;
    GasStation(double dist, double price) : dist(dist), price(price){}
};

bool cmpGasStation(GasStation* a, GasStation* b)
{
    return a->dist < b->dist;
}

int cmpDouble(double a, double b)
{
    if (abs(a - b) < DBL_EPSILON)
        return 0;
    else if (a > b)
        return 1;
    else if (a < b)
        return -1;
}

int main()
{
    double tank_max_size, total_dist, per_gas_run_dist;
    int gas_station_num;

    cin >> tank_max_size >> total_dist >> per_gas_run_dist >> gas_station_num;

    vector<GasStation*> gas_station_list;

    double price, dist;
    GasStation* new_gas_station = NULL;
    for (int i = 0; i < gas_station_num; i++)
    {
        cin >> price >> dist;
        new_gas_station = new GasStation(dist, price);
        gas_station_list.push_back(new_gas_station);
    }

    sort(gas_station_list.begin(), gas_station_list.end(), cmpGasStation);

    if (gas_station_list[0]->dist != 0)
    {
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }

    new_gas_station = new GasStation(total_dist, DBL_MAX);
    gas_station_list.push_back(new_gas_station);

    double full_gas_dist = tank_max_size * per_gas_run_dist;
    int p = 0; //current gas station index
    double cost = 0;
    double curr_gas = 0;

    while (p != gas_station_list.size() - 1)
    {
        //找巡航范围内油价更便宜的加油站，不包括终点
        bool find_cheaper_station = false;
        int cheaper_station_index = 0;
        for (int i = p + 1; i < gas_station_list.size() - 1; i++)
        {
            //超出巡航范围
            if (cmpDouble(gas_station_list[i]->dist, gas_station_list[p]->dist + full_gas_dist) == 1)
                break;

            if (gas_station_list[i]->price < gas_station_list[p]->price)
            {
                find_cheaper_station = true;
                cheaper_station_index = i;
                break;
            }
        }

        if (find_cheaper_station)
        {
            double dist = gas_station_list[cheaper_station_index]->dist - gas_station_list[p]->dist;
            cost += gas_station_list[p]->price * (dist / per_gas_run_dist - curr_gas);
            p = cheaper_station_index;
            curr_gas = 0;
        }
        else
        {
            //判断终点是否在巡航范围内
            if (cmpDouble(gas_station_list[p]->dist + full_gas_dist, total_dist) == 1) //在，则直达终点
            {
                double dist = total_dist - gas_station_list[p]->dist;
                cost += gas_station_list[p]->price * (dist / per_gas_run_dist - curr_gas);
                p = gas_station_list.size() - 1;
            }
            else //不在
            {
                //巡航范围内是否存在加油站
                double min_price = DBL_MAX;
                double min_index = -1;
                for (int i = p + 1; i < gas_station_list.size() - 1; i++)
                {
                    //超出巡航范围
                    if (cmpDouble(gas_station_list[i]->dist, gas_station_list[p]->dist + full_gas_dist) == 1)
                        break;
                    if (gas_station_list[i]->price < min_price)
                    {
                        min_price = gas_station_list[i]->price;
                        min_index = i;
                    }
                }

                if (min_index == -1) //巡航范围内不存在加油站
                {
                    double curr_gas_dist = tank_max_size * per_gas_run_dist;
                    printf("The maximum travel distance = %.2lf\n", gas_station_list[p]->dist + curr_gas_dist);
                    return 0;
                }
                else
                {
                    //加满油
                    double dist = gas_station_list[min_index]->dist - gas_station_list[p]->dist;
                    cost += gas_station_list[p]->price * (tank_max_size - curr_gas);
                    p = min_index;
                    curr_gas = tank_max_size - dist / per_gas_run_dist;
                }

            }
        }
    }
    printf("%.2lf", cost);


    return 0;
}
