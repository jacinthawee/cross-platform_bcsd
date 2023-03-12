
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OBJ_cleanup(void)

{
  _LHASH *lh;
  
  lh = added;
  if (obj_cleanup_defer == 0) {
    if (added != (_LHASH *)0x0) {
      added->down_load = 0;
      lh_doall(lh,cleanup1_LHASH_DOALL);
      lh_doall(added,cleanup2_LHASH_DOALL);
      lh_doall(added,cleanup3_LHASH_DOALL);
      lh_free(added);
      added = (_LHASH *)0x0;
    }
    return;
  }
  obj_cleanup_defer = 2;
  return;
}

