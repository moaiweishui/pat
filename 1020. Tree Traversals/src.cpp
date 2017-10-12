#include <stdio.h>
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

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int val) :val(val), left(NULL), right(NULL){}
};

TreeNode* buildTree(vector<int> postOrder, int post_l, int post_r,
    vector<int> midOrder, int mid_l, int mid_r)
{
    if (post_l > post_r)
        return NULL;

    TreeNode* node = new TreeNode(postOrder[post_r]);

    if (post_l == post_r)
    {
        return node;
    }

    auto it = find(midOrder.begin() + mid_l, midOrder.begin() + mid_r, node->val);
    int pos = it - midOrder.begin();

    int left_num = pos - mid_l;
    int right_num = mid_r - pos;

    node->left = buildTree(postOrder, post_l, post_l + left_num - 1, midOrder, mid_l, pos - 1);
    node->right = buildTree(postOrder, post_l + left_num, post_r - 1, midOrder, pos + 1, mid_r);

    return node;
}

int main()
{
    int N;
    cin >> N;
    vector<int> postOrder;
    vector<int> midOrder;

    int buf;
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        postOrder.push_back(buf);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        midOrder.push_back(buf);
    }

    TreeNode* root = buildTree(postOrder, 0, N - 1, midOrder, 0, N - 1);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();

        if (node == root)
            cout << node->val;
        else
            cout << ' ' << node->val;

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);

        q.pop();
    }

    return 0;
}
