class Solution {
public:

    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else {
            int a = 1;
            int b = 2;

            n -= 2;
            while (n > 0) {
                n--;
                a = a + b;
                if (n == 0)
                    return a;
                n--;
                b = a + b;
                if (n == 0)
                    return b;
            }
            
            //return climbStairs(n-1) + climbStairs(n-2);
        }
    }
};
