
int RSA_check_key(RSA *param_1)

{
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *dv;
  BIGNUM *r_01;
  BIGNUM *r_02;
  BN_CTX *ctx;
  int iVar1;
  BIGNUM *pBVar2;
  int local_28;
  
  if ((((param_1->p == (BIGNUM *)0x0) || (param_1->q == (BIGNUM *)0x0)) ||
      (param_1->n == (BIGNUM *)0x0)) ||
     ((param_1->e == (BIGNUM *)0x0 || (param_1->d == (BIGNUM *)0x0)))) {
    ERR_put_error(4,0x7b,0x93,"rsa_chk.c",0x3f);
    return 0;
  }
  r = BN_new();
  r_00 = BN_new();
  dv = BN_new();
  r_01 = BN_new();
  r_02 = BN_new();
  ctx = BN_CTX_new();
  if ((r == (BIGNUM *)0x0) || (r_00 == (BIGNUM *)0x0)) {
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
    local_28 = -1;
    if (r == (BIGNUM *)0x0) goto LAB_0810ba5f;
    goto LAB_0810ba50;
  }
  if ((((dv == (BIGNUM *)0x0) || (r_01 == (BIGNUM *)0x0)) || (r_02 == (BIGNUM *)0x0)) ||
     (ctx == (BN_CTX *)0x0)) {
    ERR_put_error(4,0x7b,0x41,"rsa_chk.c",0x4c);
LAB_0810ba48:
    local_28 = -1;
  }
  else {
    iVar1 = BN_is_prime_ex(param_1->p,0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
    if (iVar1 != 1) {
      local_28 = iVar1;
      if (iVar1 != 0) goto LAB_0810ba50;
      ERR_put_error(4,0x7b,0x80,"rsa_chk.c",0x56);
    }
    local_28 = BN_is_prime_ex(param_1->q,0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
    if (local_28 != 1) {
      if (local_28 != 0) goto LAB_0810ba50;
      ERR_put_error(4,0x7b,0x81,"rsa_chk.c",0x5f);
      iVar1 = local_28;
    }
    local_28 = iVar1;
    iVar1 = BN_mul(r,param_1->p,param_1->q,ctx);
    if (iVar1 == 0) goto LAB_0810ba48;
    iVar1 = BN_cmp(r,param_1->n);
    if (iVar1 != 0) {
      ERR_put_error(4,0x7b,0x7f,"rsa_chk.c",0x6b);
      local_28 = 0;
    }
    pBVar2 = BN_value_one();
    iVar1 = BN_sub(r,param_1->p,pBVar2);
    if (iVar1 == 0) goto LAB_0810ba48;
    pBVar2 = BN_value_one();
    iVar1 = BN_sub(r_00,param_1->q,pBVar2);
    if (((iVar1 == 0) || (iVar1 = BN_mul(r_01,r,r_00,ctx), iVar1 == 0)) ||
       ((iVar1 = BN_gcd(r_02,r,r_00,ctx), iVar1 == 0 ||
        ((iVar1 = BN_div(dv,(BIGNUM *)0x0,r_01,r_02,ctx), iVar1 == 0 ||
         (iVar1 = BN_mod_mul(r,param_1->d,param_1->e,dv,ctx), iVar1 == 0)))))) goto LAB_0810ba48;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      ERR_put_error(4,0x7b,0x7b,"rsa_chk.c",0x94);
      local_28 = 0;
    }
    if (((param_1->dmp1 != (BIGNUM *)0x0) && (param_1->dmq1 != (BIGNUM *)0x0)) &&
       (param_1->iqmp != (BIGNUM *)0x0)) {
      pBVar2 = BN_value_one();
      iVar1 = BN_sub(r,param_1->p,pBVar2);
      if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,r_00,param_1->d,r,ctx), iVar1 != 0)) {
        iVar1 = BN_cmp(r_00,param_1->dmp1);
        if (iVar1 != 0) {
          ERR_put_error(4,0x7b,0x7c,"rsa_chk.c",0xa7);
          local_28 = 0;
        }
        pBVar2 = BN_value_one();
        iVar1 = BN_sub(r,param_1->q,pBVar2);
        if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,r_00,param_1->d,r,ctx), iVar1 != 0)) {
          iVar1 = BN_cmp(r_00,param_1->dmq1);
          if (iVar1 != 0) {
            ERR_put_error(4,0x7b,0x7d,"rsa_chk.c",0xb9);
            local_28 = 0;
          }
          pBVar2 = BN_mod_inverse(r,param_1->q,param_1->p,ctx);
          if (pBVar2 != (BIGNUM *)0x0) {
            iVar1 = BN_cmp(r,param_1->iqmp);
            if (iVar1 != 0) {
              ERR_put_error(4,0x7b,0x7e,"rsa_chk.c",0xc4);
              local_28 = 0;
            }
            goto LAB_0810ba50;
          }
        }
      }
      goto LAB_0810ba48;
    }
  }
LAB_0810ba50:
  BN_free(r);
LAB_0810ba5f:
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
  return local_28;
}

