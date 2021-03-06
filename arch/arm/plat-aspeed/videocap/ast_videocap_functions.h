/****************************************************************
 ****************************************************************
 **                                                            **
 **    (C)Copyright 2006-2009, American Megatrends Inc.        **
 **                                                            **
 **            All Rights Reserved.                            **
 **                                                            **
 **        5555 Oakbrook Pkwy Suite 200, Norcross              **
 **                                                            **
 **        Georgia - 30093, USA. Phone-(770)-246-8600.         **
 **                                                            **
 ****************************************************************
 ****************************************************************/

#ifndef __AST_VIDEOCAP_FUNCTIONS_H__
#define __AST_VIDEOCAP_FUNCTIONS_H__

#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/sysctl.h>

/* Function prototypes for proc and sysctl entry addition and removal */
struct proc_dir_entry *AddProcEntry(struct proc_dir_entry *moduledir,char *KeyName,
		read_proc_t *read_proc, write_proc_t *write_proc,void *PrivateData);
struct ctl_table_header *AddSysctlTable(char *ModuleName,struct ctl_table* ModuleTable);

extern struct proc_dir_entry *rootdir;

void RemoveProcEntry(struct proc_dir_entry *moduledir, char *KeyName);
void RemoveSysctlTable(struct ctl_table_header *table_header);

extern uint32_t ast_videocap_read_reg(uint32_t reg);
extern void ast_videocap_write_reg(uint32_t data, uint32_t reg);

/* defined in mmap.c, used in module.c */
extern int ast_videocap_mmap(struct file *filp, struct vm_area_struct *vma);

/* Defined in ioctl.c, used in module.c */
extern int ast_videocap_ioctl(struct inode *inode, struct file *filep,unsigned int cmd, unsigned long arg);

/* defined in proc.c, used in module.c */
extern void ast_videocap_add_proc_entries(void);
extern void ast_videocap_del_proc_entries(void);

/* defined in engine.c, used in module.c */
extern void ast_videocap_engine_data_init(void);
extern int ast_videocap_remap_vga_mem(void);
extern void ast_videocap_unmap_vga_mem(void);
extern irqreturn_t ast_videocap_irq_handler(int irq, void *dev_id);

/* Defined in engine.c and used in ioctl.c */
extern void ast_videocap_reset_hw(void);
extern void ast_videocap_hw_init(void);
extern int StartVideoCapture(struct ast_videocap_engine_info_t *info);
extern void StopVideoCapture(void);
extern int ast_videocap_create_video_packet(struct ast_videocap_engine_info_t *info, unsigned long *size);
extern int ast_videocap_create_cursor_packet(struct ast_videocap_engine_info_t *info, unsigned long *size);
extern int ast_videocap_set_engine_config(struct ast_videocap_engine_info_t *info, struct ast_videocap_engine_config_t *config);
extern int ast_videocap_get_engine_config(struct ast_videocap_engine_info_t *info, struct ast_videocap_engine_config_t *config, unsigned long *size);
extern int ast_videocap_enable_video_dac(struct ast_videocap_engine_info_t *info, struct ast_videocap_engine_config_t *config);

#endif /* !__AST_VIDEOCAP_FUNCTIONS_H__ */
