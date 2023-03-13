
int BN_nist_mod_192(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  size_t __n;
  uint uVar4;
  ulong uVar5;
  ulong *puVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulong *rp;
  int in_GS_OFFSET;
  uint local_50 [4];
  uint local_40;
  uint local_3c;
  ulong local_38 [6];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = a->neg;
  if (uVar2 == 0) {
    iVar9 = a->top;
    puVar6 = a->d;
    iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_192_sqr_6101);
    if (iVar1 < 0) {
      iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_192,a);
      if (iVar1 == 0) {
        uVar2 = 1;
        BN_set_word(r,0);
        goto LAB_081e5984;
      }
      if (0 < iVar1) {
        uVar2 = 1;
        if (a != r) {
          pBVar3 = BN_copy(r,a);
          uVar2 = (uint)(pBVar3 != (BIGNUM *)0x0);
        }
        goto LAB_081e5984;
      }
      rp = puVar6;
      if (a != r) {
        if ((r->dmax < 6) && (pBVar3 = bn_expand2(r,6), pBVar3 == (BIGNUM *)0x0)) goto LAB_081e5984;
        rp = r->d;
        *rp = *puVar6;
        rp[1] = puVar6[1];
        rp[2] = puVar6[2];
        rp[3] = puVar6[3];
        rp[4] = puVar6[4];
        rp[5] = puVar6[5];
      }
      if (iVar9 < 7) {
        iVar1 = 0;
LAB_081e5a55:
        __n = iVar1 * -4 + 0x18;
        if (5 < iVar1) {
          __n = 4;
        }
        memset(local_50 + iVar1,0,__n);
      }
      else {
        iVar1 = iVar9 + -6;
        memcpy(local_50,puVar6 + 6,iVar9 * 4 - 0x18);
        if (iVar1 < 6) goto LAB_081e5a55;
      }
      uVar2 = *rp + local_50[0];
      uVar7 = (uint)CARRY4(*rp,local_50[0]) + (uint)CARRY4(uVar2,local_40);
      *rp = uVar2 + local_40;
      uVar2 = uVar7 + rp[1];
      uVar4 = uVar2 + local_50[1];
      uVar8 = (uint)CARRY4(uVar7,rp[1]) + (uint)CARRY4(uVar2,local_50[1]) +
              (uint)CARRY4(uVar4,local_3c);
      rp[1] = uVar4 + local_3c;
      uVar2 = uVar8 + rp[2];
      uVar4 = uVar2 + local_50[0];
      uVar7 = uVar4 + local_50[2];
      uVar8 = (uint)CARRY4(uVar8,rp[2]) + (uint)CARRY4(uVar2,local_50[0]) +
              (uint)CARRY4(uVar4,local_50[2]) + (uint)CARRY4(uVar7,local_40);
      rp[2] = uVar7 + local_40;
      uVar2 = uVar8 + rp[3];
      uVar4 = uVar2 + local_50[1];
      uVar7 = uVar4 + local_50[3];
      uVar8 = (uint)CARRY4(uVar8,rp[3]) + (uint)CARRY4(uVar2,local_50[1]) +
              (uint)CARRY4(uVar4,local_50[3]) + (uint)CARRY4(uVar7,local_3c);
      rp[3] = uVar7 + local_3c;
      uVar2 = uVar8 + rp[4];
      uVar4 = uVar2 + local_50[2];
      uVar8 = (uint)CARRY4(uVar8,rp[4]) + (uint)CARRY4(uVar2,local_50[2]) +
              (uint)CARRY4(uVar4,local_40);
      rp[4] = uVar4 + local_40;
      uVar2 = uVar8 + rp[5];
      uVar7 = 0xffffffff;
      uVar4 = uVar2 + local_50[3];
      iVar9 = (uint)CARRY4(uVar8,rp[5]) + (uint)CARRY4(uVar2,local_50[3]) +
              (uint)CARRY4(uVar4,local_3c);
      rp[5] = uVar4 + local_3c;
      if (iVar9 != 0) {
        uVar5 = bn_sub_words(rp,rp,(ulong *)(_nist_p_192 + (iVar9 * 3 + -3) * 8),6);
        uVar7 = -uVar5;
      }
      uVar5 = bn_sub_words(local_38,rp,(ulong *)_nist_p_192,6);
      puVar6 = (ulong *)(-uVar5 & uVar7 & ((uint)rp ^ (uint)local_38) ^ (uint)local_38);
      *rp = *puVar6;
      rp[1] = puVar6[1];
      rp[2] = puVar6[2];
      rp[3] = puVar6[3];
      rp[4] = puVar6[4];
      rp[5] = puVar6[5];
      puVar6 = r->d;
      r->top = 6;
      if (puVar6[5] == 0) {
        if (puVar6[4] == 0) {
          if (puVar6[3] == 0) {
            if (puVar6[2] == 0) {
              if (puVar6[1] == 0) {
                uVar2 = (uint)(*puVar6 != 0);
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
      r->top = uVar2;
      uVar2 = 1;
      goto LAB_081e5984;
    }
  }
  uVar2 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_192,ctx);
LAB_081e5984:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

