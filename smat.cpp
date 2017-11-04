/*  A command-line application to perform the multiplication
 *  of 2 sparse matrices via console input and print
 *  the result to console.
 */
#include<iostream>
using namespace std;
class sparse
{ 
    int row,col,value,a[50][50];
    public:
    void create(sparse*);
    void display(sparse*);
    void add(sparse*,sparse*);
    void mult(sparse*,sparse*,sparse*);

};
void sparse::display(sparse *a)
{  
    if(a[0].value==0)
     {
        cout<<"Matrix is empty";
        return ;
     }
    for(int i=1;i<=a[0].value;i++)
    { 
        cout<<i<<" "<<a[i].row<<" "<<a[i].col<<" "<<a[i].value<<endl;
    }
}
 void sparse ::mult(sparse *a,sparse *b,sparse *c)
 {  int m,k=1,s;
    if(a[0].col!=b[0].row)
    { 
        cout<<"\nRow Column mismatch,multiplication not possiblen\n"<<endl;
        return ;
    }
    cout<<"\nProduct of the 2 matrices:\n";
    for(int i=1;i<=a[0].value;i++)
    { 
        for(int j=1;j<=b[0].value;j++)
        {
            if(a[i].col==b[j].row)
            {
                c[k].value=a[i].value*b[j].value;
                c[k].row=a[i].row;
                c[k].col=b[j].col;
                s=0;
            }
            if(c[k-1].row==c[k].row && c[k-1].col==c[k].col  && k-1!=0)
            { 
                c[k-1].value=c[k-1].value+c[k].value;
                k=k-1;
                s=1;
                continue;
            } k++;
        } 
    }

    if(s==0)
        c[0].value=k-1;
    else 
        c[0].value=k;
    c[0].row=a[0].row;
    c[0].col=b[0].col;

 }

void sparse ::create(sparse *a)
{  
    cout<<"Enter no of rows and columns of the matrix:"<<endl;
    int m,n,l,k=1,p,q;
    cin>>m>>n;
    cout<<"Enter all elements"<<endl;
    for(int i=0;i<n;i++)
    { 
        for(int j=0;j<m;j++)
        { 
            cin>>l;
            if(l!=0)
            { 
                a[k].row=i;
                a[k].col=j;
                a[k].value=l;
                k++;
            }
        }
    }
   a[0].row=m;
   a[0].col=n;
   a[0].value=k-1;
}


void sparse::add(sparse a[],sparse b[])
{ 
    int m,i,n;
    if(a[0].row>b[0].row)
         m=a[0].row;
    else 
        m=b[0].row;
    for( i=0;i<=n;i++)
    { 
        a[i].value=a[i].value+b[i].value;
    } i++;
    while(i<=b[0].row)
     {
         a[i].value=b[i].value;
        i++;
     }

}
int main()
{ 
    sparse a[10],b[10],c[10],t;
    cout<<"\nInput for first matrix:\n";
    t.create(a);
    cout<<"\nDisplaying first matrix:\n";
    t.display(a);
    cout<<"\nInput for 2nd matrix:\n";
    t.create(b);
    cout<<"\nDisplaying 2nd matrix:\n";
    t.display(b);
    t.mult(a,b,c);
    t.display(c);
    return 0;
}