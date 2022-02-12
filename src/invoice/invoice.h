#ifndef _INVOICE_H_
#define _INVOICE_H_

#include "../customer/customer.h"
#include "invoice_line_list.h"

typedef struct Invoice {
  Customer *customer;
  InvoiceLineList *invoice_line_list;
} Invoice;

Invoice * invoice_new(Customer *);
void invoice_delete(Invoice *);
void invoice_add_invoice_line(Invoice *, Product *, double quantity);
double invoice_compute_total_without_tax(Invoice *);
double invoice_compute_total_all_tax_included(Invoice *);

#endif
