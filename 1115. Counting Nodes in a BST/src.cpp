#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeWithLevel {
    TreeNode *node;
    int level;
    TreeNodeWithLevel(TreeNode *node) : node(node), level(NULL) {}
};

void insertBST(TreeNode* node, int key)
{
    if (key <= node->val)
    {
        if (node->left == NULL)
        {
            TreeNode* new_node = new TreeNode(key);
            node->left = new_node;
        }
        else
        {
            insertBST(node->left, key);
        }
    }
    else
    {
        if (node->right == NULL)
        {
            TreeNode* new_node = new TreeNode(key);
            node->right = new_node;
        }
        else
        {
            insertBST(node->right, key);
        }
    }


    return;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> keys;
    int buf;
    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        keys.push_back(buf);
    }

    TreeNode* root = new TreeNode(keys[0]);

    for (int i = 1; i < n; i++)
    {
        insertBST(root, keys[i]);
    }


    queue<TreeNodeWithLevel*> q;

    TreeNodeWithLevel* rootnode = new TreeNodeWithLevel(root);
    rootnode->level = 1;

    q.push(rootnode);

    TreeNodeWithLevel* curr_node;
    TreeNodeWithLevel* tmp_node;

    vector<int> cnt(n, 0);
    int last_level;
    while (!q.empty())
    {
        curr_node = q.front();
        //cout << curr_node->node->val << ' ' << curr_node->level << endl;
        if (curr_node->node->left)
        {
            tmp_node = new TreeNodeWithLevel(curr_node->node->left);
            tmp_node->level = curr_node->level + 1;
            q.push(tmp_node);
        }

        if (curr_node->node->right)
        {
            tmp_node = new TreeNodeWithLevel(curr_node->node->right);
            tmp_node->level = curr_node->level + 1;
            q.push(tmp_node);
        }
        q.pop();
        cnt[curr_node->level - 1]++;
        last_level = curr_node->level;
    }

    cout << cnt[last_level - 1] << " + " << cnt[last_level - 2] << " = " << cnt[last_level - 1] + cnt[last_level - 2] << endl;

    return 0;
}
