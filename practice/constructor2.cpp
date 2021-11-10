#include<iostream>
#include<math.h>

using namespace std;

class point{
    int x,y;
    
    public:
    point(int a, int b){
        x = a;
        y = b;
    }
    void printpoint(){
        cout<<"the point: "<<x<<" , "<<y<<endl;
    }
    friend int distance(point e ,point f);
    
};

int distance(point e ,point f){
        int dx = abs(e.x - f.x);
        int dy = abs(e.y- f.y);

        int distance = sqrt(dx*dx + dy*dy);
        
        return distance;
    }

int main(){

    point c(1,1),d(4,3);
    int dist = distance(c,d);
    cout<<dist;
    return 0;
}

