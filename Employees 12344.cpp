#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
    string name;
    int idnum;
    double pay;
    static int total;

public:
    static string company;

    Worker(string name, int idnum, double pay) {
        this->name = name;
        this->idnum = idnum;
        this->pay = pay;
        total++;
    }

    Worker(const Worker& w) {
        this->name = w.name;
        this->idnum = w.idnum;
        this->pay = w.pay;
        total++;
    }

    void showdata() const {
        cout << "--------------------------------------\n";
        cout << "Name: " << this->name << endl;
        cout << "ID: " << this->idnum << endl;
        cout << "Pay: " << this->pay << endl;
        cout << "--------------------------------------\n";
    }

    static void countshow() {
        cout << "Total Workers: " << total << endl;
    }

    void change(string name, int idnum, double pay) {
        this->name = name;
        this->idnum = idnum;
        this->pay = pay;
    }
};

string Worker::company = "BrightTech";
int Worker::total = 0;

void printData(const Worker& w) {
    w.showdata();
}

Worker makeWorker(string n, int i, double p) {
    Worker w(n, i, p);
    return w;
}

int main() {
    cout << "Company: " << Worker::company << endl;

    Worker w1("Ali", 101, 25000);
    Worker w2 = w1;

    cout << "\n--- Worker 1 Info ---\n";
    w1.showdata();

    cout << "\n--- Worker 2 Info (Copied) ---\n";
    w2.showdata();

    w1.change("Sana", 102, 30000);

    cout << "\n--- Worker 1 After Change ---\n";
    w1.showdata();

    cout << "\n--- Worker 2 (Unchanged) ---\n";
    w2.showdata();

    Worker* w3 = new Worker("Hina", 103, 27000);
    cout << "\n--- Worker 3 Info ---\n";
    w3->showdata();
    delete w3;

    cout << "\n--- Pass Object to Function ---\n";
    printData(w1);

    Worker w4 = makeWorker("Rizwan", 104, 32000);
    cout << "\n--- Worker 4 Info ---\n";
    w4.showdata();

    Worker::countshow();

    return 0;
}
