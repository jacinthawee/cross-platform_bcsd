
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
LAB_0062392c:
    (*(code *)PTR_ERR_put_error_006a9030)(3,0x79,0x70,"bn_sqrt.c",0x5e);
    return (BIGNUM *)0x0;
  }
  uVar13 = *n->d;
  if ((uVar13 & 1) != 0) {
    if ((iVar3 == 1) && (uVar13 == 1)) goto LAB_0062392c;
    if (a->top == 0) {
      if (ret != (BIGNUM *)0x0) {
        iVar3 = (*(code *)PTR_BN_set_word_006a8820)(ret,0);
        if (iVar3 == 0) {
          return (BIGNUM *)0x0;
        }
        return ret;
      }
LAB_00623b18:
      pBVar11 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
      if (pBVar11 == (BIGNUM *)0x0) goto LAB_00623998;
      uVar4 = 0;
      if (((a->top != 1) || (*a->d != 1)) || (a->neg != 0)) goto LAB_00623aec;
    }
    else {
      if (((a->top != 1) || (*a->d != 1)) || (a->neg != 0)) {
        (*(code *)PTR_BN_CTX_start_006a9644)(ctx);
        uVar4 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
        ppiVar5 = (int **)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
        pBVar11 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
        ppiVar6 = (int **)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
        iVar3 = (*(code *)PTR_BN_CTX_get_006a9648)(ctx);
        a_00 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a9648)(ctx);
        if ((a_00 != (BIGNUM *)0x0) &&
           ((pBVar8 = ret, ret != (BIGNUM *)0x0 ||
            (pBVar8 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)(), pBVar8 != (BIGNUM *)0x0)))) {
          iVar7 = (*(code *)PTR_BN_nnmod_006a9664)(uVar4,a,n,ctx);
          if (iVar7 != 0) {
            iVar7 = 1;
            while (iVar9 = (*(code *)PTR_BN_is_bit_set_006a9650)(n,iVar7), iVar9 == 0) {
              iVar7 = iVar7 + 1;
            }
            if (iVar7 == 1) {
              iVar7 = (*(code *)PTR_BN_rshift_006a96f8)(pBVar11,n,2);
              puVar1 = PTR_BN_add_word_006a81bc;
              if (iVar7 != 0) {
                pBVar11->neg = 0;
                iVar7 = (*(code *)puVar1)(pBVar11,1);
                if (iVar7 != 0) {
                  iVar7 = (*(code *)PTR_BN_mod_exp_006a8a48)(pBVar8,uVar4,pBVar11,n,ctx);
joined_r0x00623d34:
                  if ((iVar7 != 0) &&
                     (iVar7 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(iVar3,pBVar8,n,ctx), iVar7 != 0)) {
                    iVar3 = (*(code *)PTR_BN_cmp_006a8a4c)(iVar3,uVar4);
                    if (iVar3 == 0) goto LAB_00623890;
                    uVar14 = 0x6f;
                    uVar4 = 0x178;
                    goto LAB_00623cc8;
                  }
                }
              }
            }
            else if (iVar7 == 2) {
              iVar7 = (*(code *)PTR_BN_mod_lshift1_quick_006aa7f4)(ppiVar6,uVar4,n);
              if ((iVar7 != 0) &&
                 (iVar7 = (*(code *)PTR_BN_rshift_006a96f8)(pBVar11,n,3),
                 puVar1 = PTR_BN_mod_exp_006a8a48, iVar7 != 0)) {
                pBVar11->neg = 0;
                iVar7 = (*(code *)puVar1)(ppiVar5,ppiVar6,pBVar11,n,ctx);
                if (((iVar7 != 0) &&
                    (((iVar7 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(a_00,ppiVar5,n,ctx), iVar7 != 0 &&
                      (iVar7 = (*(code *)PTR_BN_mod_mul_006a9698)(ppiVar6,ppiVar6,a_00,n,ctx),
                      iVar7 != 0)) &&
                     (iVar7 = (*(code *)PTR_BN_sub_word_006a95bc)(ppiVar6,1), iVar7 != 0)))) &&
                   ((iVar7 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar3,uVar4,ppiVar5,n,ctx),
                    iVar7 != 0 &&
                    (iVar7 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar3,iVar3,ppiVar6,n,ctx),
                    iVar7 != 0)))) {
LAB_00623c6c:
                  iVar7 = (*(code *)PTR_BN_copy_006a9570)(pBVar8,iVar3);
                  goto joined_r0x00623d34;
                }
              }
            }
            else {
              iVar9 = (*(code *)PTR_BN_copy_006a9570)(pBVar11,n);
              puVar1 = PTR_BN_sub_006a96cc;
              if (iVar9 != 0) {
                iVar9 = 2;
                pBVar11->neg = 0;
                puVar2 = PTR_BN_add_006a96c8;
                do {
                  if (iVar9 < 0x16) {
LAB_00623a5c:
                    iVar10 = (*(code *)PTR_BN_set_word_006a8820)(a_00,iVar9);
                    if (iVar10 == 0) goto LAB_00623878;
                  }
                  else {
                    uVar14 = (*(code *)PTR_BN_num_bits_006a82f4)(n);
                    iVar10 = (*(code *)PTR_BN_pseudo_rand_006a8cd8)(a_00,uVar14,0,0);
                    if (iVar10 == 0) goto LAB_00623878;
                    iVar10 = (*(code *)PTR_BN_ucmp_006a9678)(a_00,n);
                    if (-1 < iVar10) {
                      pcVar12 = (code *)puVar2;
                      if (n->neg == 0) {
                        pcVar12 = (code *)puVar1;
                      }
                      iVar10 = (*pcVar12)(a_00,a_00,n);
                      if (iVar10 == 0) goto LAB_00623878;
                    }
                    if (a_00->top == 0) goto LAB_00623a5c;
                  }
                  iVar10 = BN_kronecker(a_00,pBVar11,ctx);
                  if (iVar10 < -1) goto LAB_00623878;
                  if (iVar10 == 0) {
                    uVar14 = 0x70;
                    uVar4 = 0xec;
                    goto LAB_00623cc8;
                  }
                  if (iVar10 != 1) {
                    if (iVar10 == -1) {
                      iVar9 = (*(code *)PTR_BN_rshift_006a96f8)(pBVar11,pBVar11,iVar7);
                      if ((iVar9 == 0) ||
                         (iVar9 = (*(code *)PTR_BN_mod_exp_006a8a48)(a_00,a_00,pBVar11,n,ctx),
                         iVar9 == 0)) goto LAB_00623878;
                      if ((a_00->top == 1) && ((*a_00->d == 1 && (a_00->neg == 0)))) {
                        uVar14 = 0x70;
                        uVar4 = 0x105;
                        goto LAB_00623cc8;
                      }
                      iVar9 = (*(code *)PTR_BN_rshift1_006a8a44)(ppiVar6,pBVar11);
                      if (iVar9 == 0) goto LAB_00623878;
                      if (ppiVar6[1] == (int *)0x0) {
                        iVar9 = (*(code *)PTR_BN_nnmod_006a9664)(ppiVar6,uVar4,n,ctx);
                        if (iVar9 == 0) goto LAB_00623878;
                        if (ppiVar6[1] == (int *)0x0) {
LAB_00623f6c:
                          (*(code *)PTR_BN_set_word_006a8820)(pBVar8,0);
                          goto LAB_00623890;
                        }
                        iVar9 = (*(code *)PTR_BN_set_word_006a8820)(iVar3,1);
                        if (iVar9 == 0) goto LAB_00623878;
                      }
                      else {
                        iVar9 = (*(code *)PTR_BN_mod_exp_006a8a48)(iVar3,uVar4,ppiVar6,n,ctx);
                        if (iVar9 == 0) goto LAB_00623878;
                        if (*(int *)(iVar3 + 4) == 0) goto LAB_00623f6c;
                      }
                      iVar9 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(ppiVar5,iVar3,n,ctx);
                      if ((iVar9 == 0) ||
                         (iVar9 = (*(code *)PTR_BN_mod_mul_006a9698)(ppiVar5,ppiVar5,uVar4,n,ctx),
                         iVar9 == 0)) goto LAB_00623878;
                      iVar9 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar3,iVar3,uVar4,n,ctx);
                      goto joined_r0x00623ea0;
                    }
                    break;
                  }
                  iVar9 = iVar9 + 1;
                } while (iVar9 != 0x52);
                uVar14 = 0x71;
                uVar4 = 0xf9;
LAB_00623cc8:
                (*(code *)PTR_ERR_put_error_006a9030)(3,0x79,uVar14,"bn_sqrt.c",uVar4);
              }
            }
          }
