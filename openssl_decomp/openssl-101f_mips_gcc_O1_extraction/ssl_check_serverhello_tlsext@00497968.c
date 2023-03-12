
undefined4 ssl_check_serverhello_tlsext(int param_1,int *param_2,int param_3,char *param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  int iVar9;
  SSL *ssl;
  undefined4 uVar10;
  code *pcVar11;
  undefined *puVar12;
  undefined4 *local_28;
  int local_18;
  SSL *local_14;
  
  puVar12 = PTR___stack_chk_guard_006aabf0;
  local_18 = 0x70;
  local_14 = *(SSL **)PTR___stack_chk_guard_006aabf0;
  if ((*(int *)(param_1 + 0x148) == 0) || (*(int *)(param_1 + 0x144) == 0)) {
LAB_004979b8:
    iVar2 = *(int *)(param_1 + 0xe4);
  }
  else {
    pbVar7 = *(byte **)(*(int *)(param_1 + 0xc0) + 0xd8);
    if (((pbVar7 == (byte *)0x0) || (iVar2 = *(int *)(*(int *)(param_1 + 0xc0) + 0xd4), iVar2 == 0))
       || ((iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x344), (*(uint *)(iVar3 + 0xc) & 0xe0) == 0
           && (param_2 = (int *)(*(uint *)(iVar3 + 0x10) & 0x40), param_2 == (int *)0x0))))
    goto LAB_004979b8;
    param_2 = (int *)(uint)*pbVar7;
    pbVar8 = pbVar7 + iVar2;
    if (param_2 == (int *)0x0) goto LAB_004979b8;
    do {
      pbVar7 = pbVar7 + 1;
      if (pbVar8 == pbVar7) {
        param_3 = 0x9d;
        param_4 = "t1_lib.c";
        local_28 = (undefined4 *)0x7ff;
        param_2 = (int *)0x118;
        (*(code *)PTR_ERR_put_error_006a9030)(0x14);
        uVar10 = 0xffffffff;
        goto LAB_00497b1c;
      }
    } while (*pbVar7 != 0);
    iVar2 = *(int *)(param_1 + 0xe4);
  }
  if ((iVar2 == 0) || (pcVar11 = *(code **)(iVar2 + 0x100), pcVar11 == (code *)0x0)) {
    iVar3 = *(int *)(param_1 + 0x170);
    if ((iVar3 != 0) && (pcVar11 = *(code **)(iVar3 + 0x100), pcVar11 != (code *)0x0)) {
      uVar10 = *(undefined4 *)(iVar3 + 0x104);
      goto LAB_004979d4;
    }
    if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 300) == 0)) && (iVar2 != 0)) {
      pcVar11 = *(code **)(iVar2 + 0x13c);
      iVar3 = 0;
      if (pcVar11 == (code *)0x0) goto LAB_00497aa0;
      iVar9 = *(int *)(param_1 + 0x138);
      goto LAB_00497a1c;
    }
LAB_00497aa0:
    uVar10 = 1;
  }
  else {
    uVar10 = *(undefined4 *)(iVar2 + 0x104);
LAB_004979d4:
    param_2 = &local_18;
    iVar3 = (*pcVar11)(param_1,param_2,uVar10);
    if (((*(int *)(param_1 + 0x128) == -1) || (*(int *)(param_1 + 300) != 0)) ||
       ((iVar2 = *(int *)(param_1 + 0xe4), iVar2 == 0 ||
        (pcVar11 = *(code **)(iVar2 + 0x13c), pcVar11 == (code *)0x0)))) {
LAB_00497a84:
      if (iVar3 != 2) {
        uVar10 = 1;
        param_3 = local_18;
        if (iVar3 == 3) {
          *(undefined4 *)(param_1 + 0x124) = 0;
        }
        else {
          if (iVar3 != 1) goto LAB_00497aa0;
          param_2 = (int *)0x1;
          ssl3_send_alert(param_1);
          uVar10 = 1;
        }
        goto LAB_00497b1c;
      }
    }
    else {
      iVar9 = *(int *)(param_1 + 0x138);
LAB_00497a1c:
      if (iVar9 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
        iVar2 = *(int *)(param_1 + 0xe4);
        *(undefined4 *)(param_1 + 0x138) = 0;
        pcVar11 = *(code **)(iVar2 + 0x13c);
      }
      param_2 = *(int **)(iVar2 + 0x140);
      *(undefined4 *)(param_1 + 0x13c) = 0xffffffff;
      iVar2 = (*pcVar11)(param_1);
      if (iVar2 == 0) {
        local_18 = 0x71;
      }
      else {
        if (-1 < iVar2) goto LAB_00497a84;
        local_18 = 0x50;
      }
    }
    param_2 = (int *)&SUB_00000002;
    param_3 = local_18;
    ssl3_send_alert(param_1);
    uVar10 = 0xffffffff;
  }
LAB_00497b1c:
  if (local_14 == *(SSL **)puVar12) {
    return uVar10;
  }
  ssl = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar12 = &_gp;
  *local_28 = 0;
  ssl->tlsext_ocsp_resplen = 0;
  uVar4 = SSL_ctrl(ssl,0x20,0,(void *)0x0);
  if ((((uVar4 & 0x4000) == 0) && (0x300 < ssl->version)) &&
     (puVar5 = (ushort *)((int)param_2 + param_3), (ushort *)param_4 != (ushort *)0x0)) {
    if (((puVar5 < param_4) &&
        (((ssl->version != 0xfeff ||
          (puVar5 = (ushort *)((int)puVar5 + *(byte *)puVar5 + 1), puVar5 < param_4)) &&
         (puVar5 = (ushort *)((int)puVar5 + *puVar5 + 2), puVar5 < param_4)))) &&
       (puVar5 = (ushort *)((int)puVar5 + *(byte *)puVar5 + 1), puVar6 = puVar5 + 1,
       puVar5 <= param_4)) {
      if (param_4 <= puVar6) goto LAB_00497d24;
      do {
        puVar5 = puVar6 + 2;
        if (param_4 < puVar5) goto LAB_00497d24;
        uVar1 = *puVar6;
        uVar4 = (uint)puVar6[1];
        puVar6 = (ushort *)((int)puVar5 + uVar4);
        if (param_4 < puVar6) goto LAB_00497d24;
      } while (uVar1 != 0x23);
      if (uVar4 == 0) {
        ssl->tlsext_ocsp_resplen = 1;
        return 1;
      }
      if (ssl->tls_session_ticket_ext_cb_arg != (void *)0x0) {
        return 2;
      }
      iVar2 = tls_decrypt_ticket(ssl,puVar5,uVar4,param_2,param_3,local_28,puVar12);
      if (iVar2 == 3) {
        return 3;
      }
      if (iVar2 == 4) {
        ssl->tlsext_ocsp_resplen = 1;
        return 3;
      }
      if (iVar2 == 2) {
        ssl->tlsext_ocsp_resplen = 1;
        return 2;
      }
    }
    uVar10 = 0xffffffff;
  }
  else {
LAB_00497d24:
    uVar10 = 0;
  }
  return uVar10;
}

