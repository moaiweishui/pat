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

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), left(NULL), right(NULL){}
};

void inOrder(TreeNode* node, vector<int>& order)
{
    if (node == NULL)
        return;

    inOrder(node->left, order);
    order.push_back(node->val);
    inOrder(node->right, order);
}

int main()
{
    int num;
    cin >> num;

    int l_index, r_index;

    vector<TreeNode*> tree;
    vector<pair<int, int>> index_vec;

    for (int i = 0; i < num; i++)
    {
        cin >> l_index >> r_index;

        TreeNode* new_node = new TreeNode(i);
        tree.push_back(new_node);
        index_vec.push_back(make_pair(l_index, r_index));
    }

    for (int i = 0; i < num; i++)
    {
        if (index_vec[i].first == -1)
            tree[i]->left = NULL;
        else
            tree[i]->left = tree[index_vec[i].first];

        if (index_vec[i].second == -1)
            tree[i]->right = NULL;
        else
            tree[i]->right = tree[index_vec[i].second];
    }

    vector<int> num_vec;
    int buf;
    for (int i = 0; i < num; i++)
    {
        cin >> buf;
        num_vec.push_back(buf);
    }

    sort(num_vec.begin(), num_vec.end());

    TreeNode* root = tree[0];
    vector<int> order;

    inOrder(root, order);

    unordered_map<int, int> hmap;

    for (int i = 0; i < num; i++)
    {
        hmap[order[i]] = num_vec[i];
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();

        cout << hmap[node->val];

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);

        q.pop();
        if (q.empty())
            cout << endl;
        else
            cout << ' ';
    }

    return 0;
}
