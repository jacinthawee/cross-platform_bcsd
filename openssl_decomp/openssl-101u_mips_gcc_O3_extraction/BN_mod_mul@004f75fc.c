
int BN_mod_mul(BIGNUM *r,BIGNUM *a,BIGNUM *b,BIGNUM *m,BN_CTX *ctx)

{
  BIGNUM *r_00;
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  BN_CTX_start(ctx);
  r_00 = BN_CTX_get(ctx);
  if (r_00 != (BIGNUM *)0x0) {
    if (a == b) {
      iVar1 = BN_sqr(r_00,a,ctx);
    }
    else {
      iVar1 = BN_mul(r_00,a,b,ctx);
    }
    if ((iVar1 != 0) && (iVar1 = (*(code *)PTR_BN_div_006a855c)(0,r,r_00,m,ctx), iVar1 != 0)) {
      if (r->neg == 0) {
        uVar2 = 1;
      }
      else {
        pcVar3 = (code *)PTR_BN_sub_006a85a8;
        if (m->neg == 0) {
          pcVar3 = (code *)PTR_BN_add_006a85a4;
        }
        iVar1 = (*pcVar3)(r,r,m);
        uVar2 = (uint)(iVar1 != 0);
      }
      goto LAB_004f7700;
    }
  }
  uVar2 = 0;
LAB_004f7700:
  BN_CTX_end(ctx);
  return uVar2;
}

