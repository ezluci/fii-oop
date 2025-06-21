#pragma once

#include <vector>
#include <utility>

enum Type {
   OWNER, RENTER
};

class Neighbour {
public:
   Neighbour();
   virtual Type getType() const = 0;
   virtual int getAmount() const = 0;
};

class Owner : public Neighbour {
private:
   int tax;
public:
   Owner(int);
   Type getType() const override;
   int getAmount() const override;
};

class Renter : public Neighbour {
private:
   int rent;
public:
   Renter(int);
   Type getType() const override;
   int getAmount() const override;
};

class Office {
private:
   std::vector<Neighbour*> neighbours;
public:
   Office();
   void add(Neighbour* neighbour);
   int collect_rent() const;
   std::pair<int, int> get_statistics() const;
   ~Office();

   static int collect_property_tax(Neighbour* neighbour);
};