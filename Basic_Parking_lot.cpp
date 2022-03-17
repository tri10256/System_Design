#include<bits/stdc++.h>
using namespace std;


/*

Requirement:
1. Place a vehicle at available position
2. Remove a vechicle from the parking lot
3. Ticket ( vechicle number plate, starttime ,endtime)
4. Type of vechicles ( Two wheelr, four wheelr)
5. Charges 1 hour for fourwheeler : Rs 2
                       two wheeler: Rs 1

    Entities:
    customer details: 
    Lot 1 Level
    Vehicle
*/ 
 class Customer{
     public:
     int Vehicle_No      = 0;
     string Vehicle_Type = "";
     int startTime       = 0 ;
     int endTime         = 0;
     bool flag           = false;
     Customer(){

     }
     Customer(int no, string type,int st,int et){
         Vehicle_No    = no;
         Vehicle_Type  = type;
         startTime     = st;
         endTime       = et;
     }
 };

 class Ticket{
     public:
     int TicketNo    = 0;
     int Vehicle_No  = 0;
     string Vehicle_Type = "";
     int startTime   = 0;
     int endTime   = 0;
     int startRow = 0;
     int startCol = 0;

     Ticket(){

     }
     Ticket(int no1, int no2,string type,int st, int et,int sR,int sC){
         TicketNo = no1;
         Vehicle_No = no2;
         Vehicle_Type = type;
         startTime = st;
         endTime = et;
         startRow = sR;
         startCol =sC;
     }
 };

 class ParkingLot{
       public:
       vector<vector<int>>lot;
       unordered_map<int,Ticket>Database;
       int counter = 0;

        void print(){
           for(auto x:lot){
               for(auto y:x){
                   cout<<y<<" ";
               }
               cout<<endl;
           }
       }
       ParkingLot(int size){
           lot.resize(size,vector<int>(size,0));
           print();
       }

       void Ticket_Counter(Customer &customer){
             if(!customer.flag){
             auto check = isSpace();
             cout<<"check"<<check[0]<<" "<<check[1]<<endl;
            if(check.size() == 0){
                    cout<<"No Space is Available"<<endl;
                }
            else if(Database.count(customer.Vehicle_No)) 
                cout<<" A Vechicle with Same No is Already Present"<<endl;
                else if (check.size()>0){
                cout<<"The Space is Available at"<<" "<<" "<<check[0]<<" "<<check[1]<<endl;
                print();
                lot[check[0]][check[1]] = customer.Vehicle_No;
                cout<<endl;
                counter++;
                customer.flag = true;
               
                Ticket ticket(counter,customer.Vehicle_No,customer.Vehicle_Type,customer.startTime,customer.endTime,check[0],check[1]);
                Database[customer.Vehicle_No] = ticket;
                }
             }else{
                 price(customer);
             }
       }
       
       void price(Customer &customer){
             auto &ticket = Database[customer.Vehicle_No];
             if(ticket.Vehicle_Type == "Two_Wheeler"){
                 int val = ticket.endTime - ticket.startTime;
                 val*=1;
                 lot[ticket.startRow][ticket.startCol] = 0;
                 cout<<"Sir Please take Your Vechicle From"<<" "<<ticket.startRow<<" "<<ticket.startCol<<" "<<"and pay amount"<<" "<<val<<endl;
                 return ;
             }else if(ticket.Vehicle_Type == "Four-Wheeler"){
                 int val = ticket.endTime - ticket.startTime;
                 val*=2;
                 cout<<"Sir Please take Your Vechicle"<< customer.Vehicle_No<<" From "<<" "<<ticket.startRow<<" "<<ticket.startCol<<" "<<"and pay amount"<<" "<<val<<endl;
                 lot[ticket.startRow][ticket.startCol] = 0;
                 return ;
             }
       }
       vector<int> isSpace(){
            for(int i = 0;i<lot.size();i++){
                for(int j = 0;j<lot[i].size();j++){
                    if(lot[i][j] == 0){
                        return {i,j};
                    }
                }
            }

           return {};
       }

      
 };


int main(){
    ParkingLot parking(3);

    Customer customer1(123,"Two_Wheeler",2,5);
    Customer customer2(456,"Two_Wheeler",3,4);
    Customer customer3(789,"Two_Wheeler",3,9);
    Customer customer4(987,"Two_Wheeler",8,10);
    Customer customer5(879,"Two_Wheeler",7,10);
    Customer customer6 (789,"Two_Wheeler",8,99);

    vector<Customer>customers;

    customers.push_back(customer1);
    customers.push_back(customer2);
    customers.push_back(customer3);
    customers.push_back(customer4);
    customers.push_back(customer5);
    customers.push_back(customer6);

    for(auto &customer:customers){
        parking.Ticket_Counter(customer);
    }

    cout<<"Return mode"<<endl;

    for(auto &customer:customers){
        parking.Ticket_Counter(customer);
    }
    
    cout<<"Lot after all the Processings"<<endl;
    parking.print();
   
    
}