
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
    uVar1 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(cert);
    iVar2 = (*(code *)PTR_X509_NAME_cmp_006a8030)(uVar5,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = *(int *)(piVar4[1] + 4);
    pAVar3 = (ASN1_OCTET_STRING *)(*(code *)PTR_X509_get_serialNumber_006a6f9c)(cert);
    UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_INTEGER_cmp_006a8d38;
LAB_005b8f34:
                    /* WARNING: Could not recover jumptable at 0x005b8f44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (*UNRECOVERED_JUMPTABLE)(iVar2,pAVar3);
    return iVar2;
  }
  if (*piVar4 == 1) {
    (*(code *)PTR_X509_check_purpose_006a771c)(cert,0xffffffff,0xffffffff);
    pAVar3 = cert->skid;
    if (pAVar3 != (ASN1_OCTET_STRING *)0x0) {
      iVar2 = piVar4[1];
      UNRECOVERED_JUMPTABLE = (code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0;
      goto LAB_005b8f34;
    }
  }
  return -1;
}

