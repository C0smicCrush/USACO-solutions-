#include <bits/stdc++.h>
using namespace std;
#define size 100
int metalPiecesArr[size];
bool existsRecipe[size];
vector<vector<int>> recipeVec;

//works 9/11 cases
//recursively makes one more of each until cant make any more

bool makeOneMore(int wantToMake){
    if(metalPiecesArr[wantToMake - 1] > 0){
        metalPiecesArr[wantToMake - 1] -= 1;
        return 1;
    }

    if(existsRecipe[wantToMake - 1]){
        
        for(int a= 0; a < wantToMake; a++){
            int temp = recipeVec[wantToMake - 1][a];
            for(int b =0; b < temp; b++){
                if(!makeOneMore(a + 1)){
                    return 0;
                }
            }
        }

        return 1;

    }else{
        return 0;
    }


}

int main(){
    int N,K,M, holdNarray;
    cin >> N;
    for(int a =0; a < N; a++){
        cin >> metalPiecesArr[a];
    }
    holdNarray = metalPiecesArr[N-1];
    recipeVec.resize(N);
    for(int a =0; a < N; a++){
        recipeVec[a].resize(N);
    }

    for(int a =0; a < N; a++){
        for(int b =0; b < N; b++){
            recipeVec[a][b] = 0;
        }
    }


    cin >> K;
    int L, reqforL;
    for(int  a=0; a < K; a++){
        cin >> L;
        existsRecipe[L - 1] = 1;
        cin >> M;
        for(int b =0; b < M; b++){
            cin >> reqforL;
            recipeVec[L - 1][reqforL -1] += 1;
        }
    }

    if(existsRecipe[N - 1]){
        int hold = 0; 
        while(makeOneMore(N) > 0){
            hold++;
        }
        cout << hold;
    }else{
        cout << metalPiecesArr[N-1];
    }



    return 0;
}
