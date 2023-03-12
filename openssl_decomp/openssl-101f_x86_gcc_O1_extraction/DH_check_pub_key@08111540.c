
int DH_check_pub_key(DH *dh,BIGNUM *pub_key,int *codes)

{
  BIGNUM *a;
  int iVar1;
  
  *codes = 0;
  a = BN_new();
  iVar1 = 0;
  if (a != (BIGNUM *)0x0) {
    BN_set_word(a,1);
    iVar1 = BN_cmp(pub_key,a);
    if (iVar1 < 1) {
      *codes = *codes | 1;
    }
    BN_copy(a,dh->p);
    BN_sub_word(a,1);
    iVar1 = BN_cmp(pub_key,a);
    if (-1 < iVar1) {
      *codes = *codes | 2;
    }
    BN_free(a);
    iVar1 = 1;
  }
  return iVar1;
}

