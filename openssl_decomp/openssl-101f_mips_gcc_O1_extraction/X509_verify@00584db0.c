
int X509_verify(X509 *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ASN1_item_verify_006a9e40)
                    (PTR_X509_CINF_it_006aa098,a->sig_alg,a->signature,a->cert_info,r);
  return iVar1;
}

