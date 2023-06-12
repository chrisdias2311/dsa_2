#include<iostream>
using namespace std;


// Factorial 
// int fact(int n){
//     if(n==0)
//         return 1;
//     return n*fact(n-1);
// }


// int main() {
//     int n;
//     cin>>n;
    
//     cout<<fact(n)<<endl;

//     return 0;
// }














// X^ n 

int n_pow(int x, int n){
    if(n==0)
        return 1;
    
    return x*n_pow(x,n-1);
}


int main(){

    n_pow(2,3);
}