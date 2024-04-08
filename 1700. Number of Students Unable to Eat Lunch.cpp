class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size(),flg=0,i=0,j=0;
        while(i<n)
        {
            //cout<<students[j]<<" "<<sandwiches[i]<<endl;
            if(students[j]==sandwiches[i]){j++;i++;flg=0;}
            else{
                students.push_back(students[j]);
                j++;
                flg++;
            }
            if(flg>=n){break;}
        }
        return n-i;
    }
};
