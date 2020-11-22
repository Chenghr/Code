#include <iostream>
#include <cstring>//包含memset函数，方便初始化
#include <string>

using namespace std;

const int MAXN = 10000;

struct BigInteger
{
    int digit[MAXN];//保存位数，逆序存储的
    int length;//保存长度

    BigInteger();//初始化函数
    BigInteger(int x);//int型数转化
    BigInteger(string s);//string转化

    BigInteger operator= (const BigInteger& b);//重载赋值号

    bool operator<= (const BigInteger& b);//重载比较符号
    bool operator== (const BigInteger& b);

    BigInteger operator+ (const BigInteger& b);//重载运算符
    BigInteger operator- (const BigInteger& b);
    BigInteger operator* (const BigInteger& b);
    BigInteger operator/ (const BigInteger& b);
    BigInteger operator% (const BigInteger& b);
};

BigInteger :: BigInteger()
{
    memset(digit,0,sizeof(digit));//位数初始化为0
    length = 0;//长度置0
}

BigInteger :: BigInteger(int x)
{
    memset(digit,0,sizeof(digit));//位数初始化为0
    length = 0;//长度置0

    if(x == 0)
    {
        digit[length ++] = x;
    }
    while(x != 0)//逆序存储
    {
        digit[length ++] = x%10;
        x /= 10;
    }
}

BigInteger :: BigInteger(string s)
{
    memset(digit,0,sizeof(digit));//初始化,这样即使字符串为空串也不会出现问题
    length = s.size();

    for(int i=0; i<length; i++)
    {
        digit[i] = s[length-1-i]-'0';//逆序存储
    }
}

BigInteger BigInteger ::operator= (const BigInteger& b)
{
    memset(digit,0,sizeof(digit));//位数初始化为0
    length = b.length;

    for(int i=0; i<length; i++)
    {
        digit[i] = b.digit[i];
    }

    return *this;//这个返回值很重要
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
    else//位数相同时要单独判断
    {
        for(int i=length-1; i>=0; i--)
        {
            if(digit[i] == b.digit[i])
            {
                continue;
            }
            else
            {
                return digit[i] < b.digit[i];//使代码更简洁
            }
        }
        return true;//完全相等的情况
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

BigInteger BigInteger ::operator+(const BigInteger& b)//逆序存储的，digit[0]为最低位
{
    BigInteger answer;

    int carry = 0;//进位
    for(int i=0; i<length || i<b.length; i++)//由于digit初值赋的全为0，所以可以一直加到长度的最大值，不会影响结果
    {
        int current = carry+digit[i]+b.digit[i];//计算当前位
        answer.digit[answer.length ++] = current%10;//当前位赋值
        carry = current/10;//产生进位
    }

    if(carry != 0)//最高位也产生进位
    {
        answer.digit[answer.length ++] = carry;
    }

    return answer;
}

BigInteger BigInteger ::operator-(const BigInteger& b)
{
    BigInteger answer;

    int carry = 0;//特殊的“进位”，若当前位不够，则向下一位借1，令carry=-1即可
    for(int i=0; i<length; i++)//必须确保为大数减小数
    {
        int current = digit[i]-b.digit[i]-carry;//计算当前位

        if(current < 0)//不够则向下一位借1
        {
            current += 10;
            carry = 1;
        }
        else//够了则令借位为0
        {
            carry = 0;
        }

        answer.digit[answer.length ++] = current;//存储当前位结果
    }

    while(answer.digit[answer.length-1] == 0 && answer.length > 1)//消除前导0
    {
        answer.length --;
    }

    return answer;
}

BigInteger BigInteger ::operator*(const BigInteger& b)
{
    BigInteger answer;
    answer.length = length+b.length;//最大位数

    for(int i=0; i<length; i++)
    {
        for(int j=0; j<b.length; j++)
        {
            answer.digit[i+j] += digit[i]*b.digit[j];//先计算乘积，不进位
        }
    }

    for(int i=0; i<answer.length; i++)//统一处理进位问题
    {
        answer.digit[i+1] += answer.digit[i]/10;
        answer.digit[i] %= 10;
    }

    while(answer.digit[answer.length-1] == 0 && answer.length > 1)//消除前导0
    {
        answer.length --;
    }

    return answer;
}

BigInteger BigInteger ::operator/(const BigInteger& b)
{
    BigInteger answer;
    answer.length = length;//商的最大位数
    BigInteger remainder = BigInteger(0);//暂存的计算数，最终为余数，初始化为0
    BigInteger temp = b;//记得要重载'='号

    for(int i = length-1; i >= 0; i--)//除法是从最高位开始做减法的，循环完成后，需要余数则返回remainder，需要商则返回answer
    {
        if(! (remainder.digit[0] == 0 && remainder.length == 1))//计算数不为0时，即待计算数有数值时
        {
            for(int j = remainder.length-1; j>=0; j--)//计算数右移一位
            {
                remainder.digit[j+1] = remainder.digit[j];
            }
            remainder.length ++;//长度加1
        }

        remainder.digit[0] = digit[i];//计算数最低位补上被除数的当前位

        while(temp <= remainder)//当前待计算数不比被除数小的时候，做减法；重载'<='号
        {
            remainder = remainder-temp;//重载'-'号
            answer.digit[i] ++;//当前商的位置上加1
        }
    }

    while(answer.digit[answer.length-1] == 0 && answer.length > 1)//消除前导0
    {
        answer.length --;
    }

    return answer;
}

BigInteger BigInteger ::operator%(const BigInteger& b)//和除法的思路类似，只不过不返回商，返回余数
{
    BigInteger remainder = BigInteger(0);//待运算数，初始化为0
    BigInteger temp = b;//存储被除数

    for(int i=length-1; i>=0; i--)
    {
        if(! (remainder.digit[0] == 0 && remainder.length == 1))//待运算数不为0时
        {
            for(int j=remainder.length-1; j>=0; j--)//右移一位
            {
                remainder.digit[j+1] = remainder.digit[j];
            }
            remainder.length ++;
        }

        remainder.digit[0] = digit[i];//最低位补上运算数

        while(temp <= remainder)//当前位上重复做减法
        {
            remainder = remainder-temp;
        }
    }
    return remainder;
}

void output(const BigInteger& x)//单独写个输出函数，逆序输出
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
