/*
 * 169/172 passed, while the failed test case passed on my linux box.
 */
class Solution {
public:
    int sumv(vector<int> &v) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
            sum += v[i];
        return sum;
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> >ret;
        vector<int> stack;
        vector<int> path;
        
        sort(num.begin(), num.end());
        
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
                path.push_back(num[top]);
            
            int sum = sumv(path);
            if (sum < target) {
                int k = top;
                
                stack.push_back(-2);
                for (int i = num.size() - 1; i > k; i--) {
                    if (num[i] != num[stack.back()])
                        stack.push_back(i);
                    else
                        stack.back() = i;
                }
            } else {
                if (sum == target)
                    ret.push_back(path);
                if (!path.empty())
                    path.pop_back();
            }
        }
        return ret;
    }
};
