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

int main(void)
{
	IntSSLNode * p = new IntSSLNode(10);
	p->proximo = new IntSSLNode(8);
	p->proximo->proximo = new IntSSLNode(50); 
	return 0;
}