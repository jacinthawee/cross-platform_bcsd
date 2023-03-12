
int BN_mod_exp(BIGNUM *r,BIGNUM *a,BIGNUM *p,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  BN_MONT_CTX *mont;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  BIGNUM **ppBVar10;
  uint uVar11;
  uint uVar12;
  int local_ec;
  uint local_e8;
  int local_e4;
  BN_RECP_CTX BStack_dc;
  BIGNUM *local_a8 [33];
  
  if ((0 < m->top) && ((int)(*m->d << 0x1f) < 0)) {
    if ((a->top == 1) && (a->neg == 0)) {
      if ((p->flags & 4U) == 0) {
        iVar1 = BN_mod_exp_mont_word(r,*a->d,p,m,ctx,(BN_MONT_CTX *)0x0);
        return iVar1;
      }
LAB_00087556:
      iVar1 = BN_mod_exp_mont_consttime(r,a,p,m,ctx,(BN_MONT_CTX *)0x0);
      return iVar1;
    }
    if (p->flags << 0x1d < 0) goto LAB_00087556;
    iVar1 = BN_num_bits(p);
    if (iVar1 == 0) goto LAB_00087582;
    BN_CTX_start(ctx);
    pBVar2 = BN_CTX_get(ctx);
    pBVar3 = BN_CTX_get(ctx);
    pBVar4 = BN_CTX_get(ctx);
    local_a8[0] = pBVar4;
    if (((pBVar3 == (BIGNUM *)0x0 || pBVar2 == (BIGNUM *)0x0) || (pBVar4 == (BIGNUM *)0x0)) ||
       (mont = BN_MONT_CTX_new(), mont == (BN_MONT_CTX *)0x0)) {
      iVar1 = 0;
      goto LAB_0008780a;
    }
    iVar5 = BN_MONT_CTX_set(mont,m,ctx);
    if ((iVar5 == 0) ||
       (((a->neg != 0 || (iVar5 = BN_ucmp(a,m), -1 < iVar5)) &&
        (iVar5 = BN_nnmod(pBVar4,a,m,ctx), a = pBVar4, iVar5 == 0)))) {
LAB_00087968:
      iVar1 = 0;
    }
    else if (a->top == 0) {
      iVar1 = 1;
      BN_set_word(r,0);
    }
    else {
      iVar5 = BN_mod_mul_montgomery(pBVar4,a,&mont->RR,mont,ctx);
      if (iVar5 == 0) goto LAB_00087968;
      if (iVar1 < 0x2a0) {
        if (0xef < iVar1) {
          local_e8 = 5;
          goto LAB_000879ac;
        }
        if (0x4f < iVar1) {
          local_e8 = 4;
          goto LAB_000879ac;
        }
        if (0x17 < iVar1) {
          local_e8 = 3;
          goto LAB_000879ac;
        }
        local_e8 = 1;
      }
      else {
        local_e8 = 6;
LAB_000879ac:
        iVar5 = BN_mod_mul_montgomery(pBVar2,pBVar4,pBVar4,mont,ctx);
        if (iVar5 == 0) goto LAB_00087968;
        iVar5 = 1;
        ppBVar10 = local_a8;
        do {
          iVar5 = iVar5 + 1;
          pBVar4 = BN_CTX_get(ctx);
          ppBVar10[1] = pBVar4;
          if ((pBVar4 == (BIGNUM *)0x0) ||
             (iVar6 = BN_mod_mul_montgomery(pBVar4,*ppBVar10,pBVar2,mont,ctx), iVar6 == 0))
          goto LAB_00087968;
          ppBVar10 = ppBVar10 + 1;
        } while (iVar5 < 1 << (local_e8 - 1 & 0xff));
      }
      pBVar2 = BN_value_one();
      iVar5 = BN_mod_mul_montgomery(pBVar3,pBVar2,&mont->RR,mont,ctx);
      if (iVar5 == 0) goto LAB_00087968;
      iVar1 = iVar1 + -1;
      iVar5 = 1;
      while( true ) {
        while (iVar6 = BN_is_bit_set(p,iVar1), iVar6 == 0) {
          if ((iVar5 == 0) &&
             (iVar6 = BN_mod_mul_montgomery(pBVar3,pBVar3,pBVar3,mont,ctx), iVar6 == 0))
          goto LAB_00087968;
          if (iVar1 == 0) goto LAB_00087a3a;
          iVar1 = iVar1 + -1;
        }
        if (local_e8 == 1) {
          uVar11 = 0;
          uVar12 = local_e8;
        }
        else {
          uVar12 = 1;
          if (iVar1 + -1 < 0) {
            uVar11 = 0;
          }
          else {
            uVar11 = 0;
            uVar9 = 1;
            iVar6 = iVar1 + -1;
            iVar7 = iVar1 + -2;
            do {
              iVar6 = BN_is_bit_set(p,iVar6);
              if (iVar6 != 0) {
                uVar12 = uVar12 << (uVar9 - uVar11 & 0xff) | 1;
                uVar11 = uVar9;
              }
              uVar9 = uVar9 + 1;
              iVar8 = iVar7 + -1;
            } while ((iVar7 != iVar1 - local_e8) && (iVar6 = iVar7, iVar7 = iVar8, iVar8 != -2));
          }
        }
        if (iVar5 == 0) {
          do {
            iVar5 = iVar5 + 1;
            iVar6 = BN_mod_mul_montgomery(pBVar3,pBVar3,pBVar3,mont,ctx);
            if (iVar6 == 0) goto LAB_00087968;
          } while (iVar5 <= (int)uVar11);
        }
        iVar5 = BN_mod_mul_montgomery(pBVar3,pBVar3,local_a8[(int)uVar12 >> 1],mont,ctx);
        if (iVar5 == 0) goto LAB_00087968;
        iVar1 = iVar1 + ~uVar11;
        if (iVar1 < 0) break;
        iVar5 = 0;
      }
LAB_00087a3a:
      iVar1 = BN_from_montgomery(r,pBVar3,mont,ctx);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
    }
    BN_MONT_CTX_free(mont);
LAB_0008780a:
    BN_CTX_end(ctx);
    return iVar1;
  }
  if ((p->flags & 4U) != 0) {
    ERR_put_error(3,0x7d,0x42,"bn_exp.c",0x10e);
    return -1;
  }
  local_ec = BN_num_bits(p);
  if (local_ec == 0) {
LAB_00087582:
    if (((m->top == 1) && (*m->d == 1)) && (m->neg == 0)) {
      BN_set_word(r,0);
      return 1;
    }
    iVar1 = BN_set_word(r,1);
    return iVar1;
  }
  BN_CTX_start(ctx);
  pBVar2 = BN_CTX_get(ctx);
  pBVar3 = BN_CTX_get(ctx);
  local_a8[0] = pBVar3;
  if ((pBVar2 != (BIGNUM *)0x0) && (pBVar3 != (BIGNUM *)0x0)) {
    BN_RECP_CTX_init(&BStack_dc);
    if (m->neg == 0) {
      iVar1 = BN_RECP_CTX_set(&BStack_dc,m,ctx);
    }
    else {
      pBVar4 = BN_copy(pBVar2,m);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_0008775a;
      pBVar2->neg = 0;
      iVar1 = BN_RECP_CTX_set(&BStack_dc,pBVar2,ctx);
    }
    if ((0 < iVar1) && (iVar1 = BN_nnmod(pBVar3,a,m,ctx), iVar1 != 0)) {
      if (pBVar3->top == 0) {
        iVar1 = 1;
        BN_set_word(r,0);
        goto LAB_0008775c;
      }
      if (local_ec < 0x2a0) {
        if (0xef < local_ec) {
          iVar1 = 0x10;
          local_e8 = 5;
          goto LAB_0008762c;
        }
        if (0x4f < local_ec) {
          iVar1 = 8;
          local_e8 = 4;
          goto LAB_0008762c;
        }
        if (0x17 < local_ec) {
          iVar1 = 4;
          local_e8 = 3;
          goto LAB_0008762c;
        }
        local_e8 = 1;
      }
      else {
        iVar1 = 0x20;
        local_e8 = 6;
LAB_0008762c:
        iVar5 = BN_mod_mul_reciprocal(pBVar2,pBVar3,pBVar3,&BStack_dc,ctx);
        if (iVar5 == 0) goto LAB_0008775a;
        iVar5 = 1;
        ppBVar10 = local_a8;
        do {
          iVar5 = iVar5 + 1;
          pBVar3 = BN_CTX_get(ctx);
          ppBVar10[1] = pBVar3;
          if ((pBVar3 == (BIGNUM *)0x0) ||
             (iVar6 = BN_mod_mul_reciprocal(pBVar3,*ppBVar10,pBVar2,&BStack_dc,ctx), iVar6 == 0))
          goto LAB_0008775a;
          ppBVar10 = ppBVar10 + 1;
        } while (iVar5 < iVar1);
      }
      iVar1 = BN_set_word(r,1);
      if (iVar1 != 0) {
        local_ec = local_ec + -1;
        local_e4 = 1;
        while( true ) {
          while (iVar1 = BN_is_bit_set(p,local_ec), iVar1 == 0) {
            if ((local_e4 == 0) && (iVar1 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx), iVar1 == 0)
               ) goto LAB_0008775a;
            if (local_ec == 0) goto LAB_0008797c;
            local_ec = local_ec + -1;
          }
          if (local_e8 == 1) {
            uVar11 = 0;
            uVar12 = local_e8;
          }
          else if (local_ec + -1 < 0) {
            uVar11 = 0;
            uVar12 = 1;
          }
          else {
            uVar12 = 1;
            uVar9 = 1;
            uVar11 = 0;
            iVar1 = local_ec + -1;
            iVar5 = local_ec + -2;
            do {
              iVar1 = BN_is_bit_set(p,iVar1);
              if (iVar1 != 0) {
                uVar12 = uVar12 << (uVar9 - uVar11 & 0xff) | 1;
                uVar11 = uVar9;
              }
              uVar9 = uVar9 + 1;
              iVar6 = iVar5 + -1;
            } while ((iVar5 != local_ec - local_e8) && (iVar1 = iVar5, iVar5 = iVar6, iVar6 != -2));
          }
          if (local_e4 == 0) {
            do {
              local_e4 = local_e4 + 1;
              iVar1 = BN_mod_mul_reciprocal(r,r,r,&BStack_dc,ctx);
              if (iVar1 == 0) goto LAB_0008775a;
            } while (local_e4 <= (int)uVar11);
          }
          iVar1 = BN_mod_mul_reciprocal(r,r,local_a8[(int)uVar12 >> 1],&BStack_dc,ctx);
          if (iVar1 == 0) goto LAB_0008775a;
          local_ec = local_ec + ~uVar11;
          if (local_ec < 0) break;
          local_e4 = 0;
        }
LAB_0008797c:
        iVar1 = 1;
        goto LAB_0008775c;
      }
    }
  }
LAB_0008775a:
  iVar1 = 0;
LAB_0008775c:
  BN_CTX_end(ctx);
  BN_RECP_CTX_free(&BStack_dc);
  return iVar1;
}

