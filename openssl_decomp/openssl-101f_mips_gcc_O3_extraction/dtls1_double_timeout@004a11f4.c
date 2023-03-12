
void dtls1_double_timeout(SSL *param_1)

{
  uint uVar1;
  BIO *pBVar2;
  dtls1_state_st *pdVar4;
  undefined2 uVar3;
  
  pdVar4 = param_1->d1;
  uVar1 = (*(ushort *)&pdVar4->alert_fragment_len & 0x7fff) << 1;
  uVar3 = (undefined2)uVar1;
  if (0x3c < uVar1) {
    uVar3 = 0x3c;
  }
  *(undefined2 *)&pdVar4->alert_fragment_len = uVar3;
  if (((pdVar4->next_timeout).tv_usec == 0) && (*(int *)&pdVar4->timeout_duration == 0)) {
    *(undefined2 *)&pdVar4->alert_fragment_len = 1;
  }
  (*(code *)PTR_gettimeofday_006aabd4)(&(pdVar4->next_timeout).tv_usec,0);
  pdVar4 = param_1->d1;
  (pdVar4->next_timeout).tv_usec =
       (pdVar4->next_timeout).tv_usec + (uint)*(ushort *)&pdVar4->alert_fragment_len;
  pBVar2 = SSL_get_rbio(param_1);
                    /* WARNING: Could not recover jumptable at 0x004a12a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_ctrl_006a7f18)(pBVar2,0x2d,0,&(param_1->d1->next_timeout).tv_usec);
  return;
}

