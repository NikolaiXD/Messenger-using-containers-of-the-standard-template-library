#pragma once
#include <string>

template<typename T>
class User
{
private:
    T name_p;
    T password_p;

public:
    User() : name_p(T()), password_p(T()) {}
    User(const T& name, const T& password) : name_p(name), password_p(password) {}

    T& getName() { return name_p; }
    T& getPassword() { return password_p; }
};