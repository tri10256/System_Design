#include<bits/stdc++.h>
using namespace std;

class Player{
    public:
	int id;
	string name;

	public:
	Player(int id, string s){
		this->id = id;
        this->name =s;
	}
};


class Dice{
	public:
	int number;

	Dice(){
       number = 0;
	}
	Dice(int n){
		this->number = n;
	}

	int rollback(){
                 ///// //////////////// (this is the range of the values between the lower bound and upper bound)  
        //srand(time(0));
		int val  = rand()%(6*number-1*number) + 1*number;
		return val;
	}
};

class Jumper{

	public:
   int startpoint;
   int endpoint;
   /////for snake, endpoint>startpoint
   //// for ladder startpoint>endpoint
   Jumper(int startpoint,int endpoint){
	   this->startpoint = startpoint;
	   this->endpoint   = endpoint;
   }
};

class Board{
    public:

    Dice dice;
	queue<Player>nextTurn;
	vector<Jumper>snakes;
	vector<Jumper>ladders;
	unordered_map<string,int>pos;
	int boardsize;

	Board(Dice dice,int boardsize,queue<Player>nextTurn,vector<Jumper>snakes,vector<Jumper>ladders,unordered_map<string,int>mp){
		this->dice     = dice;
		this->nextTurn = nextTurn;
		this->snakes   = snakes;
		this->ladders  = ladders;
		this->pos      = mp;
		this->boardsize= boardsize;
	}

	void startGame(){
         
		 while(nextTurn.size()>1){
           
		   Player player = nextTurn.front();
		   cout<<"You are at this pos"<<pos[player.name]<<endl;
		   nextTurn.pop();

		   int diceValue = dice.rollback();
		   int currPos = pos[player.name];
		   int nextCell  = currPos + diceValue;

		   if(nextCell > boardsize){
			   nextTurn.push(player);
		   }else if(nextCell == boardsize){
			   cout<<"You Won the Game"<<" "<<player.name<<endl;
		   }else{
			    int nextPos[1];
				bool b[1];
				b[0] = false;
               
			   nextPos[0] = nextCell;
               for(auto &snake:snakes){
				   if(snake.startpoint == nextCell){
					   nextPos[0] = snake.endpoint;
				   }
			   }

			   if(nextPos[0] != nextCell){
				   cout<<"You are bitten by a snake"<<" "<<player.name<<endl;
			   }
			   for(auto &ladder:ladders){
				   if(ladder.startpoint == nextCell){
					   nextPos[0] = ladder.endpoint;
					   b[0] = true;
				   }
			   }

			   if(nextPos[0]!=nextCell && b[0]){
				   cout<<"You got a ladder"<<" "<<player.name<<endl;
			   }

			   if(nextPos[0] == boardsize){
				   cout<<"You won the game"<<" "<<player.name<<endl;
			   }else{
				   pos[player.name] = nextPos[0];
				   cout<<"You are at the Pos"<<" "<<nextPos[0]<<" "<<player.name<<endl;
				   nextTurn.push(player);
			   } 
		   }
	   }
	}
};





int main(){
     
    Dice ds(1);
    int boardsize = 100;
 //Dice dice,int boardsize,queue<Player>nextTurn,vector<Jumper>snakes,vector<Jumper>ladders,unordered_map<string,int>mp
	Player player1(1,"Tej");
    Player player2(2,"Trivendram_Pal");
    
    queue<Player>q;
    q.push(player1);
    q.push(player2);

    Jumper s1(12,4);
     Jumper s2(99,2);
      Jumper s3(78,12);
       Jumper s4(56,28);
        Jumper s5(30,10);
         Jumper s6(90,1);

     vector<Jumper>snakes;
     snakes.push_back(s1);
     snakes.push_back(s2);
     snakes.push_back(s3);
     snakes.push_back(s4);
     snakes.push_back(s5);
     snakes.push_back(s6);

     Jumper l1(3,34);
     Jumper l2(8,54);
     Jumper l3(15,77);
     Jumper l4(9,13);
     Jumper l5(47,97);
     Jumper l6(66,70);

     vector<Jumper>ladders;
     ladders.push_back(l1);
     ladders.push_back(l2);
     ladders.push_back(l3);
     ladders.push_back(l4);
     ladders.push_back(l5);
     ladders.push_back(l6);

     unordered_map<string,int>mp;
     mp["Trivendram"] = 1;
     mp["Tej"]        =1;

     Board board(ds,boardsize,q,snakes,ladders,mp);
     board.startGame();
  
}
