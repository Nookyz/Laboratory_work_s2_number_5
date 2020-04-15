#include <iostream>
#include <queue> // очередь
#include <stack> // стек
#include <Windows.h>

using namespace std;

queue<int> graf;
const int m = 100;

struct Edge {
    int begin;
    int end;
};
// Матрица смежности графа 
int arr[5][5] = {
    { 0, 1, 0, 1, 1 },
    { 0, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 0 },
};

int nodes[5];

void task2(int arr[5][5]) {
    // Задача поиска кратчайшего пути
    queue<int> Queue;
    stack<Edge> Edges;
    int req;
    Edge e;

    cout << "N = "; 
    cin >> req; 
    req--;

    Queue.push(0); // поміщаємо в чергу першу вершину
    while (!Queue.empty())
    {
        int node = Queue.front(); // здобуваємо вершину
        Queue.pop();
        nodes[node] = 2; // відмічаємо як відвідану
        for (int j = 0; j < 5; j++)
        {
            if (arr[node][j] == 1 && nodes[j] == 0) // якщо вершина суміжна та не знайдена
            {
                Queue.push(j); // додаємо її в чергу
                nodes[j] = 1; // відмічаємо вершину як знайдену
                e.begin = node; e.end = j;
                Edges.push(e);
                if (node == req) break;
            }
        }
        cout << node + 1 << endl; // виводимо номер вершини
    }
    cout << "Шлях до вершини " << req + 1 << endl;
    cout << req + 1;
    while (!Edges.empty()) {
        e = Edges.top();
        Edges.pop();
        if (e.end == req) {
            req = e.begin;
            cout << " <- " << req + 1;
        }
    }
    cin.get();
    cout << endl;
}

bool check(int arr[][m], int size) {
    for (int i = 0; i < size; ++i){
        for (int j = 0; j < size; ++j){
            if (arr[i][j] == arr[j][i] && i != j){
                continue;
            }
            else {
                if (arr[i][j] != arr[j][i]){
                    return false;
                }
                else{
                    if (i == j){
                        if (arr[i][j] == 0 && arr[j][i] == 0){}
                        else{
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void task3() {
    int mainSize = 5;
    int matrix[m][m];
    for (int i = 0; i < mainSize; ++i)
    {
        for (int j = 0; j < mainSize; ++j)
        {
            matrix[i][j] = arr[i][j];
        }
    }
    if (check(matrix, mainSize)){
        cout << "Графа  содержит петели";
    }
    else{
        cout << "Графа не содержит петель";
    }
    cout << endl;
}
    

void wideSearch(int st, int n) {
    // Поиск в ширину
    graf.push(0);

    while (!graf.empty())
    {
        st = graf.front();
        graf.pop();
        nodes[st] = 2;
        for (int j = 0; j < n; j++)
        {
            if (arr[st][j] == 1 && nodes[j] == 0)
            {
                graf.push(j);
                nodes[j] = 1;
            }
        }
        cout << st + 1 << endl;
    }
    cin.get();
    cout << endl;
}
void deepSearch(int st, int n) {
    // Поиск в глубину
    // обхода графа в глубину с использованием рекурсии
    cout << st + 1 << endl;
    nodes[st] = 1;
    for (int i = 0; i < n; i++) {
        if ((arr[st][i] != 0) && (nodes[i] == 0)) {
            deepSearch(i, n);
        }
    }
    cout << endl;
}
int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool alive = true;
    int num;
    
    while (alive) {
        //Завдання (на «відмінно») №1
        
        cout << "Поиск в ширину (задание 1), нажмите 1" << endl;
        cout << "Поиск в глубину (задание 1), нажмите 2" << endl;
        cout << "Задача поиска кратчайшего пути (задание 2), нажмите 3" << endl;
        cout << "Cодержит ли граф петли (задание 3), нажмите 4" << endl;
        cout << "Очистить консоль, нажмите 5" << endl;
        cout << "Выйти из программы, нажмите 6" << endl;
        cin >> num;
        cout << endl;
        for (int i = 0; i < 5; i++) {
            nodes[i] = 0;               // исходно все вершины равны 0
        }
        switch (num) {
        case 1:
            // Поиск в ширину
            wideSearch(0, 5);
            break;
        case 2:
            // Поиск в глубину
            deepSearch(0, 5);
            break;
        case 3:
            // Пошуку шляху від вершини 1 до вершини 5,
            task2(arr);
            break;
        case 4:
            // Cодержит ли граф петли
            task3();
            break;
        case 5:
            system("cls");
            break;
        case 6: 
            alive = false;
            break;

        default:
            cout << "Что-то пошло не так, пожалуйста попробуйте снова" << endl;
            cout << endl;
            break;
        }
        
    }
    return 0;   
}
