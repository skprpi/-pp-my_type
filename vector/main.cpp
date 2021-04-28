#include <iostream>

template <class T>
class vector {
public:
    vector(size_t size): size_(0), capacity(size), data(new T[size]) {}

    // конструктор копирование
    vector(const vector& other) {
        data = new T[other.size() * 2];
        for (int i = 0; i < other.size(); i++) {
            data[i] = other[i];
        }
        size_ = other.size();
        capacity = other.size() * 2;
    }

    // оператор присваивания копированием
    vector& operator= (const vector<T> &other) {
        if (&other == this) {
            return *this;
        }
        // удаляем старое
        delete [] data;
        // записываем новое
        data = new T[other.size() * 2];
        capacity = other.size() * 2;
        size_ = other.size_;
        for (int i = 0; i < other.size(); i++) {
            data[i] = other.data[i];
        }
    }

    // оператор присваивания перемещением
    vector& operator= (vector<T> &&other) {
        if (&other == this) {
            return *this;
        }
        // удаляем старое
        delete [] data;
        // записываем новое
        data = new T[other.size() * 2];
        capacity = other.size() * 2;
        size_ = other.size_;
        for (int i = 0; i < other.size(); i++) {
            data[i] = other.data[i];
        }
    }

    ~vector() {
        delete[]data;
    }

    void push(T value) {
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

    const T& operator[](size_t size) const {
        if (size >= size_) {
            throw "Vector index out of range";
        }
        return data[size];
    }


private:
    size_t size_;
    T *data;
    size_t capacity;

    void relocation() {
        T *new_data = new T[this->size_ * 2];
        for (int i = 0; i < this->size_; i++) {
            new_data[i] = data[i];
        }
        capacity = size_ * 2;
        delete[]data;
        data = new_data;
    }
};

template <typename T>
void show(vector<T> &v1) {
    std::cout << std::endl;
    for (int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    using namespace std;

    vector<int> v1(2);
    v1.push(10);
    show(v1);
    v1.pop();
    show(v1);
    v1.push(20);
    v1.push(30);
    v1.push(40);
    v1.push(50);
    show(v1);
    cout << v1[0] << " " << v1[3] << endl;
    vector<int> v2(v1);
    v2.pop();
    show(v2);
    show(v1);

    vector<string> v3(10);
    v3.push("123");
    v3.push("23 fjodqh uhwuhduh wud uhd4");
    show(v3);

    vector<string> v4 = v3;
    show(v4);
    v4.pop();
    show(v3);
    show(v4);

    return 0;
}

