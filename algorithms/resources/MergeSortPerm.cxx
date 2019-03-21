long double mergeSort(int a[], int size)
{
    long double inversions=0;
	if(size<=1) return inversions;

		//dodajemy lewa czesc i prawa czesc      
		inversions+=mergeSort(a,size/2);
		inversions+=mergeSort(a+(size/2),(size+1)/2);

        //indeksy tablic
		int i=0,j=size/2;
        //pomocnicza tablica do ktorej kopiujemy juz posortowane rozwiazanie
		int b[size];

		//merge lewej i prawej polowy
		for(int z=0;z<size;z++){
			if(i<size/2 && j<size){
				if(a[i]<=a[j]){
					b[z]=a[i];
					i++;
				}
				else if(a[j]<a[i]){
					b[z]=a[j];
					j++;
					inversions+=(size/2)-i;
				}
			}
			//gdy zostaly nam elementy tylko w lewej czesci tablicy
			else if(i<size/2){
				b[z]=a[i];
				i++;
			}
			//tylko w prawej
			else{
				b[z]=a[j];
				j++;
			}
		}

		//kopiowanie do poczatkowej tablicy
		for(i=0;i<size;i++)
			a[i]=b[i];
	
    return inversions;
}