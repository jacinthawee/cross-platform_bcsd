
int OCSP_id_cmp(OCSP_CERTID *a,OCSP_CERTID *b)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_OBJ_cmp_006a8cc4)(a->hashAlgorithm->algorithm,b->hashAlgorithm->algorithm);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(a->issuerNameHash,b->issuerNameHash);
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_ASN1_OCTET_STRING_cmp_006a8ee0)(a->issuerKeyHash,b->issuerKeyHash);
      if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x005ad638. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)PTR_ASN1_INTEGER_cmp_006a8d38)(a->serialNumber,b->serialNumber);
        return iVar1;
      }
    }
  }
  return iVar1;
}
