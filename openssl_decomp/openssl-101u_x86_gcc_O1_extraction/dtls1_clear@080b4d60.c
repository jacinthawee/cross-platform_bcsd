
void dtls1_clear(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  pqueue p_Var2;
  ulong uVar3;
  pqueue p_Var4;
  pqueue p_Var5;
  pqueue p_Var6;
  pqueue p_Var7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 *puVar10;
  byte bVar11;
  
  bVar11 = 0;
  pdVar1 = param_1->d1;
  if (pdVar1 != (dtls1_state_st *)0x0) {
    p_Var2 = pdVar1->buffered_messages;
    uVar3 = (pdVar1->w_msg_hdr).msg_len;
    p_Var4 = (pdVar1->unprocessed_rcds).q;
    p_Var5 = (pdVar1->processed_rcds).q;
    p_Var6 = pdVar1->sent_messages;
    p_Var7 = (pdVar1->buffered_app_data).q;
    uVar8 = *(undefined4 *)&pdVar1->w_msg_hdr;
    dtls1_clear_queues();
    pdVar1 = param_1->d1;
    pdVar1->send_cookie = 0;
    pdVar1[1].send_cookie = 0;
    puVar10 = (undefined4 *)((uint)pdVar1->cookie & 0xfffffffc);
    uVar9 = (uint)((int)pdVar1 + (0x2ec - (int)puVar10)) >> 2;
    for (; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar10 = 0;
      puVar10 = puVar10 + (uint)bVar11 * -2 + 1;
    }
    if (param_1->server != 0) {
      param_1->d1->cookie_len = 0x100;
    }
    uVar9 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    pdVar1 = param_1->d1;
    if ((uVar9 & 0x1000) != 0) {
      (pdVar1->w_msg_hdr).msg_len = uVar3;
      *(undefined4 *)&pdVar1->w_msg_hdr = uVar8;
    }
    (pdVar1->unprocessed_rcds).q = p_Var4;
    (pdVar1->processed_rcds).q = p_Var5;
    pdVar1->buffered_messages = p_Var2;
    (pdVar1->buffered_app_data).q = p_Var7;
    pdVar1->sent_messages = p_Var6;
  }
  ssl3_clear(param_1);
  param_1->version = (-(uint)((param_1->references & 0x8000U) == 0) & 0xfdff) + 0x100;
  return;
}

