
undefined4 gost_digest_cleanup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    (*(code *)PTR_memset_006aab00)(*(int *)(param_1 + 0xc),0,0x1090,param_4,&_gp);
    return 1;
  }
  return 1;
}

