#include <stdio.h>

#define IN 1        /* Valor que define el estar dentro de una palabra */
#define OUT 0		/* Valor que define el estar afuera de una palabra */

int main(void)
{
	int c;	      /* Almacena la constante de caracter de un caracter de entrada */
	int print;    /* Se utiliza como un indicador para que imprima un texto predeterminado */
	int cl;       /* Indicador del numero de linea que ingresa el usuario */
	int state;    /* Indicador del programa para saber que esta leyendo una palabra */
	int last_chr; /* Almacena un caracter previamente leido en la entrada */
	printf("Este programa permite que el usuario ingrese una linea de texto; cada palabra encontrada en el texto es\n");
	printf("impresa por linea, en la ventana donde se ejecute el programa.\n");
	printf("Para detener la captura de texto por el programa, ingresa un salto de linea cuando el programa solicite ingresar texto.");
	cl = print = 0;
	c = '\n';
	while (c == '\n' && print == 0)
	{
		print = 1;  /* Se da un valor positivo para que el programa reconozca que tiene que imprimir un texto */
		state = OUT;
		last_chr = ' ';
		printf("\n\nLinea #%d. Texto a ingresar:", ++cl);
		while ((c = getchar()) != '\n') {
			if (print) {
				printf("\nSalida del texto de la linea #%d:", cl);
				print = 0;	/* Se establece un valor nulo para que ya no imprima nuevamente el texto */
			}
			if (c == ' ' || c == '\t') 
				state = OUT;
			else {
				state = IN;		/* El programa esta en una palabra */
				if (last_chr == ' ' || last_chr == '\t')
				/* Cuando el anterior caracter leido es un espacio en blanco o tabulacion, 
				   se da un salto de linea para imprimir la siguiente palabra.
				   Esta condicion se cumple al iniciar con la primera palabra en una linea de texto, 
				   ya que last_chr se inicializa con con la constante de caracter del espacio en blanco. 
				*/
					putchar('\n');	
			}
			if (state == IN)
				putchar(c);		/* Se imprime los caracteres de una palabra */
			last_chr = c;
		}
	}
	return 0;
}