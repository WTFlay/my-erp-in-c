#include <stdio.h>
#include "printer.h"

void printer_print_invoice_line(InvoiceLine *invoice_line) {
  char *product_name = invoice_line->product->name;
  double quantity = invoice_line->quantity;
  double unit_price = invoice_line->product->price;
  double total_without_tax = invoice_line_compute_total_price_without_tax(invoice_line);
  double total_with_tax = invoice_line_compute_total_price(invoice_line);
  printf("product: %s, quantity: %.2f, unit price: $%.2f, total WT: $%.2f, total ATI: $%.2f\n",
      product_name,
      quantity,
      unit_price,
      total_without_tax,
      total_with_tax);
}

void printer_print_invoice_line_list(InvoiceLineList *invoice_line_list) {
  size_t len = invoice_line_list->len;
  for (int i = 0; i < len; i++) {
    printer_print_invoice_line(invoice_line_list->list[i]);
  }
}

void printer_print_invoice(Invoice *invoice) {
  printf("Customer: %s\n", invoice->customer->name);
  printf("Invoice Line List:\n");
  printer_print_invoice_line_list(invoice->invoice_line_list);
  double total_without_tax = invoice_compute_total_without_tax(invoice);
  printf("Total WT: $%.2f\n", total_without_tax);
  double total_all_tax_included = invoice_compute_total_all_tax_included(invoice);
  printf("Total ATI: $%.2f\n", total_all_tax_included);
}
