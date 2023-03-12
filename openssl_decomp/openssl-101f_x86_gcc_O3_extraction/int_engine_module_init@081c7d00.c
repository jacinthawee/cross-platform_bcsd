
undefined4 int_engine_module_init(CONF_IMODULE *param_1,CONF *param_2)

{
  bool bVar1;
  char *pcVar2;
  _STACK *p_Var3;
  int iVar4;
  void *pvVar5;
  _STACK *p_Var6;
  ENGINE *e;
  undefined4 *puVar7;
  char *pcVar8;
  _STACK *e_00;
  undefined4 uVar9;
  int iVar10;
  char *arg;
  char *__s;
  char *pcVar11;
  char *pcVar12;
  int in_GS_OFFSET;
  bool bVar13;
  byte bVar14;
  ENGINE *local_48;
  int local_3c;
  int local_24;
  int local_20;
  
  bVar14 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pcVar2 = CONF_imodule_get_value(param_1);
  p_Var3 = (_STACK *)NCONF_get_section(param_2,pcVar2);
  if (p_Var3 == (_STACK *)0x0) {
    ERR_put_error(0x26,0xbb,0x94,"eng_cnf.c",0xe6);
    uVar9 = 0;
  }
  else {
    for (local_3c = 0; iVar4 = sk_num(p_Var3), local_3c < iVar4; local_3c = local_3c + 1) {
      pvVar5 = sk_value(p_Var3,local_3c);
      pcVar2 = *(char **)((int)pvVar5 + 8);
      local_24 = -1;
      strchr(*(char **)((int)pvVar5 + 4),0x2e);
      p_Var6 = (_STACK *)NCONF_get_section(param_2,pcVar2);
      if (p_Var6 == (_STACK *)0x0) {
        ERR_put_error(0x26,0xbc,0x95,"eng_cnf.c",0x70);
        uVar9 = 0;
        goto LAB_081c817d;
      }
      bVar1 = false;
      local_48 = (ENGINE *)0x0;
      for (iVar4 = 0; e = (ENGINE *)sk_num(p_Var6), iVar4 < (int)e; iVar4 = iVar4 + 1) {
        puVar7 = (undefined4 *)sk_value(p_Var6,iVar4);
        __s = (char *)puVar7[1];
        pcVar8 = strchr(__s,0x2e);
        bVar13 = pcVar8 == (char *)0x0;
        arg = (char *)puVar7[2];
        if (!bVar13) {
          __s = pcVar8 + 1;
        }
        iVar10 = 10;
        pcVar11 = __s;
        pcVar12 = "engine_id";
        do {
          if (iVar10 == 0) break;
          iVar10 = iVar10 + -1;
          bVar13 = *pcVar11 == *pcVar12;
          pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
          pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
        } while (bVar13);
        if (!bVar13) {
          iVar10 = 10;
          pcVar11 = __s;
          pcVar12 = "soft_load";
          do {
            if (iVar10 == 0) break;
            iVar10 = iVar10 + -1;
            bVar13 = *pcVar11 == *pcVar12;
            pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
            pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
          } while (bVar13);
          if (!bVar13) {
            iVar10 = 0xd;
            pcVar11 = __s;
            pcVar12 = "dynamic_path";
            do {
              if (iVar10 == 0) break;
              iVar10 = iVar10 + -1;
              bVar13 = *pcVar11 == *pcVar12;
              pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
              pcVar12 = pcVar12 + (uint)bVar14 * -2 + 1;
            } while (bVar13);
            if (bVar13) {
              local_48 = ENGINE_by_id(pcVar8);
              if (local_48 == (ENGINE *)0x0) {
LAB_081c811f:
                local_48 = (ENGINE *)0x0;
              }
              else {
                iVar10 = ENGINE_ctrl_cmd_string(local_48,"SO_PATH",arg,0);
                if ((iVar10 != 0) &&
                   (iVar10 = ENGINE_ctrl_cmd_string(local_48,"LIST_ADD","2",0), iVar10 != 0)) {
                  iVar10 = ENGINE_ctrl_cmd_string(local_48,"LOAD",(char *)0x0,0);
                  goto joined_r0x081c7f50;
                }
              }
            }
            else {
              bVar13 = local_48 == (ENGINE *)0x0;
              if (bVar13) {
                local_48 = ENGINE_by_id(pcVar8);
                if ((local_48 == (ENGINE *)0x0) && (bVar1)) {
                  ERR_clear_error();
                  goto LAB_081c7fcb;
                }
                bVar13 = local_48 == (ENGINE *)0x0;
                if (bVar13) goto LAB_081c811f;
              }
              iVar10 = 6;
              pcVar8 = arg;
              pcVar11 = "EMPTY";
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar13 = *pcVar8 == *pcVar11;
                pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
                pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
              } while (bVar13);
              iVar10 = 5;
              pcVar8 = __s;
              pcVar11 = "init";
              if (bVar13) {
                arg = (char *)0x0;
              }
              do {
                if (iVar10 == 0) break;
                iVar10 = iVar10 + -1;
                bVar13 = *pcVar8 == *pcVar11;
                pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
                pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
              } while (bVar13);
              if (bVar13) {
                iVar10 = NCONF_get_number_e(param_2,pcVar2,"init",&local_24);
                if (iVar10 != 0) {
                  if (local_24 == 1) {
                    iVar10 = ENGINE_init((ENGINE *)0x1);
                    if (iVar10 != 0) {
                      if (((initialized_engines != (_STACK *)0x0) ||
                          (e_00 = sk_new_null(), initialized_engines = e_00, e_00 != (_STACK *)0x0))
                         && (e_00 = (_STACK *)sk_push(initialized_engines,local_48),
                            e_00 != (_STACK *)0x0)) goto LAB_081c7e70;
                      ENGINE_finish((ENGINE *)e_00);
                    }
                  }
                  else {
                    if (local_24 == 0) goto LAB_081c7e70;
                    ERR_put_error(0x26,0xbc,0x97,"eng_cnf.c",0xb2);
                  }
                }
              }
              else {
                iVar10 = 0x13;
                pcVar8 = __s;
                pcVar11 = "default_algorithms";
                do {
                  if (iVar10 == 0) break;
                  iVar10 = iVar10 + -1;
                  bVar13 = *pcVar8 == *pcVar11;
                  pcVar8 = pcVar8 + (uint)bVar14 * -2 + 1;
                  pcVar11 = pcVar11 + (uint)bVar14 * -2 + 1;
                } while (bVar13);
                if (bVar13) {
                  iVar10 = ENGINE_set_default_string(local_48,arg);
                }
                else {
                  iVar10 = ENGINE_ctrl_cmd_string(local_48,__s,arg,0);
                }
joined_r0x081c7f50:
                if (iVar10 != 0) goto LAB_081c7e70;
              }
            }
            ERR_put_error(0x26,0xbc,0x66,"eng_cnf.c",0xcc);
            ERR_add_error_data(6,"section=",*puVar7,", name=",puVar7[1],", value=",puVar7[2]);
            goto LAB_081c7fa6;
          }
          bVar1 = true;
        }
LAB_081c7e70:
      }
      if (local_48 != (ENGINE *)0x0) {
        bVar1 = true;
        if (local_24 == -1) {
          iVar4 = ENGINE_init(e);
          if (iVar4 != 0) {
            if ((initialized_engines != (_STACK *)0x0) ||
               (p_Var6 = sk_new_null(), initialized_engines = p_Var6, p_Var6 != (_STACK *)0x0)) {
              bVar1 = true;
              p_Var6 = (_STACK *)sk_push(initialized_engines,local_48);
              if (p_Var6 != (_STACK *)0x0) goto LAB_081c7fb4;
            }
            ENGINE_finish((ENGINE *)p_Var6);
          }
          ERR_put_error(0x26,0xbc,0x66,"eng_cnf.c",0xcc);
LAB_081c7fa6:
          if (local_48 != (ENGINE *)0x0) {
            bVar1 = false;
            goto LAB_081c7fb4;
          }
        }
        else {
LAB_081c7fb4:
          ENGINE_free(local_48);
          if (bVar1) goto LAB_081c7fcb;
        }
        uVar9 = 0;
        goto LAB_081c817d;
      }
LAB_081c7fcb:
    }
    uVar9 = 1;
  }
LAB_081c817d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar9;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

