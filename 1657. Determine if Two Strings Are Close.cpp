class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return 0;       

/* vector hash && sash will store the frequencies and hash1 
and sash1 will store the occurence by setting 0 to 1;*/

        vector<int> hash(26,0); vector<int> hash1(26,0);
        vector<int> sash(26,0); vector<int> sash1(26,0);

        for(int i=0; i<word1.size(); i++){
            hash[word1[i] - 'a']++;
            hash1[word1[i] - 'a'] = 1;
            sash[word2[i] - 'a']++;
            sash1[word2[i] - 'a'] = 1;
        }
        sort(hash.begin(), hash.end());
        sort(sash.begin(), sash.end());

        return (hash==sash && hash1==sash1);
       
    }
};
