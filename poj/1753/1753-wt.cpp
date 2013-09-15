/*************************************************
Author : wt
Time : 0MS
Memory : 732K
**************************************************/

#include <iostream>
#include <deque>
using namespace std;

int n, answer = 65535;
bool states[65540];
int mask[] = {
    0xc800, 0xe400, 0x7200, 0x3100,
    0x8e80, 0x4e40, 0x2720, 0x1310,
    0x08c8, 0x04e4, 0x0272, 0x0131,
    0x008c, 0x004e, 0x0027, 0x0013
};
typedef struct state{
    int s; int c;
    state(){}
    state(int ts, int tc) : s(ts), c(tc){}
}State;


void input(){
    n = 0;
    char c;
    for(int i = 15; i >= 0; i--){
        cin>>c;
        if(c == 'b')
            n += (1<<i);
        if( i%4 == 0)
            cin.get();
    }
}

int bfs(){
    if(n==0 || n==0xffff)
        return 0;

    deque<State> queue;
    states[n] = true;
    queue.push_back(State(n, 0));

    State tmp;
    int num, step;
    while(!queue.empty()){
        tmp = queue.front();
        queue.pop_front();

        for(int i = 0; i < 16; i++){
            num = tmp.s ^ mask[i];
            step = tmp.c;
            if(!states[num]){
                if(num==0 || num==0xffff){
                    return step+1;
                }
                queue.push_back(State(num, step+1));
                states[num] = true;
            }
        }
    }
    return -1;
}

void dfs(int num, int step, int i){
    if(num==0 || num==0xffff){
        if(answer > step)
            answer = step;
        return ;
    }
    if(i >= 16 || step >= 65535) return;

    dfs(num, step, i+1);
    dfs(num^mask[i], step+1, i+1);
}

int main()
{
    input();
//    int c = bfs();
//    if(c == -1)
//        cout<<"Impossible"<<endl;
//    else cout<<c<<endl;
    states[n] = true;
    dfs(n, 0, 0);
    if(answer >= 65535)
        cout<<"Impossible"<<endl;
    else cout<<answer<<endl;
    return 0;
}
