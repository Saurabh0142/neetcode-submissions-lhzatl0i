class Solution {
public:
    int direction[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int island=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
    void dfs(vector<vector<char>>& grid,int r,int c){
        if(r<0 || c<0  || r>=grid.size() || c>= grid[0].size() || grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';

        for(int i=0;i<4;i++){
            dfs(grid, r + direction[i][0], c +direction[i][1]);
        }
    }
};
