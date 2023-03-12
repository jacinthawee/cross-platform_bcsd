
int ssl23_accept(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  BUF_MEM *str;
  int iVar3;
  _func_3152 *p_Var4;
  int iVar5;
  int in_GS_OFFSET;
  time_t local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = time((time_t *)0x0);
  RAND_add(&local_24,4,0.0);
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var4 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var4 == (_func_3152 *)0x0) {
    p_Var4 = *(_func_3152 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if ((uVar2 & 0x3000) == 0) {
LAB_080ac5d0:
    SSL_clear(param_1);
    iVar5 = param_1->state;
    if (iVar5 < 0x2212) goto LAB_080ac550;
LAB_080ac5eb:
    if ((iVar5 == 0x4000) || (iVar5 == 0x6000)) goto LAB_080ac5ff;
LAB_080ac574:
    iVar5 = -1;
    ERR_put_error(0x14,0x73,0xff,"s23_srvr.c",0xd8);
  }
  else {
    uVar2 = SSL_state(param_1);
    if ((uVar2 & 0x4000) != 0) goto LAB_080ac5d0;
    iVar5 = param_1->state;
    if (0x2211 < iVar5) goto LAB_080ac5eb;
LAB_080ac550:
    if (iVar5 < 0x2210) {
      if ((iVar5 != 0x2000) && (iVar5 != 0x2003)) goto LAB_080ac574;
LAB_080ac5ff:
      param_1->server = 1;
      if (p_Var4 != (_func_3152 *)0x0) {
        (*p_Var4)(param_1,0x10,1);
      }
      param_1->type = 0x2000;
      if (param_1->init_buf != (BUF_MEM *)0x0) {
LAB_080ac629:
        ssl3_init_finished_mac(param_1);
        param_1->state = 0x2210;
        *(int *)(param_1->psk_server_callback + 0x40) =
             *(int *)(param_1->psk_server_callback + 0x40) + 1;
        param_1->init_num = 0;
        if ((p_Var4 != (_func_3152 *)0x0) && (iVar5 != 0x2210)) {
          param_1->state = iVar5;
          (*p_Var4)(param_1,0x2001,1);
          param_1->state = 0x2210;
        }
        goto LAB_080ac673;
      }
      str = BUF_MEM_new();
      if (str != (BUF_MEM *)0x0) {
        iVar3 = BUF_MEM_grow(str,0x4000);
        if (iVar3 != 0) {
          param_1->init_buf = str;
          goto LAB_080ac629;
        }
      }
      iVar5 = -1;
    }
    else {
LAB_080ac673:
      param_1->shutdown = 0;
      iVar5 = ssl23_get_client_hello(param_1);
      if (-1 < iVar5) {
        param_1->in_handshake = param_1->in_handshake + -1;
        goto LAB_080ac5ae;
      }
    }
  }
  param_1->in_handshake = param_1->in_handshake + -1;
  if (p_Var4 != (_func_3152 *)0x0) {
    (*p_Var4)(param_1,0x2002,iVar5);
  }
LAB_080ac5ae:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar5;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

