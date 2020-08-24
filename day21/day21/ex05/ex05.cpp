// ex05.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

bool _comapre(int a, int b) // 함수포인터 콜백으로 지정
{
    if (a < b) return true;
    else return false;
}

int main()
{
    std::vector<int> v1;
    v1.push_back(10);
    v1.push_back(9);
    v1.push_back(7);
    v1.push_back(11);
    v1.push_back(3);

   /* std::sort(v1.begin(), v1.end());*/ // sort 함수는 algorithm 헤더에 저장되어 있다. 매개변수로는 영역을 넘겨받음. 시작,끝

    std::sort(v1.begin(), v1.end(), _comapre);
    for(int i=0;i<v1.size();i++)
    {
        std::cout << v1[i] << std::endl;
    }
    return 0;
}