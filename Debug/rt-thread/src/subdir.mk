################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/src/clock.c \
../rt-thread/src/components.c \
../rt-thread/src/device.c \
../rt-thread/src/idle.c \
../rt-thread/src/ipc.c \
../rt-thread/src/irq.c \
../rt-thread/src/kservice.c \
../rt-thread/src/mem.c \
../rt-thread/src/mempool.c \
../rt-thread/src/object.c \
../rt-thread/src/scheduler.c \
../rt-thread/src/thread.c \
../rt-thread/src/timer.c 

OBJS += \
./rt-thread/src/clock.o \
./rt-thread/src/components.o \
./rt-thread/src/device.o \
./rt-thread/src/idle.o \
./rt-thread/src/ipc.o \
./rt-thread/src/irq.o \
./rt-thread/src/kservice.o \
./rt-thread/src/mem.o \
./rt-thread/src/mempool.o \
./rt-thread/src/object.o \
./rt-thread/src/scheduler.o \
./rt-thread/src/thread.o \
./rt-thread/src/timer.o 

C_DEPS += \
./rt-thread/src/clock.d \
./rt-thread/src/components.d \
./rt-thread/src/device.d \
./rt-thread/src/idle.d \
./rt-thread/src/ipc.d \
./rt-thread/src/irq.d \
./rt-thread/src/kservice.d \
./rt-thread/src/mem.d \
./rt-thread/src/mempool.d \
./rt-thread/src/object.d \
./rt-thread/src/scheduler.d \
./rt-thread/src/thread.d \
./rt-thread/src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/src/%.o: ../rt-thread/src/%.c
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DSOC_FAMILY_STM32 -DSOC_SERIES_STM32F4 -DUSE_HAL_DRIVER -DSTM32F407xx -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\drivers" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\drivers\include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\drivers\include\config" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\CMSIS\Device\ST\STM32F4xx\Include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\CMSIS\Include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\CMSIS\RTOS\Template" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\STM32F4xx_HAL_Driver\Inc" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\libraries\STM32F4xx_HAL_Driver\Inc\Legacy" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\applications" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\cubemx\Inc" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\cubemx" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\drivers\include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\drivers\spi" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\finsh" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\compilers\common" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\compilers\newlib" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\posix\io\poll" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\posix\io\stdio" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\components\libc\posix\ipc" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\include" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\libcpu\arm\common" -I"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rt-thread\libcpu\arm\cortex-m4" -include"D:\RT-ThreadStudio\workspace1\STM32F407VG_RC522\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

