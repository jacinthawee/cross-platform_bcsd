
void OBJ_NAME_do_all_sorted(int type,fn *fn,void *arg)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  int local_30;
  size_t local_2c;
  void *local_28;
  int local_24;
  undefined4 local_20;
  int *local_1c;
  
  local_1c = &local_30;
  local_30 = type;
  uVar2 = lh_num_items(names_lh);
  local_28 = CRYPTO_malloc(uVar2 << 2,"o_names.c",0x13a);
  if (local_28 != (void *)0x0) {
    iVar3 = 0;
    local_20 = 0x6bedd;
    local_2c = 0;
    local_24 = type;
    lh_doall_arg(names_lh,do_all_fn_LHASH_DOALL_ARG + 1,&local_24);
    qsort(local_28,local_2c,4,do_all_sorted_cmp + 1);
    if (0 < (int)local_2c) {
      do {
        iVar1 = iVar3 * 4;
        iVar3 = iVar3 + 1;
        (*fn)(*(OBJ_NAME **)((int)local_28 + iVar1),arg);
      } while (iVar3 < (int)local_2c);
    }
    CRYPTO_free(local_28);
  }
  return;
}

