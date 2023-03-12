
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  BIGNUM **ppBVar7;
  uint uVar8;
  int iVar9;
  int local_f0;
  uint local_ec;
  int local_e8;
  BN_RECP_CTX BStack_dc;
  BIGNUM *local_a8 [33];
  
  if ((0 < m->top) && ((int)(*m->d << 0x1f) < 0)) {
    if ((a->top == 1) && ((a->neg == 0 && ((p->flags & 4U) == 0)))) {
      iVar1 = BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
      return iVar1;
    }
    iVar1 = BN_mod_exp_mont(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
    return iVar1;
  }
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x108);
    return -1;
  }
  local_f0 = BN_num_bits(p);
  if (local_f0 == 0) {
    iVar1 = BN_set_word(r,1);
    return iVar1;
  }
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if ((a_00 != (BIGNUM *)0x0) && (pBVar2 != (BIGNUM *)0x0)) {
    BN_RECP_CTX_init(&BStack_dc);
    if (m->neg == 0) {
      iVar1 = BN_RECP_CTX_set(&BStack_dc,m,ctx);
    }
    else {
      pBVar3 = BN_copy(a_00,m);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_0008986e;
      a_00->neg = 0;
      iVar1 = BN_RECP_CTX_set(&BStack_dc,a_00,ctx);
    }
    if ((0 < iVar1) && (iVar1 = BN_nnmod(pBVar2,a,m,ctx), iVar1 != 0)) {
      if (pBVar2->top == 0) {
        iVar1 = 1;
        BN_set_word(r,0);
        goto LAB_00089870;
      }
      if (local_f0 < 0x2a0) {
        if (0xef < local_f0) {
          local_e8 = 0x10;
          local_ec = 5;
          goto LAB_00089750;
        }
        if (0x4f < local_f0) {
          local_e8 = 8;
          local_ec = 4;
          goto LAB_00089750;
        }
        if (0x17 < local_f0) {
          local_e8 = 4;
          local_ec = 3;
          goto LAB_00089750;
        }
        local_ec = 1;
      }
      else {
        local_e8 = 0x20;
        local_ec = 6;
LAB_00089750:
        iVar1 = BN_mod_mul_reciprocal(a_00,pBVar2,pBVar2,&BStack_dc,ctx);
        if (iVar1 == 0) goto LAB_0008986e;
        iVar1 = 1;
        ppBVar7 = local_a8;
        do {
          iVar1 = iVar1 + 1;
          pBVar2 = BN_CTX_get(ctx);
          ppBVar7[1] = pBVar2;
          if ((pBVar2 == (BIGNUM *)0x0) ||
             (iVar4 = BN_mod_mul_reciprocal(pBVar2,*ppBVar7,a_00,&BStack_dc,ctx), iVar4 == 0))
          goto LAB_0008986e;
          ppBVar7 = ppBVar7 + 1;
        } while (iVar1 < local_e8);
      }
      iVar1 = BN_set_word(r,1);
      if (iVar1 != 0) {
        local_f0 = local_f0 + -1;
        local_e8 = 1;
        while( true ) {
          while (iVar1 = BN_is_bit_set(p,local_f0), iVar1 == 0) {
            if ((local_e8 == 0) && (iVar1 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx), iVar1 == 0)
               ) goto LAB_0008986e;
            if (local_f0 == 0) goto LAB_000898ec;
            local_f0 = local_f0 + -1;
          }
          if (local_ec == 1) {
            uVar5 = 0;
            uVar8 = local_ec;
          }
          else {
            uVar8 = 1;
            if (local_f0 + -1 < 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = 0;
              uVar6 = 1;
              iVar1 = local_f0 + -1;
              iVar4 = local_f0 + -2;
              do {
                iVar1 = BN_is_bit_set(p,iVar1);
                if (iVar1 != 0) {
                  uVar8 = uVar8 << (uVar6 - uVar5 & 0xff) | 1;
                  uVar5 = uVar6;
                }
                uVar6 = uVar6 + 1;
                iVar9 = iVar4 + -1;
              } while ((iVar4 != local_f0 - local_ec) && (iVar1 = iVar4, iVar4 = iVar9, iVar9 != -2)
                      );
            }
          }
          if (local_e8 == 0) {
            do {
              local_e8 = local_e8 + 1;
              iVar1 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx);
              if (iVar1 == 0) goto LAB_0008986e;
            } while (local_e8 <= (int)uVar5);
          }
          iVar1 = BN_mod_mul_reciprocal(r,r,local_a8[(int)uVar8 >> 1],&BStack_dc,ctx);
          if (iVar1 == 0) goto LAB_0008986e;
          local_f0 = local_f0 + ~uVar5;
          if (local_f0 < 0) break;
          local_e8 = 0;
        }
LAB_000898ec:
        iVar1 = 1;
        goto LAB_00089870;
      }
    }
  }
LAB_0008986e:
  iVar1 = 0;
LAB_00089870:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(&BStack_dc);
  return iVar1;
}

