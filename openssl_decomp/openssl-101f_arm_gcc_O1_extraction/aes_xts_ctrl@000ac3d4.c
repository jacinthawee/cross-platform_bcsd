
undefined4 aes_xts_ctrl(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60);
  if (param_2 == 0) {
    *(undefined4 *)(iVar1 + 0x1e8) = 0;
    *(undefined4 *)(iVar1 + 0x1ec) = 0;
    return 1;
  }
  return 0xffffffff;
}

