
bool ssl3_do_compress(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *(int *)(param_1 + 0x58);
  uVar2 = 0x4400;
  iVar1 = COMP_compress_block(*(COMP_CTX **)(param_1 + 0x94),*(uchar **)(iVar3 + 0x13c),0x4400,
                              *(uchar **)(iVar3 + 0x140),*(int *)(iVar3 + 0x134));
  bVar4 = -1 < iVar1;
  if (bVar4) {
    *(int *)(iVar3 + 0x134) = iVar1;
    uVar2 = *(undefined4 *)(iVar3 + 0x13c);
  }
  if (bVar4) {
    *(undefined4 *)(iVar3 + 0x140) = uVar2;
  }
  return bVar4;
}

