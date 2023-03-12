
int OCSP_basic_add1_cert(OCSP_BASICRESP *resp,X509 *cert)

{
  int iVar1;
  stack_st_X509 *psVar2;
  
  psVar2 = resp->certs;
  if (psVar2 == (stack_st_X509 *)0x0) {
    psVar2 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
    resp->certs = psVar2;
    if (psVar2 == (stack_st_X509 *)0x0) {
      return 0;
    }
  }
  iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar2,cert);
  if (iVar1 == 0) {
    return 0;
  }
  (*(code *)PTR_CRYPTO_add_lock_006a9080)(&cert->references,1,3,"ocsp_srv.c",0xcc);
  return 1;
}

