
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OBJ_cleanup(void)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = added;
  puVar1 = PTR_lh_doall_006a95b0;
  if (obj_cleanup_defer == 0) {
    if (added != 0) {
      *(undefined4 *)(added + 0x20) = 0;
      (*(code *)puVar1)(iVar2,cleanup1_LHASH_DOALL);
      (*(code *)PTR_lh_doall_006a95b0)(added,cleanup2_LHASH_DOALL);
      (*(code *)PTR_lh_doall_006a95b0)(added,cleanup3_LHASH_DOALL);
      (*(code *)PTR_lh_free_006a8518)(added);
      added = 0;
    }
    return;
  }
  obj_cleanup_defer = 2;
  return;
}

