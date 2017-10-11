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
    TreeNode(int val) : val(val), left(NULL), right(NULL){}
};

TreeNode* buildTree(vector<int> preOrder, int pre_l, int pre_r, 
    vector<int> inOrder, int in_l, int in_r)
{
    if (pre_l > pre_r)
        return NULL;

    TreeNode* node = new TreeNode(preOrder[pre_l]);

    if (pre_l == pre_r)
    {
        return node;
    }

    auto it = find(inOrder.begin() + in_l, inOrder.begin() + in_r + 1, preOrder[pre_l]);
    int pos = it - inOrder.begin();

    node->left = buildTree(preOrder, pre_l + 1, pre_l + pos - in_l, inOrder, in_l, pos - 1);

    node->right = buildTree(preOrder, pre_l + pos - in_l + 1, pre_r, inOrder, pos + 1, in_r);

    return node;
}

void postOrder(TreeNode* node, int& cnt, int N)
{
    if (node)
    {
        postOrder(node->left, cnt, N);
        postOrder(node->right, cnt, N);
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

    vector<int> preOrder;
    vector<int> inOrder;

    string s_buf;
    int d_buf;

    stack<int> st;

    int root_id;

    for (int i = 0; i < 2 * N; i++)
    {
        cin >> s_buf;

        if (s_buf == "Push")
        {
            cin >> d_buf;
            preOrder.push_back(d_buf);
            st.push(d_buf);
        }
        else
        {
            inOrder.push_back(st.top());
            st.pop();
        }
    }
   
    root_id = preOrder[0];

    TreeNode* root = buildTree(preOrder, 0, N - 1, inOrder, 0, N - 1);

    int cnt = 0;

    postOrder(root, cnt, N);

    return 0;
}
