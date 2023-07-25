#include<vector>
using namespace std;

class Solution {
public:
  
    int find_pivot(vector<int> v) {
        //v=vector
	int s = 0, e = v.size() - 1;
	int mid=s + (e-s)/ 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
        {
            // right search
            s=mid+1;
        }
        else
        {
            e = mid;
        }
		mid = s + (e-s) / 2;
	}
	return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find_pivot(arr);
    }
};
