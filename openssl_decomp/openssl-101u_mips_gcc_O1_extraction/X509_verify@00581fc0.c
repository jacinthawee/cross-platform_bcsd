
int X509_verify(X509 *a,EVP_PKEY *r)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_X509_ALGOR_cmp_006a8f7c)(a->sig_alg,a->cert_info->signature);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_ASN1_item_verify_006a8d20)
                    (PTR_X509_CINF_it_006a8f80,a->sig_alg,a->signature,a->cert_info,r);
  return iVar1;
}

