#include "TurkeyAdapter.hpp"

void testDuck(shared_ptr<Duck> duck)
{
	duck->quack();
	duck->fly();
}
int main()
{
	shared_ptr<Duck> duck(new MallardDuck());

	shared_ptr<Turkey> turkey( new WildTurkey());
	shared_ptr<Duck> turkeyAdapter(new TurkeyAdapter(turkey));

	printf("The Turkey says...\n");
	turkey->gobble();
	turkey->fly();

	printf("\nThe Duck says...");
	testDuck(duck);

	printf("\nThe TurkeyAdapter says...");
	testDuck(turkeyAdapter);
}