#ifndef ORDEREDSET_H
#define ORDEREDSET_H
#include <iostream> /// Alex

template <typename T>
using Comparator = bool(*)(const T&, const T&);

template<typename T>
class OrderedSet {
private:
    T* elems;        // Array with elems
    int nrElems;     // Nr of elems
    int capacity;    // Capacity of array
    Comparator<T> cmp;  // Compare function for T type elems

    void resize(); // Resize the array
    int search(const T& elem) const;

public:
    OrderedSet(T* arr, int size, int cap);
    OrderedSet();
    OrderedSet(Comparator<T> cmpFunction);
    OrderedSet(const OrderedSet& other);
    OrderedSet& operator=(const OrderedSet& other);
    ~OrderedSet();

    int size() const;
    T getElem(int pos) const;
    void add(const T& elem);
    void remove(const T& elem);
    void update(const T& elem);
    bool ifExist(const T& elem) const;

    void setComparator(Comparator<T> newCmp);
};

// Implementation of the template functions

template<typename T>
void OrderedSet<T>::resize() {
    this->capacity *= 2;
    T* temp = new T[this->capacity];
    for (int i = 0; i < this->nrElems; i++) {
        temp[i] = this->elems[i];
    }
    delete[] this->elems;
    this->elems = temp;
}

template<typename T>
int OrderedSet<T>::search(const T& elem) const {
    int st = 0, dr = nrElems - 1;
    while (st <= dr) {
        int m = (st + dr) / 2;
        if (!cmp(this->elems[m], elem) && !cmp(elem, this->elems[m])) {
            return m;  // element found at position m
        }
        if (cmp(this->elems[m], elem)) {
            st = m + 1;
        }
        else {
            dr = m - 1;
        }
    }
    return st;  // return position where element should be inserted if not present
}

template<typename T>
OrderedSet<T>::OrderedSet(T* arr, int size, int cap) {
    this->capacity = cap;
    this->nrElems = size;
    this->elems = new T[capacity];

    for (int i = 0; i < nrElems; i++) {
        this->elems[i] = arr[i];
    }

    // Implicit comparator (ascending order)
    this->cmp = [](const T& a, const T& b) -> bool { return a < b; };
}

template<typename T>
OrderedSet<T>::OrderedSet() {
    this->capacity = 10;
    this->nrElems = 0;
    this->elems = new T[capacity];

    // Default comparator (ascending order)
    this->cmp = [](const T& a, const T& b) -> bool { return a < b; };
}

template<typename T>
OrderedSet<T>::OrderedSet(Comparator<T> cmpFunction) {
    this->capacity = 10;
    this->nrElems = 0;
    this->elems = new T[this->capacity];
    this->cmp = cmpFunction;
}

template<typename T>
OrderedSet<T>::OrderedSet(const OrderedSet& other) {  // Copy constructor
    this->capacity = other.capacity;
    this->nrElems = other.nrElems;
    this->elems = new T[this->capacity];
    for (int i = 0; i < this->nrElems; i++) {
        this->elems[i] = other.elems[i];
    }
    this->cmp = other.cmp;
}

template<typename T>
OrderedSet<T>::~OrderedSet() {  // Destructor
    delete[] this->elems;
}

template<typename T>
int OrderedSet<T>::size() const {
    return this->nrElems;
}

template<typename T>
T OrderedSet<T>::getElem(int pos) const {
    if (pos < 0 || pos >= this->nrElems) {
        return T();  // return default value if position is out of bounds
    }
    return this->elems[pos];
}

template<typename T>
bool OrderedSet<T>::ifExist(const T& elem) const {
    int pos = search(elem);
    return (pos < this->nrElems && !cmp(this->elems[pos], elem) && !cmp(elem, this->elems[pos]));  // if not a < b and not b < a => a == b
}

template<typename T>
void OrderedSet<T>::add(const T& elem) {
    if (ifExist(elem)) return;
    if (this->nrElems == capacity)
        resize();
    int pos = search(elem);
    for (int i = this->nrElems; i > pos; i--) {
        this->elems[i] = this->elems[i - 1];
    }
    this->elems[pos] = elem;
    this->nrElems++;
}

template<typename T>
void OrderedSet<T>::remove(const T& elem) {
    if (!ifExist(elem)) return;
    int pos = search(elem);
    for (int i = pos; i < this->nrElems - 1; i++) {
        this->elems[i] = this->elems[i + 1];
    }
    this->nrElems--;
}

template<typename T>
void OrderedSet<T>::update(const T& elem) {
    if (!ifExist(elem)) return;
    remove(elem);  // delete the old element
    add(elem);     // add the updated element
}

template<typename T>
OrderedSet<T>& OrderedSet<T>::operator=(const OrderedSet& other) {
    if (this != &other) {
        delete[] this->elems;
        this->capacity = other.capacity;
        this->nrElems = other.nrElems;
        this->elems = new T[this->capacity];
        for (int i = 0; i < this->nrElems; i++) {
            this->elems[i] = other.elems[i];
        }
        this->cmp = other.cmp;
    }
    return *this;
}

template<typename T>
void OrderedSet<T>::setComparator(Comparator<T> newCmp) {
    this->cmp = newCmp;  // Set the new comparator

    // Reorder elements based on the new comparator
    for (int i = 0; i < this->nrElems - 1; i++) {
        for (int j = i + 1; j < this->nrElems; j++) {
            if (this->cmp(this->elems[j], this->elems[i])) {
                std::swap(this->elems[i], this->elems[j]);
            }
        }
    }
}

#endif  // ORDEREDSET_H
