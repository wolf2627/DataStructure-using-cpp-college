#include<iostream>
#include<cstdlib>

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

using namespace std;

class stack{
    public:
        int data;
        stack *next;
};

stack *top = NULL; //top is assigned to null

class stacksll{
        public:
            void push(int data){ //push is the operation that inserts the element to the stack
                stack *t = new stack();
                if(top==NULL){  //checks whether the stack is empty or not and perform operation for that
                    t->data=data;
                    t->next=NULL;
                    top = t;
                } else {
                    t->data= data;
                    t->next = top;
                    top = t;
                }
            }

            int pop(){ //Pop is the operation that removes the element in the top
                int x;
                stack *y = new stack();
                if(top==NULL){  //checks whether the stack is empty or not
                    cout<<"Stack is empty"<<endl; 
                    return -1;
                } else {
                    y = top;
                    x = y->data;
                    top = top -> next;
                    free(y);
                    return x;
                }
            }
 
            void display() {  //displaying the elements in the stack
                if (top == NULL) { //Checks whether the stack is empty or not
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack" << endl;
                    stack *y = top;
                    cout<< YELLOW << y->data << RESET <<endl; //differentiates the top element by printing in the yellow colour
                    y = y->next;
                    while (y != NULL) {
                        cout << y->data << endl;
                        y = y->next;
                    }
                }
            }

            void peak(){  //to find the element at the top
                if(top==NULL){ //checks whether the stack contains data or not
                    cout<<"stack is empty"<<endl; 
                } else {
                    cout<<"The peak element is "<<top->data<<endl;
                }
            }
};

//main function display operations and calls the corresponding method choosen by the user iteratively
int main() {
    stacksll st;
    int ch, ele;
    char c;
    do {
        cout << "What do you want to do?" << endl;
        cout << "(1).PUSH\n(2).POP\n(3).DISPLAY\n(4).FIND PEAK\n(5).EXIT" << endl;
        cout<<"Enter your choice: ";
        cin >> ch;
        switch(ch) {
            case 1:
                cout<<"Enter the element to push: ";
                cin>>ele;
                st.push(ele);
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
