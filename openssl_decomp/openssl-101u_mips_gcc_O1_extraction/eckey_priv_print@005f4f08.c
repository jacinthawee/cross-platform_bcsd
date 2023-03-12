
undefined4 eckey_priv_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  
  iVar8 = *(int *)(param_2 + 0x14);
  if (iVar8 == 0) {
LAB_005f5128:
    iVar2 = 0;
    uVar4 = 0x43;
LAB_005f5130:
    uVar10 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdd,uVar4,"ec_ameth.c",0x1e5);
    iVar8 = 0;
LAB_005f50d0:
    if (iVar2 == 0) goto LAB_005f50e4;
  }
  else {
    iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(iVar8);
    if (iVar1 == 0) goto LAB_005f5128;
    iVar2 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (iVar2 == 0) {
      uVar4 = 0x41;
      goto LAB_005f5130;
    }
    iVar3 = (*(code *)PTR_EC_KEY_get0_public_key_006a7ae4)(iVar8);
    if (iVar3 == 0) {
      iVar3 = 0;
      uVar9 = 0;
    }
    else {
      uVar4 = (*(code *)PTR_EC_KEY_get_conv_form_006a96c0)(iVar8);
      iVar3 = (*(code *)PTR_EC_POINT_point2bn_006a71e8)(iVar1,iVar3,uVar4,0,iVar2);
      if (iVar3 == 0) {
        uVar4 = 0x10;
        goto LAB_005f5130;
      }
      iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar3);
      iVar6 = iVar5 + 7;
      if (iVar5 + 7 < 0) {
        iVar6 = iVar5 + 0xe;
      }
      uVar9 = iVar6 >> 3;
    }
    iVar6 = (*(code *)PTR_EC_KEY_get0_private_key_006a7f78)(iVar8);
    if (iVar6 != 0) {
      iVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar6);
      iVar8 = iVar5 + 7;
      if (iVar5 + 7 < 0) {
        iVar8 = iVar5 + 0xe;
      }
      if (uVar9 < (uint)(iVar8 >> 3)) {
        uVar9 = iVar8 >> 3;
      }
    }
    iVar8 = (*(code *)PTR_CRYPTO_malloc_006a7008)(uVar9 + 10,"ec_ameth.c",0x1c5);
    if (iVar8 != 0) {
      iVar5 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
      if (iVar5 == 0) {
        iVar5 = 0;
        uVar4 = 0x20;
        goto LAB_005f5080;
      }
      iVar5 = (*(code *)PTR_BN_new_006a71b4)();
      if (iVar5 == 0) {
LAB_005f5194:
        uVar4 = 0x20;
        goto LAB_005f5080;
      }
      iVar7 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar1,iVar5,0);
      if (iVar7 == 0) goto LAB_005f5194;
      uVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar5);
      iVar7 = (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s: (%d bit)\n","Private-Key",uVar4);
      if (iVar7 < 1) goto LAB_005f5194;
      if (iVar6 != 0) {
        iVar6 = (*(code *)PTR_ASN1_bn_print_006a86b8)(param_1,"priv:",iVar6,iVar8,param_3);
        if (iVar6 == 0) goto LAB_005f5194;
      }
      if (iVar3 != 0) {
        iVar6 = (*(code *)PTR_ASN1_bn_print_006a86b8)(param_1,"pub: ",iVar3,iVar8,param_3);
        if (iVar6 == 0) {
LAB_005f5264:
          uVar10 = 0;
          (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
        }
        else {
          iVar1 = (*(code *)PTR_ECPKParameters_print_006a7194)(param_1,iVar1,param_3);
          if (iVar1 == 0) goto LAB_005f5264;
          uVar10 = 1;
        }
        goto LAB_005f50a8;
      }
      iVar1 = (*(code *)PTR_ECPKParameters_print_006a7194)(param_1,iVar1,param_3);
      if (iVar1 == 0) {
        uVar10 = 0;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
      }
      else {
        uVar10 = 1;
      }
LAB_005f50c0:
      (*(code *)PTR_BN_free_006a701c)(iVar5);
      goto LAB_005f50d0;
    }
    iVar5 = 0;
    uVar4 = 0x41;
LAB_005f5080:
    uVar10 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdd,uVar4,"ec_ameth.c",0x1e5);
    if (iVar3 != 0) {
LAB_005f50a8:
      (*(code *)PTR_BN_free_006a701c)(iVar3);
    }
    if (iVar5 != 0) goto LAB_005f50c0;
  }
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
LAB_005f50e4:
  if (iVar8 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
  }
  return uVar10;
}

