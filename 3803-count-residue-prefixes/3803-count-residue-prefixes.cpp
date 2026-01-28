class Solution {
public:
    int residuePrefixes(string s) {
        unordered_set<char> uniq;
        int result = 0;
        for(int i = 0; i < s.length(); ++i){
            uniq.insert(s[i]);
            if (uniq.size() == (i + 1) % 3)
                result++;
            if (uniq.size() > 2)
                break;
        }
        return result;
    }
};