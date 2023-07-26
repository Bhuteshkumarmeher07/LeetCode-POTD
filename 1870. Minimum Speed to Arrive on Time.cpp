class Solution {
public:
    bool isPossible(vector<int>& arr, double hour, int mid)
    {
        double time = 0;

        for(int i=0; i<arr.size()-1;i++)
        {
            time += ceil((double) arr[i]/mid);
        }

        time += ((double)arr.back()/mid);

        if(time <= hour)
        {
            return true;
        }
        return false;
    } 


    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        int e = 1e7;
        int ans = -1;

        while(s <= e)
        {
            int mid = s + (e-s) / 2;

            if(isPossible(dist, hour, mid))
            {
                ans = mid;
                e = mid -1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
