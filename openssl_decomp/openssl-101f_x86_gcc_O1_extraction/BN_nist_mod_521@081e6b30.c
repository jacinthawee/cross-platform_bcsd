
int BN_nist_mod_521(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  size_t __n;
  ulong uVar4;
  ulong *puVar5;
  int iVar6;
  ulong *rp;
  int in_GS_OFFSET;
  uint local_64 [4];
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
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = a->neg;
  if (uVar2 == 0) {
    iVar6 = a->top;
    puVar5 = a->d;
    iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_521_sqr_6218);
    if (iVar1 < 0) {
      iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_521,a);
      if (iVar1 == 0) {
        uVar2 = 1;
        BN_set_word(r,0);
        goto LAB_081e6b97;
      }
      if (0 < iVar1) {
        uVar2 = 1;
        if (a != r) {
          pBVar3 = BN_copy(r,a);
          uVar2 = (uint)(pBVar3 != (BIGNUM *)0x0);
        }
        goto LAB_081e6b97;
      }
      rp = puVar5;
      if (a != r) {
        if ((r->dmax < 0x11) && (pBVar3 = bn_expand2(r,0x11), pBVar3 == (BIGNUM *)0x0))
        goto LAB_081e6b97;
        rp = r->d;
        *rp = *puVar5;
        rp[1] = puVar5[1];
        rp[2] = puVar5[2];
        rp[3] = puVar5[3];
        rp[4] = puVar5[4];
        rp[5] = puVar5[5];
        rp[6] = puVar5[6];
        rp[7] = puVar5[7];
        rp[8] = puVar5[8];
        rp[9] = puVar5[9];
        rp[10] = puVar5[10];
        rp[0xb] = puVar5[0xb];
        rp[0xc] = puVar5[0xc];
        rp[0xd] = puVar5[0xd];
        rp[0xe] = puVar5[0xe];
        rp[0xf] = puVar5[0xf];
        rp[0x10] = puVar5[0x10];
      }
      if (iVar6 < 0x11) {
        iVar6 = 0;
LAB_081e6cab:
        __n = iVar6 * -4 + 0x44;
        if (0x10 < iVar6) {
          __n = 4;
        }
        memset(local_64 + iVar6,0,__n);
      }
      else {
        iVar1 = 0;
        iVar6 = iVar6 + -0x10;
        do {
          local_64[iVar1] = puVar5[iVar1 + 0x10];
          iVar1 = iVar1 + 1;
        } while (iVar1 != iVar6);
        if (iVar6 < 0x11) goto LAB_081e6cab;
      }
      local_64[0] = local_64[1] << 0x17 | local_64[0] >> 9;
      local_64[1] = local_64[1] >> 9 | local_64[2] << 0x17;
      local_64[2] = local_64[2] >> 9 | local_64[3] << 0x17;
      local_64[3] = local_64[3] >> 9 | local_54 << 0x17;
      local_54 = local_54 >> 9 | local_50 << 0x17;
      local_50 = local_50 >> 9 | local_4c << 0x17;
      local_4c = local_4c >> 9 | local_48 << 0x17;
      local_48 = local_48 >> 9 | local_44 << 0x17;
      local_44 = local_44 >> 9 | local_40 << 0x17;
      local_40 = local_40 >> 9 | local_3c << 0x17;
      local_3c = local_3c >> 9 | local_38 << 0x17;
      local_38 = local_38 >> 9 | local_34 << 0x17;
      local_34 = local_34 >> 9 | local_30 << 0x17;
      local_30 = local_30 >> 9 | local_2c << 0x17;
      local_2c = local_2c >> 9 | local_28 << 0x17;
      local_28 = local_28 >> 9 | local_24 << 0x17;
      rp[0x10] = rp[0x10] & 0x1ff;
      local_24 = local_24 >> 9;
      bn_add_words(rp,rp,local_64,0x11);
      uVar4 = bn_sub_words(local_64,rp,(ulong *)_nist_p_521,0x11);
      puVar5 = (ulong *)(-uVar4 & ((uint)rp ^ (uint)local_64) ^ (uint)local_64);
      *rp = *puVar5;
      rp[1] = puVar5[1];
      rp[2] = puVar5[2];
      rp[3] = puVar5[3];
      rp[4] = puVar5[4];
      rp[5] = puVar5[5];
      rp[6] = puVar5[6];
      rp[7] = puVar5[7];
      rp[8] = puVar5[8];
      rp[9] = puVar5[9];
      rp[10] = puVar5[10];
      rp[0xb] = puVar5[0xb];
      rp[0xc] = puVar5[0xc];
      rp[0xd] = puVar5[0xd];
      rp[0xe] = puVar5[0xe];
      rp[0xf] = puVar5[0xf];
      rp[0x10] = puVar5[0x10];
      puVar5 = r->d;
      r->top = 0x11;
      if (puVar5[0x10] == 0) {
        if (puVar5[0xf] == 0) {
          if (puVar5[0xe] == 0) {
            if (puVar5[0xd] == 0) {
              if (puVar5[0xc] == 0) {
                if (puVar5[0xb] == 0) {
                  if (puVar5[10] == 0) {
                    if (puVar5[9] == 0) {
                      if (puVar5[8] == 0) {
                        if (puVar5[7] == 0) {
                          if (puVar5[6] == 0) {
                            if (puVar5[5] == 0) {
                              if (puVar5[4] == 0) {
                                if (puVar5[3] == 0) {
                                  if (puVar5[2] == 0) {
                                    if (puVar5[1] == 0) {
                                      uVar2 = (uint)(*puVar5 != 0);
                                    }
                                    else {
                                      uVar2 = 2;
                                    }
                                  }
                                  else {
                                    uVar2 = 3;
                                  }
                                }
                                else {
                                  uVar2 = 4;
                                }
                              }
                              else {
                                uVar2 = 5;
                              }
                            }
                            else {
                              uVar2 = 6;
                            }
                          }
                          else {
                            uVar2 = 7;
                          }
                        }
                        else {
                          uVar2 = 8;
                        }
                      }
                      else {
                        uVar2 = 9;
                      }
                    }
                    else {
                      uVar2 = 10;
                    }
                  }
                  else {
                    uVar2 = 0xb;
                  }
                }
                else {
                  uVar2 = 0xc;
                }
              }
              else {
                uVar2 = 0xd;
              }
            }
            else {
              uVar2 = 0xe;
            }
          }
          else {
            uVar2 = 0xf;
          }
        }
        else {
          uVar2 = 0x10;
        }
      }
      else {
        uVar2 = 0x11;
      }
      r->top = uVar2;
      uVar2 = 1;
      goto LAB_081e6b97;
    }
  }
  uVar2 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_521,ctx);
LAB_081e6b97:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

