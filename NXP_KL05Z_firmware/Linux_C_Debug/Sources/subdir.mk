################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/ProcessorExpert.c 

OBJS += \
./Sources/Events.o \
./Sources/ProcessorExpert.o 

C_DEPS += \
./Sources/Events.d \
./Sources/ProcessorExpert.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-none-eabi-gcc -I"/home/karibe/eclipse/ProcessorExpert/lib/Kinetis/iofiles" -I"/home/karibe/eclipse/ProcessorExpert/lib/Kinetis/pdd/inc" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Generated_Code" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Project_Settings" -I"/home/karibe/src/FRDM_workspace/kl05_teset/Sources" -O2 -g3 -Wall -c -fmessage-length=0 -c -fmessage-length=0 -mcpu=cortex-m0 -mabi=aapcs -mthumb -msoft-float -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


