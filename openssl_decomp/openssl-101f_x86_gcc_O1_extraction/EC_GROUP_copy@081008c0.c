
int EC_GROUP_copy(EC_GROUP *dst,EC_GROUP *src)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  BIGNUM *pBVar7;
  void *pvVar8;
  int *ptr;
  int iVar9;
  int iVar10;
  
  if (*(int *)(*(int *)dst + 0x14) == 0) {
    iVar10 = 0xb1;
    iVar9 = 0x42;
  }
  else {
    if (*(int *)dst == *(int *)src) {
      if (dst == src) {
        return 1;
      }
      if (dst != (EC_GROUP *)0xffffffbc) {
        puVar1 = *(undefined4 **)(dst + 0x44);
        while (puVar1 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar1;
          (*(code *)puVar1[3])(puVar1[1]);
          CRYPTO_free(puVar1);
          puVar1 = puVar5;
        }
        *(undefined4 *)(dst + 0x44) = 0;
      }
      for (puVar1 = *(undefined4 **)(src + 0x44); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        iVar9 = (*(code *)puVar1[2])(puVar1[1]);
        if (iVar9 == 0) {
          return 0;
        }
        iVar10 = puVar1[4];
        iVar2 = puVar1[3];
        iVar3 = puVar1[2];
        if (dst == (EC_GROUP *)0xffffffbc) {
          return 0;
        }
        for (puVar5 = *(undefined4 **)(dst + 0x44); puVar5 != (undefined4 *)0x0;
            puVar5 = (undefined4 *)*puVar5) {
          if (((iVar3 == puVar5[2]) && (iVar2 == puVar5[3])) && (iVar10 == puVar5[4])) {
            ERR_put_error(0x10,0xd3,0x6c,"ec_lib.c",0x231);
            return 0;
          }
        }
        puVar5 = (undefined4 *)CRYPTO_malloc(0x14,"ec_lib.c",0x23a);
        if (puVar5 == (undefined4 *)0x0) {
          return 0;
        }
        puVar5[2] = iVar3;
        puVar5[3] = iVar2;
        puVar5[1] = iVar9;
        puVar5[4] = iVar10;
        *puVar5 = *(undefined4 *)(dst + 0x44);
        *(undefined4 **)(dst + 0x44) = puVar5;
      }
      piVar6 = *(int **)(src + 4);
      if (piVar6 == (int *)0x0) {
        piVar6 = *(int **)(dst + 4);
        if (piVar6 != (int *)0x0) {
          pcVar4 = *(code **)(*piVar6 + 0x30);
          if (pcVar4 == (code *)0x0) {
            pcVar4 = *(code **)(*piVar6 + 0x2c);
            if (pcVar4 != (code *)0x0) {
              (*pcVar4)(piVar6);
            }
          }
          else {
            (*pcVar4)(piVar6);
          }
          OPENSSL_cleanse(piVar6,0x44);
          CRYPTO_free(piVar6);
          *(undefined4 *)(dst + 4) = 0;
        }
      }
      else {
        ptr = *(int **)(dst + 4);
        if (ptr == (int *)0x0) {
          if (*(int *)(*(int *)dst + 0x28) == 0) {
            ERR_put_error(0x10,0x79,0x42,"ec_lib.c",0x2c0);
LAB_08100c61:
            *(undefined4 *)(dst + 4) = 0;
            return 0;
          }
          ptr = (int *)CRYPTO_malloc(0x44,"ec_lib.c",0x2c4);
          if (ptr == (int *)0x0) {
            ERR_put_error(0x10,0x79,0x41,"ec_lib.c",0x2c7);
            goto LAB_08100c61;
          }
          iVar9 = *(int *)dst;
          *ptr = iVar9;
          iVar9 = (**(code **)(iVar9 + 0x28))(ptr);
          if (iVar9 == 0) {
            CRYPTO_free(ptr);
            goto LAB_08100c61;
          }
          *(int **)(dst + 4) = ptr;
          piVar6 = *(int **)(src + 4);
        }
        pcVar4 = *(code **)(*ptr + 0x34);
        if (pcVar4 == (code *)0x0) {
          ERR_put_error(0x10,0x72,0x42,"ec_lib.c",0x2f2);
          return 0;
        }
        if (*ptr != *piVar6) {
          ERR_put_error(0x10,0x72,0x65,"ec_lib.c",0x2f7);
          return 0;
        }
        if ((ptr != piVar6) && (iVar9 = (*pcVar4)(ptr,piVar6), iVar9 == 0)) {
          return 0;
        }
      }
      pBVar7 = BN_copy((BIGNUM *)(dst + 8),(BIGNUM *)(src + 8));
      if ((pBVar7 == (BIGNUM *)0x0) ||
         (pBVar7 = BN_copy((BIGNUM *)(dst + 0x1c),(BIGNUM *)(src + 0x1c)), pBVar7 == (BIGNUM *)0x0))
      {
        return 0;
      }
      *(undefined4 *)(dst + 0x30) = *(undefined4 *)(src + 0x30);
      *(undefined4 *)(dst + 0x34) = *(undefined4 *)(src + 0x34);
      *(undefined4 *)(dst + 0x38) = *(undefined4 *)(src + 0x38);
      pvVar8 = *(void **)(dst + 0x3c);
      if (*(int *)(src + 0x3c) == 0) {
        if (pvVar8 != (void *)0x0) {
          CRYPTO_free(pvVar8);
        }
        *(undefined4 *)(dst + 0x3c) = 0;
        *(undefined4 *)(dst + 0x40) = 0;
      }
      else {
        if (pvVar8 != (void *)0x0) {
          CRYPTO_free(pvVar8);
        }
        pvVar8 = CRYPTO_malloc(*(int *)(src + 0x40),"ec_lib.c",0xe6);
        *(void **)(dst + 0x3c) = pvVar8;
        if (pvVar8 == (void *)0x0) {
          return 0;
        }
        pvVar8 = memcpy(pvVar8,*(void **)(src + 0x3c),*(size_t *)(src + 0x40));
        if (pvVar8 == (void *)0x0) {
          return 0;
        }
        *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
      }
                    /* WARNING: Could not recover jumptable at 0x08100b76. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar9 = (**(code **)(*(int *)dst + 0x14))();
      return iVar9;
    }
    iVar10 = 0xb6;
    iVar9 = 0x65;
  }
  ERR_put_error(0x10,0x6a,iVar9,"ec_lib.c",iVar10);
  return 0;
}

