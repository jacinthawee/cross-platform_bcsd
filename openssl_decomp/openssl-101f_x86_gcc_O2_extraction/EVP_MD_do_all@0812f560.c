
void EVP_MD_do_all(fn *fn,void *arg)

{
  int in_GS_OFFSET;
  void *local_18;
  fn *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = fn;
  local_18 = arg;
  OBJ_NAME_do_all(1,do_all_md_fn,&local_18);
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

