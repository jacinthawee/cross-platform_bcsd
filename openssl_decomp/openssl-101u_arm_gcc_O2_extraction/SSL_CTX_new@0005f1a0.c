
SSL_CTX * SSL_CTX_new(SSL_METHOD *meth)

{
  int iVar1;
  SSL_CTX *__s;
  long lVar2;
  cert_st *pcVar3;
  _LHASH *p_Var4;
  X509_STORE *pXVar5;
  X509_VERIFY_PARAM *pXVar6;
  EVP_MD *pEVar7;
  _STACK *p_Var8;
  stack_st_SSL_COMP *psVar9;
  undefined4 *puVar10;
  uint uVar11;
  _func_3076 *p_Var12;
  char *pcVar13;
  
  if (meth == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xa9,0xc4,"ssl_lib.c",0x6b3);
    return (SSL_CTX *)0x0;
  }
  iVar1 = SSL_get_ex_data_X509_STORE_CTX_idx();
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xa9,0x10d,"ssl_lib.c",0x6be);
LAB_0005f43c:
    ERR_put_error(0x14,0xa9,0x41,"ssl_lib.c",0x774);
    return (SSL_CTX *)0x0;
  }
  __s = (SSL_CTX *)CRYPTO_malloc(0x1b8,"ssl_lib.c",0x6c1);
  if (__s == (SSL_CTX *)0x0) goto LAB_0005f43c;
  memset(__s,0,0x1b8);
  __s->session_cache_mode = 2;
  __s->session_cache_size = 0x5000;
  __s->method = meth;
  p_Var12 = meth->get_timeout;
  __s->cert_store = (x509_store_st *)0x0;
  __s->session_cache_head = (ssl_session_st *)0x0;
  __s->session_cache_tail = (ssl_session_st *)0x0;
  lVar2 = (*p_Var12)();
  __s->new_session_cb = (_func_3087 *)0x0;
  __s->remove_session_cb = (_func_3088 *)0x0;
  __s->get_session_cb = (_func_3089 *)0x0;
  __s->generate_session_id = (GEN_SESSION_CB)0x0;
  __s->session_timeout = lVar2;
  memset(&__s->stats,0,0x2c);
  __s->quiet_shutdown = 0;
  __s->info_callback = (_func_3094 *)0x0;
  __s->app_verify_callback = (_func_3090 *)0x0;
  __s->app_verify_arg = (void *)0x0;
  __s->read_ahead = 0;
  __s->msg_callback = (_func_3095 *)0x0;
  __s->msg_callback_arg = (void *)0x0;
  __s->verify_mode = 0;
  __s->sid_ctx_length = 0;
  __s->default_verify_callback = (_func_3096 *)0x0;
  __s->references = 1;
  __s->max_cert_list = 0x19000;
  pcVar3 = (cert_st *)ssl_cert_new();
  __s->cert = pcVar3;
  if (pcVar3 != (cert_st *)0x0) {
    __s->default_passwd_callback = (undefined1 *)0x0;
    __s->default_passwd_callback_userdata = (void *)0x0;
    __s->client_cert_cb = (_func_3091 *)0x0;
    __s->app_gen_cookie_cb = (_func_3092 *)0x0;
    __s->app_verify_cookie_cb = (_func_3093 *)0x0;
    p_Var4 = lh_new(ssl_session_LHASH_HASH + 1,ssl_session_LHASH_COMP + 1);
    __s->sessions = (lhash_st_SSL_SESSION *)p_Var4;
    if (p_Var4 != (_LHASH *)0x0) {
      pXVar5 = X509_STORE_new();
      __s->cert_store = pXVar5;
      if (pXVar5 != (X509_STORE *)0x0) {
        pcVar13 = "ALL:!EXPORT:!LOW:!aNULL:!eNULL:!SSLv2";
        if (meth->version == 2) {
          pcVar13 = "SSLv2";
        }
        ssl_create_cipher_list(__s->method,&__s->cipher_list,&__s->cipher_list_by_id,pcVar13);
        if (((_STACK *)__s->cipher_list == (_STACK *)0x0) ||
           (iVar1 = sk_num((_STACK *)__s->cipher_list), iVar1 < 1)) {
          ERR_put_error(0x14,0xa9,0xa1,"ssl_lib.c",0x707);
          goto LAB_0005f416;
        }
        pXVar6 = X509_VERIFY_PARAM_new();
        __s->param = pXVar6;
        if (pXVar6 != (X509_VERIFY_PARAM *)0x0) {
          pEVar7 = EVP_get_digestbyname("ssl2-md5");
          __s->rsa_md5 = pEVar7;
          if (pEVar7 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0xa9,0xf1,"ssl_lib.c",0x710);
            goto LAB_0005f416;
          }
          pEVar7 = EVP_get_digestbyname("ssl3-md5");
          __s->md5 = pEVar7;
          if (pEVar7 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0xa9,0xf2,"ssl_lib.c",0x714);
            goto LAB_0005f416;
          }
          pEVar7 = EVP_get_digestbyname("ssl3-sha1");
          __s->sha1 = pEVar7;
          if (pEVar7 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0xa9,0xf3,"ssl_lib.c",0x718);
            goto LAB_0005f416;
          }
          p_Var8 = sk_new_null();
          __s->client_CA = (stack_st_X509_NAME *)p_Var8;
          if (p_Var8 != (_STACK *)0x0) {
            CRYPTO_new_ex_data(2,__s,&__s->ex_data);
            iVar1 = meth->version;
            __s->extra_certs = (stack_st_X509 *)0x0;
            if (iVar1 != 0xfeff) {
              psVar9 = SSL_COMP_get_compression_methods();
              __s->comp_methods = psVar9;
            }
            __s->max_send_fragment = 0x4000;
            __s->tlsext_servername_callback = (_func_3097 *)0x0;
            __s->tlsext_servername_arg = (void *)0x0;
            iVar1 = RAND_bytes(__s->tlsext_tick_key_name,0x10);
            if (((iVar1 < 1) || (iVar1 = RAND_bytes(__s->tlsext_tick_hmac_key,0x10), iVar1 < 1)) ||
               (iVar1 = RAND_bytes(__s->tlsext_tick_aes_key,0x10), iVar1 < 1)) {
              __s->options = __s->options | 0x4000;
            }
            __s->tlsext_status_cb = (_func_3099 *)0x0;
            __s->tlsext_status_arg = (void *)0x0;
            __s[1].remove_session_cb = (_func_3088 *)0x0;
            __s[1].stats.sess_connect = 0;
            __s->psk_identity_hint = (char *)0x0;
            __s->psk_client_callback = (_func_3101 *)0x0;
            __s->psk_server_callback = (_func_3102 *)0x0;
            SSL_CTX_SRP_CTX_init(__s);
            __s->freelist_max_len = 0x20;
            puVar10 = (undefined4 *)CRYPTO_malloc(0xc,"ssl_lib.c",0x743);
            __s->rbuf_freelist = (ssl3_buf_freelist_st *)puVar10;
            if (puVar10 != (undefined4 *)0x0) {
              *puVar10 = 0;
              puVar10[1] = 0;
              puVar10[2] = 0;
              puVar10 = (undefined4 *)CRYPTO_malloc(0xc,"ssl_lib.c",0x749);
              __s->wbuf_freelist = (ssl3_buf_freelist_st *)puVar10;
              if (puVar10 != (undefined4 *)0x0) {
                uVar11 = __s->options;
                *puVar10 = 0;
                puVar10[1] = 0;
                puVar10[2] = 0;
                __s->client_cert_engine = (ENGINE *)0x0;
                __s->options = uVar11 | 0x1000004;
                return __s;
              }
              CRYPTO_free(__s->rbuf_freelist);
            }
          }
        }
      }
    }
  }
  ERR_put_error(0x14,0xa9,0x41,"ssl_lib.c",0x774);
LAB_0005f416:
  SSL_CTX_free(__s);
  return (SSL_CTX *)0x0;
}

