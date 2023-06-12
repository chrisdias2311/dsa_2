#include<iostream>
using namespace std;

// Reverse a string 

// void reverse_string(string& str, int i, int j){

//     //check if start is greater than end 
//     if(i>j)
//         return;
        
//     swap(str[i], str[j]);

//     //recursive call 
//     reverse_string(str, i+1, j-1);
    
// }

// int main(){

//     string str = "abcde";

//     cout<<"Before reversal: "<<str<<endl;
//     reverse_string(str, 0, str.length()-1);
//     cout<<"After reversal: "<<str<<endl;

//     return 0;

// }










// Palindrome 
// bool check_palindrome(string& str, int i, int j){
//     if(i>j)
//         return true;
    
//     if(str[i]!=str[j])
//         return false;
//     else
//         check_palindrome(str, i+1, j-1);
    
// }
// int main(){

//     string str = "bnut";

//     if(check_palindrome(str, 0, str.length()-1))
//         cout<<"Is palindrome"<<endl;
//     else
//         cout<<"Not Palindrome"<<endl;

//     return 0;

// }









// a raised to n 
// => if n is event then (a^(n/2) * a^(n/2))
// => if n is odd then a(a^(n/2) * a^(n/2))

// int power(int a, int n){
//     if(n==0)
//         return 1;
//     if(n==1)
//         return a;
        
//     // RECURSIVE CALLS
//     int ans = power(a, n/2);

//     //If n is even 
//     if(n%2==0)
//         return ans*ans;
//     //If n is odd 
//     else
//         return a*(ans*ans);
// }
// int main(){

//     cout<<power(2, 3);

//     return 0;
// }










// Bubble sort 
void bubble_sort(int *arr, int n){

    //base case - already sorted 
    if(n==0 || n==1)
        return;
    
    // Solve for one case....... will push the largest element to the end of the array
    for(int i=0; i<n; i++){
        if(arr[i]>arr[i+1])
            swap(arr[i], arr[i+1]);
    }

    bubble_sort(arr, n-1);
}

int main(){
    int arr[5] = {2, 5, 1, 6, 9};
    
    cout<<"Before swapping"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i];
    }
    cout<<endl;
    bubble_sort(arr, 5);
    cout<<"After swapping"<<endl;
    for(int i=0; i<5; i++){
        cout<<arr[i];
    }

}