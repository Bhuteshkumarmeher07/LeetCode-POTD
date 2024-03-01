class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        string str{""};
        for(int j=0;j<s.length();j++){
                if(s[j]=='1'){
                    count++;
                }
            }
        if(count==1){
            for(int j=0;j<s.length()-1;j++){
                str+='0';
            }
            str+='1';
            return str;
        }
        else{
            for(int k=0;k<count-1;k++){
                str+='1';
            }
            for(int k=0;k<s.length()-count;k++){
                str+='0';
            }
            str+='1';
            return str;
        }
    }
};
