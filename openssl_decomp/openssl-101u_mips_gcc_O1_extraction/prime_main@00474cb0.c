
int prime_main(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_30;
  int local_2c;
  
  puVar5 = PTR___stack_chk_guard_006a9ae8;
  puVar4 = PTR_bio_err_006a6e3c;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_signal_006a9ad8)(0xd,1);
  if (*(int *)puVar4 == 0) {
    uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
    iVar9 = (*(code *)PTR_BIO_new_006a6ea4)(uVar7);
    *(int *)puVar4 = iVar9;
    if (iVar9 != 0) {
      (*(code *)PTR_BIO_ctrl_006a6e18)(iVar9,0x6a,0x10,*(undefined4 *)PTR_stderr_006a9af8);
    }
  }
  param_1 = param_1 + -1;
  puVar8 = (undefined4 *)(param_2 + 4);
  if (param_1 < 1) {
    if (*(int *)(param_2 + 4) == 0) {
LAB_00475124:
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"No prime specified\n");
LAB_0047513c:
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"options are\n");
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"%-14s hex\n",&DAT_00633928);
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)puVar4,"%-14s number of checks\n","-checks <n>");
      iVar9 = 1;
      goto LAB_00474f34;
    }
LAB_00474ff0:
    local_44 = 0;
    iVar9 = 0;
    bVar1 = false;
    bVar2 = false;
    local_48 = 0x14;
  }
  else {
    pcVar10 = *(char **)(param_2 + 4);
    if (*pcVar10 != '-') goto LAB_00474ff0;
    local_44 = 0;
    local_48 = 0x14;
    iVar9 = 0;
    bVar1 = false;
    bVar2 = false;
    do {
      iVar6 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,&DAT_00633928);
      puVar3 = puVar8;
      if (iVar6 == 0) {
        bVar2 = true;
      }
      else {
        iVar6 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"-generate");
        if (iVar6 == 0) {
          bVar1 = true;
        }
        else {
          iVar6 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"-bits");
          if (iVar6 == 0) {
            param_1 = param_1 + -1;
            if (param_1 == 0) goto LAB_0047513c;
            iVar9 = (*(code *)PTR_strtol_006a9958)(puVar8[1],0,10);
            puVar3 = puVar8 + 1;
          }
          else {
            iVar6 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"-safe");
            if (iVar6 == 0) {
              local_44 = 1;
            }
            else {
              iVar6 = (*(code *)PTR_strcmp_006a9b18)(pcVar10,"-checks");
              if (iVar6 != 0) {
                (*(code *)PTR_BIO_printf_006a6e38)
                          (*(undefined4 *)puVar4,"Unknown option \'%s\'\n",pcVar10);
                goto LAB_0047513c;
              }
              param_1 = param_1 + -1;
              if (param_1 == 0) goto LAB_0047513c;
              local_48 = (*(code *)PTR_strtol_006a9958)(puVar8[1],0,10);
              puVar3 = puVar8 + 1;
            }
          }
        }
      }
      param_1 = param_1 + -1;
      puVar8 = puVar3 + 1;
      if (param_1 == 0) {
        if (puVar3[1] == 0) {
          if (!bVar1) goto LAB_00475124;
          uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
          iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar7);
          if (iVar6 == 0) goto LAB_00475054;
          bVar1 = true;
          (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
          goto LAB_00474e98;
        }
        break;
      }
      pcVar10 = (char *)puVar3[1];
    } while (*pcVar10 == '-');
  }
  uVar7 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  iVar6 = (*(code *)PTR_BIO_new_006a6ea4)(uVar7);
  if (iVar6 != 0) {
    (*(code *)PTR_BIO_ctrl_006a6e18)(iVar6,0x6a,0,*(undefined4 *)PTR_stdout_006a99c8);
  }
LAB_00474e98:
  if (bVar1) {
LAB_00475054:
    if (iVar9 == 0) {
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar4,"Specifiy the number of bits.\n");
      iVar9 = 1;
      goto LAB_00474f34;
    }
    local_30 = (*(code *)PTR_BN_new_006a71b4)();
    (*(code *)PTR_BN_generate_prime_ex_006a7e34)(local_30,iVar9,local_44,0,0,0);
    if (bVar2) {
      uVar7 = (*(code *)PTR_BN_bn2hex_006a7018)(local_30);
    }
    else {
      uVar7 = (*(code *)PTR_BN_bn2dec_006a7e38)(local_30);
    }
    (*(code *)PTR_BIO_printf_006a6e38)(iVar6,"%s\n",uVar7);
    (*(code *)PTR_CRYPTO_free_006a6e88)(uVar7);
  }
  else {
    if (bVar2) {
      (*(code *)PTR_BN_hex2bn_006a70f0)(&local_30,*puVar8);
    }
    else {
      (*(code *)PTR_BN_dec2bn_006a7e30)(&local_30,*puVar8);
    }
    (*(code *)PTR_BN_print_006a6f24)(iVar6,local_30);
    iVar9 = (*(code *)PTR_BN_is_prime_ex_006a7950)(local_30,local_48,0,0);
    if (iVar9 == 0) {
      pcVar10 = "not ";
    }
    else {
      pcVar10 = "";
    }
    (*(code *)PTR_BIO_printf_006a6e38)(iVar6," is %sprime\n",pcVar10);
  }
  (*(code *)PTR_BN_free_006a701c)(local_30);
  (*(code *)PTR_BIO_free_all_006a6e74)(iVar6);
  iVar9 = 0;
LAB_00474f34:
  if (local_2c != *(int *)puVar5) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return local_2c;
  }
  return iVar9;
}
