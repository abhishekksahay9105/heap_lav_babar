#include<bits/stdc++.h>
using namespace std;

void swap(int* x,int* y)
{
  int temp=*x;
  *x=*y;
  *y=temp;
}

class Min_heap
{
private:
  int size;
  int* arr;
public:
  Min_heap(int size,int input[]);
  void heapify(int i);
  void buildhead();
};

Min_heap::Min_heap(int size,int input[])
{
    this->size=size;
    this->arr=input;
    buildhead();
}

void Min_heap::heapify(int i)
{
  int left=2*i+1;
  int right=2*i+2;

  if(left>=size)
    return;

  int smallest;
  smallest=(arr[left]>arr[i])?left:i;

  if(right<size)
  {
    smallest=(arr[right]>arr[smallest])?right:smallest;
  }

  if(smallest!=i)
  {
    swap(arr[i],arr[smallest]);
    heapify(smallest);
  }
}

void Min_heap:: buildhead()
{
  for(int i=size/2-1;i>=0;i--)
  {
    heapify(i);
  }
}

int main()
{
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0;i<n;i++)
      cin>>arr[i];

    Min_heap* a=new Min_heap(n,arr);

    for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<" ";
    }
    
    cout<<endl;

   for(int i=k;i<n;i++)
    {
      if(arr[0]>arr[i])
        continue;
      else
      {
        arr[0]=arr[i];
        a->heapify(0);
      }
    }

    cout<<arr[0]<<" ";

    return 0;
}
