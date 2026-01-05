# noklang project Idea
##  260106 Idea
```
# wtf
fn to(type T=int|float)
	if n==10 print(100)
	end
end 

arr:[[int 2] 5]=[[1,2] [3,4] [5 6]] 

arr2:&[int 2]=&arr
;that
arr2,ass | to(int, )(100)


#[
기초적인 판단 여부
0. 
1. obj
1-0. obj 자체를 참조
1-1. obj의 child를 참조
1-1-0. obj의 child가 객체 아님
1-1-0-1. obj의 child가 객체임
2. 수명
2-0. 같은 수명
2-1. 다른 수명
2-1-0. 스코프 
2-1-0-0. 스코프 바깥을 참조
2-1-0-1. 스코프 안을 참조
2-1-1. 함수
]#

#[참조1-1 : 객체 아님, 같은 수명일경우]#
i=1010
i_ref:&int=&i
i_ref=&i

#[참조1-2 : 객체, 같은 수명]#
i=[1 2 3 4]


#[참조1-3 : 객체, 다른 수명이나 스코프]#



arr:int[2][5]
arr2:int[2]

arr

region 

R1{
	heap A1
	stack B1
	R2{
		heap A2
		stack B2
		ret(R1) A2
	}
}

# python-like
- R-out(현재 함수를 호출한 함수)
- Rn 현재 스코프
- Rn-1 Rn-2 ... Rn-m 바깥 스코프 (부모 스코프)
- Rn+1 자식 스코프
- R-in(현재 함수가 호출할 함수)

R(var)=Rn # var의 지역은 Rn
R(var2)=Rn+1 # var2의 지역은 Rn+1
var -> var2 #var 소유권을 var2로 이동

Obj(var) # var는 obj임
!Obj(var) # var는 obj가 아님

# 패턴 A1 - 외부(R-in)에서 객체 변경
fn func(a){ --Obj(a)
	a[2]=100 --
}
fn main(){
	a=[1,2,3,4]
	b=a
	func(a)
}

# 패턴 A1.0 - 상황 추가
fn func(a){ --Obj(a)
	--R1
	a[2]=100 
	{--R2
		b=[100] --
		a[0]=b --
	}
}
fn main(){
	a=[1,2,3,4]
	b=a
	func(a)
}

```
- https://en.wikipedia.org/wiki/Region-based_memory_management

# Explain, Search
## parent가 죽어가는 child를 가질 필요는 있는가?
```cpp
void test() {
    int* ptr_parent; // [Level 1]

    {
        int* ptr_child = pool_alloc(...); // [Level 2] 영역에 할당됨
        
        ptr_child = ptr_parent; // OK. (자식이 부모를 가리키는 건 안전함. 부모가 더 오래 사니까)
        
        ptr_parent = ptr_child; // ERROR! (부모가 자식을 가리킴)
        // [Level 1] 변수에 [Level 2] 객체를 넣으려 함 -> 컴파일 에러 거부
    } 
    // 여기서 ptr_child 영역은 통째로 날아감(Bulk Free).
    // 만약 위에서 에러를 안 냈다면 ptr_parent는 댕글링 포인터가 됨.
}
```
- 아마 없을듯. R2에 child를 선언함 = child는 죽을 객체. parent가 child보다 오래 살아야 함.
- 이거 세계관이 고약하다
# Grammar Design
## Comment
Nim : `#` and `#[ ]#`

## Type name
Rust/etc : type `i8`, `i16`...

## Block style
Ruby, lua : `end` (but not `do`, `then`)

## 

```
struct Rect
	x:f32=0.
	y:f32=0.
	w:f32=0.
	h:f32=0.
	color:i32
end
```
#No Python 

fn 
Rect.Init(10,20)
{rt, cir, poly}.Destroy()



`dsfkasdfkadskf
``
	``dsfadsfasdf``
	fdf
	``asdsfd``
``
struct Rect
	ascent i=0,10
		log('{}{}{}'.format(i,j,k,'{'))
end.struct


Array |x|
	x%2==0
end

a,b=b,a

[10,20,30]
[-1,-2,-3]

3 - 1
3-10

1 -20 -3
1 -20
a -30
a-30
1 - 20

a:i32[10]=[1 2-30 2-13013 30 40 50 -1020 -301 -202 1 -20]
a:[i32*10]

b:[f32*10]

type Rect:[x:f32 y:f32 w:f32 h:f32 color:i32]
impl Rect.Init()
impl Rect.Destroy()


draw.polygon
draw.rect

a:Rect=[x y 10 20 30]
:[i32*10]=
[i32]
[i32 i32]
[i32 f32 f32;no_pading]

=[
	.x:i32=300
	.y:f32=40.
]
type 
	


[.x=10]

[]

a -10 b
3 --10

[1,2,3,4,5]

