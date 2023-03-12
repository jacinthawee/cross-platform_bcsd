
DSO * dynamic_ctrl(undefined4 *param_1,undefined4 param_2,DSO *param_3,char *param_4)

{
  DSO **ptr;
  DSO *pDVar1;
  DSO **mode;
  char *pcVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_GS_OFFSET;
  byte bVar6;
  int iVar7;
  int iVar8;
  int *num;
  CRYPTO_dynlock_value *l;
  f *f;
  int in_stack_ffffff34;
  DSO *local_c0;
  void *local_bc;
  ERR_FNS *local_b8;
  CRYPTO_EX_DATA_IMPL *local_b4;
  int local_b0;
  CRYPTO_dynlock_value local_ac [4];
  undefined local_a8 [4];
  int *local_a4;
  int local_a0;
  CRYPTO_dynlock_value *local_9c;
  CRYPTO_dynlock_value *local_98;
  CRYPTO_dynlock_value *local_94;
  undefined4 local_90 [27];
  undefined4 local_24;
  int local_20;
  
  bVar6 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (dynamic_ex_data_idx < 0) {
    iVar7 = ENGINE_get_ex_new_index
                      (0,(void *)0x0,(undefined1 *)0x0,(undefined1 *)0x0,dynamic_data_ctx_free_func)
    ;
    if (iVar7 != -1) {
      iVar8 = iVar7;
      CRYPTO_lock(iVar7,9,(char *)0x1e,(int)"eng_dyn.c");
      if (dynamic_ex_data_idx < 0) {
        dynamic_ex_data_idx = iVar7;
      }
      CRYPTO_lock(iVar8,10,(char *)0x1e,(int)"eng_dyn.c");
      goto LAB_08116274;
    }
    ERR_put_error(0x26,0xb5,0x90,"eng_dyn.c",0xf4);
LAB_081168d9:
    iVar8 = 0x142;
    iVar7 = 0x70;
    goto LAB_081162a0;
  }
LAB_08116274:
  ptr = (DSO **)ENGINE_get_ex_data((ENGINE *)param_1,dynamic_ex_data_idx);
  if (ptr == (DSO **)0x0) {
    ptr = (DSO **)CRYPTO_malloc(0x2c,"eng_dyn.c",0xbd);
    if (ptr == (DSO **)0x0) {
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xc0);
    }
    else {
      ptr[10] = (DSO *)0x0;
      puVar4 = (undefined4 *)((uint)(ptr + 1) & 0xfffffffc);
      for (uVar3 = (uint)((int)ptr + (0x2c - (int)(undefined4 *)((uint)(ptr + 1) & 0xfffffffc))) >>
                   2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar4 = 0;
        puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
      }
      *ptr = (DSO *)0x0;
      ptr[1] = (DSO *)0x0;
      ptr[2] = (DSO *)0x0;
      ptr[3] = (DSO *)0x0;
      ptr[4] = (DSO *)0x0;
      ptr[5] = (DSO *)0x0;
      ptr[6] = (DSO *)0x0;
      ptr[7] = (DSO *)"v_check";
      ptr[8] = (DSO *)"bind_engine";
      ptr[9] = (DSO *)0x1;
      pDVar1 = (DSO *)sk_new_null();
      ptr[10] = pDVar1;
      if (pDVar1 != (DSO *)0x0) {
        CRYPTO_lock((int)pDVar1,9,(char *)0x1e,(int)"eng_dyn.c");
        mode = (DSO **)ENGINE_get_ex_data((ENGINE *)param_1,dynamic_ex_data_idx);
        if (mode == (DSO **)0x0) {
          iVar7 = ENGINE_set_ex_data((ENGINE *)param_1,dynamic_ex_data_idx,ptr);
          CRYPTO_lock(iVar7,10,(char *)0x1e,(int)"eng_dyn.c");
        }
        else {
          CRYPTO_lock((int)mode,10,(char *)0x1e,(int)"eng_dyn.c");
          CRYPTO_free(ptr);
          ptr = mode;
        }
        goto LAB_0811628b;
      }
      ERR_put_error(0x26,0xb7,0x41,"eng_dyn.c",0xd1);
      CRYPTO_free(ptr);
    }
    goto LAB_081168d9;
  }
