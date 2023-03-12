
void dtls1_start_timer(SSL *param_1)

{
  BIO *pBVar1;
  dtls1_state_st *pdVar2;
  
  pdVar2 = param_1->d1;
  if ((*(int *)&pdVar2->timeout_duration == 0) && (pdVar2->alert_fragment_len == 0)) {
    *(undefined2 *)pdVar2->handshake_fragment = 1;
  }
  (*(code *)PTR_gettimeofday_006a9acc)(&pdVar2->timeout_duration,0);
  pdVar2 = param_1->d1;
  *(uint *)&pdVar2->timeout_duration =
       *(int *)&pdVar2->timeout_duration + (uint)*(ushort *)pdVar2->handshake_fragment;
  pBVar1 = SSL_get_rbio(param_1);
                    /* WARNING: Could not recover jumptable at 0x0049d738. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar1,0x2d,0,&param_1->d1->timeout_duration);
  return;
}

