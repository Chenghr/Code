#include <iostream>

using namespace std;

void reverseString(char* s, int sSize){
    int i=0;
    char t;
    for(i=0;i<sSize/2;i++)
    {
        t=s[sSize-i-1];
        s[sSize-i-1]=s[i];
        s[i]=t;
    }
}

int main()
{
    char s[100];
    int sSize;
    cin>>s;
    sSize = sizeof(s);
    reverseString(s,sSize);
    cout<<s<<endl;
    return 0;
}
