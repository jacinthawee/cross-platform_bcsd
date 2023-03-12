
uint conn_ctrl(int param_1,int param_2,int param_3,BIO *param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  uint uVar4;
  char *pcVar5;
  BIO_METHOD *pBVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char acStack_2c [16];
  int local_1c;
  
  puVar3 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  piVar9 = *(int **)(param_1 + 0x20);
  if (param_2 == 0xf) {
    uVar4 = 1;
    param_4->method = (BIO_METHOD *)piVar9[10];
  }
  else if (param_2 < 0x10) {
    if (param_2 == 9) {
      *(int *)(param_1 + 0x10) = param_3;
      uVar4 = 1;
    }
    else if (param_2 < 10) {
      if (param_2 == 1) {
        *piVar9 = 1;
        if (*(int *)(param_1 + 0x1c) != -1) {
          (*(code *)PTR_close_006a994c)();
          *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
        }
        *(undefined4 *)(param_1 + 0x14) = 0;
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
        if (param_2 == 8) {
          uVar4 = *(uint *)(param_1 + 0x10);
        }
      }
    }
    else {
      if (param_2 == 0xb) goto LAB_00523294;
      uVar4 = 0;
      if (param_2 == 0xc) {
        if ((void *)piVar9[2] != (void *)0x0) {
          BIO_ctrl(param_4,100,1,(void *)piVar9[2]);
        }
        if ((void *)piVar9[1] != (void *)0x0) {
          BIO_ctrl(param_4,100,0,(void *)piVar9[1]);
        }
        BIO_ctrl(param_4,0x66,piVar9[3],(void *)0x0);
        BIO_callback_ctrl(param_4,0xe,(fp *)piVar9[10]);
        uVar4 = 1;
      }
    }
  }
  else if (param_2 == 0x66) {
    piVar9[3] = param_3;
    uVar4 = 1;
  }
  else if (param_2 < 0x67) {
    if (param_2 == 100) {
      if (param_4 == (BIO *)0x0) {
LAB_00523294:
        uVar4 = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0xc) = 1;
        if (param_3 == 0) {
          if (piVar9[1] != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          pcVar5 = BUF_strdup((char *)param_4);
          uVar4 = 1;
          piVar9[1] = (int)pcVar5;
        }
        else if (param_3 == 1) {
          if (piVar9[2] != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          pcVar5 = BUF_strdup((char *)param_4);
          uVar4 = 1;
          piVar9[2] = (int)pcVar5;
        }
        else if (param_3 == 2) {
          BIO_snprintf(acStack_2c,0x10,"%d.%d.%d.%d",(uint)*(byte *)&param_4->method,
                       (uint)*(byte *)((int)&param_4->method + 1),
                       (uint)*(byte *)((int)&param_4->method + 2),
                       (uint)*(byte *)((int)&param_4->method + 3));
          if (piVar9[1] != 0) {
            (*(code *)PTR_CRYPTO_free_006a6e88)();
          }
          pcVar5 = BUF_strdup(acStack_2c);
          uVar4 = 1;
          piVar9[1] = (int)pcVar5;
          pBVar6 = param_4->method;
          uVar1 = (uint)(piVar9 + 4) & 3;
          puVar2 = (uint *)((int)(piVar9 + 4) - uVar1);
          *puVar2 = *puVar2 & -1 << (4 - uVar1) * 8 | (uint)pBVar6 >> uVar1 * 8;
          uVar1 = (int)piVar9 + 0x13U & 3;
          puVar2 = (uint *)(((int)piVar9 + 0x13U) - uVar1);
          *puVar2 = *puVar2 & 0xffffffffU >> (uVar1 + 1) * 8 | (int)pBVar6 << (3 - uVar1) * 8;
        }
        else {
          uVar4 = 1;
          if (param_3 == 3) {
            BIO_snprintf(acStack_2c,0xd,"%d",param_4->method);
            if (piVar9[2] != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)();
            }
            pcVar5 = BUF_strdup(acStack_2c);
            uVar4 = 1;
            pBVar6 = param_4->method;
            piVar9[2] = (int)pcVar5;
            *(short *)(piVar9 + 5) = (short)pBVar6;
          }
        }
      }
    }
    else if (param_2 == 0x65) {
      if (*piVar9 == 6) goto LAB_00523294;
      uVar4 = conn_state(param_1,piVar9);
    }
    else {
LAB_0052329c:
      uVar4 = 0;
    }
  }
  else if (param_2 == 0x69) {
    uVar4 = 0xffffffff;
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_4 != (BIO *)0x0) {
        param_4->method = *(BIO_METHOD **)(param_1 + 0x1c);
      }
      uVar4 = *(uint *)(param_1 + 0x1c);
    }
  }
  else {
    uVar4 = 0;
    if (param_2 == 0x7b) {
      if (param_4 == (BIO *)0x0) {
        if (*(int *)(param_1 + 0xc) == 0) goto LAB_0052329c;
        uVar4 = 1;
LAB_00523408:
        if (param_3 == 3) {
          uVar4 = (uint)*(ushort *)(piVar9 + 5);
        }
      }
      else if (*(int *)(param_1 + 0xc) == 0) {
        uVar4 = 0;
        param_4->method = (BIO_METHOD *)"not initialized";
      }
      else if (param_3 == 0) {
        uVar4 = 1;
        param_4->method = (BIO_METHOD *)piVar9[1];
      }
      else {
        if (param_3 == 1) {
          param_4->method = (BIO_METHOD *)piVar9[2];
          goto LAB_00523294;
        }
        uVar4 = 1;
        if (param_3 != 2) {
          uVar4 = 0;
          goto LAB_00523408;
        }
        param_4->method = (BIO_METHOD *)(piVar9 + 4);
      }
    }
  }
  if (local_1c == *(int *)puVar3) {
    return uVar4;
  }
  iVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar7 == 0) {
    return 0;
  }
  if (*(int *)(iVar7 + 0x10) == 0) {
    return 1;
  }
  iVar8 = *(int *)(iVar7 + 0x1c);
  piVar9 = *(int **)(iVar7 + 0x20);
  if (iVar8 == -1) {
    if (piVar9 == (int *)0x0) goto LAB_005235b4;
    iVar8 = piVar9[1];
  }
  else {
    if (*piVar9 == 6) {
      (*(code *)PTR_shutdown_006a995c)(iVar8,2);
      iVar8 = *(int *)(iVar7 + 0x1c);
    }
    (*(code *)PTR_close_006a994c)(iVar8);
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
    iVar8 = piVar9[1];
  }
  if (iVar8 != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  if (piVar9[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
  }
  (*(code *)PTR_CRYPTO_free_006a6e88)(piVar9);
LAB_005235b4:
  *(undefined4 *)(iVar7 + 0x20) = 0;
  *(undefined4 *)(iVar7 + 0x14) = 0;
  *(undefined4 *)(iVar7 + 0xc) = 0;
  return 1;
}

