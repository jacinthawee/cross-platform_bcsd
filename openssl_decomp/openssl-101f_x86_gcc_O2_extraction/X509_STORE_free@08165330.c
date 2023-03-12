
void X509_STORE_free(X509_STORE *v)

{
  _STACK *p_Var1;
  void *ptr;
  int iVar2;
  int iVar3;
  
  if (v == (X509_STORE *)0x0) {
    return;
  }
  p_Var1 = (_STACK *)v->get_cert_methods;
  iVar3 = 0;
  do {
    iVar2 = sk_num(p_Var1);
    if (iVar2 <= iVar3) {
      sk_free(p_Var1);
      sk_pop_free((_STACK *)v->objs,cleanup);
      CRYPTO_free_ex_data(4,v,&v->ex_data);
      if (v->param != (X509_VERIFY_PARAM *)0x0) {
        X509_VERIFY_PARAM_free(v->param);
      }
      CRYPTO_free(v);
      return;
    }
    ptr = sk_value(p_Var1,iVar3);
    iVar2 = *(int *)((int)ptr + 8);
    if (iVar2 != 0) {
      if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
        (**(code **)(iVar2 + 0x10))(ptr);
        iVar2 = *(int *)((int)ptr + 8);
        if (iVar2 == 0) goto LAB_0816538d;
      }
      if (*(code **)(iVar2 + 8) != (code *)0x0) {
        (**(code **)(iVar2 + 8))(ptr);
      }
    }
LAB_0816538d:
    iVar3 = iVar3 + 1;
    CRYPTO_free(ptr);
  } while( true );
}

