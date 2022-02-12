#include "move.h"

Move * move_new(Customer *customer);

Move * move_create_from_invoice(Invoice *invoice) {
  Move *move = move_new(invoice->customer);
  MoveLine *customer_move_line = move_line_new(move->customer->account, 0, 0);
  MoveLine *last_move_line_in_list = customer_move_line;
  for (int i = 0; i < invoice->invoice_line_list->len; i++) {
    InvoiceLine *invoice_line = invoice->invoice_line_list->list[i];

    Account *product_account = invoice_line->product->account;
    MoveLine *product_move_line = move_line_find_by_account(customer_move_line, product_account);
    double price_without_tax = invoice_line_compute_total_price_without_tax(invoice_line);
    if (product_move_line == NULL) {
      product_move_line = move_line_new(product_account, 0, price_without_tax);
      last_move_line_in_list->next_move_line = product_move_line;
      last_move_line_in_list = product_move_line;
    } else {
      product_move_line->credit += price_without_tax;
    }

    Account *product_tax_account = invoice_line->product->tax->account;
    MoveLine  *tax_move_line = move_line_find_by_account(customer_move_line, product_tax_account);
    double tax_price = invoice_line_compute_total_tax(invoice_line);
    if (tax_move_line == NULL) {
      tax_move_line = move_line_new(product_tax_account, 0, tax_price);
      last_move_line_in_list->next_move_line = tax_move_line;
      last_move_line_in_list = tax_move_line;
    } else {
      tax_move_line->credit += tax_price;
    }

    customer_move_line->debit += price_without_tax + tax_price;
  }
  move->move_line_list = customer_move_line;
  return move;
}

Move * move_new(Customer *customer) {
  Move *move = malloc(sizeof(Move));
  move->customer = customer;
  move->move_line_list = NULL;
  return move;
}
