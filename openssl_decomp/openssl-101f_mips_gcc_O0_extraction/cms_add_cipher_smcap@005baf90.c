
undefined4 cms_add_cipher_smcap(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a819c)(param_2);
  iVar2 = (*(code *)PTR_EVP_get_cipherbyname_006a8494)(uVar1);
  if (iVar2 != 0) {
    if (param_3 < 1) {
      iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
      if (iVar2 == 0) {
        return 0;
      }
      iVar3 = 0;
      uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(param_2);
      uVar4 = 0xffffffff;
    }
    else {
      iVar3 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
      if ((iVar3 == 0) ||
         (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar3,param_3), iVar2 == 0)) {
        return 0;
      }
      iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
      if (iVar2 == 0) {
        (*(code *)PTR_ASN1_INTEGER_free_006a7f94)(iVar3);
        return 0;
      }
      uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(param_2);
      uVar4 = 2;
    }
    (*(code *)PTR_X509_ALGOR_set0_006a9e04)(iVar2,uVar1,uVar4,iVar3);
    iVar3 = *param_1;
    if (iVar3 == 0) {
      iVar3 = (*(code *)PTR_sk_new_null_006a80a4)();
      *param_1 = iVar3;
      if (iVar3 == 0) goto LAB_005bb078;
    }
    iVar3 = (*(code *)PTR_sk_push_006a80a8)(iVar3,iVar2);
    if (iVar3 == 0) {
LAB_005bb078:
      (*(code *)PTR_X509_ALGOR_free_006a8f94)(iVar2);
      return 0;
    }
  }
  return 1;
}

