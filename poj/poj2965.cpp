#include <iostream>
#include <stack>
using namespace std;

int step[65535];
bool flag[65535];

unsigned short before[65535];
unsigned short path[65535];
stack<unsigned short > rpath;
unsigned short qState[65535];
int rear=0;
int top=0;

void init() {
    unsigned short temp = 0;
    char c;
    for(int i =0; i<16; i++) {
        cin>>c;
        if(c=='+')
            temp |=(1<<i);
    }
    qState[rear++]=temp;
    flag[temp]=true;
    before[temp]=temp;
}


int i,j,p;
unsigned short move(unsigned short state,int k) {
    unsigned short temp = 0;
    i = k/4;
    j= 	k%4;
    for( p=0; p<4; p++) {
        temp |= 1<<(i*4+p);
        temp |= 1<<(p*4+j);
    }
    return state ^temp;
}

bool BFS() {
    while(rear >top) {
        unsigned short state= qState[top++];
        if(state==0) {
            cout<<step[state]<<endl;
            unsigned short temp = state;
            while(before[temp]!=temp) {
                rpath.push(path[temp]);
                temp = before[temp];
            }
            while(!rpath.empty()) {
                cout<<rpath.top()/10+1<<" "<<rpath.top()%10+1<<endl;
                rpath.pop();
            }
            return true;
        }
        for(int k=0; k<16; k++) {
            unsigned short temp = move(state,k);
            if(!flag[temp]) {
                qState[rear++]=temp;
                flag[temp]=true;
                step[temp]=step[state]+1;
                before[temp]=state;
                path[temp]=i*10+j;
            }
        }
    }
    return false;
}

int main() {
    init();
    BFS();
    system("pause");

}
