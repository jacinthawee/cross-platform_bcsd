
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VAL * X509_VAL_new(void)

{
  X509_VAL *pXVar1;
  
  pXVar1 = (X509_VAL *)(*(code *)PTR_ASN1_item_new_006a9778)(X509_VAL_it);
  return pXVar1;
}

