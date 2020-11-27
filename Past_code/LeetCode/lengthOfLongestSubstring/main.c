#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int maxValue = 0; // ����Ӵ�����
    int tempMaxValue = 0; // Ŀǰ����

    /* use sliding window ʹ�û�������
    ������ָ��a����ָ��b��
    bָ�����Ҳ�����
    {
        ��ÿ��A[b]�ж��Ƿ���֮ǰ�������г��ֹ���
            ������֣�ָ��aָ����ֹ���λ�õ���һ��λ�ã�
        ������ָ�����󳤶ȣ�
    }
    �����û�����������洢���ֹ����ַ�������ASCII����Ϊ���±꣬�洢����Ϊ��һ���ַ���ASCII��
    */
    int slidingWindowHead = 0;
    int slidingWindowRear = 0;
    int slidingWindowQueue[128] = {0}; // ASCII of X86�������ַ���ASCII�����������飬��Ӧ�洢����Ϊmap

    int length = strlen(s);

    if(length == 0)
    {
        return 0; // null string
    }

    while(slidingWindowHead <= (length - 1))
    {
        if(slidingWindowQueue[ s[slidingWindowHead] ] != 0) // find the same char
        {
            if(slidingWindowQueue[ s[slidingWindowHead] ] > slidingWindowRear) // ignore outer substring
            {
                slidingWindowRear = slidingWindowQueue[ s[slidingWindowHead] ]; // refresh rear of sliding window
            }
        }

        tempMaxValue = slidingWindowHead - slidingWindowRear + 1; // equal to sliding window length

        if(tempMaxValue > maxValue) // ��������Ӵ�����
        {
            maxValue = tempMaxValue;
        }

        slidingWindowQueue[ s[slidingWindowHead] ] = slidingWindowHead + 1; // store the [string char <-> position] in queue
        slidingWindowHead++;
    }

    return maxValue;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
