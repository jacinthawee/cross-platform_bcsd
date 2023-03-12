
int BN_mod_lshift(BIGNUM *r,BIGNUM *a,int n,BIGNUM *m,BN_CTX *ctx)

{
  int iVar1;
  BIGNUM *m_00;
  code *pcVar2;
  
  iVar1 = (*(code *)PTR_BN_div_006a967c)(0,r,a,m,ctx);
  if (iVar1 != 0) {
    if (r->neg != 0) {
      pcVar2 = (code *)PTR_BN_sub_006a96cc;
      if (m->neg == 0) {
        pcVar2 = (code *)PTR_BN_add_006a96c8;
      }
      iVar1 = (*pcVar2)(r,r,m);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if (m->neg == 0) {
      iVar1 = BN_mod_lshift_quick(r,r,n,m);
      return iVar1;
    }
    m_00 = BN_dup(m);
    if (m_00 != (BIGNUM *)0x0) {
      m_00->neg = 0;
      iVar1 = BN_mod_lshift_quick(r,r,n,m_00);
      BN_free(m_00);
      return iVar1;
    }
  }
  return 0;
}
