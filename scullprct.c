#include<scull1.h>
int scull_major=SCULL_MAJOR;
int scull_minor=0;
int scull_init_module(void) {
   int result, i;
   dev_t dev = 0;
   
   /*
    * Get a range of minor numbers to work with, asking for a dynamic
    * major unless directed otherwise at load time.
    */
   if (scull_major) {
      dev = MKDEV(scull_major, scull_minor);
      result = register_chrdev_region(dev, scull_nr_devs, "scull");
   } else {
      result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs,
				   "scull");
      scull_major = MAJOR(dev);
   }
   if (result < 0) {
      printk(KERN_WARNING "scull: can't get major %d\n", scull_major);
      return result;
   }
   
