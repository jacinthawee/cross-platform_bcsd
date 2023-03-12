
BIGNUM * ASN1_INTEGER_to_BN(ASN1_INTEGER *ai,BIGNUM *bn)

{
  BIGNUM *pBVar1;
  
  pBVar1 = (BIGNUM *)(*(code *)PTR_BN_bin2bn_006a89f0)(ai->data,ai->length,bn);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(0xd,0x77,0x69,"a_int.c",0x1c3);
  }
  else if (ai->type == 0x102) {
    (*(code *)PTR_BN_set_negative_006a96e8)(pBVar1,1);
    return pBVar1;
  }
  return pBVar1;
}

