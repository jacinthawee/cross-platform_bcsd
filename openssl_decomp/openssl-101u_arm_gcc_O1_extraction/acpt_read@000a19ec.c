
char * acpt_read(BIO *param_1,void *param_2,char *param_3)

{
  BIO *pBVar1;
  char *pcVar2;
  callback *callback;
  BIO *pBVar3;
  BIO *pBVar4;
  int iVar5;
  int extraout_r1;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  long in_stack_ffffffc8;
  long in_stack_ffffffcc;
  
  pcVar2 = param_3;
  BIO_clear_flags(param_1,0xf);
  piVar8 = (int *)param_1->ptr;
  do {
    pBVar1 = param_1->next_bio;
    pcVar6 = pcVar2;
    while( true ) {
      if (pBVar1 != (BIO *)0x0) {
        pcVar2 = (char *)BIO_read(pBVar1,param_2,(int)param_3);
        BIO_copy_next_retry(param_1);
        return pcVar2;
      }
      iVar9 = *piVar8;
      if (iVar9 == 2) goto LAB_000a1a64;
      if (iVar9 == 3) break;
      if (iVar9 != 1) {
        return (char *)0x0;
      }
      if ((char *)piVar8[1] == (char *)0x0) {
        ERR_put_error(0x20,100,0x6f,"bss_acpt.c",0xd2);
        return (char *)0xffffffff;
      }
      iVar9 = BIO_get_accept_socket((char *)piVar8[1],piVar8[6]);
      pcVar6 = (char *)(iVar9 + 1);
      if (pcVar6 == (char *)0x0) {
        return (char *)0xffffffff;
      }
      if ((piVar8[3] != 0) && (iVar5 = BIO_socket_nbio(iVar9,1), iVar5 == 0)) {
        close(iVar9);
        ERR_put_error(0x20,100,0x6a,"bss_acpt.c",0xdd);
        return (char *)0xffffffff;
      }
      pBVar1 = param_1->next_bio;
      piVar8[2] = iVar9;
      param_1->num = iVar9;
      *piVar8 = 2;
    }
    *piVar8 = 2;
LAB_000a1a64:
    BIO_clear_flags(param_1,0xf);
    iVar9 = piVar8[2];
    param_1->retry_reason = 0;
    pcVar2 = (char *)BIO_accept(iVar9,(char **)(piVar8 + 4));
    pcVar7 = pcVar2 + 2;
    if (pcVar7 == (char *)0x0) {
      BIO_set_flags(param_1,0xc);
      param_1->retry_reason = 3;
      return (char *)0xffffffff;
    }
    if ((int)pcVar2 < 0) {
      return pcVar2;
    }
    pBVar1 = BIO_new_socket((int)pcVar2,1);
    if (pBVar1 == (BIO *)0x0) {
      return (char *)0x0;
    }
    callback = (callback *)
               BIO_get_callback(param_1,extraout_r1,pcVar6,(int)pcVar7,in_stack_ffffffc8,
                                in_stack_ffffffcc);
    BIO_set_callback(pBVar1,callback);
    pcVar6 = BIO_get_callback_arg(param_1);
    BIO_set_callback_arg(pBVar1,pcVar6);
    if ((piVar8[5] != 0) && (iVar9 = BIO_socket_nbio((int)pcVar2,1), iVar9 == 0)) {
      ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x103);
LAB_000a1b50:
      BIO_free(pBVar1);
      return (char *)0x0;
    }
    pBVar3 = pBVar1;
    if ((((BIO *)piVar8[7] != (BIO *)0x0) &&
        ((pBVar3 = BIO_dup_chain((BIO *)piVar8[7]), pBVar3 == (BIO *)0x0 ||
         (pBVar4 = BIO_push(pBVar3,pBVar1), pBVar4 == (BIO *)0x0)))) ||
       (pBVar1 = pBVar3, pBVar3 = BIO_push(param_1,pBVar1), pBVar3 == (BIO *)0x0))
    goto LAB_000a1b50;
    *piVar8 = 3;
  } while( true );
}

