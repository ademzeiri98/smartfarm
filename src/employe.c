#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employe.h"
#include <gtk/gtk.h> 
enum{
 Ide,
 Nome,
 Prenome,
 Sexe,
 Date_naissance,
 CiN,
 Adresse,
 Situation_familiale,
 Date_dembauche,
 Salaire_actuel ,
 Specialite, 
 C_column,

 }; 

 void ajouter_employe(employe *e){ 
FILE *f5;
f5=fopen("employe.txt","a+");
if(f5!=NULL){

fprintf(f5,"%s %s %s %s %s %s %s %s %s %s %s \n",e->ide,e->nome,e->prenome,e->sexe,e->date_naissance,e->ciN,e->adresse, e->situation_familiale,e->date_dembauche,e->salaire_actuel,e->specialite);
fclose(f5);
}

}
void afficher_employe(GtkWidget *liste,employe e){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;



store=NULL;

FILE *f5;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ide",renderer,"text",Ide,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nome",renderer,"text",Nome,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" prenome",renderer,"text",Prenome,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",Sexe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_naissance",renderer,"text",Date_naissance,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ciN",renderer,"text",CiN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
 
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",Adresse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" situation_familiale",renderer,"text",Situation_familiale,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_dembauche",renderer,"text",Date_dembauche,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" salaire_actuel",renderer,"text",Salaire_actuel,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("specialite",renderer,"text",Specialite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);





store=gtk_list_store_new(C_column, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f5=fopen("employe.txt","r");

if(f5==NULL)
	{
return;
	}
else
{
	f5=fopen("employe.txt","r");
	while(fscanf(f5,"%s %s %s %s %s %s %s %s %s %s %s  \n",e.ide,e.nome,e.prenome,e.sexe,e.date_naissance,e.ciN,e.adresse, e.situation_familiale,e.date_dembauche,e.salaire_actuel,e.specialite)!=EOF)
	{
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, Ide, e.ide, Nome, e.nome, Prenome, e.prenome ,Sexe, e.sexe ,Date_naissance, e.date_naissance,CiN, e.ciN,Adresse,e.adresse,Situation_familiale,e.situation_familiale,Date_dembauche,e.date_dembauche,Salaire_actuel,e.salaire_actuel,Specialite,e.specialite,  -1);


	}
fclose(f5);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
 
void modifier_employe(employe e ){

FILE*f5;
FILE*f55=NULL;
employe e1;
f5=fopen("employe.txt","r");
f55=fopen("tempo5.txt","a+");
if(f5 !=NULL){
while(fscanf(f5,"%s %s %s %s %s %s %s %s %s %s %s \n",e1.ide,e1.nome,e1.prenome,e1.sexe,e1.date_naissance,e1.ciN,e1.adresse, e1.situation_familiale,e1.date_dembauche,e1.salaire_actuel,e1.specialite)!=EOF)
{
	if(strcmp(e.ide,e1.ide)==0)
		{
		fprintf(f55,"%s %s %s %s %s %s %s %s %s %s %s  \n",e.ide,e.nome,e.prenome,e.sexe,e.date_naissance,e.ciN,e.adresse, e.situation_familiale,e.date_dembauche,e.salaire_actuel,e.specialite);
	        }

	else
	{
		fprintf(f55,"%s %s %s %s %s %s %s %s %s %s %s \n",e1.ide,e1.nome,e1.prenome,e1.sexe,e1.date_naissance,e1.ciN,e1.adresse, e1.situation_familiale,e1.date_dembauche,e1.salaire_actuel,e1.specialite);
	        }

}
fclose(f5);
fclose(f55);
}
remove("employe.txt");
rename("tempo5.txt","employe.txt");
}


void supprimer_employe(GtkListStore *store, gchar *path){


gchar *ide;
gchar *nome;
gchar *prenome;
gchar *sexe;
gchar *date_naissance;
gchar *ciN;
gchar *adresse;
gchar *situation_familiale;
gchar *date_dembauche;
gchar *salaire_actuel;
gchar *specialite; 
FILE* f;
        GtkTreeIter iter;
        gboolean valid;





        f=fopen(path,"w");
        valid=gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store),
                                            &iter);
        while ( valid) {
              
                        gtk_tree_model_get ( GTK_TREE_MODEL(store),&iter,Ide, &ide, Nome, &nome, Prenome, &prenome ,Sexe, &sexe ,Date_naissance,&date_naissance,CiN,&ciN,Adresse,&adresse,Situation_familiale,&situation_familiale,Date_dembauche,&date_dembauche,Salaire_actuel,&salaire_actuel,Specialite,&specialite,-1);

                        fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s  \n",ide,nome,prenome,sexe,date_naissance,ciN,adresse, situation_familiale,date_dembauche,salaire_actuel,specialite);
            
                valid=gtk_tree_model_iter_next (GTK_TREE_MODEL(store),&iter);
        }

        fclose(f);
}

void cherchertreee(GtkWidget *liste,employe e,char *ID1, char *NOM1)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkListStore *store;

store=NULL;
FILE *f5;

 store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
GtkTreeIter    iter;


if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ide",renderer,"text",Ide,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nome",renderer,"text",Nome,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" prenome",renderer,"text",Prenome,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",Sexe,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_naissance",renderer,"text",Date_naissance,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" ciN",renderer,"text",CiN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
 
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" adresse",renderer,"text",Adresse,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" situation_familiale",renderer,"text",Situation_familiale,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_dembauche",renderer,"text",Date_dembauche,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" salaire_actuel",renderer,"text",Salaire_actuel,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("specialite",renderer,"text",Specialite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}

store=gtk_list_store_new(C_column, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f5=fopen("employe.txt","r");

if (!f5) g_print("error");

while(fscanf(f5,"%s %s %s %s %s %s %s %s %s %s %s \n",e.ide,e.nome,e.prenome,e.sexe,e.date_naissance,e.ciN,e.adresse, e.situation_familiale,e.date_dembauche,e.salaire_actuel,e.specialite)!=EOF)
        {
	if(strcmp(e.ide,ID1)==0 && strcmp(e.nome,NOM1)==0){
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(store, &iter);
         /* Mise a jour des donnees */
         gtk_list_store_set(store, &iter, Ide, e.ide, Nome, e.nome, Prenome, e.prenome ,Sexe, e.sexe ,Date_naissance,e.date_naissance,CiN,e.ciN,Adresse,e.adresse,Situation_familiale,e.situation_familiale,Date_dembauche,e.date_dembauche,Salaire_actuel,e.salaire_actuel,Specialite,e.specialite,-1);}}

fclose(f5);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
g_object_unref(store);



}


