#include "Magician.h"

Magician::Magician(string name, int hp, int mp, int power, int defence)
    : Player(name, hp, mp, power, defence) {
    job = "Mage";
    this->mp += 30;                  // 마법사 특화: MP +30
    cout << "* You became a Mage! (MP +30)\n";
}

void Magician::attack() {
    cout << "* Fires a fireball!\n";
}
