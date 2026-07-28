#include "Monster.h"
#include "Player.h"
#include <iostream>
using namespace std;

Monster::Monster(string name, int hp, int power, int defence,
                 string dropItemName, int dropItemPrice) {
    this->name = name;
    this->hp = hp;
    this->power = power;
    this->defence = defence;
    this->dropItemName = dropItemName;
    this->dropItemPrice = dropItemPrice;
}

// 실제 데미지 계산은 main에서 하고, 여기는 행동 메시지만 출력
void Monster::attack(Player* player) {
    cout << name << " lunges at " << player->getName() << "!\n";
}
