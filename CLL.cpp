#include <iostream>
using namespace std;

struct node{
    int info;
    node* next;

    node(int value, node* c = 0)
    : info(value), next(c){};
};

node* first = NULL;

void Empty(node* n){
    first = n;
    n->next = first;
}

void deleteLastElement(){
    node* n = first;
    n->next = NULL;
    first = NULL;
    delete n;
}

void insertfirst(int value){
    node* q = first;
    node* n = new node(value);
    if (first != NULL){
        while(q->next != first){
            q = q->next;
        }
        n->next = first;
        q->next = n;
        first = n;
    } else {Empty(n);}
    
    
}

void insertlast(int value){
    node* q = first;
    node* n = new node(value);
    if (first != NULL){
        while(q->next != first){
            q = q->next;
        }
        n->next = first;
        q->next = n;
    } else {Empty(n);}
}

void insertbefore(int value , node* c){
    if (first != c){
        node* temp;
        node* p = first;
        
        while(p != c){
            temp = p;
            p = p->next;
        }
        
        node* n = new node(value);
        n->next = temp->next;
        temp->next = n;

    } else {
        node* n = new node(value);
        n->next = first;
        first = n;
    }
}

void insertafter(int value, node* c){
    node* temp;
    node* p = first;
    
    while(p != c){
        p = p->next;
    }
    
    node* k = new node(value);
    k->next = p->next;
    p->next = k;
}


void deletefirst(){
    node* q = first;
    if (first != NULL){
        while(q->next != first){
            q = q->next;
        }
        node* n = first;
        first = n->next;
        n->next = NULL;
        q->next = first;
        delete n;
    } 
	else {deleteLastElement();}
}

void deletelast(){
    node* q = first;
    while(q->next->next != first){
        q = q->next;
    }
    node* n = q->next;
    q->next = first;
    n->next = NULL;
    delete n;
}

void deleteafter(node* c){
    node* p = first;
    
    while(p != c){
        p = p->next;
    }
    node* del = p->next;
    c->next = p->next->next;
    delete del;

}

int search(int key){
    node* p = first;
    int i = 1;
    while (p->info != key){
        p = p->next;
        i++;
    }
    return i;
}

void print(node* c){
    while(c->next != first){
        cout << c->info << " ";
        c = c->next;
    } 
    cout << c->info << " ";
    cout << endl;
}

int main(){
	
	cout<<"Data Awal\n";
    insertfirst(18);
    insertfirst(15);
    insertfirst(10);
    print(first);
    
    cout<<"Insert Last\n";
    insertlast(20);
    print(first);
    
    cout<<"Insert Before\n";
    insertbefore(23 , first->next->next);
    print(first);
    
    cout<<"Insert After\n";
    insertafter(43 , first->next);
    print(first);
    
    cout<<"Delete Fisrt\n";
    deletefirst();
    print(first);
    
    cout<<"Delete Last\n";
    deletelast();
    print(first);
    
    cout<<"Delete After\n";
    deleteafter(first);
    print(first);
    
    int key;
    cout << "Data yang ingin di cari: ";
    cin >> key;
    cout << "key "<< key <<" ditemukan di urutan ke-" << search(key);
    
    return 0;
}
