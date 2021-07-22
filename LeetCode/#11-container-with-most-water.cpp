class Solution {
public:
    int maxArea(vector<int>& height) {
        
        
        int left = 0;
        int right = height.size() - 1;
        double water = min(height[left], height[right]) * (right - left);
        double maxWater = water;
        while(left < right) {
            
            int tempLeft = left;
            int tempRight = right;
            while(tempLeft < right) {
                tempLeft++;
                if(height[left] < height[tempLeft]) {
                    break;
                }
            }
            while(left < tempRight) {
                tempRight--;
                if(height[right] < height[tempRight]) {
                    break;
                }
            }
            
            // cout << left << ", " << right << "max : " << maxWater << endl;
            // cout << "temp " << tempLeft << ", " << tempRight << endl;
            
            int leftNextHeight = height[tempLeft];
            int rightNextHeight = height[tempRight];
            
            int supposeLeftCaseWater = min(leftNextHeight, height[right]) * (right - tempLeft);
            int supposeRightCaseWater = min(rightNextHeight, height[left]) * (tempRight - left);
            
            if(supposeLeftCaseWater >= supposeRightCaseWater) {
                left = tempLeft;
            }
            else{
                right = tempRight;
            }
            water = min(height[left], height[right]) * (right - left);
            if(maxWater < water) {
                maxWater = water;
            }
        }
        
        return maxWater;
    }
};