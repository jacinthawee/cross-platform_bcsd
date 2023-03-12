
int BN_mod_exp_mont(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx,BN_MONT_CTX *m_ctx)

{
  bool bVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *r_00;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int in_GS_OFFSET;
  uint local_cc;
  int local_c0;
  BN_MONT_CTX *local_bc;
  int local_b8;
  BIGNUM *apBStack_a4 [33];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar7 = p->flags & 4;
  if (uVar7 != 0) {
    if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
      iVar2 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,m_ctx);
      return iVar2;
    }
    goto LAB_080f5272;
  }
  if ((m->top < 1) || ((*(byte *)m->d & 1) == 0)) {
    ERR_put_error(3,0x6d,0x66,"bn_exp.c",0x196);
  }
  else {
    iVar2 = BN_num_bits(p);
    if (iVar2 == 0) {
      if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
        iVar2 = BN_set_word(r,1);
        return iVar2;
      }
      goto LAB_080f5272;
    }
    BN_CTX_start(ctx);
    pBVar3 = BN_CTX_get(ctx);
    r_00 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    apBStack_a4[1] = pBVar4;
    if ((pBVar3 == (BIGNUM *)0x0 || r_00 == (BIGNUM *)0x0) || (pBVar4 == (BIGNUM *)0x0)) {
LAB_080f4f48:
      uVar7 = 0;
      BN_CTX_end(ctx);
      goto LAB_080f4d60;
    }
    local_bc = m_ctx;
    if (m_ctx == (BN_MONT_CTX *)0x0) {
      local_bc = BN_MONT_CTX_new();
      if (local_bc == (BN_MONT_CTX *)0x0) goto LAB_080f4f48;
      iVar5 = BN_MONT_CTX_set(local_bc,m,ctx);
      if (iVar5 != 0) goto LAB_080f4e14;
      uVar7 = 0;
LAB_080f4f20:
      BN_MONT_CTX_free(local_bc);
    }
    else {
LAB_080f4e14:
      if (((a->neg == 0) && (iVar5 = BN_ucmp(a,m), iVar5 < 0)) ||
         (iVar5 = BN_nnmod(pBVar4,a,m,ctx), a = pBVar4, iVar5 != 0)) {
        if (a->top == 0) {
          uVar7 = 1;
          BN_set_word(r,0);
        }
        else {
          iVar5 = BN_mod_mul_montgomery(pBVar4,a,&local_bc->RR,local_bc,ctx);
          if (iVar5 == 0) goto LAB_080f4f16;
          if (iVar2 < 0x2a0) {
            if (0xef < iVar2) {
              local_c0 = 0x10;
              local_b8 = 5;
              goto LAB_080f50c8;
            }
            if (0x4f < iVar2) {
              local_c0 = 8;
              local_b8 = 4;
              goto LAB_080f50c8;
            }
            if (0x17 < iVar2) {
              local_c0 = 4;
              local_b8 = 3;
              goto LAB_080f50c8;
            }
            local_b8 = 1;
          }
          else {
            local_c0 = 0x20;
            local_b8 = 6;
LAB_080f50c8:
            iVar5 = BN_mod_mul_montgomery(pBVar3,pBVar4,pBVar4,local_bc,ctx);
            if (iVar5 == 0) goto LAB_080f4f16;
            iVar5 = 1;
            do {
              pBVar4 = BN_CTX_get(ctx);
              apBStack_a4[iVar5 + 1] = pBVar4;
              if ((pBVar4 == (BIGNUM *)0x0) ||
                 (iVar8 = BN_mod_mul_montgomery(pBVar4,apBStack_a4[iVar5],pBVar3,local_bc,ctx),
                 iVar8 == 0)) goto LAB_080f4f16;
              iVar5 = iVar5 + 1;
            } while (iVar5 < local_c0);
          }
          pBVar3 = BN_value_one();
          iVar5 = BN_mod_mul_montgomery(r_00,pBVar3,&local_bc->RR,local_bc,ctx);
          if (iVar5 == 0) goto LAB_080f4f16;
          bVar1 = true;
          local_c0 = iVar2 + -1;
          while( true ) {
            while (iVar2 = BN_is_bit_set(p,local_c0), iVar2 != 0) {
              if (local_b8 == 1) {
                local_cc = 1;
                iVar2 = 0;
              }
              else {
                iVar2 = 0;
                local_cc = 1;
                iVar5 = local_c0 + -1;
                if (-1 < iVar5) {
                  iVar8 = 1;
                  do {
                    iVar6 = BN_is_bit_set(p,iVar5);
                    if (iVar6 != 0) {
                      local_cc = local_cc << ((char)iVar8 - (char)iVar2 & 0x1fU) | 1;
                      iVar2 = iVar8;
                    }
                    iVar8 = iVar8 + 1;
                  } while ((iVar8 != local_b8) && (iVar5 = iVar5 + -1, iVar5 != -1));
                }
              }
              if (!bVar1) {
                iVar5 = 0;
                do {
                  iVar8 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_bc,ctx);
                  if (iVar8 == 0) goto LAB_080f4f16;
                  iVar5 = iVar5 + 1;
                } while (iVar5 <= iVar2);
              }
              iVar5 = BN_mod_mul_montgomery
                                (r_00,r_00,apBStack_a4[((int)local_cc >> 1) + 1],local_bc,ctx);
              if (iVar5 == 0) goto LAB_080f4f16;
              local_c0 = local_c0 - (iVar2 + 1);
              if (local_c0 < 0) goto LAB_080f51a0;
              bVar1 = false;
            }
            if ((!bVar1) && (iVar2 = BN_mod_mul_montgomery(r_00,r_00,r_00,local_bc,ctx), iVar2 == 0)
               ) goto LAB_080f4f16;
            if (local_c0 == 0) break;
            local_c0 = local_c0 + -1;
          }
LAB_080f51a0:
          iVar2 = BN_from_montgomery(r,r_00,local_bc,ctx);
          uVar7 = (uint)(iVar2 != 0);
        }
      }
      else {
LAB_080f4f16:
        uVar7 = 0;
      }
      if (m_ctx == (BN_MONT_CTX *)0x0) goto LAB_080f4f20;
    }
    BN_CTX_end(ctx);
  }
LAB_080f4d60:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar7;
  }
LAB_080f5272:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

