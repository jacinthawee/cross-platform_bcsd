
int SSL_CTX_add_session(SSL_CTX *s,SSL_SESSION *c)

{
  SSL_SESSION *pSVar1;
  ssl_session_st *psVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ssl_session_st *psVar6;
  ssl_session_st *psVar7;
  ssl_session_st **ppsVar8;
  _func_3088 *p_Var9;
  
  CRYPTO_add_lock((int *)(c->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x309);
  CRYPTO_lock(9,0xc,"ssl_sess.c",0x30e);
  pSVar1 = (SSL_SESSION *)(*(code *)PTR_lh_insert_006a7414)(s->sessions,c);
  if (pSVar1 != (SSL_SESSION *)0x0) {
    if (c == pSVar1) {
      iVar3 = CRYPTO_add_lock((int *)(c->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if (iVar3 < 1) {
        SSL_SESSION_free_part_2(c);
        iVar3 = 0;
      }
      else {
        iVar3 = 0;
      }
      goto LAB_004aee9c;
    }
    psVar2 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x3c);
    if (psVar2 != (ssl_session_st *)0x0) {
      psVar7 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x38);
      if (psVar7 != (ssl_session_st *)0x0) {
        ppsVar8 = &s->session_cache_head;
        if (psVar2 == (ssl_session_st *)&s->session_cache_tail) {
          if (psVar7 == (ssl_session_st *)ppsVar8) {
            s->session_cache_head = (ssl_session_st *)0x0;
            s->session_cache_tail = (ssl_session_st *)0x0;
          }
          else {
            s->session_cache_tail = psVar7;
            *(ssl_session_st **)(psVar7->krb5_client_princ + 0x3c) = psVar2;
          }
        }
        else if (psVar7 == (ssl_session_st *)ppsVar8) {
          s->session_cache_head = psVar2;
          *(ssl_session_st ***)(psVar2->krb5_client_princ + 0x38) = ppsVar8;
        }
        else {
          *(ssl_session_st **)(psVar2->krb5_client_princ + 0x38) = psVar7;
          *(ssl_session_st **)(*(int *)(pSVar1->krb5_client_princ + 0x38) + 0xcc) = psVar2;
        }
        *(undefined4 *)(pSVar1->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(pSVar1->krb5_client_princ + 0x38) = 0;
      }
    }
    iVar3 = CRYPTO_add_lock((int *)(pSVar1->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar3 < 1) {
      SSL_SESSION_free_part_2(pSVar1);
    }
  }
  ppsVar8 = &s->session_cache_head;
  psVar2 = *(ssl_session_st **)(c->krb5_client_princ + 0x3c);
  if (psVar2 != (ssl_session_st *)0x0) {
    psVar7 = *(ssl_session_st **)(c->krb5_client_princ + 0x38);
    if (psVar7 != (ssl_session_st *)0x0) {
      if (psVar2 == (ssl_session_st *)&s->session_cache_tail) {
        if ((ssl_session_st *)ppsVar8 == psVar7) {
          s->session_cache_head = (ssl_session_st *)0x0;
          s->session_cache_tail = (ssl_session_st *)0x0;
          *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
          *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
        }
        else {
          s->session_cache_tail = psVar7;
          *(ssl_session_st **)(psVar7->krb5_client_princ + 0x3c) = psVar2;
          *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
          *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
        }
      }
      else if ((ssl_session_st *)ppsVar8 == psVar7) {
        s->session_cache_head = psVar2;
        *(ssl_session_st ***)(psVar2->krb5_client_princ + 0x38) = ppsVar8;
        *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
      }
      else {
        *(ssl_session_st **)(psVar2->krb5_client_princ + 0x38) = psVar7;
        *(ssl_session_st **)(*(int *)(c->krb5_client_princ + 0x38) + 0xcc) = psVar2;
        *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
      }
    }
  }
  psVar2 = s->session_cache_head;
  if (psVar2 == (ssl_session_st *)0x0) {
    s->session_cache_head = c;
    s->session_cache_tail = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar8;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x3c) = &s->session_cache_tail;
  }
  else {
    *(ssl_session_st **)(c->krb5_client_princ + 0x3c) = psVar2;
    *(SSL_SESSION **)(psVar2->krb5_client_princ + 0x38) = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar8;
    s->session_cache_head = c;
  }
  lVar4 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
  if (0 < lVar4) {
    while( true ) {
      lVar4 = SSL_CTX_ctrl(s,0x14,0,(void *)0x0);
      lVar5 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
      if ((((lVar4 <= lVar5) || (psVar2 = s->session_cache_tail, psVar2 == (ssl_session_st *)0x0))
          || (psVar2->session_id_length == 0)) ||
         (psVar7 = (ssl_session_st *)(*(code *)PTR_lh_retrieve_006a73b0)(s->sessions,psVar2),
         psVar2 != psVar7)) break;
      pSVar1 = (SSL_SESSION *)(*(code *)PTR_lh_delete_006a8390)(s->sessions,psVar2);
      psVar7 = *(ssl_session_st **)(psVar2->krb5_client_princ + 0x3c);
      if ((psVar7 != (ssl_session_st *)0x0) &&
         (psVar6 = *(ssl_session_st **)(psVar2->krb5_client_princ + 0x38),
         psVar6 != (ssl_session_st *)0x0)) {
        if (psVar7 == (ssl_session_st *)&s->session_cache_tail) {
          if ((ssl_session_st *)ppsVar8 == psVar6) {
            s->session_cache_head = (ssl_session_st *)0x0;
            s->session_cache_tail = (ssl_session_st *)0x0;
          }
          else {
            s->session_cache_tail = psVar6;
            *(ssl_session_st ***)(psVar6->krb5_client_princ + 0x3c) = &s->session_cache_tail;
          }
        }
        else if ((ssl_session_st *)ppsVar8 == psVar6) {
          s->session_cache_head = psVar7;
          *(ssl_session_st ***)(psVar7->krb5_client_princ + 0x38) = ppsVar8;
        }
        else {
          *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38) = psVar6;
          *(ssl_session_st **)(*(int *)(psVar2->krb5_client_princ + 0x38) + 0xcc) = psVar7;
        }
        *(undefined4 *)(psVar2->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(psVar2->krb5_client_princ + 0x38) = 0;
      }
      p_Var9 = s->remove_session_cb;
      *(undefined4 *)(pSVar1->krb5_client_princ + 4) = 1;
      if (p_Var9 != (_func_3088 *)0x0) {
        (*p_Var9)(s,pSVar1);
      }
      iVar3 = CRYPTO_add_lock((int *)(pSVar1->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if (iVar3 < 1) {
        SSL_SESSION_free_part_2(pSVar1);
      }
      (s->stats).sess_cache_full = (s->stats).sess_cache_full + 1;
    }
  }
  iVar3 = 1;
LAB_004aee9c:
  CRYPTO_lock(10,0xc,"ssl_sess.c",0x340);
  return iVar3;
}

