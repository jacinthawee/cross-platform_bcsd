
bool rsa_priv_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  char *pcVar8;
  
  iVar6 = *(int *)(param_2 + 0x14);
  if (*(int *)(iVar6 + 0x10) == 0) {
    uVar5 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    uVar5 = iVar2 >> 3;
  }
  if (*(int *)(iVar6 + 0x14) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar6 + 0x18) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar6 + 0x1c) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar6 + 0x20) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar6 + 0x24) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar6 + 0x28) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  if (*(int *)(iVar6 + 0x2c) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar5 < (uint)(iVar2 >> 3)) {
      uVar5 = iVar2 >> 3;
    }
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar5 + 10,"rsa_ameth.c",199);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x92,0x41,"rsa_ameth.c",0xc9);
    return false;
  }
  if (*(int *)(iVar6 + 0x10) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(code *)PTR_BN_num_bits_006a71f4)();
  }
  iVar1 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
  if (iVar1 != 0) {
    if (*(int *)(iVar6 + 0x18) == 0) {
      iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Public-Key: (%d bit)\n",uVar3);
      if (0 < iVar1) {
        pcVar8 = "Exponent:";
        pcVar4 = "Modulus:";
        goto LAB_005fa6b4;
      }
    }
    else {
      iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Private-Key: (%d bit)\n");
      if (0 < iVar1) {
        pcVar8 = "publicExponent:";
        pcVar4 = "modulus:";
LAB_005fa6b4:
        iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                          (param_1,pcVar4,*(undefined4 *)(iVar6 + 0x10),iVar2,param_3);
        if ((((iVar1 != 0) &&
             (iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,pcVar8,*(undefined4 *)(iVar6 + 0x14),iVar2,param_3),
             iVar1 != 0)) &&
            (iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                               (param_1,"privateExponent:",*(undefined4 *)(iVar6 + 0x18),iVar2,
                                param_3), iVar1 != 0)) &&
           (((iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,"prime1:",*(undefined4 *)(iVar6 + 0x1c),iVar2,param_3),
             iVar1 != 0 &&
             (iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,"prime2:",*(undefined4 *)(iVar6 + 0x20),iVar2,param_3),
             iVar1 != 0)) &&
            ((iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,"exponent1:",*(undefined4 *)(iVar6 + 0x24),iVar2,param_3),
             iVar1 != 0 &&
             (iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                                (param_1,"exponent2:",*(undefined4 *)(iVar6 + 0x28),iVar2,param_3),
             iVar1 != 0)))))) {
          iVar6 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                            (param_1,"coefficient:",*(undefined4 *)(iVar6 + 0x2c),iVar2,param_3);
          bVar7 = iVar6 != 0;
          goto LAB_005fa6d8;
        }
      }
    }
  }
  bVar7 = false;
LAB_005fa6d8:
  (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
  return bVar7;
}

