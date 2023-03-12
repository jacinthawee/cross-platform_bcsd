
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ** do_server(undefined2 param_1,int *param_2,int **param_3,undefined4 *param_4,char *param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int **ppiVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  char *pcVar9;
  char *pcVar10;
  undefined *unaff_s4;
  undefined4 *unaff_s5;
  code *pcVar11;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  int iStack_a4;
  undefined1 *puStack_9c;
  int *piStack_98;
  int iStack_94;
  int **ppiStack_90;
  undefined *puStack_8c;
  undefined4 *puStack_88;
  code *pcStack_84;
  undefined4 local_70;
  undefined *local_68;
  undefined4 *local_5c;
  undefined4 *local_58;
  int *local_54;
  undefined4 local_50;
  char *local_4c;
  undefined4 *local_48;
  char *local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  
  local_3c = 2;
  local_54 = (int *)PTR___stack_chk_guard_006a9ae8;
  puStack_9c = (undefined1 *)&local_3c;
  local_68 = &_gp;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcVar10 = &DAT_00000011;
  local_5c = param_4;
  local_3a = param_1;
  if (param_2 == (int *)&SUB_00000002) {
    pcVar10 = &DAT_00000006;
    piVar8 = param_2;
    piStack_98 = (int *)(*(code *)PTR_socket_006a9984)(2);
  }
  else {
    piVar8 = (int *)0x1;
    piStack_98 = (int *)(*(code *)PTR_socket_006a9984)(2);
  }
  iStack_94 = -1;
  if (piStack_98 == (int *)0xffffffff) {
LAB_00460be0:
    ppiVar4 = (int **)0x0;
  }
  else {
    unaff_s5 = &local_40;
    local_70 = 4;
    local_40 = 1;
    param_4 = unaff_s5;
    (**(code **)(local_68 + -0x52b4))(piStack_98,0xffff,4);
    pcVar10 = &SUB_00000010;
    iVar3 = (**(code **)(local_68 + -0x53d0))(piStack_98,puStack_9c);
    if (iVar3 == -1) {
      (**(code **)(local_68 + -0x5360))(&DAT_00640fd0);
LAB_00460bbc:
      pcVar11 = *(code **)(local_68 + -0x5484);
LAB_00460bc0:
      piVar8 = (int *)0x0;
      (*pcVar11)(piStack_98);
      (**(code **)(local_68 + -0x5494))(piStack_98);
      goto LAB_00460be0;
    }
    if (param_2 == (int *)&SUB_00000002) {
      iVar3 = (**(code **)(local_68 + -0x5430))(piStack_98,0x80);
      if (iVar3 == -1) {
        pcVar11 = *(code **)(local_68 + -0x5484);
        goto LAB_00460bc0;
      }
    }
    local_48 = *(undefined4 **)(local_68 + -0x7fa4);
    if (param_3 != (int **)0x0) {
      *param_3 = piStack_98;
    }
    unaff_s4 = &_gp_1;
    iStack_94 = 0;
    puStack_9c = from_18073;
    local_50 = 0x6aa904;
    local_4c = "-check_ss_sig";
    local_44 = "bad gethostbyaddr\n";
    do {
      while (pcVar10 = param_5, param_2 != (int *)&SUB_00000002) {
        ppiVar4 = (int **)(*(code *)local_5c)(iStack_94,piStack_98);
        if (iStack_94 != 0) {
          (**(code **)(local_68 + -0x7f58))(iStack_94);
        }
        pcVar11 = *(code **)(local_68 + -0x5484);
        if ((int)ppiVar4 < 0) goto LAB_00460b60;
      }
      param_3 = (int **)&SUB_00000010;
      iStack_94 = -1;
      while( true ) {
        from_18073._0_4_ = 0;
        from_18073._4_4_ = 0;
        from_18073._8_4_ = 0;
        from_18073._12_4_ = 0;
        local_40 = 0x10;
        puVar5 = (undefined4 *)(**(code **)(local_68 + -0x5368))(piStack_98,from_18073,unaff_s5);
        if (puVar5 != (undefined4 *)0xffffffff) break;
        param_4 = (undefined4 *)(**(code **)(local_68 + -0x53f8))();
        param_4 = (undefined4 *)*param_4;
        if (param_4 != (undefined4 *)&SUB_00000004) {
          pcVar10 = "errno=%d ";
          (**(code **)(local_68 + -0x5460))(**(undefined4 **)(local_68 + -0x52e8),1);
          (**(code **)(local_68 + -0x5360))("accept");
          goto LAB_00460bbc;
        }
      }
      local_58 = puVar5;
      param_3 = (int **)(**(code **)(local_68 + -0x532c))(local_50,4,2);
      if (param_3 != (int **)0x0) {
        iVar3 = (**(code **)(local_68 + -0x53bc))(*param_3);
        pcVar10 = (char *)0x1c5;
        iStack_94 = (**(code **)(local_68 + -0x7dd8))(iVar3 + 1,local_4c + 0xff8);
        if (iStack_94 == 0) {
          local_5c = local_58;
          (**(code **)(local_68 + -0x5360))("OPENSSL_malloc");
        }
        else {
          param_3 = (int **)*param_3;
          iVar3 = (**(code **)(local_68 + -0x53bc))(param_3);
          pcVar10 = (char *)(iVar3 + 1);
          (**(code **)(local_68 + -0x7e7c))(iStack_94,param_3);
          iVar3 = GetHostByName(iStack_94);
          if (iVar3 == 0) {
            pcVar11 = *(code **)(local_68 + -0x7fa8);
            pcVar9 = "gethostbyname failure\n";
          }
          else {
            if (*(int *)(iVar3 + 8) == 2) {
              pcVar10 = param_5;
              ppiVar4 = (int **)(*(code *)local_5c)(iStack_94,local_58);
              (**(code **)(local_68 + -0x7f58))(iStack_94);
              goto LAB_00460d60;
            }
            pcVar11 = *(code **)(local_68 + -0x7fa8);
            pcVar9 = "gethostbyname addr is not AF_INET\n";
          }
          local_5c = local_58;
          (*pcVar11)(**(undefined4 **)(local_68 + -0x7fa4),pcVar9);
        }
        (**(code **)(local_68 + -0x5494))(local_5c);
        goto LAB_00460bbc;
      }
      iStack_94 = 0;
      (**(code **)(local_68 + -0x7fa8))(*local_48,local_44);
      ppiVar4 = (int **)(*(code *)local_5c)(0,local_58);
LAB_00460d60:
      (**(code **)(local_68 + -0x5484))(local_58,2);
      (**(code **)(local_68 + -0x5494))(local_58);
    } while (-1 < (int)ppiVar4);
    pcVar11 = *(code **)(local_68 + -0x5484);
LAB_00460b60:
    piVar8 = (int *)&SUB_00000002;
    (*pcVar11)(piStack_98);
    (**(code **)(local_68 + -0x5494))(piStack_98);
    param_3 = ppiVar4;
  }
  if (local_2c == *local_54) {
    return ppiVar4;
  }
  pcStack_84 = extract_host_port;
  iVar3 = local_2c;
  (**(code **)(local_68 + -0x5330))();
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppiStack_90 = param_3;
  puStack_8c = unaff_s4;
  puStack_88 = unaff_s5;
  puVar6 = (undefined *)(*(code *)PTR_strchr_006a9a28)();
  if (puVar6 == (undefined *)0x0) {
    ppiVar4 = (int **)0x0;
    pcVar10 = "no port defined\n";
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
    goto LAB_00460fd0;
  }
  *puVar6 = 0;
  if (pcVar10 != (char *)0x0) {
    iVar7 = (*(code *)PTR___isoc99_sscanf_006a9a04)
                      (iVar3,"%u.%u.%u.%u",&uStack_b4,&uStack_b0,&uStack_ac,&uStack_a8);
    if (iVar7 == 4) {
      if ((((0xff < uStack_b4) || (0xff < uStack_b0)) || (0xff < uStack_ac)) || (0xff < uStack_a8))
      {
        ppiVar4 = (int **)0x0;
        pcVar10 = "invalid IP address\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_00460fd0;
      }
      *pcVar10 = (char)uStack_b4;
      pcVar10[1] = (char)uStack_b0;
      pcVar10[2] = (char)uStack_ac;
      pcVar10[3] = (char)uStack_a8;
    }
    else {
      iVar7 = GetHostByName(iVar3);
      if (iVar7 == 0) {
        ppiVar4 = (int **)0x0;
        pcVar10 = "gethostbyname failure\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_00460fd0;
      }
      if (*(short *)(iVar7 + 10) != 2) {
        ppiVar4 = (int **)0x0;
        pcVar10 = "gethostbyname addr is not AF_INET\n";
        (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c);
        goto LAB_00460fd0;
      }
      *pcVar10 = ***(char ***)(iVar7 + 0x10);
      pcVar10[1] = *(char *)(**(int **)(iVar7 + 0x10) + 1);
      pcVar10[2] = *(char *)(**(int **)(iVar7 + 0x10) + 2);
      pcVar10[3] = *(char *)(**(int **)(iVar7 + 0x10) + 3);
    }
  }
  puVar1 = PTR_strtol_006a9958;
  if (piVar8 != (int *)0x0) {
    *piVar8 = iVar3;
  }
  puVar6 = puVar6 + 1;
  pcVar10 = (char *)0x0;
  ppiVar4 = (int **)(*(code *)puVar1)(puVar6,0,10);
  if (ppiVar4 == (int **)0x0) {
    pcVar10 = &DAT_00641018;
    iVar3 = (*(code *)PTR_getservbyname_006a99f0)(puVar6);
    if (iVar3 == 0) {
      pcVar10 = "getservbyname failure for %s\n";
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"getservbyname failure for %s\n",puVar6);
      goto LAB_00460fd0;
    }
    *(short *)param_4 = (short)*(undefined4 *)(iVar3 + 8);
  }
  else {
    *(short *)param_4 = (short)ppiVar4;
  }
  ppiVar4 = (int **)0x1;
LAB_00460fd0:
  if (iStack_a4 == *(int *)puVar2) {
    return ppiVar4;
  }
  iVar3 = iStack_a4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  ppiVar4 = (int **)(*(code *)PTR_strtol_006a9958)();
  if (ppiVar4 == (int **)0x0) {
    iVar7 = (*(code *)PTR_getservbyname_006a99f0)(iVar3,&DAT_00641018);
    if (iVar7 != 0) {
      *(short *)pcVar10 = (short)*(undefined4 *)(iVar7 + 8);
      return (int **)0x1;
    }
    (*(code *)PTR_BIO_printf_006a6e38)
              (*(undefined4 *)PTR_bio_err_006a6e3c,"getservbyname failure for %s\n",iVar3);
  }
  else {
    *(short *)pcVar10 = (short)ppiVar4;
    ppiVar4 = (int **)0x1;
  }
  return ppiVar4;
}

