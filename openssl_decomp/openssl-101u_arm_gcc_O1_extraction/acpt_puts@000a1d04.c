
char * acpt_puts(BIO *param_1,char *param_2,char *param_3)

{
  size_t len;
  BIO *pBVar1;
  callback *callback;
  BIO *b;
  BIO *pBVar2;
  int iVar3;
  int extraout_r1;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  int iVar7;
  long in_stack_ffffffc8;
  long in_stack_ffffffcc;
  
  len = strlen(param_2);
  BIO_clear_flags(param_1,0xf);
  piVar6 = (int *)param_1->ptr;
  do {
    pBVar1 = param_1->next_bio;
    pcVar4 = param_3;
    while( true ) {
      if (pBVar1 != (BIO *)0x0) {
        pcVar4 = (char *)BIO_write(pBVar1,param_2,len);
        BIO_copy_next_retry(param_1);
        return pcVar4;
      }
      iVar7 = *piVar6;
      if (iVar7 == 2) goto LAB_000a1d92;
      if (iVar7 == 3) break;
      if (iVar7 != 1) {
        return (char *)0x0;
      }
      if ((char *)piVar6[1] == (char *)0x0) {
        ERR_put_error(0x20,100,0x6f,"bss_acpt.c",0xd2);
        return (char *)0xffffffff;
      }
      iVar7 = BIO_get_accept_socket((char *)piVar6[1],piVar6[6]);
      pcVar4 = (char *)(iVar7 + 1);
      if (pcVar4 == (char *)0x0) {
        return (char *)0xffffffff;
      }
      if ((piVar6[3] != 0) && (iVar3 = BIO_socket_nbio(iVar7,1), iVar3 == 0)) {
        close(iVar7);
        ERR_put_error(0x20,100,0x6a,"bss_acpt.c",0xdd);
        return (char *)0xffffffff;
      }
      pBVar1 = param_1->next_bio;
      piVar6[2] = iVar7;
      param_1->num = iVar7;
      *piVar6 = 2;
    }
    *piVar6 = 2;
LAB_000a1d92:
    BIO_clear_flags(param_1,0xf);
    iVar7 = piVar6[2];
    param_1->retry_reason = 0;
    param_3 = (char *)BIO_accept(iVar7,(char **)(piVar6 + 4));
    pcVar5 = param_3 + 2;
    if (pcVar5 == (char *)0x0) {
      BIO_set_flags(param_1,0xc);
      param_1->retry_reason = 3;
      return (char *)0xffffffff;
    }
    if ((int)param_3 < 0) {
      return param_3;
    }
    pBVar1 = BIO_new_socket((int)param_3,1);
    if (pBVar1 == (BIO *)0x0) {
      return (char *)0x0;
    }
    callback = (callback *)
               BIO_get_callback(param_1,extraout_r1,pcVar4,(int)pcVar5,in_stack_ffffffc8,
                                in_stack_ffffffcc);
    BIO_set_callback(pBVar1,callback);
    pcVar4 = BIO_get_callback_arg(param_1);
    BIO_set_callback_arg(pBVar1,pcVar4);
    if ((piVar6[5] != 0) && (iVar7 = BIO_socket_nbio((int)param_3,1), iVar7 == 0)) {
      ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x103);
LAB_000a1e84:
      BIO_free(pBVar1);
      return (char *)0x0;
    }
    b = pBVar1;
    if ((((BIO *)piVar6[7] != (BIO *)0x0) &&
        ((b = BIO_dup_chain((BIO *)piVar6[7]), b == (BIO *)0x0 ||
         (pBVar2 = BIO_push(b,pBVar1), pBVar2 == (BIO *)0x0)))) ||
       (pBVar2 = BIO_push(param_1,b), pBVar1 = b, pBVar2 == (BIO *)0x0)) goto LAB_000a1e84;
    *piVar6 = 3;
  } while( true );
}

