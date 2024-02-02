class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s="123456789";
        vector<int> ans;
        for(int k=1;k<10;k++){
            int i=0;
            int j=0;
            while(j<9){
                if(j-i+1<k)j++;
                else if(j-i+1==k){
                    string sub=s.substr(i,k);
                    int num=stoi(sub);

                    if(num>=low && num<=high){
                        ans.push_back(num);
                    }
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};
// Intuition
// The code generates sequential digits of length k from the string "123456789" and checks if the generated number is within the given range [low, high]. It uses two pointers i and j to iterate over the string and create substrings of length k. If the generated number is within the range, it is added to the result vector.

// Approach
// The approach is to use two pointers, i and j, to iterate through the string "123456789" and create substrings of length k. For each substring, convert it to an integer and check if it is within the given range [low, high]. If it is, add it to the result vector. Increment both pointers in each iteration.

// Complexity
// Time complexity: O(1) -> constant time since the string "123456789" has fixed length

// Space complexity: O(1) -> constant space since the result vector is the only additional data structure used
