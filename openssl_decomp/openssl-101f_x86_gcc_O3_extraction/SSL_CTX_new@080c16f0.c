
SSL_CTX * SSL_CTX_new(SSL_METHOD *meth)

{
  int iVar1;
  SSL_CTX *obj;
  long lVar2;
  cert_st *pcVar3;
  _LHASH *p_Var4;
  X509_STORE *pXVar5;
  char *pcVar6;
  X509_VERIFY_PARAM *pXVar7;
  EVP_MD *pEVar8;
  _STACK *p_Var9;
  stack_st_SSL_COMP *psVar10;
  uint uVar11;
  undefined4 *puVar12;
  byte bVar13;
  
  bVar13 = 0;
  if (meth == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xa9,0xc4,"ssl_lib.c",0x695);
    return (SSL_CTX *)0x0;
  }
  iVar1 = SSL_get_ex_data_X509_STORE_CTX_idx();
  if (iVar1 < 0) {
    ERR_put_error(0x14,0xa9,0x10d,"ssl_lib.c",0x6a3);
LAB_080c1b79:
    ERR_put_error(0x14,0xa9,0x41,"ssl_lib.c",0x754);
    return (SSL_CTX *)0x0;
  }
  obj = (SSL_CTX *)CRYPTO_malloc(0x1b8,"ssl_lib.c",0x6a6);
  if (obj == (SSL_CTX *)0x0) goto LAB_080c1b79;
  obj[1].stats.sess_connect_good = 0;
  puVar12 = (undefined4 *)((uint)&obj->cipher_list & 0xfffffffc);
  uVar11 = (uint)((int)obj + (0x1b8 - (int)puVar12)) >> 2;
  for (; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + (uint)bVar13 * -2 + 1;
  }
  obj->method = meth;
  obj->cert_store = (x509_store_st *)0x0;
  obj->session_cache_mode = 2;
  obj->session_cache_size = 0x5000;
  obj->session_cache_head = (ssl_session_st *)0x0;
  obj->session_cache_tail = (ssl_session_st *)0x0;
  puVar12 = (undefined4 *)((uint)&(obj->stats).sess_connect_renegotiate & 0xfffffffc);
  lVar2 = (*meth->get_timeout)();
  (obj->stats).sess_connect = 0;
  (obj->stats).sess_cb_hit = 0;
  obj->session_timeout = lVar2;
  obj->new_session_cb = (_func_3087 *)0x0;
  obj->remove_session_cb = (_func_3088 *)0x0;
  obj->get_session_cb = (_func_3089 *)0x0;
  obj->generate_session_id = (GEN_SESSION_CB)0x0;
  uVar11 = (uint)((int)obj + (0x60 - (int)puVar12)) >> 2;
  for (; uVar11 != 0; uVar11 = uVar11 - 1) {
    *puVar12 = 0;
    puVar12 = puVar12 + (uint)bVar13 * -2 + 1;
  }
  obj->references = 1;
  obj->quiet_shutdown = 0;
  obj->info_callback = (_func_3094 *)0x0;
  obj->app_verify_callback = (_func_3090 *)0x0;
  obj->app_verify_arg = (void *)0x0;
  obj->max_cert_list = 0x19000;
  obj->read_ahead = 0;
  obj->msg_callback = (_func_3095 *)0x0;
  obj->msg_callback_arg = (void *)0x0;
  obj->verify_mode = 0;
  obj->sid_ctx_length = 0;
  obj->default_verify_callback = (_func_3096 *)0x0;
  pcVar3 = (cert_st *)ssl_cert_new();
  obj->cert = pcVar3;
  if (pcVar3 != (cert_st *)0x0) {
    obj->default_passwd_callback = (undefined1 *)0x0;
    obj->default_passwd_callback_userdata = (void *)0x0;
    obj->client_cert_cb = (_func_3091 *)0x0;
    obj->app_gen_cookie_cb = (_func_3092 *)0x0;
    obj->app_verify_cookie_cb = (_func_3093 *)0x0;
    p_Var4 = lh_new(ssl_session_LHASH_HASH,ssl_session_LHASH_COMP);
    obj->sessions = (lhash_st_SSL_SESSION *)p_Var4;
    if (p_Var4 != (_LHASH *)0x0) {
      pXVar5 = X509_STORE_new();
      obj->cert_store = pXVar5;
      if (pXVar5 != (X509_STORE *)0x0) {
        pcVar6 = "SSLv2";
        if (meth->version != 2) {
          pcVar6 = "ALL:!aNULL:!eNULL:!SSLv2";
        }
        ssl_create_cipher_list(obj->method,&obj->cipher_list,&obj->cipher_list_by_id,pcVar6);
        if (((_STACK *)obj->cipher_list == (_STACK *)0x0) ||
           (iVar1 = sk_num((_STACK *)obj->cipher_list), iVar1 < 1)) {
          ERR_put_error(0x14,0xa9,0xa1,"ssl_lib.c",0x6ea);
          goto LAB_080c1b1e;
        }
        pXVar7 = X509_VERIFY_PARAM_new();
        obj->param = pXVar7;
        if (pXVar7 != (X509_VERIFY_PARAM *)0x0) {
          pEVar8 = EVP_get_digestbyname("ssl2-md5");
          obj->rsa_md5 = pEVar8;
          if (pEVar8 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0xa9,0xf1,"ssl_lib.c",0x6f4);
            goto LAB_080c1b1e;
          }
          pEVar8 = EVP_get_digestbyname("ssl3-md5");
          obj->md5 = pEVar8;
          if (pEVar8 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0xa9,0xf2,"ssl_lib.c",0x6f9);
            goto LAB_080c1b1e;
          }
          pEVar8 = EVP_get_digestbyname("ssl3-sha1");
          obj->sha1 = pEVar8;
          if (pEVar8 == (EVP_MD *)0x0) {
            ERR_put_error(0x14,0xa9,0xf3,"ssl_lib.c",0x6fe);
            goto LAB_080c1b1e;
          }
          p_Var9 = sk_new_null();
          obj->client_CA = (stack_st_X509_NAME *)p_Var9;
          if (p_Var9 != (_STACK *)0x0) {
            CRYPTO_new_ex_data(2,obj,&obj->ex_data);
            iVar1 = meth->version;
            obj->extra_certs = (stack_st_X509 *)0x0;
            if (iVar1 != 0xfeff) {
              psVar10 = SSL_COMP_get_compression_methods();
              obj->comp_methods = psVar10;
            }
            obj->max_send_fragment = 0x4000;
            obj->tlsext_servername_callback = (_func_3097 *)0x0;
            obj->tlsext_servername_arg = (void *)0x0;
            iVar1 = RAND_pseudo_bytes(obj->tlsext_tick_key_name,0x10);
            if (((iVar1 < 1) || (iVar1 = RAND_bytes(obj->tlsext_tick_hmac_key,0x10), iVar1 < 1)) ||
               (iVar1 = RAND_bytes(obj->tlsext_tick_aes_key,0x10), iVar1 < 1)) {
              obj->options = obj->options | 0x4000;
            }
            obj->tlsext_status_cb = (_func_3099 *)0x0;
            obj->tlsext_status_arg = (void *)0x0;
            obj[1].remove_session_cb = (_func_3088 *)0x0;
            obj[1].stats.sess_connect = 0;
            obj->psk_identity_hint = (char *)0x0;
            obj->psk_client_callback = (_func_3101 *)0x0;
            obj->psk_server_callback = (_func_3102 *)0x0;
            SSL_CTX_SRP_CTX_init(obj);
            obj->freelist_max_len = 0x20;
            puVar12 = (undefined4 *)CRYPTO_malloc(0xc,"ssl_lib.c",0x729);
            obj->rbuf_freelist = (ssl3_buf_freelist_st *)puVar12;
            if (puVar12 != (undefined4 *)0x0) {
              *puVar12 = 0;
              puVar12[1] = 0;
              puVar12[2] = 0;
              puVar12 = (undefined4 *)CRYPTO_malloc(0xc,"ssl_lib.c",0x72f);
              obj->wbuf_freelist = (ssl3_buf_freelist_st *)puVar12;
              if (puVar12 != (undefined4 *)0x0) {
                *puVar12 = 0;
                puVar12[1] = 0;
                puVar12[2] = 0;
                obj->client_cert_engine = (ENGINE *)0x0;
                obj->options = obj->options | 4;
                return obj;
              }
              CRYPTO_free(obj->rbuf_freelist);
            }
          }
        }
      }
    }
  }
  ERR_put_error(0x14,0xa9,0x41,"ssl_lib.c",0x754);
LAB_080c1b1e:
  iVar1 = CRYPTO_add_lock(&obj->references,-1,0xc,"ssl_lib.c",0x773);
  if (iVar1 < 1) {
    SSL_CTX_free_part_6();
  }
  return (SSL_CTX *)0x0;
}

