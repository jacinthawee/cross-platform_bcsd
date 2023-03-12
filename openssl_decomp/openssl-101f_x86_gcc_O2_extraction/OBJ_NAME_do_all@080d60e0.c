
void OBJ_NAME_do_all(int type,fn *fn,void *arg)

{
  int in_GS_OFFSET;
  int local_1c;
  fn *local_18;
  void *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_1c = type;
  local_18 = fn;
  local_14 = arg;
  lh_doall_arg(names_lh,do_all_fn_LHASH_DOALL_ARG,&local_1c);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

