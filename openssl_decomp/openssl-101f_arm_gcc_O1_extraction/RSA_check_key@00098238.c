
int RSA_check_key(RSA *param_1)

{
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *dv;
  BIGNUM *r_01;
  BIGNUM *r_02;
  BN_CTX *ctx;
  int iVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  
  if ((((param_1->p == (BIGNUM *)0x0) || (param_1->q == (BIGNUM *)0x0)) ||
      (param_1->n == (BIGNUM *)0x0)) ||
     ((param_1->e == (BIGNUM *)0x0 || (param_1->d == (BIGNUM *)0x0)))) {
    ERR_put_error(4,0x7b,0x93,"rsa_chk.c",0x41);
    return 0;
  }
  r = BN_new();
  r_00 = BN_new();
  dv = BN_new();
  r_01 = BN_new();
  r_02 = BN_new();
  ctx = BN_CTX_new();
  if (r_00 == (BIGNUM *)0x0 || r == (BIGNUM *)0x0) {
    iVar1 = -1;
    iVar2 = -1;
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4f);
    if (r == (BIGNUM *)0x0) goto LAB_000982b6;
  }
  else if ((r_01 == (BIGNUM *)0x0 || dv == (BIGNUM *)0x0) ||
          (ctx == (BN_CTX *)0x0 || r_02 == (BIGNUM *)0x0)) {
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4f);
    iVar2 = -1;
  }
  else {
    iVar1 = BN_is_prime_ex(param_1->p,0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
    if (iVar1 != 1) {
      iVar2 = iVar1;
      if (iVar1 != 0) goto LAB_000982b0;
      ERR_put_error(4,0x7b,0x80,"rsa_chk.c",0x5a);
    }
    iVar2 = BN_is_prime_ex(param_1->q,0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
    if (iVar2 != 1) {
      if (iVar2 != 0) goto LAB_000982b0;
      ERR_put_error(4,0x7b,0x81,"rsa_chk.c",100);
      iVar1 = iVar2;
    }
    iVar2 = iVar1;
    iVar1 = BN_mul(r,param_1->p,param_1->q,ctx);
    if (iVar1 != 0) {
      iVar1 = BN_cmp(r,param_1->n);
      if (iVar1 != 0) {
        iVar2 = 0;
        ERR_put_error(4,0x7b,0x7f,"rsa_chk.c",0x6e);
      }
      pBVar4 = param_1->p;
      pBVar3 = BN_value_one();
      iVar1 = BN_sub(r,pBVar4,pBVar3);
      if (iVar1 != 0) {
        pBVar4 = param_1->q;
        pBVar3 = BN_value_one();
        iVar1 = BN_sub(r_00,pBVar4,pBVar3);
        if ((((iVar1 != 0) && (iVar1 = BN_mul(r_01,r,r_00,ctx), iVar1 != 0)) &&
            (iVar1 = BN_gcd(r_02,r,r_00,ctx), iVar1 != 0)) &&
           ((iVar1 = BN_div(dv,(BIGNUM *)0x0,r_01,r_02,ctx), iVar1 != 0 &&
            (iVar1 = BN_mod_mul(r,param_1->d,param_1->e,dv,ctx), iVar1 != 0)))) {
          if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
            iVar2 = 0;
            ERR_put_error(4,0x7b,0x7b,"rsa_chk.c",0x86);
          }
          if (((param_1->dmp1 == (BIGNUM *)0x0) || (param_1->dmq1 == (BIGNUM *)0x0)) ||
             (param_1->iqmp == (BIGNUM *)0x0)) goto LAB_000982b0;
          pBVar4 = param_1->p;
          pBVar3 = BN_value_one();
          iVar1 = BN_sub(r,pBVar4,pBVar3);
          if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,r_00,param_1->d,r,ctx), iVar1 != 0)) {
            iVar1 = BN_cmp(r_00,param_1->dmp1);
            if (iVar1 != 0) {
              iVar2 = 0;
              ERR_put_error(4,0x7b,0x7c,"rsa_chk.c",0x96);
            }
            pBVar4 = param_1->q;
            pBVar3 = BN_value_one();
            iVar1 = BN_sub(r,pBVar4,pBVar3);
            if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,r_00,param_1->d,r,ctx), iVar1 != 0)) {
              iVar1 = BN_cmp(r_00,param_1->dmq1);
              if (iVar1 != 0) {
                iVar2 = 0;
                ERR_put_error(4,0x7b,0x7d,"rsa_chk.c",0xa4);
              }
              pBVar3 = BN_mod_inverse(r,param_1->q,param_1->p,ctx);
              if (pBVar3 != (BIGNUM *)0x0) {
                iVar1 = BN_cmp(r,param_1->iqmp);
                if (iVar1 != 0) {
                  iVar2 = 0;
                  ERR_put_error(4,0x7b,0x7e,"rsa_chk.c",0xb2);
                }
                goto LAB_000982b0;
              }
            }
          }
        }
      }
    }
    iVar2 = -1;
  }
LAB_000982b0:
  BN_free(r);
  iVar1 = iVar2;
LAB_000982b6:
  if (r_00 != (BIGNUM *)0x0) {
    BN_free(r_00);
  }
  if (dv != (BIGNUM *)0x0) {
    BN_free(dv);
  }
  if (r_01 != (BIGNUM *)0x0) {
    BN_free(r_01);
  }
  if (r_02 != (BIGNUM *)0x0) {
    BN_free(r_02);
  }
  if (ctx != (BN_CTX *)0x0) {
    BN_CTX_free(ctx);
  }
  return iVar1;
}

