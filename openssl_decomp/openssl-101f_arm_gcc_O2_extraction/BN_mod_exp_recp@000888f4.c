
int BN_mod_exp_recp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  BIGNUM *a_00;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  BIGNUM **ppBVar9;
  int local_ec;
  uint local_e8;
  int local_e4;
  BN_RECP_CTX BStack_dc;
  BIGNUM *local_a8 [33];
  
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x108);
    return -1;
  }
  local_ec = BN_num_bits(p);
  if (local_ec == 0) {
    iVar2 = BN_set_word(r,1);
    return iVar2;
  }
  BN_CTX_start(ctx);
  a_00 = BN_CTX_get(ctx);
  pBVar1 = BN_CTX_get(ctx);
  local_a8[0] = pBVar1;
  if ((a_00 != (BIGNUM *)0x0) && (pBVar1 != (BIGNUM *)0x0)) {
    BN_RECP_CTX_init(&BStack_dc);
    if (m->neg == 0) {
      iVar2 = BN_RECP_CTX_set(&BStack_dc,m,ctx);
    }
    else {
      pBVar5 = BN_copy(a_00,m);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_00088a92;
      a_00->neg = 0;
      iVar2 = BN_RECP_CTX_set(&BStack_dc,a_00,ctx);
    }
    if ((0 < iVar2) && (iVar2 = BN_nnmod(pBVar1,a,m,ctx), iVar2 != 0)) {
      if (pBVar1->top == 0) {
        iVar2 = 1;
        BN_set_word(r,0);
        goto LAB_00088a94;
      }
      if (local_ec < 0x2a0) {
        if (0xef < local_ec) {
          iVar2 = 0x10;
          local_e8 = 5;
          goto LAB_00088992;
        }
        if (0x4f < local_ec) {
          iVar2 = 8;
          local_e8 = 4;
          goto LAB_00088992;
        }
        if (0x17 < local_ec) {
          iVar2 = 4;
          local_e8 = 3;
          goto LAB_00088992;
        }
        local_e8 = 1;
      }
      else {
        iVar2 = 0x20;
        local_e8 = 6;
LAB_00088992:
        iVar3 = BN_mod_mul_reciprocal(a_00,pBVar1,pBVar1,&BStack_dc,ctx);
        if (iVar3 == 0) goto LAB_00088a92;
        iVar3 = 1;
        ppBVar9 = local_a8;
        do {
          iVar3 = iVar3 + 1;
          pBVar1 = BN_CTX_get(ctx);
          ppBVar9[1] = pBVar1;
          if ((pBVar1 == (BIGNUM *)0x0) ||
             (iVar4 = BN_mod_mul_reciprocal(pBVar1,*ppBVar9,a_00,&BStack_dc,ctx), iVar4 == 0))
          goto LAB_00088a92;
          ppBVar9 = ppBVar9 + 1;
        } while (iVar3 < iVar2);
      }
      iVar2 = BN_set_word(r,1);
      if (iVar2 != 0) {
        local_ec = local_ec + -1;
        local_e4 = 1;
        while( true ) {
          while (iVar2 = BN_is_bit_set(p,local_ec), iVar2 == 0) {
            if ((local_e4 == 0) && (iVar2 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx), iVar2 == 0)
               ) goto LAB_00088a92;
            if (local_ec == 0) goto LAB_00088b32;
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
              uVar7 = 0;
              uVar6 = 1;
              iVar2 = local_ec + -1;
              iVar3 = local_ec + -2;
              do {
                iVar2 = BN_is_bit_set(p,iVar2);
                if (iVar2 != 0) {
                  uVar8 = uVar8 << (uVar6 - uVar7 & 0xff) | 1;
                  uVar7 = uVar6;
                }
                uVar6 = uVar6 + 1;
                iVar4 = iVar3 + -1;
              } while ((iVar3 != local_ec - local_e8) && (iVar2 = iVar3, iVar3 = iVar4, iVar4 != -2)
                      );
            }
          }
          if (local_e4 == 0) {
            do {
              local_e4 = local_e4 + 1;
              iVar2 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx);
              if (iVar2 == 0) goto LAB_00088a92;
            } while (local_e4 <= (int)uVar7);
          }
          iVar2 = BN_mod_mul_reciprocal(r,r,local_a8[(int)uVar8 >> 1],&BStack_dc,ctx);
          if (iVar2 == 0) goto LAB_00088a92;
          local_ec = local_ec + ~uVar7;
          if (local_ec < 0) break;
          local_e4 = 0;
        }
LAB_00088b32:
        iVar2 = 1;
        goto LAB_00088a94;
      }
    }
  }
LAB_00088a92:
  iVar2 = 0;
LAB_00088a94:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(&BStack_dc);
  return iVar2;
}

