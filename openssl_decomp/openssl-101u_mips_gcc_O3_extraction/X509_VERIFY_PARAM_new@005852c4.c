
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VERIFY_PARAM * X509_VERIFY_PARAM_new(void)

{
  X509_VERIFY_PARAM *pXVar1;
  
  pXVar1 = (X509_VERIFY_PARAM *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x20,"x509_vpm.c",0x5d);
  if (pXVar1 == (X509_VERIFY_PARAM *)0x0) {
    pXVar1 = (X509_VERIFY_PARAM *)0x0;
  }
  else {
    (*(code *)PTR_memset_006a99f4)(pXVar1,0,0x20);
    pXVar1->name = (char *)0x0;
    pXVar1->purpose = 0;
    pXVar1->trust = 0;
    pXVar1->inh_flags = 0;
    pXVar1->flags = 0;
    pXVar1->depth = -1;
    if (pXVar1->policies == (stack_st_ASN1_OBJECT *)0x0) {
      return pXVar1;
    }
    (*(code *)PTR_sk_pop_free_006a7058)(pXVar1->policies,PTR_ASN1_OBJECT_free_006a7004);
    pXVar1->policies = (stack_st_ASN1_OBJECT *)0x0;
  }
  return pXVar1;
}

