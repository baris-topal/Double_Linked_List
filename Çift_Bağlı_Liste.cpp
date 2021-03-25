#include<iostream>

using namespace std;

class node {
public:
	int data;
	node* root;
	node* next;
	node* prev;
	node* ekle(node* r, int x);
	node* basaekle(node* r, int x);
	void arayaekle(node* r, int x, int ara);
	void sil(node* r, int ara);
	void yazdir(node* r);
};

node* node::ekle(node* r, int x) {
	if (r == NULL)
	{
		r = new node;
		r->data = x;
		r->next = r;
		r->prev = NULL;
	}
	else
	{
		node* yrd;
		yrd = r;
		while (yrd->next != r)
			yrd = yrd->next;
		yrd->next = new node;
		yrd->next->data = x;
		yrd->next->next = r;
		yrd->next->prev = yrd;
		yrd = NULL;
		delete yrd;
	}
	return r;
}

node* node::basaekle(node* r, int x) {
	if (r == NULL)
	{
		r = new node;
		r->data = x;
		r->next = r;
		r->prev = NULL;
	}
	else
	{
		node* yrd;
		yrd = new node;
		yrd->next = r;
		yrd->prev = NULL;
		yrd->data = x;
		r->prev = yrd;
		yrd = yrd->next;
		while (yrd->next != r)
			yrd = yrd->next;
		// r=r->prev;
		// yrd->next=r;
		yrd->next = r->prev;
		r = r->prev;
		yrd = NULL;
		delete yrd;
	}
	return r;
}

void node::arayaekle(node* r, int x, int ara) {
	// CİFT BAGLİ LİSTE UYGULAMASI
	if (r == NULL)
	{
		r = new node;
		r->data = x;
		r->next = r;
		r->prev = NULL;
	}
	else
	{
		if (r->next == r)
		{
			r = ekle(r, x);
		}
		else
		{
			node* yrd;
			yrd = r;
			while (yrd->data != ara)
				yrd = yrd->next;
			node* tmp;
			tmp = new node;
			tmp->data = x;
			tmp->next = yrd->next;
			yrd->next = tmp;
			tmp->next->prev = tmp;
			tmp->prev = yrd;
			tmp = yrd = NULL;
			delete tmp, yrd;
		}
	}
}

void node::sil(node* r, int ara) {

	node* yrd;
	yrd = r;
	while (yrd->data != ara)
		yrd = yrd->next;
	yrd->prev->next = yrd->next;
	yrd->next->prev = yrd->prev;
	yrd->next = NULL;
	yrd->prev = NULL;
	//data kullanilacaksa islem görsün hesapla(yrd->data);
	delete yrd;

}

void node::yazdir(node* r) {


	node* yrd;
	yrd = r;
	while (yrd->next != r) {
		cout << yrd->data << " ";
		yrd = yrd->next;
	}
	cout << yrd->data << endl;

}

void main() {
	node node;

	node.root = NULL;
	node.root = node.ekle(node.root, 10);
	node.ekle(node.root, 20);
	node.ekle(node.root, 30);
	node.ekle(node.root, 40);
	node.ekle(node.root, 50);
	cout << "Ilk Hal..............";
	node.yazdir(node.root);
	node.root = node.basaekle(node.root, 5);
	cout << "1.Adim (5 Eklendi)...";
	node.yazdir(node.root);
	node.arayaekle(node.root, 35, 30);
	cout << "2.Adim (35 Eklendi)..";
	node.yazdir(node.root);
	node.sil(node.root, 35);
	cout << "3.Adim (35 Silindi)..";
	node.yazdir(node.root);
	node.ekle(node.root, 60);
	cout << "4.Adim (60 Eklendi)..";
	node.yazdir(node.root);

	system("pause");
}

