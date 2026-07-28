#include "Thief.h"

Thief::Thief(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence) {
    job = "Rogue";
    this->power += 30;               // 도적 특화: 공격력 +30
    cout << "* You became a Rogue! (Attack +30)\n";
}

void Thief::attack() {
    cout << "* Backstabs with daggers!\n";
}
