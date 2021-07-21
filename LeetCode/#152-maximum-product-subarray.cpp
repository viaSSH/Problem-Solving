class Solution {
    vector<int> accum;
    bool minusFlag = false;
    int maxV = -99999999;
public:
    
    void calc(int v) {
        if(accum.empty()) {
            accum.push_back(v);
            
        }
        else{
            for(int i=0 ; i<accum.size() ; i++) {
                accum[i] *= v;
                if(maxV < accum[i]){
                    maxV = accum[i];
                }
            }
            
            if(minusFlag) {
                accum.push_back(v);
                minusFlag = false;
            }
            
        }
        if(maxV < v){
            maxV = v;
        }
        
        if(v <= 0) {
            minusFlag = true;
        }
    }
    
    int maxProduct(vector<int>& nums) {
        
        vector<int> zip;
        
        int temp = 1;
        bool flag = false;
        for(int i=0 ; i<nums.size() ; i++) {
            if(nums[i] > 0) {
                temp *= nums[i];
                flag = true;
            }
            else{
                // zip.push_back(temp);
                
                if(flag) {
                    zip.push_back(temp);
                    temp = 1;
                    flag = false;
                }
                zip.push_back(nums[i]);   
            }
            
            
        }
        
        if(flag) {
            zip.push_back(temp);
        }
        
        
        
        for(int i=0 ; i<zip.size() ; i++) {
            
            calc(zip[i]);
            
        }
        
        
        return maxV;
    }
};