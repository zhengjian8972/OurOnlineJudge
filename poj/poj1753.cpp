#include <iostream>
#include <queue>
using namespace std;

int step[65535];
bool flag[65535];

unsigned short qState[65535];
int rear=0;
int top=0;

void init()
{
    unsigned short temp = 0;
    char c;
    for(int i =0; i<4; i++)
        for(int j =0; j<4; j++)
        {
            cin>>c;
            if(c=='b')
                temp |=(1<<(i*4+j));	//使用16位短整数存储状态
        }
    qState[rear++]=temp;
    flag[temp]=true;
}

unsigned short move(unsigned short state,int i)
{
    unsigned short temp = 0;
    temp |= (1<<i);

    if((i+1)%4!=0)
        temp |= (1<<(i+1));
    if((i)%4!=0)
        temp |= (1<<(i-1));
    if(i>=4)
        temp |= (1<<(i-4));
    if(i<12)
        temp |= (1<<(i+4));

    return state ^temp;
}

bool BFS()
{
    while(rear >top)
    {
        unsigned short state= qState[top++];
        if(state==0||state==65535)
        {
            cout<<step[state];
            return true;
        }
        for(int i=0; i<16; i++)
        {
            unsigned short temp = move(state,i);

            if(!flag[temp])
            {
                qState[rear++]=temp;
                flag[temp]=true;
                flag[temp]=true;
                step[temp]=step[state]+1;
            }
        }
    }
    return false;
}

int main()
{
    init();
    if(!BFS())
        cout<<"Impossible";
    system("pause");

}
