#include "main.h"
/**
 * print_char - writes char to buffer or standard output
 * @inv: the arguments inventory with most commonly used argument
 * Return: number of chars wrote to buffer
 */
void print_char(inventory_t *inv)
{
	inv->c0 = va_arg(*(inv->args), int);

	write_buffer(inv);
}
/**
 * print_percent - writes a percent symbol to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void print_percent(inventory_t *inv)
{
	inv->c0 = '%';

	if (inv->space)
	{
		inv->space = 0;
		inv->buffer[--(inv->buf_index)] = '\0';
	}

	write_buffer(inv);
}
