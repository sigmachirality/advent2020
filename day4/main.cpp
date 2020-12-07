#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

#include <vector>
#include <map>
#include <set>
#include <iostream>

int main(int argc, char *argv[])
{
    QFile file("C:/Users/ArceusDrago/Desktop/advent/day4/day4.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    std::vector<std::map<QString, QString>> passports;
    std::map<QString, QString> curr_passport;
    while (!file.atEnd()) {
        QString line = file.readLine();
        if (line.trimmed().isEmpty()) {
            passports.push_back(std::map<QString, QString>(curr_passport));
            curr_passport = std::map<QString, QString>();
        } else {
            QStringList tokens = line.split(" ");
            for (auto token : tokens) {
                QStringList value_pair = token.split(":");
                curr_passport[value_pair[0]] = value_pair[1].trimmed();
            }
        }
    }
    passports.push_back(curr_passport);

    // Part 1
    uint count = 0;
    for (auto passport : passports) {
        if (passport.size() == 8 || (passport.size() == 7 && passport.find("cid") == passport.end())) {
            count++;
        }
    }
    std::cout << count << std::endl;


    std::cout << count << std::endl;
}
