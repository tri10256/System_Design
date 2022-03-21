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

    /*
    We are thinking that the player which make the move is going to win the game if the player wins the game then his id
    is returned;
    @player -> player, like +1, for first user and +2 for 2nd user, and 0 blank
    Specifications:

    1. Multiplayer Game with spectator functionality
    2. Board size can be changed accroding to requirement
    3. User Friendly Game
    4. Handled All the Edge Cases

    */
     void start(vector<Player>&players){
       
       for(auto player:players){
           nextTurn.push(players[0]);
           nextTurn.push(players[1]);
       }
     
       int row  = -1;
       int col  = -1;

       while(!GameOver){
           
           Player p = nextTurn.front();
           nextTurn.pop();
           cout<<endl;
           print(board);
           cout<<endl;
           
           cout<<p.name<<" : "<<"Please Enter your Postion where you want to make move:"<<endl;
           cin>>row>>col;
           int status = Move(p.id,row,col,count);
           /*
             -1 : Illegal move enter a row col within the range
             -2 : board is already occupied
             -3 : wrong user id is sent
             -4 : Game is Draw;
              0 : move is made no winner is There 
              1 : player with id 1 is won
              2 : player with id 2 is won
           */
          while(status == -1 || status == -2 || status == -3){

           if(status == -1){
              cout<<"Illegal Move Enter a row and col again within the range"<<endl;
              cin>>row>>col;
              status = Move(p.id,row,col,count);
           }

           if(status == -2){
              cout<<"Board is Already Occupied Please select Different cell"<<endl;
              cin>>row>>col;
              status = Move(p.id,row,col,count);
           }

           if(status == -3){
               cout<<"Wrong User Please Just Spectate the Game and Say To make Move to a Legal Player"<<endl;
                int player_id = -1;
                cin>>player_id;
                p.id = player_id;
               status = Move(p.id,row,col,count);
           }
        }
           
           if(status == -4){
               GameOver = true;
               cout<<"Game is Draw"<<endl;
               break;
           }else if(status == 0){
               nextTurn.push(p);
           }else if(status == 1){
               GameOver = true;
               cout<<p.name<<" : "<<"have won the Game"<<endl;
               print(board);
           }else  if(status == 2){
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
    
    int Move(int player,int row,int col,int count){
        if(row < 0 || col < 0 || row>=n || col >=n){
            return -1;
        }

        if(board[row][col] != 0)
        return -2;

        if(player != 1 && player != 2)
        return -3;
        
       
        if(count > n*n)
        return -4;

        board[row][col] = player;
        count++;
       
        bool flag1 = true;
        for(int i = 0;i<n;i++){
            if(board[row][i] != player)
            flag1 = false;
        }
        if(flag1)
        return player;

        bool flag2 = true;

        for(int i = 0;i<n;i++){
            if(board[i][col] != player)
            flag2 = false;
        }
        if(flag2)
        return player;
        
        bool flag3 = true;

        for(int i = 0;i<n;i++){
            if(board[i][i] != player)
            flag3 = false;
        }
        if(flag3)
        return player;

        bool flag4 = true;

        for(int i = 0;i<n;i++){
            if(board[i][n-i-1] != player)
            flag4 = false;
        }
        if(flag4)
        return player;
        cout<<" count "<<count<<endl;
        if(count >=n*n)
        return -4;

        return 0;
    }
};


int main(){
    Player player1(1,"Trivendram");
    Player player2(2,"Computer");
    int n = 0;
    cout<<"Please Enter the Board Size"<<endl;
    cin>>n;
    Board board1(n);
    vector<Player>players;
    players.push_back(player1);
    players.push_back(player2);
    
    board1.start(players);
}
