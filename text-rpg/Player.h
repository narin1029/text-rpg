#pragma once              // 같은 헤더가 여러 번 포함되는 것을 막음
#include <string>
#include <iostream>
using namespace std;

class Player {
protected:                 // 자식 클래스(직업)에서 직접 접근 가능
    string name;
    string job;
    int level;
    int hp;
    int mp;
    int power;
    int defence;

public:
    // 생성자: main에서 입력받은 능력치를 받아 멤버 초기화
    Player(string name, int hp, int mp, int power, int defence);

    virtual ~Player() {}   // 가상 소멸자: 자식 객체를 delete할 때 안전하게 해제

    // getter / setter (전투에서 능력치를 읽고 수정할 때 사용)
    string getName()    { return name; }
    string getJob()     { return job; }
    int getHP()         { return hp; }
    int getMP()         { return mp; }
    int getPower()      { return power; }
    int getDefence()    { return defence; }
    void setHP(int h)   { hp = h; }
    void setMP(int m)   { mp = m; }

    virtual void attack() = 0;   // 순수 가상함수: 자식이 반드시 구현해야 함
    void printPlayerStatus();   // 공통 출력 함수
};
