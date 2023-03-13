
stack_st_X509_EXTENSION * X509v3_add_ext(stack_st_X509_EXTENSION **x,X509_EXTENSION *ex,int loc)

{
  int iVar1;
  X509_EXTENSION *a;
  _STACK *sk;
  int line;
  
  if (x == (stack_st_X509_EXTENSION **)0x0) {
    line = 0x98;
    iVar1 = 0x43;
  }
  else {
    sk = (_STACK *)*x;
    if ((sk != (_STACK *)0x0) || (sk = sk_new_null(), sk != (_STACK *)0x0)) {
      iVar1 = sk_num(sk);
      if ((iVar1 < loc) || (loc < 0)) {
        loc = iVar1;
      }
      a = X509_EXTENSION_dup(ex);
      if (a != (X509_EXTENSION *)0x0) {
        iVar1 = sk_insert(sk,a,loc);
        if (iVar1 != 0) {
          if (*x == (stack_st_X509_EXTENSION *)0x0) {
            *x = (stack_st_X509_EXTENSION *)sk;
            return (stack_st_X509_EXTENSION *)sk;
          }
          return (stack_st_X509_EXTENSION *)sk;
        }
        ERR_put_error(0xb,0x68,0x41,"x509_v3.c",0xb0);
        X509_EXTENSION_free(a);
      }
      sk_free(sk);
      return (stack_st_X509_EXTENSION *)0x0;
    }
    line = 0xb0;
    iVar1 = 0x41;
  }
  ERR_put_error(0xb,0x68,iVar1,"x509_v3.c",line);
  return (stack_st_X509_EXTENSION *)0x0;
}

