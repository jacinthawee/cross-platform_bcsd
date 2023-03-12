
undefined4 init_gost_hash_ctx(int param_1,undefined4 param_2)

{
  int iVar1;
  
  (*(code *)PTR_memset_006a99f4)(param_1,0,0x70);
  iVar1 = (*(code *)PTR_malloc_006a9a58)(0x1020);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    gost_init(iVar1,param_2);
    return 1;
  }
  return 0;
}

