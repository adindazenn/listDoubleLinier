/* File : driverListDoubleLinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer double*/
/* Representasi address dengan pointer */
/* infotype adalah integer */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 22 November 2021*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "listDoubleLinier.h"

int main(){
    /*Kamus main*/
    List A,B,Kon;
    address P,Q,R;
    infotype Y;

    /*Algoritma*/
    CreateList(&A);
    if(ListEmpty(A)){
        printf("List kosong\n");
    }
    else{
        printf("List tidak kosong\n");
    }
    printf("\n");

    R=Alokasi(1);
    InsertFirst(&A,R);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("\n");

    Q=Alokasi(2);
    InsertFirst(&A,Q);
    printf("=====Insert First=====\n");
    PrintInfo(A);
    printf("address prev(1) = %x\n",prev(R));
    printf("address 2 = %x\n",Q);
    printf("\n");

    P=Alokasi(5);
    InsertAfter(&A,P,Q);
    printf("=====Insert After=====\n");
    PrintInfo(A);
    printf("address prev(5) = %x\n",prev(P));
    printf("address 2 = %x\n",Q);
    printf("\n");

    Q=Alokasi(3);
    InsertLast(&A,Q);
    printf("=====Insert Last=====\n");
    PrintInfo(A);
    printf("address prev(3) = %x\n",prev(Q));
    printf("address 1 = %x\n",R);
    printf("\n");

    DelFirst(&A,&P);
    printf("=====Del First=====\n");
    PrintInfo(A);
    printf("address prev(5) = %x\n",prev(First(A)));
    printf("\n");

    DelLast(&A,&P);
    printf("=====Del Last=====\n");
    PrintInfo(A);
    printf("\n");

    Q=Alokasi(3);
    InsertFirst(&A,Q);
    printf("=====List A=====\n");
    PrintInfo(A);
    printf("\n");

    DelAfter(&A,&P,First(A));
    printf("=====Del After=====\n");
    PrintInfo(A);
    printf("address prev(1) = %x\n",prev(R));
    printf("address 3 = %x\n",Q);
    printf("\n");

    DelAfter(&A,&P,First(A));
    printf("=====Del After=====\n");
    PrintInfo(A);
    printf("\n");

    InsVFirst(&A,5);
    printf("=====Ins V First=====\n");
    PrintInfo(A);
    printf("\n");

    InsVLast(&A,3);
    printf("=====Ins V Last=====\n");
    PrintInfo(A);
    printf("\n");

    InsVAfter(&A,4);
    printf("=====Ins V After=====\n");
    PrintInfo(A);
    printf("\n");

    DelVFirst(&A,&Y);
    printf("=====Del V First=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVLast(&A,&Y);
    printf("=====Del V Last=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    DelVAfter(&A,&Y);
    printf("=====Del V After=====\n");
    PrintInfo(A);
    printf("Y=%d\n",Y);
    printf("\n");

    printf("jumlah elemen list = %d\n", NbElmt(A));
    printf("\n");

    InsVLast(&A,2);
    InsVLast(&A,1);
    PrintInfo(A);
    printf("\n");

    printf("=====Invers List=====\n");
    InversList(&A);
    printf("=====List A=====\n");
    PrintInfo(A);
    printf("\n");

    CreateList(&B);
    InsVLast(&B,1);
    InsVLast(&B,2);
    InsVLast(&B,3);

    printf("=====List B=====\n");
    PrintInfo(B);
    printf("\n");

    if(IsSimetriList(A,B)){
        printf("List simetri\n");
    }
    else{
        printf("tidak simetri\n");
    }
    printf("\n");

    CreateList(&Kon);
    Konkat(&A,&B,&Kon);
    printf("=====List Kon=====\n");
    PrintInfo(Kon);

    return 0;
}

