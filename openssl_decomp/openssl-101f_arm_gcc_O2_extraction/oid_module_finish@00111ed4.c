
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void oid_module_finish(void)

{
  _LHASH *p_Var1;
  _LHASH *lh;
  
  lh = added;
  p_Var1 = obj_cleanup_defer;
  if (obj_cleanup_defer == (_LHASH *)0x0) {
    if (added != (_LHASH *)0x0) {
      added->down_load = 0;
      lh_doall(lh,cleanup1_LHASH_DOALL + 1);
      lh_doall(added,cleanup2_LHASH_DOALL + 1);
      lh_doall(added,cleanup3_LHASH_DOALL + 1);
      lh_free(added);
      added = p_Var1;
    }
    return;
  }
  obj_cleanup_defer = (_LHASH *)0x2;
  return;
}

