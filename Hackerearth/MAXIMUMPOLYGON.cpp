#include <bits/stdc++.h>

using namespace std;
struct Point{
  int x,y;
};
Point p0;

void swap(Point *p1,Point *p2){
  Point temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

Point nextToTop(stack<Point> &s){
  Point p = s.top();
  s.pop();
  Point nxt = s.top();
  s.push(p);
  return nxt;
}

int dissq(Point a,Point b){
  return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
}

int orientation(Point p, Point q, Point r){
  int val = (q.x-p.x)*(r.y-p.y)-(r.x-p.x)*(q.y-p.y);
  if(val==0)
  return 0;
  if(val<0)
  return 1;//Clockwise
  else
  return 2;//Counter-Clockwise
}

int compare(const void *vp1,const void *vp2){
  Point *p1 = (Point *)vp1;
  Point *p2 = (Point *)vp2;
  int o=orientation(p0,*p1,*p2);
  if(o==0)
  return (dissq(p0,*p2)>=dissq(p0,*p1))?-1:1;
  else
  return (o==2)?1:-1;
}

void convexHull(Point points[],int n){
  int ymin = points[0].y,min=0;
  for(int i=1;i<n;i++){
    if(points[i].y<ymin || (points[i].y==ymin && points[min].x<points[i].x)){
      ymin = points[i].y;
      min = i;
    }
  }
  swap(points[0],points[min]);

  p0 = points[0];
  qsort(&points[1],n-1,sizeof(Point),compare);

  int m=1;
  for(int i=1;i<n;i++){
    while(i<n-1 && orientation(p0,points[i],points[i+1])==0){
      i++;
    }
    points[m]=points[i];
    m++;
  }
  if(m<3)
  return;

  cout<<points[0].x<<" "<<points[0].y<<endl;
  stack<Point> s;
  s.push(p0);
  s.push(points[1]);
  s.push(points[2]);

  for(int i=3;i<n;i++){
    while(orientation(nextToTop(s),s.top(),points[i])!=2){
      s.pop();
    }
    s.push(points[i]);
  }
  while(!s.empty()){
    Point p = s.top();
    cout<<"{"<<p.x<<","<<p.y<<"}"<<endl;
    s.pop();
  }

}


int main(){
  Point points[]={{2,1},{1,0},{2,2},{1,3},{0,1},{0,2}};
  int n = sizeof(points)/sizeof(points[0]);
  convexHull(points,n);
  return 0;
}
