
obj-m+=dummy.o
 
all:
 make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
 $(CC) testdummy.c -o test
clean:
 make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean
 rm test
