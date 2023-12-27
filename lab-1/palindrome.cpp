#include <iostream>

using namespace std;

class Palindrome{
    public:
        int len;
        string a;
        string str, strcp;
        Palindrome(){
            reverse();
            strcp=str;
            int len = strcp.length();
            for (int i = 0; i < len / 2; i++)
                swap(strcp[i], strcp[len - i - 1]);
            cout << "The reversed string : "<< strcp <<endl;
            if(str==strcp){
                cout << str << " is a palindrome." << endl;
            } else{
                cout << str << " is not a palindrome." << endl;
            }
        }
        void reverse(){
            cout << "Enter the number/String to check palindrome or not: ";
            cin>>str;
        }
};

int main()
{
	Palindrome versus;
	return 0;
}
