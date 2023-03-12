
BIGNUM * BN_CTX_get(BN_CTX *ctx)

{
  BIGNUM *pBVar1;
  uint uVar2;
  ulong *puVar3;
  BIGNUM *a;
  BIGNUM *pBVar4;
  int iVar5;
  uint uVar6;
  
  if (*(int *)(ctx + 0x24) != 0) {
    return (BIGNUM *)0x0;
  }
  if (*(int *)(ctx + 0x28) != 0) {
    return (BIGNUM *)0x0;
  }
  uVar2 = *(uint *)(ctx + 0xc);
  if (uVar2 == *(uint *)(ctx + 0x10)) {
    a = (BIGNUM *)CRYPTO_malloc(0x148,"bn_ctx.c",0x199);
    if (a == (BIGNUM *)0x0) goto LAB_080f7aa1;
    pBVar4 = a;
    do {
      pBVar1 = pBVar4 + 1;
      BN_init(pBVar4);
      pBVar4 = pBVar1;
    } while (pBVar1 != a + 0x10);
    iVar5 = *(int *)ctx;
    puVar3 = *(ulong **)(ctx + 8);
    a[0x10].top = 0;
    a[0x10].d = puVar3;
    if (iVar5 == 0) {
      *(BIGNUM **)(ctx + 8) = a;
      *(BIGNUM **)(ctx + 4) = a;
      *(BIGNUM **)ctx = a;
    }
    else {
      puVar3[0x51] = (ulong)a;
      *(BIGNUM **)(ctx + 8) = a;
      *(BIGNUM **)(ctx + 4) = a;
    }
    *(int *)(ctx + 0x10) = *(int *)(ctx + 0x10) + 0x10;
    *(int *)(ctx + 0xc) = *(int *)(ctx + 0xc) + 1;
  }
  else {
    if (uVar2 == 0) {
      iVar5 = *(int *)ctx;
      uVar6 = 0;
      *(int *)(ctx + 4) = iVar5;
    }
    else {
      iVar5 = *(int *)(ctx + 4);
      uVar6 = uVar2 & 0xf;
      if (uVar6 == 0) {
        iVar5 = *(int *)(iVar5 + 0x144);
        *(int *)(ctx + 4) = iVar5;
      }
    }
    *(uint *)(ctx + 0xc) = uVar2 + 1;
    a = (BIGNUM *)(iVar5 + uVar6 * 0x14);
    if (a == (BIGNUM *)0x0) {
LAB_080f7aa1:
      *(undefined4 *)(ctx + 0x28) = 1;
      ERR_put_error(3,0x74,0x6d,"bn_ctx.c",0x12a);
      return (BIGNUM *)0x0;
    }
  }
  BN_set_word(a,0);
  *(int *)(ctx + 0x20) = *(int *)(ctx + 0x20) + 1;
  return a;
}

