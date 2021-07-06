#include<bits/stdc++.h>
using namespace std;

long long merges(int ara[],int l,int mid,int r){
  long long inv=0;
  int n1=mid-l+1;
  int n2=r-mid;
  int a[n1];
  int b[n2];
  for(int i=0;i<n1;i++){
    a[i]=ara[l+i];
  }

  for(int i=0;i<n2;i++){
    b[i]=ara[mid+1+i];
  }
  int i=0,j=0,k=l;
  while (i<n1 and j< n2) {
    if(a[i]<=b[j]){
      ara[k]=a[i];
      k++;i++;

    }
    else {
      ara[k]=b[j];
      inv+=n1-i;
      // a[i] > b[j] and i<j
      k++,j++;
    }

  }

  while (i<n1) {
      ara[k]=a[j];
      k++;i++;

  }
  while (j<n2) {
     ara[k]=b[j];
     k++;j++;
  }

  return inv;

}
long long mergesort(int ara[],int l,int r){
  long long inv=0;
  if(l<r){
    int mid=(l+r)/2;
    inv+=mergesort(ara,l,mid);
    inv+=mergesort(ara,mid+1,r);
    inv+=merges(ara,l,mid,r);

  }
  return inv;
}
int main(int argc, char const *argv[]) {
   int n;
   cin>>n;
   int ara[n];
   for(int i=0;i<n;i++)
   {
     cin>>ara[i];
   }
   cout<<mergesort(ara,0,n-1)<<endl;

  return 0;
}
