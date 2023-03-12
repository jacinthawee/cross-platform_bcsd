
int ssl_get_prev_session(undefined4 *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  SSL_SESSION *pSVar4;
  int iVar5;
  SSL_CTX *s;
  int iVar6;
  int iVar7;
  SSL_SESSION *unaff_s2;
  undefined4 *unaff_s3;
  char *unaff_s5;
  uint uVar8;
  int unaff_s6;
  code *pcVar9;
  SSL_SESSION **ppSVar10;
  SSL_SESSION *local_128;
  int local_124;
  undefined4 local_120 [17];
  int local_dc;
  undefined auStack_d8 [172];
  undefined local_2c;
  undefined local_2b;
  undefined local_2a;
  undefined local_29;
  int local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_128 = (SSL_SESSION *)0x0;
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar7 = 0;
  if (0x20 < param_3) goto LAB_004b2058;
  unaff_s3 = param_1;
  if (param_3 == 0) {
    uVar3 = tls1_process_ticket();
    switch(uVar3) {
    case 0:
    case 1:
    case 2:
    case 3:
      goto switchD_004b20c8_caseD_2;
    default:
      goto switchD_004b20c8_caseD_5;
    case 0xffffffff:
      iVar7 = -1;
      bVar1 = false;
    }
  }
  else {
    ppSVar10 = &local_128;
    uVar3 = tls1_process_ticket();
    switch(uVar3) {
    case 0:
    case 1:
      if (local_128 == (SSL_SESSION *)0x0) {
        iVar7 = param_1[0x5c];
        if ((*(uint *)(iVar7 + 0x20) & 0x100) == 0) {
          local_120[0] = *param_1;
          unaff_s5 = "x";
          local_dc = param_3;
          (*(code *)PTR___memcpy_chk_006aab54)(auStack_d8,param_2,param_3,0xac,ppSVar10);
          CRYPTO_lock(5,0xc,"ssl_sess.c",0x1fe);
          local_128 = (SSL_SESSION *)
                      (*(code *)PTR_lh_retrieve_006a84b0)
                                (*(undefined4 *)(param_1[0x5c] + 0x10),local_120);
          if (local_128 != (SSL_SESSION *)0x0) {
            CRYPTO_add_lock((int *)(local_128->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x203);
          }
          CRYPTO_lock(6,0xc,"ssl_sess.c",0x205);
          if (local_128 != (SSL_SESSION *)0x0) goto LAB_004b220c;
          iVar7 = param_1[0x5c];
          *(int *)(iVar7 + 0x4c) = *(int *)(iVar7 + 0x4c) + 1;
        }
        if (*(code **)(iVar7 + 0x30) == (code *)0x0) {
          iVar7 = 0;
          unaff_s2 = local_128;
          goto LAB_004b2058;
        }
        local_124 = 1;
        local_128 = (SSL_SESSION *)(**(code **)(iVar7 + 0x30))(param_1,param_2,param_3,&local_124);
        if (local_128 != (SSL_SESSION *)0x0) {
          s = (SSL_CTX *)param_1[0x5c];
          (s->stats).sess_cb_hit = (s->stats).sess_cb_hit + 1;
          if (local_124 != 0) {
            unaff_s5 = "x";
            CRYPTO_add_lock((int *)(local_128->krb5_client_princ + 0x14),1,0xe,"ssl_sess.c",0x21a);
            s = (SSL_CTX *)param_1[0x5c];
          }
          if ((s->session_cache_mode & 0x200U) == 0) {
            SSL_CTX_add_session(s,local_128);
            bVar1 = true;
            goto LAB_004b20d8;
          }
        }
        bVar1 = true;
        goto LAB_004b20d8;
      }
LAB_004b220c:
      bVar1 = true;
      break;
    case 2:
    case 3:
switchD_004b20c8_caseD_2:
      bVar1 = false;
LAB_004b20d8:
      iVar7 = 0;
      unaff_s2 = local_128;
      if (local_128 == (SSL_SESSION *)0x0) goto LAB_004b2058;
      break;
    default:
switchD_004b20c8_caseD_5:
      iVar7 = (*(code *)PTR_abort_006aaa74)();
      return iVar7;
    case 0xffffffff:
      iVar7 = -1;
      bVar1 = true;
      goto LAB_004b2148;
    }
    unaff_s2 = local_128;
    uVar8 = local_128->sid_ctx_length;
    if ((uVar8 != param_1[0x27]) ||
       (iVar7 = (*(code *)PTR_memcmp_006aabd8)(local_128->sid_ctx,param_1 + 0x28,uVar8), iVar7 != 0)
       ) {
      iVar7 = 0;
LAB_004b20f4:
      unaff_s5 = "x";
      goto LAB_004b20f8;
    }
    if (((param_1[0x32] & 1) != 0) && (uVar8 == 0)) {
      unaff_s5 = "x";
      iVar7 = -1;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xd9,0x115,"ssl_sess.c",0x23e);
      unaff_s2 = local_128;
      goto joined_r0x004b214c;
    }
    if (*(int *)(unaff_s2->krb5_client_princ + 0x24) == 0) {
      uVar3 = *(undefined4 *)(unaff_s2->krb5_client_princ + 0x28);
      local_29 = (undefined)uVar3;
      local_2c = (undefined)((uint)uVar3 >> 0x18);
      local_2b = (undefined)((uint)uVar3 >> 0x10);
      local_2a = (undefined)((uint)uVar3 >> 8);
      if (unaff_s2->ssl_version < 0x300) {
        uVar3 = (**(code **)(param_1[2] + 0x48))(&local_2b);
        *(undefined4 *)(unaff_s2->krb5_client_princ + 0x24) = uVar3;
      }
      else {
        uVar3 = (**(code **)(param_1[2] + 0x48))(&local_2a);
        *(undefined4 *)(unaff_s2->krb5_client_princ + 0x24) = uVar3;
      }
      unaff_s2 = local_128;
      if (*(int *)(local_128->krb5_client_princ + 0x24) == 0) {
        unaff_s5 = "x";
        goto LAB_004b20f8;
      }
    }
    iVar6 = *(int *)(unaff_s2->krb5_client_princ + 0x18);
    iVar5 = (*(code *)PTR_time_006aabe4)(0);
    unaff_s2 = local_128;
    unaff_s5 = (char *)(uint)(iVar6 < iVar5 - *(int *)(local_128->krb5_client_princ + 0x1c));
    if (unaff_s5 == (char *)0x0) {
      iVar7 = param_1[0x30];
      *(int *)(param_1[0x5c] + 0x58) = *(int *)(param_1[0x5c] + 0x58) + 1;
      if ((iVar7 != 0) &&
         (iVar5 = CRYPTO_add_lock((int *)(iVar7 + 0xa4),-1,0xe,"ssl_sess.c",0x2e4), iVar5 < 1)) {
        SSL_SESSION_free_part_2(iVar7);
      }
      uVar3 = *(undefined4 *)(local_128->krb5_client_princ + 0x10);
      iVar7 = 1;
      param_1[0x30] = local_128;
      param_1[0x3b] = uVar3;
      unaff_s2 = local_128;
      goto LAB_004b2058;
    }
    unaff_s6 = param_1[0x5c];
    *(int *)(unaff_s6 + 0x50) = *(int *)(unaff_s6 + 0x50) + 1;
    if (!bVar1) goto LAB_004b20f4;
    bVar1 = true;
    if (local_128->session_id_length == 0) {
      unaff_s5 = "x";
      goto LAB_004b20f8;
    }
    unaff_s5 = "x";
    CRYPTO_lock(9,0xc,"ssl_sess.c",0x2c6);
    pSVar4 = (SSL_SESSION *)
             (*(code *)PTR_lh_retrieve_006a84b0)(*(undefined4 *)(unaff_s6 + 0x10),unaff_s2);
    if (unaff_s2 == pSVar4) goto LAB_004b2520;
    bVar1 = true;
    CRYPTO_lock(10,0xc,"ssl_sess.c",0x2ce);
  }
LAB_004b2148:
  unaff_s5 = "x";
  unaff_s2 = local_128;
joined_r0x004b214c:
  while( true ) {
    param_1 = unaff_s3;
    local_128 = unaff_s2;
    if (unaff_s2 != (SSL_SESSION *)0x0) {
LAB_004b20f8:
      iVar5 = CRYPTO_add_lock((int *)(unaff_s2->krb5_client_princ + 0x14),-1,0xe,unaff_s5 + -0x7cdc,
                              0x2e4);
      if (iVar5 < 1) {
        SSL_SESSION_free_part_2(unaff_s2);
      }
      unaff_s3 = param_1;
      if (!bVar1) {
        param_1[0x50] = 1;
      }
    }
LAB_004b2058:
    if (local_24 == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    param_1 = unaff_s3;
LAB_004b2520:
    pSVar4 = (SSL_SESSION *)
             (*(code *)PTR_lh_delete_006a94ac)(*(undefined4 *)(unaff_s6 + 0x10),unaff_s2);
    iVar5 = *(int *)(unaff_s2->krb5_client_princ + 0x3c);
    if (iVar5 != 0) {
      iVar6 = *(int *)(unaff_s2->krb5_client_princ + 0x38);
      if (iVar6 != 0) {
        if (iVar5 == unaff_s6 + 0x1c) {
          if (iVar6 == unaff_s6 + 0x18) {
            *(undefined4 *)(unaff_s6 + 0x18) = 0;
            *(undefined4 *)(unaff_s6 + 0x1c) = 0;
          }
          else {
            *(int *)(unaff_s6 + 0x1c) = iVar6;
            *(int *)(iVar6 + 0xcc) = iVar5;
          }
        }
        else if (iVar6 == unaff_s6 + 0x18) {
          *(int *)(unaff_s6 + 0x18) = iVar5;
          *(int *)(iVar5 + 200) = iVar6;
        }
        else {
          *(int *)(iVar5 + 200) = iVar6;
          *(int *)(*(int *)(unaff_s2->krb5_client_princ + 0x38) + 0xcc) = iVar5;
        }
        *(undefined4 *)(unaff_s2->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(unaff_s2->krb5_client_princ + 0x38) = 0;
      }
    }
    CRYPTO_lock(10,0xc,unaff_s5 + -0x7cdc,0x2ce);
    pcVar9 = *(code **)(unaff_s6 + 0x2c);
    *(undefined4 *)(pSVar4->krb5_client_princ + 4) = 1;
    if (pcVar9 != (code *)0x0) {
      (*pcVar9)(unaff_s6,pSVar4);
    }
    SSL_SESSION_free(pSVar4);
    bVar1 = true;
    unaff_s3 = param_1;
    unaff_s2 = local_128;
  }
  return iVar7;
}

