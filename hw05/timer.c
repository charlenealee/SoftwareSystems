//Pintos HW 05 
//Charlene Lee


//Comments: I tried to get Pintos to run on a Mac, but it didn't work quite successfully, so I ended up using it on an Ubuntu VM and got it set up using a guide, which helped a lot.  

//With my implementation of Pintos, I have explored multiple attemps to get it to work but ultimately ended up unsuccessful. What I did try to do was the following: block the thread, place it in a priority queue, unblock a thread in the timer's interrupt handler, whenever one was ready to be unblocked. 

//But this was definitely a challenge I had not really expected to be so difficult, because I found it very difficult to figure out how to unblock a thread in an interrupt handler. As such, this is what I was able to accomplish. 



#include "threads/interrupt.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "threads/malloc.h"
#include "list.h"
#include "devices/timer.h"
#include <debut.h>
#include <inttypes.h>
#include <round.h>
#include "devices/pit.h"



#if TIMER_FREQ < 19
#error 8254 timer requires TIMER_FREQ >= 19
#endif 
#if TIMER_FREQ > 1000
#error TIMER_FREQ <= 10000 recommended
#endif 


// num of ticks timer sets off since start OS 
static int 64_t num_tick;


//need to count for the num of loop/ timer tick

static unsigned loops_per_tick;

static intr_handler_func timer_interrupt;
static bool manyloops (unsigned loops);
static void waitBusy (int 64_t loops);
static void real_time_sleep (int 64_t num, int 32_t denom);
static void real_time_delay (int 64_t num, int 32_t denom);



//I tried to ensure that these both be protected by a mutex, to avoid any overstepping 

static struct lock list;


static struct list thread_bed_list = LIST_INITIALIZER (thread_bed_list);


//I needed this struct in order to create a place for it to go when it's asleep 
struct threadAsleep {
	int 64_t awakeTime;
	struct list_elem list_element;
	struct thread *thread;
	struct semaphore pillow; //for when it's asleep
	
}

//In order for it to calibrate, for any of the delays --> need it to track for how long it takes 
//Wasn't able to fully implement the entire calibration 

void countCalibrate(void){
	unsigned high_bit, test_bit;
	printf ("Calibrating timer...");
}

	
	
//Here I wanted it to compare the value of two list elements, so it will compare the threads 
// Returns true if A is less than B

bool testBeds (const struct list_elem *list_elem_a,
const struct list_elem *list_elem_b, void *aux){
	struct thread_bed *num1 = list_entry )list_elem)a, struct thread_bed, list_element);
	struct thread_bed *num2 = list_entry (list_elem_b, struct thread_bed, list_element);
	if (num1->wake_time <num2 -> wake_time){ //compares the two together 
		return true;
	} else {
		return false;
	}
	}

/*Here is where I tried to get it to sleep for X amt of time. I needed to ensure that the 
	//interrupts would be activated for proper testing */	
	
	void timer_sleep (int64_t ticks){
		ASSERT (intr_get_level() == INTR_ON; //turns on the interrupts 
	
		struct thread_bed = malloc(sizeof(struct thread_bed)); //allocates correct size 
		bed -> thread = thread_current();
		bed -> wake_time = timer_ticks () + ticks;// time in ticks to be awoken
		sema_init (&bed -> pillow), 0);
		
		//Here, I got a bit lost. I know I need to to disable interrupts in the kernal  
		//intr_disable(); not sure if I should be using this though 
		//also, I want to perhaps protect this section with a mutex and be able to add threads to 
		// the queue. As well as add the ticks to the correct queue. 
		
		intr_enable();
		
	}
	
}
	
	
	
	
	
	
	
	
	



