#include <gtk/gtk.h>


typedef struct
{
 char ide [20];
 char nome[20];
 char prenome[20];
 char sexe [20];
 char date_naissance[30];
 char ciN[20];
 char adresse [20];
 char situation_familiale [20];
 char date_dembauche [30];
 char salaire_actuel [30];
 char specialite [30];

}employe ;
 void ajouter_employe(employe *e);
 void modifier_employe(employe e);
 void afficher_employe(GtkWidget *liste, employe e);
 void supprimer_employe(GtkListStore *store, gchar *path);
 void cherchertreee(GtkWidget *liste,employe e,char*ID1,char *NOM1);
