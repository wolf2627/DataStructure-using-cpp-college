#include <iostream>

using namespace std;

class Palindrome{
    public:
        int len, a=0;
        string str, strcp;

        void reverse(string str){
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

        void reverse(int a){
            int cp = a, rev = 0;
            int digit;
            for(int i = 0; cp!=0; i++){
                digit = cp % 10;
                rev = rev * 10 + digit;
                cp /=10;
            }
            if(a==cp){
                cout << cp << " is a palindrome." << endl;
            } else{
                cout << cp << " is not a palindrome." << endl;
            }
            
        }
};

int main()
{
	Palindrome versus;
    versus.str = "malayalam";
    versus.a = 121;
    versus.reverse(versus.str);
	return 0;
}
