class Solution {
public:
    int dfs(int i , int j ,vector<int>& nums , int turn){
        if(i == nums.size() || j == -1) return 0;
        if(i > j) return 0;
        if(turn == 0){
            return max(nums[i] + dfs(i + 1 , j , nums , 1), 
                       nums[j] + dfs(i , j - 1 , nums , 1));
        }
        else{
            return min(-nums[i] + dfs(i + 1 , j , nums , 0),
                       -nums[j] + dfs(i , j - 1 , nums , 0));
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int val = dfs(0 , n - 1 , nums , 0);
        return val >= 0;
    }
};
// Intuition
// The intuition behind the question was pretty simple like , we have to two choices at a point whether we take from start or from end and based on that we keep repeating the steps and playing optimally for both the peoples

// Approach
// Made 3 base cases :
// When we take all from start
// When we take all from end
// When we take from both sides
// (We can create only one base case too (i > j) , but for showing i made all possiblities).
// Then when we choose for player one we add that to our total sum.
// When we choose for player two we subtract it from our total sum as it takes score away from player one.
// We keep on doing this until we hit our base case and then if we manage to find one set where the sum of the player ones point is greater than or equal zero we simply return true;
// Complexity
// Time complexity: O(N * N)

// Space complexity: O(N * N * 2)
