#include "invoice.h"

Invoice * invoice_new(Customer *customer) {
  Invoice *invoice = malloc(sizeof(Invoice));
  invoice->customer = customer;
  invoice->invoice_line_list = invoice_line_list_new();
  return invoice;
}

void invoice_delete(Invoice *invoice) {
  invoice_line_list_delete(invoice->invoice_line_list);
  free(invoice);
}

inline void invoice_add_invoice_line(Invoice *invoice, Product *product, double quantity) {
  invoice_line_list_add_line(invoice->invoice_line_list, product, quantity);
}

inline double invoice_compute_total_without_tax(Invoice *invoice) {
  return invoice_line_list_compute_total_without_tax(invoice->invoice_line_list);
}

inline double invoice_compute_total_all_tax_included(Invoice *invoice) {
  return invoice_line_list_compute_total_all_tax_included(invoice->invoice_line_list);
}
