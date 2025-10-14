# Nok lang (녹 언어)
이름은 닉네임 앞 글자 따서 만듦<br>여러번 갈아엎어서 구상하다가 포기하고 차근하게 아이디어 제대로 세우게 됨

실제로 구현할지, 아니면 의사코드처럼 수 많은 언어를 공통적인 방법으로 표현하는 수단으로 쓸 지 생각중

## 참고 언어
- **접해본 모든 언어 (C/C++ C# Java Kotlin Rust Go Delphi/Object Pascal Dart Javascript Typescript PHP Python Ruby Prolog Lua )** 

- 마이너하지만 Mojo Crystal도 참고
- 학습용 페이지 [プログラミング言語を作ろう](https://kmaebashi.com/programmer/devlang/index.html)

물론 모든 기능을 넣을수는 없고, 쉬운 언어를 만드는게 목적이므로 <br>
[Crystal](https://crystal-lang.org/) 처럼 간결하지만 개인적인 욕심기능을 추가할까 생각중<br>

구현체는 왠만하면 C/C++로 만들예정<br>
문서는 필요에 따라 세분화

개인적으로 실력상 동적 언어를 만드는게 현실적이나<br>
컴파일 언어를 구현하면 멋질거 같아서 ** 정적 타이핑 + 컴파일 언어 **를 구상중

# 자료형 (Type)
파이썬처럼 mut(가변), immut(불변) 두 가지를 지원, 
기본 자료형은 반드시 immut에 속함
## 기본 자료형 (Basic Type)
### 불변(Immutable Type)
- byte 1byte
- short 2byte
- int 4byte
- long 8byte
- ubyte, ushort, uint, ulong 
- float 4byte
- double 8byte
- char 2byte
- str 
키워드는 기본적으로 C/C++, Java를 따름<br>
double을 real로 대체할까 생각했지만 새로운 키워드 만들어도 혼란만 생길듯해 포기

`char`는 Java처럼 2바이트 와이드캐릭터를 사용, 0~2^16-1 사용가능<br>
(굳이 1바이트를 쓸거면 byte 권장)
`str`는 Rust처럼 문자열 리터럴

### 가변 (Mutable Type)
- String
- Array
- Dict

필요에 따라 추가 예정<br>
클래스로 선언한 식별자는 전부 가변형(Mutable Type)임

## 클래스 (Class)
클래스 기반 언어를 생각 중이나
