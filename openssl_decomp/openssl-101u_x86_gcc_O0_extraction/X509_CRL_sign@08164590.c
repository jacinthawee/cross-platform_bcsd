
int X509_CRL_sign(X509_CRL *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_CRL_INFO *data;
  int iVar1;
  
  data = x->crl;
  (data->enc).modified = 1;
  iVar1 = ASN1_item_sign((ASN1_ITEM *)X509_CRL_INFO_it,data->sig_alg,x->sig_alg,x->signature,data,
                         pkey,md);
  return iVar1;
}

