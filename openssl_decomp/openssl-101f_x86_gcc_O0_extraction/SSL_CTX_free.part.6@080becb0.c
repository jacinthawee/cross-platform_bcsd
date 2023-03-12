
void __regparm3 SSL_CTX_free_part_6(SSL_CTX *param_1)

{
  _STACK *p_Var1;
  ssl3_buf_freelist_st *psVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_1->param != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(param_1->param);
  }
  if (param_1->sessions != (lhash_st_SSL_SESSION *)0x0) {
    SSL_CTX_flush_sessions(param_1,0);
  }
  CRYPTO_free_ex_data(2,param_1,&param_1->ex_data);
  if ((_LHASH *)param_1->sessions != (_LHASH *)0x0) {
    lh_free((_LHASH *)param_1->sessions);
  }
  if (param_1->cert_store != (X509_STORE *)0x0) {
    X509_STORE_free(param_1->cert_store);
  }
  if ((_STACK *)param_1->cipher_list != (_STACK *)0x0) {
    sk_free((_STACK *)param_1->cipher_list);
  }
  if ((_STACK *)param_1->cipher_list_by_id != (_STACK *)0x0) {
    sk_free((_STACK *)param_1->cipher_list_by_id);
  }
  if (param_1->cert != (cert_st *)0x0) {
    ssl_cert_free(param_1->cert);
  }
  if ((_STACK *)param_1->client_CA != (_STACK *)0x0) {
    sk_pop_free((_STACK *)param_1->client_CA,X509_NAME_free);
  }
  if ((_STACK *)param_1->extra_certs != (_STACK *)0x0) {
    sk_pop_free((_STACK *)param_1->extra_certs,X509_free);
  }
  p_Var1 = (_STACK *)param_1[1].stats.sess_connect_good;
  param_1->comp_methods = (stack_st_SSL_COMP *)0x0;
  if (p_Var1 != (_STACK *)0x0) {
    sk_free(p_Var1);
  }
  if (param_1->psk_identity_hint != (char *)0x0) {
    CRYPTO_free(param_1->psk_identity_hint);
  }
  SSL_CTX_SRP_CTX_free(param_1);
  if (param_1->client_cert_engine != (ENGINE *)0x0) {
    ENGINE_finish(param_1->client_cert_engine);
  }
  psVar2 = param_1->wbuf_freelist;
  if (psVar2 != (ssl3_buf_freelist_st *)0x0) {
    puVar4 = *(undefined4 **)(psVar2 + 8);
    while (puVar4 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)*puVar4;
      CRYPTO_free(puVar4);
      puVar4 = puVar3;
    }
    CRYPTO_free(psVar2);
  }
  psVar2 = param_1->rbuf_freelist;
  if (psVar2 != (ssl3_buf_freelist_st *)0x0) {
    puVar4 = *(undefined4 **)(psVar2 + 8);
    while (puVar4 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)*puVar4;
      CRYPTO_free(puVar4);
      puVar4 = puVar3;
    }
    CRYPTO_free(psVar2);
  }
  CRYPTO_free(param_1);
  return;
}

