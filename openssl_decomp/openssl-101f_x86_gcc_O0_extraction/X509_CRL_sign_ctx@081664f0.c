
int X509_CRL_sign_ctx(X509_CRL *x,EVP_MD_CTX *ctx)

{
  X509_CRL_INFO *asn;
  int iVar1;
  
  asn = x->crl;
  (asn->enc).modified = 1;
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)X509_CRL_INFO_it,asn->sig_alg,x->sig_alg,x->signature,asn,
                             ctx);
  return iVar1;
}

