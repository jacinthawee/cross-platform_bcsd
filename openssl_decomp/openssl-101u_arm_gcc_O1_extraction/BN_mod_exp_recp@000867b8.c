
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *a_00;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  int iVar4;
  int iVar5;
  BIGNUM **ppBVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_ec;
  uint local_e8;
  int local_e4;
  BN_RECP_CTX BStack_dc;
  BIGNUM *local_a8 [33];
  
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x10e);
    return -1;
  }
  local_ec = BN_num_bits(p);
  if (local_ec == 0) {
    if (((m->top == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      return 1;
    }
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
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_000869be;
      a_00->neg = 0;
      iVar1 = BN_RECP_CTX_set(&BStack_dc,a_00,ctx);
    }
    if ((0 < iVar1) && (iVar1 = BN_nnmod(pBVar2,a,m,ctx), iVar1 != 0)) {
      if (pBVar2->top == 0) {
        iVar1 = 1;
        BN_set_word(r,0);
        goto LAB_000869c0;
      }
      if (local_ec < 0x2a0) {
        if (0xef < local_ec) {
          iVar1 = 0x10;
          local_e8 = 5;
          goto LAB_000868ac;
        }
        if (0x4f < local_ec) {
          iVar1 = 8;
          local_e8 = 4;
          goto LAB_000868ac;
        }
        if (0x17 < local_ec) {
          iVar1 = 4;
          local_e8 = 3;
          goto LAB_000868ac;
        }
        local_e8 = 1;
      }
      else {
        iVar1 = 0x20;
        local_e8 = 6;
LAB_000868ac:
        iVar4 = BN_mod_mul_reciprocal(a_00,pBVar2,pBVar2,&BStack_dc,ctx);
        if (iVar4 == 0) goto LAB_000869be;
        iVar4 = 1;
        ppBVar6 = local_a8;
        do {
          iVar4 = iVar4 + 1;
          pBVar2 = BN_CTX_get(ctx);
          ppBVar6[1] = pBVar2;
          if ((pBVar2 == (BIGNUM *)0x0) ||
             (iVar5 = BN_mod_mul_reciprocal(pBVar2,*ppBVar6,a_00,&BStack_dc,ctx), iVar5 == 0))
          goto LAB_000869be;
          ppBVar6 = ppBVar6 + 1;
        } while (iVar4 < iVar1);
      }
      iVar1 = BN_set_word(r,1);
      if (iVar1 != 0) {
        local_ec = local_ec + -1;
        local_e4 = 1;
        while( true ) {
          while (iVar1 = BN_is_bit_set(p,local_ec), iVar1 == 0) {
            if ((local_e4 == 0) && (iVar1 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx), iVar1 == 0)
               ) goto LAB_000869be;
            if (local_ec == 0) goto LAB_00086a2a;
            local_ec = local_ec + -1;
          }
          if (local_e8 == 1) {
            uVar7 = 0;
            uVar8 = local_e8;
          }
          else {
            uVar8 = 1;
            if (local_ec + -1 < 0) {
              uVar7 = 0;
            }
            else {
              uVar9 = 1;
              uVar7 = 0;
              iVar1 = local_ec + -1;
              iVar4 = local_ec + -2;
              do {
                iVar1 = BN_is_bit_set(p,iVar1);
                if (iVar1 != 0) {
                  uVar8 = uVar8 << (uVar9 - uVar7 & 0xff) | 1;
                  uVar7 = uVar9;
                }
                uVar9 = uVar9 + 1;
                iVar5 = iVar4 + -1;
              } while ((iVar4 != local_ec - local_e8) && (iVar1 = iVar4, iVar4 = iVar5, iVar5 != -2)
                      );
            }
          }
          if (local_e4 == 0) {
            do {
              local_e4 = local_e4 + 1;
              iVar1 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx);
              if (iVar1 == 0) goto LAB_000869be;
            } while (local_e4 <= (int)uVar7);
          }
          iVar1 = BN_mod_mul_reciprocal(r,r,local_a8[(int)uVar8 >> 1],&BStack_dc,ctx);
          if (iVar1 == 0) goto LAB_000869be;
          local_ec = local_ec + ~uVar7;
          if (local_ec < 0) break;
          local_e4 = 0;
        }
LAB_00086a2a:
        iVar1 = 1;
        goto LAB_000869c0;
      }
    }
  }
LAB_000869be:
  iVar1 = 0;
LAB_000869c0:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(&BStack_dc);
  return iVar1;
}

