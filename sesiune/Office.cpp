#include "Office.h"
#include <algorithm>
#include <string>

// vvv exceptions vvv

class exc_alreadyAdded : public std::exception {
   const char* what() const noexcept {
      return "Neighbour already in list!";
   }
};

class exc_notOwner : public std::exception {
   const char* what() const noexcept {
      return "Neighbour is not an owner!";
   }
};

// vvv neighbour vvv

Neighbour::Neighbour() {

}


// vvv owner vvv

Owner::Owner(int amount) {
   tax = amount;
}

Type Owner::getType() const {
   return OWNER;
}

int Owner::getAmount() const {
   return tax;
}


// vvv renter vvv

Renter::Renter(int amount) {
   rent = amount;
}
Type Renter::getType() const {
   return RENTER;
}

int Renter::getAmount() const {
   return rent;
}


// vvv office vvv

Office::Office() {

}

void Office::add(Neighbour* neighbour) {
   if (std::find(neighbours.begin(), neighbours.end(), neighbour) != neighbours.end()) {
      throw exc_alreadyAdded();
   }
   neighbours.push_back(neighbour);
}

int Office::collect_rent() const {
   int rent = 0;
   for (auto &neighbour : neighbours) {
      if (neighbour->getType() == RENTER) {
         rent += neighbour->getAmount();
      }
   }
   return rent;
}

std::pair<int, int> Office::get_statistics() const {
   std::pair<int, int> ret = std::make_pair(0, 0);
   for (auto &neighbour : neighbours) {
      if (neighbour->getType() == RENTER) {
         ret.first += 1;
      } else {
         ret.second += 1;
      }
   }

   return ret;
}

Office::~Office() {
   for (auto &neighbour : neighbours) {
      if (neighbour->getType() == RENTER) {
         delete (Renter*) neighbour;
      } else if (neighbour->getType() == OWNER) {
         delete (Owner*) neighbour;
      }
   }
}


int Office::collect_property_tax(Neighbour* neighbour) {
   if (neighbour->getType() != OWNER) {
      throw exc_notOwner();
   }

   return neighbour->getAmount();
}