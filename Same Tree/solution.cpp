/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool retVal = true;
        if(p == nullptr && q != nullptr)
            return false;
        if(p != nullptr && q == nullptr)
            return false;
        if(p == nullptr)
            return true;
        if(p->val != q->val)
            return false;
        if((p->right == nullptr && q->right != nullptr) || (p->right != nullptr && q->right == nullptr))
            return false;
        if((p->left == nullptr && q->left != nullptr) || (p->left != nullptr && q->left == nullptr))
            return false;
        if(p->right == nullptr && q->left == nullptr)
            return true;
        if(p->right != nullptr)
            retVal = retVal && isSameTree(p->right,q->right);
        if(p->left != nullptr)
            retVal = retVal && isSameTree(p->left,q->left);
        return retVal;
    }
};
