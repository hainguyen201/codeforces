#include <iostream>
#define MAX 100
using namespace std;
int n, M;
int X[100]; //model the solution
int T;
//X1+X2+..+X(k-1)+X[k]+X[k+1]=M
//T=X1+X2+..+X(k-1)
//kiểm tra giá trị v có thể gán cho xk mà không vi
//phạm điểu kiên bài toán
int check(int v, int k){
    if(k<n) return 1;
    return T+v==M;
}
//in đáp án
void solution(){
    for(int i=1; i<=n; i++) printf("%d", X[i]); printf("\n");
}
void TRY(int k){
    for(int v=1; v<=M-T-n+k; v++){
        if(check(v, k)){
            X[k]=v;
            T=T+X[k];
            if(k==n) solution();
            else TRY(k+1);
            T=T-X[k];//recover when backtracking
        }
    }
}
int main(){
 n=3; M=6;
 T=0;
 TRY(1);
}
