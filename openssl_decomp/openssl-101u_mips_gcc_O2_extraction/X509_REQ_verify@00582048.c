
int X509_REQ_verify(X509_REQ *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_verify_006a8d20)
                    (PTR_X509_REQ_INFO_it_006a8f84,a->sig_alg,a->signature,a->req_info,r);
  return iVar1;
}

