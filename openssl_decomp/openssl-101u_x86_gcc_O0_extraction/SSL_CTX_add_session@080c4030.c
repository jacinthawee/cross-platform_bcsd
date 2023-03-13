
int SSL_CTX_add_session(SSL_CTX *s,SSL_SESSION *c)

{
  int *piVar1;
  ssl_session_st *psVar2;
  ssl_session_st *psVar3;
  _func_3088 *p_Var4;
  int iVar5;
  SSL_SESSION *pSVar6;
  ssl_session_st *psVar7;
  long lVar8;
  ssl_session_st **ppsVar9;
  
  iVar5 = CRYPTO_add_lock((int *)(c->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x309);
  CRYPTO_lock(iVar5,9,&DAT_0000000c,(int)"ssl_sess.c");
  pSVar6 = (SSL_SESSION *)lh_insert((_LHASH *)s->sessions,c);
  if ((pSVar6 == (SSL_SESSION *)0x0) || (c == pSVar6)) {
    if (pSVar6 != (SSL_SESSION *)0x0) {
      iVar5 = 0;
      psVar7 = (ssl_session_st *)
               CRYPTO_add_lock((int *)(pSVar6->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if ((int)psVar7 < 1) {
        psVar7 = (ssl_session_st *)SSL_SESSION_free_part_2();
      }
      goto LAB_080c40b9;
    }
  }
  else {
    psVar7 = *(ssl_session_st **)(pSVar6->krb5_client_princ + 0x3c);
    if ((psVar7 != (ssl_session_st *)0x0) &&
       (psVar2 = *(ssl_session_st **)(pSVar6->krb5_client_princ + 0x38),
       psVar2 != (ssl_session_st *)0x0)) {
      ppsVar9 = &s->session_cache_head;
      if (psVar7 == (ssl_session_st *)&s->session_cache_tail) {
        if (psVar2 == (ssl_session_st *)ppsVar9) {
          s->session_cache_head = (ssl_session_st *)0x0;
          s->session_cache_tail = (ssl_session_st *)0x0;
        }
        else {
          s->session_cache_tail = psVar2;
          *(ssl_session_st **)(psVar2->krb5_client_princ + 0x3c) = psVar7;
        }
      }
      else if (psVar2 == (ssl_session_st *)ppsVar9) {
        s->session_cache_head = psVar7;
        *(ssl_session_st ***)(psVar7->krb5_client_princ + 0x38) = ppsVar9;
      }
      else {
        *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38) = psVar2;
        *(ssl_session_st **)(*(int *)(pSVar6->krb5_client_princ + 0x38) + 0xcc) = psVar7;
      }
      *(undefined4 *)(pSVar6->krb5_client_princ + 0x3c) = 0;
      *(undefined4 *)(pSVar6->krb5_client_princ + 0x38) = 0;
    }
    iVar5 = CRYPTO_add_lock((int *)(pSVar6->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar5 < 1) {
      SSL_SESSION_free_part_2();
    }
  }
  ppsVar9 = &s->session_cache_head;
  psVar7 = *(ssl_session_st **)(c->krb5_client_princ + 0x3c);
  if ((psVar7 != (ssl_session_st *)0x0) &&
     (psVar2 = *(ssl_session_st **)(c->krb5_client_princ + 0x38), psVar2 != (ssl_session_st *)0x0))
  {
    if (psVar7 == (ssl_session_st *)&s->session_cache_tail) {
      if ((ssl_session_st *)ppsVar9 == psVar2) {
        s->session_cache_head = (ssl_session_st *)0x0;
        s->session_cache_tail = (ssl_session_st *)0x0;
      }
      else {
        s->session_cache_tail = psVar2;
        *(ssl_session_st **)(psVar2->krb5_client_princ + 0x3c) = psVar7;
      }
    }
    else if ((ssl_session_st *)ppsVar9 == psVar2) {
      s->session_cache_head = psVar7;
      *(ssl_session_st ***)(psVar7->krb5_client_princ + 0x38) = ppsVar9;
    }
    else {
      *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38) = psVar2;
      *(ssl_session_st **)(*(int *)(c->krb5_client_princ + 0x38) + 0xcc) = psVar7;
    }
    *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
  }
  psVar7 = s->session_cache_head;
  if (psVar7 == (ssl_session_st *)0x0) {
    s->session_cache_head = c;
    s->session_cache_tail = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar9;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x3c) = &s->session_cache_tail;
  }
  else {
    *(ssl_session_st **)(c->krb5_client_princ + 0x3c) = psVar7;
    *(SSL_SESSION **)(psVar7->krb5_client_princ + 0x38) = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar9;
    s->session_cache_head = c;
  }
  psVar7 = (ssl_session_st *)SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
  if (0 < (int)psVar7) {
    while( true ) {
      lVar8 = SSL_CTX_ctrl(s,0x14,0,(void *)0x0);
      psVar7 = (ssl_session_st *)SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
      if ((((lVar8 <= (int)psVar7) ||
           (psVar2 = s->session_cache_tail, psVar2 == (ssl_session_st *)0x0)) ||
          (psVar7 = (ssl_session_st *)psVar2->session_id_length, psVar7 == (ssl_session_st *)0x0))
         || (psVar7 = (ssl_session_st *)lh_retrieve((_LHASH *)s->sessions,psVar2), psVar2 != psVar7)
         ) break;
      pSVar6 = (SSL_SESSION *)lh_delete((_LHASH *)s->sessions,psVar2);
      psVar7 = *(ssl_session_st **)(psVar2->krb5_client_princ + 0x3c);
      if ((psVar7 != (ssl_session_st *)0x0) &&
         (psVar3 = *(ssl_session_st **)(psVar2->krb5_client_princ + 0x38),
         psVar3 != (ssl_session_st *)0x0)) {
        if (psVar7 == (ssl_session_st *)&s->session_cache_tail) {
          if ((ssl_session_st *)ppsVar9 == psVar3) {
            s->session_cache_head = (ssl_session_st *)0x0;
            s->session_cache_tail = (ssl_session_st *)0x0;
          }
          else {
            s->session_cache_tail = psVar3;
            *(ssl_session_st ***)(psVar3->krb5_client_princ + 0x3c) = &s->session_cache_tail;
          }
        }
        else if ((ssl_session_st *)ppsVar9 == psVar3) {
          s->session_cache_head = psVar7;
          *(ssl_session_st ***)(psVar7->krb5_client_princ + 0x38) = ppsVar9;
        }
        else {
          *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38) = psVar3;
          *(ssl_session_st **)(*(int *)(psVar2->krb5_client_princ + 0x38) + 0xcc) = psVar7;
        }
        *(undefined4 *)(psVar2->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(psVar2->krb5_client_princ + 0x38) = 0;
      }
      p_Var4 = s->remove_session_cb;
      *(undefined4 *)(pSVar6->krb5_client_princ + 4) = 1;
      if (p_Var4 != (_func_3088 *)0x0) {
        (*p_Var4)(s,pSVar6);
      }
      iVar5 = CRYPTO_add_lock((int *)(pSVar6->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if (iVar5 < 1) {
        SSL_SESSION_free_part_2();
      }
      piVar1 = &(s->stats).sess_cache_full;
      *piVar1 = *piVar1 + 1;
    }
  }
  iVar5 = 1;
LAB_080c40b9:
  CRYPTO_lock((int)psVar7,10,&DAT_0000000c,(int)"ssl_sess.c");
  return iVar5;
}

