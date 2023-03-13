
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BN_MONT_CTX *mont;
  int iVar7;
  int iVar8;
  int iVar9;
  BIGNUM **ppBVar10;
  int in_GS_OFFSET;
  BN_RECP_CTX *local_fc;
  int local_f8;
  int local_f0;
  int local_ec;
  uint local_e4;
  BN_RECP_CTX local_d4;
  BIGNUM *local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((0 < m->top) && ((*(byte *)m->d & 1) != 0)) {
    if ((a->top == 1) && (a->neg == 0)) {
      if ((*(byte *)&p->flags & 4) == 0) {
        uVar2 = BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
        goto LAB_080f35ad;
      }
    }
    else if ((*(byte *)&p->flags & 4) == 0) {
      iVar3 = BN_num_bits(p);
      if (iVar3 == 0) goto LAB_080f358a;
      BN_CTX_start(ctx);
      pBVar4 = BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      pBVar6 = BN_CTX_get(ctx);
      local_a0[0] = pBVar6;
      if (((pBVar4 == (BIGNUM *)0x0 || pBVar5 == (BIGNUM *)0x0) || (pBVar6 == (BIGNUM *)0x0)) ||
         (mont = BN_MONT_CTX_new(), mont == (BN_MONT_CTX *)0x0)) {
        uVar2 = 0;
      }
      else {
        iVar7 = BN_MONT_CTX_set(mont,m,ctx);
        if ((iVar7 == 0) ||
           (((a->neg != 0 || (iVar7 = BN_ucmp(a,m), -1 < iVar7)) &&
            (iVar7 = BN_nnmod(pBVar6,a,m,ctx), a = pBVar6, iVar7 == 0)))) {
LAB_080f3c31:
          uVar2 = 0;
        }
        else if (a->top == 0) {
          BN_set_word(r,0);
          uVar2 = 1;
        }
        else {
          iVar7 = BN_mod_mul_montgomery(pBVar6,a,&mont->RR,mont,ctx);
          if (iVar7 == 0) goto LAB_080f3c31;
          if (iVar3 < 0x2a0) {
            if (0xef < iVar3) {
              local_f0 = 5;
              goto LAB_080f3ca7;
            }
            if (0x4f < iVar3) {
              local_f0 = 4;
              goto LAB_080f3ca7;
            }
            if (0x17 < iVar3) {
              local_f0 = 3;
              goto LAB_080f3ca7;
            }
            local_f0 = 1;
          }
          else {
            local_f0 = 6;
LAB_080f3ca7:
            iVar7 = BN_mod_mul_montgomery(pBVar4,pBVar6,pBVar6,mont,ctx);
            if (iVar7 == 0) goto LAB_080f3c31;
            ppBVar10 = local_a0 + 1;
            do {
              pBVar6 = BN_CTX_get(ctx);
              *ppBVar10 = pBVar6;
              if (pBVar6 == (BIGNUM *)0x0) {
                uVar2 = 0;
                goto LAB_080f36d0;
              }
              iVar7 = BN_mod_mul_montgomery(pBVar6,ppBVar10[-1],pBVar4,mont,ctx);
              if (iVar7 == 0) goto LAB_080f3c31;
              ppBVar10 = ppBVar10 + 1;
            } while ((BIGNUM **)((int)local_a0 + (4 << ((char)local_f0 - 1U & 0x1f))) != ppBVar10);
          }
          pBVar4 = BN_value_one();
          iVar7 = BN_mod_mul_montgomery(pBVar5,pBVar4,&mont->RR,mont,ctx);
          if (iVar7 == 0) goto LAB_080f3c31;
          bVar1 = true;
          iVar3 = iVar3 + -1;
          while( true ) {
            while (iVar7 = BN_is_bit_set(p,iVar3), iVar7 != 0) {
              if (local_f0 == 1) {
                uVar2 = 1;
                iVar7 = 0;
              }
              else {
                iVar7 = 0;
                uVar2 = 1;
                local_f8 = iVar3 + -1;
                if (-1 < local_f8) {
                  iVar9 = 1;
                  iVar7 = 0;
                  do {
                    iVar8 = BN_is_bit_set(p,local_f8);
                    if (iVar8 != 0) {
                      uVar2 = uVar2 << ((char)iVar9 - (char)iVar7 & 0x1fU) | 1;
                      iVar7 = iVar9;
                    }
                    iVar9 = iVar9 + 1;
                  } while ((iVar9 != local_f0) && (local_f8 = local_f8 + -1, local_f8 != -1));
                }
              }
              iVar9 = 0;
              if (!bVar1) {
                do {
                  iVar8 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,mont,ctx);
                  if (iVar8 == 0) goto LAB_080f3c31;
                  iVar9 = iVar9 + 1;
                } while (iVar9 <= iVar7);
              }
              iVar9 = BN_mod_mul_montgomery(pBVar5,pBVar5,local_a0[(int)uVar2 >> 1],mont,ctx);
              if (iVar9 == 0) goto LAB_080f3c31;
              iVar3 = iVar3 - (iVar7 + 1);
              if (iVar3 < 0) goto LAB_080f3d78;
              bVar1 = false;
            }
            if ((!bVar1) &&
               (iVar7 = BN_mod_mul_montgomery(pBVar5,pBVar5,pBVar5,mont,ctx), iVar7 == 0))
            goto LAB_080f3c31;
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
          }
LAB_080f3d78:
          iVar3 = BN_from_montgomery(r,pBVar5,mont,ctx);
          uVar2 = (uint)(iVar3 != 0);
        }
LAB_080f36d0:
        BN_MONT_CTX_free(mont);
      }
      BN_CTX_end(ctx);
      goto LAB_080f35ad;
    }
    uVar2 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
    goto LAB_080f35ad;
  }
  if ((*(byte *)&p->flags & 4) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x10e);
    uVar2 = 0xffffffff;
    goto LAB_080f35ad;
  }
  local_ec = BN_num_bits(p);
  if (local_ec == 0) {
LAB_080f358a:
    if (((m->top == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      uVar2 = 1;
    }
    else {
      uVar2 = BN_set_word(r,1);
    }
    goto LAB_080f35ad;
  }
  BN_CTX_start(ctx);
  pBVar4 = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  local_a0[0] = pBVar5;
  if ((pBVar4 == (BIGNUM *)0x0) || (pBVar5 == (BIGNUM *)0x0)) {
LAB_080f39b8:
    uVar2 = 0;
  }
  else {
    BN_RECP_CTX_init(&local_d4);
    pBVar6 = m;
    if (m->neg != 0) {
      pBVar6 = BN_copy(pBVar4,m);
      if (pBVar6 == (BIGNUM *)0x0) goto LAB_080f39b8;
      pBVar4->neg = 0;
      pBVar6 = pBVar4;
    }
    iVar3 = BN_RECP_CTX_set(&local_d4,pBVar6,ctx);
    if ((iVar3 < 1) || (iVar3 = BN_nnmod(pBVar5,a,m,ctx), iVar3 == 0)) goto LAB_080f39b8;
    if (pBVar5->top == 0) {
      BN_set_word(r,0);
      uVar2 = 1;
    }
    else {
      if (local_ec < 0x2a0) {
        if (0xef < local_ec) {
          iVar3 = 0x10;
          local_f0 = 5;
          goto LAB_080f3a2d;
        }
        if (0x4f < local_ec) {
          iVar3 = 8;
          local_f0 = 4;
          goto LAB_080f3a2d;
        }
        if (0x17 < local_ec) {
          iVar3 = 4;
          local_f0 = 3;
          goto LAB_080f3a2d;
        }
        local_f0 = 1;
      }
      else {
        iVar3 = 0x20;
        local_f0 = 6;
LAB_080f3a2d:
        iVar7 = BN_mod_mul_reciprocal(pBVar4,pBVar5,pBVar5,&local_d4,ctx);
        if (iVar7 == 0) goto LAB_080f39b8;
        iVar7 = 1;
        do {
          pBVar5 = BN_CTX_get(ctx);
          local_a0[iVar7] = pBVar5;
          if ((pBVar5 == (BIGNUM *)0x0) ||
             (iVar9 = BN_mod_mul_reciprocal(pBVar5,local_a0[iVar7 + -1],pBVar4,&local_d4,ctx),
             iVar9 == 0)) goto LAB_080f39b8;
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar3);
      }
      iVar3 = BN_set_word(r,1);
      if (iVar3 == 0) goto LAB_080f39b8;
      bVar1 = true;
      local_ec = local_ec + -1;
      while( true ) {
        while (iVar3 = BN_is_bit_set(p,local_ec), iVar3 != 0) {
          if ((local_f0 == 1) || (iVar3 = local_ec + -1, iVar3 < 0)) {
            local_e4 = 1;
            iVar7 = 0;
          }
          else {
            local_e4 = 1;
            iVar7 = 0;
            iVar9 = 1;
            do {
              iVar8 = BN_is_bit_set(p,iVar3);
              if (iVar8 != 0) {
                local_e4 = local_e4 << ((char)iVar9 - (char)iVar7 & 0x1fU) | 1;
                iVar7 = iVar9;
              }
              iVar9 = iVar9 + 1;
            } while ((local_f0 != iVar9) && (iVar3 = iVar3 + -1, iVar3 != -1));
          }
          if (!bVar1) {
            iVar3 = 0;
            do {
              iVar9 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx);
              if (iVar9 == 0) goto LAB_080f39b8;
              iVar3 = iVar3 + 1;
            } while (iVar3 <= iVar7);
          }
          iVar3 = BN_mod_mul_reciprocal(r,r,local_a0[(int)local_e4 >> 1],&local_d4,ctx);
          if (iVar3 == 0) goto LAB_080f39b8;
          local_ec = local_ec - (iVar7 + 1);
          if (local_ec < 0) goto LAB_080f3c5e;
          bVar1 = false;
        }
        if ((!bVar1) && (iVar3 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx), iVar3 == 0))
        goto LAB_080f39b8;
        if (local_ec == 0) break;
        local_ec = local_ec + -1;
      }
LAB_080f3c5e:
      uVar2 = 1;
    }
  }
  local_fc = &local_d4;
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(local_fc);
LAB_080f35ad:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

