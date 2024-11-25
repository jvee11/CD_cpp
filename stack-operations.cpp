#include<iostream>
using namespace std;
int stack[100],value,top=-1;
int n=sizeof(stack)/sizeof(stack[0]);
void push(){
    if(top>=n-1){
        cout<<"Stack is full"<<endl;
    }
    else{
        top++;
        cout<<"Enter the value to be pushed"<<endl;
        cin>>value;
        stack[top]=value;


}
}
void pop(){
    if(top<=-1){
        cout<<"Stack is empty"<<endl;

    }
    else{
        cout<<"Popped element is "<<stack[top]<<endl;
        top--;

    }

}
void display(){
    if(top>=0){
        for (int i=top;i>=0;i--){
    
             cout<<"stack elements are: "<<stack[i]<<endl;
        }
        }
        else{
            cout<<"Stack is empty"<<endl;
        }
       
}
int main(){
    int choice;
    while(true){
    cout<<"Stack operations"<<endl;
    cout<<"1.Push"<<endl;
    cout<<"2.Pop"<<endl;
    cout<<"3.Display"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter your choice"<<endl;
    cin>>choice;
         switch (choice)
    {
    case 1:
        push();
        break;

    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        cout<<"Exit";
        return 0;
        break;
    
    default:
    cout<<"Invalid choice"<<endl;
        break;
    }

    }
   
    
    
}