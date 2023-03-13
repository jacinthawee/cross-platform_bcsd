
int PKCS7_add_certificate(PKCS7 *p7,X509 *x509)

{
  stack_st_X509 **ppsVar1;
  int iVar2;
  _STACK *p_Var3;
  int line;
  
  iVar2 = OBJ_obj2nid(p7->type);
  if ((iVar2 == 0x16) || (iVar2 == 0x18)) {
    ppsVar1 = &((p7->d).sign)->cert;
    if (((p7->d).sign)->cert == (stack_st_X509 *)0x0) {
      p_Var3 = sk_new_null();
      *ppsVar1 = (stack_st_X509 *)p_Var3;
    }
    if (*ppsVar1 != (stack_st_X509 *)0x0) {
      CRYPTO_add_lock(&x509->references,1,3,"pk7_lib.c",0x13a);
      iVar2 = sk_push((_STACK *)*ppsVar1,x509);
      if (iVar2 != 0) {
        return 1;
      }
      X509_free(x509);
      return 0;
    }
    line = 0x137;
    iVar2 = 0x41;
  }
  else {
    line = 0x130;
    iVar2 = 0x71;
  }
  ERR_put_error(0x21,100,iVar2,"pk7_lib.c",line);
  return 0;
}

