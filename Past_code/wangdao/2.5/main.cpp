#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        int row = 0, col = 0;//�ַ�-������к���
        row = s.size()/3+1;
        col = s.size()-2*(row-1);
        while(s.size()%3 == 0)//����Ϊ0ʱ���������಻�ܱȵױ߳�������Ҫ�޸�
        {
            row--;
            col += 2;
        }

        char **arr = new char*[row];//��̬������ά����
        for(int i=0; i<row; i++)
        {
            arr[i] = new char[col];
        }

        int j = 0;//�������
        for(int i=0; i<row; i++,j++) arr[i][0] = s[j];
        for(int i=1; i<col; i++,j++) arr[row-1][i] = s[j];
        for(int i=row-2; i>=0; i--,j++) arr[i][col-1] = s[j];
        for(int i=0; i<row-1; i++)
        {
            for(int j=1; j<col-1;j++)
            {
                arr[i][j] = ' ';
            }
        }

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col;j++)
            {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
