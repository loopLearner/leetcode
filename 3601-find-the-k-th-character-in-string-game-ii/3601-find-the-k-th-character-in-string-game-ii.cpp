class Solution {
public:
    int power(long long x){
        int ans = 0;
        while(x!=0 && x!=1){
            x/=2;
            ans++;
        }
        return ans;
    }
    char kthCharacter(long long k, vector<int>& operations) {
        k--;
        int x = power(k);
        int count = 0;
        while(k!=0){
            x = power(k);
            count += operations[x];
            k = k%(long long)pow(2,x);
        }
        count = count%26;
        char ans = (char)((int)'a' + count);
        return ans;
    }
};