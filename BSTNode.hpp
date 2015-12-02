// Generic use bst nodes written at 3:30am
// std=c++11

#pragma once

// T must implement operator< and operator>
template <typename T>
class BSTNode {
public:
    // constructors
    BSTNode() : _left(nullptr), _right(nullptr), _data() {}
    BSTNode(const T &data) : _left(nullptr), _right(nullptr), _data(data) {}
    
    // destructor
    ~BSTNode() {
        if (_left) {
            delete _left;
        }
        if (_right) {
            delete _right;
        }
    }
   
    // helpers

    static inline bool exists(const BSTNode<T> *node) {
        return node != nullptr;
    }
    
    // transversal

    template <typename Func>
    void map(Func f) {
        if (exists(_left)) {
            _left->map(f);
        }
        f(_data);
        if (exists(_right)) {
            _right->map(f);
        }
    }
    
    // modify data map
    template <typename Func>
    void fmap(Func f) {
        if (exists(_left)) {
            _left->fmap(f);
        }
        _data = f(_data);
        if (exists(_right)) {
            _right->fmap(f);
        }
    }

    template <typename FuncL, typename FuncR>
    void transverse(FuncL l, FuncR r) {
        if (exists(_left)) {
            l(_data, _left->data());
            _left->transverse(l, r);
        }
        if (exists(_right)) {
            r(_data, _right->data());
            _right->transverse(l, r);
        }
    }

    // info

    unsigned count() {
        unsigned count = 0;
        map([&](unsigned) {
            count++;    
        });
        return count;
    } 

    // structure

    void add(T const &data) {
        if (data < _data) {
            if (exists(_left)) {
                _left->add(data);
            } else {
                _left = new BSTNode<T>(data);
            }
        } else if (data > _data) {
            if (exists(_right)) {
                _right->add(data);
            } else {
                _right = new BSTNode<T>(data);
            }
        }
    }

    // getter functions
    BSTNode<T> *right() const {
        return _right;
    }

    BSTNode<T> *left() const {
        return _left;
    }
    
    // const data getter
    const T &data() const {
        return _data;
    }
    
    // mutable data getter
    T &mutData() {
        return _data;
    }

    T copyData() {
        return _data;
    }

private:
    BSTNode<T> *_left;
    BSTNode<T> *_right;

    T _data;
};

