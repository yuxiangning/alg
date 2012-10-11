struct string_pair {
    string *s1; // sorted string
    string *s2; // un-sorted, original string
};
    
bool string_pair_comp(const struct string_pair &a, const struct string_pair &b)
{
    return (*a.s1 < *b.s1);
}
    

class Solution {
public:

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vs;        
        vector<struct string_pair> spv;
        vector<string> orig_strs = strs;
        vector<string>::iterator iter;
        
        if (strs.size() == 0)
            return vs;
            
        for (int i = 0; i < strs.size(); i++) {            
            struct string_pair sp;
            
            string &s = strs[i];
            sort(s.begin(), s.end());
            sp.s1 = &strs[i];
            sp.s2 = &orig_strs[i];
            
            spv.push_back(sp);
        }   
        
        sort(spv.begin(), spv.end(), string_pair_comp);
    
        int i = spv.size() - 1;
        while (i > 0) {
            int j = i - 1;
            bool found = false;
            
            while (j >= 0 && *spv[i].s1 == *spv[j].s1) {
                found = true;
                vs.push_back(*spv[j].s2);
                j--;                
            }
            if (found)
                vs.push_back(*spv[i].s2);
            i = j;
        }
        
            
        return vs;
    }
};
