
int EVP_PKEY_asn1_add0(EVP_PKEY_ASN1_METHOD *ameth)

{
  int iVar1;
  
  if (((app_methods != (_STACK *)0x0) ||
      (app_methods = sk_new(ameth_cmp + 1), app_methods != (_STACK *)0x0)) &&
     (iVar1 = sk_push(app_methods,ameth), iVar1 != 0)) {
    sk_sort(app_methods);
    return 1;
  }
  return 0;
}

