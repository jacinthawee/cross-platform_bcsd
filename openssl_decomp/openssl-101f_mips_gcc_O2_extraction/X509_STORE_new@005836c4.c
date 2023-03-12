
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_STORE * X509_STORE_new(void)

{
  undefined *puVar1;
  X509_STORE *pXVar2;
  stack_st_X509_OBJECT *psVar3;
  stack_st_X509_LOOKUP *psVar4;
  X509_VERIFY_PARAM *pXVar5;
  int iVar6;
  
  pXVar2 = (X509_STORE *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x48,"x509_lu.c",0xb6);
  if (pXVar2 != (X509_STORE *)0x0) {
    psVar3 = (stack_st_X509_OBJECT *)(*(code *)PTR_sk_new_006a91b4)(x509_object_cmp);
    pXVar2->objs = psVar3;
    puVar1 = PTR_sk_new_null_006a80a4;
    pXVar2->cache = 1;
    psVar4 = (stack_st_X509_LOOKUP *)(*(code *)puVar1)();
    pXVar2->get_cert_methods = psVar4;
    pXVar2->verify = (_func_1843 *)0x0;
    pXVar2->verify_cb = (_func_1844 *)0x0;
    pXVar5 = X509_VERIFY_PARAM_new();
    pXVar2->param = pXVar5;
    puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
    if (pXVar5 != (X509_VERIFY_PARAM *)0x0) {
      pXVar2->get_issuer = (_func_1845 *)0x0;
      pXVar2->check_issued = (_func_1846 *)0x0;
      pXVar2->check_revocation = (_func_1847 *)0x0;
      pXVar2->get_crl = (_func_1848 *)0x0;
      pXVar2->check_crl = (_func_1849 *)0x0;
      pXVar2->cert_crl = (_func_1850 *)0x0;
      pXVar2->lookup_certs = (_func_1851 *)0x0;
      pXVar2->lookup_crls = (_func_1852 *)0x0;
      pXVar2->cleanup = (_func_1853 *)0x0;
      iVar6 = (*(code *)puVar1)(4,pXVar2,&pXVar2->ex_data);
      if (iVar6 != 0) {
        pXVar2->references = 1;
        return pXVar2;
      }
      (*(code *)PTR_sk_free_006a7f80)(pXVar2->objs);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pXVar2);
    }
  }
  return (X509_STORE *)0x0;
}

