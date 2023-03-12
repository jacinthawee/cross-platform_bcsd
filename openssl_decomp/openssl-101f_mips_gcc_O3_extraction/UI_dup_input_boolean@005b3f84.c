
int UI_dup_input_boolean
              (UI *ui,char *prompt,char *action_desc,char *ok_chars,char *cancel_chars,int flags,
              char *result_buf)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (prompt == (char *)0x0) {
    iVar1 = 0;
    if (action_desc != (char *)0x0) goto LAB_005b3fe0;
LAB_005b4088:
    iVar2 = 0;
    if (ok_chars != (char *)0x0) goto LAB_005b4000;
LAB_005b4090:
    iVar3 = 0;
LAB_005b4018:
    if (cancel_chars == (char *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = (*(code *)PTR_BUF_strdup_006a80dc)(cancel_chars);
      if (iVar4 == 0) {
        uVar5 = 0x15c;
LAB_005b40b4:
        (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6e,0x41,"ui_lib.c",uVar5);
        if (iVar1 != 0) goto LAB_005b40cc;
        goto LAB_005b40dc;
      }
    }
    iVar1 = general_allocate_boolean_constprop_5(ui,iVar1,iVar2,iVar3,iVar4,1,flags,result_buf);
  }
  else {
    iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(prompt);
    if (iVar1 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6e,0x41,"ui_lib.c",0x13e);
    }
    else {
      if (action_desc == (char *)0x0) goto LAB_005b4088;
LAB_005b3fe0:
      iVar2 = (*(code *)PTR_BUF_strdup_006a80dc)(action_desc);
      if (iVar2 != 0) {
        if (ok_chars == (char *)0x0) goto LAB_005b4090;
LAB_005b4000:
        iVar3 = (*(code *)PTR_BUF_strdup_006a80dc)(ok_chars);
        if (iVar3 != 0) goto LAB_005b4018;
        uVar5 = 0x152;
        goto LAB_005b40b4;
      }
      iVar3 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(0x28,0x6e,0x41,"ui_lib.c",0x148);
      if (iVar1 == 0) {
        return -1;
      }
LAB_005b40cc:
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar1);
LAB_005b40dc:
      if (iVar2 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
      }
      if (iVar3 != 0) {
        (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
        return -1;
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}

