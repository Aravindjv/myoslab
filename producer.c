#include <stdio.h>
#include <stdlib.h>

int mutex=1, full=0, empty=3, x=0;

int wait(int s){
    return --s;
}
int signal(int s) {
    return ++s;
}

void producer() {
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item: %d", x);
    mutex=signal(mutex);
}
void consumer() {
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes the item: %d", x);
    x--;
    mutex=signal(mutex);
}

void main() {

    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1. Producer\n2. consumer\n3. Exit");
    while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                if(mutex==1 && empty!=0) producer(); else printf("Buffer is full.");
                break;
            case 2:
                if(mutex==1 && full!=0) consumer(); else printf("Buffer is empty.");
                break;
            case 3:
                return;
        }
    }
}
    /*
    1. Producer
    2. consumer
    3. Exit
    Enter your choice: 1

    Producer produces the item: 1
    Enter your choice: 1

    Producer produces the item: 2
    Enter your choice: 2

    Consumer consumes the item: 2
    Enter your choice: 2

    Consumer consumes the item: 1
    Enter your choice: 2
    Buffer is empty.
    Enter your choice: 3
*/