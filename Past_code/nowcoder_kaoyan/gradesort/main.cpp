#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 10000;

struct Student
{
    string name;
    int grade;
    int order;
};

bool comp_0(Student x, Student y)//½µĞòÅÅÁĞ
{
    if(x.grade == y.grade)
    {
        return x.order < y.order;
    }
    else return x.grade > y.grade;
}

bool comp_1(Student x, Student y)//ÉıĞòÅÅÁĞ
{
    if(x.grade == y.grade)
    {
        return x.order < y.order;
    }
    else return x.grade < y.grade;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int tag;
        cin >> tag;

        Student s[MAXN];
        for(int i=0; i<n; i++)
        {
            cin >> s[i].name >> s[i].grade;
            s[i].order = i;
        }

        if(tag == 0) sort(s,s+n,comp_0);
        else sort(s,s+n,comp_1);

        for(int i=0; i<n; i++)
        {
            cout << s[i].name << " " << s[i].grade << endl;
        }

    }
    return 0;
}
