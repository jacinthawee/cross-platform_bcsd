
undefined4 cms_add_cipher_smcap(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a709c)(param_2);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a7394)(uVar1);
  if (iVar2 != 0) {
    if (param_3 < 1) {
      iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
      if (iVar2 == 0) {
        return 0;
      }
      iVar3 = 0;
      uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(param_2);
      uVar4 = 0xffffffff;
    }
    else {
      iVar3 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
      if ((iVar3 == 0) ||
         (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar3,param_3), iVar2 == 0)) {
        return 0;
      }
      iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
      if (iVar2 == 0) {
        (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar3);
        return 0;
      }
      uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(param_2);
      uVar4 = 2;
    }
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar1,uVar4,iVar3);
    iVar3 = *param_1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *param_1 = iVar3;
      if (iVar3 == 0) goto LAB_005b86d8;
    }
    iVar3 = (*(code *)PTR_sk_push_006a6fa8)(iVar3,iVar2);
    if (iVar3 == 0) {
LAB_005b86d8:
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(iVar2);
      return 0;
    }
  }
  return 1;
}

