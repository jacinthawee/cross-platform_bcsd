
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  BIGNUM *pBVar1;
  BIGNUM *r_00;
  BIGNUM *pBVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  BIGNUM **ppBVar7;
  uint uVar8;
  uint uVar9;
  BN_MONT_CTX *local_c0;
  int local_bc;
  int local_b8;
  uint local_b4;
  BIGNUM *local_a8 [33];
  
  if ((p->flags & 4U) != 0) {
    iVar3 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,m_ctx);
    return iVar3;
  }
  if ((m->top < 1) || (-1 < (int)(*m->d << 0x1f))) {
    ERR_put_error(3,0x6d,0x66,"bn_exp.c",0x196);
    return 0;
  }
  local_bc = BN_num_bits(p);
  if (local_bc == 0) {
    iVar3 = BN_set_word(r,1);
    return iVar3;
  }
  BN_CTX_start(ctx);
  pBVar1 = BN_CTX_get(ctx);
  r_00 = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  local_a8[0] = pBVar2;
  if ((r_00 == (BIGNUM *)0x0 || pBVar1 == (BIGNUM *)0x0) || (pBVar2 == (BIGNUM *)0x0)) {
LAB_00089158:
    BN_CTX_end(ctx);
    return 0;
  }
  if (m_ctx == (BN_MONT_CTX *)0x0) {
    local_c0 = BN_MONT_CTX_new();
    if (local_c0 == (BN_MONT_CTX *)0x0) goto LAB_00089158;
    iVar3 = BN_MONT_CTX_set(local_c0,m,ctx);
    if (iVar3 != 0) goto LAB_000890da;
  }
  else {
    local_c0 = m_ctx;
LAB_000890da:
    if (((a->neg == 0) && (iVar3 = BN_ucmp(a,m), iVar3 < 0)) ||
       (iVar3 = BN_nnmod(pBVar2,a,m,ctx), a = pBVar2, iVar3 != 0)) {
      if (a->top == 0) {
        iVar3 = 1;
        BN_set_word(r,0);
      }
      else {
        iVar3 = BN_mod_mul_montgomery(pBVar2,a,&local_c0->RR,local_c0,ctx);
        if (iVar3 == 0) goto LAB_0008914e;
        if (local_bc < 0x2a0) {
          if (0xef < local_bc) {
            local_b8 = 0x10;
            local_b4 = 5;
            goto LAB_000891a6;
          }
          if (0x4f < local_bc) {
            local_b8 = 8;
            local_b4 = 4;
            goto LAB_000891a6;
          }
          if (0x17 < local_bc) {
            local_b8 = 4;
            local_b4 = 3;
            goto LAB_000891a6;
          }
          local_b4 = 1;
        }
        else {
          local_b8 = 0x20;
          local_b4 = 6;
LAB_000891a6:
          iVar3 = BN_mod_mul_montgomery(pBVar1,pBVar2,pBVar2,local_c0,ctx);
          if (iVar3 == 0) goto LAB_0008914e;
          iVar3 = 1;
          ppBVar7 = local_a8;
          do {
            iVar3 = iVar3 + 1;
            pBVar2 = BN_CTX_get(ctx);
            ppBVar7[1] = pBVar2;
            if ((pBVar2 == (BIGNUM *)0x0) ||
               (iVar4 = BN_mod_mul_montgomery(pBVar2,*ppBVar7,pBVar1,local_c0,ctx), iVar4 == 0))
            goto LAB_0008914e;
            ppBVar7 = ppBVar7 + 1;
          } while (iVar3 < local_b8);
        }
        pBVar1 = BN_value_one();
        iVar3 = BN_mod_mul_montgomery(r_00,pBVar1,&local_c0->RR,local_c0,ctx);
        if (iVar3 == 0) goto LAB_0008914e;
        local_bc = local_bc + -1;
        local_b8 = 1;
        while( true ) {
          while (iVar3 = BN_is_bit_set(p,local_bc), iVar3 == 0) {
            if ((local_b8 == 0) &&
               (iVar3 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_c0,ctx), iVar3 == 0))
            goto LAB_0008914e;
            if (local_bc == 0) goto LAB_000892de;
            local_bc = local_bc + -1;
          }
          if (local_b4 == 1) {
            uVar5 = 0;
            uVar8 = local_b4;
          }
          else {
            uVar8 = 1;
            if (local_bc + -1 < 0) {
              uVar5 = 0;
            }
            else {
              uVar9 = 1;
              uVar5 = 0;
              iVar3 = local_bc + -1;
              iVar4 = local_bc + -2;
              do {
                iVar3 = BN_is_bit_set(p,iVar3);
                if (iVar3 != 0) {
                  uVar8 = uVar8 << (uVar9 - uVar5 & 0xff) | 1;
                  uVar5 = uVar9;
                }
                uVar9 = uVar9 + 1;
                iVar6 = iVar4 + -1;
              } while ((iVar4 != local_bc - local_b4) && (iVar3 = iVar4, iVar4 = iVar6, iVar6 != -2)
                      );
            }
          }
          if (local_b8 == 0) {
            do {
              local_b8 = local_b8 + 1;
              iVar3 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_c0,ctx);
              if (iVar3 == 0) goto LAB_0008914e;
            } while (local_b8 <= (int)uVar5);
          }
          iVar3 = BN_mod_mul_montgomery(r_00,r_00,local_a8[(int)uVar8 >> 1],local_c0,ctx);
          if (iVar3 == 0) goto LAB_0008914e;
          local_bc = local_bc + ~uVar5;
          if (local_bc < 0) break;
          local_b8 = 0;
        }
LAB_000892de:
        iVar3 = BN_from_montgomery(r,r_00,local_c0,ctx);
        if (iVar3 != 0) {
          iVar3 = 1;
        }
      }
    }
    else {
LAB_0008914e:
      iVar3 = 0;
    }
    if (m_ctx != (BN_MONT_CTX *)0x0) goto LAB_0008910e;
  }
  BN_MONT_CTX_free(local_c0);
LAB_0008910e:
  BN_CTX_end(ctx);
  return iVar3;
}

