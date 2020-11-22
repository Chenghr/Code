#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if(n == 0) break;
        priority_queue <int, vector<int>, greater<int> > prior_q;//创建有小到大的优先级队列
        for(int i=0; i<n; i++)
        {
            int num;
            cin >> num;
            prior_q.push(num);
        }

        int cost = 0;
        while (prior_q.size() > 1)
        {
            int a = prior_q.top();//取最小值
            prior_q.pop();
            int b = prior_q.top();//取次小值
            prior_q.pop();
            cost += a+b;
            prior_q.push(a+b);//再入队
        }
        cout << cost << endl;
    }
    return 0;
}
