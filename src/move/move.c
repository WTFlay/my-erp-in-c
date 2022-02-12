#include "move.h"

Move * move_new(Customer *customer);

Move * move_create_from_invoice(Invoice *invoice) {
  Move *move = move_new(invoice->customer);
  MoveLine *customerMoveLine = move_line_new(move->customer->account, 0, 0);
  MoveLine *lastMoveLineInList = customerMoveLine;
  for (int i = 0; i < invoice->invoice_line_list->len; i++) {
    InvoiceLine *invoiceLine = invoice->invoice_line_list->list[i];

    Account *productAccount = invoiceLine->product->account;
    MoveLine *productMoveLine = move_line_find_by_account(customerMoveLine, productAccount);
    double priceWithoutTax = invoice_line_compute_total_price_without_tax(invoiceLine);
    if (productMoveLine == NULL) {
      productMoveLine = move_line_new(productAccount, 0, priceWithoutTax);
      lastMoveLineInList->next_move_line = productMoveLine;
      lastMoveLineInList = productMoveLine;
    } else {
      productMoveLine->credit += priceWithoutTax;
    }

    Account *productTaxAccount = invoiceLine->product->tax->account;
    MoveLine  *taxMoveLine = move_line_find_by_account(customerMoveLine, productTaxAccount);
    double taxPrice = invoice_line_compute_total_tax(invoiceLine);
    if (taxMoveLine == NULL) {
      taxMoveLine = move_line_new(productTaxAccount, 0, taxPrice);
      lastMoveLineInList->next_move_line = taxMoveLine;
      lastMoveLineInList = taxMoveLine;
    } else {
      taxMoveLine->credit += taxPrice;
    }

    customerMoveLine->debit += priceWithoutTax + taxPrice;
  }
  move->move_line_list = customerMoveLine;
  return move;
}

Move * move_new(Customer *customer) {
  Move *move = malloc(sizeof(Move));
  move->customer = customer;
  move->move_line_list = NULL;
  return move;
}
