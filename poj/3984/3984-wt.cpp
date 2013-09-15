/*************************************************
Author : wt
Time : 0MS
Memory : 696K
**************************************************/

#include <iostream>
#include <deque>
using namespace std;

#define isValid(i, j) i>=0&&i<5&&j>=0&&j<5&&!map[i][j]

typedef struct point{
	int i, j;
	struct point *parent;
	point(int ti, int tj, struct point *p){
		i = ti;	j = tj;	parent = p;
	}
	bool operator == (const struct point &p) const{
		return (i == p.i)&&(j == p.j);
	}
	bool operator < (const struct point &p) const{
		return (i*5+j < p.i*5+p.j);
	}
	point& operator = (const struct point &p){
		return *this;
	}
}Point;

int isVisited[5][5];
deque<Point> queue;
int map[5][5];

void print(Point *p){
	if(p->parent)
		print(p->parent);
	cout<<'('<<p->i<<", "<<p->j<<')'<<endl;
}

int main()
{
	int i, j, step;
	for(i = 0; i < 5; ++i){
		for(j = 0; j < 5; ++j)
			cin>>map[i][j];
	}

	Point start(0, 0, NULL);
	queue.push_back(start);
	isVisited[0][0] = 1;

	Point *cur;
	while(!queue.empty()){
		cur = &(queue.front());
		if(cur->i == 4 && cur->j == 4)
			break;
		step = isVisited[cur->i][cur->j];
		queue.pop_front();
		if(isValid(cur->i-1, cur->j)){
			Point next(cur->i-1, cur->j, cur);

			if(!isVisited[next.i][next.j]){
				isVisited[next.i][next.j] = step+1;
				queue.push_back(next);
			}
		}
		if(isValid(cur->i, cur->j-1)){
			Point next(cur->i, cur->j-1, cur);

			if(!isVisited[next.i][next.j]){
				isVisited[next.i][next.j] = step+1;
				queue.push_back(next);
			}
		}
		if(isValid(cur->i+1, cur->j)){
			Point next(cur->i+1, cur->j, cur);

			if(!isVisited[next.i][next.j]){
				isVisited[next.i][next.j] = step+1;
				queue.push_back(next);
			}
		}
		if(isValid(cur->i, cur->j+1)){
			Point next(cur->i, cur->j+1, cur);

			if(!isVisited[next.i][next.j]){
				isVisited[next.i][next.j] = step+1;
				queue.push_back(next);
			}
		}
	}
	print(cur);
    return 0;
}