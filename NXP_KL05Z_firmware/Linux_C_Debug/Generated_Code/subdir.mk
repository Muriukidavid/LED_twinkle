################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/Bits1.c \
../Generated_Code/Cpu.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SysTick.c \
../Generated_Code/TI1.c \
../Generated_Code/TU1.c \
../Generated_Code/Vectors.c \
../Generated_Code/WAIT1.c 

OBJS += \
./Generated_Code/Bits1.o \
./Generated_Code/Cpu.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SysTick.o \
./Generated_Code/TI1.o \
./Generated_Code/TU1.o \
./Generated_Code/Vectors.o \
./Generated_Code/WAIT1.o 

C_DEPS += \
./Generated_Code/Bits1.d \
./Generated_Code/Cpu.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SysTick.d \
./Generated_Code/TI1.d \
./Generated_Code/TU1.d \
./Generated_Code/Vectors.d \
./Generated_Code/WAIT1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -I"/home/karibe/eclipse/ProcessorExpert/lib/Kinetis/iofiles" -I"/home/karibe/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Generated_Code" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Project_Settings" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Sources" -O2 -g3 -Wall -c -fmessage-length=0 -c -fmessage-length=0 -mcpu=cortex-m0 -mabi=aapcs -mthumb -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


