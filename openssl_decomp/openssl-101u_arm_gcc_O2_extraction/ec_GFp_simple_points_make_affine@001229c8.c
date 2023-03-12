
BIGNUM * ec_GFp_simple_points_make_affine(int *param_1,uint param_2,int *param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM **ptr;
  uint uVar3;
  int *piVar4;
  BIGNUM **ppBVar5;
  BIGNUM *pBVar6;
  BIGNUM **ppBVar7;
  int iVar8;
  BN_CTX *local_38;
  
  if (param_2 == 0) {
    return (BIGNUM *)0x1;
  }
  if (param_4 == (BN_CTX *)0x0) {
    param_4 = BN_CTX_new();
    local_38 = param_4;
    if (param_4 == (BN_CTX *)0x0) {
      return (BIGNUM *)0x0;
    }
  }
  else {
    local_38 = (BN_CTX *)0x0;
  }
  BN_CTX_start(param_4);
  pBVar1 = BN_CTX_get(param_4);
  pBVar2 = BN_CTX_get(param_4);
  uVar3 = (uint)(pBVar1 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0);
  if ((pBVar1 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0) ||
     (ptr = (BIGNUM **)CRYPTO_malloc(param_2 * 4,"ecp_smpl.c",0x4f9), ptr == (BIGNUM **)0x0)) {
    pBVar6 = (BIGNUM *)0x0;
    ptr = (BIGNUM **)0x0;
  }
  else {
    ppBVar5 = ptr + -1;
    do {
      pBVar6 = BN_new();
      uVar3 = uVar3 + 1;
      ppBVar5 = ppBVar5 + 1;
      *ppBVar5 = pBVar6;
      if (pBVar6 == (BIGNUM *)0x0) goto LAB_00122a0e;
    } while (uVar3 != param_2);
    if (*(int *)(*param_3 + 0x30) == 0) {
      if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
        pBVar6 = (BIGNUM *)BN_set_word(*ptr,1);
      }
      else {
        pBVar6 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,*ptr,param_4);
      }
    }
    else {
      pBVar6 = BN_copy(*ptr,(BIGNUM *)(*param_3 + 0x2c));
    }
    if (pBVar6 != (BIGNUM *)0x0) {
      if (param_2 != 1) {
        uVar3 = 1;
        ppBVar7 = ptr;
        piVar4 = param_3;
        ppBVar5 = ptr;
        do {
          piVar4 = piVar4 + 1;
          uVar3 = uVar3 + 1;
          if (*(int *)(*piVar4 + 0x30) == 0) {
            pBVar6 = BN_copy(ppBVar7[1],*ppBVar5);
          }
          else {
            pBVar6 = (BIGNUM *)
                     (**(code **)(*param_1 + 0x84))
                               (param_1,ppBVar7[1],*ppBVar5,*piVar4 + 0x2c,param_4);
          }
          if (pBVar6 == (BIGNUM *)0x0) goto LAB_00122a0e;
          ppBVar7 = ppBVar7 + 1;
          ppBVar5 = ppBVar5 + 1;
        } while (uVar3 != param_2);
      }
      ppBVar5 = ptr + param_2;
      pBVar6 = BN_mod_inverse(pBVar1,ppBVar5[-1],(BIGNUM *)(param_1 + 0x12),param_4);
      if (pBVar6 == (BIGNUM *)0x0) {
        ERR_put_error(0x10,0x89,3,"ecp_smpl.c",0x525);
      }
      else if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
              ((pBVar6 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_4),
               pBVar6 != (BIGNUM *)0x0 &&
               (pBVar6 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,pBVar1,pBVar1,param_4),
               pBVar6 != (BIGNUM *)0x0)))) {
        iVar8 = param_2 - 1;
        if (iVar8 != 0) {
          piVar4 = param_3 + param_2;
          do {
            if ((*(int *)(piVar4[-1] + 0x30) != 0) &&
               (((pBVar6 = (BIGNUM *)
                           (**(code **)(*param_1 + 0x84))(param_1,pBVar2,ppBVar5[-2],pBVar1,param_4)
                 , pBVar6 == (BIGNUM *)0x0 ||
                 (pBVar6 = (BIGNUM *)
                           (**(code **)(*param_1 + 0x84))
                                     (param_1,pBVar1,pBVar1,piVar4[-1] + 0x2c,param_4),
                 pBVar6 == (BIGNUM *)0x0)) ||
                (pBVar6 = BN_copy((BIGNUM *)(piVar4[-1] + 0x2c),pBVar2), pBVar6 == (BIGNUM *)0x0))))
            goto LAB_00122a0e;
            iVar8 = iVar8 + -1;
            piVar4 = piVar4 + -1;
            ppBVar5 = ppBVar5 + -1;
          } while (iVar8 != 0);
        }
        if ((*(int *)(*param_3 + 0x30) == 0) ||
           (pBVar6 = BN_copy((BIGNUM *)(*param_3 + 0x2c),pBVar1), pBVar6 != (BIGNUM *)0x0)) {
          uVar3 = 0;
          param_3 = param_3 + -1;
          do {
            param_3 = param_3 + 1;
            iVar8 = *param_3;
            if (*(int *)(iVar8 + 0x30) != 0) {
              pBVar2 = (BIGNUM *)(iVar8 + 0x2c);
              pBVar6 = (BIGNUM *)(**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar2,param_4);
              if ((pBVar6 == (BIGNUM *)0x0) ||
                 (pBVar6 = (BIGNUM *)
                           (**(code **)(*param_1 + 0x84))
                                     (param_1,iVar8 + 4,iVar8 + 4,pBVar1,param_4),
                 pBVar6 == (BIGNUM *)0x0)) goto LAB_00122a0e;
              pBVar6 = (BIGNUM *)
                       (**(code **)(*param_1 + 0x84))(param_1,pBVar1,pBVar1,pBVar2,param_4);
              if ((pBVar6 == (BIGNUM *)0x0) ||
                 (pBVar6 = (BIGNUM *)
                           (**(code **)(*param_1 + 0x84))
                                     (param_1,iVar8 + 0x18,iVar8 + 0x18,pBVar1,param_4),
                 pBVar6 == (BIGNUM *)0x0)) goto LAB_00122a0e;
              if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
                pBVar6 = (BIGNUM *)BN_set_word(pBVar2,1);
              }
              else {
                pBVar6 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,pBVar2,param_4);
              }
              if (pBVar6 == (BIGNUM *)0x0) goto LAB_00122a0e;
              *(undefined4 *)(iVar8 + 0x40) = 1;
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 != param_2);
          pBVar6 = (BIGNUM *)0x1;
        }
      }
    }
  }
LAB_00122a0e:
  BN_CTX_end(param_4);
  if (local_38 != (BN_CTX *)0x0) {
    BN_CTX_free(local_38);
  }
  if (ptr != (BIGNUM **)0x0) {
    pBVar1 = *ptr;
    if (pBVar1 != (BIGNUM *)0x0) {
      uVar3 = 0;
      ppBVar5 = ptr;
      do {
        uVar3 = uVar3 + 1;
        BN_clear_free(pBVar1);
        if (uVar3 == param_2) break;
        ppBVar5 = ppBVar5 + 1;
        pBVar1 = *ppBVar5;
      } while (pBVar1 != (BIGNUM *)0x0);
    }
    CRYPTO_free(ptr);
  }
  return pBVar6;
}

