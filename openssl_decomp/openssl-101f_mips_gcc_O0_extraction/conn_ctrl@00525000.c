
undefined4 conn_ctrl(int param_1,int param_2,int param_3,BIO *param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  BIO_METHOD *pBVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  char acStack_2c [16];
  int local_1c;
  
  puVar3 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
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
          (*(code *)PTR_close_006aaa5c)();
          *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
        }
        *(undefined4 *)(param_1 + 0x14) = 0;
LAB_005251ec:
        uVar4 = 0;
      }
      else {
        uVar4 = 0;
        if (param_2 == 8) {
          uVar4 = *(undefined4 *)(param_1 + 0x10);
        }
      }
    }
    else {
      if (param_2 == 0xb) goto LAB_005251bc;
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
LAB_005251bc:
        uVar4 = 1;
      }
      else {
        *(undefined4 *)(param_1 + 0xc) = 1;
        if (param_3 == 0) {
          if (piVar9[1] != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
          }
          pcVar5 = BUF_strdup((char *)param_4);
          uVar4 = 1;
          piVar9[1] = (int)pcVar5;
        }
        else if (param_3 == 1) {
          if (piVar9[2] != 0) {
            (*(code *)PTR_CRYPTO_free_006a7f88)();
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
            (*(code *)PTR_CRYPTO_free_006a7f88)();
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
              (*(code *)PTR_CRYPTO_free_006a7f88)();
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
    else {
      if (param_2 != 0x65) goto LAB_005251ec;
      if (*piVar9 == 6) goto LAB_005251bc;
      uVar4 = conn_state(param_1,piVar9);
    }
  }
  else if (param_2 == 0x69) {
    uVar4 = 0xffffffff;
    if (*(int *)(param_1 + 0xc) != 0) {
      if (param_4 != (BIO *)0x0) {
        param_4->method = *(BIO_METHOD **)(param_1 + 0x1c);
      }
      uVar4 = *(undefined4 *)(param_1 + 0x1c);
    }
  }
  else {
    uVar4 = 0;
    if ((param_2 == 0x7b) && (uVar4 = 1, param_4 != (BIO *)0x0)) {
      if (param_3 == 0) {
        param_4->method = (BIO_METHOD *)piVar9[1];
      }
      else if (param_3 == 1) {
        param_4->method = (BIO_METHOD *)piVar9[2];
      }
      else if (param_3 == 2) {
        param_4->method = (BIO_METHOD *)(piVar9 + 4);
      }
      else if (param_3 == 3) {
        param_4->method = (BIO_METHOD *)(uint)*(ushort *)(piVar9 + 5);
      }
      if (*(int *)(param_1 + 0xc) != 0) goto LAB_005251bc;
      uVar4 = 1;
      param_4->method = (BIO_METHOD *)"not initialized";
    }
  }
  if (local_1c == *(int *)puVar3) {
    return uVar4;
  }
  iVar7 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (iVar7 == 0) {
    return 0;
  }
  if (*(int *)(iVar7 + 0x10) == 0) {
    return 1;
  }
  iVar8 = *(int *)(iVar7 + 0x1c);
  piVar9 = *(int **)(iVar7 + 0x20);
  if (iVar8 == -1) {
    if (piVar9 == (int *)0x0) goto LAB_005254b0;
    iVar8 = piVar9[1];
  }
  else {
    if (*piVar9 == 6) {
      (*(code *)PTR_shutdown_006aaa6c)(iVar8,2);
      iVar8 = *(int *)(iVar7 + 0x1c);
    }
    (*(code *)PTR_close_006aaa5c)(iVar8);
    *(undefined4 *)(iVar7 + 0x1c) = 0xffffffff;
    iVar8 = piVar9[1];
  }
  if (iVar8 != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  if (piVar9[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(piVar9);
LAB_005254b0:
  *(undefined4 *)(iVar7 + 0x20) = 0;
  *(undefined4 *)(iVar7 + 0x14) = 0;
  *(undefined4 *)(iVar7 + 0xc) = 0;
  return 1;
}

