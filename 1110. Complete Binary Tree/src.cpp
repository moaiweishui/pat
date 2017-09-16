#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{
    int n;
    cin >> n;
    
    vector<TreeNode*> treeVec;
    vector<bool> isRoot(n, true);

    string l_buf, r_buf;
    int tmp;

    for (int i = 0; i < n; i++)
    {
        TreeNode* new_node = new TreeNode(i);
        treeVec.push_back(new_node);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> l_buf >> r_buf;
        if (l_buf == "-")
            treeVec[i]->left = NULL;
        else
        {
            stringstream ss;
            ss << l_buf;
            ss >> tmp;
            isRoot[tmp] = false;
            treeVec[i]->left = treeVec[tmp];
        }

        if (r_buf == "-")
            treeVec[i]->right = NULL;
        else
        {
            stringstream ss;
            ss << r_buf;
            ss >> tmp;
            isRoot[tmp] = false;
            treeVec[i]->right = treeVec[tmp];
        }
    }

    TreeNode* root;

    for (int i = 0; i < n; i++)
    {
        if (isRoot[i])
        {
            root = treeVec[i];
            break;
        }
    }
    
    queue<TreeNode*> treeQueue;
    treeQueue.push(root);

    bool flag = true;
    bool nullflag = false;

    TreeNode* node = NULL;
    TreeNode* left_node = NULL;
    TreeNode* right_node = NULL;

    while (!treeQueue.empty())
    {
        node = treeQueue.front();
        left_node = node->left;
        right_node = node->right;

        if (left_node == NULL && right_node != NULL)
        {
            flag = false;
            break;
        }
        else if (left_node == NULL && right_node == NULL)
        {
            nullflag = true;
        }
        else
        {
            if (left_node)
            {
                if (nullflag)
                {
                    flag = false;
                    break;
                }
                else
                    treeQueue.push(left_node);
            }
            if (right_node)
            {
                if (nullflag)
                {
                    flag = false;
                    break;
                }
                else
                    treeQueue.push(right_node);
            }
                
        }
        treeQueue.pop();
    }

    if (flag)
        cout << "YES " << node->val << endl;
    else
        cout << "NO " << root->val << endl;

    return 0;
}
