
bool rand_serial(BIGNUM *param_1,ASN1_INTEGER *param_2)

{
  int iVar1;
  ASN1_INTEGER *pAVar2;
  BIGNUM *rnd;
  bool bVar3;
  
  if (param_1 == (BIGNUM *)0x0) {
    rnd = BN_new();
    if (rnd == (BIGNUM *)0x0) {
      return false;
    }
    iVar1 = BN_pseudo_rand(rnd,0x40,0,0);
    if (iVar1 == 0) {
      bVar3 = false;
      goto LAB_0807c640;
    }
    bVar3 = true;
    if (param_2 == (ASN1_INTEGER *)0x0) goto LAB_0807c640;
  }
  else {
    iVar1 = BN_pseudo_rand(param_1,0x40,0,0);
    if (iVar1 == 0) {
      return false;
    }
    rnd = param_1;
    if (param_2 == (ASN1_INTEGER *)0x0) {
      return true;
    }
  }
  pAVar2 = BN_to_ASN1_INTEGER(rnd,param_2);
  bVar3 = pAVar2 != (ASN1_INTEGER *)0x0;
  if (param_1 != (BIGNUM *)0x0) {
    return bVar3;
  }
LAB_0807c640:
  BN_free(rnd);
  return bVar3;
}

