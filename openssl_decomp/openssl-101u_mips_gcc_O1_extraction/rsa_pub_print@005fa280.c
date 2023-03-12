
bool rsa_pub_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *(int *)(param_2 + 0x14);
  if (*(int *)(iVar5 + 0x10) == 0) {
    uVar4 = 0;
  }
  else {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    uVar4 = iVar2 >> 3;
  }
  if (*(int *)(iVar5 + 0x14) != 0) {
    iVar1 = (*(code *)PTR_BN_num_bits_006a71f4)();
    iVar2 = iVar1 + 7;
    if (iVar1 + 7 < 0) {
      iVar2 = iVar1 + 0xe;
    }
    if (uVar4 < (uint)(iVar2 >> 3)) {
      uVar4 = iVar2 >> 3;
    }
  }
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar4 + 10,"rsa_ameth.c",199);
  if (iVar2 != 0) {
    if (*(int *)(iVar5 + 0x10) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (*(code *)PTR_BN_num_bits_006a71f4)();
    }
    iVar1 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
    if (((iVar1 == 0) ||
        (iVar1 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Public-Key: (%d bit)\n",uVar3),
        iVar1 < 1)) ||
       (iVar1 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                          (param_1,"Modulus:",*(undefined4 *)(iVar5 + 0x10),iVar2,param_3),
       iVar1 == 0)) {
      bVar6 = false;
    }
    else {
      iVar5 = (*(code *)PTR_ASN1_bn_print_006a86b8)
                        (param_1,"Exponent:",*(undefined4 *)(iVar5 + 0x14),iVar2,param_3);
      bVar6 = iVar5 != 0;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
    return bVar6;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x92,0x41,"rsa_ameth.c",0xc9);
  return false;
}

