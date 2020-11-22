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
int parti(int a[],int low,int high)//һ�˿���
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
    if(low<high)//�������ж��Ԫ��
    {
        mid = parti(a,low,high);//�ҳ����ֵ���±�
        if(mid == k-1)//ǡ�÷ָ�λΪ����λ��
        {
            return a[mid];
        }
        else if (mid < k-1)//Ҫ��λ���ڷָ���Ҳ�
        {
            return quickselect(a,mid+1,high,k);
        }
        else//Ҫ��λ���ڷָ�����
        {
            return quickselect(a,low,mid-1,k);
        }
    }
    else//�����ڽ���һ��Ԫ��
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
