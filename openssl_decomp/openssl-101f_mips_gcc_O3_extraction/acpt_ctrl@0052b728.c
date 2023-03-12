
int acpt_ctrl(BIO *param_1,int param_2,char *param_3,int *param_4)

{
  char *pcVar1;
  int iVar2;
  BIO *b;
  callback *callback;
  BIO *b_00;
  BIO *pBVar3;
  int iVar4;
  int *piVar5;
  long in_stack_ffffffd8;
  long in_stack_ffffffdc;
  
  piVar5 = (int *)param_1->ptr;
  if (param_2 == 0x66) {
    piVar5[5] = (int)param_3;
    return 1;
  }
  if (param_2 < 0x67) {
    if (param_2 == 9) {
      param_1->shutdown = (int)param_3;
      return 1;
    }
    if (param_2 < 10) {
      if (param_2 == 1) {
        *piVar5 = 1;
        if (piVar5[2] != -1) {
          (*(code *)PTR_shutdown_006aaa6c)(piVar5[2],2);
          (*(code *)PTR_close_006aaa5c)(piVar5[2]);
          piVar5[2] = -1;
          param_1->num = -1;
        }
        param_1->flags = 0;
        return 0;
      }
      if (param_2 == 8) {
        return param_1->shutdown;
      }
      return 0;
    }
    if (param_2 < 0xb) {
      return 0;
    }
    if (0xc < param_2) {
      if (param_2 != 0x65) {
        return 0;
      }
      iVar4 = *piVar5;
      while( true ) {
        while (iVar4 == 2) {
          iVar4 = 3;
          if (param_1->next_bio == (bio_st *)0x0) {
            BIO_clear_flags(param_1,0xf);
            iVar4 = piVar5[2];
            param_1->retry_reason = 0;
            iVar4 = BIO_accept(iVar4,(char **)(piVar5 + 4));
            if (iVar4 == -2) {
              BIO_set_flags(param_1,0xc);
              param_1->retry_reason = 3;
              return -1;
            }
            if (iVar4 < 0) {
              return iVar4;
            }
            iVar2 = 1;
            b = BIO_new_socket(iVar4,1);
            if (b == (BIO *)0x0) {
              return 0;
            }
            callback = (callback *)
                       BIO_get_callback(param_1,iVar2,param_3,(int)param_4,in_stack_ffffffd8,
                                        in_stack_ffffffdc);
            BIO_set_callback(b,callback);
            pcVar1 = BIO_get_callback_arg(param_1);
            BIO_set_callback_arg(b,pcVar1);
            if ((piVar5[5] == 0) || (iVar4 = BIO_socket_nbio(iVar4,1), iVar4 != 0)) {
              b_00 = b;
              if ((((BIO *)piVar5[7] == (BIO *)0x0) ||
                  ((b_00 = BIO_dup_chain((BIO *)piVar5[7]), b_00 != (BIO *)0x0 &&
                   (pBVar3 = BIO_push(b_00,b), pBVar3 != (BIO *)0x0)))) &&
                 (pBVar3 = BIO_push(param_1,b_00), b = b_00, pBVar3 != (BIO *)0x0)) {
                *piVar5 = 3;
                return 1;
              }
            }
            else {
              ERR_put_error(0x20,100,0x69,"bss_acpt.c",0x107);
            }
            BIO_free(b);
            return 0;
          }
          *piVar5 = 3;
        }
        if (iVar4 != 3) break;
        iVar4 = 2;
        if (param_1->next_bio != (bio_st *)0x0) {
          return 1;
        }
        *piVar5 = 2;
      }
      if (iVar4 != 1) {
        return 0;
      }
      if ((char *)piVar5[1] == (char *)0x0) {
        iVar2 = 0x6f;
        iVar4 = 0xd4;
      }
      else {
        iVar4 = BIO_get_accept_socket((char *)piVar5[1],piVar5[6]);
        if (iVar4 == -1) {
          return -1;
        }
        if ((piVar5[3] == 0) || (iVar2 = BIO_socket_nbio(iVar4,1), iVar2 != 0)) {
          piVar5[2] = iVar4;
          param_1->num = iVar4;
          *piVar5 = 2;
          return 1;
        }
        (*(code *)PTR_close_006aaa5c)(iVar4);
        iVar2 = 0x6a;
        iVar4 = 0xe0;
      }
      ERR_put_error(0x20,100,iVar2,"bss_acpt.c",iVar4);
      return -1;
    }
    return 1;
  }
  if (param_2 == 0x76) {
    if (param_4 == (int *)0x0) {
      return 1;
    }
    if (param_3 == (char *)0x0) {
      iVar4 = piVar5[1];
      param_1->init = 1;
      if (iVar4 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)();
      }
      pcVar1 = BUF_strdup((char *)param_4);
      piVar5[1] = (int)pcVar1;
      return 1;
    }
    if (param_3 == (char *)0x1) {
      piVar5[3] = 1;
      return 1;
    }
    if (param_3 == &SUB_00000002) {
      if ((BIO *)piVar5[7] != (BIO *)0x0) {
        BIO_free((BIO *)piVar5[7]);
      }
      piVar5[7] = (int)param_4;
      return 1;
    }
    return 1;
  }
  if (param_2 < 0x77) {
    if (param_2 == 0x68) {
      param_1->init = 1;
      iVar4 = *param_4;
      param_1->num = iVar4;
      piVar5[2] = iVar4;
      *piVar5 = 2;
      param_1->shutdown = (int)param_3;
      param_1->init = 1;
      return 1;
    }
    if (param_2 == 0x69) {
      if (param_1->init == 0) {
        return -1;
      }
      if (param_4 != (int *)0x0) {
        *param_4 = piVar5[2];
      }
      return piVar5[2];
    }
    return 0;
  }
  if (param_2 == 0x83) {
    piVar5[6] = (int)param_3;
    return 1;
  }
  if (param_2 != 0x84) {
    if (param_2 != 0x7c) {
      return 0;
    }
    if (param_1->init == 0) {
      return -1;
    }
    if (param_4 == (int *)0x0) {
      return -1;
    }
    *param_4 = piVar5[1];
    return 1;
  }
  return piVar5[6];
}

