#pragma once
#include "Catalog.h"

class CatalogRO : public Catalog {
public:
   std::string getProgram() const override;
};