/* Approach is straight forward and is as follows in some points :

->Used a res variable and it will tell the rank of every key present

->Use 2 Maps : One for storing key,value pairs and another for
storing key rank pairs

-> Whenever the get function is called if key is not present in map simply return -1;
else delete the previous ranked key present in st and update it with a new rank which shows it is recently used.

-> Whenever the put function is called there are 2 possibilities:

if key is already present in map just delete the previous ranked key present in st and update it with a new rank and valye which shows it is recently used.

else if size of map is equal to capacity delete the element which is present at top of set , ie st.begin and insert the element with a new rank and value in set and maps

Happy Coding !

Complexity
Time complexity:O(LogN) 
*/

Space complexity: O(N)
class LRUCache {
public:
    int cnt;
    unordered_map<int,int> mp;
    deque<int> dq;
    set<pair<int,int>> st;
    unordered_map<int,int> val;
    int res=0;
    LRUCache(int capacity) {
        cnt=capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            int v=val[key];
            st.erase({v,key});
            res++;
            st.insert({res,key});
            val[key]=res;
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(!mp.count(key)){
            if(mp.size()==cnt){
                int r=st.begin()->second;
                st.erase(st.begin());
                mp.erase(r);
                val.erase(r);
            }
            res++;
            mp[key]=value;
            val[key]=res;
            st.insert({res,key});
        }
        else{
            int v=val[key];
            st.erase({v,key});
            res++;
            st.insert({res,key});
            mp[key]=value;
            val[key]=res;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
