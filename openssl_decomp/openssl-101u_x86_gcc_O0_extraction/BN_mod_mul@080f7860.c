
int BN_mod_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  BIGNUM *r_00;
  int iVar1;
  code *pcVar2;
  uint uVar3;
  
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  if (r_00 != (BIGNUM *)0x0) {
    if (a == b) {
      iVar1 = BN_sqr(r_00,a,ctx);
    }
    else {
      iVar1 = BN_mul(r_00,a,b,ctx);
    }
    if ((iVar1 != 0) && (iVar1 = BN_div((BIGNUM *)0x0,r,r_00,m,ctx), iVar1 != 0)) {
      uVar3 = 1;
      if (r->neg != 0) {
        pcVar2 = BN_sub;
        if (m->neg == 0) {
          pcVar2 = BN_add;
        }
        iVar1 = (*pcVar2)(r,r,m);
        uVar3 = (uint)(iVar1 != 0);
      }
      goto LAB_080f7922;
    }
  }
  uVar3 = 0;
LAB_080f7922:
  BN_CTX_end(ctx);
  return uVar3;
}

