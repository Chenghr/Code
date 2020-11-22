#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

double cmax,d,davg;//�������������Ŀ�ĳ��о��룬��λ������ʻ���룬
int n;//����վ����

struct GasStation
{
    double price;
    double distance;
};

bool comp (GasStation x, GasStation y)
{
    if(x.distance == y.distance)
    {
        return x.price < y.price;
    }
    else
    {
        return x.distance < y.distance;
    }
}

int findgas(GasStation gas[],int curpos)
{
    int minpos = curpos+1;
    int maxlength = cmax*davg;

    if(curpos == n-1)//��ǰ�����һվ�����
    {
        if(maxlength < d-gas[curpos].distance)return -1;
        else return 0;
    }
    if(maxlength < gas[curpos+1].distance-gas[curpos].distance) return -1;//�Ҳ�����һ���ɵ���ļ���վ

    int tag = 0;//��־λ���ڿɴﷶΧ���Ƿ����ҵ��ȵ�ǰ����վ�۸�͵�
    for (int i=curpos+1; i<n; i++)
    {
        if(gas[i].distance - gas[curpos].distance > maxlength) break;//�ɴﷶΧ���Ҽ���վ
        if(gas[i].price < gas[curpos].price)//�ҵ��ȵ�ǰ����վ�۸�͵�
        {
            minpos = i;
            tag = 1;
            break;
        }
    }
    if(tag == 0)//�Ҳ����ȵ�ǰ�۸�͵ģ��������ֱ���յ㣬�򷵻�0�����������ǵ����ҳ���Լ۸���͵�
    {
        if (gas[curpos].distance+maxlength >= d) return 0;
        double minprice = gas[curpos+1].price;
        for (int i=curpos+1; i<n; i++)
        {
            if(gas[i].distance - gas[curpos].distance > maxlength) break;//�ɴﷶΧ���Ҽ���վ
            if(gas[i].price < minprice)//�ҵ��ȵ�ǰ����վ�۸�͵�
            {
                minpos = i;
                minprice = gas[i].price;
            }
        }
    }
    return minpos;
}

int main()
{
    while (cin >> cmax >> d >> davg >> n)
    {
        GasStation * gas = new GasStation [n];
        for(int i=0; i<n; i++)
        {
            cin >> gas[i].price >> gas[i].distance;
        }

        double mincost = 0;
        int curpos = 0;
        int curlength = 0;
        int tag = 1;//��־�н�
        double cap = 0;//��ǰ������ʣ�µ���

        sort(gas, gas+n, comp);//����վ���վ�������

        if(gas[0].distance != 0)//��ʼ�ص�û�м���ս
        {
            printf("The maximum travel distance = 0.00\n");
            continue;
        }

        while (curlength  < d && curpos < n)
        {
            int nextpos = findgas(gas,curpos);
            if (nextpos == -1)//�յ㲻�ɴ�
            {
                tag = 0;
                break;
            }
            else if(nextpos == 0)//��ǰ����վֱ���յ�
            {
                break;
            }
            else//�ҵ��¸�����վ����Ϊ�����������ǰ�ͼ۹���ߵ�ǰ�ͼ۱���
            {
                if(gas[curpos].price >= gas[nextpos].price)//��ǰ�ͼ۱ȽϹ�
                {
                    if((gas[nextpos].distance-gas[curpos].distance)/davg < cap)//�����ڵ��͹���
                    {
                        curlength += gas[nextpos].distance-gas[curpos].distance;//�����¸�����վ
                        mincost += 0;
                        cap -= (gas[nextpos].distance-gas[curpos].distance)/davg;//��������������
                        curpos = nextpos;
                    }
                    else//�Ͳ�����
                    {
                        mincost += ((gas[nextpos].distance-gas[curpos].distance)/davg - cap)*gas[curpos].price;//���͵Ļ���
                        curlength += gas[nextpos].distance-gas[curpos].distance;//�����¸�����վ
                        curpos = nextpos;
                        cap = 0;//���¸�����վ�������͸պ�����
                    }
                }
                else//��ǰ�ͼ۱Ƚϱ��ˣ����ͼ���
                {
                    mincost += (cmax-cap) * gas[curpos].price;
                    cap = cmax;
                    curlength += gas[nextpos].distance-gas[curpos].distance;
                    cap -= (gas[nextpos].distance-gas[curpos].distance)/davg;
                    curpos = nextpos;
                }
            }
        }

        if(tag == 0)//Ŀ��ص㲻�ɴ�
        {
            double maxlength = curlength+cmax*davg;
            printf("The maximum travel distance = %.2lf\n",maxlength);
        }
        else
        {
            mincost += (d-curlength)*gas[curpos].price/davg;
            printf("%.2lf\n",mincost);
        }
    }
    return 0;
}
