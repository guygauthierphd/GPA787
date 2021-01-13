/*
* Cligne_1_Hz .c
*
* Ce programme fait clignoter un DEL à une fr é quence de 1 Hz .
* Aucun param è tre en entr ée.
*
*/

# include <stdio .h>
# include <bcm2835 .h>

# define DEL_Rouge 20 // Dé finition du GPIO associ é au DEL rouge ( broche 38)

int main ( void )
{
  // Initialisation du bcm2835
  if (! bcm2835_init ()){
    return 1;
  }

  // Configuration du GPIO pour DEL 1 ( rouge )
  bcm2835_gpio_fsel ( DEL_Rouge , BCM2835_GPIO_FSEL_OUTP );

  // Clignoter DEL :
  // DEL allumée 500 ms et éteinte 500 ms
  while (1) {
    bcm2835_gpio_write ( DEL_Rouge , HIGH );
    bcm2835_delay (500) ;
    bcm2835_gpio_write ( DEL_Rouge , LOW );
    bcm2835_delay (500) ;
  }

  // Libérer les broches du GPIO
  bcm2835_close ();
  return 0;
}
