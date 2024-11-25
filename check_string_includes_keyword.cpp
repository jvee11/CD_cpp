#include<iostream>
using namespace std;
bool iskeyword(const string &word){
    string keywords[] = {"alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor",
        "bool", "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t",
        "class", "compl", "concept", "const", "consteval", "constexpr", "constinit",
        "const_cast", "continue", "co_await", "co_return", "co_yield", "decltype",
        "default", "delete", "do", "double", "dynamic_cast", "else", "enum", "explicit",
        "export", "extern", "false", "float", "for", "friend", "goto", "if", "inline",
        "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
        "nullptr", "operator", "or", "or_eq", "private", "protected", "public",
        "register", "reinterpret_cast", "requires", "return", "short", "signed",
        "sizeof", "static", "static_assert", "static_cast", "struct", "switch",
        "template", "this", "thread_local", "throw", "true", "try", "typedef",
        "typeid", "typename", "union", "unsigned", "using", "virtual", "void",
        "volatile", "wchar_t", "while", "xor", "xor_eq"};
        int size=sizeof(keywords)/sizeof(keywords[0]);
        for (int i = 0; i < size; i++)
        {
            if(keywords[i]==word){
                return true;
            }
            false;
        }
        
}
int main(){
    string str;
    cout<<"enter string "<<endl;
    cin>>str;
    if(iskeyword(str)){
        cout<<"keyword"<<endl;
    }
    else{
        cout<<"not keyword"<<endl;
    }
    return 0;
}
