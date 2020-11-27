#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_ok(char ip[],int low,int high)//��low��high-1���ַ�ת��Ϊ����
{
    int num = 0;
    int i = low;
    for(i=low; i<high; i++)//ת��
    {
        num = num*10;
        num += ip[i]-'0';
    }
    if(0 <= num && num <= 255) return 1;//�Ϸ�����1
    return 0; //���Ϸ�����0
}

int main()
{
    char ip[20];//���ֻ��16���ַ�
    int n;
    int i,j,k;
    int length;
    int tag;

    scanf("%d",&n);
    for(i=0; i<n; i++)//n������
    {
        scanf("%s",ip);//�����ַ��������ip��������ַ�������׵�ַ����˲��ü�ȡ��ַ��&
        length = strlen(ip);//ȷ���ַ������ȣ�
        ip[length] = '.';//���ַ���ĩβ����'.'�����ں�������

        tag = 1;
        j = 0;
        for(k=0; k<=length;k++)
        {
            if(ip[k] == '.')//j��k֮��Ϊһ��ip��ַ
            {
                if(is_ok(ip,j,k)) //�Ϸ��Ļ�������һ����ַ
                {
                    j = k+1;
                }
                else
                {
                    printf("No\n");
                    tag = 0;//��ǲ��Ϸ�
                    break;//��һ�����Ϸ��Ͳ��������¼����
                }
            }
        }
        if(tag == 1) printf("Yes\n");//��ѭ����tag=1��˵�����ǲ��Ϸ�break������
    }
    return 0;
}
