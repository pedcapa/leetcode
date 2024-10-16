class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0 || k==1){
            return 0;
        }
        int i=0, j=0;
        int n=nums.size();
        int product=nums[0], ans=0;
        nums.push_back(1);
        while(j<n){
            if(product<k){
                product*=nums[++j];
            }
            else{
                ans+=j-i;
                product/=nums[i++];
            }
        }
        ans+=(j-i)*(j-i+1)/2;
        return ans;
    }
};
