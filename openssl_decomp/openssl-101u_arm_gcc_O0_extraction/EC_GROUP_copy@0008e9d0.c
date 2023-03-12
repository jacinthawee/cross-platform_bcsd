
int EC_GROUP_copy(EC_GROUP *dst,EC_GROUP *src)

{
  void **ptr;
  int iVar1;
  undefined4 *puVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
  int *piVar5;
  code *pcVar6;
  undefined4 uVar7;
  int iVar8;
  void *pvVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  
  if (*(int *)(*(int *)dst + 0x14) == 0) {
    ERR_put_error(0x10,0x6a,0x42,"ec_lib.c",0xa9);
    return 0;
  }
  if (*(int *)dst != *(int *)src) {
    ERR_put_error(0x10,0x6a,0x65,"ec_lib.c",0xad);
    return 0;
  }
  if (dst == src) {
    return 1;
  }
  if (dst != (EC_GROUP *)0xffffffbc) {
    ptr = (void **)*(void **)(dst + 0x44);
    while (ptr != (void **)0x0) {
      pvVar9 = *ptr;
      (*(code *)ptr[3])(ptr[1]);
      CRYPTO_free(ptr);
      ptr = (void **)pvVar9;
    }
    *(undefined4 *)(dst + 0x44) = 0;
  }
  for (piVar10 = *(int **)(src + 0x44); piVar10 != (int *)0x0; piVar10 = (int *)*piVar10) {
    iVar1 = (*(code *)piVar10[2])(piVar10[1]);
    if (iVar1 == 0) {
      return 0;
    }
    iVar8 = piVar10[2];
    iVar11 = piVar10[3];
    iVar12 = piVar10[4];
    if (dst == (EC_GROUP *)0xffffffbc) {
      return 0;
    }
    for (piVar5 = *(int **)(dst + 0x44); piVar5 != (int *)0x0; piVar5 = (int *)*piVar5) {
      if (((iVar8 == piVar5[2]) && (iVar11 == piVar5[3])) && (iVar12 == piVar5[4])) {
        ERR_put_error(0x10,0xd3,0x6c,"ec_lib.c",0x215);
        return 0;
      }
    }
    puVar2 = (undefined4 *)CRYPTO_malloc(0x14,"ec_lib.c",0x21e);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    puVar2[1] = iVar1;
    puVar2[2] = iVar8;
    puVar2[3] = iVar11;
    puVar2[4] = iVar12;
    *puVar2 = *(undefined4 *)(dst + 0x44);
    *(undefined4 **)(dst + 0x44) = puVar2;
  }
  piVar10 = *(int **)(src + 4);
  if (piVar10 == (int *)0x0) {
    piVar10 = *(int **)(dst + 4);
    if (piVar10 != (int *)0x0) {
      pcVar6 = *(code **)(*piVar10 + 0x30);
      if ((pcVar6 != (code *)0x0) || (pcVar6 = *(code **)(*piVar10 + 0x2c), pcVar6 != (code *)0x0))
      {
        (*pcVar6)(piVar10);
      }
      OPENSSL_cleanse(piVar10,0x44);
      CRYPTO_free(piVar10);
      *(undefined4 *)(dst + 4) = 0;
    }
  }
  else {
    piVar5 = *(int **)(dst + 4);
    if (piVar5 == (int *)0x0) {
      if (*(int *)(*(int *)dst + 0x28) == 0) {
        ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2a3);
LAB_0008ec1c:
        *(undefined4 *)(dst + 4) = 0;
        return 0;
      }
      piVar5 = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2a7);
      if (piVar5 == (int *)0x0) {
        ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2a9);
        goto LAB_0008ec1c;
      }
      iVar1 = *(int *)dst;
      *piVar5 = iVar1;
      iVar1 = (**(code **)(iVar1 + 0x28))();
      if (iVar1 == 0) {
        CRYPTO_free(piVar5);
        goto LAB_0008ec1c;
      }
      *(int **)(dst + 4) = piVar5;
      piVar10 = *(int **)(src + 4);
    }
    pcVar6 = *(code **)(*piVar5 + 0x34);
    if (pcVar6 == (code *)0x0) {
      ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2d1);
      return 0;
    }
    if (*piVar5 != *piVar10) {
      ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2d5);
      return 0;
    }
    if ((piVar10 != piVar5) && (iVar1 = (*pcVar6)(), iVar1 == 0)) {
      return 0;
    }
  }
  pBVar3 = BN_copy((BIGNUM *)(dst + 8),(BIGNUM *)(src + 8));
  if ((pBVar3 == (BIGNUM *)0x0) ||
     (pBVar3 = BN_copy((BIGNUM *)(dst + 0x1c),(BIGNUM *)(src + 0x1c)), pBVar3 == (BIGNUM *)0x0)) {
    return 0;
  }
  iVar1 = *(int *)(src + 0x3c);
  uVar4 = *(undefined4 *)(src + 0x34);
  uVar7 = *(undefined4 *)(src + 0x38);
  *(undefined4 *)(dst + 0x30) = *(undefined4 *)(src + 0x30);
  *(undefined4 *)(dst + 0x34) = uVar4;
  *(undefined4 *)(dst + 0x38) = uVar7;
  if (iVar1 == 0) {
    if (*(void **)(dst + 0x3c) != (void *)0x0) {
      CRYPTO_free(*(void **)(dst + 0x3c));
    }
    *(undefined4 *)(dst + 0x3c) = 0;
    *(undefined4 *)(dst + 0x40) = 0;
  }
  else {
    if (*(void **)(dst + 0x3c) != (void *)0x0) {
      CRYPTO_free(*(void **)(dst + 0x3c));
    }
    pvVar9 = CRYPTO_malloc(*(int *)(src + 0x40),"ec_lib.c",0xdc);
    *(void **)(dst + 0x3c) = pvVar9;
    if (pvVar9 == (void *)0x0) {
      return 0;
    }
    pvVar9 = memcpy(pvVar9,*(void **)(src + 0x3c),*(size_t *)(src + 0x40));
    if (pvVar9 == (void *)0x0) {
      return 0;
    }
    *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
  }
                    /* WARNING: Could not recover jumptable at 0x0008eb92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(*(int *)dst + 0x14))(dst,src);
  return iVar1;
}

