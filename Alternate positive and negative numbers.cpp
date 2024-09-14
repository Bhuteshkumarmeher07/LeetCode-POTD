void rearrange(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> pos, neg;
        for(int i=0; i<n; i++){
            if(arr[i] >= 0){
                // +ve
                pos.push_back(arr[i]);
            }
            else{
                // -ve
                neg.push_back(arr[i]);
            }
        }
        // initialize the arr
        int i=0, j=0, k = 0;
        while(i < pos.size() && j < neg.size()){
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        while(i < pos.size()) arr[k++] = pos[i++];
        while(j < neg.size()) arr[k++] = neg[j++];
    }
