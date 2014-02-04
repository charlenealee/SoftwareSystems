#include <stdio.h>
#include <stdlib.h>



int main() {
	char card_name[3];
	int count = 0;
	int val = 0;
	while (val != -1) {
		puts("Enter the card name:");
		scanf("%2s", card_name);
		val = testSwitch(card_name);
	    count = changeVal(val,count);
	}
	return 0;
}
		
int testSwitch(char *card_name){
	int val = 0;		
		switch(card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			break;
		default:
			val = atoi(card_name);
			if ((val < 1) || (val > 10)) {
				puts("I don't understand!");
				break;
			}
		}
		return val;
	}
	
	
	
	int changeVal(int val, int count){
	/* Check if the value is 3 to 6 */
		if ((val > 2) && (val < 7)) {
			puts("Count has gone up");
			count++;
	/* Otherwise check if the card was 10, J, Q, or K */
		} else if (val == 10) {
			puts("Count has gone down");
			count--;
		}
		printf("Current count is %i\n", count);
		return count;
	}
	
	
	
	
