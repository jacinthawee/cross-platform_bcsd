
bool ssl3_do_uncompress(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  
  iVar3 = *(int *)(param_1 + 0x58);
  uVar2 = 0x4000;
  iVar1 = COMP_expand_block(*(COMP_CTX **)(param_1 + 0x88),*(uchar **)(iVar3 + 0x120),0x4000,
                            *(uchar **)(iVar3 + 0x118),*(int *)(iVar3 + 0x110));
  bVar4 = -1 < iVar1;
  if (bVar4) {
    *(int *)(iVar3 + 0x110) = iVar1;
    uVar2 = *(undefined4 *)(iVar3 + 0x120);
  }
  if (bVar4) {
    *(undefined4 *)(iVar3 + 0x118) = uVar2;
  }
  return bVar4;
}

