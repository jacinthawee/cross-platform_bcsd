
undefined4 dh_private_print(BIO *param_1,int param_2,int param_3)

{
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_2 + 0x14);
  if (*(BIGNUM **)(iVar2 + 8) != (BIGNUM *)0x0) {
    a = *(BIGNUM **)(iVar2 + 0x18);
    a_00 = *(BIGNUM **)(iVar2 + 0x14);
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
    iVar3 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar3 = iVar1 + 7;
    }
    uVar5 = iVar3 >> 3;
    if (uVar5 != 0) {
      if (*(BIGNUM **)(iVar2 + 0xc) != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0xc));
        iVar3 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar3 = iVar1 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (a_00 != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(a_00);
        iVar3 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar3 = iVar1 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      if (a != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(a);
        iVar3 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar3 = iVar1 + 0xe;
        }
        if (uVar5 < (uint)(iVar3 >> 3)) {
          uVar5 = iVar3 >> 3;
        }
      }
      buf = (uchar *)CRYPTO_malloc(uVar5 + 10,"dh_ameth.c",0x164);
      if (buf == (uchar *)0x0) {
        iVar2 = 0x41;
        goto LAB_08111cfc;
      }
      BIO_indent(param_1,param_3,0x80);
      iVar3 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
      iVar3 = BIO_printf(param_1,"%s: (%d bit)\n","PKCS#3 DH Private-Key",iVar3);
      if (0 < iVar3) {
        param_3 = param_3 + 4;
        iVar3 = ASN1_bn_print(param_1,"private-key:",a,buf,param_3);
        if ((((iVar3 != 0) &&
             (iVar3 = ASN1_bn_print(param_1,"public-key:",a_00,buf,param_3), iVar3 != 0)) &&
            (iVar3 = ASN1_bn_print(param_1,"prime:",*(BIGNUM **)(iVar2 + 8),buf,param_3), iVar3 != 0
            )) && (iVar3 = ASN1_bn_print(param_1,"generator:",*(BIGNUM **)(iVar2 + 0xc),buf,param_3)
                  , iVar3 != 0)) {
          if (*(int *)(iVar2 + 0x10) != 0) {
            BIO_indent(param_1,param_3,0x80);
            iVar2 = BIO_printf(param_1,"recommended-private-length: %d bits\n",
                               *(undefined4 *)(iVar2 + 0x10),iVar3);
            if (iVar2 < 1) goto LAB_08111e10;
          }
          uVar4 = 1;
          goto LAB_08111e2d;
        }
      }
LAB_08111e10:
      uVar4 = 0;
      ERR_put_error(5,100,7,"dh_ameth.c",0x181);
LAB_08111e2d:
      CRYPTO_free(buf);
      return uVar4;
    }
  }
  iVar2 = 0x43;
LAB_08111cfc:
  ERR_put_error(5,100,iVar2,"dh_ameth.c",0x181);
  return 0;
}

