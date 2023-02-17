################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../lwip/src/core/ipv6/dhcp6.c \
../lwip/src/core/ipv6/ethip6.c \
../lwip/src/core/ipv6/icmp6.c \
../lwip/src/core/ipv6/inet6.c \
../lwip/src/core/ipv6/ip6.c \
../lwip/src/core/ipv6/ip6_addr.c \
../lwip/src/core/ipv6/ip6_frag.c \
../lwip/src/core/ipv6/mld6.c \
../lwip/src/core/ipv6/nd6.c 

C_DEPS += \
./lwip/src/core/ipv6/dhcp6.d \
./lwip/src/core/ipv6/ethip6.d \
./lwip/src/core/ipv6/icmp6.d \
./lwip/src/core/ipv6/inet6.d \
./lwip/src/core/ipv6/ip6.d \
./lwip/src/core/ipv6/ip6_addr.d \
./lwip/src/core/ipv6/ip6_frag.d \
./lwip/src/core/ipv6/mld6.d \
./lwip/src/core/ipv6/nd6.d 

OBJS += \
./lwip/src/core/ipv6/dhcp6.o \
./lwip/src/core/ipv6/ethip6.o \
./lwip/src/core/ipv6/icmp6.o \
./lwip/src/core/ipv6/inet6.o \
./lwip/src/core/ipv6/ip6.o \
./lwip/src/core/ipv6/ip6_addr.o \
./lwip/src/core/ipv6/ip6_frag.o \
./lwip/src/core/ipv6/mld6.o \
./lwip/src/core/ipv6/nd6.o 


# Each subdirectory must supply rules for building sources it contributes
lwip/src/core/ipv6/%.o: ../lwip/src/core/ipv6/%.c lwip/src/core/ipv6/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -DCPU_MK64FN1M0VLL12 -DCPU_MK64FN1M0VLL12_cm4 -DUSE_RTOS=1 -DPRINTF_ADVANCED_ENABLE=1 -DFRDM_K64F -DFREEDOM -DLWIP_DISABLE_PBUF_POOL_SIZE_SANITY_CHECKS=1 -DSERIAL_PORT_TYPE_UART=1 -DSDK_OS_FREE_RTOS -DMCUXPRESSO_SDK -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -D__REDLIB__ -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/source" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/mdio" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/phy" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/lwip/contrib/apps/tcpecho" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/lwip/port" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/lwip/src" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/lwip/src/include" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/drivers" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/utilities" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/device" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/component/uart" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/component/serial_manager" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/component/lists" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/CMSIS" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/freertos/freertos_kernel/include" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/freertos/freertos_kernel/portable/GCC/ARM_CM4F" -I"/Users/snaiderbautista/Documents/MCUXpressoIDE_11.6.1_8255/workspace/lwip_tcpecho_freertos_pr1/board" -O0 -fno-common -g3 -c -ffunction-sections -fdata-sections -ffreestanding -fno-builtin -fmerge-constants -fmacro-prefix-map="$(<D)/"= -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-lwip-2f-src-2f-core-2f-ipv6

clean-lwip-2f-src-2f-core-2f-ipv6:
	-$(RM) ./lwip/src/core/ipv6/dhcp6.d ./lwip/src/core/ipv6/dhcp6.o ./lwip/src/core/ipv6/ethip6.d ./lwip/src/core/ipv6/ethip6.o ./lwip/src/core/ipv6/icmp6.d ./lwip/src/core/ipv6/icmp6.o ./lwip/src/core/ipv6/inet6.d ./lwip/src/core/ipv6/inet6.o ./lwip/src/core/ipv6/ip6.d ./lwip/src/core/ipv6/ip6.o ./lwip/src/core/ipv6/ip6_addr.d ./lwip/src/core/ipv6/ip6_addr.o ./lwip/src/core/ipv6/ip6_frag.d ./lwip/src/core/ipv6/ip6_frag.o ./lwip/src/core/ipv6/mld6.d ./lwip/src/core/ipv6/mld6.o ./lwip/src/core/ipv6/nd6.d ./lwip/src/core/ipv6/nd6.o

.PHONY: clean-lwip-2f-src-2f-core-2f-ipv6

