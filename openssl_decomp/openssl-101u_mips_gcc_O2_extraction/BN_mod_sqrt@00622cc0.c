
BIGNUM * BN_mod_sqrt(BIGNUM *ret,BIGNUM *a,BIGNUM *n,BN_CTX *ctx)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  int **ppiVar5;
  int **ppiVar6;
  BIGNUM *a_00;
  int iVar7;
  BIGNUM *pBVar8;
  int iVar9;
  int iVar10;
  BIGNUM *pBVar11;
  code *pcVar12;
  uint uVar13;
  undefined4 uVar14;
  
  iVar3 = n->top;
  if (iVar3 < 1) {
LAB_00622f2c:
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x79,0x70,"bn_sqrt.c",0x5b);
    return (BIGNUM *)0x0;
  }
  uVar13 = *n->d;
  if ((uVar13 & 1) != 0) {
    if ((iVar3 == 1) && (uVar13 == 1)) goto LAB_00622f2c;
    if (a->top == 0) {
      if (ret != (BIGNUM *)0x0) {
        iVar3 = (*(code *)PTR_BN_set_word_006a7730)(ret,0);
        if (iVar3 == 0) {
          return (BIGNUM *)0x0;
        }
        return ret;
      }
LAB_00623118:
      pBVar11 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
      if (pBVar11 == (BIGNUM *)0x0) goto LAB_00622f98;
      uVar4 = 0;
      if (((a->top != 1) || (*a->d != 1)) || (a->neg != 0)) goto LAB_006230ec;
    }
    else {
      if (((a->top != 1) || (*a->d != 1)) || (a->neg != 0)) {
        (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
        uVar4 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
        ppiVar5 = (int **)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
        pBVar11 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
        ppiVar6 = (int **)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
        iVar3 = (*(code *)PTR_BN_CTX_get_006a852c)(ctx);
        a_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
        if ((a_00 != (BIGNUM *)0x0) &&
           ((pBVar8 = ret, ret != (BIGNUM *)0x0 ||
            (pBVar8 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)(), pBVar8 != (BIGNUM *)0x0)))) {
          iVar7 = (*(code *)PTR_BN_nnmod_006a8548)(uVar4,a,n,ctx);
          if (iVar7 != 0) {
            iVar7 = 1;
            while (iVar9 = (*(code *)PTR_BN_is_bit_set_006a8538)(n,iVar7), iVar9 == 0) {
              iVar7 = iVar7 + 1;
            }
            if (iVar7 == 1) {
              iVar7 = (*(code *)PTR_BN_rshift_006a85d4)(pBVar11,n,2);
              puVar1 = PTR_BN_add_word_006a70bc;
              if (iVar7 != 0) {
                pBVar11->neg = 0;
                iVar7 = (*(code *)puVar1)(pBVar11,1);
                if (iVar7 != 0) {
                  iVar7 = (*(code *)PTR_BN_mod_exp_006a795c)(pBVar8,uVar4,pBVar11,n,ctx);
joined_r0x00623334:
                  if ((iVar7 != 0) &&
                     (iVar7 = (*(code *)PTR_BN_mod_sqr_006a96e8)(iVar3,pBVar8,n,ctx), iVar7 != 0)) {
                    iVar3 = (*(code *)PTR_BN_cmp_006a7960)(iVar3,uVar4);
                    if (iVar3 == 0) goto LAB_00622e90;
                    uVar14 = 0x6f;
                    uVar4 = 0x18a;
                    goto LAB_006232c8;
                  }
                }
              }
            }
            else if (iVar7 == 2) {
              iVar7 = (*(code *)PTR_BN_mod_lshift1_quick_006a96ec)(ppiVar6,uVar4,n);
              if ((iVar7 != 0) &&
                 (iVar7 = (*(code *)PTR_BN_rshift_006a85d4)(pBVar11,n,3),
                 puVar1 = PTR_BN_mod_exp_006a795c, iVar7 != 0)) {
                pBVar11->neg = 0;
                iVar7 = (*(code *)puVar1)(ppiVar5,ppiVar6,pBVar11,n,ctx);
                if (((iVar7 != 0) &&
                    (((iVar7 = (*(code *)PTR_BN_mod_sqr_006a96e8)(a_00,ppiVar5,n,ctx), iVar7 != 0 &&
                      (iVar7 = (*(code *)PTR_BN_mod_mul_006a8574)(ppiVar6,ppiVar6,a_00,n,ctx),
                      iVar7 != 0)) &&
                     (iVar7 = (*(code *)PTR_BN_sub_word_006a849c)(ppiVar6,1), iVar7 != 0)))) &&
                   ((iVar7 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar3,uVar4,ppiVar5,n,ctx),
                    iVar7 != 0 &&
                    (iVar7 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar3,iVar3,ppiVar6,n,ctx),
                    iVar7 != 0)))) {
LAB_0062326c:
                  iVar7 = (*(code *)PTR_BN_copy_006a8450)(pBVar8,iVar3);
                  goto joined_r0x00623334;
                }
              }
            }
            else {
              iVar9 = (*(code *)PTR_BN_copy_006a8450)(pBVar11,n);
              puVar1 = PTR_BN_sub_006a85a8;
              if (iVar9 != 0) {
                iVar9 = 2;
                pBVar11->neg = 0;
                puVar2 = PTR_BN_add_006a85a4;
                do {
                  if (iVar9 < 0x16) {
LAB_0062305c:
                    iVar10 = (*(code *)PTR_BN_set_word_006a7730)(a_00,iVar9);
                    if (iVar10 == 0) goto LAB_00622e78;
                  }
                  else {
                    uVar14 = (*(code *)PTR_BN_num_bits_006a71f4)(n);
                    iVar10 = (*(code *)PTR_BN_pseudo_rand_006a7bec)(a_00,uVar14,0,0);
                    if (iVar10 == 0) goto LAB_00622e78;
                    iVar10 = (*(code *)PTR_BN_ucmp_006a7fb4)(a_00,n);
                    if (-1 < iVar10) {
                      pcVar12 = (code *)puVar2;
                      if (n->neg == 0) {
                        pcVar12 = (code *)puVar1;
                      }
                      iVar10 = (*pcVar12)(a_00,a_00,n);
                      if (iVar10 == 0) goto LAB_00622e78;
                    }
                    if (a_00->top == 0) goto LAB_0062305c;
                  }
                  iVar10 = BN_kronecker(a_00,pBVar11,ctx);
                  if (iVar10 < -1) goto LAB_00622e78;
                  if (iVar10 == 0) {
                    uVar14 = 0x70;
                    uVar4 = 0xf9;
                    goto LAB_006232c8;
                  }
                  if (iVar10 != 1) {
                    if (iVar10 == -1) {
                      iVar9 = (*(code *)PTR_BN_rshift_006a85d4)(pBVar11,pBVar11,iVar7);
                      if ((iVar9 == 0) ||
                         (iVar9 = (*(code *)PTR_BN_mod_exp_006a795c)(a_00,a_00,pBVar11,n,ctx),
                         iVar9 == 0)) goto LAB_00622e78;
                      if ((a_00->top == 1) && ((*a_00->d == 1 && (a_00->neg == 0)))) {
                        uVar14 = 0x70;
                        uVar4 = 0x114;
                        goto LAB_006232c8;
                      }
                      iVar9 = (*(code *)PTR_BN_rshift1_006a7958)(ppiVar6,pBVar11);
                      if (iVar9 == 0) goto LAB_00622e78;
                      if (ppiVar6[1] == (int *)0x0) {
                        iVar9 = (*(code *)PTR_BN_nnmod_006a8548)(ppiVar6,uVar4,n,ctx);
                        if (iVar9 == 0) goto LAB_00622e78;
                        if (ppiVar6[1] == (int *)0x0) {
LAB_0062356c:
                          (*(code *)PTR_BN_set_word_006a7730)(pBVar8,0);
                          goto LAB_00622e90;
                        }
                        iVar9 = (*(code *)PTR_BN_set_word_006a7730)(iVar3,1);
                        if (iVar9 == 0) goto LAB_00622e78;
                      }
                      else {
                        iVar9 = (*(code *)PTR_BN_mod_exp_006a795c)(iVar3,uVar4,ppiVar6,n,ctx);
                        if (iVar9 == 0) goto LAB_00622e78;
                        if (*(int *)(iVar3 + 4) == 0) goto LAB_0062356c;
                      }
                      iVar9 = (*(code *)PTR_BN_mod_sqr_006a96e8)(ppiVar5,iVar3,n,ctx);
                      if ((iVar9 == 0) ||
                         (iVar9 = (*(code *)PTR_BN_mod_mul_006a8574)(ppiVar5,ppiVar5,uVar4,n,ctx),
                         iVar9 == 0)) goto LAB_00622e78;
                      iVar9 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar3,iVar3,uVar4,n,ctx);
                      goto joined_r0x006234a0;
                    }
                    break;
                  }
                  iVar9 = iVar9 + 1;
                } while (iVar9 != 0x52);
                uVar14 = 0x71;
                uVar4 = 0x105;
LAB_006232c8:
                (*(code *)PTR_ERR_put_error_006a7f34)(3,0x79,uVar14,"bn_sqrt.c",uVar4);
              }
            }
          }
LAB_00622e78:
          if (ret != pBVar8) {
            (*(code *)PTR_BN_clear_free_006a7fa8)(pBVar8);
            pBVar8 = (BIGNUM *)0x0;
            goto LAB_00622e90;
          }
        }
        goto LAB_00622f98;
      }
      pBVar11 = ret;
      if (ret == (BIGNUM *)0x0) goto LAB_00623118;
    }
    uVar4 = 1;
