#include <iostream>
#include <string>

using namespace std;

// Definisi Node untuk linked list
struct Node {
  string nama;
  string nim;
  Node* next;

  Node(string nama, string nim) : nama(nama), nim(nim), next(nullptr) {}
};

class Queue {
private:
  Node* front; // Node depan antrian
  Node* rear;  // Node belakang antrian

public:
  Queue() : front(nullptr), rear(nullptr) {}

  // Fungsi untuk menambahkan elemen ke dalam antrian
  void enqueue(string nama, string nim) {
    Node* newNode = new Node(nama, nim);
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
      cout << "Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
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

  int choice; // Variabel untuk pilihan menu
  string nama, nim; // Variabel untuk nama dan NIM mahasiswa

  do {
    cout << "\nMenu Antrian Mahasiswa:" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Hapus Data Mahasiswa Terdepan" << endl;
    cout << "3. Hapus Semua Data" << endl;
    cout << "4. Tampilkan Data" << endl;
    cout << "5. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch (choice) {
      case 1: // Menambahkan data mahasiswa
        cout << "Masukkan nama mahasiswa: ";
        cin >> nama;
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;
        myQueue.enqueue(nama, nim);
        cout << "Data mahasiswa " << nama << " dengan NIM " << nim << " berhasil ditambahkan!" << endl;
        break;

      case 2: // Menghapus data mahasiswa terdepan
        if (myQueue.isEmpty()) {
          cout << "Antrian kosong!" << endl;
        } else {
          myQueue.dequeue();
          cout << "Data mahasiswa terdepan telah dihapus!" << endl;
        }
        break;

      case 3: // Menghapus semua data
        myQueue.clear();
        cout << "Semua data dalam antrian telah dihapus!" << endl;
        break;

      case 4: // Menampilkan data
        myQueue.display();
        break;

      case 5: // Keluar dari program
        cout << "Terima kasih telah menggunakan program antrian mahasiswa!" << endl;
        break;

      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (choice != 5); // Looping menu hingga memilih keluar (5)

  return 0;
}