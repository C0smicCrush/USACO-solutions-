#include <bits/stdc++.h>
using namespace std;
int main(){

    vector<vector<int>> myArr;
    myArr.resize(1001);
    for(int a =0; a < 1001; a++){
        myArr[a].resize(1001);
    }
    for(int a= 0; a < 1001; a++){
        for(int b =0;b  < 1001; b++){
            myArr[a][b] = 0 ;
        }
    }
    bool cowBools[1001][1001];
    int x, y;
    int currComfy = 0;
    int N;
    cin >> N;
    for(int a =0; a < N; a++){
        cin >> x >> y;
        cowBools[x][y] = 1;
        if(cowBools[x][y+1] == 1){
            myArr[x][y] += 1;
            myArr[x][y+1] += 1;
            if(myArr[x][y + 1] == 3){
                currComfy++;
            }else if( myArr[x][y + 1] == 4){
                currComfy--;
            }
        }
        if(cowBools[x][y-1] == 1){
            myArr[x][y] += 1;
            myArr[x][y-1] += 1;
            if(myArr[x][y - 1] == 3){
                currComfy++;
            }else if( myArr[x][y - 1] == 4){
                currComfy--;
            }
        }
        if(cowBools[x-1][y] == 1){
            myArr[x][y] += 1;
            myArr[x - 1][y] += 1;
            if(myArr[x - 1][y] == 3){
                currComfy++;
            }else if( myArr[x - 1][y] == 4){
                currComfy--;
            }
        }
        if(cowBools[x + 1][y] == 1){
            myArr[x][y] += 1;
            myArr[x + 1][y] += 1;
            if(myArr[x + 1][y] == 3){
                currComfy++;
            }else if( myArr[x + 1][y] == 4){
                currComfy--;
            }
        }
        if(myArr[x][y] == 3){
            currComfy++;
        }
        cout << currComfy << endl;
    //     for(int a =0;a < 10; a++){
    //     for(int b =0; b < 10; b++){
    //         cout << myArr[a][b] << " ";
    //     }
    //     cout << endl;
    // }
    }

    return 0;
}