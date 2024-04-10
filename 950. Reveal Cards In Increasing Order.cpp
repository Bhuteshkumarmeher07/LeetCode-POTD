class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int>q;
        int n = deck.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++) q.push(i);
        sort(deck.begin(),deck.end());
        int i=0;
        while(i<n){
            int idx1 = q.front();
            q.pop();
            ans[idx1] = deck[i];
            if(q.size()>1)
            {
                int idx2 = q.front();
                q.pop();
                q.push(idx2);
            }
            i++;
        }
        return ans; 
    }
};
