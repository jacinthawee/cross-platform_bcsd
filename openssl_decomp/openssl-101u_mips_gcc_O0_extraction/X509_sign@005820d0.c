
int X509_sign(X509 *x,EVP_PKEY *pkey,EVP_MD *md)

{
  X509_CINF *pXVar1;
  int iVar2;
  ASN1_BIT_STRING *pAVar3;
  X509_ALGOR *pXVar4;
  
  pXVar1 = x->cert_info;
  pXVar4 = x->sig_alg;
  pAVar3 = x->signature;
  (pXVar1->enc).modified = 1;
  iVar2 = (*(code *)PTR_ASN1_item_sign_006a8f8c)
                    (PTR_X509_CINF_it_006a8f80,pXVar1->signature,pXVar4,pAVar3,pXVar1,pkey,md);
  return iVar2;
}

