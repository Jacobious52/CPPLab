#include "BSTNode.hpp"
#include <iostream>

int main() {
    // create a root node
    BSTNode<int> *root = new BSTNode<int>(5);
    std::cout << "root: " << root->data() << std::endl;
    
    // add some values
    root->add(3);
    root->add(4);
    root->add(2);
    root->add(8);
    root->add(7);

    // manually print some nodes
    std::cout << "left->right: " << root->left()->right()->data() << std::endl;
    
    // use map to iterate and print all the nums with a lambda
    // use could use a function pointer or a Functor aswell
    root->map([](int i) {
        std::cout << i << ", ";
    });
    std::cout << std::endl;

    // tranverse the tree, knowing which direction and where you came from
    root->transverse([](int from, int to) {
        std::cout << "going left from: " << from << " to: " << to << std::endl;
    }, [](int from, int to) {
        std::cout << "going right from: " << from << " to: " << to << std::endl;
    });
    
    // map, but this time times every num by do by using ref i
    root->map([](int &i) {
        i*=2;
    });
    
    // print all the doubled nums
    root->map([](int i) {
        std::cout << i << ", ";
    });
    std::cout << std::endl;

    //this time use fmap to edit values without using ref ii
    //NOTE: if applying non uniform transforms to the data
    //      ie. if num % 2 == 0; i+10
    //      then it will no longer be a bst.
    //      a reshuffle will be needed
    root->fmap([](int i) {
        return i*10;
    });
    
    // print all the *10 nums
    root->map([](int i) {
        std::cout << i << ", ";
    });
    std::cout << std::endl;

    //print the count of the bst
    std::cout << "count: " << root->count() << std::endl; 

    delete root;

    return 0;
}
