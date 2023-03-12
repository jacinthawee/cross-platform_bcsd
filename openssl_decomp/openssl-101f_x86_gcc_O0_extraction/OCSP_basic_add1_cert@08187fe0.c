
int OCSP_basic_add1_cert(OCSP_BASICRESP *resp,X509 *cert)

{
  int iVar1;
  _STACK *st;
  
  st = (_STACK *)resp->certs;
  if (st == (_STACK *)0x0) {
    st = sk_new_null();
    resp->certs = (stack_st_X509 *)st;
    if (st == (_STACK *)0x0) {
      return 0;
    }
  }
  iVar1 = sk_push(st,cert);
  if (iVar1 == 0) {
    return 0;
  }
  CRYPTO_add_lock(&cert->references,1,3,"ocsp_srv.c",0xcc);
  return 1;
}

