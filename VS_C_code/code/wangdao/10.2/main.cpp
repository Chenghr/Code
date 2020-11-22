#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int a[1000] = {0};
    int k;
    while (cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        cin >> k;

        sort(a,a+n);

        if(k == 1) cout << a[0] << endl;
        else
        {
            int i=0,j=0;
            for(i=1; i<n; i++)
            {
                if(a[i] != a[i-1]) j++;
                if(j+1 == k) break;
            }
            cout << a[i] << endl;
        }
    }
    return 0;
}

/*
int parti(int a[],int low,int high)//一趟快排
{
    int pivot = a[low];
    int i=low, j=high;
    while (i < j)
    {
        while(i<j && a[j]>pivot) j--;
        while(i<j && a[i]<pivot) i++;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    int temp = a[i];
    a[i] = a[low];
    a[low] = temp;
    return i;
}

int quickselect(int *a,int low,int high,int k)
{
    int mid = -1;
    if(low<high)//区间内有多个元素
    {
        mid = parti(a,low,high);//找出划分点的下标
        if(mid == k-1)//恰好分割位为所找位置
        {
            return a[mid];
        }
        else if (mid < k-1)//要找位置在分割点右侧
        {
            return quickselect(a,mid+1,high,k);
        }
        else//要找位置在分割点左侧
        {
            return quickselect(a,low,mid-1,k);
        }
    }
    else//区间内仅有一个元素
    {
        return a[low];
    }
}

int main()
{
    int n;
    int a[1000] = {0};
    int k;
    while (cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        cin >> k;

        cout << quickselect(a,0,n-1,k) << endl;
    }
    return 0;
}
*/