LAB_00623878:
          if (ret != pBVar8) {
            (*(code *)PTR_BN_clear_free_006a9130)(pBVar8);
            pBVar8 = (BIGNUM *)0x0;
            goto LAB_00623890;
          }
        }
        goto LAB_00623998;
      }
      pBVar11 = ret;
      if (ret == (BIGNUM *)0x0) goto LAB_00623b18;
    }
    uVar4 = 1;
LAB_00623aec:
    iVar3 = (*(code *)PTR_BN_set_word_006a8820)(pBVar11,uVar4);
    if (iVar3 != 0) {
      return pBVar11;
    }
    if (ret == pBVar11) {
      return (BIGNUM *)0x0;
    }
    (*(code *)PTR_BN_free_006a811c)(pBVar11);
    return (BIGNUM *)0x0;
  }
  if ((iVar3 != 1) || (uVar13 != 2)) goto LAB_0062392c;
  if (ret != (BIGNUM *)0x0) {
    uVar4 = (*(code *)PTR_BN_is_bit_set_006a9650)(a,0);
    iVar3 = (*(code *)PTR_BN_set_word_006a8820)(ret,uVar4);
    if (iVar3 == 0) {
      return (BIGNUM *)0x0;
    }
    return ret;
  }
  pBVar11 = (BIGNUM *)(*(code *)PTR_BN_new_006a82b4)();
  if (pBVar11 != (BIGNUM *)0x0) {
    uVar4 = (*(code *)PTR_BN_is_bit_set_006a9650)(a,0);
    iVar3 = (*(code *)PTR_BN_set_word_006a8820)(pBVar11,uVar4);
    if (iVar3 != 0) {
      return pBVar11;
    }
    (*(code *)PTR_BN_free_006a811c)(pBVar11);
    return (BIGNUM *)0x0;
  }
