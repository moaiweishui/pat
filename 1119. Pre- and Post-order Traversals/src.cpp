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
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(NULL), right(NULL){}
};

TreeNode* buildTree(vector<int>& preVec, int pre_l, int pre_r,
    vector<int>& postVec, int post_l, int post_r, bool& unique)
{
    //该子树只有一个节点
    if (pre_l >= pre_r)
    {
        return new TreeNode(preVec[pre_l]);
    }

    //前序区间第一个为父节点
    TreeNode* root = new TreeNode(preVec[pre_l]);
    //前序区间第二个节点是当前父节点的子树的根
    TreeNode* father = new TreeNode(preVec[pre_l + 1]);

    int pos; //father在后序区间中的位置索引
    for (int i = post_l; i < post_r; i++)
    {
        if (postVec[i] == father->val)
        {
            pos = i;
            break;
        }
    }

    //以father为根节点的子树的节点个数（在后续区间中，某个节点之前的所有节点全是其子节点）
    int child_num = pos - post_l + 1;

    //该区间root下只有一棵子树，那无法确定是左子树还是右子树
    if (child_num == pre_r - pre_l + 1 - 1)
        unique = false;
    
    //把father所在看作左子树
    root->left = buildTree(preVec, pre_l + 1, pre_l + child_num, postVec, post_l, post_l + child_num - 1, unique);

    //如果还存在多余节点，则为右子树
    if (child_num < pre_r - pre_l + 1 - 1)
    {
        root->right = buildTree(preVec, pre_l + child_num + 1, pre_r, postVec, post_l + child_num, post_r - 1, unique);
    }

    return root;
}

void inOrder(TreeNode* node, int& cnt, int total_cnt)
{
    if (node == NULL)
        return;

    inOrder(node->left, cnt, total_cnt);
  
    cout << node->val;
    cnt++;
    if (cnt != total_cnt)
        cout << ' ';
    else
        cout << endl;
  
    inOrder(node->right, cnt, total_cnt);
}

int main() {

    int N;
    cin >> N;

    vector<int> preVec;
    vector<int> postVec;
    int buf;
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        preVec.push_back(buf);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> buf;
        postVec.push_back(buf);
    }

    bool unique = true;
    TreeNode* root = buildTree(preVec, 0, N - 1, postVec, 0, N - 1, unique);

    if (unique)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    int cnt = 0;
    inOrder(root, cnt, N);

    return 0;
}
