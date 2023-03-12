
int X509_VERIFY_PARAM_add0_policy(X509_VERIFY_PARAM *param,ASN1_OBJECT *policy)

{
  int iVar1;
  _STACK *st;
  
  st = (_STACK *)param->policies;
  if (st == (_STACK *)0x0) {
    st = sk_new_null();
    param->policies = (stack_st_ASN1_OBJECT *)st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar1 = sk_push(st,policy);
  return (uint)(iVar1 != 0);
}

