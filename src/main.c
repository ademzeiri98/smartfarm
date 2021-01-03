/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int main (int argc, char *argv[]){
	GtkWidget *ajout_produit;
	GtkWidget *Afficher_produit;
	GtkWidget *modifie_produit;
	GtkWidget *employe ;	
	GtkWidget *ajout_employe;
	GtkWidget *afficher_employe;
	GtkWidget *accueil;

  
 

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);
  
  add_pixmap_directory ("/home/adem/Projets/projetProduit/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /*ajout_produit = create_ajout_produit ();
  gtk_widget_show (ajout_produit);*/
    /*modifie_produit =create_modifie_produit();
    gtk_widget_show(modifie_produit);*/

    /*Afficher_produit = create_Afficher_produit ();
    gtk_widget_show (Afficher_produit);*/


  accueil = create_accueil(); 
gtk_widget_show (accueil);

  
  gtk_main ();
  return 0;
}
