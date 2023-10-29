#include<iostream>
#include<cstdlib>

using namespace std;

class Node //class node for doubly linked list
{
    public:
		int data;
		Node *next,*prev;
};

Node *head = NULL,*y,*temp; //creating node variables 
	
class Linked_list //class block for defining the operations
{
    int i,flag=0,n,pos,ch,ele; // variables are defaulty in private 
    public: // setting access mode as public
    void create(){
        cout<<"Number of nodes to be created: ";
        cin>>n; // getting number of nodes
        for(i=0;i<n;i++)
        {
            Node *x = new Node();
            cout<<"Enter element to be inserted: ";
            cin>>x->data; //setting data field
            x->next=NULL; //setting next link field
            x->prev=NULL; //setting prev link field
            if(head==NULL){  //if head is not set
                head=x;
                y=x;
            } else { //if head is set
                y->next=x;
                x->prev=y;
                y=x;
            }
        }
    }
    
    void display() //displaying the list
    {
        cout<<"Doubly Linked List \n";
        y=head;
        cout<<"NULL<-->";
        while(y!=NULL){  // checking is the current node is last node
            cout<<y->data<<"<->"; //printing the data
            y=y->next;
        }
        cout<<"NULL"<<endl;
    }	
 
    void reverse(){  //diplaying the list in reverse order..traversing from reverse(using prev link field)
        cout<<"Doubly Linked List ~ reverse traversing\n";
        y=head;
        while(y->next!=NULL){ //traversing the y to last node
            y=y->next;
        }
        cout<<"NULL<->";
        while(y!=NULL){ //traversing from last node
            cout<<y->data<<"<->";
            y=y->prev;
        }
        cout<<"NULL"<<endl;
    }


    void insert() {  //inserting an element to the list
        int e, ch, any;
        cout<<"Enter the element to be inserted: ";
        cin>>e;
        Node *x = new Node();
        x->data=e;
        x->next=NULL;
        x->prev=NULL;
        cout<<"Where do you want to insert?\n"; //displaying the posibilities
        cout<<"(1) Insert at beginning\n";
        cout<<"(2) Insert at any position\n";
        cout<<"(3) Insert at end\n";
        cout<<"Enter choice: ";
        cin>> ch; //getting the choice from the user
        switch (ch) {
            case 1: //inserting at begining
                x->next=head;
                head->prev=x;
                head=x;
                n++;
                break;
            case 2: //inserting at middle
                cout<<"Which position do you want to insert: "; //getting the position from the user
                cin>>any;
                if(any>0 && any<=n){ //checking for the valid position 
                    y = head;
                    for (int i = 1; i < any - 1; i++) {
                        y = y->next; //changing the posiiton of the y
                    }
                    x->prev=y;
                    x->next=y->next;
                    if (y->next) {
                        y->next->prev = x;
                    }
                    y->next=x;
                    n++;
                } else {
                    cout<<"Can't insert at this position" << endl; //if position is not valid then, else block will be executed
                }
                break;
            case 3: //insertion at end
                y=head;
                while (y->next!=NULL) { //changing the y to the last 2nd node
                    y=y->next;
                }
                y->next=x;
                x->prev=y;
                n++;
                break;
            default:
                cout<<"Enter a valid option..."<<endl; 
        }
    }
	
        
    void search(int item) //getting the searching element as an argument 
    {
        y=head;flag=0,i=0;
        while(y!=NULL){ //traversing through ther list
            if(y->data==item){
                cout<<"Element is found at position "<<i<<": ";  // if searching element is matched with the current node
                flag=1;
                break;
            } else { //if searching element is not matched with current node
                y=y->next;
                i++;
            }
        }
        if(flag==0)  
            cout<<item <<" is not found in the List"<<endl; //if searching element is not found
    }

    void deletenode(){
            int pos, element, any;
            cout<<"Where do you want to delete?\n"; //displaying the options 
            cout<<"(1) delete at begining\n";
            cout<<"(2) delete at any position\n";
            cout<<"(3) delete at end\n";
            cout<<"Enter choice: ";
            cin>>pos;
            switch(pos){
                case 1: //deletion at begining
                    begin:
                    y=head;
                    head = y->next;
                    head->prev = NULL;
                    free(y); //removing the memory of y (first node)
                    n--;
                    cout<<"deletion successful\n";
                    break;
                case 2: //deletion at any 
                    y = head;
                    cout<<"which position do you want to delete? "; //getting the position to be removed
                    cin>>any;
                    if (any == 0)// Special case: Deleting the first node
                        goto begin;
                    if(any==n-1)
                        goto end;
                    if(any>0 && any<n-1){ //cheching for the position's possiblites
                    for (int i=0; i<any-1; i++) //traversing till the position to be deleted
                        y = y->next;
                    temp = y->next; //assigning the deleting the node to the temp variable
                    y->next = temp->next;
                    temp->next->prev = y;
                    free(temp); //removing the memory for the temp variable
                    n--;
                    cout<<"deletion successful\n";
                    } else {
                        cout <<"Your choice of position is not possible\n"; //if choice is not possible
                    }
                    break;
                case 3: //deletion at end
                    end: 
                    y = head;
                    while (y->next->next != NULL) { //traversing till the last 2nd node;
                        y = y->next;
                    } 
                    temp = y->next; //assigning the last node to the temp variable
                    y->next = NULL;
                    free(temp); //removing the memory for the last node
                    n--;
                    cout<<"deletion successful\n";
                    break;
                default:
                    cout<<"Enter the valid option...\n";
             }


        }
};
	 
int main() 
{
    Linked_list ll;
    int ch,ele;
    char choice;
    cout<<"DOUBLY LINKED LIST"<<endl;
    cout<<"Creation of a Linked List"<<endl;
    ll.create(); //calling the create method in linkedList class
    cout<<"After creation,Linked List Looks Like"<<endl;
    ll.display(); //calling the display method in linkedList class
    do
    {
        cout<<endl<<"Operations on Doubly Linked List"<<endl; //displaying the available operations
        cout<<"(1)Inserting an element\n";
        cout<<"(2)Searching an element\n";
        cout<<"(3)Deleting an Element\n";
        cout<<"(4)Displaying the list\n";
        cout<<"(5)Displaying in reverse\n";
        cout<<"(6)Exit\n";
        cout<<"Enter Your Choice: ";
        cin>>ch; 
        switch(ch)
        {
            case 1:
                ll.insert(); //calling the insert method in linkedList class
                cout<<"After Insertion,Linked List Looks Like"<<endl;
                ll.display(); //calling the display method in linkedList class
                break;
            case 2:	
                cout<<"Enter the element to be searched:"<<endl; //getting the element that has to be searched
                cin>>ele;
                ll.search(ele); //calling the search method in linkedList class and passing the searching element as an argument
                break;
            case 3: 
                cout<<"Before Deletion,Linked List"<<endl;
                ll.display(); //calling the display method in linkedList class
                ll.deletenode(); //calling the deletenode method in linkedList class
                break;
            case 4:
                ll.display(); //calling the display method in linkedList class
                break;
            case 5: 
                ll.reverse(); //calling the reverse method in linkedList class
                break;
            case 6:
                exit(0); //Exiting from the program
                break;
            default:
                cout<<"Enter valid option..\n";
        } 
        cout<<endl<<"Enter any character to continue...";
        cin>>choice; //getting a char from user, to continue execution
    } while(true); //infinite loop
    return 0;
}