class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;
        
        if (num.size() < 3)
            return v;
            
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 2; ++i) {
            int j = i + 1;
            int k = num.size() - 1;
            
            int a, b, c;
            a = num[i];
            while (j < k) {
                b = num[j];
                c = num[k];
                
                int sum = a + b + c;
                if (sum == 0) {
                    // found a 3 sum
                    addit(v, a, b, c);
                    
                    // skip all same b
                    while (num[j] == b && j < k)
                        j++;
                    // skip all same c
                    while (num[k] == c && j < k)
                        k--;
                } else if (sum > 0) {
                    // too large
                    k--;
                } else {
                    j++;
                }
            }
            
            // skip all same a
            while (num[i+1] == a && i < num.size() - 2)
                i++;
        }
    }
    
    void addit(vector<vector<int> > &v, int a, int b, int c)
    {
        int tmp[] = {a, b, c};
        v.push_back(vector<int>(tmp, tmp + 3));
    }
};
