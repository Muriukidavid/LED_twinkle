################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Settings/Startup_Code/startup.c 

S_UPPER_SRCS += \
../Project_Settings/Startup_Code/startup.S 

OBJS += \
./Project_Settings/Startup_Code/startup.o 

C_DEPS += \
./Project_Settings/Startup_Code/startup.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	arm-none-eabi-as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/%.o: ../Project_Settings/Startup_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -I"/home/karibe/eclipse/ProcessorExpert/lib/Kinetis/iofiles" -I"/home/karibe/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Generated_Code" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Project_Settings" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Sources" -O2 -g3 -Wall -c -fmessage-length=0 -c -fmessage-length=0 -mcpu=cortex-m0 -mabi=aapcs -mthumb -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


