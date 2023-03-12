
int BN_BLINDING_invert(BIGNUM *n,BN_BLINDING *b,BN_CTX *ctx)

{
  int iVar1;
  
  if (*(int *)(b + 4) != 0) {
    iVar1 = (*(code *)PTR_BN_mod_mul_006a9698)(n,n,*(int *)(b + 4),*(undefined4 *)(b + 0xc),ctx);
    return iVar1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(3,0x65,0x6b,"bn_blind.c",0x10d);
  return 0;
}

