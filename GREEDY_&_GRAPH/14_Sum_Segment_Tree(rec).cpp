#include <bits/stdc++.h>
using namespace std;

void build(int node,int start,int end,int tree[],int a[]) 
{
   if(start==end)
   {    
    tree[node]=a[start];
   }
   else
   {
    int mid=(start+end)/2;
    build(2*node+1,start,mid,tree,a);
    build(2*node+2,mid+1,end,tree,a);
    tree[node]=tree[2*node+1]+tree[2*node+2];
   }
}

void update(int node,int start,int end,int idx,int val,int tree[],int a[])
{

    if(start==end)
    {
       a[idx]=val;
       tree[node]=val;
    }

    else
    {
        int mid=(start+end)/2;
        if(idx>=start&&idx<=mid)
        {    
           update(2*node+1,start,mid,idx,val,tree,a);
        }
        else
        {    
         update(2*node+2,mid+1,end,idx,val,tree,a);
        }
        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
}

int query(int node,int start,int end,int l,int r,int tree[])
{
    if(l>end||start>r)
    {     
      return 0;
    }
    if(l<=start&&r>=end)
    {    
     return tree[node];
    }
    int q1,q2;
    int mid=(start+end)/2;
    q1=query(2*node+1,start,mid,l,r,tree);
    q2=query(2*node+2,mid+1,end,l,r,tree);

    return q1+q2;
}

int main()
{
  int a[]={4,5,3,2,4,6,6,3};
  int n=sizeof(a)/sizeof(a[0]); 
  int tree[4*n];
  build(0,0,n-1,tree,a);
  cout<<"query(3,6) before update :"<<query(0,0,n-1,3,6,tree)<<"\n";
  update(0,0,n-1,3,0,tree,a);
  cout<<"query(3,6) after update :"<<query(0,0,n-1,3,6,tree)<<"\n";
  return 0;
 }
