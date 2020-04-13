#include <iostream>
#include <queue>
#include <Windows.h>

using namespace std;

queue<int> graf;
// Матрица смежности графа 
int arr[5][5] = {
    { 0, 1, 0, 1, 1 },
    { 0, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 1, 0, 1 },
    { 0, 0, 0, 0, 0 },
};

int nodes[5];

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
}
int main()
{   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool alive = true;
    int num;
    
    while (alive) {
        //Завдання (на «відмінно») №1
        cout << "Поиск в ширину нажмите 1" << endl;
        cout << "Поиск в глубину нажмите 2" << endl;
        cout << "Выйти из программы нажмите 3" << endl;
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
            alive = false;
            break;

        default:
            cout << "Что-то пошло не так, пожалуйста попробуйте снова" << endl;
            break;
        }
    }
    return 0;   
}
