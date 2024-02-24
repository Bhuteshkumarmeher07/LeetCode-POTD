class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
      vector<int> time(n,INT_MAX);
      vector<pair<int,int>> adj[n];
      unordered_map<int,int> vis;
      set<int> ans;

      //Step 1 : create adjacency list
      for(auto it : meetings) {
         adj[it[0]].push_back({it[1],it[2]});
         adj[it[1]].push_back({it[0],it[2]});
      }
      //Step 2: perform neccesary starting conditions
      pq.push({0,0});           ans.insert(0);    
      pq.push({0,firstPerson}); ans.insert(firstPerson);
      time[0] = 0;
      time[firstPerson] = 0;

      while(!pq.empty())
      {
         auto currPerson = pq.top().second;
         pq.pop();

        if(vis.count(currPerson) > 0) //if visited, then skip
          continue;

         vis[currPerson]++;
         for(auto it : adj[currPerson])
         {
             int nxtPerson = it.first;
             int revealTime = it.second;
             //if current person had already knew the secret before the time it can reveal to the next person
             if(time[currPerson] <= revealTime) {
                 ans.insert(nxtPerson); //then reveal it to the nxtPerson
                 time[nxtPerson] = min(time[nxtPerson],revealTime);
                 pq.push({time[nxtPerson],nxtPerson}); //push it in pq
             }
         }
      }
     return vector<int>(ans.begin(),ans.end()); //convert set into vector before returning
    }
};
