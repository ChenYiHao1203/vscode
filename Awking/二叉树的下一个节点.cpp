/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode *father;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
 * 
 * };
 */

/**
 * @brief 
 * 分三种情况：

如果该节点有右子树，那么下一个节点就是其右子树中最左边的节点；
如果该节点没有右子树，且是其父节点的左子节点，那么下一个节点就是其父节点；
如果该节点没有右子树，且是其父节点的右子节点，沿着父指针一直向上，直到找到一个是它父节点的左子节点的节点，如果这样的节点存在，那么这个节点的父节点即是所求。
 * 
 */

class solution{
    public:
    TreeNode* inorderSuccessor(TreeNode* p){
        //如果有右子树,找到右子树的最左节点
        if(p->right){
            p=p->right;
            while(p->left) p=p->left;
            return p;
        }
        //如果没有右子树，往上遍历
        //一举两用，如果是第二种情况的话，那么p->father就是答案
        //如果是第三种情况的话p->father也是NULL

        while(p->father && p==p->father->right)//其实就是找  一个节点不是其右节点
        p=p->father;
        // Case 3. 如果该节点没有右子树，且是其父节点的右子节点
        // 沿着父指针一直向上，直到找到一个是它父节点的左子节点的节点
        // 如果这样的节点存在，那么这个节点的父节点即是所求
        
        // Case 2. 如果该节点没有右子树，且是其父节点的左子节点，那么下一个节点就是其父节点

        return p->father;
    }

};

//https://www.acwing.com/solution/content/63101/