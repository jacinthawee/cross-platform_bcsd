
int DHparams_print(BIO *bp,DH *x)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (x->p != (BIGNUM *)0x0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar3 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar3 = iVar1 + 0xe;
    }
    uVar4 = iVar3 >> 3;
    if (uVar4 != 0) {
      if (x->g != (BIGNUM *)0x0) {
        iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
        iVar3 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar3 = iVar1 + 0xe;
        }
        if (uVar4 < (uint)(iVar3 >> 3)) {
          uVar4 = iVar3 >> 3;
        }
      }
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4 + 10,"dh_ameth.c",0x15b);
      if (iVar3 != 0) {
        BIO_indent(bp,4,0x80);
        uVar2 = (*(code *)PTR_BN_num_bits_006a71f4)(x->p);
        iVar1 = BIO_printf(bp,"%s: (%d bit)\n","PKCS#3 DH Parameters",uVar2);
        if (0 < iVar1) {
          iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"private-key:",0,iVar3,8);
          if (iVar1 != 0) {
            iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"public-key:",0,iVar3,8);
            if (iVar1 != 0) {
              iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"prime:",x->p,iVar3,8);
              if (iVar1 != 0) {
                iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(bp,"generator:",x->g,iVar3,8);
                if (iVar1 != 0) {
                  if (x->length == 0) {
                    iVar1 = 1;
                    goto LAB_00517dfc;
                  }
                  BIO_indent(bp,8,0x80);
                  iVar1 = BIO_printf(bp,"recommended-private-length: %d bits\n",x->length);
                  if (0 < iVar1) {
                    iVar1 = 1;
                    goto LAB_00517dfc;
                  }
                }
              }
            }
          }
        }
        iVar1 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x179);
LAB_00517dfc:
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
        return iVar1;
      }
      iVar3 = 0x41;
      goto LAB_00517cbc;
    }
  }
  iVar3 = 0x43;
LAB_00517cbc:
  ERR_put_error(5,100,iVar3,"dh_ameth.c",0x179);
  return 0;
}

