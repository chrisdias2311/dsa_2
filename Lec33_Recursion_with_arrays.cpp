#include<iostream>
using namespace std;

// Chech if an array is sorted or not using recursion
// bool isSorted(int *arr, int size){

//     //base case
//     if(size==0 || size==1){
//         return true;
//     }
    
//     if( arr[0]>arr[1])
//         return false;
//     else {
//         bool remainingPart = isSorted(arr+1, size-1);
//         return remainingPart;
//     }
// }

// int main() {
//     int arr[5] = {2, 4, 6, 8, 10};
//     int size = 5;

//     cout<<isSorted(arr, size)<<endl;

//     return 0;
// }






// Sum of Array 

// int arrSum(int *arr, int size){
//     if(size==0)
//         return 0;
//     else if(size==1)
//         return arr[0];
//     else{
//         int remainingSum=arrSum(arr+1, size-1);    // skip the first element and take sum for the remaining part 
//         int totalSum = arr[0]+remainingSum;
//         return totalSum;
//     }
// }

// int main() {
//     int arr[5] = {2, 4, 6, 8, 10};
//     int size = 5;

//     cout<<arrSum(arr, size)<<endl;

//     return 0;
// }









// Linear Search
// bool linearSearch(int *arr, int size, int key){
//     if(size==0)
//         return false;
    
//     if(key==arr[0])
//         return true;
    
//     else{
//         bool remainingpart = linearSearch(arr+1, size-1, key);
//         return remainingpart;
//     }
// }

// int main() {
//     int arr[5] = {2, 4, 6, 8, 10};
//     int size = 5;
//     int key=2;

//     if(linearSearch(arr, size, key))
//         cout<<"Present"<<endl;
//     else
//         cout<<"Not Present"<<endl;    

//     return 0;
// }











//Binary Search 
bool binarySearch(int *arr, int s, int e, int key){
    // element not found 
    if(s>e)
        return false;

    // Find the mid elemenmt 
    int mid = (s+e)/2;

    //element found
    if(arr[mid]==key)
        return true;

    // Search Left arr
    if(key<arr[mid])
        return binarySearch(arr, s, mid, key);
    //Search Right arr 
    else
        return binarySearch(arr, mid+1, e, key);


}

int main() {
    int arr[6] = {2, 4, 6, 10, 14, 16};
    int size = 6;
    int key=16;

    if(binarySearch(arr, 0, 5, key))
        cout<<"Present"<<endl;
    else
        cout<<"Not Present"<<endl;    

    return 0;
}