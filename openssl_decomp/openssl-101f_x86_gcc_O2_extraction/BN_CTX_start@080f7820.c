
void BN_CTX_start(BN_CTX *ctx)

{
  undefined4 uVar1;
  int iVar2;
  void *__dest;
  uint uVar3;
  
  if ((*(int *)(ctx + 0x24) != 0) || (*(int *)(ctx + 0x28) != 0)) {
    *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + 1;
    return;
  }
  iVar2 = *(int *)(ctx + 0x18);
  uVar1 = *(undefined4 *)(ctx + 0x20);
  if (iVar2 == *(int *)(ctx + 0x1c)) {
    if (iVar2 == 0) {
      iVar2 = 0x80;
      uVar3 = 0x20;
    }
    else {
      uVar3 = (uint)(iVar2 * 3) >> 1;
      iVar2 = uVar3 * 4;
    }
    __dest = CRYPTO_malloc(iVar2,"bn_ctx.c",0x152);
    if (__dest == (void *)0x0) {
      ERR_put_error(3,0x81,0x6d,"bn_ctx.c",0x108);
      *(int *)(ctx + 0x24) = *(int *)(ctx + 0x24) + 1;
      return;
    }
    if (*(int *)(ctx + 0x18) != 0) {
      memcpy(__dest,*(void **)(ctx + 0x14),*(int *)(ctx + 0x18) << 2);
    }
    if (*(int *)(ctx + 0x1c) != 0) {
      CRYPTO_free(*(void **)(ctx + 0x14));
    }
    *(void **)(ctx + 0x14) = __dest;
    *(uint *)(ctx + 0x1c) = uVar3;
    iVar2 = *(int *)(ctx + 0x18);
  }
  else {
    __dest = *(void **)(ctx + 0x14);
  }
  *(int *)(ctx + 0x18) = iVar2 + 1;
  *(undefined4 *)((int)__dest + iVar2 * 4) = uVar1;
  return;
}