LAB_006230ec:
    iVar3 = (*(code *)PTR_BN_set_word_006a7730)(pBVar11,uVar4);
    if (iVar3 != 0) {
      return pBVar11;
    }
    if (ret == pBVar11) {
      return (BIGNUM *)0x0;
    }
    (*(code *)PTR_BN_free_006a701c)(pBVar11);
    return (BIGNUM *)0x0;
  }
  if ((iVar3 != 1) || (uVar13 != 2)) goto LAB_00622f2c;
  if (ret != (BIGNUM *)0x0) {
    uVar4 = (*(code *)PTR_BN_is_bit_set_006a8538)(a,0);
    iVar3 = (*(code *)PTR_BN_set_word_006a7730)(ret,uVar4);
    if (iVar3 == 0) {
      return (BIGNUM *)0x0;
    }
    return ret;
  }
  pBVar11 = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
  if (pBVar11 != (BIGNUM *)0x0) {
    uVar4 = (*(code *)PTR_BN_is_bit_set_006a8538)(a,0);
    iVar3 = (*(code *)PTR_BN_set_word_006a7730)(pBVar11,uVar4);
    if (iVar3 != 0) {
      return pBVar11;
    }
    (*(code *)PTR_BN_free_006a701c)(pBVar11);
    return (BIGNUM *)0x0;
  }
