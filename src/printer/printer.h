#ifndef _PRINTER_H_
#define _PRINTER_H_

#include "../invoice/invoice_line.h"
#include "../invoice/invoice_line_list.h"
#include "../invoice/invoice.h"
#include "../move/move.h"

void printer_print_invoice_line(InvoiceLine *);
void printer_print_invoice_line_list(InvoiceLineList *);
void printer_print_invoice(Invoice *);
void printer_print_move(Move *);

#endif
