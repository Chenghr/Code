#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int maxValue = 0; // 最大子串长度
    int tempMaxValue = 0; // 目前长度

    /* use sliding window 使用滑动窗口
    设置左指针a，右指针b；
    b指针向右侧伸缩
    {
        对每个A[b]判断是否在之前的数组中出现过；
            如果出现，指针a指向出现过得位置的下一个位置；
        更新右指针和最大长度；
    }
    可以用滑动串口数组存储出现过的字符，以其ASCII码作为其下标，存储内容为下一个字符的ASCII码
    */
    int slidingWindowHead = 0;
    int slidingWindowRear = 0;
    int slidingWindowQueue[128] = {0}; // ASCII of X86，利用字符的ASCII码来创建数组，对应存储，作为map

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

        if(tempMaxValue > maxValue) // 更新最大子串长度
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
