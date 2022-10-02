#include<bits/stdc++.h>
using namespace std;
int me(int n,int a,int b,int c)
{
    if(n==0)
    return 0;
    if(n<0)
    return -1;
    int r=max(me(n-a,a,b,c),me(n-b,a,b,c),me(n-c,a,b,c));
    if(r==-1)
    return -1;
    return r+1;

}
int main()
{
    int m,e,f,g;
    cout<<"Enter the max.length of rope and pieces size"<<endl;
    cin>>m>>e>>f>>g;
    cout<<me(m,e,f,g);
    return 0;
}
