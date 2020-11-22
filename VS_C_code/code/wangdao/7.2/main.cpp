#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

double cmax,d,davg;//油箱最大容量，目的城市距离，单位汽油行驶距离，
int n;//加油站总数

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

    if(curpos == n-1)//当前是最后一站的情况
    {
        if(maxlength < d-gas[curpos].distance)return -1;
        else return 0;
    }
    if(maxlength < gas[curpos+1].distance-gas[curpos].distance) return -1;//找不到下一个可到达的加油站

    int tag = 0;//标志位，在可达范围内是否能找到比当前加油站价格低的
    for (int i=curpos+1; i<n; i++)
    {
        if(gas[i].distance - gas[curpos].distance > maxlength) break;//可达范围内找加油站
        if(gas[i].price < gas[curpos].price)//找到比当前加油站价格低的
        {
            minpos = i;
            tag = 1;
            break;
        }
    }
    if(tag == 0)//找不到比当前价格低的，如果可以直达终点，则返回0，否则在他们当中找出相对价格最低的
    {
        if (gas[curpos].distance+maxlength >= d) return 0;
        double minprice = gas[curpos+1].price;
        for (int i=curpos+1; i<n; i++)
        {
            if(gas[i].distance - gas[curpos].distance > maxlength) break;//可达范围内找加油站
            if(gas[i].price < minprice)//找到比当前加油站价格低的
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
        int tag = 1;//标志有解
        double cap = 0;//当前油箱内剩下的油

        sort(gas, gas+n, comp);//加油站按照距离排序

        if(gas[0].distance != 0)//初始地点没有加油战
        {
            printf("The maximum travel distance = 0.00\n");
            continue;
        }

        while (curlength  < d && curpos < n)
        {
            int nextpos = findgas(gas,curpos);
            if (nextpos == -1)//终点不可达
            {
                tag = 0;
                break;
            }
            else if(nextpos == 0)//当前加油站直达终点
            {
                break;
            }
            else//找到下个加油站，分为两种情况，当前油价贵或者当前油价便宜
            {
                if(gas[curpos].price >= gas[nextpos].price)//当前油价比较贵
                {
                    if((gas[nextpos].distance-gas[curpos].distance)/davg < cap)//油箱内的油够用
                    {
                        curlength += gas[nextpos].distance-gas[curpos].distance;//开到下个加油站
                        mincost += 0;
                        cap -= (gas[nextpos].distance-gas[curpos].distance)/davg;//更新油箱内油量
                        curpos = nextpos;
                    }
                    else//油不够用
                    {
                        mincost += ((gas[nextpos].distance-gas[curpos].distance)/davg - cap)*gas[curpos].price;//加油的花费
                        curlength += gas[nextpos].distance-gas[curpos].distance;//开到下个加油站
                        curpos = nextpos;
                        cap = 0;//到下个加油站油箱内油刚好用完
                    }
                }
                else//当前油价比较便宜，把油加满
                {
                    mincost += (cmax-cap) * gas[curpos].price;
                    cap = cmax;
                    curlength += gas[nextpos].distance-gas[curpos].distance;
                    cap -= (gas[nextpos].distance-gas[curpos].distance)/davg;
                    curpos = nextpos;
                }
            }
        }

        if(tag == 0)//目标地点不可达
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
