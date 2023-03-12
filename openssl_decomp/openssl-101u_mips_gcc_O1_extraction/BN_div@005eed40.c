
/* WARNING: Removing unreachable block (ram,0x005ef534) */

int BN_div(BIGNUM *dv,BIGNUM *rem,BIGNUM *m,BIGNUM *d,BN_CTX *ctx)

{
  ulonglong uVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  BIGNUM **ppBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  uint uVar8;
  undefined4 uVar9;
  BIGNUM *pBVar10;
  BIGNUM *pBVar11;
  BIGNUM *pBVar12;
  int iVar13;
  int *piVar14;
  int iVar15;
  uint extraout_v1;
  uint uVar16;
  uint uVar17;
  BIGNUM *pBVar18;
  BIGNUM *pBVar19;
  ulong *puVar20;
  uint uVar21;
  ulong uVar22;
  uint uVar23;
  uint uVar24;
  ulong *puVar25;
  int local_6c;
  uint *local_68;
  int local_60;
  BIGNUM *local_40;
  BIGNUM *local_3c;
  int local_38;
  undefined4 local_34;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((m->top < 1) || (m->d[m->top + -1] != 0)) &&
     ((iVar4 = d->top, iVar4 < 1 || (d->d[iVar4 + -1] != 0)))) {
    pBVar19 = m;
    if (((m->flags & 4U) == 0) && (uVar8 = d->flags & 4, uVar8 == 0)) {
      if (iVar4 == 0) {
LAB_005eef54:
        pBVar19 = (BIGNUM *)0x67;
        uVar9 = 0xe5;
        goto LAB_005eeec4;
      }
      pBVar18 = d;
      iVar4 = (*(code *)PTR_BN_ucmp_006a7fb4)(m);
      if (-1 < iVar4) {
        local_6c = 0;
        goto LAB_005eedf8;
      }
      if ((rem == (BIGNUM *)0x0) ||
         (iVar4 = (*(code *)PTR_BN_copy_006a8450)(rem), pBVar18 = m, iVar4 != 0)) {
        if (dv == (BIGNUM *)0x0) {
LAB_005ef2e8:
          uVar8 = 1;
          m = pBVar18;
        }
        else {
          m = (BIGNUM *)0x0;
          uVar8 = 1;
          (*(code *)PTR_BN_set_word_006a7730)(dv);
        }
      }
    }
    else {
      if (iVar4 == 0) goto LAB_005eef54;
      local_6c = 1;
      pBVar18 = rem;
LAB_005eedf8:
      (*(code *)PTR_BN_CTX_start_006a8528)(ctx);
      ppBVar5 = (BIGNUM **)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      pBVar6 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      pBVar7 = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx);
      pBVar10 = pBVar7;
      if ((((dv != (BIGNUM *)0x0) ||
           (dv = (BIGNUM *)(*(code *)PTR_BN_CTX_get_006a852c)(ctx), pBVar10 = dv,
           pBVar7 != (BIGNUM *)0x0)) && (pBVar10 != (BIGNUM *)0x0)) &&
         ((ppBVar5 != (BIGNUM **)0x0 && (pBVar6 != (BIGNUM *)0x0)))) {
        uVar8 = (*(code *)PTR_BN_num_bits_006a71f4)(d);
        uVar8 = uVar8 & 0x8000001f;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xffffffe0) + 1;
        }
        pBVar19 = (BIGNUM *)(0x20 - uVar8);
        pBVar18 = d;
        iVar4 = (*(code *)PTR_BN_lshift_006a8498)(pBVar7);
        puVar3 = PTR_BN_lshift_006a8498;
        if (iVar4 != 0) {
          pBVar7->neg = 0;
          pBVar10 = (BIGNUM *)(0x40 - uVar8);
          pBVar18 = m;
          pBVar19 = pBVar10;
          iVar4 = (*(code *)puVar3)(pBVar6);
          if (iVar4 != 0) {
            pBVar6->neg = 0;
            pBVar19 = pBVar6;
            if (local_6c == 0) {
              iVar15 = pBVar6->top;
              puVar20 = pBVar6->d;
            }
            else {
              iVar4 = pBVar6->top;
              iVar15 = pBVar7->top + 1;
              if (iVar15 < iVar4) {
                if (pBVar6->dmax <= iVar4) {
                  pBVar18 = (BIGNUM *)(iVar4 + 1);
                  iVar4 = (*(code *)PTR_bn_expand2_006a8524)(pBVar6);
                  if (iVar4 == 0) goto LAB_005eeea0;
                  iVar4 = pBVar6->top;
                }
                puVar20 = pBVar6->d;
                puVar20[iVar4] = 0;
                iVar15 = pBVar6->top + 1;
                pBVar6->top = iVar15;
              }
              else {
                if (iVar15 < pBVar6->dmax) {
LAB_005ef3a4:
                  puVar20 = pBVar6->d;
                  puVar25 = puVar20 + iVar4;
                  do {
                    *puVar25 = 0;
                    iVar4 = iVar4 + 1;
                    iVar15 = pBVar7->top;
                    puVar25 = puVar25 + 1;
                  } while (iVar4 <= iVar15 + 1);
                }
                else {
                  pBVar18 = (BIGNUM *)(pBVar7->top + 2);
                  iVar4 = (*(code *)PTR_bn_expand2_006a8524)(pBVar6);
                  if (iVar4 == 0) goto LAB_005eeea0;
                  iVar15 = pBVar7->top;
                  iVar4 = pBVar6->top;
                  if (iVar4 <= iVar15 + 1) goto LAB_005ef3a4;
                  puVar20 = pBVar6->d;
                }
                iVar15 = iVar15 + 2;
                pBVar6->top = iVar15;
              }
            }
            pBVar11 = (BIGNUM *)pBVar7->top;
            local_34 = 0;
            iVar4 = iVar15 - (int)pBVar11;
            local_40 = (BIGNUM *)(puVar20 + iVar4);
            local_38 = pBVar6->dmax - iVar4;
            uVar8 = pBVar7->d[(int)((int)&pBVar11[-1].flags + 3)];
            if (pBVar11 == (BIGNUM *)0x1) {
              uVar24 = 0;
            }
            else {
              uVar24 = (pBVar7->d + (int)((int)&pBVar11[-1].flags + 3))[-1];
            }
            puVar20 = pBVar6->d;
            dv->neg = m->neg ^ d->neg;
            pBVar19 = pBVar6;
            local_3c = pBVar11;
            if (dv->dmax <= iVar4) {
              pBVar18 = (BIGNUM *)(iVar4 + 1);
              iVar13 = (*(code *)PTR_bn_expand2_006a8524)(dv);
              if (iVar13 == 0) goto LAB_005eeea0;
            }
            pBVar12 = ppBVar5[2];
            puVar25 = dv->d;
            dv->top = iVar4 - local_6c;
            pBVar18 = pBVar11;
            if ((int)pBVar12 <= (int)pBVar11) {
              pBVar18 = (BIGNUM *)((int)&pBVar11->d + 1);
              iVar13 = (*(code *)PTR_bn_expand2_006a8524)(ppBVar5);
              if (iVar13 == 0) goto LAB_005eeea0;
            }
            local_68 = puVar25 + iVar4 + -1;
            if (local_6c == 0) {
              pBVar18 = pBVar7;
              iVar13 = (*(code *)PTR_BN_ucmp_006a7fb4)(&local_40);
              if (iVar13 < 0) {
                iVar13 = dv->top + -1;
                dv->top = iVar13;
              }
              else {
                pBVar19 = (BIGNUM *)pBVar7->d;
                pBVar18 = local_40;
                (*(code *)PTR_bn_sub_words_006a8580)(local_40,local_40,pBVar19,pBVar11);
                *local_68 = 1;
                iVar13 = dv->top;
              }
            }
            else {
              iVar13 = dv->top;
            }
            if (iVar13 == 0) {
              dv->neg = 0;
            }
            else {
              local_68 = local_68 + -1;
            }
            if (1 < iVar4) {
              local_60 = 0;
              puVar20 = puVar20 + iVar15 + -1;
              do {
                if (uVar8 == *puVar20) {
                  uVar23 = 0xffffffff;
                }
                else {
                  uVar22 = puVar20[-1];
                  (*(code *)PTR___udivdi3_006a85e8)(*puVar20,uVar22,0,uVar8);
                  uVar1 = (ulonglong)extraout_v1 * (ulonglong)uVar24;
                  uVar16 = uVar22 - uVar8 * extraout_v1;
                  uVar23 = extraout_v1;
                  if (CONCAT44(uVar16,puVar20[-2]) < uVar1) {
                    while( true ) {
                      uVar16 = uVar8 + uVar16;
                      uVar23 = uVar23 - 1;
                      if (uVar16 < uVar8) break;
                      uVar21 = (uint)uVar1 - uVar24;
                      uVar17 = (int)(uVar1 >> 0x20) - (uint)((uint)uVar1 < uVar21);
                      uVar1 = CONCAT44(uVar17,uVar21);
                      if ((uVar17 <= uVar16) && ((uVar16 != uVar17 || (uVar21 <= puVar20[-2]))))
                      break;
                    }
                  }
                }
                puVar25 = (ulong *)(*(code *)PTR_bn_mul_words_006a8588)
                                             (*ppBVar5,pBVar7->d,pBVar11,uVar23);
                puVar3 = PTR_bn_sub_words_006a8580;
                pBVar18 = (BIGNUM *)&local_40[-1].flags;
                (&(*ppBVar5)->d)[(int)pBVar11] = puVar25;
                pBVar19 = *ppBVar5;
                local_40 = pBVar18;
                iVar15 = (*(code *)puVar3)(pBVar18,pBVar18,pBVar19,
                                           (undefined *)((int)&pBVar11->d + 1));
                if (iVar15 != 0) {
                  uVar23 = uVar23 - 1;
                  pBVar19 = (BIGNUM *)pBVar7->d;
                  pBVar18 = local_40;
                  iVar15 = (*(code *)PTR_bn_add_words_006a8584)(local_40,local_40,pBVar19,pBVar11);
                  if (iVar15 != 0) {
                    *puVar20 = *puVar20 + 1;
                  }
                }
                *local_68 = uVar23;
                local_68 = local_68 + -1;
                local_60 = local_60 + 1;
                puVar20 = puVar20 + -1;
              } while (local_60 != iVar4 + -1);
            }
            iVar4 = pBVar6->top;
            if (0 < iVar4) {
              puVar20 = pBVar6->d + iVar4 + -2;
              do {
                if (puVar20[1] != 0) break;
                iVar4 = iVar4 + -1;
                puVar20 = puVar20 + -1;
              } while (iVar4 != 0);
              pBVar6->top = iVar4;
            }
            if (rem != (BIGNUM *)0x0) {
              iVar4 = m->neg;
              (*(code *)PTR_BN_rshift_006a85d4)(rem);
              pBVar18 = pBVar6;
              pBVar19 = pBVar10;
              if (rem->top != 0) {
                rem->neg = iVar4;
              }
            }
            if ((local_6c != 0) && (iVar4 = dv->top, 0 < iVar4)) {
              puVar20 = dv->d + iVar4 + -1;
              do {
                iVar15 = iVar4 + -1;
                if (*puVar20 != 0) break;
                puVar20 = puVar20 + -1;
                iVar4 = iVar15;
              } while (iVar15 != 0);
              dv->top = iVar4;
            }
            (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
            goto LAB_005ef2e8;
          }
        }
      }
