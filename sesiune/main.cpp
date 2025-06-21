#include "Office.h"
#include <iostream>

int main()
{
    Office asociatie;

    Owner* new_owner = new Owner(1200);
    asociatie.add(new_owner);

    Renter* new_renter = new Renter(300);
    asociatie.add(new_renter);
    asociatie.add((Neighbour*)new Owner(500));
    asociatie.add(new Renter(1300));

    try {
        asociatie.add(new_owner);
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "Total rent to collect: " << asociatie.collect_rent() << std::endl;

    try {
        std::cout << "Property tax to collect from owner: " << Office::collect_property_tax(new_owner) << std::endl;
        std::cout << "Property tax to collect from owner: " << Office::collect_property_tax(new_renter) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    auto [renters, owners] = asociatie.get_statistics();
    std::cout << "Office has " << renters << " renters and " << owners << " owners.";
}
