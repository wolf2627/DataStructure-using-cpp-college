#include<iostream>

using namespace std;

class FahToCel{
    public:
        int fah;
        double cel;
        FahToCel(int x){
            fah = x;
            cel = (x - 32.0) * 5.0 / 9.0;
            cout<<fah<<" fahrenheit = "<<cel <<" celsius"<<'\n';
        }

};

int main(){
    int fah;
    cout<<"Enter fahrenheit: ";
    cin >> fah;
    FahToCel Process(fah);
    return 0;
}