
void dtls1_double_timeout(SSL *param_1)

{
  __suseconds_t *p_Var1;
  dtls1_state_st *pdVar2;
  int iVar3;
  BIO *bp;
  ushort uVar4;
  
  pdVar2 = param_1->d1;
  iVar3 = (pdVar2->next_timeout).tv_usec;
  uVar4 = *(short *)&pdVar2->alert_fragment_len * 2;
  if (0x3c < uVar4) {
    uVar4 = 0x3c;
  }
  *(ushort *)&pdVar2->alert_fragment_len = uVar4;
  if ((iVar3 == 0) && (*(int *)&pdVar2->timeout_duration == 0)) {
    *(undefined2 *)&pdVar2->alert_fragment_len = 1;
  }
  gettimeofday((timeval *)&(pdVar2->next_timeout).tv_usec,(__timezone_ptr_t)0x0);
  pdVar2 = param_1->d1;
  p_Var1 = &(pdVar2->next_timeout).tv_usec;
  *p_Var1 = *p_Var1 + (uint)*(ushort *)&pdVar2->alert_fragment_len;
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,&(pdVar2->next_timeout).tv_usec);
  return;
}

