#include "Driver_I2C.h"
#include "PIN_LPC17xx.h"
#include "GPIO_LPC17xx.h"
#include "LED_LPC1768.h"
#include "cmsis_os.h"

extern ARM_DRIVER_I2C							Driver_I2C2;
static ARM_DRIVER_I2C *I2Cdrv =  &Driver_I2C2;

static volatile uint32_t I2C_Event;


/* I2C Signal Event function callback */
void I2C_SignalEvent (uint32_t event) {
 
  /* Save received events */
  I2C_Event |= event;
 
  /* Optionally, user can define specific actions for an event */
 
  if (event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) {
    /* Less data was transferred than requested */
  }
 
  if (event & ARM_I2C_EVENT_TRANSFER_DONE) {
    /* Transfer or receive is finished */
  }
 
  if (event & ARM_I2C_EVENT_ADDRESS_NACK) {
    /* Slave address was not acknowledged */
	
  }
 
  if (event & ARM_I2C_EVENT_ARBITRATION_LOST) {
    /* Master lost bus arbitration */
  }
 
  if (event & ARM_I2C_EVENT_BUS_ERROR) {
    /* Invalid start/stop position detected */	
  }
 
  if (event & ARM_I2C_EVENT_BUS_CLEAR) {
    /* Bus clear operation completed */
  }
 
  if (event & ARM_I2C_EVENT_GENERAL_CALL) {
    /* Slave was addressed with a general call address */
  }
 
  if (event & ARM_I2C_EVENT_SLAVE_RECEIVE) {
    /* Slave addressed as receiver but SlaveReceive operation is not started */
  }
 
  if (event & ARM_I2C_EVENT_SLAVE_TRANSMIT) {
    /* Slave addressed as transmitter but SlaveTransmit operation is not started */
  }
}


void Init_I2C(void){
		
	/* Initialize I2C peripheral */
		I2Cdrv->Initialize(I2C_SignalEvent);
 
	/* Power-on I2C peripheral */
		I2Cdrv->PowerControl(ARM_POWER_FULL);
 
	/* Configure I2C Speed */
		I2Cdrv->Control(ARM_I2C_BUS_SPEED,ARM_I2C_BUS_SPEED_FAST);
	
	/* Clear I2C bus*/	
		I2Cdrv->Control(ARM_I2C_BUS_CLEAR,0);
	
}

int main (void){
	
	//uint8_t reg = 0;
	uint8_t reg[] = {0x01,0x02,0x04,0x08};
	uint8_t buf = 0;
	int master_leds = 0;
	
	Init_I2C();							// Initialize I2C
	SystemCoreClockUpdate ();			// System Initialization
	LED_Initialize ();					// Initialize LEDs
	osKernelInitialize ();				// Initialize CMSIS-RTOS
	osKernelStart ();					// Start thread execution
	
	/* Clear event flags */
		I2C_Event = 0U;
	
	while (1){		
	
	/**************************  BITE 1 **************************************/
		 /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterTransmit (0x40, &reg[0], 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
		 
		  /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterReceive (0x40, &buf, 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
			
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
		  
	/**************************  BITE 2 **************************************/
		 /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterTransmit (0x40, &reg[1], 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
		 
		  /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterReceive (0x40, &buf, 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
			
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
	  
	/**************************  BITE 3 **************************************/
		 /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterTransmit (0x40, &reg[2], 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
		 
		  /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterReceive (0x40, &buf, 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
			
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
		  
	/**************************  BITE 4 **************************************/
		 /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterTransmit (0x40, &reg[3], 1, true);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
		 
		  /* Clear event flags before new transfer */
		  I2C_Event = 0U;
		 
		  I2Cdrv->MasterReceive (0x40, &buf, 1, false);
		 
		  /* Wait until transfer completed */
		  while ((I2C_Event & ARM_I2C_EVENT_TRANSFER_DONE) == 0U);
			
		  /* Check if all data transferred */
		  if ((I2C_Event & ARM_I2C_EVENT_TRANSFER_INCOMPLETE) != 0U) return -1;
	  
	/**************************************************************************/	 	  

	}		
}
