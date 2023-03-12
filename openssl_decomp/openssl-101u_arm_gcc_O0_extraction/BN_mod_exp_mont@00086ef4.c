
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *r_00;
  BIGNUM *pBVar3;
  int iVar4;
  uint uVar5;
  BIGNUM **ppBVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  BN_MONT_CTX *local_c0;
  int local_bc;
  int local_b8;
  uint local_b4;
  BIGNUM *local_a8 [33];
  
  if ((p->flags & 4U) != 0) {
    iVar1 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,m_ctx);
    return iVar1;
  }
  if ((m->top < 1) || (-1 < (int)(*m->d << 0x1f))) {
    ERR_put_error(3,0x6d,0x66,"bn_exp.c",0x19b);
    return 0;
  }
  local_bc = BN_num_bits(p);
  if (local_bc == 0) {
    if (((m->top == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      return 1;
    }
    iVar1 = BN_set_word(r,1);
    return iVar1;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar3 = BN_CTX_get(ctx);
  local_a8[0] = pBVar3;
  if ((r_00 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0) || (pBVar3 == (BIGNUM *)0x0)) {
LAB_00087008:
    iVar1 = 0;
    goto LAB_0008700a;
  }
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_c0 = BN_MONT_CTX_new();
    if (local_c0 == (BN_MONT_CTX *)0x0) goto LAB_00087008;
    iVar1 = BN_MONT_CTX_set(local_c0,m,ctx);
    if (iVar1 != 0) goto LAB_00086fb6;
  }
  else {
    local_c0 = m_ctx;
LAB_00086fb6:
    if (((a->neg == 0) && (iVar1 = BN_ucmp(a,m), iVar1 < 0)) ||
       (iVar1 = BN_nnmod(pBVar3,a,m,ctx), a = pBVar3, iVar1 != 0)) {
      if (a->top == 0) {
        iVar1 = 1;
        BN_set_word(r,0);
      }
      else {
        iVar1 = BN_mod_mul_montgomery(pBVar3,a,&local_c0->RR,local_c0,ctx);
        if (iVar1 == 0) goto LAB_00087068;
        if (local_bc < 0x2a0) {
          if (0xef < local_bc) {
            local_b8 = 0x10;
            local_b4 = 5;
            goto LAB_0008701a;
          }
          if (0x4f < local_bc) {
            local_b8 = 8;
            local_b4 = 4;
            goto LAB_0008701a;
          }
          if (0x17 < local_bc) {
            local_b8 = 4;
            local_b4 = 3;
            goto LAB_0008701a;
          }
          local_b4 = 1;
        }
        else {
          local_b8 = 0x20;
          local_b4 = 6;
LAB_0008701a:
          iVar1 = BN_mod_mul_montgomery(pBVar2,pBVar3,pBVar3,local_c0,ctx);
          if (iVar1 == 0) goto LAB_00087068;
          iVar1 = 1;
          ppBVar6 = local_a8;
          do {
            iVar1 = iVar1 + 1;
            pBVar3 = BN_CTX_get(ctx);
            ppBVar6[1] = pBVar3;
            if ((pBVar3 == (BIGNUM *)0x0) ||
               (iVar4 = BN_mod_mul_montgomery(pBVar3,*ppBVar6,pBVar2,local_c0,ctx), iVar4 == 0))
            goto LAB_00087068;
            ppBVar6 = ppBVar6 + 1;
          } while (iVar1 < local_b8);
        }
        pBVar2 = BN_value_one();
        iVar1 = BN_mod_mul_montgomery(r_00,pBVar2,&local_c0->RR,local_c0,ctx);
        if (iVar1 == 0) goto LAB_00087068;
        local_bc = local_bc + -1;
        local_b8 = 1;
        while( true ) {
          while (iVar1 = BN_is_bit_set(p,local_bc), iVar1 == 0) {
            if ((local_b8 == 0) &&
               (iVar1 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_c0,ctx), iVar1 == 0))
            goto LAB_00087068;
            if (local_bc == 0) goto LAB_000871ce;
            local_bc = local_bc + -1;
          }
          if (local_b4 == 1) {
            uVar5 = 0;
            uVar9 = local_b4;
          }
          else {
            uVar9 = 1;
            if (local_bc + -1 < 0) {
              uVar5 = 0;
            }
            else {
              uVar8 = 1;
              uVar5 = 0;
              iVar1 = local_bc + -1;
              iVar4 = local_bc + -2;
              do {
                iVar1 = BN_is_bit_set(p,iVar1);
                if (iVar1 != 0) {
                  uVar9 = uVar9 << (uVar8 - uVar5 & 0xff) | 1;
                  uVar5 = uVar8;
                }
                uVar8 = uVar8 + 1;
                iVar7 = iVar4 + -1;
              } while ((iVar4 != local_bc - local_b4) && (iVar1 = iVar4, iVar4 = iVar7, iVar7 != -2)
                      );
            }
          }
          if (local_b8 == 0) {
            do {
              local_b8 = local_b8 + 1;
              iVar1 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_c0,ctx);
              if (iVar1 == 0) goto LAB_00087068;
            } while (local_b8 <= (int)uVar5);
          }
          iVar1 = BN_mod_mul_montgomery(r_00,r_00,local_a8[(int)uVar9 >> 1],local_c0,ctx);
          if (iVar1 == 0) goto LAB_00087068;
          local_bc = local_bc + ~uVar5;
          if (local_bc < 0) break;
          local_b8 = 0;
        }
LAB_000871ce:
        iVar1 = BN_from_montgomery(r,r_00,local_c0,ctx);
        if (iVar1 != 0) {
          iVar1 = 1;
        }
      }
    }
    else {
LAB_00087068:
      iVar1 = 0;
    }
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_0008700a;
  }
  BN_MONT_CTX_free(local_c0);
LAB_0008700a:
  BN_CTX_end(ctx);
  return iVar1;
}

