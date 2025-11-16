#include <string>
#include <iostream>
#include <vector>
#include <memory>
struct TokenData{
    std::string name;
    std::string type;
};
#define putinword {*pword=*c;c++;pword++;if(*c=='\0')goto Print;}
bool lexer(const std::string& text,std::vector<TokenData>&tokens){
    //std::string word;
    char word[128]={0,};
    std::string type="none";

    //word.resize(text.size());
    char *pword;
    char* c=(char*)(text.c_str());
    bool res=true;
Main:
    pword=&word[0];
Skip:
    while(*c=='\t'||*c=='\n'||*c==' ') c++;
    if(*c=='\0')goto End;

    if(*c>='0' && *c<='9') goto Number;
    if((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z')||*c=='_') goto Ident;
    if(*c=='\'' || *c=='\"')goto LitStr;
    else goto Error;
Number:
    type="number";
    while(*c>='0' && *c<='9'){
        putinword;
    }
    goto Print;
Ident:
    type="ident";
    while((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z')||(*c>='0' && *c<='9')||*c=='_') putinword;
    goto Print;
LitStr:{
    type="string";
    char _q=*c++;
    while(*c!=_q)putinword;
    c++;
}
    goto Print;
Print:
    *pword=0;
    tokens.emplace_back(TokenData{word,type});
    std::cout<<'['<<type<<']'<<word<<'\n';
    goto Main;
Error:
    res=false;
    std::cout<<"[Error]"<<*c<<'\n';
    pword=&word[0];
    while(!(*c=='\0' || *c=='\n'))c++;
    goto Main;
End:
    return res;
}
#undef putinword
int main(){
    std::string text;
    text.resize(250);
    std::vector<TokenData>tokens;

    while(true){
        std::cout<<">>";
        std::cin.getline(&text[0],256);
        if(text.size()==0)break;
        else if(text[0]=='$')break;

        if (lexer(text,tokens)) std::cout<<"SUCCESS\n";
        else std::cout<<"FAILED\n";
        std::cout<<"--------\n";
    }

    for (auto tok:tokens){
        std::cout<<tok.name<<':'<<tok.type<<'\n';
    }
    return 0;
}
