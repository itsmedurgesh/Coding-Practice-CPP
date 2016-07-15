#ifndef ENEMY_H
#define ENEMY_H


class Enemy
{
    public:
        Enemy();
        virtual ~Enemy();
        void setAttackPower(int);
        //virtual void attack(){}  //by defining this virtual even pointer to this class will look for attack in subclasses
        virtual void attack() = 0; // this is pure virtual function and subclasses MUST override this.
        // Pure virtual function also makes the class as Abstract Class
    protected:
        int attackPower;
    private:

};

class Ninja: public Enemy{
    public:
        void attack();
        void setAttackPower(int);
};

class Monster: public Enemy{
    public:
        void attack();
        void attackEat();
};

/* this is just a hack as wherever this is called it is pasted over there
* but this avoids the error of multiple definitions
*/
inline void testattack(){
        Ninja n;
        Monster m;
        Enemy *enemy1 = &n;
        Enemy *enemy2 = &m;

        /*
        Enemy e;
        Monster *mons = &e;
        * this assignment is not allowed because every monster is a type of enemy but every enemy is not a type of
        * monster
        */

        enemy1->setAttackPower(20);
        /* even if we override the function the enemy1 pointer is still executing the base class version of the function
        */


        //n.setAttackPower(20);
        enemy2->setAttackPower(12);
        //enemy2->attackEat(); dynamic dispatch not allowed as in Java enemy1 pointer can only access members of Enemy


        //n.attack();
        enemy1->attack();
        m.attack();
    }


#endif // ENEMY_H



