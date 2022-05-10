
void selectionsort(int *a, int n){
    int i,j;
    int minInd = 0;
    printf("Runing Selection Sort..... \n");
    for (i = 0; i < n-1; i++)
    {
        minInd = i;
        for (j = i+1;j < n-1; j++){
            if (a[j] < a[minInd]){
                minInd = j;
            }
        }
        //Swapping the elements
        swap(&a[i], &a[minInd]);
    }
    
}