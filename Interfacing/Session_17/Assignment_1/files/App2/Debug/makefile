################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 5_SERVICE/subdir.mk
-include 3_APP/App_1/subdir.mk
-include 2_HAL/LCD/subdir.mk
-include 1_MCAL/TIMER/subdir.mk
-include 1_MCAL/EXTI/EXTI_PP/subdir.mk
-include 1_MCAL/DIO/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
lab16.lss \

FLASH_IMAGE += \
lab16.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: lab16.elf secondary-outputs

# Tool invocations
lab16.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,lab16.map -mmcu=atmega32 -o "lab16.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

lab16.lss: lab16.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S lab16.elf  >"lab16.lss"
	@echo 'Finished building: $@'
	@echo ' '

lab16.hex: lab16.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex lab16.elf  "lab16.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: lab16.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 lab16.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) lab16.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
