// 1YBet.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using std::cout; 
using std::endl;
using std::string;
using std::to_string;
using std::advance;
using std::find;
using std::map;
using std::vector;

class Horse {
public:
    CString name, breed;
    int age;
    CString owner, place;
//    Horse() {};

    Horse(CString name, CString breed, int age, CString owner, CString place) :
        name(name), breed(breed), age(age), owner(owner), place(place) {}
};

class Jockey {
public:
    CString sername, first_name, second_name;
    int age;
    Jockey() {};
    Jockey(CString sername, CString first_name, CString second_name, int age) : 
        sername(sername), first_name(first_name), second_name(second_name), age(age) {};
};

class Pair {
public:
    Horse horse;
    Jockey jockey;
    Pair(Horse horse, Jockey jockey) :
        horse(horse), jockey(jockey) {};
    
    bool operator==(const Pair& other) const {
        return horse.name == other.horse.name && jockey.sername == other.jockey.sername;
    }
};

class Race {
public:
    vector<Pair> results;
    CString name;
    int price;
    CString racetrack;
    int day, month, year;
    Race(CString name, int price, CString racetrack, int d, int m, int y) :
        name(name), price(price), racetrack(racetrack), day(d), month(m), year(y){};

    const string displayDate() {
        string str = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        return str;
    };

    void addCompetitors(Horse horse, Jockey jockey) {
        results.push_back({ horse, jockey });
    };

    void replace_to_position(Pair pair, int place) {
        auto iterator = find(results.begin(), results.end(), pair);

        if (iterator != results.end()) {
            advance(iterator, place);
            results.insert(iterator, pair);
            auto iter = find(results.begin(), results.end(), pair); //find first of duped pair and remove it
            results.erase(iter);
        }
        else {
            cout << "Not a valid pair inserted!" << endl;
        };
    };

    void print_list() {
        cout << "Horse | Jockey" << endl;
        for (const auto& r : results) {
            cout << r.horse.name << " | " << r.jockey.sername << endl;
        };
    };
};

Horse most_winner_horse(vector<Race*>& arr) {

    map<CString, int> wordFreq;

    for (const auto& vec : arr) {
        wordFreq[vec->results.front().horse.name]++;
    }

    
    Horse mostFrequent(L"", L"", 0, L"", L"");

    int maxFrequency = 0;
    for (const auto& pair : wordFreq) {
        if (pair.second > maxFrequency) {
            mostFrequent.name = pair.first;
            maxFrequency = pair.second;
        }
    }
    return mostFrequent;
}

Jockey most_winner_jockey(vector<Race*>& arr) {

    map<CString, int> wordFreq;

    for (const auto& vec : arr) {
        wordFreq[vec->results.front().jockey.sername]++;
    }

    Jockey mostFrequent;
    int maxFrequency = 0;
    for (const auto& pair : wordFreq) {
        if (pair.second > maxFrequency) {
            mostFrequent.sername = pair.first;
            maxFrequency = pair.second;
        }
    }
    return mostFrequent;
}

CString most_freq_track(vector<Race*>& arr) {

    map<CString, int> wordFreq;

    for (const auto& vec : arr) {
        wordFreq[vec->racetrack]++;
    }

    CString mostFrequent;
    int maxFrequency = 0;
    for (const auto& pair : wordFreq) {
        if (pair.second > maxFrequency) {
            mostFrequent = pair.first;
            maxFrequency = pair.second;
        }
    }
    return mostFrequent;
};

