class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& room) {
        int n=room.size();
        int m=room[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(room[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];

                if(nr<0 ||nr>=n||
                nc<0 || nc>=m){
                    continue;
                }

                if(room[nr][nc]==INT_MAX){
                    room[nr][nc]=room[r][c]+1;
                    
                    
                    q.push({nr,nc});
                               }
            }
        }
    }
};
