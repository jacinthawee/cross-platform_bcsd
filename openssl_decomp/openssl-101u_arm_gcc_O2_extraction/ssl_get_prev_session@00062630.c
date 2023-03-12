
void ssl_get_prev_session(uint *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  time_t tVar3;
  SSL_CTX *pSVar4;
  SSL_SESSION *pSVar5;
  uint uVar6;
  size_t __n;
  uint uVar7;
  int iVar8;
  SSL_SESSION **ppSVar9;
  SSL_SESSION *local_120;
  int local_11c;
  undefined4 local_118;
  int local_d4;
  undefined auStack_d0 [172];
  int local_24;
  
  local_120 = (SSL_SESSION *)0x0;
  local_24 = __stack_chk_guard;
  if (param_4 - param_2 < param_3) {
    uVar7 = 0xffffffff;
    goto LAB_00062680;
  }
  ppSVar9 = &local_120;
  iVar8 = param_3;
  if (param_3 != 0) {
    iVar8 = 1;
  }
  uVar1 = tls1_process_ticket();
  switch(uVar1) {
  case 0:
  case 1:
    if (iVar8 == 0) goto switchD_00062672_caseD_2;
    if (local_120 == (SSL_SESSION *)0x0) {
      uVar6 = param_1[0x5c];
      uVar7 = *(uint *)(uVar6 + 0x20) & 0x100;
      if (uVar7 == 0) {
        local_118 = *param_1;
        local_d4 = param_3;
        if (param_3 == 0) goto LAB_00062680;
        __memcpy_chk(auStack_d0,param_2,param_3,0xac,ppSVar9);
        CRYPTO_lock(5,0xc,"ssl_sess.c",0x282);
        local_120 = (SSL_SESSION *)lh_retrieve(*(_LHASH **)(param_1[0x5c] + 0x10),&local_118);
        if (local_120 != (SSL_SESSION *)0x0) {
          CRYPTO_add_lock((int *)(local_120->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x286);
        }
        CRYPTO_lock(6,0xc,"ssl_sess.c",0x288);
        if (local_120 != (SSL_SESSION *)0x0) goto LAB_000626ba;
        uVar6 = param_1[0x5c];
        *(int *)(uVar6 + 0x4c) = *(int *)(uVar6 + 0x4c) + 1;
      }
      if (*(code **)(uVar6 + 0x30) != (code *)0x0) {
        local_11c = 1;
        local_120 = (SSL_SESSION *)(**(code **)(uVar6 + 0x30))(param_1,param_2,param_3,&local_11c);
        if (local_120 != (SSL_SESSION *)0x0) {
          pSVar4 = (SSL_CTX *)param_1[0x5c];
          (pSVar4->stats).sess_cb_hit = (pSVar4->stats).sess_cb_hit + 1;
          if (local_11c != 0) {
            CRYPTO_add_lock((int *)(local_120->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x29c);
            pSVar4 = (SSL_CTX *)param_1[0x5c];
          }
          if (-1 < pSVar4->session_cache_mode << 0x16) {
            SSL_CTX_add_session(pSVar4,local_120);
          }
        }
        iVar8 = 1;
        goto LAB_00062698;
      }
      goto LAB_00062810;
    }
LAB_000626ba:
    iVar8 = 1;
    break;
  case 2:
  case 3:
switchD_00062672_caseD_2:
    iVar8 = 0;
LAB_00062698:
    if (local_120 == (SSL_SESSION *)0x0) {
LAB_00062810:
      uVar7 = 0;
      goto LAB_00062680;
    }
    break;
  default:
                    /* WARNING: Subroutine does not return */
    abort();
  case 0xffffffff:
    uVar7 = 0xffffffff;
    goto joined_r0x0006280a;
  }
  pSVar5 = local_120;
  __n = local_120->sid_ctx_length;
  if ((__n == param_1[0x27]) && (uVar7 = memcmp(local_120->sid_ctx,param_1 + 0x28,__n), uVar7 == 0))
  {
    if (((int)(param_1[0x32] << 0x1f) < 0) && (__n == 0)) {
      uVar7 = 0xffffffff;
      ERR_put_error(0x14,0xd9,0x115,"ssl_sess.c",0x2c7);
    }
    else {
      if (*(int *)(pSVar5->krb5_client_princ + 0x24) == 0) {
        iVar2 = *(int *)(pSVar5->krb5_client_princ + 0x28);
        local_118 = iVar2 << 0x18;
        local_118 = local_118 |
                    CONCAT12((char)((uint)iVar2 >> 8),
                             CONCAT11((char)((uint)iVar2 >> 0x10),(char)((uint)iVar2 >> 0x18)));
        if (pSVar5->ssl_version < 0x300) {
          iVar2 = (int)&local_118 + 1;
        }
        else {
          iVar2 = (int)&local_118 + 2;
        }
        uVar1 = (**(code **)(param_1[2] + 0x48))(iVar2);
        *(undefined4 *)(pSVar5->krb5_client_princ + 0x24) = uVar1;
        pSVar5 = local_120;
        if (*(int *)(local_120->krb5_client_princ + 0x24) == 0) goto LAB_000626cc;
      }
      iVar2 = *(int *)(pSVar5->krb5_client_princ + 0x18);
      tVar3 = time((time_t *)0x0);
      if (tVar3 - *(int *)(local_120->krb5_client_princ + 0x1c) <= iVar2) {
        pSVar5 = (SSL_SESSION *)param_1[0x30];
        *(int *)(param_1[0x5c] + 0x58) = *(int *)(param_1[0x5c] + 0x58) + 1;
        if (pSVar5 != (SSL_SESSION *)0x0) {
          SSL_SESSION_free(pSVar5);
        }
        uVar6 = *(uint *)(local_120->krb5_client_princ + 0x10);
        uVar7 = 1;
        param_1[0x30] = (uint)local_120;
        param_1[0x3b] = uVar6;
        goto LAB_00062680;
      }
      pSVar4 = (SSL_CTX *)param_1[0x5c];
      (pSVar4->stats).sess_timeout = (pSVar4->stats).sess_timeout + 1;
      pSVar5 = local_120;
      if (iVar8 == 0) goto LAB_000626cc;
      SSL_CTX_remove_session(pSVar4,local_120);
      iVar8 = 1;
    }
joined_r0x0006280a:
    pSVar5 = local_120;
    if (local_120 == (SSL_SESSION *)0x0) goto LAB_00062680;
  }
  else {
    uVar7 = 0;
  }
LAB_000626cc:
  iVar2 = CRYPTO_add_lock((int *)(pSVar5->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
  if (iVar2 < 1) {
    CRYPTO_free_ex_data(3,pSVar5,(CRYPTO_EX_DATA *)(pSVar5->krb5_client_princ + 0x30));
    OPENSSL_cleanse(pSVar5->key_arg,8);
    OPENSSL_cleanse(pSVar5->master_key,0x30);
    OPENSSL_cleanse(pSVar5->session_id,0x20);
    if (*(int *)(pSVar5->krb5_client_princ + 8) != 0) {
      ssl_sess_cert_free();
    }
    if (*(X509 **)(pSVar5->krb5_client_princ + 0xc) != (X509 *)0x0) {
      X509_free(*(X509 **)(pSVar5->krb5_client_princ + 0xc));
    }
    if (*(_STACK **)(pSVar5->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
      sk_free(*(_STACK **)(pSVar5->krb5_client_princ + 0x2c));
    }
    if (*(void **)(pSVar5->krb5_client_princ + 0x40) != (void *)0x0) {
      CRYPTO_free(*(void **)(pSVar5->krb5_client_princ + 0x40));
    }
    if (*(void **)(pSVar5->krb5_client_princ + 0x54) != (void *)0x0) {
      CRYPTO_free(*(void **)(pSVar5->krb5_client_princ + 0x54));
    }
    *(undefined4 *)(pSVar5->krb5_client_princ + 0x44) = 0;
    if (*(void **)(pSVar5->krb5_client_princ + 0x48) != (void *)0x0) {
      CRYPTO_free(*(void **)(pSVar5->krb5_client_princ + 0x48));
    }
    *(undefined4 *)(pSVar5->krb5_client_princ + 0x4c) = 0;
    if (*(void **)(pSVar5->krb5_client_princ + 0x50) != (void *)0x0) {
      CRYPTO_free(*(void **)(pSVar5->krb5_client_princ + 0x50));
    }
    if ((void *)pSVar5->krb5_client_princ_len != (void *)0x0) {
      CRYPTO_free((void *)pSVar5->krb5_client_princ_len);
    }
    if (*(void **)pSVar5->krb5_client_princ != (void *)0x0) {
      CRYPTO_free(*(void **)pSVar5->krb5_client_princ);
    }
    if (*(void **)(pSVar5->krb5_client_princ + 0x60) != (void *)0x0) {
      CRYPTO_free(*(void **)(pSVar5->krb5_client_princ + 0x60));
    }
    OPENSSL_cleanse(pSVar5,0xf4);
    CRYPTO_free(pSVar5);
  }
  if (iVar8 == 0) {
    param_1[0x50] = 1;
  }
LAB_00062680:
  if (local_24 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}

