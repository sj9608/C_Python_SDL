// ex04.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 

#include <iostream>
#include <vector>

int main()
{
    //int _a1[] = { 7, 4, 9 , 3, 5, 1 };
    std::vector<int> v1;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++) // iterator 형 이 헷갈리면 이렇게 사용해도 된다.
    {
        std::cout << v1[i] << std::endl;
    }
    std::cout << "size : " << v1.size() << ", capacity : " << v1.capacity() << std::endl;
    std::cout << "-----------------------" << std::endl;

    
    v1.resize(5); // 5개로 사이즈 줄이기.

    for (int i = 0; i < v1.size(); i++) 
    {
        std::cout << v1[i] << std::endl;
    }
    std::cout << "size : " << v1.size() << ", capacity : " << v1.capacity() << std::endl;
    std::cout << "-----------------------" << std::endl;

    v1.shrink_to_fit(); // capacity 를 size에 맞게 줄이기.
    std::cout << "size : " << v1.size() << ", capacity : " << v1.capacity() << std::endl;
    
    return 0;
}