#include<iostream>

using namespace std;

class factorial{
    public: 
        long int fact=1;
        factorial(int x){
            if(x<0){
                cout<<"Factorial of negative numbers is not defined."<<endl;
            } else {
            for(int i=1; i<=x; i++)
                fact = fact * i;
            cout << "Factorial of " << x <<" is "<< fact << endl;
            }
        }
};

int main(){
    int num;
    cout << "Enter the number to find the factorial: ";
    cin >> num;
    factorial proceed(num);
    return 0;
}