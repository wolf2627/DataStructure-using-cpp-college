#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void minHeapify(int arr[], int size, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < size && arr[l] < arr[smallest])
        smallest = l;

    if (r < size && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, size, smallest);
    }
}

void insertKey(int arr[], int &size, int k) {
    if (size == MAX_SIZE) {
        cout << "Heap is full. Cannot insert more elements.\n";
        return;
    }

    int i = size++;
    arr[i] = k;

    while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMin(int arr[], int &size) {
    if (size <= 0) {
        cout << "Heap is empty.\n";
        return;
    }

    int root = arr[0];
    arr[0] = arr[--size];
    minHeapify(arr, size, 0);

    cout << "Minimum value " << root << " is deleted\n";
}

void print(int arr[], int size) {
    if (size <= 0) {
        cout << "Heap is empty.\n";
        return;
    }

    cout << "Elements of the min heap are:";
    for (int i = 0; i < size; i++)
        cout << " " << arr[i];

    cout << "\n";
}

int main() {
    int choice;
    int heap[MAX_SIZE];
    int size = 0;

    while (1) {
        cout << "1.Insert\n2.Delete Minimum\n3.Print\n4.Exit\nEnter Your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            int element;
            cout << "Enter an element: ";
            cin >> element;
            insertKey(heap, size, element);
            break;
        case 2:
            deleteMin(heap, size);
            break;
        case 3:
            print(heap, size);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}
