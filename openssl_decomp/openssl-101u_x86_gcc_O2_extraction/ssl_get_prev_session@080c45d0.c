
int ssl_get_prev_session(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  size_t __n;
  SSL_SESSION *pSVar2;
  code *pcVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  time_t tVar7;
  int iVar8;
  SSL_SESSION *pSVar9;
  SSL_SESSION *pSVar10;
  SSL_CTX *s;
  SSL_SESSION *ses;
  undefined *puVar11;
  int iVar12;
  int in_GS_OFFSET;
  SSL_SESSION *local_124;
  int local_120;
  undefined4 local_11c [17];
  int local_d8;
  undefined local_d4 [175];
  undefined local_25;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_124 = (SSL_SESSION *)0x0;
  if (param_4 - param_2 < param_3) {
    iVar12 = -1;
    goto LAB_080c464d;
  }
  if (param_3 == 0) {
    uVar5 = tls1_process_ticket(param_1,param_2,0,param_4,&local_124);
    switch(uVar5) {
    case 0:
    case 1:
    case 2:
    case 3:
switchD_080c4690_caseD_2:
      bVar4 = false;
LAB_080c46a6:
      iVar12 = 0;
      if (local_124 == (SSL_SESSION *)0x0) goto LAB_080c464d;
LAB_080c46ac:
      pSVar10 = local_124;
      __n = local_124->sid_ctx_length;
      iVar12 = 0;
      if (__n == param_1[0x27]) {
        iVar12 = memcmp(local_124->sid_ctx,param_1 + 0x28,__n);
        if (iVar12 == 0) {
          if ((__n == 0) && ((*(byte *)(param_1 + 0x32) & 1) != 0)) {
            iVar12 = -1;
            ERR_put_error(0x14,0xd9,0x115,"ssl_sess.c",0x2c7);
          }
          else {
            if (*(int *)(pSVar10->krb5_client_princ + 0x24) == 0) {
              uVar5 = *(undefined4 *)(pSVar10->krb5_client_princ + 0x28);
              local_22 = (undefined)uVar5;
              local_25 = (undefined)((uint)uVar5 >> 0x18);
              local_24 = (undefined)((uint)uVar5 >> 0x10);
              local_23 = (undefined)((uint)uVar5 >> 8);
              if (pSVar10->ssl_version < 0x300) {
                iVar6 = param_1[2];
                puVar11 = &local_24;
              }
              else {
                iVar6 = param_1[2];
                puVar11 = &local_23;
              }
              uVar5 = (**(code **)(iVar6 + 0x48))(puVar11);
              *(undefined4 *)(pSVar10->krb5_client_princ + 0x24) = uVar5;
              pSVar10 = local_124;
              if (*(int *)(local_124->krb5_client_princ + 0x24) == 0) break;
            }
            iVar6 = *(int *)(pSVar10->krb5_client_princ + 0x18);
            tVar7 = time((time_t *)0x0);
            pSVar10 = local_124;
            iVar8 = tVar7 - *(int *)(local_124->krb5_client_princ + 0x1c);
            if (iVar8 <= iVar6) {
              iVar12 = param_1[0x30];
              *(int *)(param_1[0x5c] + 0x58) = *(int *)(param_1[0x5c] + 0x58) + 1;
              if ((iVar12 != 0) &&
                 (iVar12 = CRYPTO_add_lock((int *)(iVar12 + 0xa4),-1,0xe,"ssl_sess.c",0x36c),
                 iVar12 < 1)) {
                SSL_SESSION_free_part_2();
              }
              uVar5 = *(undefined4 *)(local_124->krb5_client_princ + 0x10);
              param_1[0x30] = local_124;
              iVar12 = 1;
              param_1[0x3b] = uVar5;
              goto LAB_080c464d;
            }
            iVar6 = param_1[0x5c];
            *(int *)(iVar6 + 0x50) = *(int *)(iVar6 + 0x50) + 1;
            if ((!bVar4) || (bVar4 = true, local_124->session_id_length == 0)) break;
            CRYPTO_lock(iVar8,9,&DAT_0000000c,(int)"ssl_sess.c");
            pSVar9 = (SSL_SESSION *)lh_retrieve(*(_LHASH **)(iVar6 + 0x10),pSVar10);
            if (pSVar10 == pSVar9) {
              ses = (SSL_SESSION *)lh_delete(*(_LHASH **)(iVar6 + 0x10),pSVar10);
              iVar8 = *(int *)(pSVar10->krb5_client_princ + 0x3c);
              pSVar9 = ses;
              if ((iVar8 != 0) &&
                 (pSVar2 = *(SSL_SESSION **)(pSVar10->krb5_client_princ + 0x38),
                 pSVar2 != (SSL_SESSION *)0x0)) {
                pSVar9 = (SSL_SESSION *)(iVar6 + 0x18);
                if (iVar8 == iVar6 + 0x1c) {
                  if (pSVar2 == pSVar9) {
                    *(undefined4 *)(iVar6 + 0x18) = 0;
                    *(undefined4 *)(iVar6 + 0x1c) = 0;
                  }
                  else {
                    *(SSL_SESSION **)(iVar6 + 0x1c) = pSVar2;
                    *(int *)(pSVar2->krb5_client_princ + 0x3c) = iVar8;
                  }
                }
                else if (pSVar2 == pSVar9) {
                  *(int *)(iVar6 + 0x18) = iVar8;
                  *(SSL_SESSION **)(iVar8 + 200) = pSVar2;
                }
                else {
                  *(SSL_SESSION **)(iVar8 + 200) = pSVar2;
                  *(int *)(*(int *)(pSVar10->krb5_client_princ + 0x38) + 0xcc) = iVar8;
                }
                *(undefined4 *)(pSVar10->krb5_client_princ + 0x3c) = 0;
                *(undefined4 *)(pSVar10->krb5_client_princ + 0x38) = 0;
              }
              CRYPTO_lock((int)pSVar9,10,&DAT_0000000c,(int)"ssl_sess.c");
              pcVar3 = *(code **)(iVar6 + 0x2c);
              *(undefined4 *)(ses->krb5_client_princ + 4) = 1;
              if (pcVar3 != (code *)0x0) {
                (*pcVar3)(iVar6,ses,ses,ses);
              }
              bVar4 = true;
              SSL_SESSION_free(ses);
            }
            else {
              CRYPTO_lock((int)pSVar9,10,&DAT_0000000c,(int)"ssl_sess.c");
            }
          }
          goto joined_r0x080c4a5a;
        }
        iVar12 = 0;
      }
      break;
    default:
switchD_080c4690_caseD_5:
                    /* WARNING: Subroutine does not return */
      abort();
    case 0xffffffff:
      iVar12 = -1;
      bVar4 = false;
      goto joined_r0x080c4a5a;
    }
  }
  else {
    uVar5 = tls1_process_ticket(param_1,param_2,param_3,param_4,&local_124);
    switch(uVar5) {
    case 0:
    case 1:
      if (local_124 == (SSL_SESSION *)0x0) {
        iVar6 = param_1[0x5c];
        if ((*(byte *)(iVar6 + 0x21) & 1) == 0) {
          local_11c[0] = *param_1;
          local_d8 = param_3;
          iVar12 = __memcpy_chk(local_d4,param_2,param_3,0xac);
          CRYPTO_lock(iVar12,5,&DAT_0000000c,(int)"ssl_sess.c");
          pSVar10 = (SSL_SESSION *)lh_retrieve(*(_LHASH **)(param_1[0x5c] + 0x10),local_11c);
          local_124 = pSVar10;
          if (pSVar10 != (SSL_SESSION *)0x0) {
            pSVar10 = (SSL_SESSION *)
                      CRYPTO_add_lock((int *)(pSVar10->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",
                                      0x286);
          }
          CRYPTO_lock((int)pSVar10,6,&DAT_0000000c,(int)"ssl_sess.c");
          if (local_124 != (SSL_SESSION *)0x0) goto LAB_080c473d;
          *(int *)(param_1[0x5c] + 0x4c) = *(int *)(param_1[0x5c] + 0x4c) + 1;
          iVar6 = param_1[0x5c];
        }
        iVar12 = 0;
        if (*(code **)(iVar6 + 0x30) == (code *)0x0) goto LAB_080c464d;
        local_120 = 1;
        local_124 = (SSL_SESSION *)(**(code **)(iVar6 + 0x30))(param_1,param_2,param_3,&local_120);
        if (local_124 != (SSL_SESSION *)0x0) {
          s = (SSL_CTX *)param_1[0x5c];
          piVar1 = &(s->stats).sess_cb_hit;
          *piVar1 = *piVar1 + 1;
          if (local_120 != 0) {
            CRYPTO_add_lock((int *)(local_124->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x29c);
            s = (SSL_CTX *)param_1[0x5c];
          }
          if ((*(byte *)((int)&s->session_cache_mode + 1) & 2) == 0) {
            SSL_CTX_add_session(s,local_124);
          }
        }
        bVar4 = true;
        goto LAB_080c46a6;
      }
LAB_080c473d:
      bVar4 = true;
      goto LAB_080c46ac;
    case 2:
    case 3:
      goto switchD_080c4690_caseD_2;
    default:
      goto switchD_080c4690_caseD_5;
    case 0xffffffff:
      iVar12 = -1;
      bVar4 = true;
    }
joined_r0x080c4a5a:
    pSVar10 = local_124;
    if (local_124 == (SSL_SESSION *)0x0) goto LAB_080c464d;
  }
  iVar6 = CRYPTO_add_lock((int *)(pSVar10->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x36c);
  if (iVar6 < 1) {
    SSL_SESSION_free_part_2();
  }
  if (!bVar4) {
    param_1[0x50] = 1;
  }
LAB_080c464d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar12;
}

