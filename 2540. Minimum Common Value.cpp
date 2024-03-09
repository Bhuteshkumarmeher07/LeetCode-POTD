class Solution {
public:
    // Function to find the common element between two sorted arrays
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Initialize pointers for both arrays
        int i = 0, j = 0;
        
        // Iterate through both arrays until one of them reaches the end
        while (i < nums1.size() && j < nums2.size()) {
            // If the elements at the current positions are equal, return the common element
            if (nums1[i] == nums2[j]) return nums1[i];
            // If the element in nums1 is smaller, move to the next element in nums1
            else if (nums1[i] < nums2[j]) i++;
            // If the element in nums2 is smaller, move to the next element in nums2
            else j++;
        }
        
        // Return -1 if no common element is found
        return -1;
    }
};
