
int dtls1_ctrl(SSL *param_1,int param_2,undefined4 param_3,__suseconds_t *param_4)

{
  int iVar1;
  __suseconds_t _Var2;
  BIO *bp;
  dtls1_state_st *pdVar3;
  bool bVar4;
  timeval local_18;
  
  if (param_2 == 0x4a) {
    iVar1 = dtls1_handle_timeout();
    return iVar1;
  }
  if (param_2 == 0x4b) {
    SSL_ctrl(param_1,0x20,0x2000,(void *)0x0);
    param_1->d1->mtu = 1;
    iVar1 = SSL_accept(param_1);
    if (0 < iVar1) {
      bp = SSL_get_rbio(param_1);
      BIO_ctrl(bp,0x2e,0,param_4);
      return 1;
    }
  }
  else if (param_2 == 0x49) {
    if (((param_1->d1->next_timeout).tv_usec != 0) ||
       (iVar1 = *(int *)&param_1->d1->timeout_duration, iVar1 != 0)) {
      gettimeofday(&local_18,(__timezone_ptr_t)0x0);
      pdVar3 = param_1->d1;
      iVar1 = (pdVar3->next_timeout).tv_usec;
      if ((iVar1 < local_18.tv_sec) ||
         ((iVar1 == local_18.tv_sec && (*(int *)&pdVar3->timeout_duration <= local_18.tv_usec)))) {
        *(undefined *)param_4 = 0;
        *(undefined *)((int)param_4 + 1) = 0;
        *(undefined *)((int)param_4 + 2) = 0;
        *(undefined *)((int)param_4 + 3) = 0;
        *(undefined *)(param_4 + 1) = 0;
        *(undefined *)((int)param_4 + 5) = 0;
        *(undefined *)((int)param_4 + 6) = 0;
        *(undefined *)((int)param_4 + 7) = 0;
        if (param_4 == (__suseconds_t *)0x0) {
          return 0;
        }
      }
      else {
        _Var2 = (pdVar3->next_timeout).tv_usec;
        param_4[1] = *(__suseconds_t *)&pdVar3->timeout_duration;
        *param_4 = _Var2;
        local_18.tv_usec = param_4[1] - local_18.tv_usec;
        bVar4 = local_18.tv_usec < 0;
        param_4[1] = local_18.tv_usec;
        local_18.tv_sec = *param_4 - local_18.tv_sec;
        *param_4 = local_18.tv_sec;
        if (bVar4) {
          local_18.tv_sec = local_18.tv_sec + -1;
          local_18.tv_usec = local_18.tv_usec + 1000000;
          *param_4 = local_18.tv_sec;
        }
        if (bVar4) {
          param_4[1] = local_18.tv_usec;
        }
        if ((local_18.tv_sec == 0) && (local_18.tv_usec < 15000)) {
          *(undefined *)param_4 = 0;
          *(undefined *)((int)param_4 + 1) = 0;
          *(undefined *)((int)param_4 + 2) = 0;
          *(undefined *)((int)param_4 + 3) = 0;
          *(undefined *)(param_4 + 1) = 0;
          *(undefined *)((int)param_4 + 5) = 0;
          *(undefined *)((int)param_4 + 6) = 0;
          *(undefined *)((int)param_4 + 7) = 0;
        }
      }
      return 1;
    }
  }
  else {
    iVar1 = ssl3_ctrl();
  }
  return iVar1;
}

