#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif



#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ajoutproduit.h"
#include "employe.h"
static int counter = 1;
static int s=0;
static char type[50];
static char tab[50][50];
static int n =0;
static int counter1 = 1;
/*labelerreurquantite
labelerreurprixunitaire
labelerreurnom*/
void
on_Ajouter_Produit_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
int a=0;
int b=0;
int c=0;
char jour[50];
char mois[50];
char annee[50];
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
int jour1,mois1,annee1;
FILE *f1;
produit p;
GtkWidget *input1, *input2,*input3,*input5,*input6,*inputjour,*inputmois,*inputannee;
GtkWidget *ajoutproduit;
GtkWidget *Afficher_produit;
GtkTreeView *treeview_produit;
GtkWidget *combobox1;
combobox1=lookup_widget(button,"comboboxtype");

ajoutproduit = lookup_widget(button,"ajout_produit");




label1=lookup_widget(button,"labelerreurnom");
label2=lookup_widget(button,"labelerreurquantite");
label3=lookup_widget(button,"labelerreurprixunitaire");

input2=lookup_widget(button,"entryNom_Produit");
input3=lookup_widget(button,"entryType_Produit");
input5=lookup_widget(button,"entryQuantite_Produit");
input6=lookup_widget(button,"entryPrixunitaire_Produit");

inputjour=lookup_widget(button,"spinbutton_jourajoutproduit");
inputmois=lookup_widget(button,"spinbutton_moisajoutproduit");
inputannee=lookup_widget(button,"spinbutton_anneeajoutproduit");

jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputjour));
mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputmois));
annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputannee));

sprintf(jour,"%d", jour1);
sprintf(mois,"%d", mois1);
sprintf(annee,"%d", annee1);

	
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input2)),"")==0){gtk_widget_show (label1);a=0;}
else{gtk_widget_hide (label1);strcpy(p.nomp,gtk_entry_get_text(GTK_ENTRY(input2)));a=1;}
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input5)),"")==0){gtk_widget_show (label2);b=0;}
else{gtk_widget_hide (label2);strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(input5)));b=1;}
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input6)),"")==0){gtk_widget_show (label3);c=0;}
else{gtk_widget_hide (label3);strcpy(p.prixunitaire,gtk_entry_get_text(GTK_ENTRY(input6)));c=1;}


if(b==1 && a==1 && c==1 && gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))!=0){


strcpy(p.typep,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));


strcpy(p.date_dajout,jour);
	strcat(p.date_dajout,"/");
	strcat(p.date_dajout,mois);
	strcat(p.date_dajout,"/");
	strcat(p.date_dajout,annee);


FILE *fp;
   char ch;
   int linesCount=0;
fp=fopen("produit.txt","r");
while((ch=fgetc(fp))!=EOF) {
      if(ch=='\n')
         linesCount++;
   }
   //close the file
   fclose(fp);
sprintf(p.id,"%d",linesCount+1);


ajouter_produit(&p);


}

gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");
gtk_entry_set_text(GTK_ENTRY(input6),"");
gtk_entry_set_text(GTK_ENTRY(input1),"");





}


void
on_button_afficher_ajouter_produit_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *ajout_produit;

GtkWidget *Afficher_produit;


Afficher_produit=lookup_widget(button,"Afficher_produit");
gtk_widget_destroy(Afficher_produit);

ajout_produit=create_ajout_produit();

gtk_widget_show(ajout_produit);





}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_modifier_produit_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *modifie_produit;



GtkWidget *label_idp;
GtkWidget *entry_modifiernomp;
GtkWidget *entry_modifiertypep;
GtkWidget *entry_modifierquantitep;
GtkWidget *label_modifierdatep;
GtkWidget *entry_modifierprixp;


produit p;



label_idp=lookup_widget(button,"labelid");
label_modifierdatep= lookup_widget(button, "labeldatedajout");
entry_modifiernomp= lookup_widget(button, "entrynom_produit");
entry_modifiertypep= lookup_widget(button, "entrytype_produit");
entry_modifierquantitep= lookup_widget(button, "entryquantite_produit");
entry_modifierprixp= lookup_widget(button, "entryprixunitaire_produit");


