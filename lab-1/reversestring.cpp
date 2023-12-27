#include <iostream>

using namespace std;

class ReverseString{
    public:
        int len;
        string a;
        string str;
        ReverseString(){
            reverse();
            int len = str.length();
            for (int i = 0; i < len / 2; i++)
                swap(str[i], str[len - i - 1]);
            cout << "The reversed string : "<< str<<endl;
        }
        void reverse(){
            cout << "Enter the string to reverse: ";
            cin>>str;
            
        }
};

int main()
{
	ReverseString versus;
	return 0;
}
