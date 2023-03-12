
int PKCS7_add_crl(PKCS7 *p7,X509_CRL *x509)

{
  int iVar1;
  _STACK *p_Var2;
  stack_st_X509_CRL **ppsVar3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 != 0x18)) {
    ERR_put_error(0x21,0x65,0x71,"pk7_lib.c",0x159);
    return 0;
  }
  ppsVar3 = &((p7->d).sign)->crl;
  if (*ppsVar3 == (stack_st_X509_CRL *)0x0) {
    p_Var2 = sk_new_null();
    *ppsVar3 = (stack_st_X509_CRL *)p_Var2;
    if (p_Var2 == (_STACK *)0x0) {
      ERR_put_error(0x21,0x65,0x41,"pk7_lib.c",0x161);
      return 0;
    }
  }
  CRYPTO_add_lock(&x509->references,1,6,"pk7_lib.c",0x165);
  iVar1 = sk_push((_STACK *)*ppsVar3,x509);
  if (iVar1 != 0) {
    return 1;
  }
  X509_CRL_free(x509);
  return 0;
}

