
int BN_nist_mod_384(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  size_t __n;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  ulong *puVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  ulong *rp;
  int in_GS_OFFSET;
  code *local_d4;
  uint local_80 [4];
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined local_50 [48];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = a->neg;
  if (uVar2 == 0) {
    iVar11 = a->top;
    puVar12 = a->d;
    iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_384_sqr_6199);
    if (iVar1 < 0) {
      iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_384,a);
      if (iVar1 == 0) {
        uVar2 = 1;
        BN_set_word(r,0);
        goto LAB_081e675a;
      }
      if (0 < iVar1) {
        uVar2 = 1;
        if (a != r) {
          pBVar3 = BN_copy(r,a);
          uVar2 = (uint)(pBVar3 != (BIGNUM *)0x0);
        }
        goto LAB_081e675a;
      }
      rp = puVar12;
      if (a != r) {
        if ((r->dmax < 0xc) && (pBVar3 = bn_expand2(r,0xc), pBVar3 == (BIGNUM *)0x0))
        goto LAB_081e675a;
        rp = r->d;
        *rp = *puVar12;
        rp[1] = puVar12[1];
        rp[2] = puVar12[2];
        rp[3] = puVar12[3];
        rp[4] = puVar12[4];
        rp[5] = puVar12[5];
        rp[6] = puVar12[6];
        rp[7] = puVar12[7];
        rp[8] = puVar12[8];
        rp[9] = puVar12[9];
        rp[10] = puVar12[10];
        rp[0xb] = puVar12[0xb];
      }
      if (iVar11 < 0xd) {
        iVar1 = 0;
LAB_081e685c:
        __n = iVar1 * -4 + 0x30;
        if (0xb < iVar1) {
          __n = 4;
        }
        memset(local_80 + iVar1,0,__n);
      }
      else {
        iVar1 = iVar11 + -0xc;
        memcpy(local_80,puVar12 + 0xc,iVar11 * 4 - 0x30);
        if (iVar1 < 0xc) goto LAB_081e685c;
      }
      uVar2 = *rp + local_80[0];
      uVar4 = uVar2 + local_5c;
      uVar5 = uVar4 + local_60;
      uVar14 = ((uint)CARRY4(*rp,local_80[0]) + (uint)CARRY4(uVar2,local_5c) +
               (uint)CARRY4(uVar4,local_60)) - (uint)(uVar5 < local_54);
      *rp = uVar5 - local_54;
      uVar2 = uVar14 + rp[1];
      uVar4 = uVar2 + local_80[1];
      uVar5 = uVar4 + local_58;
      uVar6 = uVar5 + local_54;
      uVar7 = uVar6 - local_80[0];
      uVar14 = ((((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[1]) +
                 (uint)CARRY4(uVar2,local_80[1]) + (uint)CARRY4(uVar4,local_58) +
                (uint)CARRY4(uVar5,local_54)) - (uint)(uVar6 < local_80[0])) -
               (uint)(uVar7 < local_60);
      rp[1] = uVar7 - local_60;
      uVar2 = uVar14 + rp[2];
      uVar4 = uVar2 + local_80[2];
      uVar5 = uVar4 + local_54;
      uVar6 = uVar5 - local_80[1];
      uVar15 = ((((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[2]) +
                 (uint)CARRY4(uVar2,local_80[2]) + (uint)CARRY4(uVar4,local_54)) -
               (uint)(uVar5 < local_80[1])) - (uint)(uVar6 < local_5c);
      rp[2] = uVar6 - local_5c;
      uVar2 = uVar15 + rp[3];
      uVar4 = uVar2 + local_80[3];
      uVar5 = uVar4 + local_80[0];
      uVar6 = uVar5 + local_60;
      uVar7 = uVar6 + local_5c;
      uVar14 = uVar7 - local_80[2];
      uVar8 = uVar14 - local_58;
      uVar16 = (((((int)uVar15 >> 0x1f) + (uint)CARRY4(uVar15,rp[3]) +
                  (uint)CARRY4(uVar2,local_80[3]) + (uint)CARRY4(uVar4,local_80[0]) +
                  (uint)CARRY4(uVar5,local_60) + (uint)CARRY4(uVar6,local_5c)) -
                (uint)(uVar7 < local_80[2])) - (uint)(uVar14 < local_58)) - (uint)(uVar8 < local_54)
      ;
      rp[3] = uVar8 - local_54;
      uVar2 = uVar16 + rp[4];
      uVar4 = uVar2 + local_5c;
      uVar5 = uVar4 + local_5c;
      uVar6 = uVar5 + local_70;
      uVar7 = uVar6 + local_80[1];
      uVar14 = uVar7 + local_80[0];
      uVar8 = uVar14 + local_60;
      uVar15 = uVar8 + local_58;
      uVar9 = uVar15 - local_80[3];
      uVar10 = uVar9 - local_54;
      uVar9 = (((((int)uVar16 >> 0x1f) + (uint)CARRY4(uVar16,rp[4]) + (uint)CARRY4(uVar2,local_5c) +
                 (uint)CARRY4(uVar4,local_5c) + (uint)CARRY4(uVar5,local_70) +
                 (uint)CARRY4(uVar6,local_80[1]) + (uint)CARRY4(uVar7,local_80[0]) +
                 (uint)CARRY4(uVar14,local_60) + (uint)CARRY4(uVar8,local_58)) -
               (uint)(uVar15 < local_80[3])) - (uint)(uVar9 < local_54)) - (uint)(uVar10 < local_54)
      ;
      rp[4] = uVar10 - local_54;
      uVar2 = uVar9 + rp[5];
      uVar4 = uVar2 + local_58;
      uVar5 = uVar4 + local_58;
      uVar6 = uVar5 + local_6c;
      uVar7 = uVar6 + local_80[2];
      uVar14 = uVar7 + local_80[1];
      uVar8 = uVar14 + local_5c;
      uVar15 = uVar8 + local_54;
      uVar9 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[5]) + (uint)CARRY4(uVar2,local_58) +
               (uint)CARRY4(uVar4,local_58) + (uint)CARRY4(uVar5,local_6c) +
               (uint)CARRY4(uVar6,local_80[2]) + (uint)CARRY4(uVar7,local_80[1]) +
               (uint)CARRY4(uVar14,local_5c) + (uint)CARRY4(uVar8,local_54)) -
              (uint)(uVar15 < local_70);
      rp[5] = uVar15 - local_70;
      uVar2 = uVar9 + rp[6];
      uVar4 = uVar2 + local_54;
      uVar5 = uVar4 + local_54;
      uVar6 = uVar5 + local_68;
      uVar7 = uVar6 + local_80[3];
      uVar14 = uVar7 + local_80[2];
      uVar8 = uVar14 + local_58;
      uVar14 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[6]) + (uint)CARRY4(uVar2,local_54) +
                (uint)CARRY4(uVar4,local_54) + (uint)CARRY4(uVar5,local_68) +
                (uint)CARRY4(uVar6,local_80[3]) + (uint)CARRY4(uVar7,local_80[2]) +
               (uint)CARRY4(uVar14,local_58)) - (uint)(uVar8 < local_6c);
      rp[6] = uVar8 - local_6c;
      uVar2 = uVar14 + rp[7];
      uVar4 = uVar2 + local_64;
      uVar5 = uVar4 + local_70;
      uVar6 = uVar5 + local_80[3];
      uVar7 = uVar6 + local_54;
      uVar14 = (((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[7]) + (uint)CARRY4(uVar2,local_64) +
                (uint)CARRY4(uVar4,local_70) + (uint)CARRY4(uVar5,local_80[3]) +
               (uint)CARRY4(uVar6,local_54)) - (uint)(uVar7 < local_68);
      rp[7] = uVar7 - local_68;
      uVar2 = uVar14 + rp[8];
      uVar4 = uVar2 + local_60;
      uVar5 = uVar4 + local_6c;
      uVar6 = uVar5 + local_70;
      uVar7 = (((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[8]) + (uint)CARRY4(uVar2,local_60) +
               (uint)CARRY4(uVar4,local_6c) + (uint)CARRY4(uVar5,local_70)) -
              (uint)(uVar6 < local_64);
      rp[8] = uVar6 - local_64;
      uVar2 = uVar7 + rp[9];
      uVar4 = uVar2 + local_5c;
      uVar5 = uVar4 + local_68;
      uVar6 = uVar5 + local_6c;
      uVar7 = (((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[9]) + (uint)CARRY4(uVar2,local_5c) +
               (uint)CARRY4(uVar4,local_68) + (uint)CARRY4(uVar5,local_6c)) -
              (uint)(uVar6 < local_60);
      rp[9] = uVar6 - local_60;
      uVar2 = uVar7 + rp[10];
      uVar4 = uVar2 + local_58;
      uVar5 = uVar4 + local_64;
      uVar6 = uVar5 + local_68;
      uVar7 = (((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[10]) + (uint)CARRY4(uVar2,local_58) +
               (uint)CARRY4(uVar4,local_64) + (uint)CARRY4(uVar5,local_68)) -
              (uint)(uVar6 < local_5c);
      rp[10] = uVar6 - local_5c;
      uVar2 = uVar7 + rp[0xb];
      uVar4 = uVar2 + local_54;
      uVar5 = uVar4 + local_60;
      uVar6 = uVar5 + local_64;
      uVar2 = (((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,rp[0xb]) + (uint)CARRY4(uVar2,local_54) +
               (uint)CARRY4(uVar4,local_60) + (uint)CARRY4(uVar5,local_64)) -
              (uint)(uVar6 < local_58);
      rp[0xb] = uVar6 - local_58;
      local_d4 = bn_sub_words;
      if (((int)uVar2 >> 0x1f < 0) || (uVar2 == 0)) {
        uVar4 = 0xffffffff;
        if (((int)uVar2 >> 0x1f | uVar2) != 0) {
          uVar13 = bn_add_words(rp,rp,(ulong *)(_nist_p_384 + ~uVar2 * 0x30),0xc);
          uVar4 = -uVar13;
          local_d4 = (code *)(uVar4 & 0x1f0 ^ 0x80fc040);
        }
      }
      else {
        local_d4 = bn_sub_words;
        uVar13 = bn_sub_words(rp,rp,(ulong *)(_nist_p_384 + (uVar2 * 3 + -3) * 0x10),0xc);
        uVar4 = -uVar13;
      }
      iVar11 = (*local_d4)(local_50,rp,_nist_p_384,0xc);
      puVar12 = (ulong *)(-iVar11 & uVar4 & ((uint)rp ^ (uint)local_50) ^ (uint)local_50);
      *rp = *puVar12;
      rp[1] = puVar12[1];
      rp[2] = puVar12[2];
      rp[3] = puVar12[3];
      rp[4] = puVar12[4];
      rp[5] = puVar12[5];
      rp[6] = puVar12[6];
      rp[7] = puVar12[7];
      rp[8] = puVar12[8];
      rp[9] = puVar12[9];
      rp[10] = puVar12[10];
      rp[0xb] = puVar12[0xb];
      puVar12 = r->d;
      r->top = 0xc;
      if (puVar12[0xb] == 0) {
        if (puVar12[10] == 0) {
          if (puVar12[9] == 0) {
            if (puVar12[8] == 0) {
              if (puVar12[7] == 0) {
                if (puVar12[6] == 0) {
                  if (puVar12[5] == 0) {
                    if (puVar12[4] == 0) {
                      if (puVar12[3] == 0) {
                        if (puVar12[2] == 0) {
                          if (puVar12[1] == 0) {
                            uVar2 = (uint)(*puVar12 != 0);
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
      r->top = uVar2;
      uVar2 = 1;
      goto LAB_081e675a;
    }
  }
  uVar2 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_384,ctx);
LAB_081e675a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

