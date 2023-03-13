
int EC_GROUP_copy(EC_GROUP *dst,EC_GROUP *src)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  BIGNUM *pBVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  
  if (*(int *)(*(int *)dst + 0x14) == 0) {
    uVar5 = 0x42;
    uVar1 = 0xa9;
  }
  else {
    if (*(int *)dst == *(int *)src) {
      if (dst == src) {
        return 1;
      }
      if (dst != (EC_GROUP *)0xffffffbc) {
        piVar8 = (int *)*(int *)(dst + 0x44);
        while (piVar8 != (int *)0x0) {
          iVar7 = *piVar8;
          (*(code *)piVar8[3])(piVar8[1]);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar8);
          piVar8 = (int *)iVar7;
        }
        *(undefined4 *)(dst + 0x44) = 0;
      }
      for (piVar8 = *(int **)(src + 0x44); piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
        iVar7 = (*(code *)piVar8[2])(piVar8[1]);
        if (iVar7 == 0) {
          return 0;
        }
        iVar6 = piVar8[2];
        iVar9 = piVar8[3];
        iVar11 = piVar8[4];
        if (dst == (EC_GROUP *)0xffffffbc) {
          return 0;
        }
        for (piVar2 = *(int **)(dst + 0x44); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          if (((iVar6 == piVar2[2]) && (iVar9 == piVar2[3])) && (iVar11 == piVar2[4])) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xd3,0x6c,"ec_lib.c",0x215);
            return 0;
          }
        }
        puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"ec_lib.c",0x21e);
        if (puVar3 == (undefined4 *)0x0) {
          return 0;
        }
        puVar3[1] = iVar7;
        puVar3[2] = iVar6;
        puVar3[3] = iVar9;
        puVar3[4] = iVar11;
        *puVar3 = *(undefined4 *)(dst + 0x44);
        *(undefined4 **)(dst + 0x44) = puVar3;
      }
      piVar8 = *(int **)(src + 4);
      if (piVar8 == (int *)0x0) {
        piVar8 = *(int **)(dst + 4);
        if (piVar8 != (int *)0x0) {
          pcVar10 = *(code **)(*piVar8 + 0x30);
          if ((pcVar10 != (code *)0x0) ||
             (pcVar10 = *(code **)(*piVar8 + 0x2c), pcVar10 != (code *)0x0)) {
            (*pcVar10)(piVar8);
          }
          (*(code *)PTR_OPENSSL_cleanse_006a7074)(piVar8,0x44);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar8);
          *(undefined4 *)(dst + 4) = 0;
        }
LAB_005011bc:
        pBVar4 = BN_copy((BIGNUM *)(dst + 8),(BIGNUM *)(src + 8));
        if (pBVar4 == (BIGNUM *)0x0) {
          return 0;
        }
        pBVar4 = BN_copy((BIGNUM *)(dst + 0x1c),(BIGNUM *)(src + 0x1c));
        if (pBVar4 == (BIGNUM *)0x0) {
          return 0;
        }
        uVar5 = *(undefined4 *)(src + 0x30);
        uVar1 = *(undefined4 *)(src + 0x38);
        iVar7 = *(int *)(src + 0x3c);
        *(undefined4 *)(dst + 0x34) = *(undefined4 *)(src + 0x34);
        *(undefined4 *)(dst + 0x30) = uVar5;
        *(undefined4 *)(dst + 0x38) = uVar1;
        if (iVar7 == 0) {
          if (*(int *)(dst + 0x3c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          *(undefined4 *)(dst + 0x3c) = 0;
          *(undefined4 *)(dst + 0x40) = 0;
        }
        else {
          if (*(int *)(dst + 0x3c) != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          iVar7 = (*(code *)PTR_CRYPTO_malloc_006a7008)(*(undefined4 *)(src + 0x40),"ec_lib.c",0xdc)
          ;
          *(int *)(dst + 0x3c) = iVar7;
          if (iVar7 == 0) {
            return 0;
          }
          iVar7 = (*(code *)PTR_memcpy_006a9aec)
                            (iVar7,*(undefined4 *)(src + 0x3c),*(undefined4 *)(src + 0x40));
          if (iVar7 == 0) {
            return 0;
          }
          *(undefined4 *)(dst + 0x40) = *(undefined4 *)(src + 0x40);
        }
                    /* WARNING: Could not recover jumptable at 0x005012a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar7 = (**(code **)(*(int *)dst + 0x14))(dst,src);
        return iVar7;
      }
      piVar2 = *(int **)(dst + 4);
      if (piVar2 == (int *)0x0) {
        if (*(int *)(*(int *)dst + 0x28) == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x79,0x42,"ec_lib.c",0x2a3);
LAB_0050139c:
          *(undefined4 *)(dst + 4) = 0;
          return 0;
        }
        piVar2 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x44,"ec_lib.c",0x2a7);
        if (piVar2 == (int *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x79,0x41,"ec_lib.c",0x2a9);
          goto LAB_0050139c;
        }
        pcVar10 = *(code **)(*(int *)dst + 0x28);
        *piVar2 = *(int *)dst;
        iVar7 = (*pcVar10)(piVar2);
        if (iVar7 == 0) {
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar2);
          goto LAB_0050139c;
        }
        *(int **)(dst + 4) = piVar2;
        piVar8 = *(int **)(src + 4);
      }
      pcVar10 = *(code **)(*piVar2 + 0x34);
      if (pcVar10 == (code *)0x0) {
        uVar5 = 0x42;
        uVar1 = 0x2d1;
      }
      else {
        uVar5 = 0x65;
        if (*piVar2 == *piVar8) {
          if ((piVar8 != piVar2) && (iVar7 = (*pcVar10)(piVar2,piVar8,0x65), iVar7 == 0)) {
            return 0;
          }
          goto LAB_005011bc;
        }
        uVar1 = 0x2d5;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x72,uVar5,"ec_lib.c",uVar1);
      return 0;
    }
    uVar5 = 0x65;
    uVar1 = 0xad;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0x6a,uVar5,"ec_lib.c",uVar1);
  return 0;
}

