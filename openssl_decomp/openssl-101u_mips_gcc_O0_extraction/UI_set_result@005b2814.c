
int UI_set_result(UI *ui,UI_STRING *uis,char *result)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined auStack_4c [16];
  undefined auStack_3c [16];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_strlen_006a9a24)(result);
  *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) & 0xfffffffe;
  if (uis != (UI_STRING *)0x0) {
    uVar3 = *(uint *)uis;
    if (uVar3 == 0) {
      iVar2 = 0;
      goto LAB_005b29a0;
    }
    if (uVar3 < 3) {
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_4c,0xd,"%d",*(undefined4 *)(uis + 0x10));
      (*(code *)PTR_BIO_snprintf_006a6f60)(auStack_3c,0xd,"%d",*(undefined4 *)(uis + 0x14));
      puVar7 = PTR_ERR_put_error_006a7f34;
      if (iVar2 < *(int *)(uis + 0x10)) {
        uVar3 = *(uint *)(ui + 0x14);
        uVar5 = 0x65;
        uVar4 = 0x337;
      }
      else {
        if (iVar2 <= *(int *)(uis + 0x14)) {
          if (*(int *)(uis + 0xc) != 0) {
            (*(code *)PTR_BUF_strlcpy_006a6f64)(*(int *)(uis + 0xc),result,*(int *)(uis + 0x14) + 1)
            ;
            iVar2 = 0;
            goto LAB_005b29a0;
          }
          uVar4 = 0x346;
          goto LAB_005b2a08;
        }
        uVar3 = *(uint *)(ui + 0x14);
        uVar5 = 100;
        uVar4 = 0x33e;
      }
      *(uint *)(ui + 0x14) = uVar3 | 1;
      (*(code *)puVar7)(0x28,0x69,uVar5,"ui_lib.c",uVar4);
      (*(code *)PTR_ERR_add_error_data_006a813c)
                (5,"You must type in ",auStack_4c,&DAT_00670d94,auStack_3c," characters");
      iVar2 = -1;
      goto LAB_005b29a0;
    }
    iVar2 = 0;
    if (uVar3 != 3) goto LAB_005b29a0;
    if (*(undefined **)(uis + 0xc) != (undefined *)0x0) {
      **(undefined **)(uis + 0xc) = 0;
      iVar2 = 0;
      if (*result != '\0') {
        puVar7 = *(undefined **)(uis + 0x14);
        do {
          iVar2 = (*(code *)PTR_strchr_006a9a28)(puVar7);
          if (iVar2 != 0) {
            iVar2 = 0;
            **(undefined **)(uis + 0xc) = *puVar7;
            break;
          }
          puVar6 = *(undefined **)(uis + 0x18);
          iVar2 = (*(code *)PTR_strchr_006a9a28)(puVar6,(int)*result);
          if (iVar2 != 0) {
            iVar2 = 0;
            **(undefined **)(uis + 0xc) = *puVar6;
            break;
          }
          result = result + 1;
          iVar2 = 0;
        } while (*result != '\0');
      }
      goto LAB_005b29a0;
    }
    uVar4 = 0x352;
LAB_005b2a08:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x28,0x69,0x69,"ui_lib.c",uVar4);
  }
  iVar2 = -1;
LAB_005b29a0:
  if (local_2c == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  intr_signal = local_2c;
  return (int)&_gp_1;
}

