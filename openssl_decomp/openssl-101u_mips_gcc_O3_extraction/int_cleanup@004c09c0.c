
/* WARNING: Removing unreachable block (ram,0x004bcc7c) */
/* WARNING: Removing unreachable block (ram,0x004bcd00) */
/* WARNING: Removing unreachable block (ram,0x004bccac) */
/* WARNING: Removing unreachable block (ram,0x004bccc8) */
/* WARNING: Removing unreachable block (ram,0x004bcd24) */
/* WARNING: Removing unreachable block (ram,0x004bcd6c) */
/* WARNING: Removing unreachable block (ram,0x004bcd90) */
/* WARNING: Removing unreachable block (ram,0x004bce1c) */
/* WARNING: Removing unreachable block (ram,0x004bce2c) */
/* WARNING: Removing unreachable block (ram,0x004bce3c) */
/* WARNING: Removing unreachable block (ram,0x004bce6c) */
/* WARNING: Removing unreachable block (ram,0x004bceb0) */
/* WARNING: Removing unreachable block (ram,0x004bce7c) */
/* WARNING: Removing unreachable block (ram,0x004bcdac) */
/* WARNING: Removing unreachable block (ram,0x004bcea0) */
/* WARNING: Removing unreachable block (ram,0x004bcdbc) */
/* WARNING: Removing unreachable block (ram,0x004bcde0) */
/* WARNING: Removing unreachable block (ram,0x004bcdf4) */
/* WARNING: Removing unreachable block (ram,0x004bcdf8) */

undefined * int_cleanup(void)

{
  undefined *puVar1;
  
  if (ex_data == 0) {
    CRYPTO_lock(9,2,"ex_data.c",0x116);
    if (ex_data == 0) {
      ex_data = (*(code *)PTR_lh_new_006a740c)(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP);
      if (ex_data == 0) {
        if (locking_callback == (code *)0x0) {
          return &_gp_1;
        }
                    /* WARNING: Could not recover jumptable at 0x004bcc74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar1 = (undefined *)(*locking_callback)();
        return puVar1;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x119);
  }
  (*(code *)PTR_lh_doall_006a8490)(ex_data,def_cleanup_cb);
  (*(code *)PTR_lh_free_006a7418)(ex_data);
  ex_data = 0;
  impl = 0;
  return &_gp_1;
}

