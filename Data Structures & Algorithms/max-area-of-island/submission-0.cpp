class Solution {
public:
    int direction[4][2]={{1,0},{0,1},{0,-1},{-1,0}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();

        int area=0;

        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    area=max(area,bfs(grid,r,c));
                }
            }
        }
        return area;
    }

    int bfs(vector<vector<int>>& grid,int r,int c){
        queue<pair<int,int>>q;
        grid[r][c]=0;
        q.push({r,c});
        int res=1;

        while(!q.empty()){
            auto node=q.front(); q.pop();
            int row=node.first, col=node.second;
            for(int i=0;i<4;i++){
                int nr=row+direction[i][0];
                int nc=col+direction[i][1];

                if(nr>=0 && nc>=0 && nr< grid.size() && nc<grid[0].size() && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                    res++;
                }
            }
        }
        return res;
    }
};
