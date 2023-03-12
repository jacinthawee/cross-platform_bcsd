
ASN1_INTEGER * rand_serial(BIGNUM *param_1,ASN1_INTEGER *param_2)

{
  ASN1_INTEGER *pAVar1;
  BIGNUM *rnd;
  
  rnd = param_1;
  if ((param_1 == (BIGNUM *)0x0) && (rnd = BN_new(), rnd == (BIGNUM *)0x0)) {
    return (ASN1_INTEGER *)0x0;
  }
  pAVar1 = (ASN1_INTEGER *)BN_pseudo_rand(rnd,0x40,0,0);
  if (pAVar1 != (ASN1_INTEGER *)0x0) {
    if (param_2 == (ASN1_INTEGER *)0x0) {
      pAVar1 = (ASN1_INTEGER *)0x1;
    }
    else {
      pAVar1 = BN_to_ASN1_INTEGER(rnd,param_2);
      if (pAVar1 != (ASN1_INTEGER *)0x0) {
        pAVar1 = (ASN1_INTEGER *)0x1;
      }
    }
  }
  if (param_1 == (BIGNUM *)0x0) {
    BN_free(rnd);
    return pAVar1;
  }
  return pAVar1;
}

