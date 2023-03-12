
void conn_ctrl(int param_1,int param_2,int param_3,BIO *param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  int __fd;
  int *piVar3;
  char acStack_2c [16];
  int local_1c;
  
  piVar3 = *(int **)(param_1 + 0x20);
  local_1c = __TMC_END__;
  if (param_2 == 0xf) {
    uVar1 = 1;
    param_4->method = (BIO_METHOD *)piVar3[10];
    goto LAB_000a05ec;
  }
  if (0xf < param_2) {
    if (param_2 == 0x66) {
      piVar3[3] = param_3;
      uVar1 = 1;
      goto LAB_000a05ec;
    }
    if (param_2 < 0x67) {
      if (param_2 == 100) {
        if (param_4 != (BIO *)0x0) {
          *(undefined4 *)(param_1 + 0xc) = 1;
          if (param_3 == 0) {
            if ((void *)piVar3[1] != (void *)0x0) {
              CRYPTO_free((void *)piVar3[1]);
            }
            uVar1 = 1;
            pcVar2 = BUF_strdup((char *)param_4);
            piVar3[1] = (int)pcVar2;
            goto LAB_000a05ec;
          }
          if (param_3 == 1) {
            if ((void *)piVar3[2] != (void *)0x0) {
              CRYPTO_free((void *)piVar3[2]);
            }
            uVar1 = 1;
            pcVar2 = BUF_strdup((char *)param_4);
            piVar3[2] = (int)pcVar2;
            goto LAB_000a05ec;
          }
          if (param_3 == 2) {
            BIO_snprintf(acStack_2c,0x10,"%d.%d.%d.%d",(uint)*(byte *)&param_4->method,
                         (uint)*(byte *)((int)&param_4->method + 1),
                         (uint)*(byte *)((int)&param_4->method + 2),
                         (uint)*(byte *)((int)&param_4->method + 3));
            if ((void *)piVar3[1] != (void *)0x0) {
              CRYPTO_free((void *)piVar3[1]);
            }
            uVar1 = 1;
            pcVar2 = BUF_strdup(acStack_2c);
            piVar3[1] = (int)pcVar2;
            piVar3[4] = (int)param_4->method;
            goto LAB_000a05ec;
          }
          if (param_3 == 3) {
            BIO_snprintf(acStack_2c,0xd,"%d",param_4->method);
            if ((void *)piVar3[2] != (void *)0x0) {
              CRYPTO_free((void *)piVar3[2]);
            }
            uVar1 = 1;
            pcVar2 = BUF_strdup(acStack_2c);
            *(short *)(piVar3 + 5) = (short)param_4->method;
            piVar3[2] = (int)pcVar2;
            goto LAB_000a05ec;
          }
        }
      }
      else {
        if (param_2 != 0x65) goto LAB_000a0676;
        if (*piVar3 != 6) {
          uVar1 = conn_state(param_1,piVar3);
          goto LAB_000a05ec;
        }
      }
    }
    else {
      if (param_2 == 0x69) {
        if (*(int *)(param_1 + 0xc) == 0) {
          uVar1 = 0xffffffff;
        }
        else {
          if (param_4 != (BIO *)0x0) {
            param_4->method = *(BIO_METHOD **)(param_1 + 0x1c);
          }
          uVar1 = *(undefined4 *)(param_1 + 0x1c);
        }
        goto LAB_000a05ec;
      }
      if (param_2 != 0x7b) goto LAB_000a0676;
      if (param_4 != (BIO *)0x0) {
        if (param_3 == 0) {
          param_4->method = (BIO_METHOD *)piVar3[1];
        }
        else if (param_3 == 1) {
          param_4->method = (BIO_METHOD *)piVar3[2];
        }
        else if (param_3 == 2) {
          param_4->method = (BIO_METHOD *)(piVar3 + 4);
        }
        else if (param_3 == 3) {
          param_4->method = (BIO_METHOD *)(uint)*(ushort *)(piVar3 + 5);
        }
        if (*(int *)(param_1 + 0xc) == 0) {
          uVar1 = 1;
          param_4->method = (BIO_METHOD *)"not initialized";
          goto LAB_000a05ec;
        }
      }
    }
    goto LAB_000a0672;
  }
  if (param_2 == 9) {
    *(int *)(param_1 + 0x10) = param_3;
    uVar1 = 1;
    goto LAB_000a05ec;
  }
  if (param_2 < 10) {
    if (param_2 == 1) {
      *piVar3 = 1;
      __fd = *(int *)(param_1 + 0x1c);
      if (__fd != -1) {
        if (**(int **)(param_1 + 0x20) == 6) {
          shutdown(__fd,2);
          __fd = *(int *)(param_1 + 0x1c);
        }
        close(__fd);
        *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
      }
      *(undefined4 *)(param_1 + 0x14) = 0;
      uVar1 = 0;
      goto LAB_000a05ec;
    }
    if (param_2 == 8) {
      uVar1 = *(undefined4 *)(param_1 + 0x10);
      goto LAB_000a05ec;
    }
LAB_000a0676:
    uVar1 = 0;
  }
  else {
    if (param_2 != 0xb) {
      if (param_2 != 0xc) goto LAB_000a0676;
      if ((void *)piVar3[2] != (void *)0x0) {
        BIO_ctrl(param_4,100,1,(void *)piVar3[2]);
      }
      if ((void *)piVar3[1] != (void *)0x0) {
        BIO_ctrl(param_4,100,0,(void *)piVar3[1]);
      }
      BIO_ctrl(param_4,0x66,piVar3[3],(void *)0x0);
      BIO_callback_ctrl(param_4,0xe,(fp *)piVar3[10]);
    }
LAB_000a0672:
    uVar1 = 1;
  }
LAB_000a05ec:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}

