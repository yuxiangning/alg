class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string c;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int pre = 0;
        int len = ((a.length() > b.length()) ? a.length() : b.length());
        
        for (int n = 0; n < len; n++) {
            char x = ((n > a.length() - 1) ? '0' : a[n]);
            int y = ((n > b.length() - 1) ? '0' : b[n]);
            
            
            int sum = x + y + pre - '0' - '0';
            if (sum >= 2) {
                sum -= 2;
                pre = 1;
            } else
                pre = 0;
                
            c.append(1, char(sum + '0'));
        }
        if (pre > 0)
            c.append(1, '1');
        reverse(c.begin(), c.end());
        return c;
    }
};