LAB_005eeea0:
      uVar8 = 0;
      (*(code *)PTR_BN_CTX_end_006a8530)(ctx);
      m = pBVar18;
    }
  }
  else {
    pBVar19 = (BIGNUM *)&DAT_0000006b;
    uVar9 = 0xcf;
LAB_005eeec4:
    m = (BIGNUM *)&DAT_0000006b;
    uVar8 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x6b,pBVar19,"bn_div.c",uVar9);
  }
  if (local_2c == *(int *)puVar2) {
    return uVar8;
  }
  iVar4 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  piVar14 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2c,"bn_blind.c",0x8d);
  if (piVar14 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x66,0x41,"bn_blind.c",0x8e);
    return 0;
  }
  (*(code *)PTR_memset_006a99f4)(piVar14,0,0x2c);
  if (iVar4 != 0) {
    iVar4 = (*(code *)PTR_BN_dup_006a8218)(iVar4);
    *piVar14 = iVar4;
    if (iVar4 == 0) goto LAB_005ef71c;
  }
  if (m == (BIGNUM *)0x0) {
LAB_005ef698:
    iVar4 = (*(code *)PTR_BN_dup_006a8218)(pBVar19);
    piVar14[3] = iVar4;
    if (iVar4 != 0) {
      if ((pBVar19->flags & 4U) != 0) {
        *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) | 4;
      }
      puVar2 = PTR_CRYPTO_THREADID_current_006a848c;
      piVar14[7] = -1;
      (*(code *)puVar2)(piVar14 + 5);
      return (int)piVar14;
    }
  }
  else {
    iVar4 = (*(code *)PTR_BN_dup_006a8218)(m);
    piVar14[1] = iVar4;
    if (iVar4 != 0) goto LAB_005ef698;
  }
  if (*piVar14 != 0) {
    (*(code *)PTR_BN_free_006a701c)(*piVar14);
  }
LAB_005ef71c:
  if (piVar14[1] != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (piVar14[2] != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  if (piVar14[3] != 0) {
    (*(code *)PTR_BN_free_006a701c)();
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar14);
  return 0;
}

