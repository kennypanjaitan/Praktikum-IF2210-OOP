#include <iostream>

using namespace std;

class Hewan {
    public:
        Hewan(string name) {
            nama = name;
        }
        ~Hewan() {
            cout << "Hewan mati " << nama << endl;
        }
        virtual void print() {
            cout << "Hewan ini namanya " << nama << endl;
        }

    protected:
        string nama;
};

class Kucing : public Hewan {
    public:
        Kucing(string nama) : Hewan(nama) {};
        virtual ~Kucing() {
            cout << "Kucing mati " << nama << endl;
        }
};

class KucingAnggora : public Kucing {
    public:
        KucingAnggora(string nama, string pemilik) : Kucing(nama) {
            this->pemilik = pemilik;
        }
        ~KucingAnggora() {
            cout << "Kucing anggora mati " << nama << endl;
        }
        void print() {
            cout << "Kucing anggora ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
        }

    private:
        string pemilik;
};

class Anjing : public Hewan {
    public:
        Anjing(string nama) : Hewan(nama) {}
        ~Anjing() {
            cout << "Anjing mati " << nama << endl;
        }
        void print() {
            cout << "Anjing ini namanya " << nama << endl;
        }
};

class AnjingBulldog : public Anjing {
    public:
        AnjingBulldog(string nama, string pemilik) : Anjing(nama) {
            this->pemilik = pemilik;
        }
        ~AnjingBulldog() {
            cout << "Anjing bulldog mati " << nama << endl;
        }
        void print() {
            cout << "Anjing bulldog ini namanya " << nama << ". Pemiliknya adalah " << pemilik << endl;
        }

    private:
        string pemilik;
};