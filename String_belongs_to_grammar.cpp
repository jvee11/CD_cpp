#include<iostream>// string alternates between 'a' and 'b', starting with 'a'.
using namespace std;
bool isvalid(const string &str){
    int len=str.length();
    
        if(len==0){
            return true;


        }
       
        if(str[0]!='a'){
            return false;
        }
        else{
            for (int i = 1; i < len; i++)
            {
                if(str[i]==str[i-1]){
                return false;
            }
            true;
            
        }
        
        

        }

}
int main(){
    string str;
    cout<<"Enter the string \n :   ";

    cin>>str;
    if(isvalid(str)){
        cout<<"The string is valid \n";

    }
    else{
        cout<<"The string is not valid \n";
    }    
    return 0;
    
    
}