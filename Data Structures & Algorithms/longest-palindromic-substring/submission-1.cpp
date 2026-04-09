class Solution {
public:
    string longestPalindrome(string s) {
        int start=0,end=0;
        int maxlen=1;
        int n=s.size();

        if (s.length() <= 1) {
            return s;
        }

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
            dp[i][i]=true;
            for(int j=0;j<i;j++){

                if(s[i]==s[j]  && ( i-j<=2 || dp[j+1][i-1] )){
                    dp[j][i]=true;

                    if(i-j+1 >maxlen){
                        maxlen=i-j+1;
                        start=j;
                        end=i;

                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
