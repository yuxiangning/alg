class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int minabs = 100000;
        int sum;
        int closest;
                
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; i++) {
            int j = i + 1;
            int k = num.size() - 1;
            while (j < k) {
                sum = num[i]+num[j]+num[k];
                if (sum == target)
                    return sum;
                    
                if (sum < target)
                    j++;
                else
                    k--;
                if (abs(target - sum) < minabs) {
                    minabs = abs(target - sum);
                    closest = sum;
                }
            }

        }
        return closest;
    }
};
