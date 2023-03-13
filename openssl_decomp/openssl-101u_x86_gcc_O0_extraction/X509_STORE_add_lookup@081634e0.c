
X509_LOOKUP * X509_STORE_add_lookup(X509_STORE *v,X509_LOOKUP_METHOD *m)

{
  _STACK *p_Var1;
  _func_1835 *p_Var2;
  int iVar3;
  X509_LOOKUP *pXVar4;
  int iVar5;
  
  p_Var1 = (_STACK *)v->get_cert_methods;
  for (iVar5 = 0; iVar3 = sk_num(p_Var1), iVar5 < iVar3; iVar5 = iVar5 + 1) {
    pXVar4 = (X509_LOOKUP *)sk_value(p_Var1,iVar5);
    if (pXVar4->method == m) {
      return pXVar4;
    }
  }
  pXVar4 = (X509_LOOKUP *)CRYPTO_malloc(0x14,"x509_lu.c",0x45);
  if (pXVar4 != (X509_LOOKUP *)0x0) {
    pXVar4->init = 0;
    pXVar4->skip = 0;
    pXVar4->method = m;
    pXVar4->method_data = (char *)0x0;
    pXVar4->store_ctx = (X509_STORE *)0x0;
    if ((m->new_item == (_func_1834 *)0x0) || (iVar5 = (*m->new_item)(pXVar4), iVar5 != 0)) {
      pXVar4->store_ctx = v;
      iVar5 = sk_push((_STACK *)v->get_cert_methods,pXVar4);
      if (iVar5 != 0) {
        return pXVar4;
      }
      if ((pXVar4->method != (X509_LOOKUP_METHOD *)0x0) &&
         (p_Var2 = pXVar4->method->free, p_Var2 != (_func_1835 *)0x0)) {
        (*p_Var2)(pXVar4);
      }
      CRYPTO_free(pXVar4);
      return (X509_LOOKUP *)0x0;
    }
    CRYPTO_free(pXVar4);
  }
  return (X509_LOOKUP *)0x0;
}

