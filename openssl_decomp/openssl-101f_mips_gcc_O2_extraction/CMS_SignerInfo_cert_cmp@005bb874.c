
int CMS_SignerInfo_cert_cmp(CMS_SignerInfo *si,X509 *cert)

{
  undefined4 uVar1;
  int iVar2;
  ASN1_OCTET_STRING *pAVar3;
  int *piVar4;
  undefined4 uVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  piVar4 = *(int **)(si + 4);
  if (*piVar4 == 0) {
    uVar5 = *(undefined4 *)piVar4[1];
    uVar1 = (*(code *)PTR_X509_get_issuer_name_006a87d0)(cert);
    iVar2 = (*(code *)PTR_X509_NAME_cmp_006a918c)(uVar5,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = *(int *)(piVar4[1] + 4);
    pAVar3 = (ASN1_OCTET_STRING *)(*(code *)PTR_X509_get_serialNumber_006a809c)(cert);
    UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_INTEGER_cmp_006a9e58;
LAB_005bb8d4:
                    /* WARNING: Could not recover jumptable at 0x005bb8e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*UNRECOVERED_JUMPTABLE)(iVar2,pAVar3);
    return iVar2;
  }
  if (*piVar4 == 1) {
    (*(code *)PTR_X509_check_purpose_006a87e8)(cert,0xffffffff,0xffffffff);
    pAVar3 = cert->skid;
    if (pAVar3 != (ASN1_OCTET_STRING *)0x0) {
      iVar2 = piVar4[1];
      UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_OCTET_STRING_cmp_006a9ffc;
      goto LAB_005bb8d4;
    }
  }
  return -1;
}

