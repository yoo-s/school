#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a, b;

	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, a+b);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a, b;

	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, b-a);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a, b;

	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, b/a);
}

void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a, b;

	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, a*b);
}

void power(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a, b;

	a = topDynArr(stack);
	popDynArr(stack);
	b = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(b, a));
}

void squared(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(a, 2));
}

void cubed(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(a, 3));
}

void absolute(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, abs(a));
}

void sqRt(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, sqrt(a));
}

void exponent(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, exp(a));
}

void natLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log(a));
}

void tenLog(struct DynArr *stack)
{
	/* FIXME: You will write this function */
	double a;

	a = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log10(a));
}


double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	double num;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			/* FIXME: replace printf with your own function */
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			/* FIXME: replace printf with your own function */
			power(stack);
		else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
			squared(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
			cubed(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
			absolute(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
			sqRt(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
			exponent(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
			natLog(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
			tenLog(stack);
		else if (isNumber(s, &num))
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			pushDynArr(stack, num);
		else if (strcmp(s, "pi") == 0)
			pushDynArr(stack, 3.14159265);
		else if (strcmp(s, "e") == 0)
			pushDynArr(stack, 2.7182818);
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if (sizeDynArr(stack) == 1) {
		result = topDynArr(stack);
		popDynArr(stack);
		printf("Result: %g\n", result);
		return result;
	} else {
		printf("\nError calculating result.");
		printf("	-- at string '%c'\n", *s);
		return 0;
	}
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
