/* File : listDoubleLinier.c */
/* ADT list linier dengan representasi fisik pointer double*/
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 22 November 2021*/

#include <stdio.h>
#include <stdlib.h>
#include "listDoubleLinier.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */
    /*Kamus lokal*/

    /*Algoritma*/
    return First(L)==Nil;
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L){
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
    /*Kamus lokal*/

    /*Algoritma*/
    First(*L)=Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P = (address) malloc(sizeof(ElmtList));
    if (P != Nil )
    {
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
    /*Kamus lokal*/

    /*Algoritma*/
    info(*P)=0;
    next(*P)=Nil;
    prev(*P)=Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=First(*L);
    prev(P)=Nil;
    if(!ListEmpty(*L)){
        prev(First(*L))=P;
        First(*L)=P;
    }
    else{
        First(*L)=P;
    }
}

void InsertAfter (List *L, address P, address Prec){
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
    /*Kamus lokal*/

    /*Algoritma*/
    next(P)=next(Prec);
    prev(next(Prec))=P;
    next(Prec)=P;
    prev(P)=Prec;
}

void InsertLast (List *L, address P){
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
    /*Kamus lokal*/
    address last;

    /*Algroitma*/
    if(First(*L)==Nil){
        InsertFirst(&(*L),P);
    }
    else{
        last=First(*L);
        while(next(last)!=Nil){
            last=next(last);
        }
        next(last)=P;
        prev(P)=last;
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
    /*Kamus lokal*/

    /*Algoritma*/
    *P=First(*L);
    First(*L)=next(First(*L));
    if(!ListEmpty(*L)){
        prev(First(*L))=Nil;
    }
}

void DelLast (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
    /*kamus lokal*/
    address last, precLast;

    /*Algoritma*/
    last=First(*L);
    precLast=Nil;
    while(next(last)!=Nil){
        precLast=last;
        last=next(last);
    }
    *P=last;
    if(precLast==Nil){
        First(*L)=Nil;
    }
    else{
        prev(last)=Nil;
        next(precLast)=Nil;
    }
}

void DelAfter (List *L, address * Pdel, address Prec){
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
    /*Kamus lokal*/

    /*Algoritma*/
    *Pdel=next(Prec);
    next(Prec)=next(next(Prec));
    if(next(Prec)!=Nil){
        prev(next(Prec))=Prec;
    }
    next(*Pdel)=Nil;
    prev(*Pdel)=Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
void InsVFirst (List *L, infotype X){
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        InsertFirst(&(*L),P);
    }
}

void InsVLast (List *L, infotype X){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen terakhir L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  di akhir yaitu
   			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    P=Alokasi(X);
    if(P!=Nil){
        InsertLast(&(*L),P);
    }
}

void InsVAfter (List *L, infotype X){
/* I.S. 	: L mungkin kosong
   F.S.		: X ditambahkan sebagai elemen setelah Prec
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
   			  setelah Prec yaitu
   			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
   			  Jika alokasi gagal, maka I.S.= F.S. */
    /*Kamus lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    if(!ListEmpty(*L)){
        AdrLast(&(*L),&Prec,&Last);
        P=Alokasi(X);
        if(P!=Nil){
            InsertAfter(&(*L),P,Prec);
        }
    }
    else{
        InsVFirst(&(*L),X);
    }
}

void AdrLast(List *L, address *Prec, address *Last){
/*mencari alamat elemen terakhir dan sebelumnya*/
    /*Kamus lokal*/

    /*Algoritma*/
    *Last=First(*L);
    *Prec=Nil;
    while(next(*Last)!=Nil){
        *Prec=*Last;
        *Last=next(*Last);
    }
}

/* Penghapusan ELemen */
void DelVFirst (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
   			 dan alamat elemen pertama di-dealokasi */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    *X=info(First(*L));
    DelFirst(&(*L),&P);
    Dealokasi(&P);
}


void DelVLast (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
   			  dan alamat elemen terakhir di-dealokasi */
    /*Kamus  lokal*/
    address P;

    /*Algoritma*/
    DelLast(&(*L),&P);
    *X=info(P);
    Dealokasi(&P);
}

void DelVAfter (List *L, infotype *X){
/* I.S.		: List L tidak kosong
   F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
   			  dan alamat elemen setelah Prec di-dealokasi */
    /*Kamus lokal*/
    address P, Prec, Last;

    /*Algoritma*/
    AdrLast(&(*L),&Prec,&Last);
    DelAfter(&(*L),&P,Prec);
    *X=info(P);
    Dealokasi(&P);
}

/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L){
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
    /*Kamus lokal*/
    address P;

    /*Algoritma*/
    if(ListEmpty(L)){
        printf("list kosong\n");
    }
    else{
        P=First(L);
        while(P!=Nil){
            printf("%d ", info(P));
            P=next(P);
        }
        printf("\n");
    }
}

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
    /*Kamus lokal*/
    address P;
    int num;

    /*Algoritma*/
    if(ListEmpty(L)){
        return 0;
    }
    else{
        num = 0;
        P = First(L);
        while(P!=Nil){
            num++;
            P = next(P);
        }
        return num;
    }
}

void InversList (List *L){
    //Kamus lokal
    address Prev,Cur,Next;

    //algoritma
    Cur = First(*L);
	Prev=Nil;
	while(Cur !=  Nil) {
        Next = next(Cur);
		next(Cur) = Prev;
		Prev = Cur;
		Cur = Next;
    }
    First(*L) = Prev;
}

boolean IsSimetriList (List L1, List L2){
    //Kamus
    boolean Sim;
    address P,Q;

    //Algi
    if(NbElmt(L1) != NbElmt(L2)) {
        Sim = false;
    }
	else{
        P = First(L1);
        Q = First(L2);
        Sim = true;
        while (P!=Nil && Sim==true) {
            if(info(P) != info(Q)) {
                Sim =false;
            }
            else{
                P = next(P);
                Q = next(Q);
            }
        }
	}
	return Sim;
}

void Konkat (List *L1, List *L2, List *L3){
    /*kamus lokal*/
    address P,Q;

    /*Algroitma*/
    P=First(*L1);
    while(P!=Nil){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(&(*L3),Q);
            P=next(P);
        }
        else{
            while(!ListEmpty(*L3)){
                DelFirst(&(*L3),&P);
                Dealokasi(&P);
            }
        }
    }
    P=First(*L2);
    while(P!=Nil){
        Q=Alokasi(info(P));
        if(Q!=Nil){
            InsertLast(&(*L3),Q);
            P=next(P);
        }
        else{
            while(!ListEmpty(*L3)){
                DelFirst(&(*L3),&P);
                Dealokasi(&P);
            }
        }
    }
}



