
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
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_30 = (*(code *)PTR_time_006a9adc)(0);
  (*(code *)PTR_RAND_add_006a8004)(&local_30,4,0,0);
  (*(code *)PTR_ERR_clear_error_006a6ee0)();
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006a99e8)();
  p_Var8 = param_1->info_callback;
  *puVar2 = 0;
  if (p_Var8 == (_func_3152 *)0x0) {
    p_Var8 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar3 = SSL_state(param_1);
  if ((uVar3 & 0x3000) != 0) {
    uVar3 = SSL_state(param_1);
    if ((uVar3 & 0x4000) == 0) goto LAB_0048fc4c;
  }
  SSL_clear(param_1);
LAB_0048fc4c:
  iVar6 = param_1->state;
  do {
    if (0x2211 < iVar6) {
      if ((iVar6 == 0x4000) || (iVar6 == 0x6000)) goto LAB_0048fd3c;
LAB_0048fc88:
      pSVar7 = (SSL_METHOD *)0xffffffff;
      (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x73,0xff,"s23_srvr.c",0xd8);
      goto LAB_0048fcb0;
    }
    if (0x220f < iVar6) goto LAB_0048fdc8;
    if ((iVar6 != 0x2000) && (iVar6 != 0x2003)) goto LAB_0048fc88;
LAB_0048fd3c:
    param_1->server = 1;
    if (p_Var8 == (_func_3152 *)0x0) {
      param_1->type = 0x2000;
      if (param_1->init_buf != (BUF_MEM *)0x0) {
        ssl3_init_finished_mac(param_1);
        param_1->state = 0x2210;
        *(int *)(param_1->psk_server_callback + 0x40) =
             *(int *)(param_1->psk_server_callback + 0x40) + 1;
        param_1->init_num = 0;
        goto LAB_0048fdc8;
      }
LAB_0048fdfc:
      pBVar4 = (BUF_MEM *)(*(code *)PTR_BUF_MEM_new_006a749c)();
      if (pBVar4 == (BUF_MEM *)0x0) {
        pSVar7 = (SSL_METHOD *)0xffffffff;
        goto LAB_0048fcb0;
      }
      iVar5 = (*(code *)PTR_BUF_MEM_grow_006a74a0)(pBVar4,0x4000);
      if (iVar5 == 0) {
        pSVar7 = (SSL_METHOD *)0xffffffff;
        (*(code *)PTR_BUF_MEM_free_006a7494)(pBVar4);
        goto LAB_0048fcb0;
      }
      param_1->init_buf = pBVar4;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x2210;
      *(int *)(param_1->psk_server_callback + 0x40) =
           *(int *)(param_1->psk_server_callback + 0x40) + 1;
      param_1->init_num = 0;
      if (p_Var8 == (_func_3152 *)0x0) {
        param_1->shutdown = 0;
        goto LAB_0048fdcc;
      }
    }
    else {
      (*p_Var8)(param_1,0x10,1);
      param_1->type = 0x2000;
      if (param_1->init_buf == (BUF_MEM *)0x0) goto LAB_0048fdfc;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x2210;
      *(int *)(param_1->psk_server_callback + 0x40) =
           *(int *)(param_1->psk_server_callback + 0x40) + 1;
      param_1->init_num = 0;
    }
    if (iVar6 != 0x2210) {
      param_1->state = iVar6;
      (*p_Var8)(param_1,0x2001,1);
      param_1->state = 0x2210;
LAB_0048fdc8:
      param_1->shutdown = 0;
LAB_0048fdcc:
      pSVar7 = (SSL_METHOD *)ssl23_get_client_hello(param_1);
      if ((int)pSVar7 < 0) {
LAB_0048fcb0:
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
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
      if (iVar6 == 0x300) {
        pSVar7 = SSLv3_client_method();
        return pSVar7;
      }
      if (iVar6 == 0x301) {
        pSVar7 = TLSv1_client_method();
        return pSVar7;
      }
      if (iVar6 != 0x302) {
        if (iVar6 == 0x303) {
          pSVar7 = TLSv1_2_client_method();
          return pSVar7;
        }
        return (SSL_METHOD *)0x0;
      }
      pSVar7 = TLSv1_1_client_method();
      return pSVar7;
    }
    iVar6 = param_1->state;
  } while( true );
}

