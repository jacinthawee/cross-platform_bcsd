
int dtls1_ctrl(SSL *param_1,int param_2,undefined4 param_3,int *param_4)

{
  __suseconds_t *p_Var1;
  dtls1_state_st *pdVar2;
  int iVar3;
  BIO *bp;
  int in_GS_OFFSET;
  timeval local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_2 == 0x4a) {
    iVar3 = dtls1_handle_timeout(param_1);
    goto LAB_080b8525;
  }
  if (param_2 == 0x4b) {
    SSL_ctrl(param_1,0x20,0x2000,(void *)0x0);
    param_1->d1->mtu = 1;
    iVar3 = SSL_accept(param_1);
    if (0 < iVar3) {
      bp = SSL_get_rbio(param_1);
      BIO_ctrl(bp,0x2e,0,param_4);
      iVar3 = 1;
    }
    goto LAB_080b8525;
  }
  if (param_2 != 0x49) {
    iVar3 = ssl3_ctrl(param_1,param_2,param_3,param_4);
    goto LAB_080b8525;
  }
  if (((param_1->d1->next_timeout).tv_usec == 0) && (*(int *)&param_1->d1->timeout_duration == 0)) {
    iVar3 = 0;
    goto LAB_080b8525;
  }
  gettimeofday(&local_18,(__timezone_ptr_t)0x0);
  pdVar2 = param_1->d1;
  p_Var1 = &(pdVar2->next_timeout).tv_usec;
  if ((*p_Var1 < local_18.tv_sec) ||
     ((*p_Var1 == local_18.tv_sec &&
      (*(int *)&pdVar2->timeout_duration == local_18.tv_usec ||
       *(int *)&pdVar2->timeout_duration < local_18.tv_usec)))) {
LAB_080b8638:
    *param_4 = 0;
    param_4[1] = 0;
  }
  else {
    local_18.tv_usec = *(int *)&pdVar2->timeout_duration - local_18.tv_usec;
    local_18.tv_sec = (pdVar2->next_timeout).tv_usec - local_18.tv_sec;
    param_4[1] = local_18.tv_usec;
    *param_4 = local_18.tv_sec;
    if (local_18.tv_usec < 0) {
      local_18.tv_sec = local_18.tv_sec + -1;
      local_18.tv_usec = local_18.tv_usec + 1000000;
      *param_4 = local_18.tv_sec;
      param_4[1] = local_18.tv_usec;
    }
    if ((local_18.tv_sec == 0) && (local_18.tv_usec < 15000)) goto LAB_080b8638;
  }
  iVar3 = 1;
LAB_080b8525:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

