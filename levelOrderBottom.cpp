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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        list<TreeNode *> a, b;
        list<TreeNode *> *cl, *nl, *tmp;
        vector<vector<int> > ret;
        vector<int> v;
        
        if (root == NULL)
            return ret;

        // start wit a list
        a.push_back(root);
        cl = &a;
        nl = &b;
        
        while (!cl->empty() || !nl->empty()) {
            while (!cl->empty()) {
                TreeNode *n = cl->front();
                cl->pop_front();
                
                if (n->left != NULL) {
                    nl->push_back(n->left);
                }
                if (n->right != NULL) {
                    nl->push_back(n->right);
                }
                v.push_back(n->val);
            }        
            tmp = cl;
            cl = nl;
            nl = tmp;
            
            ret.push_back(v);
            v.clear();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
