
void dtls1_double_timeout(SSL *param_1)

{
  uint uVar1;
  BIO *pBVar2;
  dtls1_state_st *pdVar4;
  undefined2 uVar3;
  
  pdVar4 = param_1->d1;
  uVar1 = (*(ushort *)pdVar4->handshake_fragment & 0x7fff) << 1;
  uVar3 = (undefined2)uVar1;
  if (0x3c < uVar1) {
    uVar3 = 0x3c;
  }
  *(undefined2 *)pdVar4->handshake_fragment = uVar3;
  if ((*(int *)&pdVar4->timeout_duration == 0) && (pdVar4->alert_fragment_len == 0)) {
    *(undefined2 *)pdVar4->handshake_fragment = 1;
  }
  (*(code *)PTR_gettimeofday_006a9acc)(&pdVar4->timeout_duration,0);
  pdVar4 = param_1->d1;
  *(uint *)&pdVar4->timeout_duration =
       *(int *)&pdVar4->timeout_duration + (uint)*(ushort *)pdVar4->handshake_fragment;
  pBVar2 = SSL_get_rbio(param_1);
                    /* WARNING: Could not recover jumptable at 0x0049da78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_ctrl_006a6e18)(pBVar2,0x2d,0,&param_1->d1->timeout_duration);
  return;
}

