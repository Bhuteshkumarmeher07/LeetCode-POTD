class Solution {
public:
void cyclicSort(vector<int>& nums){
        int n = nums.size();
        int i = 0;
        while(i<n)
        {
            if((nums[i]-1 < n)&& (i != nums[i]-1) && (nums[i]!=nums[nums[i]-1]))
                swap(nums[i], nums[nums[i]-1]);
            else
                i++;
        }
        for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    } 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
       for(int i=0;i<nums.size();i++){
            if(nums[i]<=0||nums[i]>n)
            nums[i]=n+1;
       }
        cyclicSort(nums);
        for(int i=0;i<nums.size();i++){
            if(i+1!=nums[i]){
                return i+1;
            }
        }
        return n+1;
    }
};
