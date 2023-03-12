
int OCSP_id_get0_info(ASN1_OCTET_STRING **piNameHash,ASN1_OBJECT **pmd,ASN1_OCTET_STRING **pikeyHash
                     ,ASN1_INTEGER **pserial,OCSP_CERTID *cid)

{
  if (cid == (OCSP_CERTID *)0x0) {
    return 0;
  }
  if (pmd != (ASN1_OBJECT **)0x0) {
    *pmd = cid->hashAlgorithm->algorithm;
  }
  if (piNameHash != (ASN1_OCTET_STRING **)0x0) {
    *piNameHash = cid->issuerNameHash;
  }
  if (pikeyHash != (ASN1_OCTET_STRING **)0x0) {
    *pikeyHash = cid->issuerKeyHash;
  }
  if (pserial != (ASN1_INTEGER **)0x0) {
    *pserial = cid->serialNumber;
  }
  return 1;
}

