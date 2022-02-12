#ifndef _INVOICE_LINE_LIST_H_
#define _INVOICE_LINE_LIST_H_

#include "invoice_line.h"
#include <stdlib.h>

typedef struct InvoiceLineList {
  size_t len;
  InvoiceLine **list;
} InvoiceLineList;

InvoiceLineList * invoice_line_list_new();
void invoice_line_list_delete(InvoiceLineList *);
void invoice_line_list_add_line(InvoiceLineList *, Product *, double quantity);
double invoice_line_list_compute_total_without_tax(InvoiceLineList *);
double invoice_line_list_compute_total_all_tax_included(InvoiceLineList *);

#endif
