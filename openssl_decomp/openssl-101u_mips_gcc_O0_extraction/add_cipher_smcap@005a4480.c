
undefined4 add_cipher_smcap(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(param_2);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 == 0) {
    return 1;
  }
  puVar3 = (undefined4 *)(*(code *)PTR_X509_ALGOR_new_006a7ec8)();
  if (puVar3 == (undefined4 *)0x0) {
    uVar1 = 0x68;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(*puVar3);
    uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(param_2);
    *puVar3 = uVar1;
    if (param_3 < 1) {
LAB_005a6208:
      (*(code *)PTR_sk_push_006a6fa8)(param_1,puVar3);
      return 1;
    }
    iVar2 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
    puVar3[1] = iVar2;
    if (iVar2 == 0) {
      uVar1 = 0x70;
    }
    else {
      iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
      if (iVar2 != 0) {
        iVar4 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar2,param_3);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x77,0x41,"pk7_attr.c",0x78);
          return 0;
        }
        puVar5 = (undefined4 *)puVar3[1];
        puVar5[1] = iVar2;
        *puVar5 = 2;
        goto LAB_005a6208;
      }
      uVar1 = 0x74;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x77,0x41,"pk7_attr.c",uVar1);
  return 0;
}

