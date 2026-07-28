#include "Player.h"

Player::Player(string name, int hp, int mp, int power, int defence) {
    this->name = name;
    this->hp = hp;
    this->mp = mp;
    this->power = power;
    this->defence = defence;
    this->level = 1;       // 시작 레벨 1
    this->job = "None";   // 자식 클래스가 직업명을 덮어씀
}

void Player::printPlayerStatus() {
    cout << "------------------------------------\n";
    cout << "Name: " << name << " | Job: " << job << " | Lv." << level << "\n";
    cout << "HP: " << hp << " | MP: " << mp
         << " | Attack: " << power << " | Defense: " << defence << "\n";
    cout << "------------------------------------\n";
}
