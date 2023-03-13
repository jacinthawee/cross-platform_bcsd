
int RSA_generate_key_ex(RSA *rsa,int bits,BIGNUM *e,BN_GENCB *cb)

{
  _func_1628 *p_Var1;
  BIGNUM *pBVar2;
  int iVar3;
  BN_CTX *ctx;
  BIGNUM *pBVar4;
  BIGNUM *r;
  BIGNUM *pBVar5;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  int iVar8;
  BIGNUM *local_64;
  BIGNUM local_5c;
  BIGNUM local_48;
  BIGNUM local_34;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  p_Var1 = rsa->meth->rsa_keygen;
  if (p_Var1 != (_func_1628 *)0x0) {
    iVar3 = (*p_Var1)(rsa,bits,e,cb);
    goto LAB_08108d51;
  }
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    ERR_put_error(4,0x81,3,"rsa_gen.c",0xf1);
    iVar3 = 0;
    goto LAB_08108d51;
  }
  BN_CTX_start(ctx);
  local_64 = BN_CTX_get(ctx);
  pBVar4 = BN_CTX_get(ctx);
  r = BN_CTX_get(ctx);
  pBVar5 = BN_CTX_get(ctx);
  if (pBVar5 != (BIGNUM *)0x0) {
    iVar3 = (bits + 1) / 2;
    if (rsa->n == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->n = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->d == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->d = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->e == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->e = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->p == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->p = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->q == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->q = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->dmp1 == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->dmp1 = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->dmq1 == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->dmq1 = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    if (rsa->iqmp == (BIGNUM *)0x0) {
      pBVar5 = BN_new();
      rsa->iqmp = pBVar5;
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_08108fb0;
    }
    BN_copy(rsa->e,e);
    iVar8 = 0;
    do {
      iVar6 = BN_generate_prime_ex(rsa->p,iVar3,0,(BIGNUM *)0x0,(BIGNUM *)0x0,cb);
      if (iVar6 == 0) break;
      pBVar5 = BN_value_one();
      iVar6 = BN_sub(r,rsa->p,pBVar5);
      if ((iVar6 == 0) || (iVar6 = BN_gcd(pBVar4,r,rsa->e,ctx), iVar6 == 0)) break;
      if ((pBVar4->top == 1) && ((*pBVar4->d == 1 && (pBVar4->neg == 0)))) {
        iVar6 = BN_GENCB_call(cb,3,0);
        if (iVar6 != 0) {
          goto LAB_08108f1b;
        }
        break;
      }
      iVar6 = BN_GENCB_call(cb,2,iVar8);
      iVar8 = iVar8 + 1;
    } while (iVar6 != 0);
  }
LAB_08108fb0:
  iVar6 = 0xf1;
  iVar8 = 3;
LAB_08108fbf:
  iVar3 = 0;
  ERR_put_error(4,0x81,iVar8,"rsa_gen.c",iVar6);
LAB_08108fd0:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
LAB_08108d51:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
  while( true ) {
    iVar6 = BN_GENCB_call(cb,2,iVar8);
    iVar8 = iVar8 + 1;
    if (iVar6 == 0) break;
LAB_08108f1b:
    iVar6 = 3;
    while( true ) {
      iVar7 = BN_generate_prime_ex(rsa->q,bits - iVar3,0,(BIGNUM *)0x0,(BIGNUM *)0x0,cb);
      if (iVar7 == 0) goto LAB_08108fb0;
      iVar7 = BN_cmp(rsa->p,rsa->q);
      if (iVar7 != 0) break;
      iVar6 = iVar6 + -1;
      if (iVar6 == 0) {
        iVar6 = 0xaf;
        iVar8 = 0x78;
        goto LAB_08108fbf;
      }
    }
    pBVar5 = BN_value_one();
    iVar6 = BN_sub(r,rsa->q,pBVar5);
    if ((iVar6 == 0) || (iVar6 = BN_gcd(pBVar4,r,rsa->e,ctx), iVar6 == 0)) break;
    if ((pBVar4->top == 1) && ((*pBVar4->d == 1 && (pBVar4->neg == 0)))) {
      iVar3 = BN_GENCB_call(cb,3,1);
      if (iVar3 != 0) {
        iVar3 = BN_cmp(rsa->p,rsa->q);
        if (iVar3 < 0) {
          pBVar5 = rsa->q;
          rsa->q = rsa->p;
          rsa->p = pBVar5;
        }
        iVar3 = BN_mul(rsa->n,rsa->p,rsa->q,ctx);
        if (iVar3 != 0) {
          pBVar5 = BN_value_one();
          iVar3 = BN_sub(pBVar4,rsa->p,pBVar5);
          if (iVar3 != 0) {
            pBVar5 = BN_value_one();
            iVar3 = BN_sub(r,rsa->q,pBVar5);
            if ((iVar3 != 0) && (iVar3 = BN_mul(local_64,pBVar4,r,ctx), iVar3 != 0)) {
              if ((*(byte *)((int)&rsa->flags + 1) & 1) == 0) {
                local_5c.d = local_64->d;
                local_5c.top = local_64->top;
                local_5c.dmax = local_64->dmax;
                local_5c.neg = local_64->neg;
                local_5c.flags = local_64->flags & 0xfffffffeU | local_5c.flags & 1U | 6;
                local_64 = &local_5c;
              }
              pBVar5 = BN_mod_inverse(rsa->d,rsa->e,local_64,ctx);
              if (pBVar5 != (BIGNUM *)0x0) {
                if ((*(byte *)((int)&rsa->flags + 1) & 1) == 0) {
                  pBVar2 = rsa->d;
                  pBVar5 = &local_48;
                  local_48.d = pBVar2->d;
                  local_48.top = pBVar2->top;
                  local_48.dmax = pBVar2->dmax;
                  local_48.neg = pBVar2->neg;
                  local_48.flags = pBVar2->flags & 0xfffffffeU | local_48.flags & 1U | 6;
                }
                else {
                  pBVar5 = rsa->d;
                }
                iVar3 = BN_div((BIGNUM *)0x0,rsa->dmp1,pBVar5,pBVar4,ctx);
                if ((iVar3 != 0) &&
                   (iVar3 = BN_div((BIGNUM *)0x0,rsa->dmq1,pBVar5,r,ctx), iVar3 != 0)) {
                  if ((*(byte *)((int)&rsa->flags + 1) & 1) == 0) {
                    pBVar4 = rsa->p;
                    local_34.d = pBVar4->d;
                    local_34.top = pBVar4->top;
                    local_34.dmax = pBVar4->dmax;
                    local_34.neg = pBVar4->neg;
                    local_34.flags = pBVar4->flags & 0xfffffffeU | local_34.flags & 1U | 6;
                    pBVar4 = &local_34;
                  }
                  else {
                    pBVar4 = rsa->p;
                  }
                  pBVar4 = BN_mod_inverse(rsa->iqmp,rsa->q,pBVar4,ctx);
                  if (pBVar4 != (BIGNUM *)0x0) {
                    iVar3 = 1;
                    goto LAB_08108fd0;
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
  goto LAB_08108fb0;
}

