//251117 am 4 add token 
#include <string>
#include <iostream>
#include <vector>
#include <memory>
struct TokenData{
    std::string name;
    std::string type;
    unsigned int itype;
};
#define putinword {*pword=*c;c++;pword++;if(*c=='\0')goto Print;}
#define putchinword(ch) {*pword=ch;c++;pword++;if(*c=='\0')goto Print;}
bool lexer(const std::string& text,std::vector<TokenData>&tokens){
    //std::string word;
    char*word=new char[text.size()+1];
    //char word[128]={0,};
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
    if(*c=='/')goto DoubtComment;
Start:
    if(*c>='0' && *c<='9') goto Number;
    if((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z')||*c=='_') goto Ident;
    if((*c=='\'')||(*c=='\"'))goto Quot;
Symbol:
/* 

S1 + - / < > ! =
S1star *
S11star 
S11 =

S2 ( ) [ ]
S2 
*/
    type=*c;
    switch(*c){
        case '+':
        case '/':
        case '=':
        case '<':
        case '>':
        case '!':
        case '-':goto SymDoubtEq;
        case '*':goto SymStar;

        case '#':
        case '@':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
        case ',':
        case '.':
        case ':':
        case ';':
            putinword;
            goto Print;
        default:
            putinword;
            goto Error;
    }
SymDoubtEq://+= -= ..
    putinword;
    if(*c=='='){ type+=*c; putinword; goto Print; }
    goto Print;

SymStar://*= **
    putinword;
    if(*c=='*'){ type="pow"; putinword; goto Print; }
    if(*c=='='){ type+=*c; putinword; goto Print; }
    goto Print;
DoubtComment:
    c++;
    if(*c=='/') goto LineComment;
    if(*c=='#') goto DoubtLineComment;
    c--;
    goto Start;
DoubtLineComment:
    c++;
    if(*c=='{')goto BlockComment;
    c-=2;
    goto Start;
LineComment:
    c++;
    if(*c=='\n'||*c=='\0') goto Skip;
    //c++;
    goto LineComment;
BlockComment:
    c++;
    if(*c=='\0')goto End;
    if(*c!='}')goto BlockComment;
    c++;
    if(*c!='#')goto BlockComment;
    c++;
    if(*c!='/')goto BlockComment;
    c++;
    goto Skip;
Number:
/* 0(b[01]+|x[0-9a-fA-F]+|'.'[0-9]+)
1-9 (0-9)*('.'[0-9]+)*/
    type="int";
    if (*c=='0') goto NumZero;
    putinword;
    while (*c>='0'&&*c<='9') putinword;
    if (*c=='.') goto NumFloat10;
    goto Print;
NumZero:
    c++;
    if(*c=='b')goto NumBin;
    if(*c=='x')goto NumHex;
    goto Print;
NumBin:
    type="bin";
    c++;
    while(*c=='0'||*c=='1')putinword;
    goto Print;
NumHex:
    type="hex";
    c++;
    while((*c>='0'&&*c<='9')||(*c>='A'&&*c<='F')||(*c>='a'&&*c<='f'))putinword;
    goto Print;
NumFloat10:
    type="float";
    putinword;
    while (*c>='0'&&*c<='9') putinword;
    goto Print;
Ident:
    type="ident";
    while((*c>='a'&&*c<='z')||(*c>='A'&&*c<='Z')||(*c>='0' && *c<='9')||*c=='_') putinword;
    goto Print;

Quot:
    {
        char _q=*c;
        bool ischar=(*c=='\''?true:false);
        c++;
        while(!(*c==_q||*c=='\0')){
            if (*c!='\\') { putinword; continue; }
    CharEscape:
            c++;
            if(*c=='x'){
                c++;
                while((*c>='0'&&*c<='9')||(*c>='A'&&*c<='F')||(*c>='a'&&*c<='f'))c++;
                continue;
            }
            else if(*c>='0'&&*c<='9'){c++;}
            else if(*c=='n'){putchinword('\n');}
            else if(*c=='t'){putchinword('\t');}
            else goto Error;
        }
        c++;
        if(pword-word>1) ischar=false;
        type=(ischar?"char":"string");
    }
    goto Print;
Print:
    *pword=0;
    std::cout<<'['<<type<<']'<<word<<'\n';
    tokens.emplace_back(TokenData{word,std::move(type)});
    goto Main;
Error:
    res=false;
    std::cout<<"[Error]"<<*c<<'\n';
    pword=&word[0];
    while(!(*c=='\0' || *c=='\n'))c++;
    goto Main;
End:
    delete word;
    return res;
}
#undef putinword
int main(){
    std::string text="/#{asdfasdfmkd\nfhbtbfcbv /#{ sdff }#/ /#{}# / }#/ asdf\nasdf//asdfasdasdgasdf\nasdgdbrt";
   
    std::vector<TokenData>tokens;
    if (lexer(text,tokens)) std::cout<<"SUCCESS\n";
        else std::cout<<"FAILED\n";

    text.resize(250);
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
        std::cout<<'['<<tok.type<<']'<<tok.name<<'\n';
    }
    return 0;
}
/*
process:
label1:
    proc1(); //lex 처리

label2:

    if M goto labeln;

*/
