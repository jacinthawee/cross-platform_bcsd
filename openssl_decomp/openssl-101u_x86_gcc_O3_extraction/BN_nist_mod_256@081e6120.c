
int BN_nist_mod_256(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

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
  int iVar10;
  ulong *puVar11;
  ulong uVar12;
  uint uVar13;
  uint uVar14;
  ulong *rp;
  int in_GS_OFFSET;
  code *local_ac;
  uint local_60 [4];
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  undefined local_40 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = a->neg;
  if (uVar2 == 0) {
    iVar10 = a->top;
    puVar11 = a->d;
    iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_256_sqr_6168);
    if (iVar1 < 0) {
      iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_256,a);
      if (iVar1 == 0) {
        uVar2 = 1;
        BN_set_word(r,0);
        goto LAB_081e618a;
      }
      if (0 < iVar1) {
        uVar2 = 1;
        if (a != r) {
          pBVar3 = BN_copy(r,a);
          uVar2 = (uint)(pBVar3 != (BIGNUM *)0x0);
        }
        goto LAB_081e618a;
      }
      rp = puVar11;
      if (a != r) {
        if ((r->dmax < 8) && (pBVar3 = bn_expand2(r,8), pBVar3 == (BIGNUM *)0x0)) goto LAB_081e618a;
        rp = r->d;
        *rp = *puVar11;
        rp[1] = puVar11[1];
        rp[2] = puVar11[2];
        rp[3] = puVar11[3];
        rp[4] = puVar11[4];
        rp[5] = puVar11[5];
        rp[6] = puVar11[6];
        rp[7] = puVar11[7];
      }
      if (iVar10 < 9) {
        iVar1 = 0;
LAB_081e6271:
        __n = iVar1 * -4 + 0x20;
        if (7 < iVar1) {
          __n = 4;
        }
        memset(local_60 + iVar1,0,__n);
      }
      else {
        iVar1 = iVar10 + -8;
        memcpy(local_60,puVar11 + 8,iVar10 * 4 - 0x20);
        if (iVar1 < 8) goto LAB_081e6271;
      }
      uVar2 = *rp + local_60[0];
      uVar4 = uVar2 + local_60[1];
      uVar5 = uVar4 - local_60[3];
      uVar6 = uVar5 - local_50;
      uVar7 = uVar6 - local_4c;
      uVar13 = (((((uint)CARRY4(*rp,local_60[0]) + (uint)CARRY4(uVar2,local_60[1])) -
                 (uint)(uVar4 < local_60[3])) - (uint)(uVar5 < local_50)) - (uint)(uVar6 < local_4c)
               ) - (uint)(uVar7 < local_48);
      *rp = uVar7 - local_48;
      uVar2 = uVar13 + rp[1];
      uVar4 = uVar2 + local_60[1];
      uVar5 = uVar4 + local_60[2];
      uVar6 = uVar5 - local_50;
      uVar7 = uVar6 - local_4c;
      uVar8 = uVar7 - local_48;
      uVar13 = ((((((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar13,rp[1]) +
                   (uint)CARRY4(uVar2,local_60[1]) + (uint)CARRY4(uVar4,local_60[2])) -
                 (uint)(uVar5 < local_50)) - (uint)(uVar6 < local_4c)) - (uint)(uVar7 < local_48)) -
               (uint)(uVar8 < local_44);
      rp[1] = uVar8 - local_44;
      uVar2 = uVar13 + rp[2];
      uVar4 = uVar2 + local_60[2];
      uVar5 = uVar4 + local_60[3];
      uVar6 = uVar5 - local_4c;
      uVar7 = uVar6 - local_48;
      uVar14 = (((((int)uVar13 >> 0x1f) + (uint)CARRY4(uVar13,rp[2]) +
                  (uint)CARRY4(uVar2,local_60[2]) + (uint)CARRY4(uVar4,local_60[3])) -
                (uint)(uVar5 < local_4c)) - (uint)(uVar6 < local_48)) - (uint)(uVar7 < local_44);
      rp[2] = uVar7 - local_44;
      uVar2 = uVar14 + rp[3];
      uVar4 = uVar2 + local_60[3];
      uVar5 = uVar4 + local_60[3];
      uVar6 = uVar5 + local_50;
      uVar7 = uVar6 + local_50;
      uVar8 = uVar7 + local_4c;
      uVar13 = uVar8 - local_44;
      uVar9 = uVar13 - local_60[0];
      uVar14 = (((((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[3]) +
                  (uint)CARRY4(uVar2,local_60[3]) + (uint)CARRY4(uVar4,local_60[3]) +
                  (uint)CARRY4(uVar5,local_50) + (uint)CARRY4(uVar6,local_50) +
                 (uint)CARRY4(uVar7,local_4c)) - (uint)(uVar8 < local_44)) -
               (uint)(uVar13 < local_60[0])) - (uint)(uVar9 < local_60[1]);
      rp[3] = uVar9 - local_60[1];
      uVar2 = uVar14 + rp[4];
      uVar4 = uVar2 + local_50;
      uVar5 = uVar4 + local_50;
      uVar6 = uVar5 + local_4c;
      uVar7 = uVar6 + local_4c;
      uVar8 = uVar7 + local_48;
      uVar13 = uVar8 - local_60[1];
      uVar9 = ((((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[4]) + (uint)CARRY4(uVar2,local_50) +
                (uint)CARRY4(uVar4,local_50) + (uint)CARRY4(uVar5,local_4c) +
                (uint)CARRY4(uVar6,local_4c) + (uint)CARRY4(uVar7,local_48)) -
              (uint)(uVar8 < local_60[1])) - (uint)(uVar13 < local_60[2]);
      rp[4] = uVar13 - local_60[2];
      uVar2 = uVar9 + rp[5];
      uVar4 = uVar2 + local_4c;
      uVar5 = uVar4 + local_4c;
      uVar6 = uVar5 + local_48;
      uVar7 = uVar6 + local_48;
      uVar8 = uVar7 + local_44;
      uVar13 = uVar8 - local_60[2];
      uVar14 = ((((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[5]) + (uint)CARRY4(uVar2,local_4c) +
                 (uint)CARRY4(uVar4,local_4c) + (uint)CARRY4(uVar5,local_48) +
                 (uint)CARRY4(uVar6,local_48) + (uint)CARRY4(uVar7,local_44)) -
               (uint)(uVar8 < local_60[2])) - (uint)(uVar13 < local_60[3]);
      rp[5] = uVar13 - local_60[3];
      uVar2 = uVar14 + rp[6];
      uVar4 = uVar2 + local_48;
      uVar5 = uVar4 + local_48;
      uVar6 = uVar5 + local_44;
      uVar7 = uVar6 + local_44;
      uVar8 = uVar7 + local_48;
      uVar13 = uVar8 + local_4c;
      uVar9 = uVar13 - local_60[0];
      uVar14 = ((((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[6]) + (uint)CARRY4(uVar2,local_48) +
                 (uint)CARRY4(uVar4,local_48) + (uint)CARRY4(uVar5,local_44) +
                 (uint)CARRY4(uVar6,local_44) + (uint)CARRY4(uVar7,local_48) +
                (uint)CARRY4(uVar8,local_4c)) - (uint)(uVar13 < local_60[0])) -
               (uint)(uVar9 < local_60[1]);
      rp[6] = uVar9 - local_60[1];
      uVar2 = uVar14 + rp[7];
      uVar4 = uVar2 + local_44;
      uVar5 = uVar4 + local_44;
      uVar6 = uVar5 + local_44;
      uVar7 = uVar6 + local_60[0];
      uVar8 = uVar7 - local_60[2];
      uVar13 = uVar8 - local_60[3];
      uVar9 = uVar13 - local_50;
      uVar2 = ((((((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar14,rp[7]) + (uint)CARRY4(uVar2,local_44)
                  + (uint)CARRY4(uVar4,local_44) + (uint)CARRY4(uVar5,local_44) +
                 (uint)CARRY4(uVar6,local_60[0])) - (uint)(uVar7 < local_60[2])) -
               (uint)(uVar8 < local_60[3])) - (uint)(uVar13 < local_50)) - (uint)(uVar9 < local_4c);
      rp[7] = uVar9 - local_4c;
      local_ac = bn_sub_words;
      if (((int)uVar2 >> 0x1f < 0) || (uVar2 == 0)) {
        uVar4 = 0xffffffff;
        if (((int)uVar2 >> 0x1f | uVar2) != 0) {
          uVar12 = bn_add_words(rp,rp,(ulong *)(_nist_p_256 + ~uVar2 * 0x20),8);
          uVar4 = -uVar12;
          local_ac = (code *)(uVar4 & 0x1f0 ^ 0x80fc040);
        }
      }
      else {
        local_ac = bn_sub_words;
        uVar12 = bn_sub_words(rp,rp,(ulong *)(_nist_p_256_sqr + uVar2 * 0x20 + 0x20),8);
        uVar4 = -uVar12;
      }
      iVar10 = (*local_ac)(local_40,rp,_nist_p_256,8);
      puVar11 = (ulong *)(-iVar10 & uVar4 & ((uint)rp ^ (uint)local_40) ^ (uint)local_40);
      *rp = *puVar11;
      rp[1] = puVar11[1];
      rp[2] = puVar11[2];
      rp[3] = puVar11[3];
      rp[4] = puVar11[4];
      rp[5] = puVar11[5];
      rp[6] = puVar11[6];
      rp[7] = puVar11[7];
      puVar11 = r->d;
      r->top = 8;
      if (puVar11[7] == 0) {
        if (puVar11[6] == 0) {
          if (puVar11[5] == 0) {
            if (puVar11[4] == 0) {
              if (puVar11[3] == 0) {
                if (puVar11[2] == 0) {
                  if (puVar11[1] == 0) {
                    uVar2 = (uint)(*puVar11 != 0);
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
      r->top = uVar2;
      uVar2 = 1;
      goto LAB_081e618a;
    }
  }
  uVar2 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_256,ctx);
LAB_081e618a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

