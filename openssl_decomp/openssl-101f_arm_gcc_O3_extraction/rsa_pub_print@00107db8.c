
uchar * rsa_pub_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *pBVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  int iVar4;
  uchar *puVar5;
  
  iVar4 = *(int *)(param_2 + 0x14);
  pBVar1 = *(BIGNUM **)(iVar4 + 0x10);
  if (pBVar1 != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(pBVar1);
    iVar3 = iVar2 + 0xe;
    if (-1 < iVar2 + 7) {
      iVar3 = iVar2 + 7;
    }
    pBVar1 = (BIGNUM *)(iVar3 >> 3);
  }
  if (*(BIGNUM **)(iVar4 + 0x14) != (BIGNUM *)0x0) {
    iVar2 = BN_num_bits(*(BIGNUM **)(iVar4 + 0x14));
    iVar3 = iVar2 + 7;
    if (iVar2 + 7 < 0) {
      iVar3 = iVar2 + 0xe;
    }
    if (pBVar1 < (BIGNUM *)(iVar3 >> 3)) {
      pBVar1 = (BIGNUM *)(iVar3 >> 3);
    }
  }
  buf = (uchar *)CRYPTO_malloc((int)((int)&pBVar1->dmax + 2),"rsa_ameth.c",0xcc);
  if (buf == (uchar *)0x0) {
    ERR_put_error(4,0x92,0x41,"rsa_ameth.c",0xcf);
  }
  else {
    pBVar1 = *(BIGNUM **)(iVar4 + 0x10);
    if (pBVar1 != (BIGNUM *)0x0) {
      pBVar1 = (BIGNUM *)BN_num_bits(pBVar1);
    }
    iVar3 = BIO_indent(param_1,param_3,0x80);
    if (((iVar3 == 0) || (iVar3 = BIO_printf(param_1,"Public-Key: (%d bit)\n",pBVar1), iVar3 < 1))
       || (iVar3 = ASN1_bn_print(param_1,"Modulus:",*(BIGNUM **)(iVar4 + 0x10),buf,param_3),
          iVar3 == 0)) {
      puVar5 = (uchar *)0x0;
    }
    else {
      puVar5 = (uchar *)ASN1_bn_print(param_1,"Exponent:",*(BIGNUM **)(iVar4 + 0x14),buf,param_3);
      if (puVar5 != (uchar *)0x0) {
        puVar5 = (uchar *)0x1;
      }
    }
    CRYPTO_free(buf);
    buf = puVar5;
  }
  return buf;
}

