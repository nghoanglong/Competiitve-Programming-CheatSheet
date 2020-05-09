/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

void bottomUpMAXHeapify(int arr[], int n, int node){
    int compare ,parent = node;
    int left_child = 2 * parent + 1;
    int right_child = (2 * parent) + 2;
    if (left_child < n && right_child < n){
        if (arr[left_child] <= arr[right_child]){
            compare = left_child;
        }
        else{
            compare = right_child;
        }

        if(arr[parent] > arr[compare]){
            parent = compare;
        }
    }
    else{
        if (right_child < n && arr[right_child] < arr[parent]){
            parent = right_child;
        }
        else if (left_child < n && arr[left_child] < arr[parent]){
            parent = left_child;
        }
    }
    if (parent != node){
        swap(arr[parent], arr[node]);
        bottomUpMAXHeapify(arr, n, parent);
    }
}

int main(){
    int num_element;
    cin >> num_element;
    int *arr = new int[num_element];
    for(int i = 0;i < num_element;i++){
        cin >> arr[i];
    }
    for (int i = num_element / 2 - 1; i >= 0; i--){
        bottomUpMAXHeapify(arr, num_element, i);
    }
    for (int i = num_element - 1; i > 0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        bottomUpMAXHeapify(arr, i, 0);
    }
    for(int i = 0;i < num_element;i++){
        cout << arr[i] << " ";
    }

}

