/*  A command-line application to perform the multiplication
 *  of 2 sparse matrices via console input and print
 *  the result to console.
 */
#include<iostream>
using namespace std;

class sparse
{ 
    int row,col,value;
    public:
        void create(sparse*);
        void display(sparse*);
        void add(sparse*,sparse*);
        void spmult(sparse*,sparse*,sparse*);
        bool isSparse(sparse*);
};

//  Function to display a sparse matrix in triplet form(Row,column,value)
void sparse::display(sparse *a)
{  

    // Checks if the matrix is empty
    if(a[0].value == 0)
    {
        cout<<"Matrix is empty\n";
        return ;
    }

    // Prints the matrix in row, column, value format
    cout<<"\nR C V"<<endl;
    for(int i = 1;i <= a[0].value;i++)
    { 
        cout<<a[i].row<<" "<<a[i].col<<" "<<a[i].value<<endl;
    }
}

//  Function to multiply 2 sparse matrices.
void sparse ::spmult(sparse *a,sparse *b,sparse *c)
{  
    int m,k = 1,s;

    // Checks if the matrices can be multiplied
    if(a[0].col != b[0].row)
    { 
        cout<<"Row,Column mismatch!Unable to multiply\n"<<endl;
        return ;
    }

    // Iterates through matrices and performs multiplication
    for(int i = 1;i <= a[0].value;i++)
    { 
        for(int j = 1;j <= b[0].value;j++)
        {
            if(a[i].col == b[j].row)
            {

                // Multiplies corresponding column and row elements and stores the result and index in a third sparse matrix 
                c[k].value = a[i].value * b[j].value;
                c[k].row = a[i].row;
                c[k].col = b[j].col;
                s = 0;

                // Checks if product of elements in the same row of one matrix and column of the other already exists
                if(c[k-1].row == c[k].row && c[k-1].col == c[k].col  && k-1 != 0)
                {       

                    // Adds the new product to the existing one and stores the sum
                    c[k-1].value = c[k-1].value+c[k].value;
                    k=k-1;
                    s=1;
                    continue;
                } 
                k++; 
            }
        } 
    }

    // Sets the number of rows, columns and elements in product matrix
    if(s == 0)
        c[0].value = k-1;
    else 
        c[0].value = k;
    c[0].row = a[0].row;
    c[0].col = b[0].col;

}

//  Function to read input for a matrix.
void sparse ::create(sparse *a)
{  
    cout<<"Number of rows and columns in matrix:\n";
    int m,n,l,k = 1;
    cin>>m>>n;
    cout<<"Enter all elements in the appropriate order:\n";

    // Accepts the matrix in regular format and stores it as a sparse matrix
    for(int i = 0;i < m;i++)
    { 
        for(int j = 0;j < n;j++)
        { 
            cin>>l;
            if(l!=0)
            {    
                a[k].row = i;
                a[k].col = j;
                a[k].value = l;
                k++;
            }

        }    
   }

   // Sets the number of rows, columns and elements in the matrix
   a[0].row = m;
   a[0].col = n;
   a[0].value = k-1;
}

// Function to check if a matrix is sparse or not
bool sparse::isSparse(sparse a[]) {
    return (a[0].row * a[0].col + 1) / 2 > a[0].value;
}

//  Main function
int main()
{ 
    sparse a[10],b[10],c[10],t;
    cout<<"Input for first matrix:\n";
    t.create(a);
    cout<<"Entered matrix in Row,Col,value triplet form:\n";
    t.display(a);
    cout<<"Input for second matrix:\n";
    t.create(b);
    cout<<"Entered matrix in Row,Col,value triplet form:\n";
    t.display(b);

    // Multiplies the matrices if they are sparse
    if(t.isSparse(a) && t.isSparse(b)) {
        t.spmult(a,b,c);
        cout<<"The product of the two matrices:\n ";
        t.display(c);
    } else cout << "Both matrices are not sparse";
    return 0;
}

