#include <iostream>
#include <iomanip>

#include "bst.h"

int main(int argc, char* argv[]) {
    BST bst;
    for (int i = 1; i < argc; i++)
        bst.insert(atoi(argv[i]));
    bst.printDFS();
    std::cout << "--------------" << std::endl;
    bst.printInorder();
    std::cout << "--------------" << std::endl;
    bst.printPreorder();
    std::cout << "--------------" << std::endl;
    bst.printPostorder();
    std::cout << "--------------" << std::endl;
    bst.printGraphical();
    return 0;
}
