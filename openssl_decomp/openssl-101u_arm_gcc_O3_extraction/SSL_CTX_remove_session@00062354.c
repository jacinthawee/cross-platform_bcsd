
int SSL_CTX_remove_session(SSL_CTX *param_1,SSL_SESSION *c)

{
  SSL_SESSION *pSVar1;
  ssl_session_st *psVar2;
  ssl_session_st *psVar3;
  _func_3088 *p_Var4;
  bool bVar5;
  
  if ((c != (SSL_SESSION *)0x0) && (c->session_id_length != 0)) {
    CRYPTO_lock(9,0xc,"ssl_sess.c",0x350);
    pSVar1 = (SSL_SESSION *)lh_retrieve((_LHASH *)param_1->sessions,c);
    if (c != pSVar1) {
      CRYPTO_lock(10,0xc,"ssl_sess.c",0x358);
      return 0;
    }
    pSVar1 = (SSL_SESSION *)lh_delete((_LHASH *)param_1->sessions,c);
    psVar3 = *(ssl_session_st **)(c->krb5_client_princ + 0x3c);
    if ((psVar3 != (ssl_session_st *)0x0) &&
       (psVar2 = *(ssl_session_st **)(c->krb5_client_princ + 0x38), psVar2 != (ssl_session_st *)0x0)
       ) {
      if (psVar3 == (ssl_session_st *)&param_1->session_cache_tail) {
        bVar5 = psVar2 != (ssl_session_st *)&param_1->session_cache_head;
        if (bVar5) {
          param_1->session_cache_tail = psVar2;
        }
        if (bVar5) {
          *(ssl_session_st **)(psVar2->krb5_client_princ + 0x3c) = psVar3;
        }
        else {
          psVar3 = (ssl_session_st *)0x0;
        }
        if (!bVar5) {
          param_1->session_cache_head = psVar3;
        }
        if (!bVar5) {
          param_1->session_cache_tail = psVar3;
        }
      }
      else {
        bVar5 = psVar2 == (ssl_session_st *)&param_1->session_cache_head;
        if (!bVar5) {
          *(ssl_session_st **)(psVar3->krb5_client_princ + 0x38) = psVar2;
        }
        if (bVar5) {
          param_1->session_cache_head = psVar3;
        }
        else {
          psVar2 = *(ssl_session_st **)(c->krb5_client_princ + 0x38);
        }
        if (bVar5) {
          *(ssl_session_st **)(psVar3->krb5_client_princ + 0x38) = psVar2;
        }
        if (!bVar5) {
          *(ssl_session_st **)(psVar2->krb5_client_princ + 0x3c) = psVar3;
        }
      }
      *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
      *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
    }
    CRYPTO_lock(10,0xc,"ssl_sess.c",0x358);
    p_Var4 = param_1->remove_session_cb;
    *(undefined4 *)(pSVar1->krb5_client_princ + 4) = 1;
    if (p_Var4 != (_func_3088 *)0x0) {
      (*p_Var4)(param_1,pSVar1);
    }
    SSL_SESSION_free(pSVar1);
    return 1;
  }
  return 0;
}

