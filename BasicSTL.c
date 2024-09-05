#include<stdio.h>
#include "BasicSTL.h"
#include <time.h>
#include <stdlib.h>
void swap(int *val1,int *val2){
	int temp=*val1;
	*val1=*val2;
	*val2=temp;
}
void BubbleSort(int* arr,int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
               swap(&arr[j+1],&arr[j]); 
            }
        }
    }
    
}
void merge(int* arr,int s,int e){
	int m=s+(e-s)/2;
	int l1=m-s+1;
	int l2=e-m;
	int* arr1=(int*)malloc(l1*sizeof(int));
	int* arr2=(int*)malloc(l2*sizeof(int));
	int k=s;
	for(int i=0;i<l1;i++){
		arr1[i]=arr[k++];
	}
	for(int i=0;i<l2;i++){
		arr2[i]=arr[k++];
	}
	k=s;
	int i=0;
	int j=0;
	while(i<l1 && j<l2){
		if(arr1[i]<arr2[j]){
			arr[k++]=arr1[i];
			i++;
		}
		else{
			arr[k++]=arr2[j];
			j++;
		}
	}
	while(i<l1){
            arr[k++]=arr1[i];
            i++;

	}
	while(j<l2){
		 arr[k++]=arr2[j];
                 j++;

	}
	free(arr1);
	free(arr2);

}
void MergeSort(int* arr,int s,int e){
   
	if(s>=e){
		return ;
	}
	int m=s+(e-s)/2;
	MergeSort(arr,s,m);
	MergeSort(arr,m+1,e);
	merge(arr,s,e);
}

	

int pivot(int* arr ,int s,int e){
    int p=arr[s];
    int c=0;
    for (int i=s+1;i<=e;i++){
        if (arr[i]<=p){
            c++;
        }
    }
    int k=s+c;
    int n=arr[k];
    arr[k]=arr[s];
    arr[s]=n;
    int i=s;
    int j=e;
    while (i<k && j>k){
        while (arr[i]<=p){
            i++;
        }
        while (arr[j]>p){
            j--;
        }
        if (i<k && j>k){
            int m=arr[j];
            arr[j]=arr[i];
            arr[i]=m;
            i++;
            j--;
        } 
    }
    return k;
}
void QuickSort(int* arr,int s,int e){

    if(s>=e){
        return ;
    }
    int p=pivot(arr,s,e);
    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
    
}

void SelectionSort(int* arr,int n){

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
            swap(&arr[i],&arr[j]);    
            }
        }	
    }
}
int BinarySearch(int* arr,int size,int target){
    int start=0;
    int end=size-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if( target<arr[mid]){
            end=mid-1;
        }
        else {
            start=mid+1;
        }
    }
    return -1;
}
int LinearSearch(int* arr, int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
        return -1;
}
int abs(int num){
    if(num<0){
        return 0-num;
    }
    return num;
}
int min(int a,int b){
    if( a<=b){
        return a;
    }
    return b;
}
int max(int a,int b){
    if( a>=b){
        return a;
    }
    return b;
}
int power(int x,int n){
    if(x==0) return 0;
    if( n==0) return 1;
    if( n==1) return x;
    if(n<0){
        return 0;
    }
    int ans=power(x,n/2);
    if(n%2==0){
        return ans*ans;
    }
    return ans*ans*x;

}
int sqroot(int num){
    if(num<0){
        return -1;
    }
     if(num == 0 || num == 1){
        return num;
    }
    int start=0;
    int end=num;
    int ans=-1;
    while(start<=end){
        int m=start+(end-start)/2;
        int sq=m*m;
        if(sq==num){
            return m;
        }
        else if(sq<num){
            ans=m;
            start=m+1;
        }
        else{
            end=m-1;
        }
    }
    return ans;
}
