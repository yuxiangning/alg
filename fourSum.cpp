class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > v;        
        int a, b, c, d;
        
        if (num.size() < 4)
            return v;
        sort(num.begin(), num.end());
        
        for (int i = 0; i < num.size() - 3; i++) {
            for (int j = i + 1; j < num.size() - 2; j++) {
                int k = j + 1;
                int l = num.size() - 1;               
                
                a = num[i];
                b = num[j];
                
                while (k < l) {
                    c = num[k];
                    d = num[l];                    
                    int sum = a + b + c + d;
                    
                    if (sum == target) {
                        addit(v, a, b, c, d);
                        
                        while (num[k] == c && k < l)
                            k++;
                        while (num[l] == d && k < l)
                            l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
                
                while (num[j+1] == b && j < num.size() - 2)
                    j++;
            }
            while (num[i+1] == a && i < num.size() - 3)
                i++;
        }
        return v;
    }
    
    void addit(vector<vector<int> > &v, int a, int b, int c, int d)
    {
        int tmp[] = {a, b, c, d};
        
        v.push_back(vector<int>(tmp, tmp + 4));
    }
};
