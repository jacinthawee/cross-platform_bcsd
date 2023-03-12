
undefined4 eckey_param_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_2 + 0x14) == 0) {
LAB_005f6368:
    iVar2 = 0;
    uVar5 = 0x43;
  }
  else {
    iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(*(int *)(param_2 + 0x14));
    if (iVar1 == 0) goto LAB_005f6368;
    iVar2 = (*(code *)PTR_BN_CTX_new_006a794c)();
    if (iVar2 == 0) {
      uVar5 = 0x41;
    }
    else {
      iVar3 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_3,0x80);
      if (iVar3 != 0) {
        iVar3 = (*(code *)PTR_BN_new_006a71b4)();
        if (iVar3 != 0) {
          iVar4 = (*(code *)PTR_EC_GROUP_get_order_006a71ec)(iVar1,iVar3,0);
          if (iVar4 == 0) {
LAB_005f63f4:
            uVar6 = 0;
            (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdd,0x20,"ec_ameth.c",0x1e5);
          }
          else {
            uVar5 = (*(code *)PTR_BN_num_bits_006a71f4)(iVar3);
            iVar4 = (*(code *)PTR_BIO_printf_006a6e38)
                              (param_1,"%s: (%d bit)\n","ECDSA-Parameters",uVar5);
            if (iVar4 < 1) goto LAB_005f63f4;
            iVar1 = (*(code *)PTR_ECPKParameters_print_006a7194)(param_1,iVar1,param_3);
            if (iVar1 == 0) goto LAB_005f63f4;
            uVar6 = 1;
          }
          (*(code *)PTR_BN_free_006a701c)(iVar3);
          goto LAB_005f6430;
        }
      }
      uVar5 = 0x20;
    }
  }
  uVar6 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xdd,uVar5,"ec_ameth.c",0x1e5);
  if (iVar2 == 0) {
    return 0;
  }
LAB_005f6430:
  (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
  return uVar6;
}

