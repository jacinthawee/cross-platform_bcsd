
int ssl_get_new_session(SSL *param_1,int param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  SSL_SESSION *pSVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  ssl_session_st *psVar8;
  ssl_session_st *psVar9;
  long lVar10;
  long lVar11;
  uchar *puVar12;
  ssl_session_st *psVar13;
  SSL_CTX *ctx;
  size_t sVar14;
  uint uVar15;
  undefined4 uVar16;
  ssl_session_st *psVar17;
  ssl_session_st **ppsVar18;
  SSL_SESSION *pSVar19;
  code *pcVar20;
  _func_3088 *p_Var21;
  uint local_30;
  SSL_CTX *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(SSL_CTX **)PTR___stack_chk_guard_006a9ae8;
  pSVar3 = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc4);
  if (pSVar3 == (SSL_SESSION *)0x0) {
    psVar17 = (ssl_session_st *)0xbd;
    iVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xbd,0x41,"ssl_sess.c",0xc6);
  }
  else {
    (*(code *)PTR_memset_006a99f4)(pSVar3,0,0xf4);
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x10) = 1;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x14) = 1;
    puVar1 = PTR_time_006a9adc;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x18) = 0x130;
    uVar4 = (*(code *)puVar1)(0);
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x1c) = uVar4;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x38) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x20) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x40) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x44) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x48) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x4c) = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x50) = 0;
    CRYPTO_new_ex_data(3,pSVar3,(CRYPTO_EX_DATA *)(pSVar3->krb5_client_princ + 0x30));
    pvVar5 = param_1->tls_session_secret_cb_arg;
    pSVar3->krb5_client_princ_len = 0;
    *(undefined4 *)pSVar3->krb5_client_princ = 0;
    *(undefined4 *)(pSVar3->krb5_client_princ + 0x60) = 0;
    iVar6 = *(int *)((int)pvVar5 + 0x24);
    if (iVar6 == 0) {
      lVar10 = SSL_get_default_timeout(param_1);
      *(long *)(pSVar3->krb5_client_princ + 0x18) = lVar10;
    }
    else {
      *(int *)(pSVar3->krb5_client_princ + 0x18) = iVar6;
    }
    pSVar19 = param_1->session;
    if (pSVar19 != (SSL_SESSION *)0x0) {
      iVar6 = CRYPTO_add_lock((int *)(pSVar19->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if (iVar6 < 1) {
        SSL_SESSION_free_part_2(pSVar19);
        param_1->session = (SSL_SESSION *)0x0;
      }
      else {
        param_1->session = (SSL_SESSION *)0x0;
      }
    }
    if (param_2 == 0) {
      pSVar3->session_id_length = 0;
LAB_004ae7b8:
      uVar15 = param_1->sid_ctx_length;
joined_r0x004ae97c:
      if (0x20 < uVar15) {
        uVar16 = 0x44;
        uVar4 = 0x230;
LAB_004ae998:
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb5,uVar16,"ssl_sess.c",uVar4);
        goto LAB_004ae9b0;
      }
      psVar17 = (ssl_session_st *)param_1->sid_ctx;
      iVar6 = 1;
      (*(code *)PTR_memcpy_006a9aec)(pSVar3->sid_ctx);
      iVar7 = param_1->version;
      pSVar3->sid_ctx_length = param_1->sid_ctx_length;
      param_1->session = pSVar3;
      pSVar3->ssl_version = iVar7;
      *(undefined4 *)(pSVar3->krb5_client_princ + 0x10) = 0;
    }
    else {
      iVar7 = param_1->version;
      if (iVar7 != 2) {
        if ((((iVar7 == 0x300) || (iVar7 == 0x301)) || (iVar7 == 0x302)) ||
           (((iVar7 == 0x303 || (iVar7 == 0x100)) || (iVar7 == 0xfeff)))) {
          iVar6 = param_1->tlsext_ocsp_resplen;
          pSVar3->ssl_version = iVar7;
          pSVar3->session_id_length = 0x20;
          goto joined_r0x004ae87c;
        }
        uVar16 = 0x103;
        uVar4 = 0x1c0;
        goto LAB_004ae998;
      }
      iVar6 = param_1->tlsext_ocsp_resplen;
      pSVar3->ssl_version = 2;
      pSVar3->session_id_length = 0x10;
joined_r0x004ae87c:
      if (iVar6 == 0) {
        CRYPTO_lock(5,0xc,"ssl_sess.c",0x1da);
        pcVar20 = param_1->generate_session_id;
        if ((pcVar20 == (GEN_SESSION_CB)0x0) &&
           (pcVar20 = *(GEN_SESSION_CB *)((int)param_1->tls_session_secret_cb_arg + 0xec),
           pcVar20 == (GEN_SESSION_CB)0x0)) {
          pcVar20 = def_generate_session_id;
        }
        puVar12 = pSVar3->session_id;
        CRYPTO_lock(6,0xc,"ssl_sess.c",0x1df);
        local_30 = pSVar3->session_id_length;
        iVar7 = (*pcVar20)(param_1,puVar12,&local_30);
        if (iVar7 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb5,0x12d,"ssl_sess.c",0x1e5);
          goto LAB_004ae9b0;
        }
        if (local_30 == 0) {
LAB_004aeaf8:
          uVar16 = 0x12f;
          uVar4 = 0x1f0;
        }
        else {
          uVar15 = pSVar3->session_id_length;
          if (uVar15 < local_30) goto LAB_004aeaf8;
          if ((local_30 < uVar15) && (param_1->version == 2)) {
            (*(code *)PTR_memset_006a99f4)(puVar12 + local_30,0,uVar15 - local_30);
            uVar15 = pSVar3->session_id_length;
          }
          else {
            pSVar3->session_id_length = local_30;
            uVar15 = local_30;
          }
          iVar7 = SSL_has_matching_session_id(param_1,puVar12,uVar15);
          if (iVar7 == 0) goto LAB_004ae888;
          uVar16 = 0x12e;
          uVar4 = 0x1fc;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb5,uVar16,"ssl_sess.c",uVar4);
        psVar17 = (ssl_session_st *)0xffffffff;
        iVar7 = CRYPTO_add_lock((int *)(pSVar3->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c)
        ;
        if (iVar7 < 1) {
          SSL_SESSION_free_part_2(pSVar3);
          goto LAB_004ae7f8;
        }
      }
      else {
        pSVar3->session_id_length = 0;
LAB_004ae888:
        if (param_1->tlsext_debug_arg != (void *)0x0) {
          iVar6 = (*(code *)PTR_BUF_strdup_006a6fdc)();
          *(int *)(pSVar3->krb5_client_princ + 0x40) = iVar6;
          if (iVar6 == 0) {
            uVar16 = 0x44;
            uVar4 = 0x205;
            goto LAB_004ae998;
          }
        }
        if (param_1->tlsext_ecpointformatlist_length == 0) {
LAB_004ae910:
          if (param_1->tlsext_ellipticcurvelist_length == 0) goto LAB_004ae7b8;
          if (*(void **)(pSVar3->krb5_client_princ + 0x50) != (void *)0x0) {
            CRYPTO_free(*(void **)(pSVar3->krb5_client_princ + 0x50));
          }
          pvVar5 = CRYPTO_malloc((int)param_1->tlsext_ecpointformatlist,"ssl_sess.c",0x21e);
          *(void **)(pSVar3->krb5_client_princ + 0x50) = pvVar5;
          puVar1 = PTR_memcpy_006a9aec;
          if (pvVar5 != (void *)0x0) {
            puVar12 = param_1->tlsext_ecpointformatlist;
            sVar14 = param_1->tlsext_ellipticcurvelist_length;
            *(uchar **)(pSVar3->krb5_client_princ + 0x4c) = puVar12;
            (*(code *)puVar1)(pvVar5,sVar14,puVar12);
            uVar15 = param_1->sid_ctx_length;
            goto joined_r0x004ae97c;
          }
          uVar4 = 0x220;
        }
        else {
          if (*(void **)(pSVar3->krb5_client_princ + 0x48) != (void *)0x0) {
            CRYPTO_free(*(void **)(pSVar3->krb5_client_princ + 0x48));
          }
          pvVar5 = CRYPTO_malloc(param_1->tlsext_ticket_expected,"ssl_sess.c",0x20f);
          *(void **)(pSVar3->krb5_client_princ + 0x48) = pvVar5;
          puVar1 = PTR_memcpy_006a9aec;
          if (pvVar5 != (void *)0x0) {
            iVar6 = param_1->tlsext_ticket_expected;
            sVar14 = param_1->tlsext_ecpointformatlist_length;
            *(int *)(pSVar3->krb5_client_princ + 0x44) = iVar6;
            (*(code *)puVar1)(pvVar5,sVar14,iVar6);
            goto LAB_004ae910;
          }
          uVar4 = 0x211;
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xb5,0x41,"ssl_sess.c",uVar4);
LAB_004ae9b0:
        psVar17 = (ssl_session_st *)0xffffffff;
        iVar6 = CRYPTO_add_lock((int *)(pSVar3->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c)
        ;
        if (iVar6 < 1) {
          SSL_SESSION_free_part_2(pSVar3);
          iVar6 = 0;
          goto LAB_004ae7f8;
        }
      }
      iVar6 = 0;
    }
  }
LAB_004ae7f8:
  if (local_2c == *(SSL_CTX **)puVar2) {
    return iVar6;
  }
  ctx = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  CRYPTO_add_lock((int *)((int)psVar17->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x309);
  CRYPTO_lock(9,0xc,"ssl_sess.c",0x30e);
  psVar8 = (ssl_session_st *)(*(code *)PTR_lh_insert_006a7414)(ctx->sessions,psVar17);
  if (psVar8 != (ssl_session_st *)0x0) {
    if (psVar17 == psVar8) {
      iVar6 = CRYPTO_add_lock((int *)((int)psVar17->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",
                              0x36c);
      if (iVar6 < 1) {
        SSL_SESSION_free_part_2(psVar17);
        iVar6 = 0;
      }
      else {
        iVar6 = 0;
      }
      goto LAB_004aee9c;
    }
    psVar9 = *(ssl_session_st **)(psVar8->krb5_client_princ + 0x3c);
    if (psVar9 != (ssl_session_st *)0x0) {
      psVar13 = *(ssl_session_st **)(psVar8->krb5_client_princ + 0x38);
      if (psVar13 != (ssl_session_st *)0x0) {
        ppsVar18 = &ctx->session_cache_head;
        if (psVar9 == (ssl_session_st *)&ctx->session_cache_tail) {
          if (psVar13 == (ssl_session_st *)ppsVar18) {
            ctx->session_cache_head = (ssl_session_st *)0x0;
            ctx->session_cache_tail = (ssl_session_st *)0x0;
          }
          else {
            ctx->session_cache_tail = psVar13;
            *(ssl_session_st **)(psVar13->krb5_client_princ + 0x3c) = psVar9;
          }
        }
        else if (psVar13 == (ssl_session_st *)ppsVar18) {
          ctx->session_cache_head = psVar9;
          *(ssl_session_st ***)(psVar9->krb5_client_princ + 0x38) = ppsVar18;
        }
        else {
          *(ssl_session_st **)(psVar9->krb5_client_princ + 0x38) = psVar13;
          *(ssl_session_st **)(*(int *)(psVar8->krb5_client_princ + 0x38) + 0xcc) = psVar9;
        }
        *(undefined4 *)(psVar8->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(psVar8->krb5_client_princ + 0x38) = 0;
      }
    }
    iVar6 = CRYPTO_add_lock((int *)(psVar8->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
    if (iVar6 < 1) {
      SSL_SESSION_free_part_2(psVar8);
    }
  }
  ppsVar18 = &ctx->session_cache_head;
  psVar8 = *(ssl_session_st **)((int)psVar17->krb5_client_princ + 0x3c);
  if (psVar8 != (ssl_session_st *)0x0) {
    psVar9 = *(ssl_session_st **)((int)psVar17->krb5_client_princ + 0x38);
    if (psVar9 != (ssl_session_st *)0x0) {
      if (psVar8 == (ssl_session_st *)&ctx->session_cache_tail) {
        if ((ssl_session_st *)ppsVar18 == psVar9) {
          ctx->session_cache_head = (ssl_session_st *)0x0;
          ctx->session_cache_tail = (ssl_session_st *)0x0;
          *(tls_session_secret_cb_fn *)((int)psVar17->krb5_client_princ + 0x3c) =
               (tls_session_secret_cb_fn)0x0;
          *(void **)((int)psVar17->krb5_client_princ + 0x38) = (void *)0x0;
        }
        else {
          ctx->session_cache_tail = psVar9;
          *(ssl_session_st **)(psVar9->krb5_client_princ + 0x3c) = psVar8;
          *(tls_session_secret_cb_fn *)((int)psVar17->krb5_client_princ + 0x3c) =
               (tls_session_secret_cb_fn)0x0;
          *(void **)((int)psVar17->krb5_client_princ + 0x38) = (void *)0x0;
        }
      }
      else if ((ssl_session_st *)ppsVar18 == psVar9) {
        ctx->session_cache_head = psVar8;
        *(ssl_session_st ***)(psVar8->krb5_client_princ + 0x38) = ppsVar18;
        *(tls_session_secret_cb_fn *)((int)psVar17->krb5_client_princ + 0x3c) =
             (tls_session_secret_cb_fn)0x0;
        *(void **)((int)psVar17->krb5_client_princ + 0x38) = (void *)0x0;
      }
      else {
        *(ssl_session_st **)(psVar8->krb5_client_princ + 0x38) = psVar9;
        *(ssl_session_st **)((int)*(void **)((int)psVar17->krb5_client_princ + 0x38) + 0xcc) =
             psVar8;
        *(tls_session_secret_cb_fn *)((int)psVar17->krb5_client_princ + 0x3c) =
             (tls_session_secret_cb_fn)0x0;
        *(void **)((int)psVar17->krb5_client_princ + 0x38) = (void *)0x0;
      }
    }
  }
  psVar8 = ctx->session_cache_head;
  if (psVar8 == (ssl_session_st *)0x0) {
    ctx->session_cache_head = psVar17;
    ctx->session_cache_tail = psVar17;
    *(ssl_session_st ***)((int)psVar17->krb5_client_princ + 0x38) = ppsVar18;
    *(ssl_session_st ***)((int)psVar17->krb5_client_princ + 0x3c) = &ctx->session_cache_tail;
  }
  else {
    *(ssl_session_st **)((int)psVar17->krb5_client_princ + 0x3c) = psVar8;
    *(ssl_session_st **)(psVar8->krb5_client_princ + 0x38) = psVar17;
    *(ssl_session_st ***)((int)psVar17->krb5_client_princ + 0x38) = ppsVar18;
    ctx->session_cache_head = psVar17;
  }
  lVar10 = SSL_CTX_ctrl(ctx,0x2b,0,(void *)0x0);
  if (0 < lVar10) {
    while( true ) {
      lVar10 = SSL_CTX_ctrl(ctx,0x14,0,(void *)0x0);
      lVar11 = SSL_CTX_ctrl(ctx,0x2b,0,(void *)0x0);
      if ((((lVar10 <= lVar11) ||
           (psVar17 = ctx->session_cache_tail, psVar17 == (ssl_session_st *)0x0)) ||
          (psVar17->session_id_length == 0)) ||
         (psVar8 = (ssl_session_st *)(*(code *)PTR_lh_retrieve_006a73b0)(ctx->sessions,psVar17),
         psVar17 != psVar8)) break;
      pSVar3 = (SSL_SESSION *)(*(code *)PTR_lh_delete_006a8390)(ctx->sessions,psVar17);
      psVar8 = *(ssl_session_st **)(psVar17->krb5_client_princ + 0x3c);
      if ((psVar8 != (ssl_session_st *)0x0) &&
         (psVar9 = *(ssl_session_st **)(psVar17->krb5_client_princ + 0x38),
         psVar9 != (ssl_session_st *)0x0)) {
        if (psVar8 == (ssl_session_st *)&ctx->session_cache_tail) {
          if ((ssl_session_st *)ppsVar18 == psVar9) {
            ctx->session_cache_head = (ssl_session_st *)0x0;
            ctx->session_cache_tail = (ssl_session_st *)0x0;
          }
          else {
            ctx->session_cache_tail = psVar9;
            *(ssl_session_st ***)(psVar9->krb5_client_princ + 0x3c) = &ctx->session_cache_tail;
          }
        }
        else if ((ssl_session_st *)ppsVar18 == psVar9) {
          ctx->session_cache_head = psVar8;
          *(ssl_session_st ***)(psVar8->krb5_client_princ + 0x38) = ppsVar18;
        }
        else {
          *(ssl_session_st **)(psVar8->krb5_client_princ + 0x38) = psVar9;
          *(ssl_session_st **)(*(int *)(psVar17->krb5_client_princ + 0x38) + 0xcc) = psVar8;
        }
        *(undefined4 *)(psVar17->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(psVar17->krb5_client_princ + 0x38) = 0;
      }
      p_Var21 = ctx->remove_session_cb;
      *(undefined4 *)(pSVar3->krb5_client_princ + 4) = 1;
      if (p_Var21 != (_func_3088 *)0x0) {
        (*p_Var21)(ctx,pSVar3);
      }
      iVar6 = CRYPTO_add_lock((int *)(pSVar3->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
      if (iVar6 < 1) {
        SSL_SESSION_free_part_2(pSVar3);
      }
      (ctx->stats).sess_cache_full = (ctx->stats).sess_cache_full + 1;
    }
  }
  iVar6 = 1;
LAB_004aee9c:
  CRYPTO_lock(10,0xc,"ssl_sess.c",0x340);
  return iVar6;
}

