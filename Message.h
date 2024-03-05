#pragma once
#include <string>

template<typename T>
class Message
{
private:
    T recepient_p;
    T send_p;
    T text_p;

public:
    Message() : recepient_p(T()), send_p(T()), text_p(T()) {}
    Message(const T& recepient, const T& send, const T& text)
        : recepient_p(recepient), send_p(send), text_p(text) {}

    T& getRecepient() { return recepient_p; }
    T& getSend() { return send_p; }
    T& getText() { return text_p; }
};