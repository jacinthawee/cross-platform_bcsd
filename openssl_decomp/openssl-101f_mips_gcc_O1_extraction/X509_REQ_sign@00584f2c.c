
int X509_REQ_sign(X509_REQ *x,EVP_PKEY *pkey,EVP_MD *md)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_sign_006aa0a4)
                    (PTR_X509_REQ_INFO_it_006aa09c,x->sig_alg,0,x->signature,x->req_info,pkey,md);
  return iVar1;
}