LAB_0811628b:
  if (*ptr != (DSO *)0x0) {
    iVar8 = 0x14a;
    iVar7 = 100;
    goto LAB_081162a0;
  }
  switch(param_2) {
  case 200:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      if (ptr[3] != (DSO *)0x0) {
        CRYPTO_free(ptr[3]);
      }
      ptr[3] = (DSO *)0x0;
      local_c0 = (DSO *)0x0;
    }
    else {
      if (ptr[3] != (DSO *)0x0) {
        CRYPTO_free(ptr[3]);
      }
      pDVar1 = (DSO *)BUF_strdup(param_4);
      ptr[3] = pDVar1;
      local_c0 = (DSO *)(uint)(pDVar1 != (DSO *)0x0);
    }
    goto LAB_081162b1;
  case 0xc9:
    local_c0 = (DSO *)0x1;
    ptr[4] = (DSO *)(uint)(param_3 != (DSO *)0x0);
    goto LAB_081162b1;
  case 0xca:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      if (ptr[5] != (DSO *)0x0) {
        CRYPTO_free(ptr[5]);
      }
      ptr[5] = (DSO *)0x0;
      local_c0 = (DSO *)0x0;
    }
    else {
      if (ptr[5] != (DSO *)0x0) {
        CRYPTO_free(ptr[5]);
      }
      pDVar1 = (DSO *)BUF_strdup(param_4);
      ptr[5] = pDVar1;
      local_c0 = (DSO *)(uint)(pDVar1 != (DSO *)0x0);
    }
    goto LAB_081162b1;
  case 0xcb:
    if (param_3 < (DSO *)0x3) {
      local_c0 = (DSO *)0x1;
      ptr[6] = param_3;
      goto LAB_081162b1;
    }
    iVar8 = 0x16c;
    iVar7 = 0x8f;
    break;
  case 0xcc:
    if (param_3 < (DSO *)0x3) {
      local_c0 = (DSO *)0x1;
      ptr[9] = param_3;
      goto LAB_081162b1;
    }
    iVar8 = 0x177;
    iVar7 = 0x8f;
    break;
  case 0xcd:
    if ((param_4 == (char *)0x0) || (*param_4 == '\0')) {
      iVar8 = 0x181;
      iVar7 = 0x8f;
    }
    else {
      pcVar2 = BUF_strdup(param_4);
      if (pcVar2 != (char *)0x0) {
        sk_insert((_STACK *)ptr[10],pcVar2,-1);
LAB_08116825:
        local_c0 = (DSO *)0x1;
        goto LAB_081162b1;
      }
      iVar8 = 0x189;
      iVar7 = 0x41;
    }
    break;
  case 0xce:
    pDVar1 = DSO_new();
    local_c0 = ptr[3];
    *ptr = pDVar1;
    if (local_c0 == (DSO *)0x0) {
      if (ptr[5] == (DSO *)0x0) goto LAB_081162b1;
      local_c0 = (DSO *)DSO_convert_filename(pDVar1,(char *)ptr[5]);
      ptr[3] = local_c0;
    }
    if (ptr[9] == (DSO *)0x2) {
LAB_081164a4:
      iVar7 = sk_num((_STACK *)ptr[10]);
      if (0 < iVar7) {
        iVar8 = 0;
        do {
          pcVar2 = (char *)sk_value((_STACK *)ptr[10],iVar8);
          pcVar2 = DSO_merge(*ptr,(char *)ptr[3],pcVar2);
          if (pcVar2 == (char *)0x0) break;
          pDVar1 = DSO_load(*ptr,pcVar2,(DSO_METHOD *)0x0,0);
          if (pDVar1 != (DSO *)0x0) {
            CRYPTO_free(pcVar2);
            goto LAB_081166bf;
          }
          iVar8 = iVar8 + 1;
          CRYPTO_free(pcVar2);
        } while (iVar7 != iVar8);
      }
    }
    else {
      pDVar1 = DSO_load(*ptr,(char *)local_c0,(DSO_METHOD *)0x0,0);
      if (pDVar1 != (DSO *)0x0) {
LAB_081166bf:
        pDVar1 = (DSO *)DSO_bind_func(*ptr,(char *)ptr[8]);
        ptr[2] = pDVar1;
        if (pDVar1 == (DSO *)0x0) {
          DSO_free(*ptr);
          *ptr = (DSO *)0x0;
          ERR_put_error(0x26,0xb6,0x68,"eng_dyn.c",0x1cf);
          local_c0 = (DSO *)0x0;
          goto LAB_081162b1;
        }
        local_c0 = ptr[4];
        if (local_c0 == (DSO *)0x0) {
          pDVar1 = (DSO *)DSO_bind_func(*ptr,(char *)ptr[7]);
          ptr[1] = pDVar1;
          if ((pDVar1 != (DSO *)0x0) && (uVar3 = (*(code *)pDVar1)(0x20000), 0x1ffff < uVar3))
          goto LAB_08116724;
          ptr[2] = (DSO *)0x0;
          ptr[1] = (DSO *)0x0;
          DSO_free(*ptr);
          *ptr = (DSO *)0x0;
          iVar8 = 0x1e7;
          iVar7 = 0x91;
        }
        else {
LAB_08116724:
          puVar4 = param_1;
          puVar5 = local_90;
          for (iVar7 = 0x1c; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
            puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
          }
          local_bc = ENGINE_get_static_state();
          local_b8 = ERR_get_implementation();
          pcVar2 = (char *)0x8116748;
          local_b4 = CRYPTO_get_ex_data_implementation();
          f = (f *)local_a8;
          l = local_ac;
          local_a4 = &local_b0;
          num = local_a4;
          CRYPTO_get_mem_functions((m *)local_a4,(r *)l,f);
          CRYPTO_get_locking_callback((int)num,(int)l,(char *)f,(int)pcVar2);
          local_a0 = CRYPTO_get_add_lock_callback(num,(int)l,(int)f,pcVar2,in_stack_ffffff34);
          local_94 = CRYPTO_get_dynlock_create_callback((char *)num,(int)l);
          local_9c = local_94;
          CRYPTO_get_dynlock_lock_callback((int)num,l,(char *)f,(int)pcVar2);
          local_98 = local_94;
          CRYPTO_get_dynlock_destroy_callback((CRYPTO_dynlock_value *)num,(char *)l,(int)f);
          engine_set_all_null(param_1);
          local_c0 = (DSO *)(*(code *)ptr[2])(param_1,ptr[5],&local_bc);
          if (local_c0 == (DSO *)0x0) {
            ptr[2] = (DSO *)0x0;
            ptr[1] = (DSO *)0x0;
            DSO_free(*ptr);
            *ptr = (DSO *)0x0;
            ERR_put_error(0x26,0xb6,0x6d,"eng_dyn.c",0x209);
            *param_1 = local_90[0];
            param_1[0x1b] = local_24;
            iVar7 = (int)param_1 - (int)(undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
            puVar4 = (undefined4 *)((int)local_90 - iVar7);
            puVar5 = (undefined4 *)((uint)(param_1 + 1) & 0xfffffffc);
            for (uVar3 = iVar7 + 0x70U >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
              puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
            }
            goto LAB_081162b1;
          }
          if (((int)ptr[6] < 1) ||
             (local_c0 = (DSO *)ENGINE_add((ENGINE *)ptr[6]), local_c0 != (DSO *)0x0))
          goto LAB_08116825;
          if ((int)ptr[6] < 2) {
            ERR_clear_error();
            local_c0 = (DSO *)0x1;
            goto LAB_081162b1;
          }
          iVar8 = 0x21c;
          iVar7 = 0x67;
        }
        ERR_put_error(0x26,0xb6,iVar7,"eng_dyn.c",iVar8);
        goto LAB_081162b1;
      }
      if (ptr[9] != (DSO *)0x0) goto LAB_081164a4;
    }
    ERR_put_error(0x26,0xb6,0x84,"eng_dyn.c",0x1c2);
    DSO_free(*ptr);
    *ptr = (DSO *)0x0;
    local_c0 = (DSO *)0x0;
    goto LAB_081162b1;
  default:
    iVar8 = 0x192;
    iVar7 = 0x77;
  }
LAB_081162a0:
  ERR_put_error(0x26,0xb4,iVar7,"eng_dyn.c",iVar8);
  local_c0 = (DSO *)0x0;
LAB_081162b1:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return local_c0;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

