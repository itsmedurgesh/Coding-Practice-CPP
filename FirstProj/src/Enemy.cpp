#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy()
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::setAttackPower(int n){
    attackPower = n;
}

void Ninja::attack(){
    cout<<"ninja attacked with "<<attackPower<<endl;
}

void Ninja::setAttackPower(int n){
    attackPower = 2*n;
}

void Monster::attack(){
    cout<<"Monster attacked with "<<attackPower<<endl;
}

void Monster::attackEat(){
    cout<<"Monster attacked and eaten you "<<endl;
}
