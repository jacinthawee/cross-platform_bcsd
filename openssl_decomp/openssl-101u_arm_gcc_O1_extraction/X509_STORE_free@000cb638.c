
void X509_STORE_free(X509_STORE *v)

{
  void *ptr;
  int iVar1;
  int iVar2;
  _STACK *p_Var3;
  
  if (v == (X509_STORE *)0x0) {
    return;
  }
  p_Var3 = (_STACK *)v->get_cert_methods;
  iVar2 = 0;
  do {
    iVar1 = sk_num(p_Var3);
    if (iVar1 <= iVar2) {
      sk_free(p_Var3);
      sk_pop_free((_STACK *)v->objs,cleanup + 1);
      CRYPTO_free_ex_data(4,v,&v->ex_data);
      if (v->param != (X509_VERIFY_PARAM *)0x0) {
        X509_VERIFY_PARAM_free(v->param);
      }
      CRYPTO_free(v);
      return;
    }
    ptr = sk_value(p_Var3,iVar2);
    iVar1 = *(int *)((int)ptr + 8);
    if (iVar1 != 0) {
      if (*(code **)(iVar1 + 0x10) != (code *)0x0) {
        (**(code **)(iVar1 + 0x10))();
        iVar1 = *(int *)((int)ptr + 8);
        if (iVar1 == 0) goto LAB_000cb660;
      }
      if (*(code **)(iVar1 + 8) != (code *)0x0) {
        (**(code **)(iVar1 + 8))(ptr);
      }
    }
LAB_000cb660:
    CRYPTO_free(ptr);
    iVar2 = iVar2 + 1;
  } while( true );
}

