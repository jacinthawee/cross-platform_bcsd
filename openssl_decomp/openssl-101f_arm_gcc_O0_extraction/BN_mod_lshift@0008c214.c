
int BN_mod_lshift(BIGNUM *r,BIGNUM *a,int n,BIGNUM *m,BN_CTX *ctx)

{
  code *pcVar1;
  int iVar2;
  BIGNUM *m_00;
  
  iVar2 = BN_div((BIGNUM *)0x0,r,a,m,ctx);
  if (iVar2 != 0) {
    if (r->neg != 0) {
      pcVar1 = BN_sub;
      if (m->neg == 0) {
        pcVar1 = BN_add;
      }
      iVar2 = (*(pcVar1 + 1))(r,r,m);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if (m->neg == 0) {
      iVar2 = BN_mod_lshift_quick(r,r,n,m);
      return iVar2;
    }
    m_00 = BN_dup(m);
    if (m_00 != (BIGNUM *)0x0) {
      m_00->neg = 0;
      iVar2 = BN_mod_lshift_quick(r,r,n,m_00);
      BN_free(m_00);
      return iVar2;
    }
  }
  return 0;
}

