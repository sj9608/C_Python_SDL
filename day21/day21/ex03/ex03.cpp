// ex03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vect_1;    // integer 형 vector 선언 c에서의 배열과 비슷함.

    std::cout << "maxsize : " << vect_1.max_size() << std::endl; // 할당 받을수 있는 최대 사이즈
    std::cout << "Size : " << vect_1.size() << ", capacity " << vect_1.capacity() << std::endl; // capacity는 실제 메모리 할당량

    vect_1.push_back(1); // 배열에 아무것도 없다고 가정하고 값을 넣을 때는 push_back 사용

    std::cout << "Size : " << vect_1.size() << ", capacity " << vect_1.capacity() << std::endl; // size는 현재 할당받은수

    vect_1.push_back(2);
    vect_1.push_back(3);
    vect_1.push_back(4);
    vect_1.push_back(5);

    std::cout << "Size : " << vect_1.size() << ", capacity " << vect_1.capacity() << std::endl;

    std::cout << vect_1[0] << std::endl;
    std::cout << "use []" << vect_1[1] << std::endl;
    vect_1[0] = 10;
    std::cout << "use at " << vect_1.at(0) << std::endl; // at으로도 값에 접근할 수 있다.

    vect_1.pop_back();      // 벡터는 스택에 저장되기 때문에 가장 마지막 값을 빼낸다.


    // 반복자 순회
    for (auto i = vect_1.begin(); i != vect_1.end(); i++) // iterator 형 (auto) 뜻은 반복자
    {
        std::cout << *i << std::endl;   // 포인터의 한단계 업그레이드버전
    }


    vect_1.insert(vect_1.begin(), 20); // 시작 값에 추가
    vect_1.insert(vect_1.begin()+3, 33); // 특정 위치에 값 추가.
    std::cout << "------------------------------ " << std::endl;

    // 반복자 순회
    for (auto i = vect_1.begin(); i != vect_1.end(); i++) // iterator 형 (auto) 뜻은 반복자
    {
        std::cout << *i << std::endl;   // 포인터의 한단계 업그레이드버전
    }
    std::cout << "------------------------------ " << std::endl;

    vect_1.erase(vect_1.begin()+ 2); // iterator 집어넣어야함 erase함수안에

    // 반복자 순회
    for (auto i = vect_1.begin(); i != vect_1.end(); i++) // iterator 형 (auto) 뜻은 반복자
    {
        std::cout << *i << std::endl;   // 포인터의 한단계 업그레이드버전
    }
    std::cout << "------------------------------ " << std::endl;

    vect_1.erase(vect_1.end()-1); // pop_back 대신 마지막 iterator - 1  넣어줘도 된다.

    // 반복자 순회
    for (auto i = vect_1.begin(); i != vect_1.end(); i++) // iterator 형 (auto) 뜻은 반복자
    {
        std::cout << *i << std::endl;   // 포인터의 한단계 업그레이드버전
    }
    std::cout << "------------------------------ " << std::endl;


    return 0;
}

