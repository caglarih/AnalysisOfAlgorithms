/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 5  *
 ********************/

#include "person.h"
#include <string>

Person::Person(){
}

Person::Person(int a, std::string n, char g){
    age = a;
    name = n;
    gender = g;
}

int Person::getAge(){
    return age;
}

std::string Person::getName(){
    return name;
}

char Person::getGender(){
    return gender;
}

void Person::setAge(int a){
    age = a;
}

void Person::setName(std::string n){
    name = n;
}

void Person::setGender(char g){
    gender = g;
}
