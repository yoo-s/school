#include <stdio.h>
#include "cart.h"

int main()
{
	/* This is where we'll write our test harness. A test harness is something
	 * that a user would never see; it's just for verifying that your code
	 * is behaving correctly. In this case, we're testing whether our
	 * ShoppingCart data structure is working properly. */

	/* NOTE: there *are* bugs in cart.c; this test harness will help you find
	 * and fix them! */

	/* Let's start by creating a shopping cart with space for 2 items */
	printf("Creating a shopping cart...\n");
	struct ShoppingCart *cart = createCart(2);

	/* The cart is empty, so it's numItems and  totalPrice should be 0 */
	/* This tests whether getNumItems() returns 0 (i.e., is the cart empty?) */
	printf ("Shopping cart should be empty: ");
	if (getNumItems(cart) == 0)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Write a test to verify that getTotalPrice() returns 0 */
	printf ("Shopping cart should have no charge: ");
	if (getTotalPrice(cart) == 0)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Now we'll add some items to the cart */
	struct CartItem *milk = createItem("milk", 3.00);
	struct CartItem *coffee = createItem("coffee", 10.00);
	addItemToCart(cart, milk);
	addItemToCart(cart, coffee);

	/* This tests whether 'milk' was successfully added */
	printf ("Shopping cart should contain 'milk': ");
	if (containsItem(cart, milk) > -1)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Write a test to verify that 'coffee' was also sucessfully added */
	printf ("Shopping cart should contain 'coffee': ");
	if (containsItem(cart, coffee) > -1)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Write tests to verify that the cart contains 2 items (use the
	 * getNumItems() function) and the total price of the cart is $13.00. */
	printf ("Shopping cart should contain 2 items and total price is $13.00: ");
	if (getNumItems(cart) == 2 && getTotalPrice(cart) == 13)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Now we'll remove an item from the cart */
	removeItemFromCart(cart, milk);

	/* Write tests to verify that the cart no longer contains 'milk', but
	 * still contains 'coffee'. */
	printf("Shopping cart no longer contains 'milk', but still has 'coffee': ");
	if (containsItem(cart, milk) <= -1 && containsItem(cart, coffee) > -1)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Write tests to verify that the cart contains 1 item (use the
	 * getNumItems() function) and the total price of the cart is $10.00. */
	printf ("Shopping cart should contain 1 item and total price is $10.00: ");
	if (getNumItems(cart) == 1 && getTotalPrice(cart) == 10)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Now let's add 'milk' back to the cart... (uncomment the follow line)*/
	addItemToCart(cart, milk);
	//printf("\nNumItems in cart: %d\n", getNumItems(cart));
	//printf("TotalPrice of cart: %g\n", getTotalPrice(cart));

	/* ...and an avocado (uncomment the next two lines) */
	struct CartItem *avocado = createItem("avocado", 2.00);
	addItemToCart(cart, avocado);
	//printf("\nNumItems when avocado is added: %d\n", getNumItems(cart));
	//printf("TotalPrice when avocado is added: %g\n", getTotalPrice(cart));

/* But, adding the avocado should fail because we only created a cart with
 * enough space for 2 items. So test that the cart does *not* contain
 * 'avocado', that it has 2 items, and the total price is $13.00. */
	printf ("Shopping cart should contain 2 items and total price is $13.00: ");
	if (containsItem(cart, avocado) <= -1 && getNumItems(cart) == 2 && getTotalPrice(cart) == 13)
		printf("success.\n");
	else
		printf("FAIL.\n");

	/* Clean up after ourselves */
	freeCart(cart);
	
	return 0;
}
