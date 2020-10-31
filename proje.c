#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <string.h>
#include <conio.h>

struct personel{
 char isim[100];
 long long int TCkimlikNo;
 long long int telefon;
char eposta[100];
char adres[100];
struct personel *sonraki;
 };
 void personel_silme(struct personel **ilk, char no[20])
 {
     struct personel *gecici;
     struct personel *silinecek;
     struct personel *onceki;
     if(*ilk!=NULL) // Müsteri listesi bos degilse
     {
         if(strcmp((*ilk)->TCkimlikNo,no)==0) // eger silinceke personel en bastakiyse
         {
             silinecek=*ilk;
             *ilk=(*ilk)->sonraki;
             free(silinecek);
         }
         else { // eger silinicek personel ortada veya sondaysa
            onceki=*ilk;
            gecici=*ilk;
            //aranan personeli liste sonuna kadar arar
            while(strcmp(gecici->TCkimlikNo,no)!=0 && gecici->sonraki!=NULL)
            {
                // onceki ve gecici her defasinda birer kaydirilir
                onceki=gecici;
                gecici=gecici->sonraki;
            }
            // aranilan musteriye ulasildiginda
            if (strcmp(gecici->TCkimlikNo,no)==0)
              {
                 silinecek=gecici; // gecici silincek yapilir
                 onceki->sonraki=gecici->sonraki; // aradaki bag koparilir
                 free(silinecek); // silincek serbest birakilir
               }
               else printf("\n");


         }

     }
 }

