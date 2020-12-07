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


    // Part 2
    count = 0;
    std::set<QString> ecl = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
    for (auto passport : passports) {
        if (passport.find("byr") != passport.end()) {
            if (passport["byr"].length() != 4) continue;
            int val = passport["byr"].toInt();
            if (val < 1920 || val > 2002) continue;
        } else {
            continue;
        }

        if (passport.find("iyr") != passport.end()) {
            if (passport["iyr"].trimmed().length() != 4) continue;
            int val = passport["iyr"].toInt();
            if (val < 2010 || val > 2020) continue;
        } else {
            continue;
        }

        if (passport.find("eyr") != passport.end()) {
            if (passport["eyr"].trimmed().length() != 4) continue;
            int val = passport["eyr"].toInt();
            if (val < 2020 || val > 2030) continue;
        } else {
            continue;
        }

        if (passport.find("hgt") != passport.end()) {
            if (passport["hgt"].endsWith("cm")) {
                int val = passport["hgt"].left(passport["hgt"].trimmed().length() - 2).toInt();
                if (val < 150 || val > 193) continue;
            } else if (passport["hgt"].endsWith("in")) {
                int val = passport["hgt"].left(passport["hgt"].trimmed().length() - 2).toInt();
                if (val < 59 || val > 76) continue;
            } else {
                continue;
            }
        } else {
            continue;
        }

        if (passport.find("hcl") != passport.end()) {
            if (!passport["hcl"].startsWith("#") || !(passport["hcl"].length() == 7)) continue;
            bool is_valid = true;
            for (auto i : passport["hcl"].right(6)) {
                if (!i.isDigit() && !(i.toLatin1() >= QChar('a').toLatin1() && i.toLatin1() <= QChar('f').toLatin1())) is_valid = false;
            }
            if (!is_valid) continue;
        } else {
            continue;
        }

        if (passport.find("ecl") != passport.end()) {
            if (ecl.find(passport["ecl"]) == ecl.end()) continue;
        } else {
            continue;
        }

        if (passport.find("pid") != passport.end()) {
            if (!(passport["pid"].length() == 9)) continue;
            bool is_valid = true;
            for (auto i : passport["pid"].trimmed()) {
                if (!i.isDigit()) is_valid = false;
            }
            if (!is_valid) continue;
        } else {
            continue;
        }

        count++;
    }

    std::cout << count << std::endl;
}
