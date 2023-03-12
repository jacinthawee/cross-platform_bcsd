
void dtls1_clear(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  pqueue p_Var2;
  pqueue p_Var3;
  pqueue p_Var4;
  pqueue p_Var5;
  pqueue p_Var6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 *puVar9;
  byte bVar10;
  
  bVar10 = 0;
  pdVar1 = param_1->d1;
  if (pdVar1 != (dtls1_state_st *)0x0) {
    p_Var2 = pdVar1->buffered_messages;
    p_Var3 = (pdVar1->unprocessed_rcds).q;
    p_Var4 = (pdVar1->processed_rcds).q;
    p_Var5 = pdVar1->sent_messages;
    p_Var6 = (pdVar1->buffered_app_data).q;
    uVar7 = *(undefined4 *)&pdVar1->w_msg_hdr;
    dtls1_clear_queues_isra_0();
    pdVar1 = param_1->d1;
    pdVar1->send_cookie = 0;
    pdVar1->listen = 0;
    puVar9 = (undefined4 *)((uint)pdVar1->cookie & 0xfffffffc);
    uVar8 = (uint)((int)pdVar1 + (0x2e8 - (int)puVar9)) >> 2;
    for (; uVar8 != 0; uVar8 = uVar8 - 1) {
      *puVar9 = 0;
      puVar9 = puVar9 + (uint)bVar10 * -2 + 1;
    }
    if (param_1->server != 0) {
      param_1->d1->cookie_len = 0x100;
    }
    uVar8 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    pdVar1 = param_1->d1;
    if ((uVar8 & 0x1000) != 0) {
      *(undefined4 *)&pdVar1->w_msg_hdr = uVar7;
    }
    (pdVar1->unprocessed_rcds).q = p_Var3;
    (pdVar1->processed_rcds).q = p_Var4;
    pdVar1->buffered_messages = p_Var2;
    (pdVar1->buffered_app_data).q = p_Var6;
    pdVar1->sent_messages = p_Var5;
  }
  ssl3_clear(param_1);
  param_1->version = (-(uint)((param_1->references & 0x8000U) == 0) & 0xfdff) + 0x100;
  return;
}

