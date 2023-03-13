
void OBJ_NAME_cleanup(int type)

{
  ulong uVar1;
  _LHASH *lh;
  
  lh = names_lh;
  if (names_lh != (_LHASH *)0x0) {
    uVar1 = names_lh->down_load;
    names_lh->down_load = 0;
    free_type = type;
    lh_doall(lh,names_lh_free_LHASH_DOALL);
    if (type < 0) {
      lh_free(names_lh);
      sk_pop_free(name_funcs_stack,name_funcs_free);
      names_lh = (_LHASH *)0x0;
      name_funcs_stack = (_STACK *)0x0;
    }
    else {
      names_lh->down_load = uVar1;
    }
  }
  return;
}

