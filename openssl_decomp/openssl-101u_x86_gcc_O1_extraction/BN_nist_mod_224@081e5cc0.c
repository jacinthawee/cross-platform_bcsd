
int BN_nist_mod_224(BIGNUM *r,BIGNUM *a,BIGNUM *p,BN_CTX *ctx)

{
  int iVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  size_t __n;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong *rp;
  int in_GS_OFFSET;
  code *local_8c;
  uint local_58 [4];
  uint local_48;
  uint local_44;
  uint local_40;
  undefined local_3c [28];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = a->neg;
  if (uVar2 == 0) {
    iVar5 = a->top;
    puVar6 = a->d;
    iVar1 = BN_ucmp(a,(BIGNUM *)_bignum_nist_p_224_sqr_6137);
    if (iVar1 < 0) {
      iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_224,a);
      if (iVar1 == 0) {
        uVar2 = 1;
        BN_set_word(r,0);
        goto LAB_081e5d24;
      }
      if (0 < iVar1) {
        uVar2 = 1;
        if (a != r) {
          pBVar3 = BN_copy(r,a);
          uVar2 = (uint)(pBVar3 != (BIGNUM *)0x0);
        }
        goto LAB_081e5d24;
      }
      rp = puVar6;
      if (a != r) {
        if ((r->dmax < 7) && (pBVar3 = bn_expand2(r,7), pBVar3 == (BIGNUM *)0x0)) goto LAB_081e5d24;
        rp = r->d;
        *rp = *puVar6;
        rp[1] = puVar6[1];
        rp[2] = puVar6[2];
        rp[3] = puVar6[3];
        rp[4] = puVar6[4];
        rp[5] = puVar6[5];
        rp[6] = puVar6[6];
      }
      if (iVar5 < 8) {
        iVar1 = 0;
LAB_081e5dfb:
        __n = iVar1 * -4 + 0x1c;
        if (6 < iVar1) {
          __n = 4;
        }
        memset(local_58 + iVar1,0,__n);
      }
      else {
        iVar1 = iVar5 + -7;
        memcpy(local_58,puVar6 + 7,iVar5 * 4 - 0x1c);
        if (iVar1 < 7) goto LAB_081e5dfb;
      }
      uVar2 = *rp - local_58[0];
      uVar8 = -(uint)(uVar2 < local_48) - (uint)(*rp < local_58[0]);
      *rp = uVar2 - local_48;
      uVar2 = uVar8 + rp[1];
      uVar4 = uVar2 - local_58[1];
      uVar8 = ((((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,rp[1])) - (uint)(uVar2 < local_58[1])) -
              (uint)(uVar4 < local_44);
      rp[1] = uVar4 - local_44;
      uVar2 = uVar8 + rp[2];
      uVar4 = uVar2 - local_58[2];
      uVar9 = ((((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,rp[2])) - (uint)(uVar2 < local_58[2])) -
              (uint)(uVar4 < local_40);
      rp[2] = uVar4 - local_40;
      uVar2 = uVar9 + rp[3];
      uVar4 = uVar2 + local_58[0];
      uVar8 = uVar4 + local_48;
      uVar9 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[3]) + (uint)CARRY4(uVar2,local_58[0]) +
              (uint)CARRY4(uVar4,local_48)) - (uint)(uVar8 < local_58[3]);
      rp[3] = uVar8 - local_58[3];
      uVar2 = uVar9 + rp[4];
      uVar4 = uVar2 + local_58[1];
      uVar8 = uVar4 + local_44;
      uVar9 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[4]) + (uint)CARRY4(uVar2,local_58[1]) +
              (uint)CARRY4(uVar4,local_44)) - (uint)(uVar8 < local_48);
      rp[4] = uVar8 - local_48;
      uVar2 = uVar9 + rp[5];
      uVar4 = uVar2 + local_58[2];
      uVar8 = uVar4 + local_40;
      uVar9 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[5]) + (uint)CARRY4(uVar2,local_58[2]) +
              (uint)CARRY4(uVar4,local_40)) - (uint)(uVar8 < local_44);
      rp[5] = uVar8 - local_44;
      uVar2 = uVar9 + rp[6];
      uVar4 = uVar2 + local_58[3];
      uVar2 = (((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,rp[6]) + (uint)CARRY4(uVar2,local_58[3])) -
              (uint)(uVar4 < local_40);
      rp[6] = uVar4 - local_40;
      local_8c = bn_sub_words;
      if (((int)uVar2 >> 0x1f < 0) || (uVar2 == 0)) {
        uVar4 = 0xffffffff;
        if (((int)uVar2 >> 0x1f | uVar2) != 0) {
          uVar7 = bn_add_words(rp,rp,(ulong *)(_nist_p_224 + ~uVar2 * 0x1c),7);
          uVar4 = -uVar7;
          local_8c = (code *)(uVar4 & 0x1f0 ^ 0x80fc040);
        }
      }
      else {
        local_8c = bn_sub_words;
        uVar7 = bn_sub_words(rp,rp,(ulong *)(_nist_p_224 + (uVar2 - 1) * 0x1c),7);
        uVar4 = -uVar7;
      }
      iVar5 = (*local_8c)(local_3c,rp,_nist_p_224,7);
      puVar6 = (ulong *)(-iVar5 & uVar4 & ((uint)rp ^ (uint)local_3c) ^ (uint)local_3c);
      *rp = *puVar6;
      rp[1] = puVar6[1];
      rp[2] = puVar6[2];
      rp[3] = puVar6[3];
      rp[4] = puVar6[4];
      rp[5] = puVar6[5];
      rp[6] = puVar6[6];
      puVar6 = r->d;
      r->top = 7;
      if (puVar6[6] == 0) {
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
      }
      else {
        uVar2 = 7;
      }
      r->top = uVar2;
      uVar2 = 1;
      goto LAB_081e5d24;
    }
  }
  uVar2 = BN_nnmod(r,a,(BIGNUM *)_bignum_nist_p_224,ctx);
LAB_081e5d24:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

