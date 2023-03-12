
int X509_REQ_verify(X509_REQ *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_verify_006a9e40)
                    (PTR_X509_REQ_INFO_it_006aa09c,a->sig_alg,a->signature,a->req_info,r);
  return iVar1;
}

