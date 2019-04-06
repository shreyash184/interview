#include <bits/stdc++.h>
using namespace std;
void move(stack<int> &s,stack<int> &d,string ss,string dd){
        d.push(s.top());
        cout<<"\n Ring  "<<s.top()<<"moved from  "<<ss<<" to "<<dd<<endl;
        s.pop();
    }
int main()
{
    stack<int>sour;
    stack<int>aux;
    stack<int>dest;
    int n;
    cout<<"enter the number of the rings in the tower of hanoi : ";
    cin>>n;
    int N=n;
    string s3=("destination");
    string s1=("source");
    string s2=("aux");
    if(sour.empty()){
                while(N>0)
                    sour.push(N--);
            }
    int i=1;
    while(i<=(int)pow(2,n)){
        if(n%2!=0){
            if(i%3==1){
                if(dest.empty())
                    move(sour,dest,s1,s3);
                else
                    if(sour.empty())
                        move(dest,sour,s3,s1);
                    else{
                        if(sour.top()>dest.top())
                            move(dest,sour,s3,s1);
                        else
                            move(sour,dest,s1,s3);
                    }
            }
            if(i%3==2){
                if(aux.empty())
                    move(sour,aux,s1,s2);
                else if(sour.empty())
                        move(aux,sour,s2,s1);
                    else{
                        if(sour.top()>aux.top())
                            move(aux,sour,s2,s1);
                        else
                            move(sour,aux,s1,s2);
                    }
            }
            if(i%3==0){
                if(dest.empty())
                    move(aux,dest,s2,s3);
                else if(aux.empty())
                        move(dest,aux,s3,s2);
                    else{
                        if(aux.top()>dest.top())
                            move(dest,aux,s3,s2);
                        else
                            move(aux,dest,s2,s3);
                    }
            }
        }
        else{
            if(i%3==1){
                if(aux.empty())
                    move(sour,aux,s1,s2);
                else if(sour.empty())
                        move(aux,sour,s2,s1);
                    else{
                        if(sour.top()>aux.top())
                            move(aux,sour,s2,s1);
                        else
                            move(sour,aux,s1,s2);
                    }
            }
            if(i%3==2){
                if(dest.empty())
                    move(sour,dest,s1,s3);
                else if(sour.empty())
                        move(dest,sour,s3,s1);
                    else{
                        if(sour.top()>dest.top())
                            move(dest,sour,s3,s1);
                        else
                            move(sour,dest,s1,s3);
                    }
            }
            if(i%3==0){
                if(aux.empty())
                    move(dest,aux,s3,s2);
                else if(aux.empty())
                        move(aux,dest,s2,s3);
                    else
                    {
                        if(dest.top()>aux.top())
                            move(aux,dest,s2,s3);
                        else
                            move(dest,aux,s3,s2);
                    }
            }
        }i++;
    }
    return 0;
}