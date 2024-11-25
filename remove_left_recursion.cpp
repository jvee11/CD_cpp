#include<iostream>
using namespace std;
int main(){
    int n;
    string productions,parent,alpha,beta;
    cout<<"Enter the non terminal"<<endl;
    cin>>parent;
    cout<<"enter the no of productions"<<endl;
    cin>>n;
    bool hasleft_recursion=false;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter production"<<i+1<<":";
        cin>>productions;
        if(parent[0]==productions[0]){
            hasleft_recursion=true;
            alpha+=productions.substr(1)+parent+"'|";//left recurs<<ive parts
        }
        else{
            beta+=productions+parent+"'|";

        }

        
    }
    if(hasleft_recursion){
        cout<<parent<<"->"<<beta<<"#"<<endl;
        cout<<parent<<"'->"<<alpha<<endl;
        
    }
    else{
        cout<<"no left recursion found"<<endl;
    }
    return 0;
    
}