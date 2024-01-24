#include <bits/stdc++.h>
using namespace std;

/*
Create a data structure twoStacks that represents two stacks. 
Implementation of twoStacks should use only one array, i.e., 
both stacks should use the same array for storing elements. 
Following functions must be supported by twoStacks.
push1(int x) –> pushes x to first stack 
push2(int x) –> pushes x to second stack
pop1() –> pops an element from first stack and return the popped element 
pop2() –> pops an element from second stack and return the popped element
Implementation of twoStack should be space efficient.
*/

class TwoStacks{
    int* a;
    int size;
    int top1, top2;
    public:

    TwoStacks(int n){
        size = n;
        a = new int[n];
        top1 = -1;
        top2 = size;
    }

    void push1(int v){
        if(top1<top2-1) a[++top1] = v; 
        else cout<<"Overflow!"<<endl;
    }

    void push2(int v){
        if(top1<top2-1) a[--top2] = v; 
        else cout<<"Overflow!"<<endl;
    }

    void pop1(){
        if(top1>=0) cout<<a[top1--]<<endl;
        else cout<<"Underflow!"<<endl;
    }

    void pop2(){
        if(top2<size) cout<<a[top2++]<<endl;
        else cout<<"Underflow!"<<endl;
    }

    void getTop2(){
        if(top2<size) cout<<a[top2]<<endl;
        else cout<<"Empty!"<<endl;
    }

    void getTop1(){
        if(top1>=0) cout<<a[top1]<<endl;
        else cout<<"Empty!"<<endl;
    }
};

int main()
{
    TwoStacks ts(6);

    ts.push1(4);
    ts.push2(9);
    ts.push2(2);
    ts.push1(3);
    ts.push1(5);
    ts.push2(7);
    ts.push2(1);

    ts.getTop1();
    ts.getTop2();

    ts.pop1();
    ts.pop2();

    ts.getTop1();
    ts.getTop2();
}
