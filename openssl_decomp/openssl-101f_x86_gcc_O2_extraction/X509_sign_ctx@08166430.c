
int X509_sign_ctx(X509 *x,EVP_MD_CTX *ctx)

{
  X509_CINF *asn;
  int iVar1;
  
  asn = x->cert_info;
  (asn->enc).modified = 1;
  iVar1 = ASN1_item_sign_ctx((ASN1_ITEM *)X509_CINF_it,asn->signature,x->sig_alg,x->signature,asn,
                             ctx);
  return iVar1;
}

