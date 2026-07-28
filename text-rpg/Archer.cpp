#include "Archer.h"

Archer::Archer(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence) {
    job = "Archer";
    this->defence += 30;             // 궁수 특화: 방어력 +30
    cout << "* You became an Archer! (Defense +30)\n";
}

void Archer::attack() {
    cout << "* Shoots an arrow!\n";
}
