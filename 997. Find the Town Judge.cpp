class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int len=trust.size();
        vector<int> outdegree(n+1) ,indegree(n+1);
        

        for(int i=0;i<len;i++){
            outdegree[trust[i][0]]++;
            indegree[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(outdegree[i]==0 && indegree[i]==n-1){
                return i;
            }
        }
     return -1;   
    }
};
