
int BN_nist_mod_521(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  ulong uVar5;
  ulong *puVar6;
  ulong *puVar7;
  uint uVar8;
  ulong *puVar9;
  ulong *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint local_70 [4];
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  uVar8 = a->neg;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (uVar8 == 0) {
    iVar11 = a->top;
    puVar10 = a->d;
    iVar4 = (*(code *)PTR_BN_ucmp_006a9678)(a,_bignum_nist_p_521_sqr_6238);
    if (iVar4 < 0) {
      iVar4 = (*(code *)PTR_BN_ucmp_006a9678)(_bignum_nist_p_521,a);
      if (iVar4 == 0) {
        uVar8 = 1;
        (*(code *)PTR_BN_set_word_006a8820)(r,0);
        goto LAB_0062d320;
      }
      if (0 < iVar4) {
        if (a == r) {
          uVar8 = 1;
        }
        else {
          iVar4 = (*(code *)PTR_BN_copy_006a9570)(r,a);
          uVar8 = (uint)(iVar4 != 0);
        }
        goto LAB_0062d320;
      }
      puVar7 = puVar10;
      if (a != r) {
        if (r->dmax < 0x11) {
          iVar4 = (*(code *)PTR_bn_expand2_006a9680)(r,0x11);
          if (iVar4 == 0) goto LAB_0062d320;
          uVar5 = *puVar10;
        }
        else {
          uVar5 = *puVar10;
        }
        puVar7 = r->d;
        *puVar7 = uVar5;
        puVar7[1] = puVar10[1];
        puVar7[2] = puVar10[2];
        puVar7[3] = puVar10[3];
        puVar7[4] = puVar10[4];
        puVar7[5] = puVar10[5];
        puVar7[6] = puVar10[6];
        puVar7[7] = puVar10[7];
        puVar7[8] = puVar10[8];
        puVar7[9] = puVar10[9];
        puVar7[10] = puVar10[10];
        puVar7[0xb] = puVar10[0xb];
        puVar7[0xc] = puVar10[0xc];
        puVar7[0xd] = puVar10[0xd];
        puVar7[0xe] = puVar10[0xe];
        puVar7[0xf] = puVar10[0xf];
        puVar7[0x10] = puVar10[0x10];
      }
      puVar9 = puVar10 + 0x10;
      if (iVar11 < 0x11) {
        iVar11 = 0;
        bVar1 = true;
LAB_0062d488:
        iVar4 = 4;
        if (bVar1) {
          iVar4 = iVar11 * -4 + 0x44;
        }
        (*(code *)PTR_memset_006aab00)(local_70 + iVar11,0,iVar4);
      }
      else {
        puVar6 = local_70;
        do {
          uVar5 = *puVar9;
          puVar9 = puVar9 + 1;
          *puVar6 = uVar5;
          puVar6 = puVar6 + 1;
        } while (puVar9 != puVar10 + iVar11);
        iVar11 = iVar11 + -0x10;
        bVar1 = iVar11 < 0x11;
        if (bVar1) goto LAB_0062d488;
      }
      puVar2 = PTR_bn_add_words_006a96a8;
      uVar8 = local_70[1] << 0x17;
      local_70[1] = local_70[1] >> 9 | local_70[2] << 0x17;
      local_70[2] = local_70[2] >> 9 | local_70[3] << 0x17;
      uVar12 = local_38 << 0x17;
      uVar13 = local_3c << 0x17;
      local_70[3] = local_70[3] >> 9 | local_60 << 0x17;
      local_70[0] = local_70[0] >> 9 | uVar8;
      local_38 = local_38 >> 9 | local_34 << 0x17;
      uVar8 = local_30 << 0x17;
      local_30 = local_30 >> 9;
      local_34 = local_34 >> 9 | uVar8;
      local_60 = local_60 >> 9 | local_5c << 0x17;
      local_3c = local_3c >> 9 | uVar12;
      local_5c = local_5c >> 9 | local_58 << 0x17;
      local_58 = local_58 >> 9 | local_54 << 0x17;
      local_54 = local_54 >> 9 | local_50 << 0x17;
      local_50 = local_50 >> 9 | local_4c << 0x17;
      local_4c = local_4c >> 9 | local_48 << 0x17;
      local_48 = local_48 >> 9 | local_44 << 0x17;
      local_44 = local_44 >> 9 | local_40 << 0x17;
      local_40 = local_40 >> 9 | uVar13;
      puVar7[0x10] = puVar7[0x10] & 0x1ff;
      (*(code *)puVar2)(puVar7,puVar7,local_70,0x11);
      iVar4 = (*(code *)PTR_bn_sub_words_006a96a4)(local_70,puVar7,_nist_p_521,0x11);
      puVar9 = (ulong *)((uint)local_70 ^ ((uint)puVar7 ^ (uint)local_70) & -iVar4);
      *puVar7 = *puVar9;
      puVar7[1] = puVar9[1];
      puVar7[2] = puVar9[2];
      puVar7[3] = puVar9[3];
      puVar7[4] = puVar9[4];
      puVar7[5] = puVar9[5];
      puVar7[6] = puVar9[6];
      puVar7[7] = puVar9[7];
      puVar7[8] = puVar9[8];
      puVar7[9] = puVar9[9];
      puVar7[10] = puVar9[10];
      puVar7[0xb] = puVar9[0xb];
      puVar7[0xc] = puVar9[0xc];
      puVar7[0xd] = puVar9[0xd];
      puVar7[0xe] = puVar9[0xe];
      puVar7[0xf] = puVar9[0xf];
      puVar10 = r->d;
      puVar7[0x10] = puVar9[0x10];
      r->top = 0x11;
      if (puVar10[0x10] == 0) {
        if (puVar10[0xf] == 0) {
          if (puVar10[0xe] == 0) {
            if (puVar10[0xd] == 0) {
              if (puVar10[0xc] == 0) {
                if (puVar10[0xb] == 0) {
                  if (puVar10[10] == 0) {
                    if (puVar10[9] == 0) {
                      if (puVar10[8] == 0) {
                        if (puVar10[7] == 0) {
                          if (puVar10[6] == 0) {
                            if (puVar10[5] == 0) {
                              if (puVar10[4] == 0) {
                                if (puVar10[3] == 0) {
                                  uVar8 = 1;
                                  if (puVar10[2] == 0) {
                                    if (puVar10[1] != 0) goto LAB_0062d954;
                                    r->top = (uint)(*puVar10 != 0);
                                  }
                                  else {
                                    r->top = 3;
                                  }
                                }
                                else {
                                  uVar8 = 1;
                                  r->top = 4;
                                }
                              }
                              else {
                                uVar8 = 1;
                                r->top = 5;
                              }
                            }
                            else {
                              uVar8 = 1;
                              r->top = 6;
                            }
                          }
                          else {
                            uVar8 = 1;
                            r->top = 7;
                          }
                        }
                        else {
                          uVar8 = 1;
                          r->top = 8;
                        }
                      }
                      else {
                        uVar8 = 1;
                        r->top = 9;
                      }
                    }
                    else {
                      uVar8 = 1;
                      r->top = 10;
                    }
                  }
                  else {
                    uVar8 = 1;
                    r->top = 0xb;
                  }
                }
                else {
                  uVar8 = 1;
                  r->top = 0xc;
                }
              }
              else {
                uVar8 = 1;
                r->top = 0xd;
              }
            }
            else {
              uVar8 = 1;
              r->top = 0xe;
            }
          }
          else {
            uVar8 = 1;
            r->top = 0xf;
          }
        }
        else {
          uVar8 = 1;
          r->top = 0x10;
        }
      }
      else {
        uVar8 = 1;
        r->top = 0x11;
      }
      goto LAB_0062d320;
    }
  }
  uVar8 = (*(code *)PTR_BN_nnmod_006a9664)(r,a,_bignum_nist_p_521);
LAB_0062d320:
  while( true ) {
    if (local_2c == *(int *)puVar3) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0062d954:
    r->top = 2;
  }
  return uVar8;
}

