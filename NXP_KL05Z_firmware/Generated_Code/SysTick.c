/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SysTick.c
**     Project     : ProcessorExpert
**     Processor   : MKL05Z32VLC4
**     Component   : Init_SysTick
**     Version     : Component 01.002, Driver 01.02, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2014-03-18, 02:40, # CodeGen: 88
**     Abstract    :
**          This file implements the SysTick (SysTick) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : SysTick
**          Device                                         : SysTick
**          Settings                                       : 
**            Clock source                                 : Processor clock
**            Reload value                                 : 6000000
**            Counter period                               : 286.102 ms
**          Interrupts                                     : 
**            Interrupt                                    : INT_SysTick
**            Interrupt priority                           : 0 (Highest)
**            ISR Name                                     : 
**            Timer interrupt                              : Disabled
**          Initialization                                 : 
**            Timer enable                                 : yes
**            Clear counter                                : yes
**            Call Init method                             : yes
**     Contents    :
**         Init - void SysTick_Init(void);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file SysTick.c
** @version 01.02
** @date 2014-03-18, 02:40, # CodeGen: 88
** @brief
**          This file implements the SysTick (SysTick) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup SysTick_module SysTick module documentation
**  @{
*/         

/* MODULE SysTick. */

#include "SysTick.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  SysTick_Init (component Init_SysTick)
**     Description :
**         This method initializes registers of the SysTick module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void SysTick_Init(void)
{
  /* SYST_CSR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNTFLAG=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CLKSOURCE=0,TICKINT=0,ENABLE=0 */
  SYST_CSR = 0x00U;                                   
  /* SYST_RVR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,RELOAD=0x005B8D80 */
  SYST_RVR = SysTick_RVR_RELOAD(0x005B8D80);                                   
  /* SYST_CVR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CURRENT=0 */
  SYST_CVR = SysTick_CVR_CURRENT(0x00);                                   
  /* SYST_CSR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNTFLAG=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CLKSOURCE=1,TICKINT=0,ENABLE=1 */
  SYST_CSR = (SysTick_CSR_CLKSOURCE_MASK | SysTick_CSR_ENABLE_MASK);                                   
}


/* END SysTick. */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.06]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/