
undefined4 ssl3_do_compress(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x58);
  iVar2 = COMP_compress_block(*(COMP_CTX **)(param_1 + 0x94),*(uchar **)(iVar1 + 0x13c),0x4400,
                              *(uchar **)(iVar1 + 0x140),*(int *)(iVar1 + 0x134));
  if (-1 < iVar2) {
    *(int *)(iVar1 + 0x134) = iVar2;
    *(undefined4 *)(iVar1 + 0x140) = *(undefined4 *)(iVar1 + 0x13c);
    return 1;
  }
  return 0;
}

