
undefined4 ssl3_do_uncompress(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x58);
  iVar2 = COMP_expand_block(*(COMP_CTX **)(param_1 + 0x88),*(uchar **)(iVar1 + 0x120),0x4000,
                            *(uchar **)(iVar1 + 0x118),*(int *)(iVar1 + 0x110));
  if (-1 < iVar2) {
    *(int *)(iVar1 + 0x110) = iVar2;
    *(undefined4 *)(iVar1 + 0x118) = *(undefined4 *)(iVar1 + 0x120);
    return 1;
  }
  return 0;
}

