
uint dynamic_ctrl(int *param_1,undefined4 param_2,uint param_3,char *param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  _STACK *p_Var5;
  int *piVar6;
  void *pvVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  uint uVar11;
  char *pcVar12;
  int *piVar13;
  int iVar14;
  uint uVar15;
  void *local_c8;
  ERR_FNS *local_c4;
  undefined4 local_c0;
  undefined auStack_bc [4];
  undefined auStack_b8 [4];
  undefined auStack_b4 [4];
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  int local_9c [29];
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_9c[28] = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (dynamic_ex_data_idx < 0) {
    iVar4 = ENGINE_get_ex_new_index
                      (0,(void *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,dynamic_data_ctx_free_func)
    ;
    if (iVar4 != -1) {
      (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_dyn.c",0x10e);
      if (dynamic_ex_data_idx < 0) {
        dynamic_ex_data_idx = iVar4;
      }
      (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_dyn.c",0x115);
      goto LAB_0051d268;
    }
    ERR_put_error(0x26,0xb5,0x90,"eng_dyn.c",0x10b);
LAB_0051d9dc:
    uVar15 = 0;
    ERR_put_error(0x26,0xb4,0x70,"eng_dyn.c",0x160);
    goto LAB_0051d2b4;
  }
LAB_0051d268:
  piVar3 = (int *)ENGINE_get_ex_data((ENGINE *)param_1,dynamic_ex_data_idx);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x2c,"eng_dyn.c",0xd2);
    if (piVar3 == (int *)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xd4);
    }
    else {
      (*(code *)PTR_memset_006a99f4)(piVar3,0,0x2c);
      *piVar3 = 0;
      piVar3[1] = 0;
      piVar3[2] = 0;
      piVar3[7] = (int)"v_check";
      piVar3[3] = 0;
      piVar3[4] = 0;
      piVar3[5] = 0;
      piVar3[6] = 0;
      piVar3[8] = (int)"bind_engine";
      piVar3[9] = 1;
      p_Var5 = sk_new_null();
      piVar3[10] = (int)p_Var5;
      if (p_Var5 != (_STACK *)0x0) {
        (*(code *)PTR_CRYPTO_lock_006a8144)(9,0x1e,"eng_dyn.c",0xe8);
        piVar6 = (int *)ENGINE_get_ex_data((ENGINE *)param_1,dynamic_ex_data_idx);
        if (piVar6 == (int *)0x0) {
          ENGINE_set_ex_data((ENGINE *)param_1,dynamic_ex_data_idx,piVar3);
          (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_dyn.c",0xf1);
        }
        else {
          (*(code *)PTR_CRYPTO_lock_006a8144)(10,0x1e,"eng_dyn.c",0xf1);
          (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
          piVar3 = piVar6;
        }
        goto LAB_0051d280;
      }
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xe4);
      (*(code *)PTR_CRYPTO_free_006a6e88)(piVar3);
    }
    goto LAB_0051d9dc;
  }
LAB_0051d280:
  if (*piVar3 != 0) {
    iVar14 = 100;
    iVar4 = 0x166;
    goto LAB_0051d29c;
  }
  switch(param_2) {
  case 200:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      if (piVar3[3] == 0) {
        piVar3[3] = 0;
        uVar15 = 0;
      }
      else {
        uVar15 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        piVar3[3] = 0;
      }
    }
    else {
      if (piVar3[3] != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      pcVar12 = BUF_strdup(param_4);
      uVar15 = (uint)(pcVar12 != (char *)0x0);
      piVar3[3] = (int)pcVar12;
    }
    break;
  case 0xc9:
    uVar15 = 1;
    piVar3[4] = (uint)(param_3 != 0);
    break;
  case 0xca:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      if (piVar3[5] == 0) {
        piVar3[5] = 0;
        uVar15 = 0;
      }
      else {
        uVar15 = 0;
        (*(code *)PTR_CRYPTO_free_006a6e88)();
        piVar3[5] = 0;
      }
    }
    else {
      if (piVar3[5] != 0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
      pcVar12 = BUF_strdup(param_4);
      uVar15 = (uint)(pcVar12 != (char *)0x0);
      piVar3[5] = (int)pcVar12;
    }
    break;
  case 0xcb:
    uVar15 = 1;
    if (param_3 < 3) {
      piVar3[6] = param_3;
      break;
    }
    iVar14 = 0x8f;
    iVar4 = 0x185;
    goto LAB_0051d29c;
  case 0xcc:
    uVar15 = 1;
    if (param_3 < 3) {
      piVar3[9] = param_3;
      break;
    }
    iVar14 = 0x8f;
    iVar4 = 0x18e;
    goto LAB_0051d29c;
  case 0xcd:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      iVar14 = 0x8f;
      iVar4 = 0x196;
    }
    else {
      pcVar12 = BUF_strdup(param_4);
      if (pcVar12 != (char *)0x0) {
        sk_insert((_STACK *)piVar3[10],pcVar12,-1);
LAB_0051d918:
        uVar15 = 1;
        break;
      }
      iVar14 = 0x41;
      iVar4 = 0x19c;
    }
LAB_0051d29c:
    ERR_put_error(0x26,0xb4,iVar14,"eng_dyn.c",iVar4);
LAB_0051d2b0:
    uVar15 = 0;
    break;
  case 0xce:
    iVar4 = (*(code *)PTR_DSO_new_006a8880)();
    iVar14 = piVar3[3];
    *piVar3 = iVar4;
    if (iVar14 != 0) {
LAB_0051d4d8:
      if (piVar3[9] == 2) {
LAB_0051d4ec:
        iVar4 = sk_num((_STACK *)piVar3[10]);
        if (0 < iVar4) {
          iVar14 = 0;
          do {
            pvVar7 = sk_value((_STACK *)piVar3[10],iVar14);
            iVar8 = (*(code *)PTR_DSO_merge_006a8888)(*piVar3,piVar3[3],pvVar7);
            if (iVar8 == 0) break;
            iVar9 = (*(code *)PTR_DSO_load_006a8884)(*piVar3,iVar8,0,0);
            if (iVar9 != 0) {
              (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
              goto LAB_0051d71c;
            }
            iVar14 = iVar14 + 1;
            (*(code *)PTR_CRYPTO_free_006a6e88)(iVar8);
          } while (iVar4 != iVar14);
        }
      }
      else {
        iVar4 = (*(code *)PTR_DSO_load_006a8884)(*piVar3,iVar14,0,0);
        if (iVar4 != 0) {
LAB_0051d71c:
          iVar4 = (*(code *)PTR_DSO_bind_func_006a888c)(*piVar3,piVar3[8]);
          piVar3[2] = iVar4;
          if (iVar4 == 0) {
            uVar15 = 0;
            (*(code *)PTR_DSO_free_006a8874)(*piVar3);
            *piVar3 = 0;
            ERR_put_error(0x26,0xb6,0x68,"eng_dyn.c",0x1de);
            break;
          }
          uVar15 = piVar3[4];
          if (uVar15 == 0) {
            pcVar10 = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(*piVar3,piVar3[7]);
            piVar3[1] = (int)pcVar10;
            if ((pcVar10 != (code *)0x0) && (uVar11 = (*pcVar10)(0x20000), 0x1ffff < uVar11))
            goto LAB_0051d780;
            puVar1 = PTR_DSO_free_006a8874;
            piVar3[2] = 0;
            piVar3[1] = 0;
            (*(code *)puVar1)(*piVar3);
            iVar14 = 0x91;
            *piVar3 = 0;
            iVar4 = 0x1f9;
          }
          else {
LAB_0051d780:
            piVar6 = param_1;
            piVar13 = local_9c;
            do {
              iVar9 = *piVar6;
              iVar8 = piVar6[1];
              iVar14 = piVar6[2];
              iVar4 = piVar6[3];
              piVar6 = piVar6 + 4;
              *piVar13 = iVar9;
              piVar13[1] = iVar8;
              piVar13[2] = iVar14;
              piVar13[3] = iVar4;
              piVar13 = piVar13 + 4;
            } while (piVar6 != param_1 + 0x1c);
            local_c8 = ENGINE_get_static_state();
            local_c4 = ERR_get_implementation();
            local_c0 = (*(code *)PTR_CRYPTO_get_ex_data_implementation_006a8898)();
            (*(code *)PTR_CRYPTO_get_mem_functions_006a889c)(auStack_bc,auStack_b8,auStack_b4);
            local_b0 = (*(code *)PTR_CRYPTO_get_locking_callback_006a88a0)();
            local_ac = (*(code *)PTR_CRYPTO_get_add_lock_callback_006a88a4)();
            local_a8 = (*(code *)PTR_CRYPTO_get_dynlock_create_callback_006a88a8)();
            local_a4 = (*(code *)PTR_CRYPTO_get_dynlock_lock_callback_006a88ac)();
            local_a0 = (*(code *)PTR_CRYPTO_get_dynlock_destroy_callback_006a88b0)();
            engine_set_all_null(param_1);
            uVar15 = (*(code *)piVar3[2])(param_1,piVar3[5],&local_c8);
            puVar1 = PTR_DSO_free_006a8874;
            if (uVar15 == 0) {
              piVar3[2] = 0;
              piVar3[1] = 0;
              (*(code *)puVar1)(*piVar3);
              *piVar3 = 0;
              ERR_put_error(0x26,0xb6,0x6d,"eng_dyn.c",0x21f);
              piVar3 = local_9c;
              do {
                piVar6 = piVar3 + 4;
                iVar8 = piVar3[1];
                iVar14 = piVar3[2];
                iVar4 = piVar3[3];
                *param_1 = *piVar3;
                param_1[1] = iVar8;
                param_1[2] = iVar14;
                param_1[3] = iVar4;
                param_1 = param_1 + 4;
                piVar3 = piVar6;
              } while (piVar6 != local_9c + 0x1c);
              break;
            }
            if ((piVar3[6] < 1) || (uVar15 = ENGINE_add((ENGINE *)param_1), uVar15 != 0))
            goto LAB_0051d918;
            if (piVar3[6] < 2) {
              uVar15 = 1;
              ERR_clear_error();
              break;
            }
            iVar14 = 0x67;
            iVar4 = 0x230;
          }
          ERR_put_error(0x26,0xb6,iVar14,"eng_dyn.c",iVar4);
          break;
        }
        if (piVar3[9] != 0) goto LAB_0051d4ec;
      }
      uVar15 = 0;
      ERR_put_error(0x26,0xb6,0x84,"eng_dyn.c",0x1d1);
      (*(code *)PTR_DSO_free_006a8874)(*piVar3);
      *piVar3 = 0;
      break;
    }
    if (piVar3[5] != 0) {
      iVar14 = (*(code *)PTR_DSO_convert_filename_006a88bc)(iVar4);
      piVar3[3] = iVar14;
      goto LAB_0051d4d8;
    }
    goto LAB_0051d2b0;
  default:
    uVar15 = 0;
    ERR_put_error(0x26,0xb4,0x77,"eng_dyn.c",0x1a5);
  }
LAB_0051d2b4:
  if (local_9c[28] == *(int *)puVar2) {
    return uVar15;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return 0;
}

