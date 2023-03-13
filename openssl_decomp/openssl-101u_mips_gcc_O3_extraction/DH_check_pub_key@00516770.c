
int DH_check_pub_key(DH *dh,BIGNUM *pub_key,int *codes)

{
  BIGNUM *a;
  int iVar1;
  
  *codes = 0;
  a = (BIGNUM *)(*(code *)PTR_BN_new_006a71b4)();
  if (a != (BIGNUM *)0x0) {
    (*(code *)PTR_BN_set_word_006a7730)(a,1);
    iVar1 = (*(code *)PTR_BN_cmp_006a7960)(pub_key,a);
    if (iVar1 < 1) {
      *codes = *codes | 1;
    }
    (*(code *)PTR_BN_copy_006a8450)(a,dh->p);
    BN_sub_word(a,1);
    iVar1 = (*(code *)PTR_BN_cmp_006a7960)(pub_key,a);
    if (-1 < iVar1) {
      *codes = *codes | 2;
    }
    (*(code *)PTR_BN_free_006a701c)(a);
    return 1;
  }
  return 0;
}

