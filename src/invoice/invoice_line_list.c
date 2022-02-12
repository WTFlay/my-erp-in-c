#include "invoice_line_list.h"

InvoiceLineList * invoice_line_list_new() {
  InvoiceLineList *invoice_line_list = malloc(sizeof(InvoiceLineList));
  invoice_line_list->len = 0;
  return invoice_line_list;
}

void invoice_line_list_delete(InvoiceLineList *invoice_line_list) {
  for (int i = 0; i< invoice_line_list->len; i++) {
    free(invoice_line_list->list[i]);
  }
  free(invoice_line_list->list);
  free(invoice_line_list);
}

void invoice_line_list_add_line(InvoiceLineList *invoice_line_list, Product *product, double quantity) {
  int cursor = invoice_line_list->len;
  size_t new_len = invoice_line_list->len + 1;
  InvoiceLine **new_list = reallocarray(invoice_line_list->list, new_len, sizeof(InvoiceLine *));
  new_list[cursor] = malloc(sizeof(InvoiceLine));
  new_list[cursor]->product = product;
  new_list[cursor]->quantity = quantity;
  invoice_line_list->list = new_list;
  invoice_line_list->len = new_len;
}

double invoice_line_list_compute_total_without_tax(InvoiceLineList *invoice_line_list) {
  double total_without_tax = 0;
  for (int i = 0; i < invoice_line_list->len; i++) {
    total_without_tax += invoice_line_compute_total_price_without_tax(invoice_line_list->list[i]);
  }
  return total_without_tax;
}

double invoice_line_list_compute_total_all_tax_included(InvoiceLineList *invoice_line_list) {
  double total_all_tax_included = 0;
  for (int i = 0; i < invoice_line_list->len; i++) {
    total_all_tax_included += invoice_line_compute_total_price(invoice_line_list->list[i]);
  }
  return total_all_tax_included;
}
