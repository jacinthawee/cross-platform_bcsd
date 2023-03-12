
void BN_CTX_end(BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(ctx + 0x24) != 0) {
    *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + -1;
    return;
  }
  iVar1 = *(int *)(ctx + 0x18);
  *(int *)(ctx + 0x18) = iVar1 + -1;
  uVar2 = *(uint *)(*(int *)(ctx + 0x14) + (iVar1 + -1) * 4);
  if (uVar2 < *(uint *)(ctx + 0x20)) {
    iVar1 = *(int *)(ctx + 0xc);
    iVar3 = *(uint *)(ctx + 0x20) - uVar2;
    *(int *)(ctx + 0xc) = iVar1 - iVar3;
    uVar4 = iVar1 - 1U & 0xf;
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      while (uVar4 == 0) {
        iVar3 = iVar3 + -1;
        *(undefined4 *)(ctx + 4) = *(undefined4 *)(*(int *)(ctx + 4) + 0x140);
        uVar4 = 0xf;
        if (iVar3 == -1) goto LAB_080f797d;
      }
      uVar4 = uVar4 - 1;
    }
  }
LAB_080f797d:
  *(uint *)(ctx + 0x20) = uVar2;
  *(undefined4 *)(ctx + 0x28) = 0;
  return;
}

