#include <gtk/gtk.h>


typedef struct
{
char id[20];
char nomp[20];
char typep[20];
char date_dajout[20];
char quantite[20];
char prixunitaire[20];

}produit;

liste_type (char ref[][50]);
void ajouter_produit(produit *p);
void afficher_produit(GtkWidget *liste, produit p);
void modifier_produit(produit p);
void supprimer_produit(GtkListStore *store, gchar *path);
void cherchertree(GtkWidget *liste,produit p,char*ID,char *NOM);


