#include<iostream>

using namespace std;

class fiboncci{
    public:
        int num;
        fiboncci(int digit){
            int a=0, b= 1, c;
            for(int i=1;i<=digit;i++){
                cout<< a<< " ";
                c = a+b;
                a = b;
                b = c;
            }
            cout<<" "<< endl;
        }
};

int main(){
    int digits;
    cout<<"Enter number of digits to be printed: ";
    cin>>digits;
    fiboncci process(digits);
    return 0;
}