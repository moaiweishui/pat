#include <iostream>
#include <algorithm>
#include <math.h>
#include <float.h>
#include <string>

#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

struct TreeNode{
    int val;
    int height;
    TreeNode *left, *right;
    TreeNode(int val) : val(val), height(0), left(NULL), right(NULL){}
};

int getHeight(TreeNode* node)
{
    if (node == NULL)
        return 0;
    else
        return node->height;
}

TreeNode* ll_rotation(TreeNode* node)
{
    TreeNode* new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    new_node->height = max(getHeight(new_node->left), getHeight(node)) + 1;
    
    return new_node;
}

TreeNode* rr_rotation(TreeNode* node)
{
    TreeNode* new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    new_node->height = max(getHeight(node), getHeight(new_node->right)) + 1;

    return new_node;
}

TreeNode* lr_rotation(TreeNode* node)
{
    node->left = rr_rotation(node->left);

    return ll_rotation(node);
}

TreeNode* rl_rotation(TreeNode* node)
{
    node->right = ll_rotation(node->right);

    return rr_rotation(node);
}

TreeNode* insert(TreeNode* root, int key)
{
    if (root == NULL)
    {
        TreeNode* new_node = new TreeNode(key);
        new_node->height = max(getHeight(new_node->left), getHeight(new_node->right)) + 1;
        return new_node;
    }
    else if (key < root->val)
    {
        root->left = insert(root->left, key);
        if (getHeight(root->left) - getHeight(root->right) == 2)
        {
            if (key < root->left->val)
                root = ll_rotation(root);
            else if (key > root->left->val)
                root = lr_rotation(root);           
        }


    }
    else if (key > root->val)
    {
        root->right = insert(root->right, key);
        if (getHeight(root->right) - getHeight(root->left) == 2)
        {
            if (key > root->right->val)
                root = rr_rotation(root);
            else if (key < root->right->val)
                root = rl_rotation(root);
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

bool isCompleteTree(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);

    bool flag = false;

    while (!q.empty())
    {
        TreeNode* node = q.front();

        q.pop();

        if (flag && (node->left || node->right))
            return false;
        
        if (!flag)
        {
            if (node->left && node->right)
            {
                q.push(node->left);
                q.push(node->right);
            }
            else if (node->left)
            {
                q.push(node->left);
                flag = true;
            }
            else if (node->right)
            {
                return false;
            }
            else
            {
                flag = true;
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n;

    vector<int> node_val;

    int buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        node_val.push_back(buf);
    }

    TreeNode* root = new TreeNode(node_val[0]);
    root->height = 1;

    for (int i = 1; i < n; i++)
    {
        root = insert(root, node_val[i]);
    }

    queue<TreeNode*> q;
    q.push(root);

    int cnt = 0;

    while (!q.empty())
    {
        TreeNode* node = q.front();
        cout << node->val;
        cnt++;
        if (cnt == n)
            cout << endl;
        else
            cout << ' ';

        if (node->left)
        {
            q.push(node->left);
        }
            

        if (node->right)
        {
            q.push(node->right);
        }
            
        q.pop();
    }

    if (isCompleteTree(root))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
