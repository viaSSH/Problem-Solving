class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;
        
        while(left < right) {
            int leftHeight = height[left];
            int rightHeight = height[right];
            
            maxWater = max(maxWater, (right-left)*min(leftHeight, rightHeight)  );
            
            if(leftHeight < rightHeight) {
                left++;
            }
            else{
                right--;
            }
        }
        
        return maxWater;
        
    }
};