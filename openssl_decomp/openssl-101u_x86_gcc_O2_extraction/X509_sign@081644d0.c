
int X509_sign(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_CINF *data;
  int iVar1;
  
  data = x->cert_info;
  (data->enc).modified = 1;
  iVar1 = ASN1_item_sign((ASN1_ITEM *)X509_CINF_it,data->signature,x->sig_alg,x->signature,data,pkey
                         ,md);
  return iVar1;
}

