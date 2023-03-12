
undefined4 pkey_cmac_init(int param_1)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_CMAC_CTX_new_006a952c)();
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
    return 1;
  }
  return 0;
}

