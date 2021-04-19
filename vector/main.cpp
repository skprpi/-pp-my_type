#include <iostream>


class vector {
public:
    vector(size_t size): size_(0), capacity(size) {
        data = new int[capacity];
    }

    ~vector() {
        delete[]data;
    }

    void push(int value) {
        if (size_ == capacity) {
            relocation();
        }
        data[size_] = value;
        ++size_;
    }

    void pop() {
        if (empty()) {
            throw "Vector is empty. It seems nothing to `pop()`";
        }
        size_ -= 1;
        data[size_] = NULL;
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

    int at(size_t index) {
        if (index >= size_) {
            throw "Vector index out of range";
        }
        return data[index];
    }


private:
    size_t size_;
    int *data;
    size_t capacity;

    void relocation() {
        int *new_data = new int[this->size_ * 2];
        for (int i = 0; i < this->size_; i++) {
            new_data[i] = data[i];
        }
        capacity = size_ * 2;
        delete[]data;
        data = new_data;
    }
};


void show(vector &v1) {
    std::cout << std::endl;
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1.at(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    using namespace std;

    vector v1(2);
    v1.push(10);
    show(v1);
    v1.pop();
    show(v1);
    v1.push(20);
    v1.push(30);
    v1.push(40);
    v1.push(50);
    show(v1);
//    cout << v1.at(10);
    cout << v1.at(3) << endl;
    cout << v1.at(2) << endl;
    cout << v1.at(0) << endl;

    v1.pop();
    show(v1);
    cout << v1.empty() << endl;
    v1.pop();
    show(v1);
    cout << v1.empty() << endl;
    v1.pop();
    show(v1);
    cout << v1.empty() << endl;
    v1.pop();
    show(v1);
    cout << v1.empty() << endl;


    return 0;
}
