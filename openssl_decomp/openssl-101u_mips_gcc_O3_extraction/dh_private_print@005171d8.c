
undefined4 dh_private_print(BIO *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_2 + 0x14);
  if (*(int *)(iVar5 + 8) != 0) {
    iVar6 = *(int *)(iVar5 + 0x18);
    iVar7 = *(int *)(iVar5 + 0x14);
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    uVar4 = iVar2 >> 3;
    if (uVar4 != 0) {
      if (*(int *)(iVar5 + 0xc) != 0) {
        iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (uVar4 < (uint)(iVar2 >> 3)) {
          uVar4 = iVar2 >> 3;
        }
      }
      if (iVar7 != 0) {
        iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar7);
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (uVar4 < (uint)(iVar2 >> 3)) {
          uVar4 = iVar2 >> 3;
        }
      }
      if (iVar6 != 0) {
        iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar6);
        iVar2 = iVar1 + 7;
        if (iVar1 + 7 < 0) {
          iVar2 = iVar1 + 0xe;
        }
        if (uVar4 < (uint)(iVar2 >> 3)) {
          uVar4 = iVar2 >> 3;
        }
      }
      iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4 + 10,"dh_ameth.c",0x15b);
      if (iVar2 != 0) {
        BIO_indent(param_1,param_3,0x80);
        uVar3 = (*(code *)PTR_BN_num_bits_006a71f4)(*(undefined4 *)(iVar5 + 8));
        iVar1 = BIO_printf(param_1,"%s: (%d bit)\n","PKCS#3 DH Private-Key",uVar3);
        if (0 < iVar1) {
          param_3 = param_3 + 4;
          iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(param_1,"private-key:",iVar6,iVar2,param_3);
          if (iVar1 != 0) {
            iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)(param_1,"public-key:",iVar7,iVar2,param_3)
            ;
            if (iVar1 != 0) {
              iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,"prime:",*(undefined4 *)(iVar5 + 8),iVar2,param_3);
              if (iVar1 != 0) {
                iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                  (param_1,"generator:",*(undefined4 *)(iVar5 + 0xc),iVar2,param_3);
                if (iVar1 != 0) {
                  if (*(int *)(iVar5 + 0x10) == 0) {
                    uVar3 = 1;
                    goto LAB_005173f8;
                  }
                  BIO_indent(param_1,param_3,0x80);
                  iVar5 = BIO_printf(param_1,"recommended-private-length: %d bits\n",
                                     *(undefined4 *)(iVar5 + 0x10));
                  if (0 < iVar5) {
                    uVar3 = 1;
                    goto LAB_005173f8;
                  }
                }
              }
            }
          }
        }
        uVar3 = 0;
        ERR_put_error(5,100,7,"dh_ameth.c",0x179);
LAB_005173f8:
        (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
        return uVar3;
      }
      iVar5 = 0x41;
      goto LAB_00517250;
    }
  }
  iVar5 = 0x43;
LAB_00517250:
  ERR_put_error(5,100,iVar5,"dh_ameth.c",0x179);
  return 0;
}

