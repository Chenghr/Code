#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    int a[100];
    vector<int> graph[100];
    memset(a,INF,sizeof(a));
    for(int i=0; i<100; i++) cout << a[i] << " ";
    memset(graph,0,sizeof(graph));
    return 0;
}
