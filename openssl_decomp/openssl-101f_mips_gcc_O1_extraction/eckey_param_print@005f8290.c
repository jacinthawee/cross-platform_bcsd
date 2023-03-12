
undefined4 eckey_param_print(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_2 + 0x14) == 0) {
LAB_005f831c:
    iVar2 = 0;
    uVar5 = 0x43;
  }
  else {
    iVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(*(int *)(param_2 + 0x14));
    if (iVar1 == 0) goto LAB_005f831c;
    iVar2 = (*(code *)PTR_BN_CTX_new_006a8a38)();
    if (iVar2 == 0) {
      uVar5 = 0x41;
    }
    else {
      iVar3 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_3,0x80);
      if (iVar3 != 0) {
        iVar3 = (*(code *)PTR_BN_new_006a82b4)();
        if (iVar3 != 0) {
          iVar4 = (*(code *)PTR_EC_GROUP_get_order_006a82ec)(iVar1,iVar3,0);
          if (iVar4 == 0) {
LAB_005f83a8:
            uVar6 = 0;
            (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdd,0x20,"ec_ameth.c",0x1fe);
          }
          else {
            uVar5 = (*(code *)PTR_BN_num_bits_006a82f4)(iVar3);
            iVar4 = (*(code *)PTR_BIO_printf_006a7f38)
                              (param_1,"%s: (%d bit)\n","ECDSA-Parameters",uVar5);
            if (iVar4 < 1) goto LAB_005f83a8;
            iVar1 = (*(code *)PTR_ECPKParameters_print_006a8294)(param_1,iVar1,param_3);
            if (iVar1 == 0) goto LAB_005f83a8;
            uVar6 = 1;
          }
          (*(code *)PTR_BN_free_006a811c)(iVar3);
          goto LAB_005f83e4;
        }
      }
      uVar5 = 0x20;
    }
  }
  uVar6 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x10,0xdd,uVar5,"ec_ameth.c",0x1fe);
  if (iVar2 == 0) {
    return 0;
  }
LAB_005f83e4:
  (*(code *)PTR_BN_CTX_free_006a8a40)(iVar2);
  return uVar6;
}

