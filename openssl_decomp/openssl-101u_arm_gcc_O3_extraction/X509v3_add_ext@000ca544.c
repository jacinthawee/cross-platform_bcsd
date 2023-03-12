
stack_st_X509_EXTENSION * X509v3_add_ext(stack_st_X509_EXTENSION **x,X509_EXTENSION *ex,int loc)

{
  uint where;
  X509_EXTENSION *a;
  int iVar1;
  _STACK *sk;
  bool bVar2;
  
  if (x == (stack_st_X509_EXTENSION **)0x0) {
    ERR_put_error(0xb,0x68,0x43,"x509_v3.c",0x98);
    return (stack_st_X509_EXTENSION *)0x0;
  }
  sk = (_STACK *)*x;
  if ((sk == (_STACK *)0x0) && (sk = sk_new_null(), sk == (_STACK *)0x0)) {
    ERR_put_error(0xb,0x68,0x41,"x509_v3.c",0xb0);
    return (stack_st_X509_EXTENSION *)0x0;
  }
  where = sk_num(sk);
  bVar2 = where < (uint)loc;
  if ((int)where < loc) {
    a = X509_EXTENSION_dup(ex);
  }
  else {
    where = where & loc >> 0x20;
    if (bVar2) {
      where = loc;
    }
    a = X509_EXTENSION_dup(ex);
  }
  if (a == (X509_EXTENSION *)0x0) {
    if (sk == (_STACK *)0x0) {
      return (stack_st_X509_EXTENSION *)0x0;
    }
  }
  else {
    iVar1 = sk_insert(sk,a,where);
    if (iVar1 != 0) {
      if (*x != (stack_st_X509_EXTENSION *)0x0) {
        return (stack_st_X509_EXTENSION *)sk;
      }
      *x = (stack_st_X509_EXTENSION *)sk;
      return (stack_st_X509_EXTENSION *)sk;
    }
    ERR_put_error(0xb,0x68,0x41,"x509_v3.c",0xb0);
    X509_EXTENSION_free(a);
  }
  sk_free(sk);
  return (stack_st_X509_EXTENSION *)0x0;
}