strcpy(p.id,gtk_label_get_text(GTK_LABEL(label_idp)));
strcpy(p.date_dajout,gtk_label_get_text(GTK_LABEL(label_modifierdatep)));
strcpy(p.typep,gtk_entry_get_text(GTK_ENTRY(entry_modifiertypep)));
strcpy(p.nomp,gtk_entry_get_text(GTK_ENTRY(entry_modifiernomp)));
strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(entry_modifierquantitep)));
strcpy(p.prixunitaire,gtk_entry_get_text(GTK_ENTRY(entry_modifierprixp)));




modifier_produit(p);


gtk_entry_set_text(GTK_ENTRY(entry_modifiernomp),"");
gtk_entry_set_text(GTK_ENTRY(entry_modifiertypep),"");
gtk_entry_set_text(GTK_ENTRY(entry_modifierquantitep),"");
gtk_entry_set_text(GTK_ENTRY(entry_modifierprixp),"");



}


void
on_Pr__c__dent_ajouter_afficher_produit_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
produit p;
GtkWidget *ajout_produit;
GtkWidget *treeview_produit;
GtkWidget *Afficher_produit;


ajout_produit=lookup_widget(button,"ajout_produit");
gtk_widget_destroy(ajout_produit);

Afficher_produit = create_Afficher_produit(); 
gtk_widget_show (Afficher_produit);

treeview_produit=lookup_widget(Afficher_produit,"treeview1");
afficher_produit(treeview_produit,p);
}





void
on_button_afficher_supprimer_produit_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{

 GtkWidget *Afficher_produit;
 GtkWidget *treeview1;
GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;
GtkWidget* p;
Afficher_produit=lookup_widget(button,"Afficher_produit");
p=lookup_widget(Afficher_produit,"treeview1");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
 if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {
                gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
/* supprimer la ligne de treeViw puis decharger la nouvelle treeView(sans la ligne a supprimer) vers le fichier*/
		supprimer_produit(GTK_LIST_STORE(model),"produit.txt");
		  
}

}


void
on_buttongestionproduits_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
produit p;
GtkWidget *employe;
GtkWidget *treeview_produit;
GtkWidget *Afficher_produit;




employe=lookup_widget(button,"employe");


Afficher_produit = create_Afficher_produit(); 
gtk_widget_show (Afficher_produit);


treeview_produit=lookup_widget(Afficher_produit,"treeview1");
afficher_produit(treeview_produit,p);
gtk_widget_destroy(employe);
}


void
on_button_afficher_modifier_produit_clicked
                                        (GtkWidget      *button,
                                        gpointer         user_data)
{
 GtkWidget *Afficher_produit;
 GtkWidget *modifie_produit;
modifie_produit=lookup_widget(button,"modifie_produit");
Afficher_produit=lookup_widget(button,"Afficher_produit");
modifie_produit = create_modifie_produit ();



	gchar *id;
        gchar *date;

      
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *p=lookup_widget(Afficher_produit,"treeview1");
 	GtkWidget *labelid=lookup_widget(modifie_produit,"labelid");
	GtkWidget *labeldatedajout=lookup_widget(modifie_produit,"labeldatedajout");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));

        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&id,3,&date,-1);//recuperer les information de la ligne selectionneé

		gtk_label_set_text(GTK_LABEL(labelid),id);
		gtk_label_set_text(GTK_LABEL(labeldatedajout),date);



gtk_widget_show (modifie_produit);
gtk_widget_destroy (Afficher_produit);
}

}



void
on_button_rechercheproduit_clicked     (GtkWidget      *button_rechercheproduit,
                                        gpointer         user_data)
{
/*GtkWidget *combobox_rechercheidproduit;

char ref[50][50];
int i,nbr;
combobox_rechercheidproduit=lookup_widget(button_rechercheproduit,"combobox_rechercheidproduit");
nbr=liste_produits(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox_rechercheidproduit),_(ref[i]));
}*/

}

