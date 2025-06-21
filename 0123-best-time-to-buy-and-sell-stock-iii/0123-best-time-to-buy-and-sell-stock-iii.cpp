class Solution {
public:
    int dp(int index, bool buy, int k, vector<int>& prices, vector<vector<vector<int>>>& memo){
        if(k==0) return 0;
        if(index == prices.size()-1){
            if(!buy){
                return prices[index];
            }
            else return 0;
        }
        if(memo[index][buy][k]!=-1) return memo[index][buy][k];
        if(buy){
            return memo[index][buy][k] = max(dp(index+1, buy, k, prices, memo), dp(index+1, !buy, k, prices, memo)-prices[index]);
        }
        else{
            return memo[index][buy][k] = max(dp(index+1, buy, k, prices, memo), dp(index+1, !buy, k-1, prices, memo)+prices[index]);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        int k = 2;
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2, vector<int>(k+1,-1)));
        return dp(0, buy, k, prices, memo);
    }
};