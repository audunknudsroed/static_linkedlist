typedef enum status PKT_STATUS;

enum status {
	NOT_SENT,
	SENT_EARLIER,
	SENT_NOW,
	ACKD,
} ;

#include <stdio.h>

void catcaharoo(void);

void main(void)
{
	PKT_STATUS lal = ACKD;
	switch(lal){
		case ACKD:
			printf("Hello, World!\n");
			break;
		default:
			break;
	}
	catcaharoo();
}

void catcaharoo(void)
{
	
	int one = 16;
	int two = 3;
	int three = one + two;
}