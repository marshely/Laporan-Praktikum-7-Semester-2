#include <iostream>

using namespace std;

// Definisi Node untuk linked list
struct Node {
    string data;
    Node* next;

    Node(string data) : data(data), next(nullptr) {}
};

class Queue {
private:
    Node* front; // Node depan antrian
    Node* rear;  // Node belakang antrian

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Fungsi untuk menambahkan elemen ke dalam antrian
    void enqueue(string data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Fungsi untuk menghapus elemen dari antrian
    void dequeue() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        }
    }

    // Fungsi untuk memeriksa apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Fungsi untuk menampilkan semua elemen dalam antrian
    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        cout << "Data dalam antrian:" << endl;
        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // Fungsi untuk menghapus semua elemen dalam antrian
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue("Andi");
    myQueue.enqueue("Maya");
    myQueue.display();

    myQueue.dequeue();
    myQueue.display();

    myQueue.clear();
    myQueue.display();

    return 0;
}

