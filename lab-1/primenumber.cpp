#include<iostream>

using namespace std;

class Prime{
    public:
        int n;
        bool isPrime = true;
        Prime(){
            cout<<"Enter N: ";
            cin>>n;
            cout<< "The prime between 0 to "<< n << endl;
            for(int j = 1; j <=n; j++){
                isPrime = true;
                if(j<=1){
                    isPrime = false;
                } else {
                    for(int i =2; i < j/2; i++){
                        if(j%i==0){
                            isPrime = false;
                            break;
                        }
                }
                }
                if(isPrime){
                    cout<<j<<" ";
                }
            }
            cout<<"\n" ;
        }
};

int main(){
    Prime process;
    return 0;
}