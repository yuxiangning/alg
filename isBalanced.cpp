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

    int height(map<TreeNode *, int> &tmap, TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = height(tmap, root->left);
        int r = height(tmap, root->right);
        
        int h = ((l > r) ? l : r);
        tmap[root] = abs(l-r);
        return (h+1);
    }
    
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<TreeNode *, int> tmap;
        
        height(tmap, root);
        
         map<TreeNode *, int>::iterator it;
        for (it = tmap.begin(); it != tmap.end(); ++it) {
            if (it->second >= 2)
                return false;
        }
    // Start typing your code here...
        return true;    
    }
};
