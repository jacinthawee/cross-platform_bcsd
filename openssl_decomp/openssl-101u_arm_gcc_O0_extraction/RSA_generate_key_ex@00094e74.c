
int RSA_generate_key_ex(RSA *rsa,int bits,BIGNUM *e,BN_GENCB *cb)

{
  int iVar1;
  BN_CTX *ctx;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  int iVar6;
  _func_1628 *p_Var7;
  int b;
  BIGNUM *pBVar8;
  bool bVar9;
  BIGNUM *local_6c;
  BIGNUM local_64;
  BIGNUM local_50;
  BIGNUM local_3c;
  
  p_Var7 = rsa->meth->rsa_keygen;
  if (p_Var7 != (_func_1628 *)0x0) {
    iVar1 = (*p_Var7)(rsa,bits,e,cb);
    return iVar1;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(4,0x81,3,"rsa_gen.c",0xf1);
    return 0;
  }
  BN_CTX_start(ctx);
  local_6c = BN_CTX_get(ctx);
  pBVar2 = BN_CTX_get(ctx);
  pBVar3 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  if (pBVar4 != (BIGNUM *)0x0) {
    iVar1 = (bits + 1) / 2;
    if (rsa->n == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->n = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->d == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->d = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->e == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->e = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->p == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->p = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->q == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->q = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->dmp1 == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->dmp1 = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->dmq1 == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->dmq1 = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    if (rsa->iqmp == (BIGNUM *)0x0) {
      pBVar4 = BN_new();
      rsa->iqmp = pBVar4;
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_00095004;
    }
    BN_copy(rsa->e,e);
    b = 0;
    do {
      iVar5 = BN_generate_prime_ex(rsa->p,iVar1,0,(BIGNUM *)0x0,(BIGNUM *)0x0,cb);
      if (iVar5 == 0) break;
      pBVar8 = rsa->p;
      pBVar4 = BN_value_one();
      iVar5 = BN_sub(pBVar3,pBVar8,pBVar4);
      if ((iVar5 == 0) || (iVar5 = BN_gcd(pBVar2,pBVar3,rsa->e,ctx), iVar5 == 0)) break;
      if ((pBVar2->top == 1) && ((*pBVar2->d == 1 && (pBVar2->neg == 0)))) {
        iVar5 = BN_GENCB_call(cb,3,0);
        if (iVar5 != 0) {
          goto LAB_00094f9a;
        }
        break;
      }
      iVar5 = BN_GENCB_call(cb,2,b);
      b = b + 1;
    } while (iVar5 != 0);
  }
  goto LAB_00095004;
  while( true ) {
    iVar5 = BN_GENCB_call(cb,2,b);
    b = b + 1;
    if (iVar5 == 0) break;
LAB_00094f9a:
    iVar5 = 3;
    while( true ) {
      iVar6 = BN_generate_prime_ex(rsa->q,bits - iVar1,0,(BIGNUM *)0x0,(BIGNUM *)0x0,cb);
      if (iVar6 == 0) goto LAB_00095004;
      iVar6 = BN_cmp(rsa->p,rsa->q);
      if (iVar6 != 0) break;
      iVar5 = iVar5 + -1;
      if (iVar5 == 0) {
        ERR_put_error(4,0x81,0x78,"rsa_gen.c",0xaf);
        goto LAB_0009501e;
      }
    }
    pBVar8 = rsa->q;
    pBVar4 = BN_value_one();
    iVar5 = BN_sub(pBVar3,pBVar8,pBVar4);
    if ((iVar5 == 0) || (iVar5 = BN_gcd(pBVar2,pBVar3,rsa->e,ctx), iVar5 == 0)) break;
    if ((pBVar2->top == 1) &&
       ((pBVar4 = (BIGNUM *)*pBVar2->d, pBVar4 == (BIGNUM *)0x1 &&
        (pBVar8 = (BIGNUM *)pBVar2->neg, pBVar8 == (BIGNUM *)0x0)))) {
      iVar1 = BN_GENCB_call(cb,3,1);
      if (iVar1 != 0) {
        iVar1 = BN_cmp(rsa->p,rsa->q);
        bVar9 = iVar1 < 0;
        if (bVar9) {
          pBVar8 = rsa->p;
          pBVar4 = rsa->q;
        }
        if (bVar9) {
          rsa->q = pBVar8;
        }
        if (bVar9) {
          rsa->p = pBVar4;
        }
        iVar1 = BN_mul(rsa->n,rsa->p,rsa->q,ctx);
        if (iVar1 != 0) {
          pBVar8 = rsa->p;
          pBVar4 = BN_value_one();
          iVar1 = BN_sub(pBVar2,pBVar8,pBVar4);
          if (iVar1 != 0) {
            pBVar8 = rsa->q;
            pBVar4 = BN_value_one();
            iVar1 = BN_sub(pBVar3,pBVar8,pBVar4);
            if ((iVar1 != 0) && (iVar1 = BN_mul(local_6c,pBVar2,pBVar3,ctx), iVar1 != 0)) {
              if (-1 < rsa->flags << 0x17) {
                local_64.d = local_6c->d;
                local_64.top = local_6c->top;
                local_64.dmax = local_6c->dmax;
                local_64.neg = local_6c->neg;
                local_64.flags = local_64.flags & 1U | local_6c->flags & 0xfffffffeU | 6;
                local_6c = &local_64;
              }
              pBVar4 = BN_mod_inverse(rsa->d,rsa->e,local_6c,ctx);
              if (pBVar4 != (BIGNUM *)0x0) {
                if (rsa->flags << 0x17 < 0) {
                  pBVar4 = rsa->d;
                }
                else {
                  pBVar8 = rsa->d;
                  pBVar4 = &local_50;
                  local_50.d = pBVar8->d;
                  local_50.top = pBVar8->top;
                  local_50.dmax = pBVar8->dmax;
                  local_50.neg = pBVar8->neg;
                  local_50.flags = local_50.flags & 1U | pBVar8->flags & 0xfffffffeU | 6;
                }
                iVar1 = BN_div((BIGNUM *)0x0,rsa->dmp1,pBVar4,pBVar2,ctx);
                if ((iVar1 != 0) &&
                   (iVar1 = BN_div((BIGNUM *)0x0,rsa->dmq1,pBVar4,pBVar3,ctx), iVar1 != 0)) {
                  if (rsa->flags << 0x17 < 0) {
                    pBVar2 = rsa->p;
                  }
                  else {
                    pBVar3 = rsa->p;
                    pBVar2 = &local_3c;
                    local_3c.d = pBVar3->d;
                    local_3c.top = pBVar3->top;
                    local_3c.dmax = pBVar3->dmax;
                    local_3c.neg = pBVar3->neg;
                    local_3c.flags = pBVar3->flags & 0xfffffffeU | local_3c.flags & 1U | 6;
                  }
                  pBVar2 = BN_mod_inverse(rsa->iqmp,rsa->q,pBVar2,ctx);
                  if (pBVar2 != (BIGNUM *)0x0) {
                    iVar5 = 1;
                    goto LAB_0009501e;
                  }
                }
              }
            }
          }
        }
      }
      break;
    }
  }
LAB_00095004:
  iVar5 = 0;
  ERR_put_error(4,0x81,3,"rsa_gen.c",0xf1);
LAB_0009501e:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return iVar5;
}

