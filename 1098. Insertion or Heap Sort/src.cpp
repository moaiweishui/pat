#include <iostream>
#include <algorithm>
#include <functional>
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

void display(vector<int> num)
{
    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i];
        if (i != num.size() - 1)
            cout << ' ';
        else
            cout << endl;
    }
}

void insert_sort(vector<int>& insert_vec, int pos)
{
    sort(insert_vec.begin(), insert_vec.begin() + pos + 1);
}

void heap_sort(vector<int>& heap_vec, int pos)
{
    pop_heap(heap_vec.begin(), heap_vec.end() - pos);
}

int main()
{
    int n;
    cin >> n;

    vector<int> initial_vec;
    vector<int> partial_vec;

    int buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        initial_vec.push_back(buf);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        partial_vec.push_back(buf);
    }

    vector<int> insert_vec(initial_vec.begin(), initial_vec.end());
    vector<int> heap_vec(initial_vec.begin(), initial_vec.end());

    make_heap(heap_vec.begin(), heap_vec.end());


    int i;
    int flag = 0; //1: insert sort 2: heap_sort
    for (i = 0; i < n; i++)
    {
        insert_sort(insert_vec, i);
        heap_sort(heap_vec, i);
        if (insert_vec == partial_vec)
        {
            flag = 1;
            break;
        }
        else if (heap_vec == partial_vec)
        {
            flag = 2;
            break;
        }
    }

    if (flag == 1)
    {
        cout << "Insertion Sort" << endl;
        while (insert_vec == partial_vec)
        {
            i++;
            insert_sort(insert_vec, i);
        }
        display(insert_vec);
    }
    else if (flag == 2)
    {
        cout << "Heap Sort" << endl;
        while (heap_vec == partial_vec)
        {
            i++;
            heap_sort(heap_vec, i);
        }
        display(heap_vec);
    }

    return 0;
}
