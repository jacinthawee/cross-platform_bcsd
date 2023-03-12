
SSL_METHOD * ssl23_accept(SSL *param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  BUF_MEM *pBVar4;
  int iVar5;
  int iVar6;
  SSL_METHOD *pSVar7;
  _func_3152 *p_Var8;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_30 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_30,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  p_Var8 = param_1->info_callback;
  *puVar2 = 0;
  if (p_Var8 == (_func_3152 *)0x0) {
    p_Var8 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar3 = SSL_state(param_1);
  if ((uVar3 & 0x3000) != 0) {
    uVar3 = SSL_state(param_1);
    if ((uVar3 & 0x4000) == 0) goto LAB_00493b7c;
  }
  SSL_clear(param_1);
LAB_00493b7c:
  iVar6 = param_1->state;
  do {
    if (0x2211 < iVar6) {
      if ((iVar6 == 0x4000) || (iVar6 == 0x6000)) goto LAB_00493c6c;
LAB_00493bb8:
      pSVar7 = (SSL_METHOD *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x73,0xff,"s23_srvr.c",0xd8);
      goto LAB_00493be0;
    }
    if (0x220f < iVar6) goto LAB_00493cf8;
    if ((iVar6 != 0x2000) && (iVar6 != 0x2003)) goto LAB_00493bb8;
LAB_00493c6c:
    param_1->server = 1;
    if (p_Var8 == (_func_3152 *)0x0) {
      param_1->type = 0x2000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
LAB_00493d2c:
        pBVar4 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a859c)();
        if (pBVar4 != (BUF_MEM *)0x0) {
          iVar5 = (*(code *)PTR_BUF_MEM_grow_006a85a0)(pBVar4,0x4000);
          if (iVar5 != 0) {
            param_1->init_buf = pBVar4;
            ssl3_init_finished_mac(param_1);
            param_1->state = 0x2210;
            *(int *)(param_1->psk_server_callback + 0x40) =
                 *(int *)(param_1->psk_server_callback + 0x40) + 1;
            param_1->init_num = 0;
            if (p_Var8 != (_func_3152 *)0x0) goto LAB_00493cc4;
            param_1->shutdown = 0;
            goto LAB_00493cfc;
          }
        }
        pSVar7 = (SSL_METHOD *)0xffffffff;
        goto LAB_00493be0;
      }
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x2210;
      *(int *)(param_1->psk_server_callback + 0x40) =
           *(int *)(param_1->psk_server_callback + 0x40) + 1;
      param_1->init_num = 0;
      goto LAB_00493cf8;
    }
    (*p_Var8)(param_1,0x10,1);
    param_1->type = 0x2000;
    if (param_1->init_buf == (BUF_MEM *)0x0) goto LAB_00493d2c;
    ssl3_init_finished_mac(param_1);
    param_1->state = 0x2210;
    *(int *)(param_1->psk_server_callback + 0x40) =
         *(int *)(param_1->psk_server_callback + 0x40) + 1;
    param_1->init_num = 0;
LAB_00493cc4:
    if (iVar6 != 0x2210) {
      param_1->state = iVar6;
      (*p_Var8)(param_1,0x2001,1);
      param_1->state = 0x2210;
LAB_00493cf8:
      param_1->shutdown = 0;
LAB_00493cfc:
      pSVar7 = (SSL_METHOD *)ssl23_get_client_hello(param_1);
      if ((int)pSVar7 < 0) {
LAB_00493be0:
        param_1->in_handshake = param_1->in_handshake + -1;
        if (p_Var8 != (_func_3152 *)0x0) {
          (*p_Var8)(param_1,0x2002,(int)pSVar7);
        }
      }
      else {
        param_1->in_handshake = param_1->in_handshake + -1;
      }
      if (local_2c == *(int *)puVar1) {
        return pSVar7;
      }
      iVar6 = local_2c;
      (*(code *)PTR___stack_chk_fail_006aabb8)();
      if (iVar6 == 2) {
        pSVar7 = SSLv2_client_method();
        return pSVar7;
      }
      if (iVar6 == 0x300) {
        pSVar7 = SSLv3_client_method();
        return pSVar7;
      }
      if (iVar6 != 0x301) {
        if (iVar6 == 0x302) {
          pSVar7 = TLSv1_1_client_method();
          return pSVar7;
        }
        if (iVar6 == 0x303) {
          pSVar7 = TLSv1_2_client_method();
          return pSVar7;
        }
        return (SSL_METHOD *)0x0;
      }
      pSVar7 = TLSv1_client_method();
      return pSVar7;
    }
    iVar6 = param_1->state;
  } while( true );
}