LAB_00623998:
  pBVar8 = (BIGNUM *)0x0;
LAB_00623890:
  (*(code *)PTR_BN_CTX_end_006a9654)(ctx);
  return pBVar8;
joined_r0x00623ea0:
  if (iVar9 == 0) goto LAB_00623878;
  if (((ppiVar5[1] == (int *)0x1) && (**ppiVar5 == 1)) && (ppiVar5[3] == (int *)0x0))
  goto LAB_00623c6c;
  iVar9 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(ppiVar6,ppiVar5,n,ctx);
  if (iVar9 == 0) goto LAB_00623878;
  iVar10 = 1;
  while (((ppiVar6[1] != (int *)0x1 || (**ppiVar6 != 1)) || (ppiVar6[3] != (int *)0x0))) {
    iVar10 = iVar10 + 1;
    if (iVar7 == iVar10) {
      uVar14 = 0x6f;
      uVar4 = 0x15a;
      goto LAB_00623cc8;
    }
    iVar9 = (*(code *)PTR_BN_mod_mul_006a9698)(ppiVar6,ppiVar6,ppiVar6,n,ctx);
    if (iVar9 == 0) goto LAB_00623878;
  }
  iVar9 = (*(code *)PTR_BN_copy_006a9570)(ppiVar6,a_00,ppiVar6,n);
  if (iVar9 == 0) goto LAB_00623878;
  iVar7 = iVar7 - iVar10;
  while (iVar7 = iVar7 + -1, 0 < iVar7) {
    iVar9 = (*(code *)PTR_BN_mod_sqr_006aa7f0)(ppiVar6,ppiVar6,n,ctx);
    if (iVar9 == 0) goto LAB_00623878;
  }
  iVar7 = (*(code *)PTR_BN_mod_mul_006a9698)(a_00,ppiVar6,ppiVar6,n,ctx);
  if ((iVar7 == 0) ||
     (iVar7 = (*(code *)PTR_BN_mod_mul_006a9698)(iVar3,iVar3,ppiVar6,n,ctx), iVar7 == 0))
  goto LAB_00623878;
  iVar9 = (*(code *)PTR_BN_mod_mul_006a9698)(ppiVar5,ppiVar5,a_00,n,ctx);
  iVar7 = iVar10;
  goto joined_r0x00623ea0;
}

