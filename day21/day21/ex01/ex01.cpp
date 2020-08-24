// ex01.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";
    std::cout << "Hi\n";
    // 숫자도 출력가능
    std::cout << 123; // 이러면 개행이 안됌
    std::cout << 3.14  << std::endl; // <<는 입출력 연산자 (c와 다르게 따로 타입을 입력하지 않아도 됌) endl 입력해줘야 개행이 됀다.

    // << 입출력 연산자 계속 사용가능

    std::cout << "hello " << 3.14 << std::endl;  // std는 네임스페이스 (이름공간) 이름구분하는 구분자.

    int a = 1;
    int b = 6;
    std::cout << a << "+" << b << "= " << a + b << std::endl;

    std::cout << "정수를 입력하세요" << std::endl;
    std::cin >> a; //  >> : 입력 연산자
    std::cout << "정수를 입력하세요" << std::endl;
    std::cin >> b;
    std::cout << "a " << "-" << " b " << "= " << a-b << "입니다" << std::endl;

    std::string mystr;
    std::cout << "단어를 입력하세요" << std::endl; // scanf 와 마찬가지로 공백문자 앞까지만 들어감 한줄 전체 입력받는것 불가능


    std::cin >> mystr;

    std::cout << mystr << std::endl;
    rewind(stdin);              // c 와 마찬가지로 입력버퍼 초기화 시켜줘야함.

    std::cout << "문장을 입력하세요 . :";
    getline(std::cin, mystr);   // 한 라인을 받으려면 getline 함수를 사용해야함. 이 함수는 string 헤더에 들어있음.
    std::cout << mystr;
    /*rewind(stdin);*/

    std::cout << "문장을 입력하세요 . :";
    getline(std::cin, mystr);   // 한 라인을 받으려면 getline 함수를 사용해야함. 이 함수는 string 헤더에 들어있음.
    std::cout << mystr;


    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
