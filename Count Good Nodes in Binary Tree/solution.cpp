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
    int goodNodes(TreeNode* root) {
        return count(root,INT_MIN);
    }
    
private:
    int count(TreeNode* node, int x){
        int c = 0;
        if(node->val >= x)
            c++;
        if(node->right != nullptr)
            c += count(node->right,max(x,node->val));
        if(node->left != nullptr)
            c += count(node->left,max(x,node->val));
        return c;
    }
};