int main()
{

    setlocale(LC_ALL, "Turkish");
    int m_sayi,kisi,i;
    int silme;
    int sayi;
    char cikis;
    char harf;
    char isim[100];
    long long int TC;
      FILE *dosya;
    dosya=fopen("Personel.txt","w+");
    if(dosya==NULL)
    {
        printf("Dosya acma hatasi!");
        exit(1);
    }


fclose(dosya);


   struct personel personel_bilgi;
      ana_menu:






   printf("\tPERSONEL BILGI SISTEMI\n");
   printf("ISLEMLER\n");
   printf("1.Kayit Ekle\n");
   printf("2.Personel Listele\n");
   printf("3.Kaydi Duzenle\n");
   printf("4.TC Kimlik No Kayit Bul\n");
   printf("5.Isim ile Kayit Bul\n");
   printf("6.Kayit sil\n");
   printf("0.Cikis\n");
   printf("Lutfen Bir Menu Seciniz:"); scanf("%d",&m_sayi);






if(0<=m_sayi && m_sayi<7)
{


   if(m_sayi==1)
   {
       dosya=fopen("Personel.txt","a+");
    if(dosya==NULL)
    {
        printf("Dosya acma hatasi!");
        exit(1);
    }

       printf("personel sayisini giriniz:"); scanf("%d",&kisi);


       for(i=0; i<kisi; i++)
        {
            printf("\t%d.Personel Bilgilerini Giriniz\n",i+1);
            printf(" Ismini giriniz:"); scanf("%s",&personel_bilgi.isim);
            printf("TC kimlik numarasini giriniz:"); scanf("%lld",&personel_bilgi.TCkimlikNo);
            printf("Telefon Numarasini Giriniz:"); scanf("%lld",&personel_bilgi.telefon);
            printf("Epostasini giriniz:"); scanf("%s",&personel_bilgi.eposta);
            printf("Adresini giriniz:"); scanf("%s",&personel_bilgi.adres);
            fprintf(dosya,"%s\t",personel_bilgi.isim);
            fprintf(dosya,"%lld\t",personel_bilgi.TCkimlikNo);
            fprintf(dosya,"%lld\t",personel_bilgi.telefon);
            fprintf(dosya,"%s\t",personel_bilgi.eposta);
            fprintf(dosya,"%s\n",personel_bilgi.adres);



        }
        fclose(dosya);

   }


   if(m_sayi==2)
   {
dosya=fopen("Personel.txt","r+");


while(!feof(dosya))
{


           fscanf(dosya,"%s",&personel_bilgi.isim);
           fscanf(dosya,"%lld",&personel_bilgi.TCkimlikNo);
           fscanf(dosya,"%lld",&personel_bilgi.telefon);
           fscanf(dosya,"%s",&personel_bilgi.eposta);
           fscanf(dosya,"%s",&personel_bilgi.adres);
           printf(" Ismi:%s\n",personel_bilgi.isim);
           printf(" Tc:%lld\n",personel_bilgi.TCkimlikNo);
           printf(" Tel:%lld\n",personel_bilgi.telefon);
           printf(" Eposta:%s\n",personel_bilgi.eposta);
           printf(" Adres:%s\n",personel_bilgi.adres);



       }
       fclose(dosya);



   }
   if(m_sayi== 3)
   { if(dosya=fopen("Personel.txt","rb+")==NULL)
   {
       printf("dosya okuma hatasi\n");
       exit(1);
   }

       printf("Personelin adini girinizi:"); scanf("%s",&isim);
       if(isim==personel_bilgi.isim)
       {

            printf(" Ismini giriniz:"); scanf("%s",&personel_bilgi.isim);
            printf("Telefon Numarasini Giriniz:"); scanf("%lld",&personel_bilgi.telefon);
            printf("Epostasini giriniz:"); scanf("%s",&personel_bilgi.eposta);
            printf("Adresini giriniz:"); scanf("%s",&personel_bilgi.adres);
            fprintf(dosya,"%s\t",personel_bilgi.isim);
            fprintf(dosya,"%lld\t",personel_bilgi.telefon);
            fprintf(dosya,"%s\t",personel_bilgi.eposta);
            fprintf(dosya,"%s\n",personel_bilgi.adres);
    }
       else{printf("personel kayit aramayi tekrardan yapmak istiyor musunuz?"); scanf("%s",&harf);
         if('E'  || 'e')
         {
            goto ana_menu;
         }

           }
       fclose(dosya);

   }
   if(m_sayi== 4)
   {
dosya=fopen("Personel.txt","r");

printf("TC giriniz:");  scanf("%lld",&TC);
while (fscanf(dosya,"%s  %d",personel_bilgi.isim,personel_bilgi.TCkimlikNo)!= EOF)
{
if (personel_bilgi.TCkimlikNo==TC)
{
    printf ("%s  %lld",personel_bilgi.isim,personel_bilgi.TCkimlikNo);
}
else {
printf ("Kayit bulunamadi");
}
}
fclose(dosya);

   }
   if(m_sayi==5)
   { FILE *dosya=fopen("Personel.txt","r");

                 printf("aranan ismi giriniz:");
                 scanf("%s",&isim);
                 while(!feof(dosya))
                {

                   fscanf(dosya,"%s ",personel_bilgi.isim);
                   if(strcmp(personel_bilgi.isim,isim)==0)
                    {
                       printf("%s \n",personel_bilgi.isim);
                       printf("%lld\n",personel_bilgi.TCkimlikNo);
                    }
                 }
                 fclose(dosya);

   }

   if(m_sayi==6)
   {
       alt_menu:
     if(dosya=fopen("Personel.txt","rb+")==NULL)
     {
         printf("dosya okunmadi");
         exit(1);
     }

                 printf("TC Kimlik NO giriniz:");
                 scanf("%lld",&TC);
                    while(!feof(dosya))
                {

                   fscanf(dosya,"%lld ",personel_bilgi.TCkimlikNo);
                   if(strcmp(personel_bilgi.TCkimlikNo,TC)==0)
                    {
                       printf("%lld \n",personel_bilgi.TCkimlikNo);

                    }






          printf("kayit silme amaciyla tekrar arama yapip yapmak istiyor musunuz? 'E/e/h/H'"); scanf("%s",&harf);
          if(harf=='e'|| harf   =='E')
      {
          goto alt_menu;
      }

      else

      {
            goto ana_menu;

      }
                }


      fclose(dosya);




   }


  if(m_sayi==0)
   {
       printf("***Cikis***\n");
      printf("Cikis yapmak istediginizden eminseniz lutfen 'E/e/h/H'  basiniz. "); scanf("%s",&cikis);
      if(cikis=='e'|| cikis=='E')
      {

        printf("Programimizdan cikis yaptiniz kapatmak icin herhangi bir tusa basin.");

      }
      else
      {
          goto ana_menu;
      }
   }
}


else { printf("lütfen 1 ile 6 arasinda sayi giriniz!!\n");
goto ana_menu;

}



return 0;

}
