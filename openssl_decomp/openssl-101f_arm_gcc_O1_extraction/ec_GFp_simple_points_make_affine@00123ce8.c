
BIGNUM * ec_GFp_simple_points_make_affine(int *param_1,uint param_2,int param_3,BN_CTX *param_4)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *b;
  uint uVar3;
  int iVar4;
  BIGNUM *b_00;
  BIGNUM *b_01;
  int iVar5;
  ulong **ppuVar6;
  uint uVar7;
  uint uVar8;
  ulong **ppuVar9;
  BIGNUM *ptr;
  int *piVar10;
  uint local_44;
  BN_CTX *local_40;
  
  pBVar1 = (BIGNUM *)0x1;
  if (param_2 != 0) {
    if (param_4 == (BN_CTX *)0x0) {
      param_4 = BN_CTX_new();
      local_40 = param_4;
      if (param_4 == (BN_CTX *)0x0) {
        return (BIGNUM *)0x0;
      }
    }
    else {
      local_40 = (BN_CTX *)0x0;
    }
    BN_CTX_start(param_4);
    pBVar2 = BN_CTX_get(param_4);
    b = BN_CTX_get(param_4);
    if (pBVar2 == (BIGNUM *)0x0 || b == (BIGNUM *)0x0) {
      local_44 = 0;
      ptr = (BIGNUM *)0x0;
      pBVar1 = (BIGNUM *)0x0;
    }
    else {
      if (param_2 < 2) {
        iVar5 = 8;
        local_44 = 2;
      }
      else {
        uVar7 = 1;
        do {
          local_44 = uVar7;
          uVar7 = local_44 * 2;
        } while (local_44 * 2 < param_2);
        iVar5 = local_44 << 4;
        local_44 = local_44 << 2;
      }
      ptr = (BIGNUM *)CRYPTO_malloc(iVar5,"ecp_smpl.c",0x4c1);
      pBVar1 = ptr;
      if (ptr != (BIGNUM *)0x0) {
        uVar7 = local_44 >> 1;
        iVar5 = uVar7 - 1;
        ptr->d = (ulong *)0x0;
        if (iVar5 != 0) {
          memset(&ptr->top,0,(uVar7 + 0x3fffffff) * 4);
        }
        ppuVar9 = &ptr->d + uVar7;
        iVar4 = 0;
        do {
          *(int *)((int)ppuVar9 + iVar4) = *(int *)(param_3 + iVar4) + 0x2c;
          iVar4 = iVar4 + 4;
        } while (iVar4 != param_2 * 4);
        uVar8 = uVar7 + param_2;
        if (uVar8 < local_44) {
          memset(&ptr->d + uVar8,0,(local_44 - uVar8) * 4);
        }
        if (iVar5 != 0) {
          ppuVar6 = ppuVar9 + uVar7;
          do {
            pBVar1 = BN_new();
            ppuVar9 = ppuVar9 + -1;
            *ppuVar9 = (ulong *)pBVar1;
            if (pBVar1 == (BIGNUM *)0x0) goto LAB_00123d2c;
            b_00 = (BIGNUM *)ppuVar6[-2];
            if (b_00 != (BIGNUM *)0x0) {
              b_01 = (BIGNUM *)ppuVar6[-1];
              if ((b_01 == (BIGNUM *)0x0) || (b_01->top == 0)) {
                pBVar1 = BN_copy(pBVar1,b_00);
              }
              else {
                if (b_00->top != 0) {
                  pBVar1 = (BIGNUM *)
                           (**(code **)(*param_1 + 0x84))(param_1,pBVar1,b_00,b_01,param_4);
                  if (pBVar1 != (BIGNUM *)0x0) goto LAB_00123e04;
                  goto LAB_00123d2c;
                }
                pBVar1 = BN_copy(pBVar1,b_01);
              }
              if (pBVar1 == (BIGNUM *)0x0) goto LAB_00123d2c;
            }
LAB_00123e04:
            iVar5 = iVar5 + -1;
            ppuVar6 = ppuVar6 + -2;
          } while (iVar5 != 0);
        }
        pBVar1 = (BIGNUM *)ptr->top;
        if ((pBVar1->top == 0) ||
           (pBVar1 = BN_mod_inverse(pBVar1,pBVar1,(BIGNUM *)(param_1 + 0x12),param_4),
           pBVar1 != (BIGNUM *)0x0)) {
          if ((*(code **)(*param_1 + 0x90) == (code *)0x0) ||
             ((pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,ptr->top,ptr->top,param_4),
              pBVar1 != (BIGNUM *)0x0 &&
              (pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x90))(param_1,ptr->top,ptr->top,param_4),
              pBVar1 != (BIGNUM *)0x0)))) {
            if (2 < uVar8) {
              uVar7 = 2;
              do {
                uVar3 = uVar7 >> 1;
                iVar5 = (&ptr->top)[uVar7];
                if ((iVar5 == 0) || (*(int *)(iVar5 + 4) == 0)) {
                  pBVar1 = BN_copy((BIGNUM *)(&ptr->d)[uVar7],(BIGNUM *)(&ptr->d)[uVar3]);
                }
                else {
                  pBVar1 = (BIGNUM *)
                           (**(code **)(*param_1 + 0x84))
                                     (param_1,pBVar2,(&ptr->d)[uVar3],iVar5,param_4);
                  if (((pBVar1 == (BIGNUM *)0x0) ||
                      (pBVar1 = (BIGNUM *)
                                (**(code **)(*param_1 + 0x84))
                                          (param_1,b,(&ptr->d)[uVar3],(&ptr->d)[uVar7],param_4),
                      pBVar1 == (BIGNUM *)0x0)) ||
                     (pBVar1 = BN_copy((BIGNUM *)(&ptr->d)[uVar7],pBVar2), pBVar1 == (BIGNUM *)0x0))
                  goto LAB_00123d2c;
                  pBVar1 = BN_copy((BIGNUM *)(&ptr->top)[uVar7],b);
                }
                if (pBVar1 == (BIGNUM *)0x0) goto LAB_00123d2c;
                uVar7 = uVar7 + 2;
              } while (uVar7 < uVar8);
            }
            piVar10 = (int *)(param_3 + -4);
            uVar7 = 0;
            do {
              piVar10 = piVar10 + 1;
              iVar5 = *piVar10;
              if (*(int *)(iVar5 + 0x30) != 0) {
                pBVar2 = (BIGNUM *)(iVar5 + 0x2c);
                pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x88))(param_1,b,pBVar2,param_4);
                if ((pBVar1 == (BIGNUM *)0x0) ||
                   (pBVar1 = (BIGNUM *)
                             (**(code **)(*param_1 + 0x84))(param_1,iVar5 + 4,iVar5 + 4,b,param_4),
                   pBVar1 == (BIGNUM *)0x0)) goto LAB_00123d2c;
                pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x84))(param_1,b,b,pBVar2,param_4);
                if ((pBVar1 == (BIGNUM *)0x0) ||
                   (pBVar1 = (BIGNUM *)
                             (**(code **)(*param_1 + 0x84))
                                       (param_1,iVar5 + 0x18,iVar5 + 0x18,b,param_4),
                   pBVar1 == (BIGNUM *)0x0)) goto LAB_00123d2c;
                if (*(code **)(*param_1 + 0x98) == (code *)0x0) {
                  pBVar1 = (BIGNUM *)BN_set_word(pBVar2,1);
                }
                else {
                  pBVar1 = (BIGNUM *)(**(code **)(*param_1 + 0x98))(param_1,pBVar2,param_4);
                }
                if (pBVar1 == (BIGNUM *)0x0) goto LAB_00123d2c;
                *(undefined4 *)(iVar5 + 0x40) = 1;
              }
              uVar7 = uVar7 + 1;
            } while (uVar7 != param_2);
            pBVar1 = (BIGNUM *)0x1;
          }
        }
        else {
          ERR_put_error(0x10,0x89,3,"ecp_smpl.c",0x4fa);
        }
      }
    }
LAB_00123d2c:
    BN_CTX_end(param_4);
    if (local_40 != (BN_CTX *)0x0) {
      BN_CTX_free(local_40);
    }
    if (ptr != (BIGNUM *)0x0) {
      iVar5 = (local_44 >> 1) - 1;
      if (iVar5 != 0) {
        ppuVar9 = &ptr->d + (local_44 >> 1);
        do {
          ppuVar9 = ppuVar9 + -1;
          if ((BIGNUM *)*ppuVar9 != (BIGNUM *)0x0) {
            BN_clear_free((BIGNUM *)*ppuVar9);
          }
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      CRYPTO_free(ptr);
    }
  }
  return pBVar1;
}

