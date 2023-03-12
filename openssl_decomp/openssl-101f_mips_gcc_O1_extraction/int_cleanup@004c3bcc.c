
/* WARNING: Removing unreachable block (ram,0x004bfddc) */
/* WARNING: Removing unreachable block (ram,0x004bfe60) */
/* WARNING: Removing unreachable block (ram,0x004bfe0c) */
/* WARNING: Removing unreachable block (ram,0x004bfe28) */
/* WARNING: Removing unreachable block (ram,0x004bfe84) */
/* WARNING: Removing unreachable block (ram,0x004bfecc) */
/* WARNING: Removing unreachable block (ram,0x004bfef0) */
/* WARNING: Removing unreachable block (ram,0x004bff7c) */
/* WARNING: Removing unreachable block (ram,0x004bff8c) */
/* WARNING: Removing unreachable block (ram,0x004bff9c) */
/* WARNING: Removing unreachable block (ram,0x004bffcc) */
/* WARNING: Removing unreachable block (ram,0x004c0010) */
/* WARNING: Removing unreachable block (ram,0x004bffdc) */
/* WARNING: Removing unreachable block (ram,0x004bff0c) */
/* WARNING: Removing unreachable block (ram,0x004c0000) */
/* WARNING: Removing unreachable block (ram,0x004bff1c) */
/* WARNING: Removing unreachable block (ram,0x004bff40) */
/* WARNING: Removing unreachable block (ram,0x004bff54) */
/* WARNING: Removing unreachable block (ram,0x004bff58) */

undefined1 * int_cleanup(void)

{
  undefined1 *puVar1;
  
  if (ex_data == 0) {
    CRYPTO_lock(9,2,"ex_data.c",0x10e);
    if (ex_data == 0) {
      ex_data = (*(code *)PTR_lh_new_006a850c)(ex_class_item_LHASH_HASH,ex_class_item_LHASH_COMP);
      if (ex_data == 0) {
        if (locking_callback == (code *)0x0) {
          return &_ITM_registerTMCloneTable;
        }
                    /* WARNING: Could not recover jumptable at 0x004bfdd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        puVar1 = (undefined1 *)(*locking_callback)();
        return puVar1;
      }
    }
    CRYPTO_lock(10,2,"ex_data.c",0x112);
  }
  (*(code *)PTR_lh_doall_006a95b0)(ex_data,def_cleanup_cb);
  (*(code *)PTR_lh_free_006a8518)(ex_data);
  ex_data = 0;
  impl = 0;
  return &_ITM_registerTMCloneTable;
}

