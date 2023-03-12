
undefined4 eckey_priv_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar9 = *(int *)(param_2 + 0x14);
  if (iVar9 == 0) {
LAB_005f7170:
    iVar2 = 0;
    uVar3 = 0x43;
LAB_005f7178:
    uVar4 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdd,uVar3,"ec_ameth.c",0x1fe);
    iVar9 = 0;
LAB_005f7114:
    if (iVar2 == 0) goto LAB_005f712c;
  }
  else {
    iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(iVar9);
    if (iVar1 == 0) goto LAB_005f7170;
    iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (iVar2 == 0) {
      uVar3 = 0x41;
      goto LAB_005f7178;
    }
    uVar3 = (*(code *)PTR_EC_KEY_get0_public_key_006a8bd0)(iVar9);
    uVar4 = (*(code *)PTR_EC_KEY_get_conv_form_006aa7c8)(iVar9);
    iVar5 = (*(code *)PTR_EC_POINT_point2bn_006a82e8)(iVar1,uVar3,uVar4,0,iVar2);
    if (iVar5 == 0) {
      uVar3 = 0x10;
      goto LAB_005f7178;
    }
    iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar5);
    iVar7 = iVar6 + 7;
    if (iVar6 + 7 < 0) {
      iVar7 = iVar6 + 0xe;
    }
    uVar10 = iVar7 >> 3;
    iVar7 = (*(code *)PTR_EC_KEY_get0_private_key_006a910c)(iVar9);
    if (iVar7 != 0) {
      iVar6 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar7);
      iVar9 = iVar6 + 7;
      if (iVar6 + 7 < 0) {
        iVar9 = iVar6 + 0xe;
      }
      if (uVar10 < (uint)(iVar9 >> 3)) {
        uVar10 = iVar9 >> 3;
      }
    }
    iVar9 = (*(code *)PTR_CRYPTO_malloc_006a8108)(uVar10 + 10,"ec_ameth.c",0x1dd);
    if (iVar9 == 0) {
      iVar6 = 0;
      uVar3 = 0x41;
LAB_005f70cc:
      uVar4 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdd,uVar3,"ec_ameth.c",0x1fe);
    }
    else {
      iVar6 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
      if (iVar6 == 0) {
        iVar6 = 0;
        uVar3 = 0x20;
        goto LAB_005f70cc;
      }
      iVar6 = (*(code *)PTR_BN_new_006a82b4)();
      if (iVar6 == 0) {
LAB_005f71dc:
        uVar3 = 0x20;
        goto LAB_005f70cc;
      }
      iVar8 = (*(code *)PTR_EC_GROUP_get_order_006a82ec)(iVar1,iVar6,0);
      if (iVar8 == 0) goto LAB_005f71dc;
      uVar3 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar6);
      iVar8 = (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s: (%d bit)\n","Private-Key",uVar3);
      if (iVar8 < 1) goto LAB_005f71dc;
      if (iVar7 != 0) {
        iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"priv:",iVar7,iVar9,param_3);
        if (iVar7 == 0) goto LAB_005f71dc;
      }
      iVar7 = (*(code *)PTR_ASN1_bn_print_006a97dc)(param_1,"pub: ",iVar5,iVar9,param_3);
      if (iVar7 == 0) goto LAB_005f71dc;
      iVar1 = (*(code *)PTR_ECPKParameters_print_006a8294)(param_1,iVar1,param_3);
      if (iVar1 == 0) goto LAB_005f71dc;
      uVar4 = 1;
    }
    (*(code *)PTR_BN_free_006a811c)(iVar5);
    if (iVar6 != 0) {
      (*(code *)PTR_BN_free_006a811c)(iVar6);
      goto LAB_005f7114;
    }
  }
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
LAB_005f712c:
  if (iVar9 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar9);
  }
  return uVar4;
}

