
int EVP_PKEY_asn1_add0(EVP_PKEY_ASN1_METHOD *ameth)

{
  int iVar1;
  
  if (((app_methods != 0) ||
      (app_methods = (*(code *)PTR_sk_new_006a91b4)(ameth_cmp), app_methods != 0)) &&
     (iVar1 = (*(code *)PTR_sk_push_006a80a8)(app_methods,ameth), iVar1 != 0)) {
    (*(code *)PTR_sk_sort_006a94d8)(app_methods);
    return 1;
  }
  return 0;
}

