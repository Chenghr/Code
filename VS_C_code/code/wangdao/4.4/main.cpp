//�ܵ���˵����˼·��һ���Ƚ��и��������룬����֮�����ͬһ�ӷ���
//��һ���Ƿ�Ϊ������С�������֣��ֱ���мӷ�

#include <iostream>
#include <string>

using namespace std;

string stradd_1(string s1,string s2)//��������������
{
    string result,sa,sb;

    //����������
    int ia = s1.find(".");
    int ib = s2.find(".");
    sa = (ia > ib) ? s1 : s2;//s1��s2���������ֽϳ��ĸ�ֵ��sa����һ����sb
    sb = (ia > ib) ? s2 : s1;

    int n = (ia > ib) ? (ia - ib) : (ib - ia);//�������ֶ���
    while (n--)
    {
        sb = "0"+sb;
    }
    s1 = sa;
    s2 = sb;

    sa = (s1.size() > s2.size()) ? s1 : s2;//s1��s2��С�����ֽϳ��ĸ�ֵ��sa����һ����sb
    sb = (s1.size() > s2.size()) ? s2 : s1;
    n = (s1.size() > s2.size()) ? (s1.size() - s2.size()) : (s2.size() - s1.size());//С�����ֶ���
    while (n--)
    {
        sb += "0";
    }
    s1 = sa;
    s2 = sb;

    //�����ĸ��������
    int carry = 0;//��λ
    for(int i=s1.size()-1; i>=0; i--)
    {
        if(s1[i] == '.')
        {
            result = "."+result;
            continue;
        }
        char value = s1[i]-'0'+s2[i]-'0'+carry;
        result = char(value%10 + '0')+result;//�洢��ǰλ�Ľ��
        carry = value/10;//�洢��λ
    }
    while (carry != 0)//�����λ�����Ľ�λ���д���
    {
        result = char(carry%10 + '0')+result;
        carry = carry/10;
    }
    return result;
}

void stradd_2(string s1,string s2)
{
    string z1,x1,z2,x2;

    //�Ƚ���������С���ķָ�
    int ia = s1.find(".");
    int ib = s2.find(".");
    z1 = (ia > ib) ? s1.substr(0,ia) : s2.substr(0,ib);//��֤��������z1�,ia����Ϊ'.'���±꣬�������±��ʵ��-1����ǡ��Ϊ�������ֳ���
    z2 = (ia > ib) ? s2.substr(0,ib) : s1.substr(0,ia);
    x1 = (s1.size()-ia > s2.size() -ib) ? s1.substr(ia+1,s1.size()-ia) : s2.substr(ib+1,s2.size()-ib);//��֤С������x1�
    x2 = (s1.size()-ia > s2.size() -ib) ? s2.substr(ib+1,s2.size()-ib) : s1.substr(ia+1,s1.size()-ia);

    //�ֱ���мӷ�
    int carry = 0;//��λ
    for(int i=x2.size()-1; i>=0; i--)//�Ƚ���С�����ּӷ�
    {
        int a = x1[i]-'0'+x2[i]-'0'+carry;
        x1[i] = a%10+'0';
        carry = a/10;
    }

    int l = z1.size()-1;
    for(int i=z2.size()-1; i>=0; i--,l--)
    {
        int a = z1[l]-'0'+z2[i]-'0'+carry;
        z1[l] = a%10+'0';
        carry = a/10;
    }
    while(l >= 0)
    {
        int a = z1[l]-'0'+carry;
        z1[l] = a%10+'0';
        carry = a/10;
        l--;
    }
    while (carry != 0)
    {
        z1 = char (carry%10+'0')+z1;
        carry = carry/10;
    }
    cout << z1 << "." << x1 << endl;
    return ;
}

int main()
{
    string s1,s2;
    while (cin >> s1 >> s2)
    {
        cout << stradd_1(s1,s2) << endl;
        stradd_2(s1,s2);
    }
    return 0;
}
