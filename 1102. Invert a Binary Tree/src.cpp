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

void inOrderWithCnt(TreeNode* node, int& cnt, int& n)
{
    if (node->left)
        inOrderWithCnt(node->left, cnt, n);

    cout << node->val;
    cnt++;

    if (cnt == n)
        cout << endl;
    else
        cout << ' ';

    if (node->right)
        inOrderWithCnt(node->right, cnt, n);

    return;
}

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
        cin >> r_buf >> l_buf;
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

    TreeNode* root = NULL;

    for (int i = 0; i < n; i++)
    {
        if (isRoot[i])
        {
            root = treeVec[i];
            break;
        }
    }
    
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node = NULL;

    while (!q.empty())
    {
        node = q.front();
        cout << node->val;
        if (node->left)
            q.push(node->left);

        if (node->right)
            q.push(node->right);

        q.pop();
        if (!q.empty())
            cout << ' ';
        else
            cout << endl;
    }


    int cnt = 0;
    inOrderWithCnt(root, cnt, n);

    return 0;
}
