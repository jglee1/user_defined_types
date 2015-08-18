#include <QCoreApplication>
#include <iostream>

using namespace std;

// 2nd change
// 3rd change
// from github

struct Entry {
    string name;
    int number;
};

ostream& operator<<(ostream& os, const Entry& e)
{
    return os << "{\"" << e.name << "\", " <<
           e.number << "}";
}

istream& operator>>(istream& is, Entry& e)
    // read { "name" , number } pair. Note: formatted with { "", and }
{
    char c, c2;
    if (is>>c && c=='{' && is>>c2 && c2=='"') {  // start with a { "
        string name;    // the default value of a string is the empty string: ""
        while (is.get(c) && c!='"')     // anything before a " is part of the name
            name += c;
        if (is>>c && c==',') {
            int number = 0;
            if (is>>number>>c && c=='}') {  // read the number and a }
                e = {name, number};    // assign to the entry
                return is;
            }
         }

     }
   //  is.setf(ios_base::failbit);        // register the failure in the stream
     return is;
}

void read_write()
{
    for (Entry ee; cin>>ee;)        // read from cin into ee
        cout << ee << '\n';         // write ee to cout
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    read_write();

    return a.exec();
}
