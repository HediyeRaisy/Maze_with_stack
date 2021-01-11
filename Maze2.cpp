#include<iostream>
#include <time.h>
#include<unistd.h>
#include<stdlib.h>
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

using namespace std;
unsigned int MAP[12][12];
int flag=0;

struct mouse{
    int x;
    int y;
}M;
struct cheese{
    int x;
    int y;
}C;

class Stack{
    
        
    int top;
    public:
        int get_top(){
            return top;
        }
        int a[1000];
        Stack(){ top=-1 ;}
        bool push(int x);
        int pop();
        int peek();
        

        
};
bool Stack ::push (int x){
    if(top==199){
        cout<<"STACK OVER FLOW";
        return 0;
    }
    else{
        top++;
        a[top]=x;
        return 1;
    }
    
}
int Stack ::pop (){
    if(top=-1){
        cout<<"STACK UNDERFLOW";
        return 0;

    }
    else{
        top--;
        return 1;
    }
}
int Stack ::peek(){
    return a[top];
}
int rand_x(){
    srand(time(0));
    int x = rand()%10 + 1;
    return x;
}
int rand_y(int x){
    int y,h;
    if(x==1 || x==10){
        srand(time(0));
        y=rand()%10 + 1;
    }
    else{
        srand(time(0));
        h=rand()%2;
        if(h==0){
            y=10;
        }
        if(h==1){
            y=1;
        } 
        
    }
return y;
}

void print1(unsigned int a[12][12]){
    for(int j=0;j<12;j++){
        for(int i=0;i<12;i++){
            cout<<a[j][i];
        }
        cout<<"\n";
    }
}
void road(int x1, int y1,int x2,int y2,unsigned int MAP[12][12]){
    srand(time(0));
    int a=rand()%2;
    if(a==0){
        if(x1>x2){

            while(x1!=x2){
                x1--;
                MAP[x1][y1]=1;
            }
        }
        else{
            while(x1!=x2){
                x1++;
                MAP[x1][y1]=1;
            }
        }
        if(y1>y2){

            while(y1!=y2){
                y1--;
                MAP[x1][y1]=1;
            }
        }
        else{
            while(y1!=y2){
                y1++;
                MAP[x1][y1]=1;
            }
        }

    }
    if(a==1){
        if(y1>y2){

            while(y1!=y2){
                y1--;
                MAP[x1][y1]=1;
            }
        }
        else{
            while(y1!=y2){
                y1++;
                MAP[x1][y1]=1;
            }
        }
        if(x1>x2){

            while(x1!=x2){
                x1--;
                MAP[x1][y1]=1;
            }
        }
        else{
            while(x1!=x2){
                x1++;
                MAP[x1][y1]=1;
            }
        }
    }
  
    
}

void random(unsigned int MAP[12][12]){
    for(int i=0; i<12 ; i++){
        for(int j=0; j<12 ; j++){
            if(MAP[i][j]==2){
                if((i+j)%2==0){
                    MAP[i][j]=1;
                }
                else{
                    MAP[i][j]=0;
                }
            }
        }
    }
}

void printMap(unsigned int a[12][12]){
	int i;
	int j;
    for(i = 0; i < 12; i++) {
		for(j = 0; j < 12; j++) {
			if (j == M.x && i == M.y) {
				cout<<COLOR_MAGENTA "M" COLOR_RESET;
			} 
			else if (j == C.x && i==C.y) {
				cout<<COLOR_YELLOW "C" COLOR_RESET;
			}
			else if((a[j][i]==1)) {
				cout<<" ";		
			}
			else 
				cout<<COLOR_BLUE "*" COLOR_RESET;		
		}
		cout<<"\n";
	}
	
}
void screen(){
    if(M.x==C.x && M.y==C.y){
        system("clear");
        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
    }
    printMap(MAP);
    sleep(1);
    system("clear");
    
}

