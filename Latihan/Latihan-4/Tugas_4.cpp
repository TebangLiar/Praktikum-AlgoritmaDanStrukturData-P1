#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node *kiri;
    Node *kanan;
};

int jarak_maksimum = 0;
void tambah(Node **root, int databaru) 
{
    if (*root == NULL) 
    {
        Node *baru;
        baru = new Node;
        
        baru->data = databaru;
        baru->kiri = NULL;
        baru->kanan = NULL;
        
        (*root) = baru;
    }
    else if (databaru < (*root)->data) 
    {
        tambah(&(*root)->kiri, databaru);
    }
    else if (databaru > (*root)->data) 
    {
        tambah(&(*root)->kanan, databaru);
    }
}

int hitungJarak(Node *root) 
{
    if (root == NULL) 
    {
        return 0; 
    }

    int tinggiKiri = hitungJarak(root->kiri);
    int tinggiKanan = hitungJarak(root->kanan);

    if (tinggiKiri + tinggiKanan > jarak_maksimum) 
    {
        jarak_maksimum = tinggiKiri + tinggiKanan;
    }

    if (tinggiKiri > tinggiKanan) 
    {
        return tinggiKiri + 1;
    } 
    else 
    {
        return tinggiKanan + 1;
    }
}

int main() 
{
    int n;
    Node *pohon;
    
    pohon = NULL;
    cout << "Input\n";
    cin >> n; 
    
    for (int i = 0; i < n; i++) 
    {
        int elemen;
        cin >> elemen;
        
        tambah(&pohon, elemen);
    }
    
    hitungJarak(pohon);
    cout << "Output\n";

    cout << jarak_maksimum << "\n";
    return 0;
}