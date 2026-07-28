#include <iostream>
#include <string>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"
using namespace std;

// ===== STEP 1: 능력치 출력 함수 (배열을 통째로 받음) =====
void printStatus(string name, int stat[]) {
    cout << "====================================\n";
    cout << "  " << name << "'s Stats\n";
    cout << "====================================\n";
    cout << "HP: " << stat[0] << "    MP: " << stat[1] << "\n";
    cout << "Attack: " << stat[2] << "    Defense: " << stat[3] << "\n";
    cout << "====================================\n";
}

int main() {
    // ===== STEP 1: 변수 / 배열 선언 =====
    const int SIZE = 4;
    int stat[SIZE] = {0};   // stat[0]=HP, [1]=MP, [2]=공격력, [3]=방어력
    string name;

    cout << "===========================================\n";
    cout << "   [ Dungeon Escape Text RPG ]\n";
    cout << "===========================================\n";
    cout << "Enter your hero's name: ";
    getline(cin, name);    // 이름에 공백이 있어도 한 줄 통째로 입력

    // ===== STEP 2: HP/MP 입력 검사 =====
    while (true) {
        cout << "Enter HP and MP: ";
        cin >> stat[0] >> stat[1];
        if (stat[0] > 50 && stat[1] > 50) break;   // 둘 다 50 초과일 때만 통과
        cout << "HP or MP is too low. Try again.\n";
    }

    // ===== STEP 2: 공격력/방어력 입력 검사 =====
    while (true) {
        cout << "Enter Attack and Defense: ";
        cin >> stat[2] >> stat[3];
        if (stat[2] > 0 && stat[3] > 0) break;     // 0 이하이면 재입력
        cout << "Attack or Defense is too low. Try again.\n";
    }
    cout << "\n";
    printStatus(name, stat);

    // ===== STEP 3: 업그레이드 메뉴 =====
    int hpPotion = 5, mpPotion = 5;   // 시작 포션
    bool isGameStart = false;          // 메뉴 루프 종료 플래그
    cout << "\n* You received 5 HP Potions and 5 MP Potions.\n";

    while (!isGameStart) {
        cout << "============================================\n";
        cout << "< Character Upgrade >\n";
        cout << "1. HP UP    2. MP UP    3. Attack x2\n";
        cout << "4. Defense x2  5. Show Stats  0. Start Game\n";
        cout << "============================================\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:     // HP +20, 포션 차감
                if (hpPotion > 0) {
                    stat[0] += 20;
                    hpPotion--;
                    cout << "* HP increased by 20. (HP Potion used: "
                         << hpPotion << " left)\n";
                } else {
                    cout << "* HP 포션이 부족합니다!\n";
                }
                break;
            case 2:     // MP +20, 포션 차감
                if (mpPotion > 0) {
                    stat[1] += 20;
                    mpPotion--;
                    cout << "* MP increased by 20. (MP Potion used: "
                         << mpPotion << " left)\n";
                } else {
                    cout << "* MP 포션이 부족합니다!\n";
                }
                break;
            case 3:     // 공격력 2배
                stat[2] *= 2;
                cout << "* Attack doubled! Attack: " << stat[2] << "\n";
                break;
            case 4:     // 방어력 2배
                stat[3] *= 2;
                cout << "* Defense doubled! Defense: " << stat[3] << "\n";
                break;
            case 5:     // 능력치 확인
                printStatus(name, stat);
                break;
            case 0:     // 게임 시작 -> 루프 탈출
                cout << "Starting the game!\n";
                isGameStart = true;
                break;
            default:
                cout << "잘못된 선택입니다.\n";
        }
    }

    // ===== STEP 4: 직업 선택 + 동적 할당 =====
    Player* player = nullptr;   // 부모 포인터로 자식 객체 가리킴(다형성)

    while (player == nullptr) {
        cout << "\n< Job Selection >\n";
        cout << name << ", choose your job!\n";
        cout << "1. Warrior   2. Mage   3. Rogue   4. Archer\n";
        cout << "Choose: ";
        int job;
        cin >> job;

        // STEP1~3에서 만든 stat[] 값을 Player 생성자로 넘김
        switch (job) {
            case 1:
                player = new Warrior(name, stat[0], stat[1], stat[2], stat[3]);
                break;
            case 2:
                player = new Magician(name, stat[0], stat[1], stat[2], stat[3]);
                break;
            case 3:
                player = new Thief(name, stat[0], stat[1], stat[2], stat[3]);
                break;
            case 4:
                player = new Archer(name, stat[0], stat[1], stat[2], stat[3]);
                break;
            default:
                cout << "잘못된 선택입니다.\n";
        }
    }

    // 가상함수 attack()이 직업별로 다르게 동작 (다형성)
    player->attack();
    player->printPlayerStatus();

    // ===== STEP 5: 1:1 전투 =====
    // 슬라임 HP 30, 공격력 20, 방어력 10
    Monster slime("Slime", 30, 20, 10, "Slime Jelly", 10);

    cout << "\n[ Battle Start! ] " << player->getName()
         << "(" << player->getJob() << ") vs " << slime.getName() << "\n\n";

    // 둘 중 하나라도 HP가 0 이하가 되면 종료
    while (player->getHP() > 0 && slime.getHP() > 0) {
        // --- 플레이어 턴 ---
        cout << "--- Player Turn ---\n";
        player->attack();    // 직업별 메시지

        int dmg = player->getPower() - slime.getDefence();
        if (dmg < 1) dmg = 1;     // 데미지 최소 1 보장

        int beforeHP = slime.getHP();
        slime.setHP(slime.getHP() - dmg);
        cout << dmg << " damage to " << slime.getName() << "!\n";
        cout << slime.getName() << " HP: " << beforeHP << " -> "
             << slime.getHP();
        if (slime.getHP() <= 0) cout << " (Dead)";
        cout << "\n\n";

        if (slime.getHP() <= 0) break;   // 몬스터 사망 시 전투 종료

        // --- 몬스터 턴 ---
        cout << "--- Monster Turn ---\n";
        slime.attack(player);   // 몬스터 행동 메시지

        int mdmg = slime.getPower() - player->getDefence();
        if (mdmg < 1) mdmg = 1;

        int pBefore = player->getHP();
        player->setHP(player->getHP() - mdmg);
        cout << slime.getName() << " deals " << mdmg << " damage!\n";
        cout << player->getName() << " HP: " << pBefore << " -> "
             << player->getHP() << "\n\n";
    }

    // ===== 승패 판정 =====
    if (player->getHP() > 0) {
        cout << "★ Victory!\n";
        cout << "  -> Got: " << slime.getDropItemName() << "!\n";
        cout << "  (Will be saved to inventory in the next STEP)\n";
    } else {
        cout << "★ Defeat...\n";
    }

    // 동적 할당 해제 (가상 소멸자 덕분에 자식 소멸자도 안전 호출됨)
    delete player;
    return 0;
}
