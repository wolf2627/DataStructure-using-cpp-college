#include<iostream>
#include<cstdlib>

using namespace std;

const int maxsize = 100;

class Stack { //class block for stack using array
    private: 
        int a[maxsize];
        int top;
    public:
        int size, x; 
        Stack() { //default constructor
            top = -1; 
            cout << "Enter the size of the stack: "; //getting size from user
            cin >> size;
        }

        bool isFull() { //returns true if stack is full
            return (top == size - 1);
        }

        bool isEmpty() { //returns true if stack is empty
            return top == -1;
        }

        void push() { //method for insertion
            if (isFull()) { //checks whether the stack is full or not
                cout << "Stack is full.So, you can't push element" << endl; 
            } else {
                cout<<"Enter element to push: ";
                cin>>x;
                top++;
                a[top] = x;
                cout<<"Element "<<x<<" pushed successfully"<<endl;
            }
        }

        int pop() {
            if (isEmpty()) {
                cout << "Stack is empty. So you can't pop element" << endl;
                return -1;
            } else {
                x = a[top];
                top--;
                return x;
            }
        }

        void display() {
            if (isEmpty()) {
                cout << "There are no elements to display" << endl;
            } else {
                cout <<"\nStack" << endl;
                for (int i = top; i >= 0; i--)
                    cout<< a[i] <<endl;
                cout << endl;
            }
        }

        void peak() {
            if (isEmpty()) {
                cout << "Stack is empty, hence no peek value" << endl;
            } else {
                cout << "The peek value is : " << a[top] << endl;
            }
        }
};

int main() {
    Stack st;
    int ch, ele;
    char c;
    do {
        cout << "What do you want to do?" << endl;
        cout << "(1).PUSH\n(2).POP\n(3).DISPLAY\n(4).FIND PEAK\n(5).EXIT" << endl;
        cout<<"Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                st.push();
                break;
            case 2:
                ele= st.pop();
                if(ele!=-1)
                    cout << "The popped element from the stack is: " <<ele<< endl;
                break;
            case 3:
                st.display();
                break;
            case 4:
                st.peak();
                break;
            case 5:
                exit(0);
            default:
                cout << "Enter a valid choice" << endl;
        }
        cout << "Press any character to continue...";
        cin >> c;
    } while (true);
}
