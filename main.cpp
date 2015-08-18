#include <QCoreApplication>
#include <iostream>

using namespace std;

struct Entry {
    string name;
    int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
    return os << "{\"" << e.name << "\", " <<
           e.number << "}";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
