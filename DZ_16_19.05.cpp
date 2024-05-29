#include <iostream> // библиотека для ввода/вывода
#include <queue> // библиотека для работы с очередями
#include <ctime> // библиотека для работы со временем
#include <locale.h> 

using namespace std; 

// Структура для хранения информации о клиенте
struct Client 
{
    string name; // имя клиента
    int priority; // приоритет
};

// Функция для вывода статистики печати
void printStats(queue<pair<string, time_t>> statsQueue) 
{
    cout << "Статистика печати:" << endl; // вывод заголовка статистики печати
    while (!statsQueue.empty()) // цикл вывода статистики для каждого элемента в очереди
    { 
        char buffer[26]; // буфер для хранения времени в формате строки
        ctime_s(buffer, sizeof(buffer), &statsQueue.front().second); // преобразование времени в строку с использованием безопасной функции ctime_s
        cout << "Пользователь: " << statsQueue.front().first << ", Время: " << buffer; // вывод информации о пользователе и времени
        statsQueue.pop(); // извлечение элемента из очереди
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian"); // установка русской локали

    queue<Client> printQueue; // очередь для запросов на печать
    queue<pair<string, time_t>> statsQueue; // очередь для статистики печати

    printQueue.push({ "Иванов", 2 }); // добавление клиента в очередь печати
    printQueue.push({ "Петров", 1 }); // добавление клиента в очередь печати
    printQueue.push({ "Сидоров", 3 }); // добавление клиента в очередь печати

    while (!printQueue.empty()) // цикл обработки очереди на печать
    { 
        Client currentClient = printQueue.front(); // получение текущего клиента из очереди
        printQueue.pop(); // удаление первого элемента из очереди

        time_t now = time(0); // получение текущего времени
        statsQueue.push({ currentClient.name, now }); // добавление информации о печати в статистику

        cout << "Печать для пользователя " << currentClient.name << " (приоритет " << currentClient.priority << ")..." << endl; // вывод информации о печати
    }

    printStats(statsQueue); // вызов функции для вывода статистики

    return 0;
}