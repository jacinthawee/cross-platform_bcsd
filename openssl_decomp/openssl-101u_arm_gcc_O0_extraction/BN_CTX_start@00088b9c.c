
void BN_CTX_start(BN_CTX *ctx)

{
  int num;
  void *__dest;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(ctx + 0x24);
  if ((iVar1 != 0) || (*(int *)(ctx + 0x28) != 0)) {
LAB_00088baa:
    *(int *)(ctx + 0x24) = iVar1 + 1;
    return;
  }
  iVar1 = *(int *)(ctx + 0x18);
  uVar2 = *(undefined4 *)(ctx + 0x20);
  if (iVar1 == *(int *)(ctx + 0x1c)) {
    num = 0x80;
    uVar3 = 0x20;
    if (iVar1 != 0) {
      uVar3 = (uint)(iVar1 * 3) >> 1;
      num = uVar3 << 2;
    }
    __dest = CRYPTO_malloc(num,"bn_ctx.c",0x152);
    if (__dest == (void *)0x0) {
      ERR_put_error(3,0x81,0x6d,"bn_ctx.c",0x106);
      iVar1 = *(int *)(ctx + 0x24);
      goto LAB_00088baa;
    }
    if (*(int *)(ctx + 0x18) != 0) {
      memcpy(__dest,*(void **)(ctx + 0x14),*(int *)(ctx + 0x18) << 2);
    }
    if (*(int *)(ctx + 0x1c) != 0) {
      CRYPTO_free(*(void **)(ctx + 0x14));
    }
    iVar1 = *(int *)(ctx + 0x18);
    *(void **)(ctx + 0x14) = __dest;
    *(uint *)(ctx + 0x1c) = uVar3;
  }
  else {
    __dest = *(void **)(ctx + 0x14);
  }
  *(int *)(ctx + 0x18) = iVar1 + 1;
  *(undefined4 *)((int)__dest + iVar1 * 4) = uVar2;
  return;
}

