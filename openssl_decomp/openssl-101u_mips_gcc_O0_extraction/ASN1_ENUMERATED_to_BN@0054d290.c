
BIGNUM * ASN1_ENUMERATED_to_BN(ASN1_ENUMERATED *ai,BIGNUM *bn)

{
  BIGNUM *pBVar1;
  
  pBVar1 = (BIGNUM *)(*(code *)PTR_BN_bin2bn_006a7904)(ai->data,ai->length,bn);
  if (pBVar1 == (BIGNUM *)0x0) {
    ERR_put_error(0xd,0x71,0x69,"a_enum.c",0xb1);
  }
  else if (ai->type == 0x10a) {
    (*(code *)PTR_BN_set_negative_006a85c4)(pBVar1,1);
    return pBVar1;
  }
  return pBVar1;
}

