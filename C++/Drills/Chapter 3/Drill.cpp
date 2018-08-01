//read and write a first name
#include "std_lib_facilities.h"

int main()
{
    cout << "Please enter the name of the person you want to write to: \n";
    string first_name;
    cin >> first_name;
    cout << "Please enter a name of a friend: \n";
    string friend_name;
    cin >> friend_name;
    cout << "Please enter gender of friend (Male = m, Female = f): \n";
    char friend_gender = 0;
    cin >> friend_gender;
    cout << "Please enter age of recipient: \n";
    int age = 0;
    cin >> age;
    cout << "Dear " << first_name << ",\n";
    cout << "  How are you? I am fine. I miss you \n";
    cout << "Have you seen " << friend_name << " lately ?\n";
    if (friend_gender == 'm')
    {
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    }

    if (friend_gender == 'f')
    {
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    }
    if (age <= 0)
    {
        simple_error("you're kidding !");
    }
    if (age >= 110)
    {
        simple_error("you're kidding !");
    }
    cout << "I hear you just had a birthday and you are " << age << " years old.\n ";
    if (age < 12)
    {
        cout << "Next year you will be " << age + 1 << "\n";
    }
    if (age == 17)
    {
        cout << "Next year you will be able to vote \n";
    }
    if (age > 70)
    {
        cout << "I hope you are enjoying retirement \n";
    }

    cout << "Yours Sincerely, "
         << "\n"
         << "\n"
         << "Salil Gokhale";
}