#include "invoice_line.h"

inline double invoice_line_get_product_price(InvoiceLine *invoice_line) {
  return invoice_line->product->price;
}

double invoice_line_compute_total_price(InvoiceLine *invoice_line) {
  double product_price = invoice_line_get_product_price(invoice_line);
  double product_tax = invoice_line->product->tax->value;
  double quantity = invoice_line->quantity;
  return product_price * (1 + product_tax) * quantity;
}

double invoice_line_compute_total_price_without_tax(InvoiceLine *invoice_line) {
  double product_price = invoice_line->product->price;
  double quantity = invoice_line->quantity;
  return product_price * quantity;
}

double invoice_line_compute_total_tax(InvoiceLine *invoice_line) {
  double product_price = invoice_line_get_product_price(invoice_line);
  double quantity = invoice_line->quantity;
  double tax = invoice_line->product->tax->value;
  return (product_price * quantity) * tax;
}
