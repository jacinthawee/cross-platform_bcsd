
X509_EXTENSION * OCSP_archive_cutoff_new(char *tim)

{
  ASN1_GENERALIZEDTIME *s;
  ASN1_GENERALIZEDTIME *pAVar1;
  
  s = ASN1_GENERALIZEDTIME_new();
  if (s != (ASN1_GENERALIZEDTIME *)0x0) {
    pAVar1 = (ASN1_GENERALIZEDTIME *)ASN1_GENERALIZEDTIME_set_string(s,tim);
    if (pAVar1 != (ASN1_GENERALIZEDTIME *)0x0) {
      pAVar1 = (ASN1_GENERALIZEDTIME *)X509V3_EXT_i2d(0x172,0,s);
    }
    ASN1_GENERALIZEDTIME_free(s);
    s = pAVar1;
  }
  return (X509_EXTENSION *)s;
}

