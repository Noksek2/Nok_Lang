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

```

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

