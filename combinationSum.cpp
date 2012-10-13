class Solution {
public:
    int sumv(vector<int> &v) {
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
            sum += v[i];
        return sum;
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<int> path;
        vector<int> stack;
        
        if (candidates.empty())
            return ret;
            
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        stack.push_back(-1);
        while (!stack.empty()) {
            int top = stack.back();
            stack.pop_back();
            
            if (top == -2) {
                // level delimiter
                if (!path.empty())
                    path.pop_back();
                continue;
            }
            if (top != -1) {
                // root
                path.push_back(candidates[top]);
            }
    
            sum = sumv(path);
            if (sum < target) {
                int k = top;
                if (k == -1)
                    k = 0;
                // push a level delimiter
                stack.push_back(-2);
                for (int i = candidates.size() - 1; i >= k; i--) {
                    stack.push_back(i);
                }
            } else {
                if (sum == target) {
                    ret.push_back(path);
                }
                if (!path.empty())
                    path.pop_back();
            }
        }
        return ret;
    }
};
