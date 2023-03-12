
int cms_SignerIdentifier_cert_cmp(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (*param_1 == 0) {
    uVar4 = *(undefined4 *)param_1[1];
    uVar1 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(param_2);
    iVar3 = (*(code *)PTR_X509_NAME_cmp_006a8030)(uVar4,uVar1);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar2 = *(int *)(param_1[1] + 4);
    iVar3 = (*(code *)PTR_X509_get_serialNumber_006a6f9c)(param_2);
    UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_INTEGER_cmp_006a8d38;
LAB_005b8b34:
                    /* WARNING: Could not recover jumptable at 0x005b8b44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar3 = (*UNRECOVERED_JUMPTABLE)(iVar2,iVar3);
    return iVar3;
  }
  if (*param_1 == 1) {
    (*(code *)PTR_X509_check_purpose_006a771c)(param_2,0xffffffff,0xffffffff);
    iVar3 = *(int *)(param_2 + 0x38);
    if (iVar3 != 0) {
      iVar2 = param_1[1];
      UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0;
      goto LAB_005b8b34;
    }
  }
  return -1;
}

