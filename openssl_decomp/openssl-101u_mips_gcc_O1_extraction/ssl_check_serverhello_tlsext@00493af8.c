
undefined4 ssl_check_serverhello_tlsext(int param_1,int *param_2,int param_3,char *param_4)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  byte *pbVar8;
  SSL *ssl;
  byte *pbVar9;
  short *psVar10;
  code *pcVar11;
  undefined *puVar12;
  undefined4 *local_28;
  int local_18;
  SSL *local_14;
  
  puVar12 = PTR___stack_chk_guard_006a9ae8;
  local_18 = 0x70;
  local_14 = *(SSL **)PTR___stack_chk_guard_006a9ae8;
  if ((*(int *)(param_1 + 0x148) == 0) || (*(int *)(param_1 + 0x144) == 0)) {
LAB_00493b48:
    iVar3 = *(int *)(param_1 + 0xe4);
  }
  else {
    pbVar8 = *(byte **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pbVar8 == (byte *)0x0) || (iVar3 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar3 == 0))
       || ((iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), (*(uint *)(iVar5 + 0xc) & 0xe0) == 0
           && (param_2 = (int *)(*(uint *)(iVar5 + 0x10) & 0x40), param_2 == (int *)0x0))))
    goto LAB_00493b48;
    param_2 = (int *)(uint)*pbVar8;
    pbVar9 = pbVar8 + iVar3;
    if (param_2 == (int *)0x0) goto LAB_00493b48;
    do {
      pbVar8 = pbVar8 + 1;
      if (pbVar8 == pbVar9) {
        param_3 = 0x9d;
        param_4 = "t1_lib.c";
        local_28 = (undefined4 *)0x802;
        param_2 = (int *)0x118;
        (*(code *)PTR_ERR_put_error_006a7f34)(0x14);
        uVar4 = 0xffffffff;
        goto LAB_00493ca4;
      }
    } while (*pbVar8 != 0);
    iVar3 = *(int *)(param_1 + 0xe4);
  }
  if (((iVar3 == 0) || (pcVar11 = *(code **)(iVar3 + 0x100), pcVar11 == (code *)0x0)) &&
     ((iVar3 = *(int *)(param_1 + 0x170), iVar3 == 0 ||
      (pcVar11 = *(code **)(iVar3 + 0x100), pcVar11 == (code *)0x0)))) {
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x138));
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    if (*(int *)(param_1 + 0x128) != -1) {
      uVar4 = 1;
      if ((*(int *)(param_1 + 300) != 0) || (uVar4 = 1, *(int *)(param_1 + 0x6c) != 0))
      goto LAB_00493ca4;
      iVar5 = *(int *)(param_1 + 0xe4);
      iVar3 = 0;
      if (iVar5 != 0) {
        pcVar11 = *(code **)(iVar5 + 0x13c);
        goto LAB_00493c5c;
      }
    }
LAB_00493bc8:
    uVar4 = 1;
  }
  else {
    param_2 = &local_18;
    iVar3 = (*pcVar11)(param_1,param_2,*(undefined4 *)(iVar3 + 0x104));
    (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(param_1 + 0x138));
    *(undefined4 *)(param_1 + 0x138) = 0;
    *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
    if ((((*(int *)(param_1 + 0x128) == -1) || (*(int *)(param_1 + 300) != 0)) ||
        (*(int *)(param_1 + 0x6c) != 0)) || (iVar5 = *(int *)(param_1 + 0xe4), iVar5 == 0)) {
LAB_00493bac:
      if (iVar3 != 2) {
        uVar4 = 1;
        param_3 = local_18;
        if (iVar3 == 3) {
          *(undefined4 *)(param_1 + 0x124) = 0;
        }
        else {
          if (iVar3 != 1) goto LAB_00493bc8;
          param_2 = (int *)0x1;
          ssl3_send_alert(param_1);
          uVar4 = 1;
        }
        goto LAB_00493ca4;
      }
    }
    else {
      pcVar11 = *(code **)(iVar5 + 0x13c);
LAB_00493c5c:
      if (pcVar11 == (code *)0x0) goto LAB_00493bac;
      param_2 = *(int **)(iVar5 + 0x140);
      iVar5 = (*pcVar11)(param_1);
      if (iVar5 == 0) {
        local_18 = 0x71;
      }
      else {
        if (-1 < iVar5) goto LAB_00493bac;
        local_18 = 0x50;
      }
    }
    param_2 = (int *)&SUB_00000002;
    param_3 = local_18;
    ssl3_send_alert(param_1);
    uVar4 = 0xffffffff;
  }
