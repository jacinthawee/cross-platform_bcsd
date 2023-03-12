
int BN_BLINDING_invert_ex(BIGNUM *n,BIGNUM *r,BN_BLINDING *b,BN_CTX *param_4)

{
  if ((r == (BIGNUM *)0x0) && (r = *(BIGNUM **)(b + 4), r == (BIGNUM *)0x0)) {
    ERR_put_error(3,0x65,0x6b,"bn_blind.c",0x10f);
  }
  else {
    r = (BIGNUM *)BN_mod_mul(n,n,r,*(BIGNUM **)(b + 0xc),param_4);
  }
  return (int)r;
}

