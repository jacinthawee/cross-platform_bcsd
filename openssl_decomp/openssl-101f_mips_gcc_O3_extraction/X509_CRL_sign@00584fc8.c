
int X509_CRL_sign(X509_CRL *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_CRL_INFO *pXVar1;
  int iVar2;
  ASN1_BIT_STRING *pAVar3;
  X509_ALGOR *pXVar4;
  
  pXVar1 = x->crl;
  pXVar4 = x->sig_alg;
  pAVar3 = x->signature;
  (pXVar1->enc).modified = 1;
  iVar2 = (*(code *)PTR_ASN1_item_sign_006aa0a4)
                    (PTR_X509_CRL_INFO_it_006aa0ac,pXVar1->sig_alg,pXVar4,pAVar3,pXVar1,pkey,md);
  return iVar2;
}

