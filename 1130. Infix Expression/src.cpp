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
    string val;
    TreeNode *left, *right;
    TreeNode(string val) : val(val), left(NULL), right(NULL){}
};

void postOrder(TreeNode* node, TreeNode* root)
{
    if (node == NULL)
        return;

    postOrder(node->left, root);
    postOrder(node->right, root);

    if (node->left != NULL && node->right != NULL)
    {
        if (node != root)
            node->val = '(' + node->left->val + node->val + node->right->val + ')';
        else
            node->val = node->left->val + node->val + node->right->val;
    }
    else if (node->left == NULL && node->right != NULL)
    {
        if (node != root)
            node->val = '(' + node->val + node->right->val + ')';
        else
            node->val = node->val + node->right->val;
    }

}

int main()
{
    int n;
    cin >> n;

    vector<bool> is_root(n, true);

    vector<TreeNode*> nodeVec;
    vector<pair<int, int>> chileVec;


    string s;
    int l_index, r_index;

    for (int i = 0; i < n; i++)
    {
        cin >> s >> l_index >> r_index;
        
        TreeNode* node = new TreeNode(s);

        chileVec.push_back(make_pair(l_index, r_index));
        nodeVec.push_back(node);
    }

    for (int i = 0; i < n; i++)
    {
        if (chileVec[i].first == -1)
            nodeVec[i]->left = NULL;
        else
        {
            nodeVec[i]->left = nodeVec[chileVec[i].first - 1];
            is_root[chileVec[i].first - 1] = false;
        }

        if (chileVec[i].second == -1)
            nodeVec[i]->right = NULL;
        else
        {
            nodeVec[i]->right = nodeVec[chileVec[i].second - 1];
            is_root[chileVec[i].second - 1] = false;
        }
    }

    int root_index = -1;

    for (int i = 0; i < n; i++)
    {
        if (is_root[i])
        {
            root_index = i;
            break;
        }
    }

    TreeNode* root = nodeVec[root_index];

    postOrder(root, root);

    cout << root->val << endl;

    return 0;
}
