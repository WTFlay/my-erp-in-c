#include "move.h"

Move * move_new(Customer *customer);
MoveLine * move_line_update_or_create_new_credit(MoveLine *customer_move_line, Account *account, double credit);

Move * move_create_from_invoice(Invoice *invoice) {
  Move *move = move_new(invoice->customer);
  MoveLine *customer_move_line = move_line_new(move->customer->account, 0, 0);
  MoveLine *last_move_line_in_list = customer_move_line;
  for (int i = 0; i < invoice->invoice_line_list->len; i++) {
    InvoiceLine *invoice_line = invoice->invoice_line_list->list[i];

    double price_without_tax = invoice_line_compute_total_price_without_tax(invoice_line);
    Account *product_account = invoice_line->product->account;
    MoveLine *product_move_line = move_line_update_or_create_new_credit(customer_move_line, product_account, price_without_tax);
    if (product_move_line != NULL) {
      last_move_line_in_list->next_move_line = product_move_line;
      last_move_line_in_list = product_move_line;
    }

    double tax_price = invoice_line_compute_total_tax(invoice_line);
    Account *product_tax_account = invoice_line->product->tax->account;
    MoveLine  *tax_move_line = move_line_update_or_create_new_credit(customer_move_line, product_tax_account, tax_price);
    if (tax_move_line != NULL) {
      last_move_line_in_list->next_move_line = tax_move_line;
      last_move_line_in_list = tax_move_line;
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

MoveLine * move_line_update_or_create_new_credit(MoveLine *customer_move_line, Account *account_to_find_or_create, double credit) {
  MoveLine *account_move_line = move_line_find_by_account(customer_move_line, account_to_find_or_create);
  if (account_move_line == NULL) {
    account_move_line = move_line_new(account_to_find_or_create, 0, credit);
    return account_move_line;
  } else {
    account_move_line->credit += credit;
    return NULL;
  }
}

void move_delete(Move *move) {
  move_line_delete(move->move_line_list);
  free(move);
}
