#include "main.h"
/**
 * match_specifier - matches specifier function for each conversion specifier
 * also handles modifiers of short and long
 * @inv: the arguments inventory with most commonly used arguments
 * Return: pointer to the helper function or NULL
 */
void (*match_specifier(inventory_t *inv))(inventory_t *)
{
	int j, i = 0;
	char check = inv->c1;
	static const char modifiers[] = "hl+#";
	static matches_t specifiers_list[] = {
		{'d', print_int}, {'i', print_int}, {'x', print_lowhex},
		{'X', print_uphex}, {'o', print_oct2}, {'u', print_ulongint},
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'b', print_binary}, {'p', print_pointer}, {'r', print_rev_string},
		{'R', print_rot13}, {'S', print_string_hex}, {'\0', NULL}
	};
	static matches_t modifiers_long[] = {
		{'d', print_longint}, {'i', print_longint},
		{'x', print_longlowhex}, {'X', print_longuphex},
		{'o', print_longoct}, {'u', print_ulongint}, {'\0', NULL}
	};

	for (j = 0; modifiers[j] != '\0'; j++)
		if (modifiers[j] == inv->c1)
			inv->flag = 1, check = inv->c2;
	while (TRUE)
	{
		if (specifiers_list[i].ch == '\0')
		{
			if (inv->flag)
				inv->i++;
			return (NULL);
		}
		if (specifiers_list[i].ch == check)
		{
			if (inv->flag)
				inv->i += 2;
			else
				inv->i++;
			if (inv->c1 == 'l')
				return (modifiers_long[i].func);
			return (specifiers_list[i].func);
		}
		i++;
	}
}
