#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <Windows.h>
#undef max

// simple program to add and delete info about trains
struct Train {
    int trainNumber; // номер поезда
    std::string destination; // станция назначения
    std::string departureTime; // время отправления
};

class TrainInfoSystem {
private:
    struct Node {
        Train train;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* insertTrain(Node* node, const Train& train) {
        if (node == nullptr) {
            node = new Node;
            node->train = train;
            node->left = node->right = nullptr;
            return node;
        }

        if (train.trainNumber < node->train.trainNumber) {
            node->left = insertTrain(node->left, train);
        } else if (train.trainNumber > node->train.trainNumber) {
            node->right = insertTrain(node->right, train);
        }

        return node;
    }

    void printTrains(Node* node) {
        if (node == nullptr) {
            return;
        }

        printTrains(node->left);
        std::cout << "Номер поезда: " << node->train.trainNumber << ", Пункт назначения: " << node->train.destination << ", Время отправления: " << node->train.departureTime << std::endl;
        printTrains(node->right);
    }

    Node* search(Node* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->train.trainNumber < key) {
            return search(root->right, key);
        }
        if (root->train.trainNumber > key) {
            return search(root->left, key);
        }
        return root;
    }

    void searchByDestination(Node* node, const std::string& destination, std::vector<Node*>& result) {
        if (node == nullptr) {
            return;
        }

        searchByDestination(node->left, destination, result);
        if (node->train.destination == destination) {
            result.push_back(node);
        }
        searchByDestination(node->right, destination, result);
    }

public:
    TrainInfoSystem() : root(nullptr) {}

    void addTrain(const Train& train) {
        root = insertTrain(root, train);
    }

    void displayTrains() {
        printTrains(root);
    }

    void searchTrain(int key) {
        Node* node = search(root, key);
        if (node != nullptr) {
            std::cout << "Номер поезда: " << node->train.trainNumber << ", Пункт назначения: " << node->train.destination << ", Время отправления: " << node->train.departureTime << std::endl;
        } else {
            std::cout << "Поезд не найден" << std::endl;
        }
    }

    void searchByDestination(const std::string& destination) {
        std::vector<Node*> result;
        searchByDestination(root, destination, result);
        if (result.empty()) {
            std::cout << "Поезда по данному направлению не найдены: " << destination << std::endl;
        } else {
            for (const auto& node : result) {
                std::cout << "Номер поезда: " << node->train.trainNumber << ", Пункт назначения: " << node->train.destination << ", Время отправления: " << node->train.departureTime << std::endl;
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TrainInfoSystem trainSystem;

    Train train1 = {101, "Москва", "08:00"};
    Train train2 = {205, "Санкт-Петербург", "12:30"};
    Train train3 = {150, "Новосибирск", "18:45"};

    trainSystem.addTrain(train1);
    trainSystem.addTrain(train2);
    trainSystem.addTrain(train3);
    int choice;
    Train train;
    while (true) {
        std::cout << "Система информации о поездах" << std::endl;
        std::cout << "1. Добавить поезд" << std::endl;
        std::cout << "2. Отобразить список поездов" << std::endl;
        std::cout << "3. Найти поезд по номеру" << std::endl;
        std::cout << "4. Найти поезд по пункту назначения" << std::endl;
        std::cout << "5. Выход" << std::endl;
        std::cout << "Введите пункт меню: ";
        if (!(std::cin >> choice)) {
            std::cout << "Неверно введен пункт меню!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case 1: {
            std::cout << "Введите номер поезда: ";
            if (!(std::cin >> train.trainNumber) || typeid(train.trainNumber) != typeid(int)) {
                std::cout << "Неверный номер поезда!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Введите пункт назначения: ";
            std::string destination;
            if (!(std::cin >> train.destination) || typeid(train.destination) != typeid(std::string)) {
                std::cout << "Неверный пункт назначения!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            std::cout << "Введите время отправления: ";
            if (!(std::cin >> train.departureTime)) {
                std::cout << "Неверное время отправления!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            trainSystem.addTrain(train);
            break;
        }
        case 2: {
            std::cout << "Информация о поездах:" << std::endl;
            trainSystem.displayTrains();
            break;
        }
        case 3: {
            std::cout << "Введите номер поезда: ";
            int trainNumber;
            if (!(std::cin >> trainNumber) || (typeid(trainNumber) != typeid(int))) {
                std::cout << "Неверный номер поезда!" << std::endl;
                std::cin.clear();
                continue;
            }
            trainSystem.searchTrain(trainNumber);
            break;
        }
        case 4: {
            std::cout << "Введите пункт назначения: ";
            std::string destination;
            if (!(std::cin >> destination) || typeid(destination) != typeid(std::string)) {
                std::cout << "Неверный пункт назначения!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            trainSystem.searchByDestination(destination);
            break;
        }
        case 5: {
            return 0;
        }
        default: {
            std::cout << "Неверно введен пункт меню!" << std::endl;
            break;
        }
        }
    }

    return 0;

}
