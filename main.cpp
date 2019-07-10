#include <iostream>
#include <cmath>
using namespace std;

// Search and an ordered array.

int linearSearch(int arr[], int n, int x){
    if (arr[-1] > x){cout << "not in array";return 0;}
    else{
        int i;
        int flag = 0;
        for(i = 0; i < n; i++){
            if (arr[i] == x){
                cout << "linear search found x at array index: " << i << endl;
                flag = 1;
            }
        }
        if (flag == 1){
            return 0;
        }
        else{
            cout << "not in array" << endl;
        }
        return 0;
    }

}

int binarySearch(int arr[], int l, int r, int x){
    if (arr[-1] > x){cout << "not in array";return 0;}
    else{
        int mid = l + (r-l)/2;
        if (arr[mid] == x){
            cout << "x is in the middle" << endl;
            return mid;
        }
        else if (x > arr[mid]){
            cout << "x is in the upper half" << endl;
            binarySearch(arr, mid+1, r, x);
            return x;
        }
        else if (x < arr[mid]){
            cout << "x is in the lower half" << endl;
            binarySearch(arr, l, mid-1, x);
            return x;
        }
        else{
            cout << "not in array" << endl;
            return -1;
        }
    }

}

int jumpSearch(int arr[], int n, int x){
    if (arr[-1] > x){cout << "not in array";return 0;}
    else{
        int flag = 0;
        int j;
        int m = sqrt(n);
        for (int i = 0; i < n; i += m){
            if (arr[i] == x){
                cout << "x is found at index: " << i << endl;
                return 0;
            }
            else if (arr[i] > x){
                for (j = (i-m); j < n; j++){
                    if (arr[j]== x){
                        cout << "jump search found x at array index: " << j << endl;
                        return 0;
                    }
                }
            }
        }
        cout<<"not in array"<<endl;
        return 0;
    }

}



int main() {

//index ->       0  1  2  3  4  5   6   7   8   9  10   11   12   13   14   15    16    17    18    19     20     21     22     23     24
    int arr[] = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 144;

    linearSearch(arr, n, x);
    cout << endl;

    cout << "binary search is working: " << endl;
    binarySearch(arr, 0, n-1, x);
    cout << endl;


    jumpSearch(arr, n, x);
    cout << endl;






    return 0;
}