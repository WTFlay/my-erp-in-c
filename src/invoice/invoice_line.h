#ifndef _INVOICE_LINE_
#define _INVOICE_LINE_

#include "../product/product.h"

typedef struct InvoiceLine {
  Product *product;
  unsigned int quantity;
} InvoiceLine;

double invoice_line_get_product_price(InvoiceLine *);
double invoice_line_compute_total_price(InvoiceLine *);
double invoice_line_compute_total_price_without_tax(InvoiceLine *);;
double invoice_line_compute_total_tax(InvoiceLine *);

#endif
