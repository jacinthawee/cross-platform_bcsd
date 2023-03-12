
undefined4 add_cipher_smcap(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a819c)(param_2);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar1);
  if (iVar2 == 0) {
    return 1;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_X509_ALGOR_new_006a8fb8)();
  if (puVar3 == (undefined4 *)0x0) {
    uVar1 = 0x66;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(*puVar3);
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(param_2);
    *puVar3 = uVar1;
    if (param_3 < 1) {
LAB_005a8df8:
      (*(code *)PTR_sk_push_006a80a8)(param_1,puVar3);
      return 1;
    }
    iVar2 = (*(code *)PTR_ASN1_TYPE_new_006a8fbc)();
    puVar3[1] = iVar2;
    if (iVar2 == 0) {
      uVar1 = 0x6e;
    }
    else {
      iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
      if (iVar2 != 0) {
        iVar4 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar2,param_3);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x77,0x41,"pk7_attr.c",0x76);
          return 0;
        }
        puVar5 = (undefined4 *)puVar3[1];
        puVar5[1] = iVar2;
        *puVar5 = 2;
        goto LAB_005a8df8;
      }
      uVar1 = 0x72;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x77,0x41,"pk7_attr.c",uVar1);
  return 0;
}

