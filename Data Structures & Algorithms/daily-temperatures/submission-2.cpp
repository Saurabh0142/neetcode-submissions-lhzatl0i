class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tp) {
        // int n=tp.size();

        // vector<int> res(n);

        // for(int i=0;i<n;i++){

        //     int count=1;
        //     int j=i+1;
        //     while(j<n){
        //         if(tp[j]>tp[i]){
        //             break;
        //         }
        //         count++;
        //         j++;

        //     }
        //     count= (j==n)?0:count;
        //     res[i]=count;
        // }
        // return res;

        vector<int> res(tp.size(),0);
        stack<pair<int,int>>stack;

        for(int i=0;i<tp.size();i++){
            int t=tp[i];
            while(!stack.empty() && t>stack.top().first){
                auto pair=stack.top();
                stack.pop();
                res[pair.second]= i - pair.second;
            }
            stack.push({t,i});
        }
        
        return res;

    }
};
