class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size()-1;
            n = n/2;       
        int s1 = 0, s2 = 0;
        for(int i = 0; i < s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                if(i > n){
                    s2++;
                }
                else{
                    s1++;
                }
            }
       
        }   

        return s1 == s2;
    }
};
