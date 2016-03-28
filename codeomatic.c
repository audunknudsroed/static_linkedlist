/* declarations for development. */
#include <stdint.h>
struct somestruct {
	uint8_t omg;
};
#define NULL (0)
#define BUFFER_SIZE (8)
#define SLOT_TAKEN (1)
#define SLOT_EMPTY (0)
/* Forward declaration. */
typedef enum status PKT_STATUS;
/* Data needed to track which packets has already been passed. */
enum status {
	NOT_SENT,
	SENT_EARLIER,
	SENT_NOW,
	ACKD,
	OPEN_SLOT,
};
/* Conventional linked list equipment. */
struct packet {
	struct somestruct content;
	uint8_t tx_attempts;
	PKT_STATUS tx_status;
	struct packet *next;
};
static struct packet *head;
static struct packet *tail;


static int n_packets;

/* Equipment needed to fit a linked list into statically allocated memory. */
static struct packet buffer[BUFFER_SIZE];
static int bookkeeper[BUFFER_SIZE];



static void append(struct packet *node);
static void delete(struct packet *node);
static void read_head(struct packet *node);
static struct packet *assign_slot(void);
static void free_slot(struct packet *node);

void main(void) {
	struct packet test;
	int i = 0;
	for ( i = 0; i < 10 ; i++ ) {
		append(&test);
	}
	for ( i = 0; i < 11 ; i++ ) {
		delete(&test);
	}
	
}

void buffer_init(void)
{
	
}

void insert_thing(struct somestruct *content)
{
	struct packet tmp;
	tmp.content = *content;
	tmp.tx_attempts = 0;
	tmp.tx_status = NOT_SENT;
	tmp.next = NULL;
	append(&tmp);
}
void next_new_thing(struct somestruct *content)
{
	struct packet *tmp = head;
	while (tmp != NULL && ( tmp->tx_status != NOT_SENT || tmp->tx_status != SENT_EARLIER ) ) {
		
	}
}

static void append(struct packet *node)
{
	if(node == NULL) {
		return;
	}
	struct packet *tmp = assign_slot();
	if( tmp == NULL) {
		return;
	}
	*tmp = *node;
	if ( head == NULL ) {
		head = tmp;
	} 
	if ( tail == NULL ) {
		tail = tmp;
	} else {
		tail->next = tmp;
		tail = tmp;
	}
	tail->next = NULL;
}
static void read_head(struct packet *node)
{
	*node = *head;
}
	
static void delete(struct packet *node)
{
	struct packet *predecessor = head;
	struct packet *current = head;
	
	while ( current != NULL && current != node ) {
		predecessor = current;
		current = current->next;
	}
	if (current == NULL ) {
		return;
	}
	predecessor->next = current->next;
	
	if ( current == head ) {
		head = current->next;
	}
	if ( current == tail && current != head) {
		tail = predecessor;
	} else if ( current == tail && current == head ) {
		tail = NULL;
	}
	free_slot(current);
}

static struct packet *assign_slot(void)
{
	struct packet *slot = NULL;
	int i = 0;
	
	while ( ( bookkeeper[i] == SLOT_TAKEN ) && ( i < BUFFER_SIZE )) {
		i++;
	}
	if ( i < BUFFER_SIZE ) {
		slot = &buffer[i];
		bookkeeper[i] = SLOT_TAKEN;
	}
	return slot;
}
static void free_slot(struct packet *node)
{
	int i = 0;
	
	while ( &buffer[i] != node && i < BUFFER_SIZE ){
		i++;
	}
	if ( i < BUFFER_SIZE ) {
		bookkeeper[i] = SLOT_EMPTY;
	}
}