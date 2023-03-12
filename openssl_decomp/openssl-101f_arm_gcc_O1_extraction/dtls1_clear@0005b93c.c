
void dtls1_clear(SSL *param_1)

{
  long lVar1;
  dtls1_state_st *pdVar2;
  int iVar3;
  pqueue p_Var4;
  pqueue p_Var5;
  pqueue p_Var6;
  pqueue p_Var7;
  pqueue p_Var8;
  undefined4 uVar9;
  
  pdVar2 = param_1->d1;
  if (pdVar2 != (dtls1_state_st *)0x0) {
    p_Var8 = (pdVar2->unprocessed_rcds).q;
    p_Var7 = (pdVar2->processed_rcds).q;
    p_Var6 = pdVar2->buffered_messages;
    p_Var5 = pdVar2->sent_messages;
    p_Var4 = (pdVar2->buffered_app_data).q;
    uVar9 = *(undefined4 *)&pdVar2->w_msg_hdr;
    dtls1_clear_queues_isra_0(&param_1->d1);
    memset(param_1->d1,0,0x2e8);
    if (param_1->server != 0) {
      param_1->d1->cookie_len = 0x100;
    }
    lVar1 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    pdVar2 = param_1->d1;
    (pdVar2->unprocessed_rcds).q = p_Var8;
    (pdVar2->processed_rcds).q = p_Var7;
    pdVar2->buffered_messages = p_Var6;
    pdVar2->sent_messages = p_Var5;
    (pdVar2->buffered_app_data).q = p_Var4;
    if (lVar1 << 0x13 < 0) {
      *(undefined4 *)&pdVar2->w_msg_hdr = uVar9;
    }
  }
  ssl3_clear(param_1);
  if ((param_1->references & 0x8000U) == 0) {
    iVar3 = 0xfeff;
  }
  else {
    iVar3 = 0x100;
  }
  param_1->version = iVar3;
  return;
}

