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

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    int type;  //0: black  1: red
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val, int type) : val(val), type(type), left(NULL), right(NULL){}
};

void insert(TreeNode* node, int val)
{
    if (abs(val) < node->val)
    {
        if (node->left == NULL)
        {
            TreeNode* new_node = NULL;
            if (val < 0)
                new_node = new TreeNode(-val, 1);
            else
                new_node = new TreeNode(val, 0);

            node->left = new_node;
        }
        else
            insert(node->left, val);
    }
    else
    {
        if (node->right == NULL)
        {
            TreeNode* new_node = NULL;
            if (val < 0)
                new_node = new TreeNode(-val, 1);
            else
                new_node = new TreeNode(val, 0);

            node->right = new_node;
        }
        else
        {
            insert(node->right, val);
        }
    }
}

TreeNode* buildBST(vector<int> vec)
{
    TreeNode* root = NULL;
    if (vec[0] < 0)
        root = new TreeNode(-vec[0], 1);
    else
        root = new TreeNode(vec[0], 0);
    
    for (int i = 1; i < vec.size(); i++)
    {
        insert(root, vec[i]);
    }
    return root;
}

bool checkRule2(TreeNode* root)
{
    return root->type == 0;
}

bool checkRule4(TreeNode* root)
{
    TreeNode* node = root;
    queue<TreeNode*> q;
    
    q.push(node);

    while (!q.empty())
    {
        node = q.front();
        
        if (node->type == 1)
        {
            if (node->left != NULL)
            {
                if (node->left->type == 1)
                    return false;
                else
                    q.push(node->left);
            }

            if (node->right != NULL)
            {
                if (node->right->type == 1)
                    return false;
                else
                    q.push(node->right);
            }

        }
        else
        {
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right); 
        }           
        q.pop();
    }
    return true;
}

void DFS(TreeNode* node, int& black_cnt, vector<int>& mem)
{
    if (node == NULL)
    {
        mem.push_back(black_cnt + 1);
        return;
    }

    if (node->type == 0) // black
    {
        black_cnt++;
        DFS(node->left, black_cnt, mem);
        black_cnt--;

        black_cnt++;
        DFS(node->right, black_cnt, mem);
        black_cnt--;

    }
    else
    {
        DFS(node->left, black_cnt, mem);
        DFS(node->right, black_cnt, mem);
    }
        

    return;
}

bool checkRule5(TreeNode* root)
{
    int black_cnt = 0;
    vector<int> mem;

    DFS(root, black_cnt, mem);

    for (int i = 0; i < mem.size() - 1; i++)
        if (mem[i] != mem[i + 1])
            return false;

    return true;
}

int main() {
    int K;
    cin >> K;

    int N, val;

    vector<vector<int>> tree_list;

    for (int i = 0; i < K; i++)
    {
        vector<int> tmp;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> val;
            tmp.push_back(val);
        }
        tree_list.push_back(tmp);
    }

    for (int i = 0; i < K; i++)
    {
        TreeNode* root = buildBST(tree_list[i]);
        if (checkRule2(root) && checkRule4(root) && checkRule5(root))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
