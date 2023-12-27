#include <iostream> 

using namespace std; 

const int maxSize = 100; // Maximum size of the list 

class List { 
    private: 
        int arr[maxSize];
        int size; 
    public: 
        List() { //this is an Constructor, It defaulty called and the size is initiallized to 0
           size = 0; 
        } 

        void create(){ // Creating a list
            cout << "Enter the number of elements to be created: ";
            cin>>size;
            for(int i=0; i<size; i++){
                cout<<"Enter element "<<i+1<<" : ";
                cin>>arr[i];
            }
        }

        bool isEmpty() { //Checking the list whether it is empty or not
            return size == 0; 
        } 

        bool isFull() { //Checking the list is full or not and returns the max size, and also changes the mazSize value
            return size == maxSize; 
        } 

        int getSize(){ //returning size
            return size; 
        } 

        void insert(int element, int position) { //inserting the element to the array list
            if (isFull()) { 
                cout << "It seems to be there is no space left in list.\n";  
                return; 
            } 
            if (position < 0 || position > size) { 
                cout << "Invalid position.\n"; 
                return; 
            } else { 
                // Shift elements to the right to make space for the new element
                for (int i = size - 1; i >= position; i--) { 
                    arr[i + 1] = arr[i]; 
                } 
                // Insert the new element 
                arr[position] = element; 
                size++; 
                cout << "Element inserted successfully.\n"; 
            } 
        } 

        void remove(int position) { //removing the element in the list array
            if (isEmpty()) { 
                cout << "There is no element in the array...hope you understand\n";  
                return; 
            } 
            if (position > size || size<=0) { 
                cout << "Invalid position." << endl; 
                return; 
            } else { 
                // Shift elements to the left to remove the element at the specified position  
                for (int i = position; i < size - 1; i++) { 
                arr[i] = arr[i + 1]; 
                } 
                size--; 
                cout << "Element removed successfully." << endl; 
            } 
        } 

        int search(int element) {
            if (isEmpty()) {
                cout << "Oops, List is empty.\n";
                return -1; // Assuming -1 is not a valid element in the list  
            }

            for (int i = 0; i < size; i++) {
                if (arr[i] == element) {
                    return i+1; // Element found, return the index
                }
            }
            // Element not found, return -1
            return -1;
        }

        int psearch(int element) { // Getting the predecessor's position
            int pos = -1;
            if (isEmpty()) {
                cout << "Oops, List is empty.\n";
                return pos;
            }
            for (int i = 1; i < size; i++) { // Start from the second element
                if (arr[i] == element) {
                    pos = i - 1; // Store the position of the predecessor
                    break;
                }
            }
            return pos;
        }

        int ssearch(int element) {
            int pos = -1;
            if (isEmpty()) {
                cout << "Oops, List is empty.\n";
                return pos;
            }
            for (int i = 0; i < size - 1; i++) { // Iterate until the second-to-last element
                if (arr[i] == element) {
                    pos = i + 1; // Store the position of the successor
                    break;
                }
            }
            return pos;
        }

        int get(int position) { //getting the position
            if (isEmpty()) { 
               cout << "Oops, List is empty.\n"; 
                return -1; // Assuming -1 is not a valid element in the list  
            } 
            if (position < 0 || position >= size) { 
                cout << "There is no such position in the array." << endl; 
                return -1; 
            }
            return arr[position]; 
        } 


        void display() {  //displaying the list
            if (isEmpty()) { 
                cout << "Oops, List is empty." << endl; 
                return; 
            } 
            for (int i = 0; i < size; i++) { 
                cout << arr[i] << " "; 
            } 
            cout << endl; 
         } 

}; 




int main() { 
    List lt; 
    int choice; char get;
    lt.create();
    do { 
        cout << "List Operations:" << endl; 
        cout << "(1) Insert an element" << endl; 
        cout << "(2) Delete an element" << endl; 
        cout << "(3) Get an element from the position" << endl; 
        cout << "(4) Get size of the list" << endl; 
        cout << "(5) Display the list" << endl; 
        cout << "(6) Searching an element" <<endl;
        cout << "(7) Finding predecessor's position of an element" <<endl;
        cout << "(8) Finding successors's position of an element" <<endl;
        cout << "(0) Exit" << endl; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        if (choice == 0) { 
            break; 
        } 
        int element, position; 
        switch (choice) { 
            case 1: 
                cout << "Enter the element to insert: "; 
                cin >> element; 
                cout << "Enter the index to insert at: "; 
                cin >> position; 
                lt.insert(element, position); 
                break; 
            case 2: 
                cout << "Enter the index to remove: ";  
                cin >> position; 
                lt.remove(position); 
                break; 
            case 3: 
                cout << "Enter the position to get element from: "; 
                cin >> position; 
                element = lt.get(position+1); 
                if (element != -1) { 
                cout << "Element at position " << position << ": " << element << endl;  } 
                break; 
            case 4: 
                cout << "Size of the list: " << lt.getSize() << endl;  
                break; 
            case 5: 
                cout << "List elements: "; 
                lt.display(); 
                break; 
            case 6: 
                cout << "Enter the element to Search : "; 
                cin >> element; 
                position = lt.search(element); 
                if (position != -1) 
                    cout << "Element found at position " << position << endl; 
                else 
                    cout << "Oops searching element not found" << endl;
                break; 
            case 7: 
                cout << "Enter the element to find the predecessor's position : "; 
                cin >> element; 
                position = lt.psearch(element); 
                if (position != -1) 
                    cout << "predecessor's position " << position << endl; 
                else 
                    cout << "Oops no predecessor available.." << endl;
                break; 
            case 8: 
                cout << "Enter the element to find the Successor's position : "; 
                cin >> element; 
                position = lt.ssearch(element); 
                if (position != -1) 
                    cout << "successor's position " << position << endl; 
                else 
                    cout << "Oops no successor available.." << endl;
                break; 
            default: 
                cout << "Invalid choice." << endl; 
        } 
        cout << "Enter a character to continue...";
        cin >> get;
        cout << endl; 
    } while (true);
    return 0; 
}