
int X509_sign_ctx(X509 *x,EVP_MD_CTX *ctx)

{
  X509_CINF *pXVar1;
  int iVar2;
  X509_ALGOR *pXVar3;
  ASN1_BIT_STRING *pAVar4;
  
  pXVar1 = x->cert_info;
  pAVar4 = x->signature;
  pXVar3 = x->sig_alg;
  (pXVar1->enc).modified = 1;
  iVar2 = (*(code *)PTR_ASN1_item_sign_ctx_006a8f90)
                    (PTR_X509_CINF_it_006a8f80,pXVar1->signature,pXVar3,pAVar4,pXVar1,ctx,&_gp);
  return iVar2;
}

