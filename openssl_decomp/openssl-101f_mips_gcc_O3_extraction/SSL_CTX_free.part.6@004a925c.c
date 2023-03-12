
void SSL_CTX_free_part_6(SSL_CTX *param_1)

{
  void **ppvVar1;
  int iVar2;
  void *pvVar3;
  ssl3_buf_freelist_st *psVar4;
  
  if (param_1->param != (X509_VERIFY_PARAM *)0x0) {
    (*(code *)PTR_X509_VERIFY_PARAM_free_006a83cc)();
  }
  if (param_1->sessions != (lhash_st_SSL_SESSION *)0x0) {
    SSL_CTX_flush_sessions(param_1,0);
  }
  CRYPTO_free_ex_data(2,param_1,&param_1->ex_data);
  if (param_1->sessions != (lhash_st_SSL_SESSION *)0x0) {
    (*(code *)PTR_lh_free_006a8518)();
  }
  if (param_1->cert_store != (x509_store_st *)0x0) {
    (*(code *)PTR_X509_STORE_free_006a8384)();
  }
  if (param_1->cipher_list != (stack_st_SSL_CIPHER *)0x0) {
    (*(code *)PTR_sk_free_006a7f80)();
  }
  if (param_1->cipher_list_by_id != (stack_st_SSL_CIPHER *)0x0) {
    (*(code *)PTR_sk_free_006a7f80)();
  }
  if (param_1->cert != (cert_st *)0x0) {
    ssl_cert_free();
  }
  if (param_1->client_CA != (stack_st_X509_NAME *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(param_1->client_CA,PTR_X509_NAME_free_006a80f8);
  }
  if (param_1->extra_certs != (stack_st_X509 *)0x0) {
    (*(code *)PTR_sk_pop_free_006a8158)(param_1->extra_certs,PTR_X509_free_006a7f90);
  }
  iVar2 = param_1[1].stats.sess_connect_good;
  param_1->comp_methods = (stack_st_SSL_COMP *)0x0;
  if (iVar2 != 0) {
    (*(code *)PTR_sk_free_006a7f80)();
  }
  if (param_1->psk_identity_hint != (char *)0x0) {
    CRYPTO_free(param_1->psk_identity_hint);
  }
  SSL_CTX_SRP_CTX_free(param_1);
  if (param_1->client_cert_engine != (ENGINE *)0x0) {
    (*(code *)PTR_ENGINE_finish_006a80c4)();
  }
  psVar4 = param_1->wbuf_freelist;
  if (psVar4 != (ssl3_buf_freelist_st *)0x0) {
    ppvVar1 = (void **)*(void **)(psVar4 + 8);
    while (ppvVar1 != (void **)0x0) {
      pvVar3 = *ppvVar1;
      CRYPTO_free(ppvVar1);
      ppvVar1 = (void **)pvVar3;
    }
    CRYPTO_free(psVar4);
  }
  psVar4 = param_1->rbuf_freelist;
  if (psVar4 != (ssl3_buf_freelist_st *)0x0) {
    ppvVar1 = (void **)*(void **)(psVar4 + 8);
    while (ppvVar1 != (void **)0x0) {
      pvVar3 = *ppvVar1;
      CRYPTO_free(ppvVar1);
      ppvVar1 = (void **)pvVar3;
    }
    CRYPTO_free(psVar4);
  }
  CRYPTO_free(param_1);
  return;
}

