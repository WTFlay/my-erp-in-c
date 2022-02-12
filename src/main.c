#include <stdio.h>
#include "account/account.h"
#include "tax/tax.h"
#include "product/product.h"
#include "invoice/invoice.h"
#include "printer/printer.h"
#include "move/move.h"

int main() {
  Account customer_account = { .code = "411", .name = "Customer" };
  Account product_account = { .code = "701", .name = "Product" };
  Account tax_account = { .code = "445", .name = "VAT" };

  Tax product_tax = { .value = 0.1, .account = &tax_account };

  Product annual_maintenance_product = {
    .name = "Annual Maintenance",
    .price = 1460.0,
    .account = &product_account,
    .tax = &product_tax
  };

  Product processor_product = {
    .name = "Processor 6x3.2 GHz",
    .price = 540.0,
    .account = &product_account,
    .tax = &product_tax
  };

  Customer customer = {
    .name = "Jon Doe",
    .account = &customer_account
  };

  Invoice *invoice = invoice_new(&customer);
  invoice_add_invoice_line(invoice, &annual_maintenance_product, 1);
  invoice_add_invoice_line(invoice, &processor_product, 2);
  printer_print_invoice(invoice);

  printf("\n");

  Move *move = move_create_from_invoice(invoice);
  printer_print_move(move);

  move_delete(move);
  invoice_delete(invoice);
  return 0;
}
