
int SSL_CTX_remove_session(SSL_CTX *param_1,SSL_SESSION *c)

{
  SSL_SESSION *pSVar1;
  int iVar2;
  ssl_session_st *psVar3;
  ssl_session_st *psVar4;
  _func_3088 *p_Var5;
  
  if ((c == (SSL_SESSION *)0x0) || (c->session_id_length == 0)) {
    return 0;
  }
  CRYPTO_lock(9,0xc,"ssl_sess.c",0x350);
  pSVar1 = (SSL_SESSION *)(*(code *)PTR_lh_retrieve_006a73b0)(param_1->sessions,c);
  if (c == pSVar1) {
    pSVar1 = (SSL_SESSION *)(*(code *)PTR_lh_delete_006a8390)(param_1->sessions,c);
    psVar4 = *(ssl_session_st **)(c->krb5_client_princ + 0x3c);
    if (psVar4 != (ssl_session_st *)0x0) {
      psVar3 = *(ssl_session_st **)(c->krb5_client_princ + 0x38);
      if (psVar3 != (ssl_session_st *)0x0) {
        if (psVar4 == (ssl_session_st *)&param_1->session_cache_tail) {
          if (psVar3 == (ssl_session_st *)&param_1->session_cache_head) {
            param_1->session_cache_head = (ssl_session_st *)0x0;
            param_1->session_cache_tail = (ssl_session_st *)0x0;
          }
          else {
            param_1->session_cache_tail = psVar3;
            *(ssl_session_st **)(psVar3->krb5_client_princ + 0x3c) = psVar4;
          }
        }
        else if (psVar3 == (ssl_session_st *)&param_1->session_cache_head) {
          param_1->session_cache_head = psVar4;
          *(ssl_session_st **)(psVar4->krb5_client_princ + 0x38) = psVar3;
        }
        else {
          *(ssl_session_st **)(psVar4->krb5_client_princ + 0x38) = psVar3;
          *(ssl_session_st **)(*(int *)(c->krb5_client_princ + 0x38) + 0xcc) = psVar4;
        }
        *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
      }
    }
    CRYPTO_lock(10,0xc,"ssl_sess.c",0x358);
    p_Var5 = param_1->remove_session_cb;
    *(undefined4 *)(pSVar1->krb5_client_princ + 4) = 1;
    if (p_Var5 != (_func_3088 *)0x0) {
      (*p_Var5)(param_1,pSVar1);
    }
    iVar2 = CRYPTO_add_lock((int *)(pSVar1->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (0 < iVar2) {
      return 1;
    }
    SSL_SESSION_free_part_2(pSVar1);
    iVar2 = 1;
  }
  else {
    CRYPTO_lock(10,0xc,"ssl_sess.c",0x358);
    iVar2 = 0;
  }
  return iVar2;
}

