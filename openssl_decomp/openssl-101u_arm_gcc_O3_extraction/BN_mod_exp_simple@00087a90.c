
int BN_mod_exp_simple(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  BIGNUM **ppBVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_b8;
  uint local_b4;
  int local_b0;
  BIGNUM *local_a8 [33];
  
  if (p->flags << 0x1d < 0) {
    ERR_put_error(3,0x7e,0x42,"bn_exp.c",0x436);
    return -1;
  }
  iVar1 = BN_num_bits(p);
  if (iVar1 == 0) {
    if (((m->top == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      return 1;
    }
    iVar1 = BN_set_word(r,1);
    return iVar1;
  }
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if (((r_00 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) &&
     (iVar3 = BN_nnmod(pBVar2,a,m,ctx), iVar3 != 0)) {
    if (pBVar2->top == 0) {
      iVar1 = 1;
      BN_set_word(r,0);
      goto LAB_00087c50;
    }
    if (iVar1 < 0x2a0) {
      if (0xef < iVar1) {
        local_b8 = 0x10;
        local_b4 = 5;
        goto LAB_00087b2c;
      }
      if (0x4f < iVar1) {
        local_b8 = 8;
        local_b4 = 4;
        goto LAB_00087b2c;
      }
      if (0x17 < iVar1) {
        local_b8 = 4;
        local_b4 = 3;
        goto LAB_00087b2c;
      }
      local_b4 = 1;
    }
    else {
      local_b8 = 0x20;
      local_b4 = 6;
LAB_00087b2c:
      iVar3 = BN_mod_mul(r_00,pBVar2,pBVar2,m,ctx);
      if (iVar3 == 0) goto LAB_00087c4e;
      iVar3 = 1;
      ppBVar5 = local_a8;
      do {
        iVar3 = iVar3 + 1;
        pBVar2 = BN_CTX_get(ctx);
        ppBVar5[1] = pBVar2;
        if ((pBVar2 == (BIGNUM *)0x0) ||
           (iVar4 = BN_mod_mul(pBVar2,*ppBVar5,r_00,m,ctx), iVar4 == 0)) goto LAB_00087c4e;
        ppBVar5 = ppBVar5 + 1;
      } while (iVar3 < local_b8);
    }
    iVar3 = BN_set_word(r,1);
    if (iVar3 != 0) {
      local_b8 = iVar1 + -1;
      local_b0 = 1;
      while( true ) {
        while (iVar1 = BN_is_bit_set(p,local_b8), iVar1 == 0) {
          if ((local_b0 == 0) && (iVar1 = BN_mod_mul(r,r,r,m,ctx), iVar1 == 0)) goto LAB_00087c4e;
          if (local_b8 == 0) goto LAB_00087cbc;
          local_b8 = local_b8 + -1;
        }
        if (local_b4 == 1) {
          uVar6 = 0;
          uVar7 = local_b4;
        }
        else {
          uVar7 = 1;
          if (local_b8 + -1 < 0) {
            uVar6 = 0;
          }
          else {
            uVar8 = 1;
            uVar6 = 0;
            iVar1 = local_b8 + -1;
            iVar3 = local_b8 + -2;
            do {
              iVar1 = BN_is_bit_set(p,iVar1);
              if (iVar1 != 0) {
                uVar7 = uVar7 << (uVar8 - uVar6 & 0xff) | 1;
                uVar6 = uVar8;
              }
              uVar8 = uVar8 + 1;
              iVar4 = iVar3 + -1;
            } while ((iVar3 != local_b8 - local_b4) && (iVar1 = iVar3, iVar3 = iVar4, iVar4 != -2));
          }
        }
        if (local_b0 == 0) {
          do {
            local_b0 = local_b0 + 1;
            iVar1 = BN_mod_mul(r,r,r,m,ctx);
            if (iVar1 == 0) goto LAB_00087c4e;
          } while (local_b0 <= (int)uVar6);
        }
        iVar1 = BN_mod_mul(r,r,local_a8[(int)uVar7 >> 1],m,ctx);
        if (iVar1 == 0) goto LAB_00087c4e;
        local_b8 = local_b8 + ~uVar6;
        if (local_b8 < 0) break;
        local_b0 = 0;
      }
LAB_00087cbc:
      iVar1 = 1;
      goto LAB_00087c50;
    }
  }
LAB_00087c4e:
  iVar1 = 0;
LAB_00087c50:
  BN_CTX_end(ctx);
  return iVar1;
}

