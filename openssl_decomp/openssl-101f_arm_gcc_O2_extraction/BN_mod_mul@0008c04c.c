
int BN_mod_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  code *pcVar1;
  BIGNUM *r_00;
  int iVar2;
  
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  if (r_00 != (BIGNUM *)0x0) {
    if (a == b) {
      iVar2 = BN_sqr(r_00,a,ctx);
    }
    else {
      iVar2 = BN_mul(r_00,a,b,ctx);
    }
    if ((iVar2 != 0) && (iVar2 = BN_div((BIGNUM *)0x0,r,r_00,m,ctx), iVar2 != 0)) {
      if (r->neg != 0) {
        pcVar1 = BN_sub;
        if (m->neg == 0) {
          pcVar1 = BN_add;
        }
        iVar2 = (*(pcVar1 + 1))(r,r,m);
        if (iVar2 == 0) goto LAB_0008c0ce;
      }
      BN_CTX_end(ctx);
      return 1;
    }
  }
LAB_0008c0ce:
  BN_CTX_end(ctx);
  return 0;
}

