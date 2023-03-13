
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int in_GS_OFFSET;
  int local_28;
  size_t local_24;
  void *local_20;
  int local_1c;
  code *local_18;
  int *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = type;
  uVar2 = lh_num_items(names_lh);
  local_20 = CRYPTO_malloc(uVar2 << 2,"o_names.c",0x13a);
  if (local_20 != (void *)0x0) {
    local_14 = &local_28;
    local_1c = type;
    local_24 = 0;
    local_18 = do_all_sorted_fn;
    iVar3 = 0;
    lh_doall_arg(names_lh,do_all_fn_LHASH_DOALL_ARG,&local_1c);
    qsort(local_20,local_24,4,do_all_sorted_cmp);
    if (0 < (int)local_24) {
      do {
        iVar1 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        (*fn)(*(OBJ_NAME **)((int)local_20 + iVar1),arg);
      } while (iVar3 < (int)local_24);
    }
    CRYPTO_free(local_20);
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

