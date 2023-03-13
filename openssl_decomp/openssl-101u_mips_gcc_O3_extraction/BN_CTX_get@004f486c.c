
BIGNUM * BN_CTX_get(BN_CTX *ctx)

{
  undefined *puVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  uint uVar5;
  BIGNUM *pBVar6;
  BIGNUM *a;
  BIGNUM *pBVar7;
  
  if ((*(int *)(ctx + 0x24) != 0) || (*(int *)(ctx + 0x28) != 0)) {
    return (BIGNUM *)0x0;
  }
  uVar4 = *(uint *)(ctx + 0xc);
  if (uVar4 == *(uint *)(ctx + 0x10)) {
    a = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x148,"bn_ctx.c",0x197);
    if (a == (BIGNUM *)0x0) goto LAB_004f49f0;
    pBVar6 = a;
    do {
      pBVar7 = pBVar6 + 1;
      BN_init(pBVar6);
      pBVar6 = pBVar7;
    } while (pBVar7 != a + 0x10);
    puVar3 = *(ulong **)(ctx + 8);
    iVar2 = *(int *)ctx;
    a[0x10].top = 0;
    a[0x10].d = puVar3;
    if (iVar2 == 0) {
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
    if (uVar4 == 0) {
      iVar2 = *(int *)ctx;
      uVar5 = 0;
      *(int *)(ctx + 4) = iVar2;
    }
    else {
      uVar5 = uVar4 & 0xf;
      iVar2 = *(int *)(ctx + 4);
      if (uVar5 == 0) {
        iVar2 = *(int *)(iVar2 + 0x144);
        *(int *)(ctx + 4) = iVar2;
      }
    }
    a = (BIGNUM *)(iVar2 + uVar5 * 0x14);
    *(uint *)(ctx + 0xc) = uVar4 + 1;
    if (a == (BIGNUM *)0x0) {
LAB_004f49f0:
      puVar1 = PTR_ERR_put_error_006a7f34;
      *(undefined4 *)(ctx + 0x28) = 1;
      (*(code *)puVar1)(3,0x74,0x6d,"bn_ctx.c",0x129);
      return (BIGNUM *)0x0;
    }
  }
  BN_set_word(a,0);
  *(int *)(ctx + 0x20) = *(int *)(ctx + 0x20) + 1;
  return a;
}