LAB_00622f98:
  pBVar8 = (BIGNUM *)0x0;
LAB_00622e90:
  (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
  return pBVar8;
joined_r0x006234a0:
  if (iVar9 == 0) goto LAB_00622e78;
  if (((ppiVar5[1] == (int *)0x1) && (**ppiVar5 == 1)) && (ppiVar5[3] == (int *)0x0))
  goto LAB_0062326c;
  iVar9 = (*(code *)PTR_BN_mod_sqr_006a96e8)(ppiVar6,ppiVar5,n,ctx);
  if (iVar9 == 0) goto LAB_00622e78;
  iVar10 = 1;
  while (((ppiVar6[1] != (int *)0x1 || (**ppiVar6 != 1)) || (ppiVar6[3] != (int *)0x0))) {
    iVar10 = iVar10 + 1;
    if (iVar7 == iVar10) {
      uVar14 = 0x6f;
      uVar4 = 0x168;
      goto LAB_006232c8;
    }
    iVar9 = (*(code *)PTR_BN_mod_mul_006a8574)(ppiVar6,ppiVar6,ppiVar6,n,ctx);
    if (iVar9 == 0) goto LAB_00622e78;
  }
  iVar9 = (*(code *)PTR_BN_copy_006a8450)(ppiVar6,a_00,ppiVar6,n);
  if (iVar9 == 0) goto LAB_00622e78;
  iVar7 = iVar7 - iVar10;
  while (iVar7 = iVar7 + -1, 0 < iVar7) {
    iVar9 = (*(code *)PTR_BN_mod_sqr_006a96e8)(ppiVar6,ppiVar6,n,ctx);
    if (iVar9 == 0) goto LAB_00622e78;
  }
  iVar7 = (*(code *)PTR_BN_mod_mul_006a8574)(a_00,ppiVar6,ppiVar6,n,ctx);
  if ((iVar7 == 0) ||
     (iVar7 = (*(code *)PTR_BN_mod_mul_006a8574)(iVar3,iVar3,ppiVar6,n,ctx), iVar7 == 0))
  goto LAB_00622e78;
  iVar9 = (*(code *)PTR_BN_mod_mul_006a8574)(ppiVar5,ppiVar5,a_00,n,ctx);
  iVar7 = iVar10;
  goto joined_r0x006234a0;
}

