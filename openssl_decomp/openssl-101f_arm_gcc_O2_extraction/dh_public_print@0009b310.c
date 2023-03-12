
undefined4 dh_public_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  uchar *buf;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  BIGNUM *a;
  
  iVar3 = *(int *)(param_2 + 0x14);
  a = *(BIGNUM **)(iVar3 + 0x14);
  if (*(BIGNUM **)(iVar3 + 8) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 8));
    iVar2 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar2 = iVar1 + 7;
    }
    uVar5 = iVar2 >> 3;
    if (uVar5 != 0) {
      if (*(BIGNUM **)(iVar3 + 0xc) != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(*(BIGNUM **)(iVar3 + 0xc));
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (uVar5 < (uint)(iVar2 >> 3)) {
          uVar5 = iVar2 >> 3;
        }
      }
      if (a != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(a);
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (uVar5 < (uint)(iVar2 >> 3)) {
          uVar5 = iVar2 >> 3;
        }
      }
      buf = (uchar *)CRYPTO_malloc(uVar5 + 10,"dh_ameth.c",0x164);
      if (buf == (uchar *)0x0) {
        iVar3 = 0x41;
        goto LAB_0009b40e;
      }
      BIO_indent(param_1,param_3,0x80);
      iVar2 = BN_num_bits(*(BIGNUM **)(iVar3 + 8));
      iVar2 = BIO_printf(param_1,"%s: (%d bit)\n","PKCS#3 DH Public-Key",iVar2);
      if (0 < iVar2) {
        param_3 = param_3 + 4;
        iVar2 = ASN1_bn_print(param_1,"private-key:",(BIGNUM *)0x0,buf,param_3);
        if ((((iVar2 != 0) &&
             (iVar2 = ASN1_bn_print(param_1,"public-key:",a,buf,param_3), iVar2 != 0)) &&
            (iVar2 = ASN1_bn_print(param_1,"prime:",*(BIGNUM **)(iVar3 + 8),buf,param_3), iVar2 != 0
            )) && (iVar2 = ASN1_bn_print(param_1,"generator:",*(BIGNUM **)(iVar3 + 0xc),buf,param_3)
                  , iVar2 != 0)) {
          if (*(int *)(iVar3 + 0x10) != 0) {
            BIO_indent(param_1,param_3,0x80);
            iVar3 = BIO_printf(param_1,"recommended-private-length: %d bits\n",
                               *(undefined4 *)(iVar3 + 0x10));
            if (iVar3 < 1) goto LAB_0009b3e4;
          }
          uVar4 = 1;
          goto LAB_0009b3fe;
        }
      }
LAB_0009b3e4:
      uVar4 = 0;
      ERR_put_error(5,100,7,"dh_ameth.c",0x181);
LAB_0009b3fe:
      CRYPTO_free(buf);
      return uVar4;
    }
  }
  iVar3 = 0x43;
LAB_0009b40e:
  ERR_put_error(5,100,iVar3,"dh_ameth.c",0x181);
  return 0;
}

