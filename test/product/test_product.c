//
// Created by flay on 12/02/2022.
//

#include "../../src/product/product.h"
#include <assert.h>

void test_product_compute_tax_price();

int main() {
    test_product_compute_tax_price();
    return 0;
}

void test_product_compute_tax_price() {
    Tax tax = { .value = 0.2 };
    Product product = { .price = 367, .tax = &tax };
    double tax_price_computed = product_compute_tax_price(&product);
    assert(tax_price_computed == 73.40);
}
