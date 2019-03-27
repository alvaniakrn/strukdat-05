/*
 alvina vania kirana
 140810180010
 program dapat
 2019
 */

#include <iostream>
using namespace std;

struct pembalap{
    int nomor;
    char nama;
    int waktu;
    pembalap* next;
    pembalap* prev;
};

void createNode(pembalap* &p, int nomor,char nama){
    p= new pembalap;
    p->nama=nama;
    p->nomor=nomor;
    cout<< "Waktu   :";cin>>p->waktu;
    p->next=NULL;
    p->prev=NULL;
}

void insertFirst (pembalap* &head, pembalap* node){
    if (head==NULL){
        head=node;
    }
    else {
        node->next=head;
        node->prev=node;
        head=node;
    }
}

void insertBefore (pembalap &head, int nomorKey, pembalap* node){
    pembalap* pCari;
    if(pCari->next==NULL){
        pCari->next=node;
    }
    else{
        node->next=pCari;
        node->prev=pCari->prev;
        pCari->prev->next=node;
        pCari->prev=node;
    }
}

void deleteByKey(pembalap* &head, int nomorKey, pembalap* &deleteNode){
    pembalap* pCari;
    pembalap* pHapus;
    pCari=head;
    while(pCari!=NULL){
        if(pCari->nomor==nomorKey){
            pHapus=pCari;
            pCari->prev->next=pCari->next;
            pCari->next->prev=pCari->prev;
            pCari->next=NULL;
            pCari->prev=NULL;
        }
        else {
            pCari=pCari->next;
            pCari=pCari->prev;
        }
    }
}

void search (pembalap* &firstNode, int nomorKey, pembalap* &pToUpdate){
    pToUpdate=firstNode;
    while(pToUpdate->nomor!=nomorKey){
        pToUpdate=pToUpdate->next;
    }
}

void traversal (pembalap* head){
    pembalap* help;
    if (head==NULL){
        cout << "Tidak ada list"<<endl;
    }
    else {
        help=head;
        while(help!=NULL){
            cout << "Nomor  :"<<help->nomor<<endl;
            cout << "Nama   :"<<help->nama<<endl;
            cout << "Waktu  :"<<help->waktu<<endl;
        }
    }
}

void sortingByNomor (pembalap* &head){
    
}

void update(pembalap* firstNode, int nomorKey){
    
}



int main() {
    pembalap* head=NULL;
    pembalap* pBaru=NULL;
    pembalap* pToUpdate=NULL;
    char nama='a';
    
    for (int i=0; i<4; i++){
        createNode(pBaru,i+1,nama++);
        insertFirst(head,pBaru);
    }
    
    cout<< "\n>>>List"<<endl;
    traversal(head);
    
    int keyNomor=2;
    
    cout<< "\n>>>Insert Before Nomor"<<endl;
    createNode(pBaru,99,'z');
    insertBefore(*head,keyNomor,pBaru);
    traversal(head);
    
    cout<< "\n>>>SortingBynomor"<<endl;
    sortingByNomor(head);
    traversal(head);
    
    keyNomor=3;
    cout << "\n>>>Delete Nomor"<<keyNomor<<endl;
    pembalap* pHapus=NULL;
    deleteByKey(head,keyNomor,pHapus);
    traversal(head);
    
    keyNomor=4;
    cout << "\n>>>Update Nomor"<<keyNomor<<endl;
    update(head,keyNomor);
    
    cout << "\n>>>Update List\n";
    traversal(head);
    
    
    
    return 0;
}
