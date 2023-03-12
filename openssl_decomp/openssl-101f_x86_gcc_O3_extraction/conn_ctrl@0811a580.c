
undefined4 conn_ctrl(int param_1,int param_2,int param_3,BIO *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  int in_GS_OFFSET;
  char local_20 [16];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  piVar1 = *(int **)(param_1 + 0x20);
  if (param_2 == 0xf) {
    param_4->method = (BIO_METHOD *)piVar1[10];
  }
  else {
    if (param_2 < 0x10) {
      if (param_2 == 9) {
        *(int *)(param_1 + 0x10) = param_3;
        uVar2 = 1;
        goto LAB_0811a608;
      }
      if (param_2 < 10) {
        if (param_2 == 1) {
          *piVar1 = 1;
          if (*(int *)(param_1 + 0x1c) != -1) {
            close(*(int *)(param_1 + 0x1c));
            *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
          }
          *(undefined4 *)(param_1 + 0x14) = 0;
        }
        else if (param_2 == 8) {
          uVar2 = *(undefined4 *)(param_1 + 0x10);
          goto LAB_0811a608;
        }
      }
      else {
        uVar2 = 1;
        if (param_2 == 0xb) goto LAB_0811a608;
        if (param_2 == 0xc) {
          if ((void *)piVar1[2] != (void *)0x0) {
            BIO_ctrl(param_4,100,1,(void *)piVar1[2]);
          }
          if ((void *)piVar1[1] != (void *)0x0) {
            BIO_ctrl(param_4,100,0,(void *)piVar1[1]);
          }
          BIO_ctrl(param_4,0x66,piVar1[3],(void *)0x0);
          BIO_callback_ctrl(param_4,0xe,(fp *)piVar1[10]);
          uVar2 = 1;
          goto LAB_0811a608;
        }
      }
LAB_0811a728:
      uVar2 = 0;
      goto LAB_0811a608;
    }
    if (param_2 == 0x66) {
      piVar1[3] = param_3;
      uVar2 = 1;
      goto LAB_0811a608;
    }
    if (param_2 < 0x67) {
      if (param_2 == 100) {
        if (param_4 != (BIO *)0x0) {
          *(undefined4 *)(param_1 + 0xc) = 1;
          if (param_3 == 0) {
            if ((void *)piVar1[1] != (void *)0x0) {
              CRYPTO_free((void *)piVar1[1]);
            }
            pcVar3 = BUF_strdup((char *)param_4);
            piVar1[1] = (int)pcVar3;
            uVar2 = 1;
            goto LAB_0811a608;
          }
          if (param_3 == 1) {
            if ((void *)piVar1[2] != (void *)0x0) {
              CRYPTO_free((void *)piVar1[2]);
            }
            pcVar3 = BUF_strdup((char *)param_4);
            piVar1[2] = (int)pcVar3;
            uVar2 = 1;
            goto LAB_0811a608;
          }
          if (param_3 == 2) {
            BIO_snprintf(local_20,0x10,"%d.%d.%d.%d",(uint)*(byte *)&param_4->method,
                         (uint)*(byte *)((int)&param_4->method + 1),
                         (uint)*(byte *)((int)&param_4->method + 2),
                         (uint)*(byte *)((int)&param_4->method + 3));
            if ((void *)piVar1[1] != (void *)0x0) {
              CRYPTO_free((void *)piVar1[1]);
            }
            pcVar3 = BUF_strdup(local_20);
            piVar1[1] = (int)pcVar3;
            piVar1[4] = (int)param_4->method;
            uVar2 = 1;
            goto LAB_0811a608;
          }
          if (param_3 == 3) {
            BIO_snprintf(local_20,0xd,"%d",param_4->method);
            if ((void *)piVar1[2] != (void *)0x0) {
              CRYPTO_free((void *)piVar1[2]);
            }
            pcVar3 = BUF_strdup(local_20);
            piVar1[2] = (int)pcVar3;
            *(short *)(piVar1 + 5) = (short)param_4->method;
            uVar2 = 1;
            goto LAB_0811a608;
          }
        }
      }
      else {
        if (param_2 != 0x65) goto LAB_0811a728;
        if (*piVar1 != 6) {
          uVar2 = conn_state();
          goto LAB_0811a608;
        }
      }
    }
    else {
      if (param_2 == 0x69) {
        if (*(int *)(param_1 + 0xc) == 0) {
          uVar2 = 0xffffffff;
        }
        else {
          if (param_4 != (BIO *)0x0) {
            param_4->method = *(BIO_METHOD **)(param_1 + 0x1c);
          }
          uVar2 = *(undefined4 *)(param_1 + 0x1c);
        }
        goto LAB_0811a608;
      }
      if (param_2 != 0x7b) goto LAB_0811a728;
      if (param_4 != (BIO *)0x0) {
        if (param_3 == 0) {
          param_4->method = (BIO_METHOD *)piVar1[1];
        }
        else if (param_3 == 1) {
          param_4->method = (BIO_METHOD *)piVar1[2];
        }
        else if (param_3 == 2) {
          param_4->method = (BIO_METHOD *)(piVar1 + 4);
        }
        else if (param_3 == 3) {
          param_4->method = (BIO_METHOD *)(uint)*(ushort *)(piVar1 + 5);
        }
        if (*(int *)(param_1 + 0xc) == 0) {
          param_4->method = (BIO_METHOD *)0x822609b;
          uVar2 = 1;
          goto LAB_0811a608;
        }
      }
    }
  }
  uVar2 = 1;
LAB_0811a608:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

