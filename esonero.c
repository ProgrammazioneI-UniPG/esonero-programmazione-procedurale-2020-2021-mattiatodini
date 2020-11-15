#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(){
	char M[130],K[130],C[130],c;
	int lunghezzaM,lunghezzaK,operazione,scelta,i;
	time_t t;
    printf("Inserire la stringa di testo da cifrare (massimo 128 caratteri, i valori dopo 128 non vengono presi in cosiderazione)\nStringa:");
    fgets(M,130,stdin);
    lunghezzaM=strlen(M);//Calcola la lunghezza della stringa inserita dall'utente
      if(lunghezzaM>=129){//se l'utente supera i 129 caratteri inseriti svuota il buffer
        while((c=getchar()) != '\n' && c!=EOF){};//Svuota il buffer
    }
	M[lunghezzaM - 1] = '\0'; //toglie dalla lunghezza della stringa lo "\n", sennò calcola una valore in più
	lunghezzaM=strlen(M); //Calcola la lunghezza della stringa finale inserita dall'utente (senza "\n")
	printf("Lunghezza del testo inserito: %d\n",lunghezzaM);
  
    printf("\nScegliere che operazione fare: \n\n\t 1-Inserire chiave di cifratura \n\t 2-Chiave di cifratura casuale \n\nOperazione:");
    scanf("%d",&operazione);
    if(operazione==1){
        while(i!=1){
            while((c=getchar()) != '\n' && c!=EOF){};//Svuota il buffer
            printf("\nInserire una chiave maggiore o uguale al testo per cifrarlo\nChiave:");
            fgets(K,130,stdin);
            lunghezzaK=strlen(K);//Calcola la lunghezza della chiave inserita dall'utente
            K[lunghezzaK-1]='\0';//toglie dalla lunghezza della chiave lo "\n", sennò calcola una valore in più
            lunghezzaK=strlen(K);//Calcola la lunghezza della chiave finale inserita dall'utente (senza "\n")
            if(strlen(K)>=strlen(M)){ // verifica che la chiavse inserità sia uguale o più grande della stringa inizialmente dall'utente
                i=1;
                printf("Lunghezza della chiave inserita: %d\n",lunghezzaK);}
            else{
                printf("\n\nERRORE! DEVI INSERIRE UNA CHIAVE MAGGIORE O UGUALE AL TESTO DA CIFRARE.\n\n");}
                }
    }
    if(operazione==2){
        srand((unsigned)time(&t));
        printf("\n\n\tChiave casuale K: ");
        for(i=0;i!=lunghezzaM; i++){
            K[i]=rand() % (128)+32;; //genera la chiave in maniera casuale
            printf("%c",K[i]);
			}
        lunghezzaK=strlen(K); //Calcola la lunghezza della chiave
        printf("\n Lunghezza della chiave generata: %d",lunghezzaK);
    }
    printf("\n\n\tChiave cifrata: ");
    for(i=0; i!=lunghezzaK;i++){
        C[i]=M[i]^K[i];//Effettua la propietà dell'XOR per cifrare la stringa originale	
        printf("%c",C[i]);
    }
    if(lunghezzaK>=129){//se la chiave supera i 129 caratteri inseriti svuota il buffer
        while((c=getchar()) != '\n' && c!=EOF){};//Svuota il buffer
    }
    printf("\n\nVuoi tornare alla stringa iniziale? 1[si] 2[no]\noperazione:");
    scanf("%d",&scelta);
    if(scelta==1){
        printf("\n\tStringa originale: ");
        for(i=0; i!=lunghezzaK;i++){
            M[i]=C[i]^K[i];
            printf("%c",M[i]);//Effettua la proprietà dell'XOR per tornare alla stringa originale
        }
        printf("\n\nOperazioni terminate\n");
    }
    else{
        printf("\n\nOperazioni terminate\n");
    }
    return 0;
}
