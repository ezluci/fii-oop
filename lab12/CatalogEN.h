#pragma once
#include "Catalog.h"

class CatalogEN : public Catalog {
public:
   std::string getProgram() const override;
};