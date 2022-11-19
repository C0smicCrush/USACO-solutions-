#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<string> chineseZod = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    set<string> Cows; 
    map<string, int> cowYear;
    string bess = "Bessie";
    cowYear.insert({bess, 0});

    for(int a =0; a < N; a++){
        string cow1nameStr, trash, cowName2Str, prevornext, cow1Year;
        int c1y, c2y;
        bool prevornext1 = 1;
        cin >>cow1nameStr >> trash >> trash >> prevornext >>cow1Year >> trash >>trash >> cowName2Str;
        string myStr = "previous";
        if(prevornext == myStr){
            prevornext1 = 0;
        }
        //cout << cow1nameStr << cowName2Str << cowYear[cowName2Str] <<  endl;
        for(int b= 0; b < 12; b++){
            if(chineseZod[b] == cow1Year){
                c1y = b;
            }
        }
        c2y = (cowYear[cowName2Str] + 240)%12;
        //cout << c1y << c2y << endl;
        if(c1y == c2y){
            if(prevornext1){
                cowYear.insert({cow1nameStr, cowYear[cowName2Str] + 12});
            }else{
                cowYear.insert({cow1nameStr, cowYear[cowName2Str] - 12});
            }
        }else if(c1y < c2y){
            if(prevornext1){
                cowYear.insert({cow1nameStr, cowYear[cowName2Str] + 12 - c2y + c1y});         
            }else{
                cowYear.insert({cow1nameStr, cowYear[cowName2Str] - c2y + c1y});
            }
        }else{
            if(prevornext1){
                cowYear.insert({cow1nameStr, cowYear[cowName2Str] + c1y - c2y});               
            }else{
                cowYear.insert({cow1nameStr, cowYear[cowName2Str] - 12 + c1y - c2y});
            }
        }
        //cout << cowYear[cow1nameStr] << endl;
    }
    string elsStr = "Elsie";
    cout << abs(cowYear[bess]- cowYear[elsStr]);
    return 0;
}