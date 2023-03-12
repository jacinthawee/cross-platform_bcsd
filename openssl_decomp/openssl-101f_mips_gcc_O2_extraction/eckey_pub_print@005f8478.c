
undefined4 eckey_pub_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_2 + 0x14);
  if (iVar8 == 0) {
LAB_005f8644:
    iVar2 = 0;
    uVar3 = 0x43;
LAB_005f864c:
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdd,uVar3,"ec_ameth.c",0x1fe);
    iVar6 = 0;
LAB_005f85ec:
    if (iVar2 == 0) goto LAB_005f8604;
  }
  else {
    iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar8);
    if (iVar1 == 0) goto LAB_005f8644;
    iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (iVar2 == 0) {
      uVar3 = 0x41;
      goto LAB_005f864c;
    }
    uVar3 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar8);
    uVar4 = (*(code *)PTR_EC_KEY_get_conv_form_006aa7c8)(iVar8);
    iVar8 = (*(code *)PTR_EC_POINT_point2bn_006a82e8)(iVar1,uVar3,uVar4,0,iVar2);
    if (iVar8 == 0) {
      uVar3 = 0x10;
      goto LAB_005f864c;
    }
    iVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar8);
    iVar6 = iVar5 + 7;
    if (iVar5 + 7 < 0) {
      iVar6 = iVar5 + 0xe;
    }
    iVar6 = (*(code *)PTR_CRYPTO_malloc_006a8108)((iVar6 >> 3) + 10,"ec_ameth.c",0x1dd);
    if (iVar6 == 0) {
      iVar5 = 0;
      uVar3 = 0x41;
LAB_005f85a4:
      uVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdd,uVar3,"ec_ameth.c",0x1fe);
    }
    else {
      iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
      if (iVar5 == 0) {
        iVar5 = 0;
        uVar3 = 0x20;
        goto LAB_005f85a4;
      }
      iVar5 = (*(code *)PTR_BN_new_006a82b4)();
      if (iVar5 == 0) {
LAB_005f86b0:
        uVar3 = 0x20;
        goto LAB_005f85a4;
      }
      iVar7 = (*(code *)PTR_EC_GROUP_get_order_006a82ec)(iVar1,iVar5,0);
      if (iVar7 == 0) goto LAB_005f86b0;
      uVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar5);
      iVar7 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s: (%d bit)\n","Public-Key",uVar3);
      if (iVar7 < 1) goto LAB_005f86b0;
      iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"pub: ",iVar8,iVar6,param_3);
      if (iVar7 == 0) goto LAB_005f86b0;
      iVar1 = (*(code *)PTR_ECPKParameters_print_006a8294)(param_1,iVar1,param_3);
      if (iVar1 == 0) goto LAB_005f86b0;
      uVar4 = 1;
    }
    (*(code *)PTR_BN_free_006a811c)(iVar8);
    if (iVar5 != 0) {
      (*(code *)PTR_BN_free_006a811c)(iVar5);
      goto LAB_005f85ec;
    }
  }
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
LAB_005f8604:
  if (iVar6 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar6);
  }
  return uVar4;
}

