#pragma once

#include <cstddef>

template<typename K, typename V>
struct MapObject {
    K& key;
    V& val;
    size_t index;

    MapObject(K& key, V& val, size_t index)
        : key(key), val(val), index(index) { }
};

template<typename K, typename V>
class Map {
private:
    static constexpr size_t MAP_SIZE = 100;

    size_t size = 0;
    K keys[MAP_SIZE];
    V vals[MAP_SIZE];

    class Iterator {
    private:
        Map<K, V>* parent;
        size_t index;
    public:
        Iterator(Map<K, V>* parent, size_t index)
            : parent(parent), index(index) { }
        
        Iterator& operator++()
        {
            this->index += 1;
            return *this;
        }
        
        bool operator!=(const Iterator& other) const
        {
            return this->index != other.index;
        }

        MapObject<K, V> operator*()
        {
            return MapObject<K, V>(
                this->parent->keys[this->index],
                this->parent->vals[this->index],
                this->index
            );
        }
    };

public:
    void Set(const K& key, const V& val)
    {
        for (size_t i = 0; i < this->size; ++i)
        {
            if (this->keys[i] == key)
            {
                this->vals[i] = val;
                return;
            }
        }
    
        this->keys[this->size] = key;
        this->vals[this->size] = val;
        this->size += 1;
    }

    bool Get(const K& key, V& val) const
    {
        for (size_t i = 0; i < this->size; ++i)
        {
            if (this->keys[i] == key)
            {
                val = this->vals[i];
                return true;
            }
        }
    
        return false;
    }

    size_t Count() const
    {
        return this->size;
    }

    void Clear()
    {
        this->size = 0;
    }

    bool Delete(const K& key)
    {
        for (size_t i = 0; i < this->size; ++i)
        {
            if (this->keys[i] == key)
            {
                for (size_t j = i+1; j < this->size; ++j)
                    this->keys[j-1] = this->keys[j],
                    this->vals[j-1] = this->vals[j];
                this->size -= 1;
                return true;
            }
        }
    
        return false;
    }

    bool Includes(const Map<K, V>& other) const
    {
        for (size_t i_other = 0; i_other < other.size; ++i_other)
        {
            bool found = false;
            for (size_t i_this = 0; i_this < this->size; ++i_this)
                if (other.keys[i_other] == this->keys[i_this])
                    found = true;
            if (!found)
                return false;
        }
        return true;
    }
    
    Iterator begin()
    {
        return Map<K, V>::Iterator(this, 0);
    }

    Iterator end()
    {
        return Map<K, V>::Iterator(this, this->size);
    }

    V& operator[](const K& key) {
        for (size_t i = 0; i < this->size; ++i)
            if (this->keys[i] == key)
                return this->vals[i];
        
        this->keys[this->size] = key;
        this->vals[this->size] = V{};
        this->size += 1;
        return this->vals[this->size - 1];
    }
};