class Solution {
public:

    int lengthOfLastWord(string s) {
        int i=(int)s.length()-1;

        //if any spaces at the end of string then ignore that
        while(i>=0 && s[i]==' ')
        i--;

        //tranverse the last word
        int length=0;
        while(i>=0 && s[i]!=' ')
        i--,length++;

        return length;

    }
};
