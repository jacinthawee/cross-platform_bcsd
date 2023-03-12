
void dtls1_start_timer(SSL *param_1)

{
  BIO *pBVar1;
  dtls1_state_st *pdVar2;
  
  pdVar2 = param_1->d1;
  if (((pdVar2->next_timeout).tv_usec == 0) && (*(int *)&pdVar2->timeout_duration == 0)) {
    *(undefined2 *)&pdVar2->alert_fragment_len = 1;
  }
  (*(code *)PTR_gettimeofday_006aabd4)(&(pdVar2->next_timeout).tv_usec,0);
  pdVar2 = param_1->d1;
  (pdVar2->next_timeout).tv_usec =
       (pdVar2->next_timeout).tv_usec + (uint)*(ushort *)&pdVar2->alert_fragment_len;
  pBVar1 = SSL_get_rbio(param_1);
                    /* WARNING: Could not recover jumptable at 0x004a0f68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar1,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
  return;
}