void move(unsigned int MAP[12][12]){
    srand(time(0));
    Stack a,b,c;
    int h1=0;
    while(M.x!=C.x || M.y!=C.y){
        int a1=0;
        if(h1!=0){
            do{
                a1=rand()%8+1;
            }while(a1==h1);
        }
        else{
           a1=rand()%8+1; 
        }
        
        int flag=0;
        h1=0;
        switch (a1)
        {
        case 1:
            if(MAP[M.x][M.y+1]==0){
                
            }
            else{
               //while((MAP[M.x][M.y+1]!=0)) {
                a.push(M.x);
                b.push(M.y);
                c.push(a1);
                M.y++;
                printMap(MAP);
                sleep(1);
                system("clear");
                if(M.x==C.x && M.y==C.y){
                    system("clear");
                    cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                    break;
                    }
               //}
               flag=1;
               break;
            }
            
        
        case 2:
            if(MAP[M.x][M.y-1]==0){
                
            }
            else{
                //while(MAP[M.x][M.y-1]!=0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.y--;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                    if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
               // }
                flag=1;
                break;
            }
            
        
        case 3:
            if(MAP[M.x+1][M.y]==0){
                
            }
            else{
               // while(MAP[M.x+1][M.y]!=0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.x++;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                    if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
                //}
                flag=1;
                break;
            }
            break;
        case 4:
            if(MAP[M.x-1][M.y]==0){
                flag=1;
            }
            else{
                //while(MAP[M.x-1][M.y]!=0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.x--;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                    if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
                //}
                flag=1;
                break;
            }
            break;
        case 5:
            if(MAP[M.x-1][M.y+1]==0){
                
            }
            else{
                //while(MAP[M.x-1][M.y+1]!=0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.x--;
                    M.y++;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                    if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
                //}
                flag=1;
                break;
            }
            break;
        case 6:
            if(MAP[M.x+1][M.y-1]==0){
                flag=1;
            }
            else{
                //while(MAP[M.x+1][M.y-1]!=0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.x++;
                    M.y--;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                     if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
                //}
                flag=1;
                break;
            
            }
            break;
        case 7:
            if(MAP[M.x+1][M.y+1]==0){
                
            }
            else{
                //while(MAP[M.x+1][M.y+1]==0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.x++;
                    M.y++;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                    if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
                //}
                flag=1;
                break;
            }
            
        case 8:
            if(MAP[M.x-1][M.y-1]==0){
                flag=1;
            }
            else{
                //while(MAP[M.x-1][M.y-1]!=0){
                    a.push(M.x);
                    b.push(M.y);
                    c.push(a1);
                    M.x--;
                    M.y--;
                    printMap(MAP);
                    sleep(1);
                    system("clear");
                     if(M.x==C.x && M.y==C.y){
                        system("clear");
                        cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                        break;
                    }
                //}
                flag=1;
                break;
            }
            

        }
        if(flag==0 && a.get_top()!=0 && b.get_top()!=0 && c.get_top()!=0){
            h1=c.peek();
            c.pop();
            a.pop();
            b.pop();
            M.x=a.peek();
            M.y=b.peek();
            printMap(MAP);
            sleep(1);
            system("clear");
            if(M.x==C.x && M.y==C.y){
                system("clear");
                cout<<COLOR_RED "\n\n\nTHE MOUSE GET THE CHEESE\n" COLOR_RESET;
                
            }
        }
    } 
}

int main(){
    unsigned int MAP[12][12]={
        {0,0,0,0,0,0,0,0,0,0,0,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,2,2,2,2,2,2,2,2,2,2,0},
        {0,0,0,0,0,0,0,0,0,0,0,0},
    };
    M.x=rand_x();
    M.y=rand_y(M.x);
    C.x=rand_x();
    C.y=rand_y(C.x);
    if(M.x==C.x && M.y==C.y){
        while(M.x==C.x && M.y==C.y){
            M.x=rand_x();
            M.y=rand_y(M.x);
        }
    }
    MAP[M.x][M.y]=1;
    MAP[C.x][C.y]=1;
    road(M.x,M.y,C.x,C.y,MAP);
    random(MAP);
    cout<<COLOR_RED "\n\n\nWELCOME TO THE MAZE\n" COLOR_RESET;
    sleep(3);
    system("clear");
    move(MAP);
    
    
}