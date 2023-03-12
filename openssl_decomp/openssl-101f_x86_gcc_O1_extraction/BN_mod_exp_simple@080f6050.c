
int BN_mod_exp_simple(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_GS_OFFSET;
  uint local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  BIGNUM *apBStack_a4 [33];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((*(byte *)&p->flags & 4) == 0) {
    local_b8 = BN_num_bits(p);
    if (local_b8 == 0) {
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        iVar3 = BN_set_word(r,1);
        return iVar3;
      }
      goto LAB_080f645e;
    }
    BN_CTX_start(ctx);
    r_00 = BN_CTX_get(ctx);
    pBVar2 = BN_CTX_get(ctx);
    apBStack_a4[1] = pBVar2;
    if (((r_00 == (BIGNUM *)0x0) || (pBVar2 == (BIGNUM *)0x0)) ||
       (iVar3 = BN_nnmod(pBVar2,a,m,ctx), iVar3 == 0)) {
LAB_080f60fc:
      iVar3 = 0;
    }
    else if (pBVar2->top == 0) {
      iVar3 = 1;
      BN_set_word(r,0);
    }
    else {
      if (local_b8 < 0x2a0) {
        if (0xef < local_b8) {
          local_c0 = 0x10;
          local_bc = 5;
          goto LAB_080f62f0;
        }
        if (0x4f < local_b8) {
          local_c0 = 8;
          local_bc = 4;
          goto LAB_080f62f0;
        }
        if (0x17 < local_b8) {
          local_c0 = 4;
          local_bc = 3;
          goto LAB_080f62f0;
        }
        local_bc = 1;
      }
      else {
        local_c0 = 0x20;
        local_bc = 6;
LAB_080f62f0:
        iVar3 = BN_mod_mul(r_00,pBVar2,pBVar2,m,ctx);
        if (iVar3 == 0) goto LAB_080f60fc;
        iVar3 = 1;
        do {
          pBVar2 = BN_CTX_get(ctx);
          apBStack_a4[iVar3 + 1] = pBVar2;
          if ((pBVar2 == (BIGNUM *)0x0) ||
             (iVar6 = BN_mod_mul(pBVar2,apBStack_a4[iVar3],r_00,m,ctx), iVar6 == 0))
          goto LAB_080f60fc;
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_c0);
      }
      iVar3 = BN_set_word(r,1);
      if (iVar3 == 0) goto LAB_080f60fc;
      local_b8 = local_b8 + -1;
      bVar1 = true;
      while( true ) {
        while (iVar3 = BN_is_bit_set(p,local_b8), iVar3 != 0) {
          local_c4 = 1;
          iVar3 = 0;
          if ((local_bc != 1) && (iVar6 = local_b8 + -1, -1 < iVar6)) {
            iVar5 = 1;
            do {
              iVar4 = BN_is_bit_set(p,iVar6);
              if (iVar4 != 0) {
                local_c4 = local_c4 << ((char)iVar5 - (char)iVar3 & 0x1fU) | 1;
                iVar3 = iVar5;
              }
              iVar5 = iVar5 + 1;
            } while ((iVar5 != local_bc) && (iVar6 = iVar6 + -1, iVar6 != -1));
          }
          iVar6 = 0;
          if (!bVar1) {
            do {
              iVar5 = BN_mod_mul(r,r,r,m,ctx);
              if (iVar5 == 0) goto LAB_080f60fc;
              iVar6 = iVar6 + 1;
            } while (iVar6 <= iVar3);
          }
          iVar6 = BN_mod_mul(r,r,apBStack_a4[((int)local_c4 >> 1) + 1],m,ctx);
          if (iVar6 == 0) goto LAB_080f60fc;
          local_b8 = local_b8 - (iVar3 + 1);
          if (local_b8 < 0) goto LAB_080f63e8;
          bVar1 = false;
        }
        if ((!bVar1) && (iVar3 = BN_mod_mul(r,r,r,m,ctx), iVar3 == 0)) goto LAB_080f60fc;
        if (local_b8 == 0) break;
        local_b8 = local_b8 + -1;
      }
LAB_080f63e8:
      iVar3 = 1;
    }
    BN_CTX_end(ctx);
  }
  else {
    ERR_put_error(3,0x7e,0x42,"bn_exp.c",0x3e3);
    iVar3 = -1;
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
LAB_080f645e:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

