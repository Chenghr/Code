#include <iostream>
#include <cstring>//����memset�����������ʼ��
#include <string>

using namespace std;

const int MAXN = 10000;

struct BigInteger
{
    int digit[MAXN];//����λ��������洢��
    int length;//���泤��

    BigInteger();//��ʼ������
    BigInteger(int x);//int����ת��
    BigInteger(string s);//stringת��

    BigInteger operator= (const BigInteger& b);//���ظ�ֵ��

    bool operator<= (const BigInteger& b);//���رȽϷ���
    bool operator== (const BigInteger& b);

    BigInteger operator+ (const BigInteger& b);//���������
    BigInteger operator- (const BigInteger& b);
    BigInteger operator* (const BigInteger& b);
    BigInteger operator/ (const BigInteger& b);
    BigInteger operator% (const BigInteger& b);
};

BigInteger :: BigInteger()
{
    memset(digit,0,sizeof(digit));//λ����ʼ��Ϊ0
    length = 0;//������0
}

BigInteger :: BigInteger(int x)
{
    memset(digit,0,sizeof(digit));//λ����ʼ��Ϊ0
    length = 0;//������0

    if(x == 0)
    {
        digit[length ++] = x;
    }
    while(x != 0)//����洢
    {
        digit[length ++] = x%10;
        x /= 10;
    }
}

BigInteger :: BigInteger(string s)
{
    memset(digit,0,sizeof(digit));//��ʼ��,������ʹ�ַ���Ϊ�մ�Ҳ�����������
    length = s.size();

    for(int i=0; i<length; i++)
    {
        digit[i] = s[length-1-i]-'0';//����洢
    }
}

BigInteger BigInteger ::operator= (const BigInteger& b)
{
    memset(digit,0,sizeof(digit));//λ����ʼ��Ϊ0
    length = b.length;

    for(int i=0; i<length; i++)
    {
        digit[i] = b.digit[i];
    }

    return *this;//�������ֵ����Ҫ
}

bool BigInteger ::operator<=(const BigInteger& b)
{
    if(length < b.length)
    {
        return true;
    }
    else if(length > b.length)
    {
        return false;
    }
    else//λ����ͬʱҪ�����ж�
    {
        for(int i=length-1; i>=0; i--)
        {
            if(digit[i] == b.digit[i])
            {
                continue;
            }
            else
            {
                return digit[i] < b.digit[i];//ʹ��������
            }
        }
        return true;//��ȫ��ȵ����
    }
    return true;
}

bool BigInteger ::operator==(const BigInteger& b)
{
    if(length != b.length)
    {
        return false;
    }
    else
    {
         for(int i=length-1; i>=0; i--)
        {
            if(digit[i] != b.digit[i])
            {
                return false;
            }
        }
    }
    return true;
}

BigInteger BigInteger ::operator+(const BigInteger& b)//����洢�ģ�digit[0]Ϊ���λ
{
    BigInteger answer;

    int carry = 0;//��λ
    for(int i=0; i<length || i<b.length; i++)//����digit��ֵ����ȫΪ0�����Կ���һֱ�ӵ����ȵ����ֵ������Ӱ����
    {
        int current = carry+digit[i]+b.digit[i];//���㵱ǰλ
        answer.digit[answer.length ++] = current%10;//��ǰλ��ֵ
        carry = current/10;//������λ
    }

    if(carry != 0)//���λҲ������λ
    {
        answer.digit[answer.length ++] = carry;
    }

    return answer;
}

BigInteger BigInteger ::operator-(const BigInteger& b)
{
    BigInteger answer;

    int carry = 0;//����ġ���λ��������ǰλ������������һλ��1����carry=-1����
    for(int i=0; i<length; i++)//����ȷ��Ϊ������С��
    {
        int current = digit[i]-b.digit[i]-carry;//���㵱ǰλ

        if(current < 0)//����������һλ��1
        {
            current += 10;
            carry = 1;
        }
        else//���������λΪ0
        {
            carry = 0;
        }

        answer.digit[answer.length ++] = current;//�洢��ǰλ���
    }

    while(answer.digit[answer.length-1] == 0 && answer.length > 1)//����ǰ��0
    {
        answer.length --;
    }

    return answer;
}

BigInteger BigInteger ::operator*(const BigInteger& b)
{
    BigInteger answer;
    answer.length = length+b.length;//���λ��

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<b.length; j++)
        {
            answer.digit[i+j] += digit[i]*b.digit[j];//�ȼ���˻�������λ
        }
    }

    for(int i=0; i<answer.length; i++)//ͳһ�����λ����
    {
        answer.digit[i+1] += answer.digit[i]/10;
        answer.digit[i] %= 10;
    }

    while(answer.digit[answer.length-1] == 0 && answer.length > 1)//����ǰ��0
    {
        answer.length --;
    }

    return answer;
}

BigInteger BigInteger ::operator/(const BigInteger& b)
{
    BigInteger answer;
    answer.length = length;//�̵����λ��
    BigInteger remainder = BigInteger(0);//�ݴ�ļ�����������Ϊ��������ʼ��Ϊ0
    BigInteger temp = b;//�ǵ�Ҫ����'='��

    for(int i = length-1; i >= 0; i--)//�����Ǵ����λ��ʼ�������ģ�ѭ����ɺ���Ҫ�����򷵻�remainder����Ҫ���򷵻�answer
    {
        if(! (remainder.digit[0] == 0 && remainder.length == 1))//��������Ϊ0ʱ����������������ֵʱ
        {
            for(int j = remainder.length-1; j>=0; j--)//����������һλ
            {
                remainder.digit[j+1] = remainder.digit[j];
            }
            remainder.length ++;//���ȼ�1
        }

        remainder.digit[0] = digit[i];//���������λ���ϱ������ĵ�ǰλ

        while(temp <= remainder)//��ǰ�����������ȱ�����С��ʱ��������������'<='��
        {
            remainder = remainder-temp;//����'-'��
            answer.digit[i] ++;//��ǰ�̵�λ���ϼ�1
        }
    }

    while(answer.digit[answer.length-1] == 0 && answer.length > 1)//����ǰ��0
    {
        answer.length --;
    }

    return answer;
}

BigInteger BigInteger ::operator%(const BigInteger& b)//�ͳ�����˼·���ƣ�ֻ�����������̣���������
{
    BigInteger remainder = BigInteger(0);//������������ʼ��Ϊ0
    BigInteger temp = b;//�洢������

    for(int i=length-1; i>=0; i--)
    {
        if(! (remainder.digit[0] == 0 && remainder.length == 1))//����������Ϊ0ʱ
        {
            for(int j=remainder.length-1; j>=0; j--)//����һλ
            {
                remainder.digit[j+1] = remainder.digit[j];
            }
            remainder.length ++;
        }

        remainder.digit[0] = digit[i];//���λ����������

        while(temp <= remainder)//��ǰλ���ظ�������
        {
            remainder = remainder-temp;
        }
    }
    return remainder;
}

void output(const BigInteger& x)//����д������������������
{
    for(int i=x.length-1; i>=0; i--)
    {
        cout << x.digit[i];
    }
    cout << endl;
}

int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        BigInteger x = BigInteger(s1);
        BigInteger y = BigInteger(s2);

        BigInteger result = x+y;
        cout << "+ : ";
        output(result);

        result = x-y;
        cout << "- : ";
        output(result);

        result = x*y;
        cout << "* : ";
        output(result);

        result = x/y;
        cout << "/ : ";
        output(result);

        result = x%y;
        cout << "% : ";
        output(result);
    }
    return 0;
}
