
int SSL_CTX_add_session(SSL_CTX *s,SSL_SESSION *c)

{
  SSL_SESSION *pSVar1;
  long lVar2;
  long lVar3;
  ssl_session_st *psVar4;
  ssl_session_st *psVar5;
  ssl_session_st *psVar6;
  _func_3088 *p_Var7;
  int iVar8;
  ssl_session_st **ppsVar9;
  bool bVar10;
  
  CRYPTO_add_lock((int *)(c->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x309);
  CRYPTO_lock(9,0xc,"ssl_sess.c",0x30e);
  pSVar1 = (SSL_SESSION *)lh_insert((_LHASH *)s->sessions,c);
  if (pSVar1 == c || pSVar1 == (SSL_SESSION *)0x0) {
    iVar8 = 0;
    if (pSVar1 != (SSL_SESSION *)0x0) {
      SSL_SESSION_free(pSVar1);
      goto LAB_00062480;
    }
  }
  else {
    psVar6 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x3c);
    if ((psVar6 != (ssl_session_st *)0x0) &&
       (psVar4 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x38),
       psVar4 != (ssl_session_st *)0x0)) {
      ppsVar9 = &s->session_cache_head;
      if (psVar6 == (ssl_session_st *)&s->session_cache_tail) {
        bVar10 = psVar4 != (ssl_session_st *)ppsVar9;
        if (bVar10) {
          s->session_cache_tail = psVar4;
        }
        if (bVar10) {
          *(ssl_session_st **)(psVar4->krb5_client_princ + 0x3c) = psVar6;
        }
        else {
          psVar6 = (ssl_session_st *)0x0;
        }
        if (!bVar10) {
          s->session_cache_head = psVar6;
        }
        if (!bVar10) {
          s->session_cache_tail = psVar6;
        }
      }
      else {
        bVar10 = psVar4 == (ssl_session_st *)ppsVar9;
        if (!bVar10) {
          *(ssl_session_st **)(psVar6->krb5_client_princ + 0x38) = psVar4;
        }
        if (bVar10) {
          s->session_cache_head = psVar6;
        }
        else {
          psVar4 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x38);
        }
        if (bVar10) {
          *(ssl_session_st ***)(psVar6->krb5_client_princ + 0x38) = ppsVar9;
        }
        if (!bVar10) {
          *(ssl_session_st **)(psVar4->krb5_client_princ + 0x3c) = psVar6;
        }
      }
      *(undefined4 *)(pSVar1->krb5_client_princ + 0x3c) = 0;
      *(undefined4 *)(pSVar1->krb5_client_princ + 0x38) = 0;
    }
    SSL_SESSION_free(pSVar1);
  }
  ppsVar9 = &s->session_cache_head;
  psVar6 = *(ssl_session_st **)(c->krb5_client_princ + 0x3c);
  if ((psVar6 != (ssl_session_st *)0x0) &&
     (psVar4 = *(ssl_session_st **)(c->krb5_client_princ + 0x38), psVar4 != (ssl_session_st *)0x0))
  {
    if (psVar6 == (ssl_session_st *)&s->session_cache_tail) {
      bVar10 = psVar4 != (ssl_session_st *)ppsVar9;
      if (bVar10) {
        s->session_cache_tail = psVar4;
      }
      if (bVar10) {
        *(ssl_session_st **)(psVar4->krb5_client_princ + 0x3c) = psVar6;
      }
      else {
        psVar6 = (ssl_session_st *)0x0;
      }
      if (!bVar10) {
        s->session_cache_head = psVar6;
      }
      if (!bVar10) {
        s->session_cache_tail = psVar6;
      }
    }
    else {
      bVar10 = psVar4 == (ssl_session_st *)ppsVar9;
      if (!bVar10) {
        *(ssl_session_st **)(psVar6->krb5_client_princ + 0x38) = psVar4;
      }
      if (bVar10) {
        s->session_cache_head = psVar6;
      }
      else {
        psVar4 = *(ssl_session_st **)(c->krb5_client_princ + 0x38);
      }
      if (bVar10) {
        *(ssl_session_st ***)(psVar6->krb5_client_princ + 0x38) = ppsVar9;
      }
      if (!bVar10) {
        *(ssl_session_st **)(psVar4->krb5_client_princ + 0x3c) = psVar6;
      }
    }
    *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
  }
  psVar6 = s->session_cache_head;
  if (psVar6 == (ssl_session_st *)0x0) {
    s->session_cache_head = c;
    s->session_cache_tail = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar9;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x3c) = &s->session_cache_tail;
  }
  else {
    *(ssl_session_st **)(c->krb5_client_princ + 0x3c) = psVar6;
    *(SSL_SESSION **)(psVar6->krb5_client_princ + 0x38) = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar9;
    s->session_cache_head = c;
  }
  lVar2 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
  if (0 < lVar2) {
    while( true ) {
      lVar2 = SSL_CTX_ctrl(s,0x14,0,(void *)0x0);
      lVar3 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
      if ((((lVar2 <= lVar3) || (psVar6 = s->session_cache_tail, psVar6 == (ssl_session_st *)0x0))
          || (psVar6->session_id_length == 0)) ||
         (psVar4 = (ssl_session_st *)lh_retrieve((_LHASH *)s->sessions,psVar6), psVar6 != psVar4))
      break;
      pSVar1 = (SSL_SESSION *)lh_delete((_LHASH *)s->sessions,psVar6);
      psVar4 = *(ssl_session_st **)(psVar6->krb5_client_princ + 0x3c);
      if ((psVar4 != (ssl_session_st *)0x0) &&
         (psVar5 = *(ssl_session_st **)(psVar6->krb5_client_princ + 0x38),
         psVar5 != (ssl_session_st *)0x0)) {
        if (psVar4 == (ssl_session_st *)&s->session_cache_tail) {
          bVar10 = psVar5 == (ssl_session_st *)ppsVar9;
          if (!bVar10) {
            s->session_cache_tail = psVar5;
          }
          if (bVar10) {
            s->session_cache_head = (ssl_session_st *)0x0;
          }
          if (bVar10) {
            s->session_cache_tail = (ssl_session_st *)0x0;
          }
          if (!bVar10) {
            *(ssl_session_st ***)(psVar5->krb5_client_princ + 0x3c) = &s->session_cache_tail;
          }
        }
        else {
          bVar10 = psVar5 == (ssl_session_st *)ppsVar9;
          if (!bVar10) {
            *(ssl_session_st **)(psVar4->krb5_client_princ + 0x38) = psVar5;
          }
          if (bVar10) {
            s->session_cache_head = psVar4;
          }
          else {
            psVar5 = *(ssl_session_st **)(psVar6->krb5_client_princ + 0x38);
          }
          if (bVar10) {
            *(ssl_session_st ***)(psVar4->krb5_client_princ + 0x38) = ppsVar9;
          }
          if (!bVar10) {
            *(ssl_session_st **)(psVar5->krb5_client_princ + 0x3c) = psVar4;
          }
        }
        *(undefined4 *)(psVar6->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(psVar6->krb5_client_princ + 0x38) = 0;
      }
      p_Var7 = s->remove_session_cb;
      *(undefined4 *)(pSVar1->krb5_client_princ + 4) = 1;
      if (p_Var7 != (_func_3088 *)0x0) {
        (*p_Var7)(s,pSVar1);
      }
      SSL_SESSION_free(pSVar1);
      (s->stats).sess_cache_full = (s->stats).sess_cache_full + 1;
    }
  }
  iVar8 = 1;
LAB_00062480:
  CRYPTO_lock(10,0xc,"ssl_sess.c",0x340);
  return iVar8;
}

