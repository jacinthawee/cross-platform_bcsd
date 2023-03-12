
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  SSL_CTX *pSVar1;
  cert_st *pcVar2;
  int iVar3;
  undefined4 uVar4;
  _func_3154 *p_Var5;
  undefined4 uVar6;
  undefined4 uVar7;
  cert_st *pcVar8;
  
  pSVar1 = (SSL_CTX *)ssl->psk_server_callback;
  pcVar8 = ssl->cert;
  if (pSVar1 != ctx) {
    pSVar1 = ctx;
    if (ctx == (SSL_CTX *)0x0) {
      pSVar1 = (SSL_CTX *)ssl->tls_session_secret_cb_arg;
    }
    pcVar2 = (cert_st *)ssl_cert_dup(pSVar1->cert);
    ssl->cert = pcVar2;
    if (pcVar8 != (cert_st *)0x0) {
      *(undefined4 *)(pcVar2 + 0x38) = *(undefined4 *)(pcVar8 + 0x38);
      *(undefined4 *)(pcVar2 + 0x44) = *(undefined4 *)(pcVar8 + 0x44);
      *(undefined4 *)(pcVar2 + 0x50) = *(undefined4 *)(pcVar8 + 0x50);
      *(undefined4 *)(pcVar2 + 0x5c) = *(undefined4 *)(pcVar8 + 0x5c);
      *(undefined4 *)(pcVar2 + 0x68) = *(undefined4 *)(pcVar8 + 0x68);
      *(undefined4 *)(pcVar2 + 0x74) = *(undefined4 *)(pcVar8 + 0x74);
      *(undefined4 *)(pcVar2 + 0x80) = *(undefined4 *)(pcVar8 + 0x80);
      *(undefined4 *)(pcVar2 + 0x8c) = *(undefined4 *)(pcVar8 + 0x8c);
      ssl_cert_free(pcVar8);
    }
    if (0x20 < ssl->sid_ctx_length) {
      OpenSSLDie("ssl_lib.c",0xb8e,"ssl->sid_ctx_length <= sizeof(ssl->sid_ctx)");
    }
    p_Var5 = ssl->psk_server_callback;
    if (((p_Var5 != (_func_3154 *)0x0) && (ssl->sid_ctx_length == *(size_t *)(p_Var5 + 0xc4))) &&
       (iVar3 = memcmp(ssl->sid_ctx,p_Var5 + 200,ssl->sid_ctx_length), iVar3 == 0)) {
      ssl->sid_ctx_length = pSVar1->sid_ctx_length;
      uVar4 = *(undefined4 *)(pSVar1->sid_ctx + 4);
      uVar6 = *(undefined4 *)(pSVar1->sid_ctx + 8);
      uVar7 = *(undefined4 *)(pSVar1->sid_ctx + 0xc);
      *(undefined4 *)ssl->sid_ctx = *(undefined4 *)pSVar1->sid_ctx;
      *(undefined4 *)(ssl->sid_ctx + 4) = uVar4;
      *(undefined4 *)(ssl->sid_ctx + 8) = uVar6;
      *(undefined4 *)(ssl->sid_ctx + 0xc) = uVar7;
      uVar4 = *(undefined4 *)(pSVar1->sid_ctx + 0x14);
      uVar6 = *(undefined4 *)(pSVar1->sid_ctx + 0x18);
      uVar7 = *(undefined4 *)(pSVar1->sid_ctx + 0x1c);
      *(undefined4 *)(ssl->sid_ctx + 0x10) = *(undefined4 *)(pSVar1->sid_ctx + 0x10);
      *(undefined4 *)(ssl->sid_ctx + 0x14) = uVar4;
      *(undefined4 *)(ssl->sid_ctx + 0x18) = uVar6;
      *(undefined4 *)(ssl->sid_ctx + 0x1c) = uVar7;
    }
    CRYPTO_add_lock(&pSVar1->references,1,0xc,"ssl_lib.c",0xb9d);
    if ((SSL_CTX *)ssl->psk_server_callback != (SSL_CTX *)0x0) {
      SSL_CTX_free((SSL_CTX *)ssl->psk_server_callback);
    }
    ssl->psk_server_callback = (_func_3154 *)pSVar1;
  }
  return pSVar1;
}

