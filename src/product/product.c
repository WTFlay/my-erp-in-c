#include "product.h"

double product_compute_tax_price(Product *product) {
  double product_price = product->price;
  double product_tax = product->tax->value;
  return product_price * product_tax;
}

