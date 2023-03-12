
int BN_mod_lshift1(BIGNUM *r,BIGNUM *a,BIGNUM *m,BN_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = BN_lshift1(r,a);
  if (iVar2 != 0) {
    iVar2 = BN_div((BIGNUM *)0x0,r,r,m,ctx);
    if (iVar2 != 0) {
      if (r->neg != 0) {
        pcVar1 = BN_sub;
        if (m->neg == 0) {
          pcVar1 = BN_add;
        }
                    /* WARNING: Could not recover jumptable at 0x0008c152. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*(pcVar1 + 1))(r,r,m);
        return iVar2;
      }
      iVar2 = 1;
    }
  }
  return iVar2;
}

