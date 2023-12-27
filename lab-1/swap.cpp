#include<iostream>

using namespace std;

class Swap{
    public:   
        int x;
        int y;
        Swap() {         //construtor
            input();
            swap();
        }

        void swap(){
            cout<<"Value of x , y= "<<x<<","<<y<<'\n';
            y = x+y-(x=y);
            cout<<"Value of x , y= "<<x<<","<<y<<'\n';
        }
        void input(){
            cout<<"Enter value of x: ";
            cin>>x;
            cout<<"Enter value of y: ";
            cin>>y;

        }
};

int main(){
    Swap process; // creating object automatically executes the constructor
    return 0;
}
