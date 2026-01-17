/*
Create an scoped enumeration of monster types named MonsterType.
    Include the following monster types: Dragon, Goblin, Ogre, Orc, Skeleton, Troll, Vampire, and Zombie.
    Add an additional maxMonsterTypes enumerator so we can count how many enumerators there are.

*/

#include <iostream>
#include <string>

#include "random.h"

class Monster {
    public:
        enum Type {
            dragon,
            goblin,
            ogre,
            orc,
            skeleton,
            troll,
            vampire,
            zombie,

            maxMonsterTypes,
        };
    private:
        Type m_type{};
        std::string m_name{"???"};
        std::string m_roar{"???"};
        int m_hitpoints{};

        constexpr std::string_view getTypeString() const {
        switch (m_type) {
            case dragon:
                return "dragon";
            case goblin:
                return "goblin";
            case ogre:
                return "ogre";
            case orc:
                return "orc";
            case skeleton:
                return "skeleton";
            case troll:
                return "troll";
            case vampire:
                return "vampire";
            case zombie:
                return "zombie";
            default:
                return "???";
        }
    }
    
    public:
        Monster(Type type, std::string_view name, std::string_view roar, int hitpoints): m_type {type}, m_name {name}, m_roar {roar}, m_hitpoints {hitpoints} {}
        void print() const {
            std::cout << m_name << " the " << getTypeString();
            if (m_hitpoints <= 0) {
                std::cout << " is dead.\n";
            } else {
                std::cout << " has " << m_hitpoints << " hitpoints and says " << m_roar << ".\n";
            }
        }
};

namespace MonsterGenerator {
    std::string_view getName (int nameNum) {
        switch(nameNum) {
            case 0:
                return "Bones";
            case 1:
                return "Crusty";
            case 2:
                return "Blarg";
            case 3:
                return "Goofy";
            case 4:
                return "Hungry";
            case 5:
                return "Destroyer of Worlds";
            default:
                return "";
        }
    }

    std::string_view getRoar (int roarNum) {
        switch(roarNum) {
            case 0:
                return "*rattle*";
            case 1:
                return "*tonk*";
            case 2:
                return "*rustle*";
            case 3:
                return "*screech*";
            case 4:
                return "*arf arf*";
            case 5:
                return "you will soon crave the sweet release of death";
            default:
                return "";
        }
    }

    Monster generate() {
        return Monster{ static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)), 
                getName(Random::get(0, 5)), 
                getRoar(Random::get(0, 5)),
                Random::get(1, 100)};
    }
}

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}