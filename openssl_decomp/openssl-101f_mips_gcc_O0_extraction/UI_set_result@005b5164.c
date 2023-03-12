
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_strlen_006aab30)(result);
  *(uint *)(ui + 0x14) = *(uint *)(ui + 0x14) & 0xfffffffe;
  if (uis != (UI_STRING *)0x0) {
    uVar3 = *(uint *)uis;
    if (uVar3 == 0) {
      iVar2 = 0;
      goto LAB_005b52f0;
    }
    if (uVar3 < 3) {
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_4c,0xd,"%d",*(undefined4 *)(uis + 0x10));
      (*(code *)PTR_BIO_snprintf_006a8060)(auStack_3c,0xd,"%d",*(undefined4 *)(uis + 0x14));
      puVar7 = PTR_ERR_put_error_006a9030;
      if (iVar2 < *(int *)(uis + 0x10)) {
        uVar3 = *(uint *)(ui + 0x14);
        uVar5 = 0x65;
        uVar4 = 0x365;
      }
      else {
        if (iVar2 <= *(int *)(uis + 0x14)) {
          if (*(int *)(uis + 0xc) != 0) {
            (*(code *)PTR_BUF_strlcpy_006a8064)(*(int *)(uis + 0xc),result,*(int *)(uis + 0x14) + 1)
            ;
            iVar2 = 0;
            goto LAB_005b52f0;
          }
          uVar4 = 0x376;
          goto LAB_005b5358;
        }
        uVar3 = *(uint *)(ui + 0x14);
        uVar5 = 100;
        uVar4 = 0x36d;
      }
      *(uint *)(ui + 0x14) = uVar3 | 1;
      (*(code *)puVar7)(0x28,0x69,uVar5,"ui_lib.c",uVar4);
      (*(code *)PTR_ERR_add_error_data_006a9264)
                (5,"You must type in ",auStack_4c,&DAT_00671684,auStack_3c," characters");
      iVar2 = -1;
      goto LAB_005b52f0;
    }
    iVar2 = 0;
    if (uVar3 != 3) goto LAB_005b52f0;
    if (*(undefined **)(uis + 0xc) != (undefined *)0x0) {
      **(undefined **)(uis + 0xc) = 0;
      iVar2 = 0;
      if (*result != '\0') {
        puVar7 = *(undefined **)(uis + 0x14);
        do {
          iVar2 = (*(code *)PTR_strchr_006aab34)(puVar7);
          if (iVar2 != 0) {
            iVar2 = 0;
            **(undefined **)(uis + 0xc) = *puVar7;
            break;
          }
          puVar6 = *(undefined **)(uis + 0x18);
          iVar2 = (*(code *)PTR_strchr_006aab34)(puVar6,(int)*result);
          if (iVar2 != 0) {
            iVar2 = 0;
            **(undefined **)(uis + 0xc) = *puVar6;
            break;
          }
          result = result + 1;
          iVar2 = 0;
        } while (*result != '\0');
      }
      goto LAB_005b52f0;
    }
    uVar4 = 899;
LAB_005b5358:
    (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x69,0x69,"ui_lib.c",uVar4);
  }
  iVar2 = -1;
LAB_005b52f0:
  if (local_2c == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  intr_signal = local_2c;
  return (int)&_ITM_registerTMCloneTable;
}

