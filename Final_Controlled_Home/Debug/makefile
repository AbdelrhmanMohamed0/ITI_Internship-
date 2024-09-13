################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 3_APP/User_Management/subdir.mk
-include 3_APP/Pass_check/subdir.mk
-include 3_APP/Master_User/subdir.mk
-include 3_APP/App_1/subdir.mk
-include 2_HAL/Servo/subdir.mk
-include 2_HAL/LED/subdir.mk
-include 2_HAL/EEPROM/subdir.mk
-include 2_HAL/BUZZER/subdir.mk
-include 1_MCAL/USART/subdir.mk
-include 1_MCAL/TWI/subdir.mk
-include 1_MCAL/TIMER/subdir.mk
-include 1_MCAL/GIE/subdir.mk
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
Final_Controlled_Home.lss \

FLASH_IMAGE += \
Final_Controlled_Home.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Final_Controlled_Home.elf secondary-outputs

# Tool invocations
Final_Controlled_Home.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Final_Controlled_Home.map -mmcu=atmega32 -o "Final_Controlled_Home.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Final_Controlled_Home.lss: Final_Controlled_Home.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Final_Controlled_Home.elf  >"Final_Controlled_Home.lss"
	@echo 'Finished building: $@'
	@echo ' '

Final_Controlled_Home.hex: Final_Controlled_Home.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Final_Controlled_Home.elf  "Final_Controlled_Home.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Final_Controlled_Home.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Final_Controlled_Home.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Final_Controlled_Home.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
