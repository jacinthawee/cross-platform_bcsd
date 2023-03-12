
int X509_set_version(X509 *x,long version)

{
  ASN1_INTEGER *a;
  int iVar1;
  ASN1_STRING *pAVar2;
  X509_CINF *pXVar3;
  
  if (x != (X509 *)0x0) {
    pXVar3 = x->cert_info;
    a = pXVar3->version;
    if (a != (ASN1_INTEGER *)0x0) {
      iVar1 = ASN1_INTEGER_set(a,version);
      return iVar1;
    }
    pAVar2 = ASN1_STRING_type_new(2);
    pXVar3->version = pAVar2;
    if (pAVar2 != (ASN1_STRING *)0x0) {
      iVar1 = ASN1_INTEGER_set(x->cert_info->version,version);
      return iVar1;
    }
  }
  return 0;
}

