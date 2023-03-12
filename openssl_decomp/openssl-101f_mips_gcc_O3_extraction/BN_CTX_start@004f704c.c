
void BN_CTX_start(BN_CTX *ctx)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((*(int *)(ctx + 0x24) != 0) || (*(int *)(ctx + 0x28) != 0)) {
    *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + 1;
    return;
  }
  iVar1 = *(int *)(ctx + 0x18);
  uVar3 = *(undefined4 *)(ctx + 0x20);
  if (iVar1 == *(int *)(ctx + 0x1c)) {
    if (iVar1 == 0) {
      iVar1 = 0x80;
      uVar4 = 0x20;
    }
    else {
      uVar4 = (uint)(iVar1 * 3) >> 1;
      iVar1 = uVar4 << 2;
    }
    iVar2 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1,"bn_ctx.c",0x152);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x81,0x6d,"bn_ctx.c",0x108);
      *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + 1;
      return;
    }
    if (*(int *)(ctx + 0x18) != 0) {
      (*(code *)PTR_memcpy_006aabf4)(iVar2,*(undefined4 *)(ctx + 0x14),*(int *)(ctx + 0x18) << 2);
    }
    if (*(int *)(ctx + 0x1c) == 0) {
      iVar1 = *(int *)(ctx + 0x18);
    }
    else {
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(ctx + 0x14));
      iVar1 = *(int *)(ctx + 0x18);
    }
    *(int *)(ctx + 0x14) = iVar2;
    *(uint *)(ctx + 0x1c) = uVar4;
  }
  else {
    iVar2 = *(int *)(ctx + 0x14);
  }
  *(int *)(ctx + 0x18) = iVar1 + 1;
  *(undefined4 *)(iVar2 + iVar1 * 4) = uVar3;
  return;
}

