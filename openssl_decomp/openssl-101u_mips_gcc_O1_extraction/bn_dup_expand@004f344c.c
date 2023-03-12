
BIGNUM * bn_dup_expand(BIGNUM *a,int words)

{
  ulong *puVar1;
  BIGNUM *a_00;
  int iVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  int iVar5;
  
  if (a->dmax < words) {
    puVar1 = (ulong *)bn_expand_internal();
    if (puVar1 == (ulong *)0x0) {
      a_00 = (BIGNUM *)0x0;
    }
    else {
      a_00 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"bn_lib.c",0x110);
      if (a_00 == (BIGNUM *)0x0) {
        (*(code *)PTR_ERR_put_error_006a7f34)(3,0x71,0x41,"bn_lib.c",0x111);
        (*(code *)PTR_CRYPTO_free_006a6e88)(puVar1);
      }
      else {
        a_00->top = 0;
        a_00->neg = 0;
        iVar5 = a->top;
        iVar2 = a->neg;
        a_00->flags = 1;
        a_00->dmax = words;
        a_00->top = iVar5;
        a_00->neg = iVar2;
        a_00->d = puVar1;
      }
    }
  }
  else {
    a_00 = (BIGNUM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"bn_lib.c",0x110);
    if (a_00 == (BIGNUM *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x71,0x41,"bn_lib.c",0x111);
    }
    else {
      a_00->top = 0;
      a_00->neg = 0;
      a_00->dmax = 0;
      a_00->d = (ulong *)0x0;
      a_00->flags = 1;
      pBVar3 = BN_copy(a_00,a);
      if (pBVar3 == (BIGNUM *)0x0) {
        uVar4 = a_00->flags;
        if ((a_00->d != (ulong *)0x0) && ((uVar4 & 2) == 0)) {
          (*(code *)PTR_CRYPTO_free_006a6e88)();
          uVar4 = a_00->flags;
        }
        if ((uVar4 & 1) == 0) {
          a_00->d = (ulong *)0x0;
          a_00->flags = uVar4 | 0x8000;
          a_00 = (BIGNUM *)0x0;
        }
        else {
          (*(code *)PTR_CRYPTO_free_006a6e88)(a_00);
          a_00 = (BIGNUM *)0x0;
        }
      }
    }
  }
  return a_00;
}

