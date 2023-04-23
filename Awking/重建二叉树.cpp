#include<bits/stdc++.h>
using namespace std;

/*
 * @desc: 树的遍历+DFS递归+哈希表 - 重建二叉树。

【知识点】
    - DFS；递归；树的遍历；哈希表。

【本题思路】
    递归建立整棵二叉树：先递归创建左右子树，然后创建根节点，并让指针指向两棵子树。
    （1）先利用前序遍历找根节点：前序遍历的第一个数，就是根结点的值。
    （2）在中序遍历序列中找到当前根结点的位置 k，则在序列中 k 的左边是左子树的中序遍历序列（in_left, in_left + k - 1），右边是右子树的中序遍历序列（in_left + k + 1, in_right）。
    （3）假设左子树的中序遍历的长度是 l，则在前序遍历中，根结点后面的 l 个数就是左子树的前序遍历序列（pre_left + 1, pre_left + k），剩下的数是右子树的前序遍历序列（pre_left + k + 1, pre_right）。
    （4）获得左右子树的前序遍历序列和中序遍历序列后，我们可以先递归创建出左右子树，然后再创建根结点。

【时间复杂度】
    - T(n) = O(n)。

【注意点】
    （1）左子树的中序遍历序列（in_left, in_left + k - 1），右子树的中序遍历序列（in_left + k + 1, in_right）。
    （2）注意左右子树的中序遍历序列中不包括第 in_left + k 个，这是因为这个结点就是当前的根结点。
    （3）左子树的前序遍历序列（pre_left + 1, pre_left + k），右子树的前序遍历序列（pre_left + k + 1, pre_right）。
    （4）注意左右子树的前序遍历序列中不包括第 pre_left 个，这是因为这个结点就是当前的根结点。

【重点文章】
    - 代码： https://www.acwing.com/activity/content/code/content/1466482/
    - 题解： https://www.acwing.com/solution/content/706/ （y总题解，时间复杂度分析）

【变量说明】
    - pos：       记录每个结点在中序遍历序列中的位置。
    - pre：       题目输入数据，表示当前二叉树的前序遍历序列。
    - in：        题目输入数据，表示当前二叉树的中序遍历序列。
    - k：         表示当前根结点在所给的中序遍历范围区间内的位置（分割左右子树）。
    - pre_left：  表示当前根结点所代表的树在前序遍历序列中对应范围的起点位置。
    - pre_right： 表示当前根结点所代表的树在前序遍历序列中对应范围的终点位置。
    - in_left：   表示当前根结点所代表的树在中序遍历序列中对应范围的起点位置。
    - in_right：  表示当前根结点所代表的树在中序遍历序列中对应范围的终点位置。

 * @author: Zzay
 * @time: 2022/05/19 16:20
 */
class Solution {
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right; 5555 
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
public:
    // 记录每个结点在中序遍历序列中的位置
    unordered_map<int, int> pos;

    // DFS递归遍历二叉树
    TreeNode* dfs(vector<int>& pre, vector<int>& in, int pre_left, int pre_right, int in_left, int in_right) {
        // 注意递归结束条件
        if (pre_left > pre_right) {
            return NULL;
        }
        // k 表示当前根结点在所给的中序遍历范围区间内的位置（分割左右子树）
        int k = pos[pre[pre_left]] - in_left;
        // 左子树的中序遍历序列（in_left ~ in_left + k - 1），右子树的中序遍历序列（in_left + k + 1 ~ in_right）
        // 左子树的前序遍历序列（pre_left + 1 ~ pre_left + k），右子树的前序遍历序列（pre_left + k + 1, pre_right）
        TreeNode* root = new TreeNode(pre[pre_left]);
        root->left = dfs(pre, in, pre_left + 1, pre_left + k, in_left, in_left + k - 1);
        root->right = dfs(pre, in, pre_left + k + 1, pre_right, in_left + k + 1, in_right);
        return root;
    }

    // 根据前序遍历序列和中序遍历序列，构建二叉树
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 记录每个结点在中序遍历序列中的位置
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }
        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};