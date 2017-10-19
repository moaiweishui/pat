#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <limits.h>
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

void insert(TreeNode* node, int val)
{
    if (val < node->val)
    {
        if (node->left)
            insert(node->left, val);
        else
        {
            TreeNode* new_node = new TreeNode(val);
            node->left = new_node;
        }
    }
    else
    {
        if (node->right)
            insert(node->right, val);
        else
        {
            TreeNode* new_node = new TreeNode(val);
            node->right = new_node;
        }
    }
}

void insertMirror(TreeNode* node, int val)
{
    if (val >= node->val)
    {
        if (node->left)
            insertMirror(node->left, val);
        else
        {
            TreeNode* new_node = new TreeNode(val);
            node->left = new_node;
        }
    }
    else
    {
        if (node->right)
            insertMirror(node->right, val);
        else
        {
            TreeNode* new_node = new TreeNode(val);
            node->right = new_node;
        }
    }
}

void pre(TreeNode* node, vector<int>& preOrder)
{
    if (node)
    {
        preOrder.push_back(node->val);
        pre(node->left, preOrder);
        pre(node->right, preOrder);
    }
}

void displayPostOrder(TreeNode* node, int& cnt, int N)
{
    if (node)
    {
        displayPostOrder(node->left, cnt, N);
        displayPostOrder(node->right, cnt, N);
        cout << node->val;
        cnt++;
        if (cnt == N)
            cout << endl;
        else
            cout << ' ';
    }
}

int main()
{
 
    int N;
    cin >> N;

    vector<int> nums;
    vector<int> min(N, 0);

    int buf;
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        nums.push_back(buf);
    }

    TreeNode* root = NULL;

    for (int i = 0; i < N; i++)
    {
        if (i == 0)
            root = new TreeNode(nums[i]);
        else
            insert(root, nums[i]);
    }
    vector<int> preOrder;
    pre(root, preOrder);

    if (nums == preOrder)
    {
        cout << "YES" << endl;
        int cnt = 0;
        displayPostOrder(root, cnt, N);
    }
    else
    {
        root = NULL;
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
                root = new TreeNode(nums[i]);
            else
                insertMirror(root, nums[i]);
        }
        preOrder.clear();
        pre(root, preOrder);

        if (nums == preOrder)
        {
            cout << "YES" << endl;
            int cnt = 0;
            displayPostOrder(root, cnt, N);
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
