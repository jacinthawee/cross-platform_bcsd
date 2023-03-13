
undefined4 dh_param_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uchar *buf;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar2 = *(int *)(param_2 + 0x14);
  if (*(BIGNUM **)(iVar2 + 8) != (BIGNUM *)0x0) {
    iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
    iVar3 = iVar1 + 0xe;
    if (-1 < iVar1 + 7) {
      iVar3 = iVar1 + 7;
    }
    uVar4 = iVar3 >> 3;
    if (uVar4 != 0) {
      if (*(BIGNUM **)(iVar2 + 0xc) != (BIGNUM *)0x0) {
        iVar1 = BN_num_bits(*(BIGNUM **)(iVar2 + 0xc));
        iVar3 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar3 = iVar1 + 0xe;
        }
        if (uVar4 < (uint)(iVar3 >> 3)) {
          uVar4 = iVar3 >> 3;
        }
      }
      buf = (uchar *)CRYPTO_malloc(uVar4 + 10,"dh_ameth.c",0x15b);
      if (buf == (uchar *)0x0) {
        iVar2 = 0x41;
        goto LAB_0811091a;
      }
      BIO_indent(param_1,param_3,0x80);
      iVar3 = BN_num_bits(*(BIGNUM **)(iVar2 + 8));
      iVar3 = BIO_printf(param_1,"%s: (%d bit)\n","PKCS#3 DH Parameters",iVar3);
      if (0 < iVar3) {
        param_3 = param_3 + 4;
        iVar3 = ASN1_bn_print(param_1,"private-key:",(BIGNUM *)0x0,buf,param_3);
        if ((((iVar3 != 0) &&
             (iVar3 = ASN1_bn_print(param_1,"public-key:",(BIGNUM *)0x0,buf,param_3), iVar3 != 0))
            && (iVar3 = ASN1_bn_print(param_1,"prime:",*(BIGNUM **)(iVar2 + 8),buf,param_3),
               iVar3 != 0)) &&
           (iVar3 = ASN1_bn_print(param_1,"generator:",*(BIGNUM **)(iVar2 + 0xc),buf,param_3),
           iVar3 != 0)) {
          if (*(int *)(iVar2 + 0x10) != 0) {
            BIO_indent(param_1,param_3,0x80);
            iVar2 = BIO_printf(param_1,"recommended-private-length: %d bits\n",
                               *(undefined4 *)(iVar2 + 0x10),iVar3);
            if (iVar2 < 1) goto LAB_081109da;
          }
          uVar5 = 1;
          goto LAB_081109f7;
        }
      }
LAB_081109da:
      uVar5 = 0;
      ERR_put_error(5,100,7,"dh_ameth.c",0x179);
LAB_081109f7:
      CRYPTO_free(buf);
      return uVar5;
    }
  }
  iVar2 = 0x43;
LAB_0811091a:
  ERR_put_error(5,100,iVar2,"dh_ameth.c",0x179);
  return 0;
}

