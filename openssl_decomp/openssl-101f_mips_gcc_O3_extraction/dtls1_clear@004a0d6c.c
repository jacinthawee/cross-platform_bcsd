
void dtls1_clear(SSL *param_1)

{
  dtls1_state_st *pdVar1;
  uint uVar2;
  int iVar3;
  pqueue p_Var4;
  pqueue p_Var5;
  pqueue p_Var6;
  pqueue p_Var7;
  pqueue p_Var8;
  undefined4 uVar9;
  
  pdVar1 = param_1->d1;
  if (pdVar1 != (dtls1_state_st *)0x0) {
    p_Var8 = (pdVar1->unprocessed_rcds).q;
    p_Var7 = (pdVar1->processed_rcds).q;
    p_Var6 = pdVar1->buffered_messages;
    p_Var5 = pdVar1->sent_messages;
    p_Var4 = (pdVar1->buffered_app_data).q;
    uVar9 = *(undefined4 *)&pdVar1->w_msg_hdr;
    dtls1_clear_queues_isra_0(&param_1->d1);
    (*(code *)PTR_memset_006aab00)(param_1->d1,0,0x2e8);
    if (param_1->server != 0) {
      param_1->d1->cookie_len = 0x100;
    }
    uVar2 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    if ((uVar2 & 0x1000) == 0) {
      pdVar1 = param_1->d1;
    }
    else {
      pdVar1 = param_1->d1;
      *(undefined4 *)&pdVar1->w_msg_hdr = uVar9;
    }
    (pdVar1->unprocessed_rcds).q = p_Var8;
    (pdVar1->processed_rcds).q = p_Var7;
    pdVar1->buffered_messages = p_Var6;
    pdVar1->sent_messages = p_Var5;
    (pdVar1->buffered_app_data).q = p_Var4;
  }
  ssl3_clear(param_1);
  iVar3 = 0x100;
  if ((param_1->references & 0x8000U) == 0) {
    iVar3 = 0xfeff;
  }
  param_1->version = iVar3;
  return;
}

