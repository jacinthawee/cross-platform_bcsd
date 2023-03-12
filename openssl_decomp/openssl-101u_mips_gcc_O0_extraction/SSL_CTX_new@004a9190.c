
SSL_CTX * SSL_CTX_new(SSL_METHOD *meth)

{
  undefined *puVar1;
  int iVar2;
  SSL_CTX *obj;
  long lVar3;
  cert_st *pcVar4;
  lhash_st_SSL_SESSION *plVar5;
  x509_store_st *pxVar6;
  X509_VERIFY_PARAM *pXVar7;
  EVP_MD *pEVar8;
  stack_st_X509_NAME *psVar9;
  stack_st_SSL_COMP *psVar10;
  undefined4 *puVar11;
  uint uVar12;
  char *pcVar13;
  _func_3076 *p_Var14;
  
  if (meth == (SSL_METHOD *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0xc4,"ssl_lib.c",0x6b3);
    return (SSL_CTX *)0x0;
  }
  iVar2 = SSL_get_ex_data_X509_STORE_CTX_idx();
  if (iVar2 < 0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0x10d,"ssl_lib.c",0x6be);
LAB_004a95b0:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0x41,"ssl_lib.c",0x774);
    return (SSL_CTX *)0x0;
  }
  obj = (SSL_CTX *)CRYPTO_malloc(0x1b8,"ssl_lib.c",0x6c1);
  if (obj == (SSL_CTX *)0x0) goto LAB_004a95b0;
  (*(code *)PTR_memset_006a99f4)(obj,0,0x1b8);
  p_Var14 = meth->get_timeout;
  obj->method = meth;
  obj->session_cache_mode = 2;
  obj->session_cache_size = 0x5000;
  obj->cert_store = (x509_store_st *)0x0;
  obj->session_cache_head = (ssl_session_st *)0x0;
  obj->session_cache_tail = (ssl_session_st *)0x0;
  lVar3 = (*p_Var14)();
  obj->session_timeout = lVar3;
  obj->new_session_cb = (_func_3087 *)0x0;
  obj->remove_session_cb = (_func_3088 *)0x0;
  obj->get_session_cb = (_func_3089 *)0x0;
  puVar1 = PTR_memset_006a99f4;
  obj->generate_session_id = (GEN_SESSION_CB)0x0;
  (*(code *)puVar1)(&obj->stats,0,0x2c);
  obj->quiet_shutdown = 0;
  obj->references = 1;
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
  pcVar4 = (cert_st *)ssl_cert_new();
  obj->cert = pcVar4;
  puVar1 = PTR_lh_new_006a740c;
  if (pcVar4 != (cert_st *)0x0) {
    obj->default_passwd_callback = (undefined1 *)0x0;
    obj->default_passwd_callback_userdata = (void *)0x0;
    obj->client_cert_cb = (_func_3091 *)0x0;
    obj->app_gen_cookie_cb = (_func_3092 *)0x0;
    obj->app_verify_cookie_cb = (_func_3093 *)0x0;
    plVar5 = (lhash_st_SSL_SESSION *)
             (*(code *)puVar1)(ssl_session_LHASH_HASH,ssl_session_LHASH_COMP);
    obj->sessions = plVar5;
    if (plVar5 != (lhash_st_SSL_SESSION *)0x0) {
      pxVar6 = (x509_store_st *)(*(code *)PTR_X509_STORE_new_006a7250)();
      obj->cert_store = pxVar6;
      if (pxVar6 != (x509_store_st *)0x0) {
        if (meth->version == 2) {
          pcVar13 = "SSLv2";
        }
        else {
          pcVar13 = "ALL:!EXPORT:!LOW:!aNULL:!eNULL:!SSLv2";
        }
        ssl_create_cipher_list(obj->method,&obj->cipher_list,&obj->cipher_list_by_id,pcVar13);
        if ((obj->cipher_list == (stack_st_SSL_CIPHER *)0x0) ||
           (iVar2 = (*(code *)PTR_sk_num_006a6e2c)(), iVar2 < 1)) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0xa1,"ssl_lib.c",0x707);
          goto LAB_004a9544;
        }
        pXVar7 = (X509_VERIFY_PARAM *)(*(code *)PTR_X509_VERIFY_PARAM_new_006a7c00)();
        obj->param = pXVar7;
        if (pXVar7 != (X509_VERIFY_PARAM *)0x0) {
          pEVar8 = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)("ssl2-md5");
          obj->rsa_md5 = pEVar8;
          if (pEVar8 == (EVP_MD *)0x0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0xf1,"ssl_lib.c",0x710);
            goto LAB_004a9544;
          }
          pEVar8 = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)("ssl3-md5");
          obj->md5 = pEVar8;
          if (pEVar8 == (EVP_MD *)0x0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0xf2,"ssl_lib.c",0x714);
            goto LAB_004a9544;
          }
          pEVar8 = (EVP_MD *)(*(code *)PTR_EVP_get_digestbyname_006a6f2c)("ssl3-sha1");
          obj->sha1 = pEVar8;
          if (pEVar8 == (EVP_MD *)0x0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0xf3,"ssl_lib.c",0x718);
            goto LAB_004a9544;
          }
          psVar9 = (stack_st_X509_NAME *)(*(code *)PTR_sk_new_null_006a6fa4)();
          obj->client_CA = psVar9;
          if (psVar9 != (stack_st_X509_NAME *)0x0) {
            CRYPTO_new_ex_data(2,obj,&obj->ex_data);
            iVar2 = meth->version;
            obj->extra_certs = (stack_st_X509 *)0x0;
            if (iVar2 != 0xfeff) {
              psVar10 = SSL_COMP_get_compression_methods();
              obj->comp_methods = psVar10;
            }
            puVar1 = PTR_RAND_bytes_006a7574;
            obj->tlsext_servername_callback = (_func_3097 *)0x0;
            obj->tlsext_servername_arg = (void *)0x0;
            obj->max_send_fragment = 0x4000;
            iVar2 = (*(code *)puVar1)(obj->tlsext_tick_key_name,0x10);
            if (((iVar2 < 1) ||
                (iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(obj->tlsext_tick_hmac_key,0x10),
                iVar2 < 1)) ||
               (iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(obj->tlsext_tick_aes_key,0x10), iVar2 < 1
               )) {
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
            puVar11 = (undefined4 *)CRYPTO_malloc(0xc,"ssl_lib.c",0x743);
            obj->rbuf_freelist = (ssl3_buf_freelist_st *)puVar11;
            if (puVar11 != (undefined4 *)0x0) {
              *puVar11 = 0;
              puVar11[1] = 0;
              puVar11[2] = 0;
              puVar11 = (undefined4 *)CRYPTO_malloc(0xc,"ssl_lib.c",0x749);
              obj->wbuf_freelist = (ssl3_buf_freelist_st *)puVar11;
              if (puVar11 != (undefined4 *)0x0) {
                uVar12 = obj->options;
                *puVar11 = 0;
                puVar11[1] = 0;
                puVar11[2] = 0;
                obj->client_cert_engine = (ENGINE *)0x0;
                obj->options = uVar12 | 0x1000004;
                return obj;
              }
              CRYPTO_free(obj->rbuf_freelist);
            }
          }
        }
      }
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa9,0x41,"ssl_lib.c",0x774);
LAB_004a9544:
  iVar2 = CRYPTO_add_lock(&obj->references,-1,0xc,"ssl_lib.c",0x795);
  if (0 < iVar2) {
    return (SSL_CTX *)0x0;
  }
  SSL_CTX_free_part_6(obj);
  return (SSL_CTX *)0x0;
}

