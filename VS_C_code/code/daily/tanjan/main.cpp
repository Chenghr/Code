#include "cstdio"
#include "iostream"
#include "algorithm"

using namespace std ;

const int maxN = 10010;
const int maxM = 50010;

struct Kosaraju
{
    int to, next ;
} ;

Kosaraju E[ 2 ][ maxM ] ;
bool vis[ maxN ];
int head[ 2 ][ maxN ], cnt[ 2 ];
int ord[maxN], size[maxN],color[ maxN ];

int tot, dfs_num, col_num, N, M  ;

void Add_Edge( int x, int y, int _ )   //建图
{
    E[ _ ][ ++cnt[ _ ] ].to = y ;
    E[ _ ][ cnt[ _ ] ].next = head[ _ ][ x ] ;
    head[ _ ][ x ] = cnt[ _ ] ;
}

void DFS_1 ( int x, int _ )
{
    dfs_num ++ ;//发现时间
    vis[ x ] = true ;
    for ( int i = head[ _ ][ x ] ; i ; i = E[ _ ][ i ].next )
    {
        int temp = E[ _ ][ i ].to;
        if(vis[ temp ] == false)
            DFS_1 ( temp, _ ) ;
    }
    ord[(N<<1) + 1 - (++dfs_num) ] = x ;//完成时间加入栈
}

void DFS_2 ( int x, int _ )
{
    size[ tot ]++ ;// 强连通分量的大小
    vis[ x ] = false ;
    color[ x ] = col_num ;//染色
    for ( int i=head[ _ ][ x ] ; i ; i = E[ _ ][ i ].next )
    {
        int temp = E[ _ ][ i ].to;
        if(vis[temp] == true)
            DFS_2(temp, _);
    }
}

int main ( )
{
    scanf("%d %d", &N, &M );
    for ( int i=1 ; i<=M ; ++i )
    {
        int _x, _y ;
        scanf("%d %d", &_x, &_y ) ;
        Add_Edge( _x, _y, 0 ) ;  //原图的邻接表
        Add_Edge( _y, _x, 1 ) ;  //逆图的邻接表
    }
    for ( int i=1 ; i<=N ; ++i )
        if ( vis[ i ]==false )
            DFS_1 ( i, 0 ) ; //原图的DFS

    for ( int i = 1 ; i<=( N << 1) ; ++i )
    {
        if( ord[ i ]!=0 && vis[ ord[ i ] ] )
        {
            tot ++ ; //强连通分量的个数
            col_num ++ ;//染色的颜色
            DFS_2 ( ord[ i ], 1 ) ;
        }
    }

    for ( int i=1 ; i<=tot ; ++i )
        printf ("%d ",size[ i ]);
    putchar ('\n');
    for ( int i=1 ; i<=N ; ++i )
        printf ("%d ",color[ i ]);
    return 0;
}
