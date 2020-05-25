#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

struct derevo
{
    char id;
    derevo *left, *right;
};
typedef derevo *Dr;

void probel(int n)
{
    while (n>0)
    {
        cout<<"  ";
        n--;
    }
}


void show_tree(derevo*Tr, int n)
{
    if(Tr!=NULL)
    {
        n++;
        if (Tr->right) show_tree(Tr->right, n);
        probel(n);
        if (Tr->id!='0') cout<<Tr->id<<endl;
        n-2;
        if (Tr->left) show_tree(Tr->left, n);
    }
}

int rodion(char c)
{
    switch (c){
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return 100;
}

Dr matmeh(char vvod[], int first, int last)
{
    Dr Tree = new derevo;
    int MinRodion, i, k, rodya;
    int skoba = 0;
    if(first==last)
    {
        Tree->id=vvod[first];
        Tree->right=NULL;
        Tree->left=NULL;
        return Tree;
    }
    MinRodion=100;
    for ( i = first; i <= last; i ++ )
    {
        if (vvod[i]=='(')
        {
            skoba++;
            continue;
        }
        if (vvod[i]==')')
        {
            skoba--;
            continue;
        }
        if (skoba > 0) continue;
        rodya=rodion(vvod[i]);
        if (rodya<=MinRodion )
        {
            MinRodion = rodya;
            k = i;
        }
    }
    if ((MinRodion==100)&&(vvod[first]=='(')&&(vvod[last]==')'))
    {
        delete Tree;
        return matmeh(vvod, first+1, last-1);
    }
    Tree->id=vvod[k];
    Tree->left=matmeh(vvod,first,k-1);
    Tree->right=matmeh(vvod,k+1,last);
    return Tree;
}

int chislovoe(Dr Tree) {
        int listR, listL;
            if (Tree->left==NULL)
            return Tree->id-'0';
            listL=chislovoe(Tree->left);
            listR=chislovoe(Tree->right);
            switch (Tree->id) {
            case '+': return listL+listR;
            case '-': return listL-listR;
            case '*': return listL*listR;
            case '/': return listL/listR;
            }
            return 666666;
}

void job(char *hitr){
    int i=0;
    int k=strlen(hitr);
while(i<k){
    if (hitr[i]=='(' && hitr[i+1]=='-')
            {
                k++;
                for(k; k>i+1; k--){
                hitr[k]=hitr[k-1];
                }
                hitr[i+1]='0';

}
i++;
}
}

int main( )
{
    setlocale(LC_ALL, "Russian");
    char vvod[100];

ifstream fin("input.txt");
fin.getline(vvod,100);
fin.close();
cout <<"primer:"<<vvod<<endl;

    Dr Tree;
    while (2>1){

    job(vvod);
    Tree = matmeh(vvod, 0, strlen(vvod)-1);
    show_tree(Tree, -1);
    cout<<endl;
    cout<<chislovoe(Tree)<<endl;
    cout<<endl;
    return 0;
    getch();

}
}
