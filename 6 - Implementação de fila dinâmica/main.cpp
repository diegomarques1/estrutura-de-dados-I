// main.cpp
#include <iostream>
#include <clocale>
#include "Queue.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "pt_BR");
    cout << "*** Queue (fila dinâmica usando lista ligada/encadeada) ***\n";

    Queue queue;
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    queue.Enqueue('a');
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    queue.Enqueue('b');
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    queue.Enqueue('c');
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    char temp = queue.Dequeue();
    cout << "Dequeue: " << (temp == '\0' ? '_' : temp) << '\n';
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    queue.Enqueue('d');
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    temp = queue.Dequeue();
    cout << "Dequeue: " << (temp == '\0' ? '_' : temp) << '\n';
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';

    while (!queue.IsEmpty())
    {
        temp = queue.Dequeue();
        cout << "Dequeue: " << (temp == '\0' ? '_' : temp) << '\n';
        cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';
    }

    temp = queue.Dequeue();
    cout << "Dequeue: " << (temp == '\0' ? '_' : temp) << '\n';
    cout << "Front: " << queue.Front() << ", Count: " << queue.Count() << ", ToString: " << queue.ToString() << '\n';
}
