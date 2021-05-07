/* A kernel module that display info about kerenl VAS and can take an option to also display
   user space VAS details. */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>

#define CALC_DELTA(A, B) (A), (B), (B-A)
#define CALC_DELTA_KB(A, B) (A), (B), ((B-A) >> 10)
#define CALC_DELTA_MB(A, B) (A), (B), ((B-A) >> 20)
#define CALC_DELTA_GB(A, B) (A), (B), ((B-A) >> 30)

extern void* high_memory;

int __init start(void){

        // PRINT page offset
    pr_info("\n*********************************");
    pr_info("[+] Kernel vas start at %pK", PAGE_OFFSET);
    pr_info("*********************************\n");


        // print fixmap region memory locations 
    pr_info("\n*********************************");
    pr_info("[+] Kernel fix map region Start at %pK\n \
    [+] Kernel fix map region End at %pK\n \
    [+] Kernel fix map region size is %d B", FIXADDR_START, (FIXADDR_START + FIXADDR_SIZE), 
    FIXADDR_SIZE);
    pr_info("*********************************\n");

        // print modules area  location where static code of modules and its data are placed
    pr_info("\n*********************************");
    pr_info("[+] Kerenl modules area start at %pK\n \
    [+] Kernel modules area end at %pK\n \
    [+] Kernel modules area size is %d MB", CALC_DELTA_MB(MODULES_VADDR, MODULES_END));
    pr_info("*********************************\n");


        // Print vmalloc region details
    pr_info("\n*********************************");
    pr_info("[+] Vmalloc region start at %pK\n \
    [+] vmalloc region end at %pK \n \
    [+] vmalloc region size is %d GB", CALC_DELTA_GB(VMALLOC_START, VMALLOC_END));
    pr_info("*********************************\n");

    pr_info("\n*********************************");
    pr_info("[+] Kernel lowmem region start at %pK\n \
    [+] Kernel lowmem region end at %pK \n \
    [+] Kernel lowmem region size is %d GB", CALC_DELTA_GB((void*)PAGE_OFFSET, high_memory));
    pr_info("*********************************\n");

        // PRINT user sace VAS size 
    pr_info("\n*********************************");
    pr_info("[+] User space VAS size is %d TB", (TASK_SIZE >> 40));
    pr_info("*********************************\n");

    return 0;
}

void __exit end(void){
}
module_init(start);
module_exit(end);
