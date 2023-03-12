
int pkey_rsa_ctrl_str(undefined4 param_1,undefined4 param_2,int *param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  undefined4 in_stack_ffffffc8;
  undefined4 local_20;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (param_3 == (int *)0x0) {
    piVar4 = (int *)0x93;
    param_4 = "rsa_pmeth.c";
    in_stack_ffffffc8 = 600;
    pcVar3 = &DAT_00000090;
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x90,0x93,"rsa_pmeth.c");
    iVar2 = 0;
  }
  else {
    piVar4 = param_3;
    iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"rsa_padding_mode");
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,"pkcs1");
      if (iVar2 == 0) {
        in_stack_ffffffc8 = 1;
      }
      else {
        iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,"sslv23");
        if (iVar2 == 0) {
          in_stack_ffffffc8 = 2;
        }
        else {
          iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,"none");
          if (iVar2 == 0) {
            in_stack_ffffffc8 = 3;
          }
          else {
            iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,&DAT_0067879c);
            if ((iVar2 == 0) ||
               (iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,&DAT_006787a4), iVar2 == 0)) {
              in_stack_ffffffc8 = 4;
            }
            else {
              iVar2 = (*(code *)PTR_strcmp_006aac20)(param_3,&DAT_006787ac);
              if (iVar2 == 0) {
                in_stack_ffffffc8 = 5;
              }
              else if ((((*(char *)param_3 != 'p') || (*(char *)((int)param_3 + 1) != 's')) ||
                       (*(char *)((int)param_3 + 2) != 's')) ||
                      (in_stack_ffffffc8 = 6, *(char *)((int)param_3 + 3) != '\0')) {
                piVar4 = (int *)&DAT_00000076;
                param_4 = "rsa_pmeth.c";
                in_stack_ffffffc8 = 0x26f;
                pcVar3 = &DAT_00000090;
                (*(code *)PTR_ERR_put_error_006a9030)(4,0x90,0x76,"rsa_pmeth.c");
                iVar2 = -2;
                goto LAB_005fcdcc;
              }
            }
          }
        }
      }
      param_4 = (char *)0x1001;
      piVar4 = (int *)0xffffffff;
      pcVar3 = &DAT_00000006;
      iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)
                        (param_1,6,0xffffffff,0x1001,in_stack_ffffffc8,0);
    }
    else {
      iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"rsa_pss_saltlen");
      if (iVar2 == 0) {
        in_stack_ffffffc8 = (*(code *)PTR_strtol_006aaa68)(param_3,0,10);
        param_4 = (char *)0x1002;
        piVar4 = (int *)&DAT_00000018;
      }
      else {
        iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"rsa_keygen_bits");
        if (iVar2 != 0) {
          pcVar3 = "rsa_keygen_pubexp";
          iVar2 = (*(code *)PTR_strcmp_006aac20)(param_2,"rsa_keygen_pubexp");
          if (iVar2 == 0) {
            local_20 = 0;
            iVar2 = (*(code *)PTR_BN_asc2bn_006aa838)(&local_20,param_3);
            pcVar3 = (char *)param_3;
            if (iVar2 != 0) {
              param_4 = (char *)0x1004;
              piVar4 = (int *)&SUB_00000004;
              pcVar3 = &DAT_00000006;
              in_stack_ffffffc8 = 0;
              iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(param_1,6,4,0x1004,0,local_20);
              if (iVar2 < 1) {
                (*(code *)PTR_BN_free_006a811c)(local_20);
              }
            }
          }
          else {
            iVar2 = -2;
          }
          goto LAB_005fcdcc;
        }
        in_stack_ffffffc8 = (*(code *)PTR_strtol_006aaa68)(param_3,0,10);
        param_4 = (char *)0x1003;
        piVar4 = (int *)&SUB_00000004;
      }
      pcVar3 = &DAT_00000006;
      iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)
                        (param_1,6,piVar4,param_4,in_stack_ffffffc8,0);
    }
  }
LAB_005fcdcc:
  if (local_1c != *(int *)puVar1) {
    iVar2 = local_1c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar2 = (*(code *)PTR_RSA_private_decrypt_006a8734)
                      (in_stack_ffffffc8,param_4,pcVar3,*(undefined4 *)(*(int *)(iVar2 + 8) + 0x14),
                       *(undefined4 *)(*(int *)(iVar2 + 0x14) + 0x10));
    if (-1 < iVar2) {
      *piVar4 = iVar2;
      iVar2 = 1;
    }
    return iVar2;
  }
  return iVar2;
}

