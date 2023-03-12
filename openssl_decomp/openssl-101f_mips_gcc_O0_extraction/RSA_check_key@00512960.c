
int RSA_check_key(RSA *param_1)

{
  BIGNUM *r;
  BIGNUM *b;
  BIGNUM *m;
  BIGNUM *r_00;
  BIGNUM *a;
  BN_CTX *ctx;
  int iVar1;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  
  if ((((param_1->p == (BIGNUM *)0x0) || (param_1->q == (BIGNUM *)0x0)) ||
      (param_1->n == (BIGNUM *)0x0)) ||
     ((param_1->e == (BIGNUM *)0x0 || (param_1->d == (BIGNUM *)0x0)))) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x93,"rsa_chk.c",0x41);
    return 0;
  }
  r = BN_new();
  b = BN_new();
  m = BN_new();
  r_00 = BN_new();
  a = BN_new();
  ctx = BN_CTX_new();
  if (r == (BIGNUM *)0x0) {
    iVar2 = -1;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b20;
  }
  if (((b == (BIGNUM *)0x0) || (m == (BIGNUM *)0x0)) ||
     ((r_00 == (BIGNUM *)0x0 || ((a == (BIGNUM *)0x0 || (ctx == (BN_CTX *)0x0)))))) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x41,"rsa_chk.c",0x4f);
    goto LAB_00512b0c;
  }
  iVar1 = BN_is_prime_ex(param_1->p,0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar1 != 1) {
    iVar2 = iVar1;
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x80,"rsa_chk.c",0x5a);
      goto LAB_00512ab0;
    }
    goto LAB_00512b14;
  }
LAB_00512ab0:
  iVar2 = BN_is_prime_ex(param_1->q,0,(BN_CTX *)0x0,(BN_GENCB *)0x0);
  if (iVar2 != 1) {
    if (iVar2 != 0) goto LAB_00512b14;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x81,"rsa_chk.c",100);
    iVar1 = 0;
  }
  iVar2 = iVar1;
  iVar1 = BN_mul(r,param_1->p,param_1->q,ctx);
  if (iVar1 == 0) {
LAB_00512b0c:
    iVar2 = -1;
  }
  else {
    iVar1 = BN_cmp(r,param_1->n);
    if (iVar1 != 0) {
      iVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7f,"rsa_chk.c",0x6e);
    }
    pBVar4 = param_1->p;
    pBVar3 = BN_value_one();
    iVar1 = (*(code *)PTR_BN_sub_006a96cc)(r,pBVar4,pBVar3);
    if (iVar1 == 0) goto LAB_00512b0c;
    pBVar4 = param_1->q;
    pBVar3 = BN_value_one();
    iVar1 = (*(code *)PTR_BN_sub_006a96cc)(b,pBVar4,pBVar3);
    if ((((iVar1 == 0) || (iVar1 = BN_mul(r_00,r,b,ctx), iVar1 == 0)) ||
        (iVar1 = (*(code *)PTR_BN_gcd_006a9840)(a,r,b,ctx), iVar1 == 0)) ||
       ((iVar1 = (*(code *)PTR_BN_div_006a967c)(m,0,r_00,a,ctx), iVar1 == 0 ||
        (iVar1 = BN_mod_mul(r,param_1->d,param_1->e,m,ctx), iVar1 == 0)))) goto LAB_00512b0c;
    if ((r->top != 1) || ((*r->d != 1 || (r->neg != 0)))) {
      iVar2 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7b,"rsa_chk.c",0x86);
    }
    if (((param_1->dmp1 != (BIGNUM *)0x0) && (param_1->dmq1 != (BIGNUM *)0x0)) &&
       (param_1->iqmp != (BIGNUM *)0x0)) {
      pBVar4 = param_1->p;
      pBVar3 = BN_value_one();
      iVar1 = (*(code *)PTR_BN_sub_006a96cc)(r,pBVar4,pBVar3);
      if ((iVar1 != 0) && (iVar1 = (*(code *)PTR_BN_div_006a967c)(0,b,param_1->d,r,ctx), iVar1 != 0)
         ) {
        iVar1 = BN_cmp(b,param_1->dmp1);
        if (iVar1 != 0) {
          iVar2 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7c,"rsa_chk.c",0x96);
        }
        pBVar4 = param_1->q;
        pBVar3 = BN_value_one();
        iVar1 = (*(code *)PTR_BN_sub_006a96cc)(r,pBVar4,pBVar3);
        if ((iVar1 != 0) &&
           (iVar1 = (*(code *)PTR_BN_div_006a967c)(0,b,param_1->d,r,ctx), iVar1 != 0)) {
          iVar1 = BN_cmp(b,param_1->dmq1);
          if (iVar1 != 0) {
            iVar2 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7d,"rsa_chk.c",0xa4);
          }
          iVar1 = (*(code *)PTR_BN_mod_inverse_006a9714)(r,param_1->q,param_1->p,ctx);
          if (iVar1 != 0) {
            iVar1 = BN_cmp(r,param_1->iqmp);
            if (iVar1 != 0) {
              iVar2 = 0;
              (*(code *)PTR_ERR_put_error_006a9030)(4,0x7b,0x7e,"rsa_chk.c",0xb2);
            }
            goto LAB_00512b14;
          }
        }
      }
      goto LAB_00512b0c;
    }
  }
LAB_00512b14:
  BN_free(r);
LAB_00512b20:
  if (b != (BIGNUM *)0x0) {
    BN_free(b);
  }
  if (m != (BIGNUM *)0x0) {
    BN_free(m);
  }
  if (r_00 != (BIGNUM *)0x0) {
    BN_free(r_00);
  }
  if (a != (BIGNUM *)0x0) {
    BN_free(a);
  }
  if (ctx == (BN_CTX *)0x0) {
    return iVar2;
  }
  BN_CTX_free(ctx);
  return iVar2;
}

