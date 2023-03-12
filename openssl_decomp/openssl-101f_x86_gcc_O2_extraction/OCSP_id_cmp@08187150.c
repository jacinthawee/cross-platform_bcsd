
int OCSP_id_cmp(OCSP_CERTID *a,OCSP_CERTID *b)

{
  int iVar1;
  
  iVar1 = OBJ_cmp(a->hashAlgorithm->algorithm,b->hashAlgorithm->algorithm);
  if (iVar1 == 0) {
    iVar1 = ASN1_OCTET_STRING_cmp(a->issuerNameHash,b->issuerNameHash);
    if (iVar1 == 0) {
      iVar1 = ASN1_OCTET_STRING_cmp(a->issuerKeyHash,b->issuerKeyHash);
      if (iVar1 == 0) {
        iVar1 = ASN1_INTEGER_cmp(a->serialNumber,b->serialNumber);
        return iVar1;
      }
    }
  }
  return iVar1;
}

