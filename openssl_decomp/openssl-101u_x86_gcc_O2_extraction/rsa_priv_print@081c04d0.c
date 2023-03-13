
bool rsa_priv_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  uchar *buf;
  char *number;
  int iVar2;
  int iVar3;
  char *number_00;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  iVar2 = *(int *)(param_2 + 0x14);
  if (*(BIGNUM **)(iVar2 + 0x10) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x10));
    iVar3 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar3 = iVar1 + 7;
    }
    uVar4 = iVar3 >> 3;
  }
  if (*(BIGNUM **)(iVar2 + 0x14) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x14));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar2 + 0x18) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x18));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar2 + 0x1c) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x1c));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar2 + 0x20) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x20));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar2 + 0x24) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x24));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar2 + 0x28) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x28));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  if (*(BIGNUM **)(iVar2 + 0x2c) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x2c));
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar3 >> 3)) {
      uVar4 = iVar3 >> 3;
    }
  }
  buf = (uchar *)CRYPTO_malloc(uVar4 + 10,"rsa_ameth.c",199);
  if (buf == (uchar *)0x0) {
    ERR_put_error(4,0x92,0x41,"rsa_ameth.c",0xc9);
    return false;
  }
  iVar3 = 0;
  if (*(BIGNUM **)(iVar2 + 0x10) != (BIGNUM *)0x0) {
    iVar3 = BN_num_bits(*(BIGNUM **)(iVar2 + 0x10));
  }
  iVar1 = BIO_indent(param_1,param_3,0x80);
  if (iVar1 != 0) {
    if (*(int *)(iVar2 + 0x18) == 0) {
      iVar3 = BIO_printf(param_1,"Public-Key: (%d bit)\n",iVar3);
      if (0 < iVar3) {
        number_00 = "Exponent:";
        number = "Modulus:";
        goto LAB_081c067d;
      }
    }
    else {
      iVar3 = BIO_printf(param_1,"Private-Key: (%d bit)\n",iVar3);
      if (0 < iVar3) {
        number_00 = "publicExponent:";
        number = "modulus:";
LAB_081c067d:
        iVar3 = ASN1_bn_print(param_1,number,*(BIGNUM **)(iVar2 + 0x10),buf,param_3);
        if ((((iVar3 != 0) &&
             (iVar3 = ASN1_bn_print(param_1,number_00,*(BIGNUM **)(iVar2 + 0x14),buf,param_3),
             iVar3 != 0)) &&
            (iVar3 = ASN1_bn_print(param_1,"privateExponent:",*(BIGNUM **)(iVar2 + 0x18),buf,param_3
                                  ), iVar3 != 0)) &&
           (((iVar3 = ASN1_bn_print(param_1,"prime1:",*(BIGNUM **)(iVar2 + 0x1c),buf,param_3),
             iVar3 != 0 &&
             (iVar3 = ASN1_bn_print(param_1,"prime2:",*(BIGNUM **)(iVar2 + 0x20),buf,param_3),
             iVar3 != 0)) &&
            ((iVar3 = ASN1_bn_print(param_1,"exponent1:",*(BIGNUM **)(iVar2 + 0x24),buf,param_3),
             iVar3 != 0 &&
             (iVar3 = ASN1_bn_print(param_1,"exponent2:",*(BIGNUM **)(iVar2 + 0x28),buf,param_3),
             iVar3 != 0)))))) {
          iVar2 = ASN1_bn_print(param_1,"coefficient:",*(BIGNUM **)(iVar2 + 0x2c),buf,param_3);
          bVar5 = iVar2 != 0;
          goto LAB_081c0698;
        }
      }
    }
  }
  bVar5 = false;
LAB_081c0698:
  CRYPTO_free(buf);
  return bVar5;
}

