
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int * hwcrhk_load_privkey(undefined4 param_1,undefined4 param_2,undefined4 param_3,
                         undefined4 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_44c;
  uint local_448;
  undefined4 local_444;
  uint local_440;
  undefined *local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined auStack_42c [1024];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_43c = auStack_42c;
  local_438 = 0x400;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
    }
    (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x69,0x6a,"e_chil.c",0x305);
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(4,"e_chil.c",0x309);
    if (piVar4 == (int *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x69,0x41,"e_chil.c",0x30d);
      piVar4 = (int *)0x0;
    }
    else {
      local_434 = param_3;
      local_430 = param_4;
      iVar5 = (*p_hwcrhk_RSALoadKey)(hwcrhk_context,param_2,piVar4,&local_43c,&local_434);
      if (iVar5 == 0) {
        if (*piVar4 == 0) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
          }
          (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x69,0x6d,"e_chil.c",0x31d);
          piVar4 = (int *)0x0;
        }
        else {
          iVar5 = (*(code *)PTR_RSA_new_method_006a881c)(param_1);
          (*(code *)PTR_RSA_set_ex_data_006aa648)(iVar5,hndidx_rsa,piVar4);
          uVar6 = (*(code *)PTR_BN_new_006a82b4)();
          puVar1 = PTR_BN_new_006a82b4;
          *(undefined4 *)(iVar5 + 0x14) = uVar6;
          puVar7 = (undefined4 *)(*(code *)puVar1)();
          pcVar3 = p_hwcrhk_RSAGetPublicKey;
          local_444 = *puVar7;
          local_44c = **(undefined4 **)(iVar5 + 0x14);
          iVar9 = (*(undefined4 **)(iVar5 + 0x14))[2];
          local_440 = puVar7[2] << 2;
          *(undefined4 **)(iVar5 + 0x10) = puVar7;
          local_448 = iVar9 << 2;
          *(uint *)(iVar5 + 0x3c) = *(uint *)(iVar5 + 0x3c) | 0x20;
          iVar9 = (*pcVar3)(*piVar4,&local_444,&local_44c,&local_43c);
          if (iVar9 == -3) {
            (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(iVar5 + 0x14),local_448 >> 2);
            (*(code *)PTR_bn_expand2_006a9680)(*(undefined4 *)(iVar5 + 0x10),local_440 >> 2);
            local_44c = **(undefined4 **)(iVar5 + 0x14);
            local_444 = **(undefined4 **)(iVar5 + 0x10);
            local_448 = (*(undefined4 **)(iVar5 + 0x14))[2] << 2;
            local_440 = (*(undefined4 **)(iVar5 + 0x10))[2] << 2;
            iVar9 = (*p_hwcrhk_RSAGetPublicKey)(*piVar4,&local_444,&local_44c,&local_43c);
            if (iVar9 == 0) {
              piVar4 = *(int **)(iVar5 + 0x14);
              uVar8 = local_448 >> 2;
              piVar4[1] = uVar8;
              if (uVar8 != 0) {
                iVar9 = *piVar4 + (local_448 & 0xfffffffc) + -8;
                do {
                  if (*(int *)(iVar9 + 4) != 0) break;
                  uVar8 = uVar8 - 1;
                  iVar9 = iVar9 + -4;
                } while (uVar8 != 0);
                piVar4[1] = uVar8;
              }
              piVar4 = *(int **)(iVar5 + 0x10);
              uVar8 = local_440 >> 2;
              piVar4[1] = uVar8;
              if (uVar8 != 0) {
                iVar9 = *piVar4 + (local_440 & 0xfffffffc) + -8;
                do {
                  if (*(int *)(iVar9 + 4) != 0) break;
                  uVar8 = uVar8 - 1;
                  iVar9 = iVar9 + -4;
                } while (uVar8 != 0);
                piVar4[1] = uVar8;
              }
              piVar4 = (int *)(*(code *)PTR_EVP_PKEY_new_006a8710)();
              (*(code *)PTR_EVP_PKEY_assign_006a94e4)(piVar4,6,iVar5);
              if (piVar4 == (int *)0x0) {
                if (HWCRHK_lib_error_code == 0) {
                  HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
                }
                (*(code *)PTR_ERR_put_error_006a9030)
                          (HWCRHK_lib_error_code,0x69,0x6e,"e_chil.c",0x348);
                piVar4 = (int *)0x0;
              }
              goto LAB_005d6078;
            }
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
            }
            uVar6 = 0x339;
          }
          else {
            if (HWCRHK_lib_error_code == 0) {
              HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
            }
            uVar6 = 0x32c;
          }
          (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",uVar6);
          (*(code *)PTR_ERR_add_error_data_006a9264)(1,local_43c);
          (*(code *)PTR_RSA_free_006a86f0)(iVar5);
          piVar4 = (int *)0x0;
        }
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
        }
        (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x69,0x66,"e_chil.c",0x316);
        (*(code *)PTR_ERR_add_error_data_006a9264)(1,local_43c);
        piVar4 = (int *)0x0;
      }
    }
  }
LAB_005d6078:
  if (local_2c == *(int *)puVar2) {
    return piVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  piVar4 = (int *)hwcrhk_load_privkey();
  if (piVar4 != (int *)0x0) {
    if (*piVar4 != 6) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006aa644)();
      }
      (*(code *)PTR_ERR_put_error_006a9030)(HWCRHK_lib_error_code,0x6a,0x67,"e_chil.c",0x373);
      (*(code *)PTR_EVP_PKEY_free_006a7f78)(piVar4);
      return (int *)0x0;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,10,"e_chil.c",0x365);
    iVar9 = piVar4[5];
    iVar5 = (*(code *)PTR_RSA_new_006a8964)();
    piVar4[5] = iVar5;
    puVar2 = PTR_CRYPTO_lock_006a926c;
    uVar6 = *(undefined4 *)(iVar9 + 0x14);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar9 + 0x10);
    *(undefined4 *)(iVar5 + 0x14) = uVar6;
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(undefined4 *)(iVar9 + 0x14) = 0;
    (*(code *)puVar2)(10,10,"e_chil.c",0x36c);
    (*(code *)PTR_RSA_free_006a86f0)(iVar9);
    return piVar4;
  }
  return (int *)0x0;
}

