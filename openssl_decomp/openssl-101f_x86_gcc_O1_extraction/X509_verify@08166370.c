
int X509_verify(X509 *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = ASN1_item_verify((ASN1_ITEM *)X509_CINF_it,a->sig_alg,a->signature,a->cert_info,r);
  return iVar1;
}

