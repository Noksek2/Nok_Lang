# N++ Language Introduction

## What is N++?

N++ is a programming language that transpiles to C++.<br>
for beginner Compiler Developer like me.

## 🎯 Goals

- Testing & Learning: Developed primarily for testing language implementation concepts and for learning purposes.

- High Compatibility: Aims for high compatibility with C/C++, allowing existing C/C++ code to be used almost as-is.

- Development Aid: Intended to serve as a helper tool to improve convenience and productivity for C/C++ developers.

- Lightweight Implementation: To implement a lightweight compiler (transpiler).

- No Separate Library: Aims to avoid dependencies on a separate runtime library (if possible).

## ✍️ Syntax Features

- C/C++ Based Style: Follows the C/C++ syntax style closely while adding some corrections and convenience features.
   - Example: Optional semicolons (;) or commas (,) in certain contexts.

    Custom Features: Adds unique features distinct from existing languages based on the developer's preferences.

        Example: Enhanced support for procedural programming, expanded macro capabilities, and configurable syntax styles.

    Memory Management:

        Relies on direct memory management using pointers and smart pointers, identical to C/C++.

        No GC Support: There are currently no plans to support garbage collection (GC).

            Reasoning: This is due to the developer's current implementation limitations, the risk of reduced C/C++ compatibility, and the resulting management complexity.

        Future: Some limited, partial automated memory management features might be introduced as development knowledge grows, but a fully managed model (like in Java or C#) is not being considered.

## 🛠️ Implementation

    The N++ transpiler itself is written in C/C++.




## N++란 무엇인가?

N++는 C++ 코드로 번역되는 트랜스파일(transpile) 언어입니다.
컴파일러 개발 입문자(본인)를 위한 언어입니다. 

## 🎯 목표

    테스트 용도: 언어 구현 테스트 및 학습 목적으로 개발되었습니다.

    높은 C/C++ 호환성: 기존 C/C++ 코드와 높은 호환성을 가지며, 코드를 거의 그대로 사용하는 것을 목표로 합니다.

    C/C++ 개발 보조: C/C++ 개발 시 편의성을 높이고 생산성을 보조하는 것을 목적으로 합니다.

    경량 구현: 가벼운 컴파일러(트랜스파일러) 구현을 지향합니다.

    라이브러리 독립성: (가능한 한) 별도의 런타임 라이브러리를 사용하지 않습니다.

## ✍️ 문법적 특징

    C/C++ 기반 스타일: C/C++의 문법 스타일을 거의 그대로 따르면서, 일부 편의 기능을 추가하고 문법을 보정합니다.

        예시: 특정 상황에서 세미콜론(;)이나 콤마(,) 생략 허용.

    독자적인 기능 추가: 개인적으로 원하는 기능 및 기존 언어와 차별화되는 N++ 고유의 기능을 추가합니다.

        예시: 절차지향적 코드 스타일 지원, 확장된 매크로 기능, 사용자 설정 가능한 일부 문법 스타일.

    메모리 관리:

        C/C++와 동일하게 포인터 및 스마트 포인터를 사용한 직접적인 메모리 관리를 기본으로 합니다.

        GC (Garbage Collection) 미지원: 현재로서는 GC를 지원할 계획이 없습니다.

            이유: 개발자의 구현 역량 부족, C/C++ 호환성 저하, 관리 복잡성 증가 등의 문제가 있습니다.

        추후 계획: 향후 개발 지식이 축적되면 일부 제한적인 자동 메모리 관리 기능이 도입될 수 있으나, Java나 C#과 같은 완전한 관리형 메모리 모델은 고려하지 않습니다.

## 🛠️ 구현체

    N++ 트랜스파일러 자체는 **C/C++**로 작성되었습니다.

## 기능
언어 자체보다는 개발 편이를 위한 기능을 지원할 예정입니다.<br>
기존 C/C++은 방대한 문법 및 불편한 점으로 개발자/입문자가 지치기 마련이기 때문입니다. <br>

- (C/C++ 컴파일러는 고칠 수 없으니) 즉각적이고 빠른 파싱 및 코드 변환
- 전처리
- 오류 메세지
- 빌드 환경 및 패키지 관리
