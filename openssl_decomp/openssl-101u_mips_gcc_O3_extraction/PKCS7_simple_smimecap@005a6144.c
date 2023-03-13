
int PKCS7_simple_smimecap(stack_st_X509_ALGOR *sk,int nid,int arg)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar1 = (undefined4 *)(*(code *)PTR_X509_ALGOR_new_006a7ec8)();
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x68;
  }
  else {
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(*puVar1);
    uVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(nid);
    *puVar1 = uVar2;
    if (arg < 1) {
LAB_005a6208:
      (*(code *)PTR_sk_push_006a6fa8)(sk,puVar1);
      return 1;
    }
    iVar3 = (*(code *)PTR_ASN1_TYPE_new_006a7ecc)();
    puVar1[1] = iVar3;
    if (iVar3 == 0) {
      uVar2 = 0x70;
    }
    else {
      iVar3 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
      if (iVar3 != 0) {
        iVar4 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar3,arg);
        if (iVar4 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x77,0x41,"pk7_attr.c",0x78);
          return 0;
        }
        puVar5 = (undefined4 *)puVar1[1];
        puVar5[1] = iVar3;
        *puVar5 = 2;
        goto LAB_005a6208;
      }
      uVar2 = 0x74;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x77,0x41,"pk7_attr.c",uVar2);
  return 0;
}

