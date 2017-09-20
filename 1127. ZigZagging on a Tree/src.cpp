#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <float.h>
#include <string>
#include <unordered_set>

using namespace std;

#define LEFT -1
#define RIGHT 1

struct TreeNode{
    int val;
    int level;
    TreeNode *left, *right;
    TreeNode(int val) :val(val), level(NULL), left(NULL), right(NULL){}
};

void buildTree(TreeNode* last, bool flag, vector<int>& inorder, vector<int>& postorder,
    int in_l, int in_r, int post_l, int post_r)
{
    if (in_l > in_r)
    {
        if (flag) //true:left
            last->left = NULL;
        else
            last->right = NULL;
        return;
    }

    TreeNode* node = new TreeNode(postorder[post_r]);
    node->level = last->level + 1;
    
    if (flag) //true:left
        last->left = node;
    else
        last->right = node;

    int pos = find(inorder.begin() + in_l, inorder.begin() + in_r + 1, postorder[post_r])
        - inorder.begin();

    buildTree(node, true, inorder, postorder, in_l, pos - 1, post_l, post_l + pos - 1 - in_l);
    buildTree(node, false, inorder, postorder, pos + 1, in_r, post_l + pos - in_l, post_r - 1);

}

int main()
{
    int n;
    cin >> n;

    vector<int> postorder;
    vector<int> inorder;

    int buf;

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        inorder.push_back(buf);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> buf;
        postorder.push_back(buf);
    }

    TreeNode* root = new TreeNode(postorder[n - 1]);
    root->level = 1;

    int pos = find(inorder.begin(), inorder.end(), postorder[n - 1]) - inorder.begin();

    buildTree(root, true, inorder, postorder, 0, pos - 1, 0, pos - 1);
    buildTree(root, false, inorder, postorder, pos + 1, n - 1, pos, n - 2);

    vector<TreeNode*> res;
    
    vector<int> count(n + 1, 0);

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        //cout << node->val << endl;
        count[node->level]++;
        res.push_back(node);
        
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);

        q.pop();
    }

    int curr_level = 1;
    int status = LEFT;
    int cnt = 0;

    while (count[curr_level])
    {
        int num = count[curr_level];
        int start;
        int end;

        if (status == LEFT)
        {
            start = cnt + num - 1;
            end = cnt;
            for (int i = start; i >= end; i--)
            {
                cout << res[i]->val;
                if (cnt == n - 1)
                    cout << endl;
                else
                    cout << ' ';
                cnt++;
            }

            status = RIGHT;
        }
        else
        {
            start = cnt;
            end = cnt + num - 1;
            for (int i = start; i <= end; i++)
            {
                cout << res[i]->val;
                if (cnt == n - 1)
                    cout << endl;
                else
                    cout << ' ';
                cnt++;
            }

            status = LEFT;
        }
        curr_level++;
    }

    return 0;
}
