
undefined4 cms_set1_SignerIdentifier(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    iVar2 = (*(code *)PTR_ASN1_item_new_006a8654)(PTR_CMS_IssuerAndSerialNumber_it_006a9384);
    param_1[1] = iVar2;
    if (iVar2 == 0) goto LAB_005b89e0;
    uVar1 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(param_2);
    iVar2 = (*(code *)PTR_X509_NAME_set_006a8f2c)(iVar2,uVar1);
    if (iVar2 == 0) goto LAB_005b89e0;
    uVar3 = *(undefined4 *)(param_1[1] + 4);
    uVar1 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(param_2);
    iVar2 = (*(code *)PTR_ASN1_STRING_copy_006a8cb8)(uVar3,uVar1);
  }
  else {
    if (param_3 != 1) {
      uVar3 = 0x96;
      uVar1 = 0xe0;
LAB_005b8920:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x92,uVar3,"cms_sd.c",uVar1);
      return 0;
    }
    if (*(int *)(param_2 + 0x38) == 0) {
      uVar3 = 0xa0;
      uVar1 = 0xd7;
      goto LAB_005b8920;
    }
    iVar2 = (*(code *)PTR_ASN1_STRING_dup_006a8cbc)();
    param_1[1] = iVar2;
  }
  if (iVar2 != 0) {
    *param_1 = param_3;
    return 1;
  }
LAB_005b89e0:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x92,0x41,"cms_sd.c",0xe9);
  return 0;
}

