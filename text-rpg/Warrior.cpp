#include "Warrior.h"

// 부모 생성자 호출 후 직업별 세팅
Warrior::Warrior(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence) {
    job = "Warrior";
    this->hp += 30;                  // 전사 특화: HP +30
    cout << "* You became a Warrior! (HP +30)\n";
}

void Warrior::attack() {
    cout << "* Swings a greatsword!\n";
}
