#include<bits/stdc++.h>
using namespace std;

class Player{
    public:
    int id;
    string name;
    
    Player(){

    }
    Player(int val,string s){
        id = val;
        name = s;
    }
};

class Board{
    public:
    vector<vector<int>>board;
    int n;
    queue<Player>nextTurn;
    bool GameOver;
    int count = 0;

    Board(){

    }
    Board(int num){
        n = num;
        GameOver = false;
        board.resize(n,vector<int>(n,0));
        print(board);
    }

     void start(vector<Player>&players){
       for(auto player:players){
           nextTurn.push(player);
       }
     
       int row  = -1;
       int col  = -1;
       int val  = -1;

       while(!GameOver){
           
           Player p = nextTurn.front();
           nextTurn.pop();
           cout<<endl;
           print(board);
           cout<<endl;

           cout<<p.name<<" : "<<"Please Enter your Postion where you want to make move and the value"<<endl;
           cin>>row>>col>>val;
           int status = Move(row,col,count,val);
          
          while(status == -1 || status == -2 || status == -3){

           if(status == -1){
              cout<<"Illegal Move Enter a row and col again within the range"<<endl;
              cin>>row>>col;
              status = Move(row,col,count,val);
           }
           if(status == -5){
              cout<<"Illegal Val Enter a different Val again within the range"<<endl;
              int value  = 0;
              cin>>value;
              val = value;
              status = Move(row,col,count,val);
           }

           if(status == -2){
              cout<<"Board is Already Occupied Please select Different cell"<<endl;
              cin>>row>>col;
             status = Move(row,col,count,val);
           }

           if(status == -3){
               cout<<"Wrong User Please Just Spectate the Game and Say To make Move to a Legal Player"<<endl;
                int player_id = -1;
                cin>>player_id;
                p.id = player_id;
              status = Move(row,col,count,val);
           }
        }
           
           if(status == -4){
               GameOver = true;
               cout<<"All The Cells are filled and Valid So sudoku is Solved"<<endl;
               break;
           }else if(status == 0){
               nextTurn.push(p);
           }else if(status == 1){
               GameOver = true;
               cout<<p.name<<" : "<<"have won the Game"<<endl;
               print(board);
           }
        }

     }

     void print(vector<vector<int>>&board){
         for(int i = 0;i<board.size();i++){
             for(int j = 0;j<board[i].size();j++){
                 cout<<board[i][j]<<" ";
             }
             cout<<endl;
         }
     }
    
    int Move(int row,int col,int count,int val){
        if(count >= n*n)
        return -4;
        if(row < 0 || col < 0 || row>=n || col >=n){
            return -1;
        }

        if(board[row][col] != 0)
        return -2;

        board[row][col] = val;
        if(isValid(board)){
            count++;
            return 0;
        }
        return -5;
    }
    bool isValid(vector<vector<int>>& board) {
        int N = 9;
        unordered_set<int>rowSet[N];
        unordered_set<int>colSet[N];
        unordered_set<int>sqSet[N];
        
        for(int r = 0;r<N;++r){
            for(int c = 0;c<N;++c){
                if(board[r][c] != 0){
                    int val = board[r][c];
                    
                    int spos = (r/3)*3 + c/3;
                    
                    if(rowSet[r].count(val) || colSet[c].count(val) || sqSet[spos].count(val)){
                        return false;
                    }
                    
                    rowSet[r].insert(val);
                    colSet[c].insert(val);
                    sqSet[spos].insert(val);
                }
            }
        }
        
        return true;
    }
};


int main(){
    Player player1(1,"Trivendram");
    int n = 0;
    cout<<"Please Enter the Board Size"<<endl;
    cin>>n;
    Board board1(n);
    vector<Player>players;
    players.push_back(player1);
    board1.start(players);
}
