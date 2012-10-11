/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void inorderTraversalRecursive(vector<int> &nodes, TreeNode *root) {
        if (root == NULL)
            return;
            
        inorderTraversalRecursive(nodes, root->left);
        nodes.push_back(root->val);
        inorderTraversalRecursive(nodes, root->right);
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        list<TreeNode *> nodes;
    
        TreeNode *ptr = root;
        if (root == NULL)
            return v;
        
        while (true) {
            while (ptr != NULL) {
                nodes.push_back(ptr);            
                ptr = ptr->left;
            }
        
            if (nodes.empty())
                break;
                
            TreeNode *curr = nodes.back();
            nodes.pop_back();
            v.push_back(curr->val);
        
            ptr = curr->right;      
        }
        return v;       
    }
};
