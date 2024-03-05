#include<iostream>
#include<string>
#include"Hello.h"
#include"User.h"
#include"Message.h"
using namespace std;


//������ ��������� 
template<typename T>
class Memory {
private:
    int size;
    T* data;
    int i;
public:
    Memory()
    {
        size = 1;
        data = new T[size];
        i = 0;
    };
    ~Memory()
    {
        delete[] data;
    };

    void AddSms(const T& value)
    {
        if (i < size)
        {
            data[i] = value;
            ++i;
        }
        else
        {
            int newSize = size * 2;
            T* newData = new T[newSize];
            for (int j = 0; j < size; j++)
            {
                newData[j] = data[j];
            }

            newData[i] = value;
            ++i;
            delete[] data;
            data = newData;
            size = newSize;
        };
    };

    void Display()
    {
        for (int f = 0; f < i; f++)
        {
            cout << "� ���� ���� ���������!!! ����:  " << data[f].getRecepient() << ". �� ����: " << data[f].getSend() << endl;
            cout << "c��������: " << "'" << data[f].getText() << "'" << endl;
        };

    };


};






//������ ������
template<typename U>
class MemoryUser
{
private:
    int size1;
    U* data1;
    int j;
public:
    MemoryUser()
    {
        size1 = 1;
        j = 0;
        data1 = new U[size1];
    };

    ~MemoryUser()
    {
        delete[] data1;
    };

    int getSize1()
    {
        return j; // ���������� ����������� �������������,
    };

    U* getUser(int index) {
        // �������� �� ����������� ��������� � ��������� �������� ������
        if (index < 0 || index >= j) {
            return nullptr;
        }
        return &data1[index];
    }

    void AddUsers(const U& value)
    {
        if (j >= size1)
        {
            // ����������� ������ �������
            int newSize1 = size1 * 2;
            U* newData1 = new U[newSize1];
            for (int t = 0; t < size1; t++)
            {
                newData1[t] = data1[t];
            }

            delete[] data1; // ������� ������ ������
            data1 = newData1;
            size1 = newSize1;
        }

        // ������, ����� � ��� ���� ��������� �����, ��������� ����� �������
        data1[j++] = value;

    };
};



class Chat
{
    Memory<Message<string>> messages; // �������� ���� ������
public:
    void sendMessage(const string& recepient, const string& send, const string& text)
    { // ������ ������ ������� ������ � ���������
        Message<string> message1(recepient, send, text); // �������� � ������

        messages.AddSms(message1);
    }

    void DisplayMessages()
    {
        messages.Display();
    }
};





int main()
{
    system("chcp 1251");
    hello();


    MemoryUser<User<string>> Tolpa;
    //User Noubody;
    User<string>* currentUser = nullptr;


    cout << "�����������\n";
    string username, password;
    cout << "������� �����: " << endl;
    cin >> username;
    cout << "������� ������: " << endl;
    cin >> password;
    User<string> First(username, password);
    Tolpa.AddUsers(First);
    cout << "�� ������� ������������������!������ ������� � �������." << endl;

    cout << " \n";
    cout << "�������� ��������:\n ";

    cout << "1. ������� ���������\n";

    cout << "2. ����� � ������������ �������\n";

    cout << "3. ������� ����� �������\n";

    cout << "4. ����� �� ��������\n";

    cout << "5. ���������\n";

    cout << " \n";

    cout << "� ���������� ����������� ����� ��������" << endl;
    int choice;

    Chat chat;
    do {
        cin >> choice;
        switch (choice)
        {///////////
            {case 1:
                if (currentUser != nullptr) { // ������ ���� ������������ �����
                    string recipient, text;
                    cout << "������� ����������: ";
                    cin >> recipient;
                    cout << "������� ����� ���������: ";
                    cin.ignore();
                    getline(cin, text);

                    chat.sendMessage(recipient, currentUser->getName(), text);
                    cout << "��������� ����������!\n";
                    cout << " \n";
                    cout << " \n";
                }
                else {
                    cout << "�� �� ����� � �������. ������� ������� � ���� ������� ����� 2.\n";
                }
                break;
            }


            {case 2:
                cout << "���� � ������������ �������\n" << endl;
                string username1, password1;
                cout << "������� �����: " << endl;
                cin >> username1;
                cout << "������� ������: " << endl;
                cin >> password1;

                for (int k = 0; k < Tolpa.getSize1(); k++) {
                    User<string>* user = Tolpa.getUser(k); // �������� ��������� �� ������������
                    if (user != nullptr && user->getName() == username1 && user->getPassword() == password1) {
                        currentUser = user; // ������������� currentUser ��������
                        cout << "�� ������� ����� � �������!" << endl;
                        chat.DisplayMessages();
                        break;
                    }
                }
                if (currentUser == nullptr) {
                    cout << "������������ ����� ��� ������." << endl;
                }
                break;
            }



            {case 3:
                cout << "�����������\n";
                cout << "������� �����: " << endl;
                cin >> username;
                cout << "������� ������: " << endl;
                cin >> password;
                User<string> newUser(username, password);
                Tolpa.AddUsers(newUser);
                currentUser = Tolpa.getUser(Tolpa.getSize1() - 1); // ���������� ������������ ���������
                cout << "�� ������� ������������������!" << endl;
                cout << "  " << endl;
                //if (currentUser != nullptr) { // �������� �� nullptr
                //    chat.DisplayMessages();
                //}
                break;
            }

            {case 4:
                currentUser = nullptr; // ������������� currentUser � nullptr ��� ������
                cout << "����� ��������. ������� � ������������ ������� ����� 2 ��� ����������������� ����� 3\n";
                cout << " \n";
                cout << " \n";
                break;
            }

            {case 5:

                cout << "�� ��������� ������� ����� �� ����\n";
                cout << "� ������� ��� ������ ����� �������� ��� �������\n";
                cout << "� ���� - ��� ������ ������� ������" << endl;
                break;
            }



        default:
            cout << "�� ����� ������������ ��������" << endl;
            break;

        };//////

    } while (choice != 5);

    return 0;
}