void
on_button_recherche_produit_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
produit p;
 GtkWidget *Afficher_produit;
char ID[30];
char NOM[30];
Afficher_produit = lookup_widget(button,"Afficher_produit");
GtkWidget *entry = lookup_widget(Afficher_produit,"entry_idp");
GtkWidget *entry1 = lookup_widget(Afficher_produit,"entry_nomp");

strcpy(ID,gtk_entry_get_text(GTK_ENTRY(entry)));
strcpy(NOM,gtk_entry_get_text(GTK_ENTRY(entry1)));

GtkWidget *treeview2;
treeview2=lookup_widget(Afficher_produit,"treeview1");

cherchertree(treeview2,p,ID,NOM);

}


void
on_button_modifier_afficher_produit_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
produit p;
GtkWidget *modifie_produit;
GtkWidget *treeview_produit;
GtkWidget *Afficher_produit;
modifie_produit=lookup_widget(button,"modifie_produit");
Afficher_produit=lookup_widget(button,"Afficher_produit");
gtk_widget_destroy(modifie_produit);
Afficher_produit = create_Afficher_produit(); 
gtk_widget_show (Afficher_produit);




treeview_produit=lookup_widget(Afficher_produit,"treeview1");
afficher_produit(treeview_produit,p);

}


void
on_ok_clicked                          (GtkWidget       *button,
                                        gpointer         user_data)
{
char ref[50][50];
int i,nbr;
GtkWidget *combobox1;
combobox1=lookup_widget(button,"comboboxtype");
nbr=liste_type(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox1),_(ref[i]));

}
}


void
on_buttonajouteremploye_clicked        (GtkWidget      *button,
                                        gpointer         user_data)
{
int a=0;
int b=0;
int c=0;
char jourd[50];
char moisd[50];
char anneed[50];
char joure[50];
char moise[50];
char anneee[50];
GtkWidget *label1;
GtkWidget *label2;
GtkWidget *label3;
int jour1,mois1,annee1,jour2,mois2,annee2;
FILE *f1;
employe e;
GtkWidget *input1, *input2,*input3,*input4,*input5,*inputjourn,*inputmoisn,*inputanneen,*inputjoure,*inputmoise,*inputanneee;
GtkWidget *ajout_employe;
GtkWidget *Afficher_employe;
GtkTreeView *treeview_employe;
GtkWidget *combobox2;
GtkWidget *combobox3;
GtkWidget *combobox4;

combobox2=lookup_widget(button,"comboboxsexe");
combobox3=lookup_widget(button,"comboboxsituation");
combobox4=lookup_widget(button,"comboboxspecialite");


ajout_employe = lookup_widget(button,"ajout_employe");



input1=lookup_widget(button,"entrynomemploye");
input2=lookup_widget(button,"entryprenomemploye");
input3=lookup_widget(button,"entrycinemploye");
input4=lookup_widget(button,"entryadresseemploye");
input5=lookup_widget(button,"entrysalaireactuelemploye");

inputjourn=lookup_widget(button,"spinbutton_jouremploye");
inputmoisn=lookup_widget(button,"spinbutton_moisemploye");
inputanneen=lookup_widget(button,"spinbutton_anneeemploye");

inputjoure=lookup_widget(button,"spinbutton_jourajoutemploye");
inputmoise=lookup_widget(button,"spinbutton_moisajoutemploye");
inputanneee=lookup_widget(button,"spinbutton_anneeajoutemploye");


jour1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputjourn));
mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputmoisn));
annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputanneen));

jour2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputjoure));
mois2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputmoise));
annee2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(inputanneee));

sprintf(jourd,"%d", jour1);
sprintf(moisd,"%d", mois1);
sprintf(anneed,"%d", annee1);

sprintf(joure,"%d", jour2);
sprintf(moise,"%d", mois2);
sprintf(anneee,"%d", annee2);

