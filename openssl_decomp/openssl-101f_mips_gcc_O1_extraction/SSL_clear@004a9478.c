
int SSL_clear(SSL *s)

{
  int iVar1;
  uint uVar2;
  SSL_METHOD *pSVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  _func_3053 *p_Var7;
  
  if (s->method == (SSL_METHOD *)0x0) {
    uVar6 = 0xbc;
    uVar4 = 0xbe;
  }
  else {
    iVar1 = ssl_clear_bad_session();
    if (iVar1 == 0) {
      uVar2 = s->tlsext_hb_seq;
      s->error = 0;
      s->hit = 0;
      s->shutdown = 0;
    }
    else {
      SSL_SESSION_free(s->session);
      uVar2 = s->tlsext_hb_seq;
      s->session = (SSL_SESSION *)0x0;
      s->error = 0;
      s->hit = 0;
      s->shutdown = 0;
    }
    if (uVar2 == 0) {
      iVar1 = 0x6000;
      if (s->server == 0) {
        iVar1 = 0x5000;
      }
      iVar5 = s->method->version;
      s->type = 0;
      s->state = iVar1;
      s->rwstate = 1;
      s->version = iVar5;
      s->first_packet = iVar5;
      s->rstate = 0xf0;
      if (s->init_buf != (BUF_MEM *)0x0) {
        (*(code *)PTR_BUF_MEM_free_006a8594)();
        s->init_buf = (BUF_MEM *)0x0;
      }
      if (s->enc_read_ctx != (EVP_CIPHER_CTX *)0x0) {
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
        CRYPTO_free(s->enc_read_ctx);
        s->enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
      }
      if (s->enc_write_ctx != (EVP_CIPHER_CTX *)0x0) {
        (*(code *)PTR_EVP_CIPHER_CTX_cleanup_006a8b60)();
        CRYPTO_free(s->enc_write_ctx);
        s->enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
      }
      if (s->expand != (COMP_CTX *)0x0) {
        (*(code *)PTR_COMP_CTX_free_006a9210)();
        s->expand = (COMP_CTX *)0x0;
      }
      if (s->compress != (COMP_CTX *)0x0) {
        (*(code *)PTR_COMP_CTX_free_006a9210)();
        s->compress = (COMP_CTX *)0x0;
      }
      if (s->read_hash != (EVP_MD_CTX *)0x0) {
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)();
      }
      s->read_hash = (EVP_MD_CTX *)0x0;
      if (s->write_hash != (EVP_MD_CTX *)0x0) {
        (*(code *)PTR_EVP_MD_CTX_destroy_006a91c8)();
      }
      s->write_hash = (EVP_MD_CTX *)0x0;
      s->max_cert_list = 0;
      if ((s->in_handshake == 0) && (s->session == (SSL_SESSION *)0x0)) {
        pSVar3 = *(SSL_METHOD **)s->psk_server_callback;
        if (s->method != pSVar3) {
          (*s->method->ssl_free)(s);
          p_Var7 = (*(SSL_METHOD **)s->psk_server_callback)->ssl_new;
          s->method = *(SSL_METHOD **)s->psk_server_callback;
          iVar1 = (*p_Var7)(s);
          return (uint)(iVar1 != 0);
        }
      }
      else {
        pSVar3 = s->method;
      }
      (*pSVar3->ssl_clear)(s);
      return 1;
    }
    uVar6 = 0x44;
    uVar4 = 0xd4;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xa4,uVar6,"ssl_lib.c",uVar4);
  return 0;
}

