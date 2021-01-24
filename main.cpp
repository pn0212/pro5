//
//  main.cpp
//  Project 5
//
//  Created by Felix Minh Thong Vu on 11/16/20.
//

#include "Header.h"
#include <iostream>

int main()
{
    //Url Parser
    const Url url{ "https://www.desmos.com/calculator" };

    std::cout << url << "\n";

    //Display image metadata
    const Image image{"Project","PNG",11092020,5000,"Bird",45,50,8,"1/30",3000,true};
    std::cout << image << "\n";

    //Item
    std::cout << Item("books", 700000, 25, 12) << "\n";
    
    //Display store items and total number of item in store
    Store store;
    std::cout << store;
    std::cout << "Total number of item in the store = " << store.getTotal() << "\n\n";
    

    //Process order and display current store
    Order order;
    if (store.processOrder(order)){
        std::cout << "After processing\n" << store;
        std::cout << "After processing, total number of item in the store = " << store.getTotal() << "\n";
    }
}
