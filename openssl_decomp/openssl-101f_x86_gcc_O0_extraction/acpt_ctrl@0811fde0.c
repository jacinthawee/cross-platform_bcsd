
int acpt_ctrl(BIO *param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  void *ptr;
  int iVar2;
  BIO *b;
  callback *callback;
  BIO *b_00;
  BIO *pBVar3;
  char *pcVar4;
  int iVar5;
  char *unaff_EBP;
  long in_stack_ffffffe4;
  long in_stack_ffffffe8;
  
  piVar1 = (int *)param_1->ptr;
  if (param_2 == 0x66) {
    piVar1[5] = param_3;
    return 1;
  }
  if (param_2 < 0x67) {
    if (param_2 == 9) {
      param_1->shutdown = param_3;
      return 1;
    }
    if (param_2 < 10) {
      if (param_2 == 1) {
        *piVar1 = 1;
        if (piVar1[2] != -1) {
          shutdown(piVar1[2],2);
          close(piVar1[2]);
          piVar1[2] = -1;
          param_1->num = -1;
        }
        param_1->flags = 0;
        return 0;
      }
      if (param_2 != 8) {
        return 0;
      }
      return param_1->shutdown;
    }
    if (param_2 < 0xb) {
      return 0;
    }
    if (param_2 < 0xd) {
      return 1;
    }
    if (param_2 != 0x65) {
      return 0;
    }
    iVar2 = *piVar1;
    if (iVar2 == 2) goto LAB_0812008f;
    if (iVar2 != 3) {
      if (iVar2 != 1) {
        return 0;
      }
      if ((char *)piVar1[1] == (char *)0x0) {
        iVar5 = 0xd4;
        iVar2 = 0x6f;
      }
      else {
        iVar2 = BIO_get_accept_socket((char *)piVar1[1],piVar1[6]);
        if (iVar2 == -1) {
          return -1;
        }
        if ((piVar1[3] == 0) || (iVar5 = BIO_socket_nbio(iVar2,1), iVar5 != 0)) {
          piVar1[2] = iVar2;
          param_1->num = iVar2;
          *piVar1 = 2;
          return 1;
        }
        close(iVar2);
        iVar5 = 0xe0;
        iVar2 = 0x6a;
      }
      ERR_put_error(0x20,100,iVar2,"bss_acpt.c",iVar5);
      return -1;
    }
    while (param_1->next_bio == (bio_st *)0x0) {
      *piVar1 = 2;
LAB_0812008f:
      if (param_1->next_bio == (bio_st *)0x0) {
        BIO_clear_flags(param_1,0xf);
        param_1->retry_reason = 0;
        iVar2 = BIO_accept(piVar1[2],(char **)(piVar1 + 4));
        if (iVar2 == -2) {
          BIO_set_flags(param_1,0xc);
          param_1->retry_reason = 3;
          return -1;
        }
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar5 = 1;
        pcVar4 = unaff_EBP;
        b = BIO_new_socket(iVar2,1);
        if (b == (BIO *)0x0) {
          return 0;
        }
        callback = (callback *)
                   BIO_get_callback(param_1,iVar5,unaff_EBP,(int)pcVar4,in_stack_ffffffe4,
                                    in_stack_ffffffe8);
        BIO_set_callback(b,callback);
        pcVar4 = BIO_get_callback_arg(param_1);
        BIO_set_callback_arg(b,pcVar4);
        if ((piVar1[5] == 0) || (iVar2 = BIO_socket_nbio(iVar2,1), iVar2 != 0)) {
          b_00 = b;
          if ((((BIO *)piVar1[7] == (BIO *)0x0) ||
              ((b_00 = BIO_dup_chain((BIO *)piVar1[7]), b_00 != (BIO *)0x0 &&
               (pBVar3 = BIO_push(b_00,b), pBVar3 != (BIO *)0x0)))) &&
             (pBVar3 = BIO_push(param_1,b_00), b = b_00, pBVar3 != (BIO *)0x0)) {
            *piVar1 = 3;
            return 1;
          }
        }
        else {
          ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x107);
        }
        BIO_free(b);
        return 0;
      }
      *piVar1 = 3;
    }
  }
  else {
    if (param_2 != 0x76) {
      if (param_2 < 0x77) {
        if (param_2 == 0x68) {
          param_1->init = 1;
          iVar2 = *param_4;
          param_1->num = iVar2;
          piVar1[2] = iVar2;
          *piVar1 = 2;
          param_1->init = 1;
          param_1->shutdown = param_3;
          return 1;
        }
        if (param_2 != 0x69) {
          return 0;
        }
        if (param_1->init != 0) {
          if (param_4 != (int *)0x0) {
            *param_4 = piVar1[2];
          }
          return piVar1[2];
        }
      }
      else {
        if (param_2 == 0x83) {
          piVar1[6] = param_3;
          return 1;
        }
        if (param_2 == 0x84) {
          return piVar1[6];
        }
        if (param_2 != 0x7c) {
          return 0;
        }
        if ((param_1->init != 0) && (param_4 != (int *)0x0)) {
          *param_4 = piVar1[1];
          return 1;
        }
      }
      return -1;
    }
    if (param_4 != (int *)0x0) {
      if (param_3 == 0) {
        ptr = (void *)piVar1[1];
        param_1->init = 1;
        if (ptr != (void *)0x0) {
          CRYPTO_free(ptr);
        }
        pcVar4 = BUF_strdup((char *)param_4);
        piVar1[1] = (int)pcVar4;
        return 1;
      }
      if (param_3 == 1) {
        piVar1[3] = 1;
        return 1;
      }
      if (param_3 == 2) {
        if ((BIO *)piVar1[7] != (BIO *)0x0) {
          BIO_free((BIO *)piVar1[7]);
        }
        piVar1[7] = (int)param_4;
        return 1;
      }
    }
  }
  return 1;
}

