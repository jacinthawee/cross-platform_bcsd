
int X509_verify(X509 *a,EVP_PKEY *r)

{
  int iVar1;
  int iVar2;
  
  iVar1 = X509_ALGOR_cmp(a->sig_alg,a->cert_info->signature);
  iVar2 = 0;
  if (iVar1 == 0) {
    iVar2 = ASN1_item_verify((ASN1_ITEM *)X509_CINF_it,a->sig_alg,a->signature,a->cert_info,r);
  }
  return iVar2;
}
