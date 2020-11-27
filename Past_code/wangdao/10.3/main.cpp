#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        if(n == 0) break;
        priority_queue <int, vector<int>, greater<int> > prior_q;//������С��������ȼ�����
        for(int i=0; i<n; i++)
        {
            int num;
            cin >> num;
            prior_q.push(num);
        }

        int cost = 0;
        while (prior_q.size() > 1)
        {
            int a = prior_q.top();//ȡ��Сֵ
            prior_q.pop();
            int b = prior_q.top();//ȡ��Сֵ
            prior_q.pop();
            cost += a+b;
            prior_q.push(a+b);//�����
        }
        cout << cost << endl;
    }
    return 0;
}
