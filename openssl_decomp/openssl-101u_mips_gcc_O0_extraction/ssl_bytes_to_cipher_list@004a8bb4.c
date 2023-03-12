
int ssl_bytes_to_cipher_list(int param_1,char *param_2,int param_3,int *param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  
  if (*(int *)(param_1 + 0x58) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 0;
  }
  iVar3 = (**(code **)(*(int *)(param_1 + 8) + 0x4c))(0,0);
  if (iVar3 != 0) {
    if (iVar3 == 0) {
      trap(7);
    }
    if (param_3 % iVar3 == 0) {
      if ((param_4 == (int *)0x0) || (iVar8 = *param_4, iVar8 == 0)) {
        iVar8 = (*(code *)PTR_sk_new_null_006a6fa4)();
        if (iVar8 == 0) {
          uVar6 = 0x41;
          uVar5 = 0x5a6;
          goto LAB_004a8ee4;
        }
        if (0 < param_3) goto LAB_004a8c68;
      }
      else {
        (*(code *)PTR_sk_zero_006a8334)(iVar8);
        if (param_3 < 1) goto LAB_004a8cf0;
LAB_004a8c68:
        pcVar9 = param_2 + iVar3;
        iVar7 = iVar3;
        do {
          if (*(int *)(param_1 + 0x58) == 0) {
            if (iVar3 == 3) {
              if (*param_2 != '\0') goto LAB_004a8ca0;
              cVar1 = pcVar9[-2];
            }
            else {
LAB_004a8d6c:
              cVar1 = pcVar9[-2];
            }
joined_r0x004a8d70:
            if ((cVar1 != 'V') || (pcVar9[-1] != '\0')) goto LAB_004a8ca0;
            iVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x40))(param_1,0x77,0,0);
            if (iVar4 == 0) {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa1,0x175,"ssl_lib.c",0x5cd);
              if (*(int *)(param_1 + 0x58) != 0) {
                ssl3_send_alert(param_1,2,0x56);
              }
              goto LAB_004a8e4c;
            }
          }
          else {
            if (iVar3 == 3) {
              if (*param_2 == '\0') {
                cVar1 = pcVar9[-2];
                if (cVar1 != '\0') goto joined_r0x004a8d70;
                if (pcVar9[-1] != -1) goto LAB_004a8d6c;
LAB_004a8d34:
                if (*(int *)(param_1 + 400) != 0) {
                  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa1,0x159,"ssl_lib.c",0x5b6);
                  ssl3_send_alert(param_1,2,0x28);
                  goto LAB_004a8e4c;
                }
                *(undefined4 *)(*(int *)(param_1 + 0x58) + 0x418) = 1;
                goto LAB_004a8cd0;
              }
            }
            else {
              cVar1 = pcVar9[-2];
              if (cVar1 != '\0') goto joined_r0x004a8d70;
              if (pcVar9[-1] == -1) goto LAB_004a8d34;
            }
LAB_004a8ca0:
            iVar4 = (**(code **)(*(int *)(param_1 + 8) + 0x48))(param_2);
            if ((iVar4 != 0) && (iVar4 = (*(code *)PTR_sk_push_006a6fa8)(iVar8,iVar4), iVar4 == 0))
            {
              (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa1,0x41,"ssl_lib.c",0x5db);
LAB_004a8e4c:
              if ((param_4 != (int *)0x0) && (*param_4 != 0)) {
                return 0;
              }
              (*(code *)PTR_sk_free_006a6e80)(iVar8);
              return 0;
            }
          }
LAB_004a8cd0:
          bVar2 = iVar7 < param_3;
          pcVar9 = pcVar9 + iVar3;
          iVar7 = iVar7 + iVar3;
          param_2 = param_2 + iVar3;
        } while (bVar2);
      }
      if (param_4 == (int *)0x0) {
        return iVar8;
      }
LAB_004a8cf0:
      *param_4 = iVar8;
      return iVar8;
    }
  }
  uVar6 = 0x97;
  uVar5 = 0x5a0;
LAB_004a8ee4:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xa1,uVar6,"ssl_lib.c",uVar5);
  return 0;
}

