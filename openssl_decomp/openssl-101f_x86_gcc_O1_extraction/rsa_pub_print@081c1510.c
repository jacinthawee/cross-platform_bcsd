
bool rsa_pub_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  uchar *buf;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  
  uVar3 = 0;
  iVar2 = *(int *)(param_2 + 0x14);
  if (*(BIGNUM **)(iVar2 + 0x10) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x10));
    iVar4 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar4 = iVar1 + 7;
    }
    uVar3 = iVar4 >> 3;
  }
  if (*(BIGNUM **)(iVar2 + 0x14) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x14));
    iVar4 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar4 = iVar1 + 0xe;
    }
    if (uVar3 < (uint)(iVar4 >> 3)) {
      uVar3 = iVar4 >> 3;
    }
  }
  buf = (uchar *)CRYPTO_malloc(uVar3 + 10,"rsa_ameth.c",0xcc);
  if (buf != (uchar *)0x0) {
    iVar4 = 0;
    if (*(BIGNUM **)(iVar2 + 0x10) != (BIGNUM *)0x0) {
      iVar4 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x10));
    }
    iVar1 = BIO_indent(param_1,param_3,0x80);
    if (((iVar1 == 0) || (iVar4 = BIO_printf(param_1,"Public-Key: (%d bit)\n",iVar4), iVar4 < 1)) ||
       (iVar4 = ASN1_bn_print(param_1,"Modulus:",*(BIGNUM **)(iVar2 + 0x10),buf,param_3), iVar4 == 0
       )) {
      bVar5 = false;
    }
    else {
      iVar2 = ASN1_bn_print(param_1,"Exponent:",*(BIGNUM **)(iVar2 + 0x14),buf,param_3);
      bVar5 = iVar2 != 0;
    }
    CRYPTO_free(buf);
    return bVar5;
  }
  ERR_put_error(4,0x92,0x41,"rsa_ameth.c",0xcf);
  return false;
}

