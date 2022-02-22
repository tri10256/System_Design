#include<bits/stdc++.h>
using namespace std;

class Shortner{
    private:
    unordered_map<string,string>database;
    string generate(){
        string key = "";
        srand(time(0));
        for(int i = 0;i<6;i++){ ///this loop runs for the length of short url;
            int r1 = rand()%2;    ///just a way to get three unique options
            if(r1 == 0){
                int r2 = rand()%26;
                key+=(r2+'a');
                
            }else if(r1 == 1){
                int r2 = rand()%26;
                key+=(r2+'A');
            }else {
                int r2 = rand()%9;
                key+=(r2+'0');
            }
        }
        return key;
    }
    
    public:
     // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = generate();
        
        while(database.count(key)){
            key = generate();
        }
        
        database[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { 
        return database[shortUrl];
    }

    string getDomain(string &website){
        if(website.size()==0){
            return "Not a valid website_don't make me fool";
        }
        int i = 0;
        string key = encode(website);
        int found = website.find(".com");
        string domain = (website.substr(i,found+5)+ key);
        return domain;
    }
};

int main(){
    
     string website = "https://www.google.com/search?q=get+a+long+website+url&rlz=1C1UEAD_enIN954IN954&oq=get+a+long+website++url&aqs=chrome..69i57j33i22i29i30l8.7064j0j15&sourceid=chrome&ie=UTF-8";
    //  cin>>website;
    //  cout<<website<<endl;
     
    Shortner machine;
    
    cout<<"Original-Url"<<"  "<<website<<endl;
    string tinyUrl = machine.getDomain(website);
    cout<<"Shorted-Url"<<" "<<tinyUrl<<endl;
    cout<<"Redirected_From_Database"<<"  "<<machine.decode(machine.encode(website))<<endl;
}



**************************************************************OUTPUT****************************************************************************************************************
[Running] cd "c:\Users\Trivendram Pal\OneDrive\Desktop\SystemDesignn\UrlShortner\" && g++ file.cpp -o file && "c:\Users\Trivendram Pal\OneDrive\Desktop\SystemDesignn\UrlShortner\"file
Original-Url  https://www.google.com/search?q=get+a+long+website+url&rlz=1C1UEAD_enIN954IN954&oq=get+a+long+website++url&aqs=chrome..69i57j33i22i29i30l8.7064j0j15&sourceid=chrome&ie=UTF-8
Shorted-Url https://www.google.com/KNwUfb
Redirected_From_Database  https://www.google.com/search?q=get+a+long+website+url&rlz=1C1UEAD_enIN954IN954&oq=get+a+long+website++url&aqs=chrome..69i57j33i22i29i30l8.7064j0j15&sourceid=chrome&ie=UTF-8

