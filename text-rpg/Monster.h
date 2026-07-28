#pragma once
#include <string>
class Player;   // 전방 선언: Player 전체 정의 없이 포인터만 쓰기 위해

class Monster {
private:
    std::string name;
    int hp;
    int power;
    int defence;
    std::string dropItemName;
    int dropItemPrice;

public:
    Monster(std::string name, int hp, int power, int defence,
            std::string dropItemName, int dropItemPrice);

    std::string getName()          { return name; }
    int getHP()               { return hp; }
    int getPower()            { return power; }
    int getDefence()          { return defence; }
    std::string getDropItemName()  { return dropItemName; }
    int getDropItemPrice()    { return dropItemPrice; }
    void setHP(int h)         { hp = h; }

    void attack(Player* player);   // 몬스터의 공격 행동(메시지 출력)
};
