#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "../account/account.h"
#include "../tax/tax.h"

typedef struct Product {
  char *name;
  double price;
  Account *account;
  Tax *tax;
} Product;

double product_compute_tax_price(Product *);

#endif
