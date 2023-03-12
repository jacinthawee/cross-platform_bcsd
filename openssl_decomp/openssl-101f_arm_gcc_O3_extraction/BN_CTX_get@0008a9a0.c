
BIGNUM * BN_CTX_get(BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  uint uVar5;
  BIGNUM *a;
  BIGNUM *pBVar6;
  
  if (*(int *)(ctx + 0x24) != 0) {
    return (BIGNUM *)0x0;
  }
  if (*(int *)(ctx + 0x28) != 0) {
    return (BIGNUM *)0x0;
  }
  uVar3 = *(uint *)(ctx + 0xc);
  if (uVar3 == *(uint *)(ctx + 0x10)) {
    a = (BIGNUM *)CRYPTO_malloc(0x148,"bn_ctx.c",0x199);
    pBVar1 = a;
    if (a == (BIGNUM *)0x0) goto LAB_0008aa52;
    do {
      pBVar6 = pBVar1 + 1;
      BN_init(pBVar1);
      pBVar1 = pBVar6;
    } while (pBVar6 != a + 0x10);
    puVar4 = *(ulong **)(ctx + 8);
    iVar2 = *(int *)ctx;
    a[0x10].top = 0;
    a[0x10].d = puVar4;
    if (iVar2 == 0) {
      *(BIGNUM **)(ctx + 8) = a;
      *(BIGNUM **)(ctx + 4) = a;
      *(BIGNUM **)ctx = a;
    }
    else {
      puVar4[0x51] = (ulong)a;
      *(BIGNUM **)(ctx + 8) = a;
      *(BIGNUM **)(ctx + 4) = a;
    }
    *(int *)(ctx + 0x10) = *(int *)(ctx + 0x10) + 0x10;
    *(int *)(ctx + 0xc) = *(int *)(ctx + 0xc) + 1;
  }
  else {
    if (uVar3 == 0) {
      iVar2 = *(int *)ctx;
      *(int *)(ctx + 4) = iVar2;
      uVar5 = uVar3;
    }
    else {
      iVar2 = *(int *)(ctx + 4);
      uVar5 = uVar3 & 0xf;
      if (uVar5 == 0) {
        iVar2 = *(int *)(iVar2 + 0x144);
      }
      if (uVar5 == 0) {
        *(int *)(ctx + 4) = iVar2;
      }
    }
    *(uint *)(ctx + 0xc) = uVar3 + 1;
    a = (BIGNUM *)(iVar2 + uVar5 * 0x14);
    if (a == (BIGNUM *)0x0) {
LAB_0008aa52:
      *(undefined4 *)(ctx + 0x28) = 1;
      ERR_put_error(3,0x74,0x6d,"bn_ctx.c",0x12a);
      return (BIGNUM *)0x0;
    }
  }
  BN_set_word(a,0);
  *(int *)(ctx + 0x20) = *(int *)(ctx + 0x20) + 1;
  return a;
}

