class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> stack;
        vector<int> path;
        
        stack.push_back(-1);
        while (!stack.empty()) {
            int top = stack.back();
            stack.pop_back();
            
            if (top == -2) {
                if (!path.empty())
                    path.pop_back();
                continue;
            }
            if (top != -1)
                path.push_back(top+1);
            if (path.size() < k) {
                int t = top;
                
                stack.push_back(-2);
                for (int i = n-1; i > t; i--)
                    stack.push_back(i);
            } else if (path.size() == k) {
                ret.push_back(path);
                path.pop_back();
            }
        }
        return ret;
    }
};
