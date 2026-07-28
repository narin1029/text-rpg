#pragma once
#include "Player.h"

class Warrior : public Player {     // Player 상속
public:
    Warrior(string name, int hp, int mp, int power, int defence);
    void attack() override;          // 순수 가상함수 오버라이딩
};
