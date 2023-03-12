
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  bool bVar1;
  uint uVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BN_MONT_CTX *mont;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  BIGNUM **ppBVar10;
  int in_GS_OFFSET;
  BN_RECP_CTX *local_fc;
  uint local_f8;
  uint local_f4;
  int local_f0;
  int local_e8;
  BN_RECP_CTX local_d4;
  BIGNUM *local_a0 [32];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((0 < m->top) && ((*(byte *)m->d & 1) != 0)) {
    if ((a->top == 1) && (a->neg == 0)) {
      if ((*(byte *)&p->flags & 4) == 0) {
        uVar2 = BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
        goto LAB_080f5a41;
      }
    }
    else if ((*(byte *)&p->flags & 4) == 0) {
      local_e8 = BN_num_bits(p);
      if (local_e8 == 0) goto LAB_080f5a30;
      BN_CTX_start(ctx);
      pBVar3 = BN_CTX_get(ctx);
      pBVar4 = BN_CTX_get(ctx);
      pBVar5 = BN_CTX_get(ctx);
      local_a0[0] = pBVar5;
      if (((pBVar3 == (BIGNUM *)0x0 || pBVar4 == (BIGNUM *)0x0) || (pBVar5 == (BIGNUM *)0x0)) ||
         (mont = BN_MONT_CTX_new(), mont == (BN_MONT_CTX *)0x0)) {
        uVar2 = 0;
      }
      else {
        iVar6 = BN_MONT_CTX_set(mont,m,ctx);
        if ((iVar6 == 0) ||
           (((a->neg != 0 || (iVar6 = BN_ucmp(a,m), -1 < iVar6)) &&
            (iVar6 = BN_nnmod(pBVar5,a,m,ctx), a = pBVar5, iVar6 == 0)))) {
LAB_080f5e70:
          uVar2 = 0;
        }
        else if (a->top == 0) {
          BN_set_word(r,0);
          uVar2 = 1;
        }
        else {
          iVar6 = BN_mod_mul_montgomery(pBVar5,a,&mont->RR,mont,ctx);
          if (iVar6 == 0) goto LAB_080f5e70;
          if (local_e8 < 0x2a0) {
            if (0xef < local_e8) {
              local_f0 = 5;
              goto LAB_080f5ef1;
            }
            if (0x4f < local_e8) {
              local_f0 = 4;
              goto LAB_080f5ef1;
            }
            if (0x17 < local_e8) {
              local_f0 = 3;
              goto LAB_080f5ef1;
            }
            local_f0 = 1;
          }
          else {
            local_f0 = 6;
LAB_080f5ef1:
            iVar6 = BN_mod_mul_montgomery(pBVar3,pBVar5,pBVar5,mont,ctx);
            if (iVar6 == 0) goto LAB_080f5e70;
            ppBVar10 = local_a0 + 1;
            do {
              pBVar5 = BN_CTX_get(ctx);
              *ppBVar10 = pBVar5;
              if (pBVar5 == (BIGNUM *)0x0) {
                uVar2 = 0;
                goto LAB_080f5b60;
              }
              iVar6 = BN_mod_mul_montgomery(pBVar5,ppBVar10[-1],pBVar3,mont,ctx);
              if (iVar6 == 0) goto LAB_080f5e70;
              ppBVar10 = ppBVar10 + 1;
            } while ((BIGNUM **)((int)local_a0 + (4 << ((char)local_f0 - 1U & 0x1f))) != ppBVar10);
          }
          pBVar3 = BN_value_one();
          iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar3,&mont->RR,mont,ctx);
          if (iVar6 == 0) goto LAB_080f5e70;
          bVar1 = true;
          local_e8 = local_e8 + -1;
          while( true ) {
            while (iVar6 = BN_is_bit_set(p,local_e8), iVar6 != 0) {
              local_f4 = 1;
              iVar6 = 0;
              if ((local_f0 != 1) && (iVar9 = local_e8 + -1, -1 < iVar9)) {
                iVar8 = 1;
                do {
                  iVar7 = BN_is_bit_set(p,iVar9);
                  if (iVar7 != 0) {
                    local_f4 = local_f4 << ((char)iVar8 - (char)iVar6 & 0x1fU) | 1;
                    iVar6 = iVar8;
                  }
                  iVar8 = iVar8 + 1;
                } while ((iVar8 != local_f0) && (iVar9 = iVar9 + -1, iVar9 != -1));
              }
              iVar9 = 0;
              if (!bVar1) {
                do {
                  iVar8 = BN_mod_mul_montgomery(pBVar4,pBVar4,pBVar4,mont,ctx);
                  if (iVar8 == 0) goto LAB_080f5e70;
                  iVar9 = iVar9 + 1;
                } while (iVar9 <= iVar6);
              }
              iVar9 = BN_mod_mul_montgomery(pBVar4,pBVar4,local_a0[(int)local_f4 >> 1],mont,ctx);
              if (iVar9 == 0) goto LAB_080f5e70;
              local_e8 = local_e8 - (iVar6 + 1);
              if (local_e8 < 0) goto LAB_080f5f99;
              bVar1 = false;
            }
            if ((!bVar1) &&
               (iVar6 = BN_mod_mul_montgomery(pBVar4,pBVar4,pBVar4,mont,ctx), iVar6 == 0))
            goto LAB_080f5e70;
            if (local_e8 == 0) break;
            local_e8 = local_e8 + -1;
          }
LAB_080f5f99:
          iVar6 = BN_from_montgomery(r,pBVar4,mont,ctx);
          uVar2 = (uint)(iVar6 != 0);
        }
LAB_080f5b60:
        BN_MONT_CTX_free(mont);
      }
      BN_CTX_end(ctx);
      goto LAB_080f5a41;
    }
    uVar2 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
    goto LAB_080f5a41;
  }
  if ((*(byte *)&p->flags & 4) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x108);
    uVar2 = 0xffffffff;
    goto LAB_080f5a41;
  }
  iVar6 = BN_num_bits(p);
  if (iVar6 == 0) {
LAB_080f5a30:
    uVar2 = BN_set_word(r,1);
    goto LAB_080f5a41;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  local_a0[0] = pBVar4;
  if ((pBVar3 == (BIGNUM *)0x0) || (pBVar4 == (BIGNUM *)0x0)) {
LAB_080f5be0:
    uVar2 = 0;
  }
  else {
    BN_RECP_CTX_init(&local_d4);
    pBVar5 = m;
    if (m->neg != 0) {
      pBVar5 = BN_copy(pBVar3,m);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_080f5be0;
      pBVar3->neg = 0;
      pBVar5 = pBVar3;
    }
    iVar9 = BN_RECP_CTX_set(&local_d4,pBVar5,ctx);
    if ((iVar9 < 1) || (iVar9 = BN_nnmod(pBVar4,a,m,ctx), iVar9 == 0)) goto LAB_080f5be0;
    if (pBVar4->top == 0) {
      BN_set_word(r,0);
      uVar2 = 1;
    }
    else {
      if (iVar6 < 0x2a0) {
        if (0xef < iVar6) {
          iVar9 = 0x10;
          local_f0 = 5;
          goto LAB_080f5c95;
        }
        if (0x4f < iVar6) {
          iVar9 = 8;
          local_f0 = 4;
          goto LAB_080f5c95;
        }
        if (0x17 < iVar6) {
          iVar9 = 4;
          local_f0 = 3;
          goto LAB_080f5c95;
        }
        local_f0 = 1;
      }
      else {
        iVar9 = 0x20;
        local_f0 = 6;
LAB_080f5c95:
        iVar8 = BN_mod_mul_reciprocal(pBVar3,pBVar4,pBVar4,&local_d4,ctx);
        if (iVar8 == 0) goto LAB_080f5be0;
        iVar8 = 1;
        do {
          pBVar4 = BN_CTX_get(ctx);
          local_a0[iVar8] = pBVar4;
          if ((pBVar4 == (BIGNUM *)0x0) ||
             (iVar7 = BN_mod_mul_reciprocal(pBVar4,local_a0[iVar8 + -1],pBVar3,&local_d4,ctx),
             iVar7 == 0)) goto LAB_080f5be0;
          iVar8 = iVar8 + 1;
        } while (iVar8 < iVar9);
      }
      iVar9 = BN_set_word(r,1);
      if (iVar9 == 0) goto LAB_080f5be0;
      bVar1 = true;
      local_f4 = iVar6 + -1;
      while( true ) {
        while (iVar6 = BN_is_bit_set(p,local_f4), iVar6 != 0) {
          local_f8 = 1;
          iVar6 = 0;
          if ((local_f0 != 1) && (iVar9 = local_f4 + -1, -1 < iVar9)) {
            iVar8 = 1;
            do {
              iVar7 = BN_is_bit_set(p,iVar9);
              if (iVar7 != 0) {
                local_f8 = local_f8 << ((char)iVar8 - (char)iVar6 & 0x1fU) | 1;
                iVar6 = iVar8;
              }
              iVar8 = iVar8 + 1;
            } while ((iVar8 != local_f0) && (iVar9 = iVar9 + -1, iVar9 != -1));
          }
          iVar9 = 0;
          if (!bVar1) {
            do {
              iVar8 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx);
              if (iVar8 == 0) goto LAB_080f5be0;
              iVar9 = iVar9 + 1;
            } while (iVar9 <= iVar6);
          }
          iVar9 = BN_mod_mul_reciprocal(r,r,local_a0[(int)local_f8 >> 1],&local_d4,ctx);
          if (iVar9 == 0) goto LAB_080f5be0;
          local_f4 = local_f4 - (iVar6 + 1);
          if ((int)local_f4 < 0) goto LAB_080f5ea6;
          bVar1 = false;
        }
        if ((!bVar1) && (iVar6 = BN_mod_mul_reciprocal(r,r,r,&local_d4,ctx), iVar6 == 0))
        goto LAB_080f5be0;
        if (local_f4 == 0) break;
        local_f4 = local_f4 + -1;
      }
LAB_080f5ea6:
      uVar2 = 1;
    }
  }
  local_fc = &local_d4;
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(local_fc);
LAB_080f5a41:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

