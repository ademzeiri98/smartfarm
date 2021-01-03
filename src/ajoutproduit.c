#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ajoutproduit.h"
#include <gtk/gtk.h>
enum{
Id,
nom,
type,
date_dAjout,
Quantite,
Prixunitaire,
C_column

};




void ajouter_produit(produit *p){

FILE *f;
f=fopen("produit.txt","a+");
if(f!=NULL){

fprintf(f,"%s %s %s %s %s %s \n",p->id,p->nomp,p->typep,p->date_dajout,p->quantite,p->prixunitaire);
fclose(f);
}



}

void afficher_produit(GtkWidget *liste,produit p){

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;



store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",Id,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nomp",renderer,"text",nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" typep",renderer,"text",type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_dajout",renderer,"text",date_dAjout,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" quantite",renderer,"text",Quantite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" prixunitaire",renderer,"text",Prixunitaire,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



store=gtk_list_store_new(C_column, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("produit.txt","r");

if(f==NULL)
	{
return;
	}
else
{
	f=fopen("produit.txt","r");
	while(fscanf(f,"%s %s %s %s %s %s\n",p.id,p.nomp,p.typep,p.date_dajout,p.quantite,p.prixunitaire)!=EOF)
	{
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, Id, p.id, nom, p.nomp, type, p.typep,date_dAjout, p.date_dajout,Quantite, p.quantite,Prixunitaire, p.prixunitaire, -1);


	}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
void modifier_produit(produit p ){

FILE*f;
FILE*f1=NULL;
produit p1;
f=fopen("produit.txt","r");
f1=fopen("tempo1.txt","a+");
if(f !=NULL){
while(fscanf(f,"%s %s %s %s %s %s  \n",p1.id,p1.nomp,p1.typep,p1.date_dajout,p1.quantite,p1.prixunitaire)!=EOF)
{
	if(strcmp(p.id,p1.id)==0)
		{
		fprintf(f1,"%s %s %s %s %s %s  \n",p.id,p.nomp,p.typep,p.date_dajout,p.quantite,p.prixunitaire);
	        }

	else
	{
		fprintf(f1,"%s %s %s %s %s %s  \n",p1.id,p1.nomp,p1.typep,p1.date_dajout,p1.quantite,p1.prixunitaire);
	        }

}
fclose(f);
fclose(f1);
}
remove("produit.txt");
rename("tempo1.txt","produit.txt");
}
void supprimer_produit(GtkListStore *store, gchar *path){


gchar *id;
gchar *nomp;
gchar *typep;
gchar *date_dajout;
gchar *quantite;
gchar *prixunitaire;
FILE* f;
        GtkTreeIter iter;
        gboolean valid;





        f=fopen(path,"w");
        valid=gtk_tree_model_get_iter_first(GTK_TREE_MODEL(store),
                                            &iter);
        while ( valid) {
              
                        gtk_tree_model_get ( GTK_TREE_MODEL(store),&iter,Id,&id,nom,&nomp,type,&typep,date_dAjout,&date_dajout,Quantite,quantite,Prixunitaire,prixunitaire,-1);

                        fprintf(f,"%s %s %s %s %s %s\n",id,nomp,typep,date_dajout,quantite,prixunitaire);

            
                valid=gtk_tree_model_iter_next (GTK_TREE_MODEL(store),&iter);
        }

        fclose(f);
}


void cherchertree(GtkWidget *liste,produit p,char *ID, char *NOM)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkListStore *store;

store=NULL;
FILE *f;

 store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
GtkTreeIter    iter;


if(store==NULL)
{
	renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes(" id",renderer,"text",Id,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" nomp",renderer,"text",nom,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" typep",renderer,"text",type,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" date_dajout",renderer,"text",date_dAjout,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" quantite",renderer,"text",Quantite,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" prixunitaire",renderer,"text",Prixunitaire,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}

store=gtk_list_store_new(C_column, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f=fopen("produit.txt","r");

if (!f) g_print("error");

while(fscanf(f,"%s %s %s %s %s %s\n",p.id,p.nomp,p.typep,p.date_dajout,p.quantite,p.prixunitaire)!=EOF)
        {
	if(strcmp(p.id,ID)==0 && strcmp(p.nomp,NOM)==0){
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(store, &iter);
         /* Mise a jour des donnees */
         gtk_list_store_set(store, &iter, Id, p.id, nom, p.nomp, type, p.typep,date_dAjout, p.date_dajout,Quantite, p.quantite,Prixunitaire, p.prixunitaire, -1);}}

fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
g_object_unref(store);



}
int liste_type (char ref[][50])
{
char a[10];


int nb=0;

FILE*f4;

f4=fopen("type_produit.txt","r");

if(f4 !=NULL){
while(fscanf(f4,"%s \n",a)!=EOF)
{
	strcpy(ref[nb],a);
	nb++;

}fclose(f4);

}
return nb;
}
