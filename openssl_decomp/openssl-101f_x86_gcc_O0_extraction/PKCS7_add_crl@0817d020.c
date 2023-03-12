
int PKCS7_add_crl(PKCS7 *p7,X509_CRL *x509)

{
  stack_st_X509_CRL **ppsVar1;
  int iVar2;
  _STACK *p_Var3;
  int line;
  
  iVar2 = OBJ_obj2nid(p7->type);
  if ((iVar2 == 0x16) || (iVar2 == 0x18)) {
    ppsVar1 = &((p7->d).sign)->crl;
    if (((p7->d).sign)->crl == (stack_st_X509_CRL *)0x0) {
      p_Var3 = sk_new_null();
      *ppsVar1 = (stack_st_X509_CRL *)p_Var3;
    }
    if (*ppsVar1 != (stack_st_X509_CRL *)0x0) {
      CRYPTO_add_lock(&x509->references,1,6,"pk7_lib.c",0x165);
      iVar2 = sk_push((_STACK *)*ppsVar1,x509);
      if (iVar2 != 0) {
        return 1;
      }
      X509_CRL_free(x509);
      return 0;
    }
    line = 0x161;
    iVar2 = 0x41;
  }
  else {
    line = 0x159;
    iVar2 = 0x71;
  }
  ERR_put_error(0x21,0x65,iVar2,"pk7_lib.c",line);
  return 0;
}

