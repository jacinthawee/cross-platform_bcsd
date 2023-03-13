
int X509_CRL_sign_ctx(X509_CRL *x,EVP_MD_CTX *ctx)

{
  X509_CRL_INFO *pXVar1;
  int iVar2;
  X509_ALGOR *pXVar3;
  ASN1_BIT_STRING *pAVar4;
  
  pXVar1 = x->crl;
  pAVar4 = x->signature;
  pXVar3 = x->sig_alg;
  (pXVar1->enc).modified = 1;
  iVar2 = (*(code *)PTR_ASN1_item_sign_ctx_006a8f90)
                    (PTR_X509_CRL_INFO_it_006a8f94,pXVar1->sig_alg,pXVar3,pAVar4,pXVar1,ctx,&_gp);
  return iVar2;
}

