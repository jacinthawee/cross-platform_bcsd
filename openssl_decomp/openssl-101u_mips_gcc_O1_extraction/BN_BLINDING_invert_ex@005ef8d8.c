
int BN_BLINDING_invert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  int iVar1;
  
  if (r == (BIGNUM *)0x0) {
    if (*(int *)(b + 4) != 0) {
      iVar1 = (*(code *)PTR_BN_mod_mul_006a8574)
                        (n,n,*(int *)(b + 4),*(undefined4 *)(b + 0xc),param_4);
      return iVar1;
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x65,0x6b,"bn_blind.c",0x10f);
    iVar1 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_BN_mod_mul_006a8574)(n,n,r,*(undefined4 *)(b + 0xc),param_4);
  }
  return iVar1;
}

