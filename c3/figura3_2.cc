/**
classe de lista singurlamente ligada para armazenar inteiros
*/
#include <iostream>

using namespace std;

class IntSSLNode
{
public:
	int info;
	IntSSLNode * proximo;

	IntSSLNode()
	{
		proximo = 0;
	}

	IntSSLNode(int i, IntSSLNode * entrada = 0)
	{
		info = i;
		proximo = entrada;
	}
};

class IntSLList
{
private:
	IntSSLNode * topo, * resto;
public:
	~IntSLList()
	{
		for(IntSSLNode * p; !vazio();)
		{
			p = topo->proximo;
			delete topo;
			topo = p;
		}
	}

	IntSLList()
	{
		topo = resto = 0;
	}

	int vazio()
	{
		return topo == 0;
	}

	void addTopo(int el)
	{
		topo = new IntSSLNode(el, topo);
		if(resto == 0)
		{
			resto = topo;
		}
	}
	void addResto(int el)
	{
		if(resto != 0)
		{
			// se a lista nao esta vazia
			resto->proximo = new IntSSLNode(el);
			resto = resto->proximo;
		}
		else
		{
			topo = resto = new IntSSLNode(el);
		}
	}
	int deletaTopo()
	{
		int el = topo->info;
		IntSSLNode * tmp = topo;
		if(topo == resto)
		{
			// se somente um no na lista
			topo = resto = 0; 
		}
		else
		{
			topo = topo->proximo;
		}
		delete tmp;
		return el;
	}
	int deletaResto()
	{
		int el = resto->info;
		if(topo == resto)
		{
			// se somente um no na lista
			delete topo;
			topo = resto = 0;
		}
		else
		{
			// encontre o prodecessor do resto
			IntSSLNode * tmp;
			for(tmp = topo; tmp->proximo != resto; tmp = tmp->proximo);
			delete resto;
			resto = tmp;		// o prodecessor do resto se torna resto
			resto->proximo = 0;
		}
		return el;
	}
	void deletaNode(int el)
	{
		if(topo != 0)
		{
			// se lista nao esta vazia
			if(topo == resto && el == topo->info)
			{
				// se somente um na lista
				delete topo;
				topo = resto = 0;
			}
			else if(el == topo->info)
			{
				// se mais do que um na lista
				IntSSLNode * tmp = resto;
				topo = topo->proximo;
				delete tmp;					// antigo topo removido
			}
			else
			{
				IntSSLNode * pred, * tmp;

				// e um no topo eh removido
				for(pred = topo, tmp = topo->proximo;
					tmp != 0 && !(tmp->info == el);
				    pred = pred->proximo, tmp = tmp->proximo);
				if(tmp != 0)
				{
					pred->proximo = tmp->proximo;
					if(tmp == resto)
					{
						resto = pred;
					}
					delete tmp;
				}

			}
		}
	}
	bool taNaLista(int el) const
	{
		IntSSLNode * tmp;

		for(tmp = topo; tmp != 0 && !(tmp->info == el); tmp = tmp->proximo);
		return tmp != 0;
	}
};

int main(void)
{
	IntSLList lista;
	lista.addTopo(20);
	lista.deletaTopo();
	return 0;
}