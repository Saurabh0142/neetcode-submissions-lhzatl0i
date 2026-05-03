class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tp) {
        int n=tp.size();

        vector<int> res(n);

        for(int i=0;i<n;i++){

            int count=1;
            int j=i+1;
            while(j<n){
                if(tp[j]>tp[i]){
                    break;
                }
                count++;
                j++;

            }
            count= (j==n)?0:count;
            res[i]=count;
        }
        return res;

    }
};
