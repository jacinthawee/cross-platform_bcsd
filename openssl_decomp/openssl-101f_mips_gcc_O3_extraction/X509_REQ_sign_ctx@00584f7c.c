
int X509_REQ_sign_ctx(X509_REQ *x,EVP_MD_CTX *ctx)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_sign_ctx_006aa0a8)
                    (PTR_X509_REQ_INFO_it_006aa09c,x->sig_alg,0,x->signature,x->req_info,ctx,&_gp);
  return iVar1;
}

