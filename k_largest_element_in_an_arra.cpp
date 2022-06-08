#include<bits/stdc++.h>
using namespace std;

int swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}


class Min_heap
{
private:
  int size;
  int* arr;
public:
  Min_heap(int size,int input[]);
  void heapify(int i);
  void buildheap();
};


Min_heap::Min_heap(int size,int input[])
{
  this->size=size;
  this->arr=input;
  buildheap();
}

void Min_heap::heapify(int i)
{
  int left=2*i+1;
  int right=2*i+2;

  if(left>=size)
    return;

  int smallest;
  smallest=(arr[left]<arr[i])?left:i;

  if(right<size)
  {
  smallest=(arr[smallest]<arr[right])?smallest:right;
  }
  

  if(smallest!=i)
  {
    swap(arr[i],arr[smallest]);
    heapify(smallest);
  }

}

void Min_heap::buildheap()
{
  for(int i=size/2-1;i>=0;i--)
    heapify(i);
}


int main()
{

  #ifndef ONLINE_JUDGE
  freopen("INPUT.txt","r",stdin);
  freopen("OUTPUT.txt","w",stdout);
  #endif

  int n,k;
  cin>>n>>k;

  int ar[n];

  for(int i=0;i<n;i++)
  {
    cin>>ar[i];
  }
  //return 0;

  Min_heap* a=new Min_heap(k,ar);


  for(int i=k;i<n;i++)
  {
    if(ar[0]>ar[i])
      continue;
    else
    {
      ar[0]=ar[i];
      a->heapify(0);
    }
  }

  for(int i=0;i<k;i++)
    cout<<ar[i]<<" ";
}
