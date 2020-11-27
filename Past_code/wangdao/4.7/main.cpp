#include <iostream>
#include <string>

using namespace std;

string text,pattern;
int *next;

void getnext(string pattern)
{
    int j=0, i=-1;
    next = int new [pattern.size()+1];
    next[0] = -1;
    int m = pattern.size();

    while (j < m)
    {
        if(j == -1 || pattern[j] == pattern[i])
        {
            i++;
            j++;
            next[j] = i;
        }
        else
        {
            i = next[i];
        }
    }
    return ;
}

void kmp()
{
    getnext(pattern);
    int i,j=-1,sum=0;
    int m = text.size();
}
int main()
{
    while (cin >> text >> pattern)
    {

    }
    return 0;
}
