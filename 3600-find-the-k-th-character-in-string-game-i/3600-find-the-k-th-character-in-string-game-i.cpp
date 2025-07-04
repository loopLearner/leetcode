class Solution {
public:
    int power(int x){
        int ans = 0;
        while(x!=0 && x!=1){
            x/=2;
            ans++;
        }
        return ans;
    }
    char kthCharacter(int k) {
        int x = power(k);
        int count = 0;
        while(k!=0){
            x = power(k);
            k = k%(int)pow(2,x);
            count++;
        }
        char ans = (char)((int)'a' + x + count - 1);
        return ans;
    }
};