strcpy(e.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(e.situation_familiale,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));	
strcpy(e.specialite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

strcpy(e.nome,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.prenome,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.ciN,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(e.salaire_actuel,gtk_entry_get_text(GTK_ENTRY(input5)));

strcpy(e.date_naissance,jourd);
	strcat(e.date_naissance,"/");
	strcat(e.date_naissance,moisd);
	strcat(e.date_naissance,"/");
	strcat(e.date_naissance,anneed);

strcpy(e.date_dembauche,joure);
	strcat(e.date_dembauche,"/");
	strcat(e.date_dembauche,moise);
	strcat(e.date_dembauche,"/");
	strcat(e.date_dembauche,anneee);



FILE *fp;
   char ch;
   int linesCount=0;
fp=fopen("employe.txt","r");
while((ch=fgetc(fp))!=EOF) {
      if(ch=='\n')
         linesCount++;
   }
   //close the file
   fclose(fp);
sprintf(e.ide,"%d",linesCount+1);


ajouter_employe(&e);


/*if(strcmp(gtk_entry_get_text(GTK_ENTRY(input2)),"")==0){gtk_widget_show (label1);a=0;}
else{gtk_widget_hide (label1);strcpy(p.nomp,gtk_entry_get_text(GTK_ENTRY(input2)));a=1;}
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input5)),"")==0){gtk_widget_show (label2);b=0;}
else{gtk_widget_hide (label2);strcpy(p.quantite,gtk_entry_get_text(GTK_ENTRY(input5)));b=1;}
if(strcmp(gtk_entry_get_text(GTK_ENTRY(input6)),"")==0){gtk_widget_show (label3);c=0;}
else{gtk_widget_hide (label3);strcpy(p.prixunitaire,gtk_entry_get_text(GTK_ENTRY(input6)));c=1;}


if(b==1 && a==1 && c==1 && gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))!=0){


strcpy(p.typep,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));


strcpy(p.date_dajout,jour);
	strcat(p.date_dajout,"/");
	strcat(p.date_dajout,mois);
	strcat(p.date_dajout,"/");
	strcat(p.date_dajout,annee);

sprintf(p.id,"%d",counter);
counter++;


ajouter_produit(&p);


}*/

gtk_entry_set_text(GTK_ENTRY(input1),"");
gtk_entry_set_text(GTK_ENTRY(input2),"");
gtk_entry_set_text(GTK_ENTRY(input3),"");
gtk_entry_set_text(GTK_ENTRY(input4),"");
gtk_entry_set_text(GTK_ENTRY(input5),"");

}


void
on_buttonprecedentajouterafficheremploye_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
employe e;
GtkWidget *ajout_employe;
GtkWidget *treeview_employe;
GtkWidget *Afficher_employe;


ajout_employe=lookup_widget(button,"ajout_employe");
gtk_widget_destroy(ajout_employe);

Afficher_employe = create_Afficher_employe(); 
gtk_widget_show (Afficher_employe);

treeview_employe=lookup_widget(Afficher_employe,"treeview_employe");
afficher_employe(treeview_employe,e);
}


void
on_ok2_clicked                         (GtkWidget       *button,
                                        gpointer         user_data)
{
char ref[50][50];
int i,nbr;
GtkWidget *combobox2;
combobox2=lookup_widget(button,"comboboxsexe");
nbr=liste_type(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox2),_(ref[i]));

}
}


void
on_ok3_clicked                         (GtkWidget       *button,
                                        gpointer         user_data)
{
char ref[50][50];
int i,nbr;
GtkWidget *combobox3;
combobox3=lookup_widget(button,"comboboxsituation");
nbr=liste_type(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox3),_(ref[i]));

}
}


void
on_ok4_clicked                         (GtkWidget       *button,
                                        gpointer         user_data)
{
char ref[50][50];
int i,nbr;
GtkWidget *combobox4;
combobox4=lookup_widget(button,"comboboxspecialite");
nbr=liste_type(ref);
for(i=0;i<nbr;i++)
{

gtk_combo_box_append_text(GTK_COMBO_BOX(combobox4),_(ref[i]));

}
}


void
on_buttonajouterafficheremploye_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *ajout_employe;

GtkWidget *Afficher_employe;


