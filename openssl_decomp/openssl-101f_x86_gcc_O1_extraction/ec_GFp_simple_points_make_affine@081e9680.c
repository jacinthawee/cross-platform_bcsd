
undefined4 ec_GFp_simple_points_make_affine(int *param_1,uint param_2,int param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  undefined4 *ptr;
  uint uVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  BIGNUM **ppBVar11;
  BIGNUM *b;
  BN_CTX *local_30;
  BIGNUM *local_2c;
  BIGNUM *local_28;
  
  if (param_2 == 0) {
    return 1;
  }
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    if (param_4 == (BN_CTX *)0x0) {
      return 0;
    }
    BN_CTX_start(param_4);
    local_28 = BN_CTX_get(param_4);
    local_2c = BN_CTX_get(param_4);
    local_30 = param_4;
    if ((local_28 == (BIGNUM *)0x0) || (local_2c == (BIGNUM *)0x0)) {
      BN_CTX_end(param_4);
      goto LAB_081e983c;
    }
  }
  else {
    BN_CTX_start(param_4);
    local_28 = BN_CTX_get(param_4);
    local_2c = BN_CTX_get(param_4);
    if ((local_28 == (BIGNUM *)0x0) || (local_2c == (BIGNUM *)0x0)) {
      BN_CTX_end(param_4);
      return 0;
    }
    local_30 = (BN_CTX *)0x0;
  }
  if (param_2 < 2) {
    ptr = (undefined4 *)CRYPTO_malloc(8,"ecp_smpl.c",0x4c1);
    if (ptr != (undefined4 *)0x0) {
      *ptr = 0;
      uVar9 = 2;
      iVar6 = 0;
      uVar10 = 1;
      goto LAB_081e9756;
    }
  }
  else {
    uVar9 = 1;
    do {
      uVar10 = uVar9;
      uVar9 = uVar10 * 2;
    } while (uVar10 * 2 < param_2);
    uVar9 = uVar10 << 2;
    ptr = (undefined4 *)CRYPTO_malloc(uVar10 << 4,"ecp_smpl.c",0x4c1);
    if (ptr != (undefined4 *)0x0) {
      *ptr = 0;
      uVar10 = uVar9 >> 1;
      iVar6 = uVar10 - 1;
      if (iVar6 != 0) {
        memset(ptr + 1,0,uVar10 * 4 - 4);
      }
LAB_081e9756:
      uVar3 = 0;
      do {
        ptr[uVar10 + uVar3] = *(int *)(param_3 + uVar3 * 4) + 0x2c;
        uVar3 = uVar3 + 1;
      } while (param_2 != uVar3);
      uVar3 = param_2 + uVar10;
      if (uVar3 < uVar9) {
        memset(ptr + uVar3,0,(uVar9 - uVar3) * 4);
      }
      if (iVar6 != 0) {
        ppBVar11 = (BIGNUM **)(ptr + uVar10 * 2 + -2);
        iVar7 = iVar6;
        do {
          pBVar4 = BN_new();
          ptr[iVar7] = pBVar4;
          if (pBVar4 == (BIGNUM *)0x0) goto LAB_081e9884;
          pBVar1 = *ppBVar11;
          if (pBVar1 != (BIGNUM *)0x0) {
            pBVar2 = ppBVar11[1];
            b = pBVar1;
            if (((pBVar2 == (BIGNUM *)0x0) || (pBVar2->top == 0)) || (b = pBVar2, pBVar1->top == 0))
            {
              pBVar4 = BN_copy(pBVar4,b);
            }
            else {
              pBVar4 = (BIGNUM *)
                       (**(code **)(*param_1 + 0x84))(param_1,pBVar4,pBVar1,pBVar2,param_4);
            }
            if (pBVar4 == (BIGNUM *)0x0) goto LAB_081e9884;
          }
          ppBVar11 = ppBVar11 + -2;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      pBVar4 = (BIGNUM *)ptr[1];
      if ((pBVar4->top == 0) ||
         (pBVar4 = BN_mod_inverse(pBVar4,pBVar4,(BIGNUM *)(param_1 + 0x12),param_4),
         pBVar4 != (BIGNUM *)0x0)) {
        if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
           ((iVar7 = (**(code **)(*param_1 + 0x90))(param_1,ptr[1],ptr[1],param_4), iVar7 != 0 &&
            (iVar7 = (**(code **)(*param_1 + 0x90))(param_1,ptr[1],ptr[1],param_4), iVar7 != 0)))) {
          if (2 < uVar3) {
            uVar9 = 2;
            do {
              iVar7 = ptr[uVar9 + 1];
              if ((iVar7 == 0) || (*(int *)(iVar7 + 4) == 0)) {
                pBVar4 = BN_copy((BIGNUM *)ptr[uVar9],(BIGNUM *)ptr[uVar9 >> 1]);
              }
              else {
                iVar7 = (**(code **)(*param_1 + 0x84))
                                  (param_1,local_28,ptr[uVar9 >> 1],iVar7,param_4);
                if (((iVar7 == 0) ||
                    (iVar7 = (**(code **)(*param_1 + 0x84))
                                       (param_1,local_2c,ptr[uVar9 >> 1],ptr[uVar9],param_4),
                    iVar7 == 0)) ||
                   (pBVar4 = BN_copy((BIGNUM *)ptr[uVar9],local_28), pBVar4 == (BIGNUM *)0x0))
                goto LAB_081e9884;
                pBVar4 = BN_copy((BIGNUM *)ptr[uVar9 + 1],local_2c);
              }
              if (pBVar4 == (BIGNUM *)0x0) goto LAB_081e9884;
              uVar9 = uVar9 + 2;
            } while (uVar9 < uVar3);
          }
          uVar9 = 0;
          do {
            iVar7 = *(int *)(param_3 + uVar9 * 4);
            if (*(int *)(iVar7 + 0x30) != 0) {
              pBVar4 = (BIGNUM *)(iVar7 + 0x2c);
              iVar5 = (**(code **)(*param_1 + 0x88))(param_1,local_2c,pBVar4,param_4);
              if (((iVar5 == 0) ||
                  (iVar5 = (**(code **)(*param_1 + 0x84))
                                     (param_1,iVar7 + 4,iVar7 + 4,local_2c,param_4), iVar5 == 0)) ||
                 ((iVar5 = (**(code **)(*param_1 + 0x84))(param_1,local_2c,local_2c,pBVar4,param_4),
                  iVar5 == 0 ||
                  (iVar5 = (**(code **)(*param_1 + 0x84))
                                     (param_1,iVar7 + 0x18,iVar7 + 0x18,local_2c,param_4),
                  iVar5 == 0)))) goto LAB_081e9884;
              if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
                iVar5 = BN_set_word(pBVar4,1);
              }
              else {
                iVar5 = (**(code **)(*param_1 + 0x98))(param_1,pBVar4,param_4);
              }
              if (iVar5 == 0) goto LAB_081e9884;
              *(undefined4 *)(iVar7 + 0x40) = 1;
            }
            uVar9 = uVar9 + 1;
          } while (param_2 != uVar9);
          uVar8 = 1;
        }
        else {
LAB_081e9884:
          uVar8 = 0;
        }
      }
      else {
        uVar8 = 0;
        ERR_put_error(0x10,0x89,3,"ecp_smpl.c",0x4fa);
      }
      BN_CTX_end(param_4);
      if (local_30 != (BN_CTX *)0x0) {
        BN_CTX_free(local_30);
      }
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        if ((BIGNUM *)ptr[iVar6] != (BIGNUM *)0x0) {
          BN_clear_free((BIGNUM *)ptr[iVar6]);
        }
      }
      CRYPTO_free(ptr);
      return uVar8;
    }
  }
  BN_CTX_end(param_4);
  if (local_30 == (BN_CTX *)0x0) {
    return 0;
  }
LAB_081e983c:
  BN_CTX_free(local_30);
  return 0;
}

