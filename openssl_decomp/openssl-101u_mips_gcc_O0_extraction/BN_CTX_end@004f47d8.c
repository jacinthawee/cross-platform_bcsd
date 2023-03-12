
void BN_CTX_end(BN_CTX *ctx)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(int *)(ctx + 0x24) != 0) {
    *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + -1;
    return;
  }
  iVar2 = *(int *)(ctx + 0x18);
  *(int *)(ctx + 0x18) = iVar2 + -1;
  uVar5 = *(uint *)(*(int *)(ctx + 0x14) + (iVar2 + -1) * 4);
  if (uVar5 < *(uint *)(ctx + 0x20)) {
    iVar3 = *(int *)(ctx + 0xc);
    iVar2 = *(uint *)(ctx + 0x20) - uVar5;
    *(int *)(ctx + 0xc) = iVar3 - iVar2;
    uVar4 = iVar3 - 1U & 0xf;
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      while (bVar1 = uVar4 == 0, uVar4 = uVar4 - 1, bVar1) {
        iVar2 = iVar2 + -1;
        uVar4 = 0xf;
        *(undefined4 *)(ctx + 4) = *(undefined4 *)(*(int *)(ctx + 4) + 0x140);
        if (iVar2 == -1) goto LAB_004f4858;
      }
    }
  }
LAB_004f4858:
  *(uint *)(ctx + 0x20) = uVar5;
  *(undefined4 *)(ctx + 0x28) = 0;
  return;
}