Afficher_employe=lookup_widget(button,"Afficher_employe");
gtk_widget_destroy(Afficher_employe);

ajout_employe=create_ajout_employe();

gtk_widget_show(ajout_employe);
}


void
on_buttonmodifierafficheremploye_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher_employe;
 GtkWidget *modifier_employe;
modifier_employe=lookup_widget(button,"modifier_employe");
Afficher_employe=lookup_widget(button,"Afficher_employe");
modifier_employe = create_modifier_employe ();



	gchar *ide;
        gchar *daten;
	 gchar *datee;


      
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget *e=lookup_widget(Afficher_employe,"treeview_employe");
 	GtkWidget *labelide=lookup_widget(modifier_employe,"label63");
	GtkWidget *labeldatenaissance=lookup_widget(modifier_employe,"label64");
	GtkWidget *labeldateembauche=lookup_widget(modifier_employe,"label65");

        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(e));

        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,&ide,4,&daten,8,&datee,-1);//recuperer les information de la ligne selectionneé

		gtk_label_set_text(GTK_LABEL(labelide),ide);
		gtk_label_set_text(GTK_LABEL(labeldatenaissance),daten);
		gtk_label_set_text(GTK_LABEL(labeldateembauche),datee);





gtk_widget_show (modifier_employe);
gtk_widget_destroy (Afficher_employe);
}
}


void
on_buttonprecedentaffichergestionemploye_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *Afficher_employe;

GtkWidget *admin;


admin=lookup_widget(button,"admin");
Afficher_employe=lookup_widget(button,"Afficher_employe");
gtk_widget_destroy(Afficher_employe);

admin=create_admin();

gtk_widget_show(admin);


}


void
on_buttonrechercheafficheremploye_clicked
                                        (GtkWidget      *button,
                                        gpointer         user_data)
{
employe e;
 GtkWidget *Afficher_employe;
char ID1[30];
char NOM1[30];
Afficher_employe = lookup_widget(button,"Afficher_employe");
GtkWidget *entry1 = lookup_widget(Afficher_employe,"entryide");
GtkWidget *entry2 = lookup_widget(Afficher_employe,"entrynome");

strcpy(ID1,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(NOM1,gtk_entry_get_text(GTK_ENTRY(entry2)));

GtkWidget *treeview2;
treeview2=lookup_widget(Afficher_employe,"treeview_employe");

cherchertreee(treeview2,e,ID1,NOM1);

}


void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://mail.google.com/mail/u/0/#inbox");
}


void
on_buttonacceuilespaceemploye_clicked  (GtkWidget      *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *accueil;

GtkWidget *employe;

GtkWidget *admin;



accueil=lookup_widget(button,"accueil");
gtk_widget_destroy(accueil);

employe=create_employe();

gtk_widget_show(employe);
}


void
on_buttonaccueilespaceadmin_clicked    (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *accueil;

GtkWidget *admin;

GtkWidget *employe;


accueil=lookup_widget(button,"accueil");
gtk_widget_destroy(accueil);

admin=create_admin();

gtk_widget_show(admin);
}


void
on_buttonprecedentadminaccueil_clicked (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *accueil;

GtkWidget *admin;

GtkWidget *employe;


admin=lookup_widget(button,"admin");
gtk_widget_destroy(admin);

accueil=create_accueil();

gtk_widget_show(accueil);
}


void
on_buttonprecedentemployeaccueil_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *f1;


GtkWidget *accueil;

GtkWidget *admin;

GtkWidget *employe;


employe=lookup_widget(button,"employe");
gtk_widget_destroy(employe);

accueil=create_accueil();

gtk_widget_show(accueil);
}


void
on_buttonadminafficheremploye_clicked  (GtkWidget       *button,
                                        gpointer         user_data)
{
employe e;
GtkWidget *admin;
GtkWidget *treeview_employe;
GtkWidget *Afficher_employe;


admin=lookup_widget(button,"admin");


Afficher_employe = create_Afficher_employe(); 
gtk_widget_show (Afficher_employe);


treeview_employe=lookup_widget(Afficher_employe,"treeview_employe");
afficher_employe(treeview_employe,e);
gtk_widget_destroy(admin);
}


