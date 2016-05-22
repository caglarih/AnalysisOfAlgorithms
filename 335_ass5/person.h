/*********************
 * İhsan Burak Çağlar*
 *      150120057    *
 *  BLG335E - 11729  *
 *   Assignment - 5  *
 ********************/

#ifndef PERSON_H
#define PERSON_H
#include <string>
class Person{
    int age;
    std::string name;
    char gender;
public:
    int getAge();
    std::string getName();
    char getGender();
    Person();
    Person(int,std::string,char);
    void setAge(int);
    void setName(std::string);
    void setGender(char);
};

#endif // PERSON_H
