#include<iostream>

using namespace std;

class node{ // class block for the node 
    public:
        int data;
        node *next;
};

node *head = NULL; // initially the head node is assigned to NULL
node *newnode, *temp, *y;

class linkedList{
    int n;
    public: 
        //Creating the linked list 
        void create(){
            cout << "How many nodes you want to create : ";
            cin >> n; // getting number of nodes 
            for (int i =0; i<n; i++){
                node *x = new node(); // creating the object for the class Node
                cout << "Enter the element "<< i+1 << " : ";
                cin >> x->data;
                x->next = NULL;
                if(head==NULL){
                    head=x;
                    newnode=x;
                } else {
                    newnode->next=x;
                    newnode=x;
                }

            }
        }

        //Displaying the linked list

        void display(){
            cout<<"\nLinked List\n";
            newnode=head;
            while(newnode!=NULL){
                cout<<newnode->data<<" -> ";
                newnode=newnode->next;
            }
            cout<<"NULL\n";
        }

        // inserting the element to list (@begining, @any, @end)
        void insertion(){
            int pos, element, any;
            cout<<"Where do you want to insert?\n";
            cout<<"(1) insert at begining\n";
            cout<<"(2) insert at any\n";
            cout<<"(3) insert at end\n";
            cout<<"Enter choice: ";
            cin>>pos;
            node *x = new node();
            switch(pos){
                case 1: //insertion at begining
                    cout<<"Enter the element to be inserted @ begining : ";
                    cin>>x->data;
                    x->next=head;
                    head=x;
                    break;
                case 2: //insertion at any (middle)
                    y = head;
                    cout<<"which position do you want to insert? ";
                    cin>>any;
                    if(any>0 && any<n){
                    cout<<"Enter the element to be inserted @"<< any <<" : ";
                    cin>>x->data;
                    for(int i=0; i<any-2; i++){
                        y = y->next;
                    }
                    x->next = y->next;
                    y->next = x;
                    } else {
                        cout <<"operation not possible..(position cannot be used)\n";
                    }
                    break;
                case 3: //insertion at end
                    y = head; 
                    cout <<"Enter the element to be inserted @END";
                    cin>>x->data;
                    x->next = NULL;
                    while(y->next!=NULL){
                        y = y->next;
                    }  
                    y->next = x;
                    break;
                default:
                    cout<<"Enter the valid option...\n";
             }

        }

        //Deleting the node (in begining, middle (any), end)
        void deletenode(){
            int pos, element, any;
            cout<<"Where do you want to delete?\n";
            cout<<"(1) delete at begining\n";
            cout<<"(2) delete at any\n";
            cout<<"(3) delete at end\n";
            cout<<"Enter choice: ";
            cin>>pos;
            switch(pos){
                case 1: //deletion at begining
                    y=head;
                    head = y->next;
                    free(y);
                    break;
                case 2: //deletion at any (middle)
                    y = head;
                    cout<<"which position do you want to delete? ";
                    cin>>any;
                    if (any == 1) { // Special case: Deleting the first node
                        head = y->next;
                        free(y);
                        return;
                    }
                    for (int i = 0; i < any - 2; i++)
                        y = y->next;
                        temp = y->next;
                        y->next = temp->next;
                        free(temp);
                    break;
                case 3: //deletion at end
                    y = head;
                    while (y->next->next != nullptr) {
                        y = y->next;
                    }
                    temp = y->next;
                    y->next = nullptr;
                    delete temp;
                    break;
                default:
                    cout<<"Enter the valid option...\n";
             }

        }

        //Searching element in the list
        void search(){
            y = head;
            int flag = 0, searchingelement, position=0;
            cout<<"Which element do you want to find? ";
            cin>>searchingelement;
            while(y!=NULL){
                if(y->data==searchingelement){
                    cout<<"Element is the node "<<position<< endl;
                    flag = 1;
                    break;
                } else {
                    y= y->next;
                    position++;
                }
            }
            if(flag == 0){
                cout<<"Element not found in the list\n";
            }
        }

};


int main(){
    linkedList sll;
    sll.create();
    int option = 0;
    char null;
    while(1){
         cout<<"Operations\n";
        cout<<"(1) Inserting an element\n";
        cout<<"(2) Deleting an element\n";
        cout<<"(3) searching an element\n";
        cout<<"(4) Display the List\n";
        cout<<"(5) exit\n";
        cout<<"Enter operation: ";
        cin>>option;
        switch(option){
            case 1:
                sll.insertion();
                cout<<"After insertion\n";
                sll.display();
                break;
            case 2:
                sll.deletenode();
                cout<<"After Deletion\n";
                sll.display();
                break;
            case 3:
                sll.search();
                break;
            case 4:
                sll.display();
                break;
            case 5:
                exit(0);
            default:
                cout<<"oh on..the entered choice is not available(^.^)\n";

        }
        cout<<"Press a char key to continue..";
        cin>>null;
    }
    return 0;
}
