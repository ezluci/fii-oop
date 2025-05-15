#pragma once

#include <cstddef>
#include <exception>
#include <stdexcept>
#include <algorithm>

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    T* current;
public:
    ArrayIterator() : current(nullptr) { }
    
    ArrayIterator<T>& operator++() {
        this->current += 1;
        return *this;
    }

    ArrayIterator<T>& operator--() {
        this->current -= 1;
        return *this;
    }

    bool operator==(ArrayIterator<T> &other)
    {
        return this->current == other.current;
    }

    bool operator!=(ArrayIterator<T> &other)
    {
        return this->current != other.current;
    }

    T* GetElement()
    {
        return this->current;
    }
};


template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    size_t Capacity; // dimensiunea listei de pointeri
    size_t Size; // cate elemente sunt in lista
    
public:
    // Lista nu e alocata, Capacity si Size = 0
    Array()
    {
        this->Capacity = this->Size = 0;
        this->List = nullptr;
    }

    // destructor
    ~Array()
    {
        for (size_t i = 0; i < this->Size; ++i)
            delete this->List[i];
        delete[] this->List;
    }

    // Lista e alocata cu 'capacity' elemente
    Array(int capacity)
    {
        if (capacity <= 0)
            throw std::invalid_argument("Eroare Array, capacitate non-pozitiva.");
        this->Size = 0;
        this->Capacity = capacity;
        this->List = new T*[capacity];
    }

    // constructor de copiere
    Array(const Array<T>& otherArray) {
        this->Capacity = otherArray.Capacity;
        this->Size = otherArray.Size;

        if (otherArray.List)
        {
            this->List = new T*[this->Capacity];
            for (size_t i = 0; i < this->Size; ++i)
                this->List[i] = new T(*otherArray.List[i]);
        }
        else
        {
            this->List = nullptr;
        }
    }

    // arunca exceptie daca index este out of range
    T& operator[](int index)
    {
        if (index < 0 || index >= this->Size)
            throw std::out_of_range("Eroare [], index incorect.");
        return *this->List[index];
    }

    // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& operator+=(const T &newElem)
    {
        try {
            this->Insert(this->Size, newElem);
        } catch(std::exception &e) {
            throw; // arunca mai departe
        }
        return *this;
    }

    // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > this->Size)
            throw std::out_of_range("Eroare Insert, index incorect.");

        if (this->Size >= this->Capacity)
        {
            size_t newCapacity = (this->Capacity == 0) ? 1 : this->Capacity * 2;
            T** newList = new T*[newCapacity];

            for (size_t i = 0; i < this->Size; ++i)
                newList[i] = this->List[i];

            delete[] this->List;
            this->List = newList;
            this->Capacity = newCapacity;
        }

        for (int i = this->Size; i > index; --i)
            this->List[i] = this->List[i - 1];

        this->List[index] = new T(newElem);

        ++this->Size;
        return *this;
    }


    // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        try {
            for (size_t i = 0; i < otherArray.Size; ++i)
                this->Insert(index + i, *otherArray.List[i]);
        } catch(std::exception &e) {
            throw;
        }
        return *this;
    }
    
    // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= this->Size)
            throw std::out_of_range("Eroare Delete, index incorect.");
        
        delete this->List[index];
        for (size_t i = index; i + 1 < this->Size; ++i)
            this->List[i] = this->List[i+1];
        this->Size -= 1;
        return *this;
    }

    Array<T>& operator=(const Array<T>& other)
    {
        if (this != &other) {
            // destroy old
            for (size_t i = 0; i < Size; ++i) delete List[i];
            delete[] List;
            // copy new
            Capacity = other.Capacity;
            Size     = other.Size;
            List     = (Capacity ? new T*[Capacity] : nullptr);
            for (size_t i = 0; i < Size; ++i)
                List[i] = new T(*other.List[i]);
        }
        return *this;
    }

    void Sort()
    {
        std::sort(this->List, this->List + this->Size, [](T* a, T* b) {
            return *a < *b;
        });
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        std::sort(this->List, this->List + this->Size, [compare](T* a, T* b) {
            return compare(*a, *b) < 0;
        });
    }

    void Sort(Compare* comparator)
    {
        std::sort(this->List, this->List + this->Size, [comparator](T* a, T* b) {
            return comparator->CompareElements(a, b) < 0;
        });
    }


    int Find(const T& elem)
    {
        for (int i = 0; i < this->Size; ++i)
            if (*this->List[i] == elem)
                return i;
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < this->Size; ++i)
            if (compare(*this->List[i], elem) == 0)
                return i;
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < this->Size; ++i)
            if (comparator->CompareElements(this->List[i], (void*)&elem) == 0)
                return i;
        return -1;
    }

    int BinarySearch(const T& elem)
    {
        int left = 0, right = this->Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (*this->List[mid] == elem)
                return mid;
            else if (*this->List[mid] < elem)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int left = 0, right = this->Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int cmp = compare(*this->List[mid], elem);
            if (cmp == 0)
                return mid;
            else if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)
    {
        int left = 0, right = this->Size - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int cmp = comparator->CompareElements(this->List[mid], (void*)&elem);
            if (cmp == 0)
                return mid;
            else if (cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }


    int GetSize()
    {
        return this->Size;
    }

    int GetCapacity()
    {
        return this->Capacity;
    }

    ArrayIterator<T> GetBeginIterator()
    {
        return ArrayIterator<T>{this->List};
    }

    ArrayIterator<T> GetEndIterator()
    {
        return ArrayIterator<T>{this->List + this->Size};
    }
};
