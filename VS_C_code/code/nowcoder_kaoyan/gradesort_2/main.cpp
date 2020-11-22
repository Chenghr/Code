#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 101;

struct Student
{
    int num;
    int grade;
};

bool comp(Student x, Student y)
{
    if(x.grade == y.grade)
    {
        return x.num < y.num;
    }
    else return x.grade < y.grade;
}

int main()
{
    int n;
    while(cin >> n)
    {
        Student s[MAXN];
        for(int i=0; i<n; i++)
        {
            cin >> s[i].num >> s[i].grade;
        }

        sort(s,s+n,comp);

        for(int i=0; i<n; i++)
        {
            cout << s[i].num << " " << s[i].grade << endl;
        }

    }
    return 0;
}
