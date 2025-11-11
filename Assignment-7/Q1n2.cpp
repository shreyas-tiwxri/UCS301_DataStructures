#include<isotream>
using namespace std;
// selection sort
void selectionsort(int arr[], int n){
    for(int i = 0; i< n-1;i++){
        int minidx = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]< arr[minidx]){
                minidx = j;
            }
        }
        swap(arr[j], arr[minidx]);
    }
}

// insertion sort
void insertionsort(int arr[], int n){
    for(int i = 1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// bubble sort

void bubblesort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        bool swapped = false;
        for(int j = 0; j< n; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

// improved selection sort

void improevedselectionsort(int arr[], int n){
    for(int i = 0; i< n/2; i++){
        int minidx = i;
        int maxidx = i;
        for(int j = i+1; j<n-i;j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }

        swap(arr[i], arr[minIndex]);

        if (maxIndex == i)
            maxIndex = minIndex;

        swap(arr[n - i - 1], arr[maxIndex]);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], choice;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nChoose Sorting Technique:\n";
    cout << "1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. Merge Sort\n5. Quick Sort\n6. Improved Selection Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: selectionSort(arr, n); break;
        case 2: insertionSort(arr, n); break;
        case 3: bubbleSort(arr, n); break;
        case 4: mergeSort(arr, 0, n - 1); break;
        case 5: quickSort(arr, 0, n - 1); break;
        case 6: improvedSelectionSort(arr, n); break;
        default: cout << "Invalid choice!"; return 0;
    }

    cout << "\nSorted array: ";
    printArray(arr, n);

    return 0;
}