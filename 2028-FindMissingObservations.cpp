class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int m = rolls.size(), sum_m = 0, sum_n = 0, total_sum = 0;
        vector<int> ans;
        for(int i=0; i<m; i++)
            sum_m += rolls[i];
        
        total_sum = (m+n)*mean;
        if(total_sum<=sum_m) return {};
        
        sum_n = total_sum - sum_m;
        if(sum_n > (n*6) || sum_n<n) return {};
        
        int rem = sum_n%n, min = sum_n/n;
        for(int i=0; i<n; i++){
            ans.push_back(min);
            if((rem--)>0)
                ans[i]++;
        }
        return ans;
    }
};
