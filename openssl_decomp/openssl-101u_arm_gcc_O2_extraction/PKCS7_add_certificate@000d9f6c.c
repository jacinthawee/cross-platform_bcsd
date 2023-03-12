
int PKCS7_add_certificate(PKCS7 *p7,X509 *x509)

{
  int iVar1;
  _STACK *p_Var2;
  stack_st_X509 **ppsVar3;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 != 0x18)) {
    ERR_put_error(0x21,100,0x71,"pk7_lib.c",0x130);
    return 0;
  }
  ppsVar3 = &((p7->d).sign)->cert;
  if (*ppsVar3 == (stack_st_X509 *)0x0) {
    p_Var2 = sk_new_null();
    *ppsVar3 = (stack_st_X509 *)p_Var2;
    if (p_Var2 == (_STACK *)0x0) {
      ERR_put_error(0x21,100,0x41,"pk7_lib.c",0x137);
      return 0;
    }
  }
  CRYPTO_add_lock(&x509->references,1,3,"pk7_lib.c",0x13a);
  iVar1 = sk_push((_STACK *)*ppsVar3,x509);
  if (iVar1 != 0) {
    return 1;
  }
  X509_free(x509);
  return 0;
}