void
on_buttonsupprimerafficheremploye_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Afficher_employe;
 GtkWidget *treeview_employe;
GtkTreeSelection *selection;
  GtkTreeModel     *model;
  GtkTreeIter       iter;
GtkWidget* e;
Afficher_employe=lookup_widget(button,"Afficher_employe");
e=lookup_widget(Afficher_employe,"treeview_employe");
  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(e));
 if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {
                gtk_list_store_remove(GTK_LIST_STORE(model),&iter);
/* supprimer la ligne de treeViw puis decharger la nouvelle treeView(sans la ligne a supprimer) vers le fichier*/
		supprimer_employe(GTK_LIST_STORE(model),"employe.txt");
		  
}

}


void
on_buttonmodifieremploye_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{




GtkWidget *labelide;
GtkWidget *labeldatenaissance;
GtkWidget *labeldateembauche;
GtkWidget *entrynome;
GtkWidget *entryprenome;
GtkWidget *entrycin;
GtkWidget *entryadresse;
GtkWidget *entrysalaireactuel;
GtkWidget *combobox1,*combobox2,*combobox3;


employe e;



labelide=lookup_widget(button,"label63");
labeldatenaissance= lookup_widget(button, "label64");
labeldateembauche= lookup_widget(button, "label65");
entrynome= lookup_widget(button, "entrynome");
entryprenome= lookup_widget(button, "entryprenome");
entrycin= lookup_widget(button, "entrycin");
entryadresse=lookup_widget(button, "entryadresse");
entrysalaireactuel= lookup_widget(button, "entrysalaireactuel");


combobox1= lookup_widget(button, "comboboxsexee");
combobox2= lookup_widget(button, "comboboxsituationn");
combobox3= lookup_widget(button, "comboboxspecialitee");





strcpy(e.ide,gtk_label_get_text(GTK_LABEL(labelide)));
strcpy(e.date_naissance,gtk_label_get_text(GTK_LABEL(labeldatenaissance)));
strcpy(e.date_dembauche,gtk_label_get_text(GTK_LABEL(labeldateembauche)));

strcpy(e.nome,gtk_entry_get_text(GTK_ENTRY(entrynome)));
strcpy(e.prenome,gtk_entry_get_text(GTK_ENTRY(entryprenome)));
strcpy(e.ciN,gtk_entry_get_text(GTK_ENTRY(entrycin)));
strcpy(e.adresse,gtk_entry_get_text(GTK_ENTRY(entryadresse)));
strcpy(e.salaire_actuel,gtk_entry_get_text(GTK_ENTRY(entrysalaireactuel)));

strcpy(e.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(e.situation_familiale,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));	
strcpy(e.specialite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));


modifier_employe(e);


gtk_entry_set_text(GTK_ENTRY(entrynome),"");
gtk_entry_set_text(GTK_ENTRY(entryprenome),"");
gtk_entry_set_text(GTK_ENTRY(entrycin),"");
gtk_entry_set_text(GTK_ENTRY(entryadresse),"");
gtk_entry_set_text(GTK_ENTRY(entrysalaireactuel),"");
}


void
on_buttonprecedentmodifierafficheremploye_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
employe e;
GtkWidget *modifier_employe;
GtkWidget *treeview_employe;
GtkWidget *Afficher_employe;


modifier_employe=lookup_widget(button,"modifier_employe");
gtk_widget_destroy(modifier_employe);

Afficher_employe = create_Afficher_employe(); 
gtk_widget_show (Afficher_employe);

treeview_employe=lookup_widget(Afficher_employe,"treeview_employe");
afficher_employe(treeview_employe,e);
}




void
on_buttonafficher_acceuil_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
 produit p;
GtkWidget *Afficher_produit;
GtkWidget *employe;



Afficher_produit=lookup_widget(button,"Afficher_produit");
gtk_widget_destroy(Afficher_produit);

employe = create_employe(); 
gtk_widget_show (employe);
}


void
on_buttoncamera_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}

