#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

void triangule(float **a, float *b, int taille){
  int i, j, k;
  float x;

  for (k = 0; k < taille-1; k++)
  {
    for (i = k+1; i < taille; i++)
    {
      x = a[i][k];

      for ( j = k; j < taille; j++)
      {
        a[i][j] = a[i][j]*a[k][k] - a[k][j]*x;
      }

      b[i] = b[i]*a[k][k] - b[k]*x;
      
    }
    
  }

  for(k = taille-1; k > 0; k--){
    for(i = k-1; i >= 0; i--){
      x = a[i][k];

      for(j = k; j>=0; j-- ){
        a[i][j] = a[i][j]*a[k][k] - a[k][j]*x;
      }

      b[i] = b[i]*a[k][k] - b[k]*x;
    }
  }
  
}

/*float *resolution(float **a, float *b, int taille){
  int i, j;
  float *x = (float*)malloc(taille * sizeof(float)), temp;

  x[taille-1] = b[taille-1]/a[taille-1][taille-1];

  for(i = taille-2; i>=0; i--){
    temp = 0;
    for (j = i+1; j < taille; j++)
    {
      temp += a[i][j]*x[j]; 
    }

    x[i]= (b[i]-temp)/a[i][i];
    
  }

  return x;
}*/

int main(){
  float **matrice, *b, *result;
  int taille, i, j;

  printf("Entrer la taille de la matrice: ");
  scanf("%d", &taille);

  matrice = (float**)malloc(sizeof(float*) * taille);
  for ( i = 0; i < taille; i++)
  {
    matrice[i] = (float*)malloc(sizeof(float) * taille);
  }

  b = (float*)malloc(sizeof(float) * taille);

  for(i = 0; i<taille; i++){
    for(j=0; j<taille; j++){
      printf("Entrer l'element de l'equation d'indice i:%d j:%d ", i, j);
      scanf("%f", &matrice[i][j]);
    }
  }

  printf("\n");

  for(i=0; i<taille; i++){
    printf("Entrer l'element de B d'indice i: %d ", i);
    scanf("%f", &b[i]);   
  }

  triangule(matrice, b, taille);
  printf("\n  Matrice triangulee :\n\n");
  for(i = 0; i<taille; i++){
    for(j=0; j<taille; j++){
      printf("%2f\t", matrice[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  //result = resolution(matrice, b, taille);

  for(i=0; i<taille; i++){
    printf("La solution x%d est: %2f \n", i, result[i]);
  }
  
  return 0;
}