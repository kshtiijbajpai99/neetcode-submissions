class Solution {
public:
vector<string>ans;
bool backtrack(vector<vector<char>>& board, string word,int r,int c,int index){

    if(r<0 || r>=board.size()||c<0 || c>=board[0].size()){
        return false;
    }
    if(board[r][c]!=word[index])
    return false;
    if(index==word.size()-1)
    return true;

    char temp=board[r][c];
    board[r][c]='#';

    int dr[]={-1,1,0,0};
    int dc[]={0,0,-1,1};

    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];

        if(backtrack(board,word,nr,nc,index+1)){
            return true;
        }
    }
    board[r][c]=temp;

    return false;



}
    bool exist(vector<vector<char>>& board, string word) {
        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                if(backtrack(board,word,r,c,0)){
                    return true;
                }
            }
        }
        return false;
    }
};