LAB_00493ca4:
  if (local_14 == *(SSL **)puVar12) {
    return uVar4;
  }
  ssl = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar12 = &_gp;
  *local_28 = 0;
  ssl->tlsext_ocsp_resplen = 0;
  uVar6 = SSL_ctrl(ssl,0x20,0,(void *)0x0);
  if ((((uVar6 & 0x4000) == 0) && (0x300 < ssl->version)) &&
     (pbVar8 = (byte *)((int)param_2 + param_3), (byte *)param_4 != (byte *)0x0)) {
    if (pbVar8 < param_4) {
      pbVar9 = pbVar8 + 1;
      if (ssl->version == 0xfeff) {
        bVar1 = *pbVar8;
        pbVar8 = pbVar9 + bVar1;
        if ((int)param_4 - (int)pbVar9 <= (int)(uint)bVar1) goto LAB_00493fac;
        bVar1 = *pbVar8;
      }
      else {
        bVar1 = *pbVar8;
      }
      pbVar9 = pbVar8 + 2;
      uVar6 = (uint)CONCAT11(bVar1,pbVar8[1]);
      if ((int)uVar6 < (int)param_4 - (int)pbVar9) {
        if ((int)(uint)pbVar9[uVar6] <= (int)param_4 - (int)(pbVar9 + uVar6 + 1)) {
          pbVar8 = pbVar9 + uVar6 + 1 + pbVar9[uVar6];
          if ((2 < (int)param_4 - (int)pbVar8) && (3 < (int)param_4 - (int)(pbVar8 + 2))) {
            psVar10 = (short *)(pbVar8 + 6);
            sVar2 = *(short *)(pbVar8 + 2);
            uVar6 = (uint)*(ushort *)(pbVar8 + 4);
            if ((int)uVar6 <= (int)param_4 - (int)psVar10) {
              do {
                if (sVar2 == 0x23) {
                  if (uVar6 == 0) {
                    ssl->tlsext_ocsp_resplen = 1;
                    return 1;
                  }
                  uVar4 = 2;
                  if (ssl->tls_session_ticket_ext_cb_arg != (void *)0x0) {
                    return 2;
                  }
                  iVar3 = tls_decrypt_ticket(ssl,psVar10,uVar6,param_2,param_3,local_28,puVar12);
                  if (iVar3 == 3) {
                    return 3;
                  }
                  if (iVar3 == 4) {
                    uVar4 = 3;
                  }
                  else if (iVar3 != 2) goto LAB_00493fac;
                  ssl->tlsext_ocsp_resplen = 1;
                  return uVar4;
                }
                psVar7 = (short *)((int)psVar10 + uVar6);
                psVar10 = psVar7 + 2;
                if ((int)param_4 - (int)psVar7 < 4) break;
                sVar2 = *psVar7;
                uVar6 = (uint)(ushort)psVar7[1];
              } while ((int)uVar6 <= (int)param_4 - (int)psVar10);
            }
          }
          goto LAB_00493f20;
        }
      }
    }
LAB_00493fac:
    uVar4 = 0xffffffff;
  }
  else {
LAB_00493f20:
    uVar4 = 0;
  }
  return uVar4;
}

