
X509_LOOKUP * X509_STORE_add_lookup(X509_STORE *v,X509_LOOKUP_METHOD *m)

{
  undefined *puVar1;
  int iVar2;
  X509_LOOKUP *pXVar3;
  int iVar4;
  stack_st_X509_LOOKUP *psVar5;
  _func_1834 *p_Var6;
  _func_1835 *p_Var7;
  
  psVar5 = v->get_cert_methods;
  iVar4 = 0;
  while( true ) {
    iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar5);
    if (iVar2 <= iVar4) break;
    pXVar3 = (X509_LOOKUP *)(*(code *)PTR_sk_value_006a6e24)(psVar5,iVar4);
    iVar4 = iVar4 + 1;
    if (pXVar3->method == m) {
      return pXVar3;
    }
  }
  pXVar3 = (X509_LOOKUP *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"x509_lu.c",0x45);
  if (pXVar3 != (X509_LOOKUP *)0x0) {
    p_Var6 = m->new_item;
    pXVar3->init = 0;
    pXVar3->skip = 0;
    pXVar3->method = m;
    pXVar3->method_data = (char *)0x0;
    pXVar3->store_ctx = (X509_STORE *)0x0;
    if ((p_Var6 == (_func_1834 *)0x0) || (iVar4 = (*p_Var6)(pXVar3), iVar4 != 0)) {
      puVar1 = PTR_sk_push_006a6fa8;
      psVar5 = v->get_cert_methods;
      pXVar3->store_ctx = v;
      iVar4 = (*(code *)puVar1)(psVar5,pXVar3);
      if (iVar4 != 0) {
        return pXVar3;
      }
      if ((pXVar3->method != (X509_LOOKUP_METHOD *)0x0) &&
         (p_Var7 = pXVar3->method->free, p_Var7 != (_func_1835 *)0x0)) {
        (*p_Var7)(pXVar3);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(pXVar3);
      return (X509_LOOKUP *)0x0;
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(pXVar3);
  }
  return (X509_LOOKUP *)0x0;
}

