#include <pthread.h>
#include <mqueue.h>
#include "../headers/gamepadHandler.h"
#include "../headers/gamepadEventHandler.h"
#include "../headers/msgque.h"

#define AXISPOSIVE (32767)
#define AXISNEGATIVE (-32767)

void input(mqd_t mq, mq_msg_t msg) {

    // check receive message queue or not
    if(mq_receive(mq, (char*)&msg, sizeof(msg), NULL) != -1) {

        if(msg.type == DATA_TYPE_EVENT){
            button_event_t event = msg.data.event;

            // event.value = 1 : press the button
            // event.value = 0 : release the button
            if(event.type == JS_EVENT_BUTTON && event.value == 1){

                switch(event.name){

                    case BUTTON_A:
                        printf("You pressed A\n");
                        break;
                    case BUTTON_B:
                        printf("You pressed B\n");
                        break;
                    case BUTTON_X:
                        printf("You pressed X\n");
                        break;
                    case BUTTON_Y:
                        printf("You pressed Y\n");
                        break;
                    case BUTTON_LB:
                        printf("You pressed LB\n");
                        break;
                    case BUTTON_RB:
                        printf("You pressed RB\n");
                        break;
                    case BUTTON_START:
                        printf("You pressed START\n");
                        break;
                    case BUTTON_SELECT:
                        printf("You pressed SELECT\n");
                        break;
                }


            /*} else if(event.type == JS_EVENT_AXIS && event.value == 1) {*/
            // event.value = 1 : press the axis
            // event.value = 0 : release the axis
            } else if(event.type == JS_EVENT_AXIS && event.value != 0) {

                if(event.name == AXIS_X1){
                    if (event.value == AXISNEGATIVE) {
                        printf("LEFT moved axis x1 with value of %d\n", event.value);
                    } else if (event.value == AXISPOSIVE) {
                        printf("RIGHT moved axis x1 with value of %d\n", event.value);
                    }
                }
                else if(event.name == AXIS_Y1){
                    if (event.value == AXISNEGATIVE) {
                        printf("UP moved axis x1 with value of %d\n", event.value);
                    } else if (event.value == AXISPOSIVE) {
                        printf("DOWN moved axis x1 with value of %d\n", event.value);
                    }
                }
                else if(event.name == AXIS_X2){
                    printf("You moved axis x2 with value of %d\n", event.value);
                }
                else if(event.name == AXIS_X2){
                    printf("You moved axis x2 with value of %d\n", event.value);
                }

            }

        }

    }

}

int main(int argc, void * argv[]){

	pthread_t gamepadThread;
	pthread_create(&gamepadThread, NULL, gamepadHandler, NULL);

	usleep(1000);
	
	mqd_t mq;
	mq = mq_open(MQ_NAME, O_RDONLY | O_NONBLOCK);
	if (mq == -1) {
		puts("message queue not available");
		exit(1);
	}

	mq_msg_t msg;


    while(1) {
        input(mq, msg);

    }

}
