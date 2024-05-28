#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Batas maksimal antrian
int front = 0; // indeks awal antrian
int back = 0; // indeks akhir antrian
string queueTeller[maksimalQueue]; // array untuk menyimpan elemen antrian

//Fungsi untuk memeriksa apakah antrian penuh 
bool isFull() { 
    return back == maksimalQueue;
}

//Fungsi untuk memeriksa apakah antrian kosong 
bool isEmpty() { 
    return back == 0;
}

//Fungsi untuk menambahkan elemen ke antrian
void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back] = data;
        back ++;
    }
}

//Fungsi untuk menghapus elemen dari antrian
void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[back - 1] = ""; //membersihkan data terakhir
        back--;
    }
}

//Fungsi untuk menghitung jumlah elemen dalam antrian
int countQueue() { 
    return back;
}

//Fungsi untuk mengosongkan semua elemen dalam antrian
void clearQueue() { 
    for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
    }
    back = 0;
    front = 0;
}


//Fungsi untuk menampilkan semua elemen dalam antrian
void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;

    return 0;
}