/*
 ============================================================================
 Name        : C_project.c
 Author      : Youssef Osman
 Description : Vehicle Control System Project
 Data		 : 22/12/2023
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define ON 1
#define OFF 0

typedef struct {
	char EngineState;
	char ACstate;
	char EngineTemperatureController;
	int speed;
	int RoomTemperature;
	int EngineTemperature;
} DataToDisplay;

void First_List(void);
void Second_List(void);
void Ac_State(int* const, char* const);
void Engine_Temperature_Controller_State(int* const, char* const);
void Set_TrafficLightColor(char, int* const);
void Display(DataToDisplay*);

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char chose1, chose2;

	// Initial Values
	DataToDisplay data = { ON, OFF, OFF, 80, 35, 90 };
	DataToDisplay *ptr = &data;
	char Traffic_Light;

	do {
		First_List();
		scanf(" %c", &chose1);
		if (chose1 == 'a') {
			while (TRUE) {
				Second_List();
				scanf(" %c", &chose2);
				if (chose2 == 'a') {
					break;
				} else if (chose2 == 'b') {
					printf("enter the required color:\n");
					scanf(" %c", &Traffic_Light);
					Set_TrafficLightColor(Traffic_Light, &(data.speed));

				} else if (chose2 == 'c') {
					printf("enter the required room temperature:\n");
					scanf(" %d", &(data.RoomTemperature));
					Ac_State(&(data.RoomTemperature), &(data.ACstate));

				}

				else if (chose2 == 'd') {
					printf("enter the required engine temperature:\n");
					scanf(" %d", &(ptr->EngineTemperature));
					Engine_Temperature_Controller_State(
							&(ptr->EngineTemperature),
							&(ptr->EngineTemperatureController));
				}

				else {
				}

				if (30 == (ptr->speed)) {
					ptr->ACstate = ON;
					ptr->RoomTemperature = (ptr->RoomTemperature * (5 / 4) + 1);
				}
				Display(ptr);
			}

		} else if (chose1 == 'b') {
			printf("Turn off the vehicle engine\n\n");
			continue;
		} else {
			printf("Quit the system");
			return 0;
		}

	} while (TRUE);

}

void First_List(void) {
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
}
void Second_List(void) {
	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color.\n");
	printf("c. Set the room temperature (Temperature Sensor)\n");

	printf("d. Set the engine temperature (Engine Temperature Sensor)\n\n");

}

void Ac_State(int *const temp, char *const state) {
	if (*temp < 10) {
		*state = ON;
		*temp = 20;
	} else if (*temp > 30) {
		*state = ON;
		*temp = 20;
	} else {
		*state = OFF;
	}
}
void Engine_Temperature_Controller_State(int *temp, char *const state) {
	if (*temp < 100) {
		*state = ON;
		*temp = 125;
	} else if (*temp > 150) {
		*state = ON;
		*temp = 125;
	} else {
		*state = OFF;
	}
}

void Set_TrafficLightColor(char color, int *const speed) {
	if (color == 'G' || color == 'g') {
		*speed = 100;
	} else if (color == 'R' || color == 'r') {
		*speed = 0;
	} else if (color == 'O' || color == 'o') {
		*speed = 30;
	} else {

	}

}

void Display(DataToDisplay *d) {

	if (d->EngineState == 1)
		printf("Engine is ON\n");
	else
		printf("Engine is ON\n");
	if (d->ACstate == 1)
		printf("AC is ON\n");
	else
		printf("AC is ON\n");
	printf("Vehicle Speed: %d Km/Hr\n", d->speed);
	printf("Room Temperature %d C\n", d->RoomTemperature);
	if (d->EngineTemperatureController == 1)
		printf("Engine Temperature Controller is ON \n");
	else
		printf("Engine Temperature Controller is OFF\n");
	printf("Engine Temperature is %d C\n\n", d->EngineTemperature);
}
