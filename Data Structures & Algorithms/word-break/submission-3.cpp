class Solution {
public:
    unordered_set<string> wordset;
    vector<int> memo;
    //int t;

    bool wordBreak(string s, vector<string>& wordDict) {
        wordset.insert(wordDict.begin(),wordDict.end());
        memo.resize(s.size(),-1);
        //t=0;
        // for (string& w : wordDict) {
        //     t = max(t, int(w.length()));
        // }// maxlength of word

        return dfs(s,0);
    }
    bool dfs(string& s, int i){
        if(i==s.size()){
            return true;
        }

        if(memo[i]!=-1){
            return memo[i];
        }

        for(int j=i;j<s.size();j++){

            if(wordset.count(s.substr(i,j-i+1))){
                if(dfs(s,j+1)){
                    memo[i]=1;
                    return 1;
                }
            }
        }
        memo[i]=0;
        return false;
    }
};
